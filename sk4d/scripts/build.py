#!/usr/bin/env python
#
# Copyright (c) 2011-2023 Google LLC.
# Copyright (c) 2021-2023 Skia4Delphi Project.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

from __future__ import print_function

import argparse
import errno
import json
import logging
import os
import platform
import re
import shutil
import stat
import subprocess
import sys
import tempfile
import textwrap
import zipfile

try:
    import urllib.request as urlrequest
except ImportError:
    import urllib2 as urlrequest

CLANG_WIN_DEFAULT = 'C:\\Program Files\\LLVM'
WIN_SDK_DEFAULT = 'C:\\Program Files (x86)\\Windows Kits\\10'

BIN_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'bin')
ROOT_DIR = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

IS_LINUX = sys.platform == 'linux' or sys.platform == 'linux2'
IS_MAC = sys.platform == 'darwin'
IS_WIN = sys.platform == 'win32'

if not IS_WIN and not IS_LINUX and not IS_MAC:
    sys.exit('%s is invalid host platform' % sys.platform)

if platform.machine().lower() == 'amd64' or platform.machine().lower() == 'x86_64':
    ARCH = 'x64'
elif platform.machine().lower() == 'aarch64' or platform.machine().lower() == 'arm64':
    ARCH = 'arm64'
else:
    sys.exit('%s is invalid host arch' % platform.machine())

if IS_WIN and ARCH == 'x64':
    HOST = 'win64'
if IS_WIN and ARCH == 'arm64':
    HOST = 'winarm64'
elif IS_LINUX and ARCH == 'x64':
    HOST = 'linux64'
elif IS_MAC and ARCH == 'x64':
    HOST = 'osx64'
elif IS_MAC and ARCH == 'arm64':
    HOST = 'osxarm64'
else:
    sys.exit('Invalid host')

MODES = [
    'release',
    'debug'
]

GN_HOST = {
    'linux64': 'linux64',
    'osx64': 'osx64',
    'win64': 'win64',
    'winarm64': 'win64'
}

NDK_HOST = {
    'linux64': 'linux-x86_64',
    'osx64': 'darwin-x86_64',
    'win64': 'windows-x86_64',
    'winarm64': 'windows-x86_64'
}

NINJA_HOST = {
    'linux64': 'linux',
    'osx64': 'mac',
    'win64': 'win',
    'winarm64': 'win'
}

TARGETS = {
    'linux64': ['linux64', 'android', 'android64'],
    'osx64': ['osx64', 'osxarm64', 'iosdevice64', 'iossimarm64', 'android', 'android64'],
    'osxarm64': ['osx64', 'osxarm64', 'iosdevice64', 'iossimarm64', 'android', 'android64'],
    'win64': ['win32', 'win64', 'android', 'android64'],
    'winarm64': ['win32', 'win64', 'android', 'android64']
}

TARGET_STATIC_LIBRARY = ['iosdevice64']

TARGETS_CPU = {
    'win32': 'x86',
    'win64': 'x64',
    'linux64': 'x64',
    'android': 'arm',
    'android64': 'arm64',
    'iosdevice64': 'arm64',
    'iossimarm64': 'arm64',
    'osx64': 'x64',
    'osxarm64': 'arm64'
}

TARGETS_NAME = {
    'win32': 'Win32',
    'win64': 'Win64',
    'linux64': 'Linux64',
    'android': 'Android',
    'android64': 'Android64',
    'iosdevice64': 'iOSDevice64',
    'iossimarm64': 'iOSSimARM64',
    'osx64': 'OSX64',
    'osxarm64': 'OSXARM64'
}

TARGETS_OS = {
    'win32': 'win',
    'win64': 'win',
    'linux64': 'linux',
    'android': 'android',
    'android64': 'android',
    'iosdevice64': 'ios',
    'iossimarm64': 'ios',
    'osx64': 'mac',
    'osxarm64': 'mac'
}

TARGETS_OUT = {
    'win32': 'sk4d.dll',
    'win64': 'sk4d.dll',
    'linux64': 'libsk4d.so',
    'android': 'libsk4d.so',
    'android64': 'libsk4d.so',
    'iosdevice64': 'libsk4d.a',
    'iossimarm64': 'libsk4d.dylib',
    'osx64': 'libsk4d.dylib',
    'osxarm64': 'libsk4d.dylib'
}

TARGETS_OUT_TEMP = {
    'win32': 'sk4d.dll',
    'win64': 'sk4d.dll',
    'linux64': 'sk4d.so',
    'android': 'sk4d.so',
    'android64': 'sk4d.so',
    'iosdevice64': 'sk4d.a',
    'iossimarm64': 'sk4d.dylib',
    'osx64': 'sk4d.dylib',
    'osxarm64': 'sk4d.dylib'
}


