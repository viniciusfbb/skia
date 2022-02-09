#!/usr/bin/env python
#
# Copyright (c) 2011-2022 Google LLC.
# Copyright (c) 2021-2022 Skia4Delphi Project.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

from __future__ import print_function

import argparse
import errno
import json
import logging
import os
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

# Minimum iOS version based on Rad Studio Alexandria
IOS_MIN_TARGET = '11.0'

# Minimum Android version based on Rad Studio Rio
NDK_API = 22

BIN_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'bin')

CLANG_WIN_DEFAULT = 'C:\\Program Files\\LLVM'

if sys.platform.startswith('linux'):
    HOST = 'linux'
elif sys.platform.startswith('darwin'):
    HOST = 'mac'
elif sys.platform.startswith('win32'):
    HOST = 'win'
else:
    sys.exit('%s is invalid platform host' % sys.platform)

MODES = [
    'release',
    'debug'
]

NDK_HOST = {
    'linux': 'linux-x86_64',
    'mac': 'darwin-x86_64',
    'win': 'windows-x86_64'
}

OS_NAME = {
    'linux': 'Linux',
    'mac': 'macOS',
    'win': 'Windows'
}

ROOT_DIR = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

TARGETS = {
    'linux': ['linux64', 'android', 'android64'],
    'mac': ['osx64', 'osxarm64', 'iosdevice64', 'android', 'android64'],
    'win': ['win32', 'win64', 'android', 'android64']
}

TARGET_STATIC_LIBRARY = ['iosdevice64']

TARGETS_CPU = {
    'win32': 'x86',
    'win64': 'x64',
    'linux64': 'x64',
    'android': 'arm',
    'android64': 'arm64',
    'iosdevice64': 'arm64',
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
    'osx64': 'mac',
    'osxarm64': 'mac'
}

TARGETS_OUT = {
    'win32': 'sk4d.dll',
    'win64': 'sk4d.dll',
    'linux64': 'libsk4d.so',
    'android': 'libsk4d.so',
    'android64': 'libsk4d.so',
    'iosdevice64': 'sk4d.a',
    'osx64': 'sk4d.dylib',
    'osxarm64': 'sk4d.dylib'
}

TARGETS_OUT_TEMP = {
    'win32': 'sk4d.dll',
    'win64': 'sk4d.dll',
    'linux64': 'sk4d.so',
    'android': 'sk4d.so',
    'android64': 'sk4d.so',
    'iosdevice64': 'sk4d.a',
    'osx64': 'sk4d.so',
    'osxarm64': 'sk4d.so'
}


class SkException(Exception):
    pass


def call_executable(cmd, **kwargs):
    input = kwargs.pop('input', None)
    working_dir = kwargs.pop('working_dir', None)
    process = subprocess.Popen(cmd, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                               cwd=working_dir)
    output = process.communicate(input)[0]
    return process.returncode == 0, output.decode('ascii')


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


#
# Generate build files
#
def get_args_win():
    return (' skia_enable_fontmgr_win_gdi=false'
            ' skia_use_piex=true'
            ' skia_use_system_expat=false'
            ' skia_use_system_harfbuzz=false'
            ' skia_use_system_icu=false'
            ' skia_use_system_libjpeg_turbo=false'
            ' skia_use_system_libpng=false'
            ' skia_use_system_libwebp=false'
            ' skia_use_system_zlib=false')


def get_args_linux():
    return (' skia_use_system_expat=false'
            ' skia_use_system_freetype2=false'
            ' skia_use_system_harfbuzz=false'
            ' skia_use_system_icu=false'
            ' skia_use_system_libjpeg_turbo=false'
            ' skia_use_system_libpng=false'
            ' skia_use_system_libwebp=false'
            ' skia_use_system_zlib=false'
            ' cc="clang"'
            ' cxx="clang++"'
            ' ar="llvm-ar"')


def get_args_android():
    return (' skia_use_system_expat=false'
            ' skia_use_system_freetype2=false'
            ' skia_use_system_harfbuzz=false'
            ' skia_use_system_icu=false'
            ' skia_use_system_libjpeg_turbo=false'
            ' skia_use_system_libpng=false'
            ' skia_use_system_libwebp=false'
            ' skia_use_system_zlib=false'
            ' skia_use_vulkan=false')


def get_args_mac():
    return (' skia_use_metal = true'
            ' skia_use_system_expat=false'
            ' skia_use_system_harfbuzz=false'
            ' skia_use_system_icu=false'
            ' skia_use_system_libjpeg_turbo=false'
            ' skia_use_system_libpng=false'
            ' skia_use_system_libwebp=false'
            ' skia_use_system_zlib=false')


def get_args_ios():
    return (' skia_use_metal = true'
            ' skia_use_system_expat=false'
            ' skia_use_system_harfbuzz=false'
            ' skia_use_system_icu=false'
            ' skia_use_system_libjpeg_turbo=false'
            ' skia_use_system_libpng=false'
            ' skia_use_system_libwebp=false'
            ' skia_use_system_zlib=false')


def gn_gen(target, is_debug, clang_win, ndk):
    gn_gen_args = 'sk4d_component_build=%s target_os="%s" target_cpu="%s" is_official_build=%s' \
                  % (str(target not in TARGET_STATIC_LIBRARY).lower(), TARGETS_OS[target], TARGETS_CPU[target],
                     str(not is_debug).lower())
    if TARGETS_OS[target] == 'win':
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
        gn_gen_args += get_args_win() + ' clang_win="%s"' % os.path.join(output.rstrip(), 'VC')
        if not os.path.exists(clang_win):
            print(textwrap.dedent('''\
                -------- Building Recommendations --------
                
                Clang not found. It is highly recommended to build with clang-cl.
                
                The installation can be downloaded from:
                https://github.com/llvm/llvm-project/releases/latest
                
                * If installed in a custom directory use the --clang_win option.
                Default installation directory is '%s'.
                ''') % CLANG_WIN_DEFAULT)
        else:
            gn_gen_args += ' clang_win="%s"' % clang_win

    elif TARGETS_OS[target] == 'linux':
        gn_gen_args += get_args_linux()
    elif TARGETS_OS[target] == 'android':
        if not os.path.exists(ndk):
            print(textwrap.dedent('''\
                -------- Building Tips --------
                
                NDK can be downloaded from:
                https://developer.android.com/ndk/downloads
                
                * It is necessary to pass the NDK path with the "--ndk" option.
                eg: '%s'
                ''') % '--ndk C:\\ndk_1.1' if HOST == 'win' else '--ndk /home/<username>/ndk_1.1')
            raise SkException('NDK not found.')
        gn_gen_args += get_args_android() + ' ndk="%s" ndk_api=%d' % (ndk, NDK_API)
    elif TARGETS_OS[target] == 'ios' or TARGETS_OS[target] == 'mac':
        result = call_executable(['xcode-select', '-p'])[0]
        if not result:
            print(textwrap.dedent('''\
                -------- Building Tips --------
                
                Xcode can be installed via the App Store.
                '''))
            raise SkException('Xcode not found.')
        if TARGETS_OS[target] == 'ios':
            gn_gen_args += get_args_ios() + ' ios_min_target="%s"' % IOS_MIN_TARGET
        elif TARGETS_OS[target] == 'mac':
            gn_gen_args += get_args_mac()
    target_dir = os.path.join(TARGETS_NAME[target], 'Release' if not is_debug else 'Debug')
    temp_dir = os.path.join(ROOT_DIR, 'temp', target_dir)
    result, output = call_executable([os.path.join(ROOT_DIR, 'bin', 'gn'), 'gen', temp_dir, '--args=%s' % gn_gen_args,
                                      '--root=%s' % ROOT_DIR])
    if not result:
        raise SkException('Unable to generate build files for %s target: %s' % (TARGETS_NAME[target], output))
    return target_dir, temp_dir