class SkException(Exception):
    pass


def call_executable(cmd, **kwargs):
    i = kwargs.pop('input', None)
    working_dir = kwargs.pop('working_dir', None)
    process = subprocess.Popen(cmd, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                               cwd=working_dir)
    out, err = process.communicate(i)
    success = process.returncode == 0
    output = out.decode('utf-8', 'ignore')
    return success, output


def download_latest_from_github(user, repo, pattern, dest_dir, **kwargs):
    unpack = kwargs.pop('unpack', False)
    try:
        response = urlrequest.urlopen('https://api.github.com/repos/%s/%s/releases/latest' % (user, repo))
    except IOError:
        raise SkException('An error occurred while trying to connect to the %s repo, please try again later.' % repo)
    else:
        response_json = json.loads(response.read())
        download_url = None
        file_name = None
        regex = re.compile(pattern)
        for a in response_json['assets']:
            if regex.match(a['name']) is not None:
                download_url = a['browser_download_url']
                file_name = a['name']
                break
        if not download_url or not file_name:
            raise SkException('Could not locate the latest release of %s.' % repo)
        try:
            response_file = urlrequest.urlopen(download_url)
        except IOError:
            raise SkException('A connection error has occurred, please try again later.')
        else:
            if not os.path.exists(dest_dir):
                os.makedirs(dest_dir)
            dest_path = os.path.join(dest_dir, file_name)
            if unpack:
                with tempfile.TemporaryFile() as temp_file:
                    shutil.copyfileobj(response_file, temp_file)
                    with zipfile.ZipFile(temp_file, 'r') as zip_file:
                        zip_file.extractall(dest_dir)
            else:
                with open(dest_path, 'wb') as dest_file:
                    shutil.copyfileobj(response_file, dest_file)


def find_executable(search_list, **kwargs):
    executables = search_list
    environment_name = kwargs.pop('environment_name', None)
    if environment_name is not None:
        environment_executable = os.environ.get(environment_name)
        if environment_executable:
            executables.insert(0, environment_executable)
    with open(os.devnull, 'w') as devnull:
        for e in executables:
            try:
                subprocess.call([e], stdout=devnull, stderr=subprocess.STDOUT)
            except OSError as err:
                if err.errno == errno.ENOENT:
                    continue
                raise err
            return e
    return None


def gn_gen(script_executable, target, is_debug, ndk, clang_win, win_vc, win_sdk, xcode_sysroot):
    gn_gen_args = 'sk4d_component_build=%s target_os="%s" target_cpu="%s" is_official_build=%s' \
                  % (str(target not in TARGET_STATIC_LIBRARY).lower(), TARGETS_OS[target], TARGETS_CPU[target],
                     str(not is_debug).lower())
    if TARGETS_OS[target] == 'win':
        # Currently we are only supporting compiling on Windows via Clang x64. Since the ICU is static, and the official
        # scripts generate a data file as a very large source, it is only possible to compile using Clang x64 due to
        # memory constraints.
        if not os.path.exists(clang_win):
            print(textwrap.dedent('''\
                -------- Building Tips --------

                Clang x64 installation can be downloaded from:
                https://releases.llvm.org/download.html
                '''))
            raise SkException('Clang x64 not found.')
        gn_gen_args += ' clang_win="%s"' % clang_win
        if win_vc:
            gn_gen_args += ' win_vc="%s"' % win_vc
        else:
            vswhere = find_executable(['vswhere'], environment_name='VSWHERE_EXECUTABLE')
            if vswhere is None:
                download_latest_from_github('microsoft', 'vswhere', 'vswhere.exe', BIN_DIR)
                vswhere = 'vswhere'
            result, output = call_executable([vswhere, '-products', '*', '-requires',
                                              'Microsoft.VisualStudio.Component.VC.Tools.x86.x64', '-version',
                                              '[16.0,18.0)', '-latest', '-property', 'installationPath'])
            if not result or not output:
                print(textwrap.dedent('''\
                    -------- Building Tips --------
                    
                    Visual Studio C++ installation can be downloaded from:
                    https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022
                    '''))
                raise SkException('Visual Studio C++ not found.')
            gn_gen_args += ' win_vc="%s"' % os.path.join(output.rstrip(), 'VC')
        if not os.path.exists(win_sdk):
            print(textwrap.dedent('''\
                -------- Building Tips --------

                Windows SDK installation can be downloaded from:
                https://developer.microsoft.com/pt-br/windows/downloads/windows-sdk
                '''))
            raise SkException('Windows SDK not found.')
        gn_gen_args += ' win_sdk="%s"' % win_sdk
    elif TARGETS_OS[target] == 'linux':
        gn_gen_args += ' cc="clang" cxx="clang++"'
    elif TARGETS_OS[target] == 'android':
        if not os.path.exists(ndk):
            print(textwrap.dedent('''\
                -------- Building Tips --------
                
                NDK can be downloaded from:
                https://developer.android.com/ndk/downloads
                
                * It is necessary to pass the NDK path with the "--ndk" option.
                eg: '%s'
                ''') % '--ndk C:\\ndk_1.1' if IS_WIN else '--ndk /home/<username>/ndk_1.1')
            raise SkException('NDK not found.')
        gn_gen_args += ' ndk="%s"' % ndk
    elif TARGETS_OS[target] == 'ios' or TARGETS_OS[target] == 'mac':
        if TARGETS_OS[target] == 'ios' and target == 'iossimarm64':
            gn_gen_args += ' ios_use_simulator=true'
        if xcode_sysroot:
            gn_gen_args += ' xcode_sysroot="%s"' % xcode_sysroot
    target_dir = os.path.join(TARGETS_NAME[target], 'Release' if not is_debug else 'Debug')
    temp_dir = os.path.join(ROOT_DIR, 'temp', target_dir)
    result, output = call_executable([os.path.join(ROOT_DIR, 'bin', GN_HOST[HOST], 'gn.exe' if IS_WIN else 'gn'), 'gen',
                                      '--script-executable=%s' % script_executable, temp_dir, '--args=%s' % gn_gen_args,
                                      '--root=%s' % ROOT_DIR])
    if result:
        return target_dir, temp_dir
    raise SkException('Unable to generate build files for %s target: %s' % (TARGETS_NAME[target], output))