def main():
    prog = 'build' if HOST == 'win' else './build.sh'
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
                                                     TARGETS[HOST][0], 'C:\\ndk' if HOST == 'win' else '/ndk'),
                                     epilog=textwrap.dedent('''\
                                         The available targets depends on the host:
                                         
                                         Linux   {0}
                                         macOS   {1}
                                         Windows {2}
                                         ''').format(', '.join(TARGETS['linux']), ', '.join(TARGETS['mac']),
                                                     ', '.join(TARGETS['win'])))
    parser.add_argument('-v', '--verbose', action='store_const', const=logging.DEBUG, default=logging.INFO,
                        help='be verbose', dest='log_level')
    parser.add_argument('--targets', nargs='+', type=lambda x: x.lower(), required=True, metavar='<targets>')
    parser.add_argument('--mode', default='release', type=lambda x: x.lower(), metavar='|'.join(MODES))
    if HOST == 'win':
        parser.add_argument('--clang-win', default=CLANG_WIN_DEFAULT, type=lambda x: os.path.abspath(x),
                            metavar='<directory>', dest='clang_win')
    parser.add_argument('--ndk', type=lambda x: os.path.abspath(x), metavar='<directory>')
    parser.add_argument('--skip-sync-deps', action='store_true', default=False, dest='skip_sync_deps')
    args = parser.parse_args()
    file_handler = logging.FileHandler(os.path.join(ROOT_DIR, 'build.log'))
    file_handler.setFormatter(logging.Formatter('[%(asctime)s] %(levelname)-8s: %(message)s', '%m/%d/%y %H:%M:%S'))
    stream_handler = logging.StreamHandler(sys.stdout)
    stream_handler.setFormatter(logging.Formatter('%(levelname)-s: %(message)s'))
    logger = logging.getLogger()
    logger.setLevel(args.log_level)
    logger.addHandler(file_handler)
    logger.addHandler(stream_handler)
    clang_win = args.clang_win if HOST == 'win' else None
    ndk = args.ndk
    if args.mode == 'release':
        is_debug = False
    elif args.mode == 'debug':
        is_debug = True
    else:
        is_debug = True
        logger.warning('Invalid mode, Debug selected.')
    try:
        if find_executable(['git']) is None:
            if HOST == 'win':
                print(textwrap.dedent('''\
                    -------- Building Tips --------
                    
                    Git can be installed in two ways:
                    
                      - Installation downloaded from git-scm (https://git-scm.com);
                      - Using the chocolatey package manager: 'choco install -y git'.
                    
                    * Make sure it has been added to the PATH environment variable and reopen the terminal.
                    '''))
            elif HOST == 'linux':
                print(textwrap.dedent('''\
                    -------- Building Tips --------
                    
                    Git can be installed by running the command:
                    
                      - For Debian or based systems (Ubuntu):
                          'sudo apt-get -y install git'
                      - For Red Hat Enterprise or based systems (CentOS, Fedora):
                          'dnf -y install git'
                    '''))
            raise SkException('Git not found.')
        ninja = find_executable(['ninja'], environment_name='NINJA_EXECUTABLE')
        if ninja is None:
            download_latest_from_github('ninja-build', 'ninja', 'ninja-%s.zip' % HOST, BIN_DIR, unpack=True)
            ninja = 'ninja'

            # Fix ninja permissions
            if HOST != 'win':
                st = os.stat(os.path.join(BIN_DIR, ninja))
                os.chmod(os.path.join(BIN_DIR, ninja), st.st_mode | stat.S_IEXEC)

        if not args.skip_sync_deps:
            logger.info('Synchronizing dependencies.')
            result, output = call_executable([sys.executable, os.path.join(ROOT_DIR, 'tools', 'git-sync-deps')])
            if not result:
                raise SkException('Unable to sync dependencies: %s' % output)
        first_build = True
        for t in args.targets:
            if t not in TARGETS[HOST]:
                raise SkException('"%s" is not a valid target to be compiled from %s.' % (t, TARGETS[HOST]))
            logger.info('Building for %s.', TARGETS_NAME[t])
            target_dir, temp_dir = gn_gen(t, is_debug, clang_win, ndk)
            try:
                result, output = call_executable([ninja, '-C', temp_dir, 'sk4d'])
                logger.debug(output)
                # The main function of the script is to try to help the developer as much as possible to build the
                # library successfully. If they can't build it, we present custom messages with common problems.
                if not result:
                    if first_build:
                        print(textwrap.dedent('''\
                            -------- Building Tips --------
                            
                            It is necessary to maintain the internet connection to sync the dependencies.
                            If the internet is weak, or goes down, try to build again.
                            '''))
                    if TARGETS_OS[t] == 'win':
                        if clang_win is None:
                            print(textwrap.dedent('''\
                                -------- Building Tips --------
                                
                                Use Clang (clang-cl) can fix the build problem.
                                '''))
                        else:
                            print(textwrap.dedent('''\
                                -------- Building Tips --------

                                Update Clang (clang-cl) can fix the build problem.
                                '''))
                    elif TARGETS_OS[t] == 'linux':
                        print(textwrap.dedent('''\
                            -------- Building Tips --------
                            
                            Some packages are needed for the build.
                            Make sure you install them by running the command:
                            
                              - For Debian or based systems (Ubuntu):
                                  'sudo apt-get -y install clang libfontconfig1-dev libgl1-mesa-dev llvm'
                              - For Red Hat Enterprise or based systems (CentOS, Fedora):
                                  'dnf -y install clang fontconfig-devel llvm mesa-libGLw-devel'
                            '''))
                    elif TARGETS_OS[t] == 'android' and HOST == 'mac':
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
                first_build = False
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