def main():
    prog = 'sk4d-build' if IS_WIN else './sk4d-build.sh'
    parser = argparse.ArgumentParser(prog=prog, formatter_class=argparse.RawDescriptionHelpFormatter,
                                     description=textwrap.dedent('''\
                                         Targets available: {0}
                                         
                                         --------------------------------
                                         
                                         Usage examples:
                                         
                                         To Build for {2}:
                                           {1} --targets {3}
                                         To Build for Android:
                                           {1} --targets Android --ndk {4}
                                         ''').format(', '.join(TARGETS[HOST]), prog, TARGETS_NAME[TARGETS[HOST][0]],
                                                     TARGETS[HOST][0], 'C:\\ndk' if IS_WIN else '/ndk'),
                                     epilog=textwrap.dedent('''\
                                         The available targets depends on the host:
                                         
                                         Linux x64   {0}
                                         macOS x64   {1}
                                         macOS arm64 {2}
                                         Windows x64 {3}
                                         ''').format(', '.join(TARGETS['linux64']), ', '.join(TARGETS['osx64']),
                                                     ', '.join(TARGETS['osxarm64']), ', '.join(TARGETS['win64'])))
    parser.add_argument('--script-executable', type=str, required=False, help=argparse.SUPPRESS,
                        dest='script_executable')
    parser.add_argument('-v', '--verbose', action='store_const', const=logging.DEBUG, default=logging.INFO,
                        help='be verbose', dest='log_level')
    parser.add_argument('--targets', nargs='+', type=lambda x: x.lower(), required=True, metavar='<targets>')
    parser.add_argument('--mode', default='release', type=lambda x: x.lower(), metavar='|'.join(MODES))
    if IS_WIN:
        parser.add_argument('--clang-win', default=CLANG_WIN_DEFAULT, type=lambda x: os.path.abspath(x),
                            metavar='<directory>', dest='clang_win')
        parser.add_argument('--win-vc', type=lambda x: os.path.abspath(x), metavar='<directory>', dest='win_vc')
        parser.add_argument('--win-sdk', default=WIN_SDK_DEFAULT, type=lambda x: os.path.abspath(x),
                            metavar='<directory>', dest='win_sdk')
    parser.add_argument('--xcode-sysroot', type=lambda x: os.path.abspath(x), metavar='<directory>',
                        dest='xcode_sysroot')
    parser.add_argument('--ndk', type=lambda x: os.path.abspath(x), metavar='<directory>')
    args = parser.parse_args()
    script_executable = args.script_executable
    file_handler = logging.FileHandler(os.path.join(ROOT_DIR, 'build.log'))
    file_handler.setFormatter(logging.Formatter('[%(asctime)s] %(levelname)-8s: %(message)s', '%m/%d/%y %H:%M:%S'))
    stream_handler = logging.StreamHandler(sys.stdout)
    stream_handler.setFormatter(logging.Formatter('%(levelname)-s: %(message)s'))
    logger = logging.getLogger()
    logger.setLevel(args.log_level)
    logger.addHandler(file_handler)
    logger.addHandler(stream_handler)
    clang_win = args.clang_win if IS_WIN else None
    win_vc = args.win_vc if IS_WIN else None
    win_sdk = args.win_sdk if IS_WIN else None
    xcode_sysroot = args.xcode_sysroot if IS_MAC else None
    ndk = args.ndk
    if args.mode == 'release':
        is_debug = False
    elif args.mode == 'debug':
        is_debug = True
    else:
        is_debug = True
        logger.warning('Invalid mode, Debug selected.')
    try:
        ninja = find_executable(['ninja'], environment_name='NINJA')
        if ninja is None:
            if HOST == 'osxarm64':
                print(textwrap.dedent('''\
                    -------- Building Tips --------

                    Ninja Build can be installed easily through Homebrew (https://brew.sh) via the command:
                    'brew install ninja'
                    '''))
                raise SkException('Ninja build not found.')
            download_latest_from_github('ninja-build', 'ninja', 'ninja-%s.zip' % NINJA_HOST[HOST], BIN_DIR, unpack=True)
            ninja = os.path.join(BIN_DIR, 'ninja.exe' if IS_WIN else 'ninja')
            os.chmod(ninja, stat.S_IRUSR | stat.S_IWUSR | stat.S_IXUSR |
                     stat.S_IRGRP | stat.S_IXGRP |
                     stat.S_IROTH | stat.S_IXOTH)
        for t in args.targets:
            if t not in TARGETS[HOST]:
                raise SkException('"%s" is not a valid target to be compiled from %s.' % (t, TARGETS[HOST]))
            logger.info('Building for %s.', TARGETS_NAME[t])
            target_dir, temp_dir = gn_gen(script_executable, t, is_debug, ndk, clang_win, win_vc, win_sdk,
                                          xcode_sysroot)
            try:
                result, output = call_executable([ninja, '-C', temp_dir, 'sk4d'])
                logger.debug(output)
                # The main function of the script is to try to help the developer as much as possible to build the
                # library successfully. If they can't build it, we present custom messages with common problems.
                if not result:
                    if TARGETS_OS[t] == 'linux':
                        print(textwrap.dedent('''\
                            -------- Building Tips --------
                            
                            Some packages are needed for the build.
                            Make sure you install them by running the command:
                            
                              - For Debian or based systems (Ubuntu):
                                  'sudo apt -y install clang libfontconfig1-dev libgl1-mesa-dev'
                              - For Red Hat Enterprise or based systems (CentOS, Fedora):
                                  'dnf -y install clang fontconfig-devel mesa-libGLw-devel'
                            '''))
                    elif TARGETS_OS[t] == 'android' and IS_MAC:
                        print(textwrap.dedent('''\
                            -------- Building Tips --------
                            
                            Depending on the NDK version an error may occur because the developer cannot be verified.
                            
                            If you get this error, you can fix it by allowing the toolchains to open anyway.
                            In this case follow the instructions:
                            
                              a) When asked if you want to delete the tool, click 'Cancel';
                              b) Access 'System Preferences > Security & Privacy > General';
                              c) Click 'Padlock' to unlock settings by entering username and password;
                              d) Check 'App Store and identified developers';
                              e) Click 'Allow Anyway';
                              f) Try build again.
                            
                            * You may have to repeat this procedure a few times.
                            '''))
                    if args.log_level == logging.INFO:
                        print(textwrap.dedent('''\
                            -------- Building Tips --------
                                                        
                            To help debug enable verbose mode with the -v flag.
                            '''))
                    else:
                        print(textwrap.dedent('''\
                            -------- Building Tips --------
                            
                            'The logs are saved in the file "%s"'
                            ''') % os.path.join(ROOT_DIR, 'build.log'))
                    raise SkException('Unable to build for %s target: %s' % (TARGETS_NAME[t], output))
                out_dir = os.path.join(ROOT_DIR, 'out', target_dir)
                if not os.path.exists(out_dir):
                    os.makedirs(out_dir)
                shutil.copyfile(os.path.join(temp_dir, TARGETS_OUT_TEMP[t]), os.path.join(out_dir, TARGETS_OUT[t]))
            finally:
                shutil.rmtree(temp_dir, ignore_errors=True)
    except OSError as e:
        if e.errno == errno.EPERM:
            print('It is possible that the problem will be solved by running the script as root/admin.')
        logger.critical(str(e))
    except SkException as e:
        logger.error(str(e))
    else:
        logger.info('Successfully finished.')
        return 0
    return 1


if __name__ == '__main__':
    sys.exit(main())
