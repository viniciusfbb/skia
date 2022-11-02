#!/bin/bash
#
# Copyright (c) 2011-2022 Google LLC.
# Copyright (c) 2021-2022 Skia4Delphi Project.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
#

python3 --version >/dev/null 2>&1
if [ $? -eq 0 ]; then
    SCRIPT_EXECUTABLE=python3
else
    python --version >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        SCRIPT_EXECUTABLE=python
    else
        echo "Python not found."
        echo ""
        if [[ $OSTYPE == 'darwin'* ]]; then
            echo "Make sure your Xcode has been installed."
            echo "Python is installed together with Xcode, if the problem persists try installing it using the command:"
            echo "  'xcode-select --install'"
            echo ""
            echo "Note: After installing Xcode, it must be opened at least once to accept the license terms as well as to install the components."
        else
            echo "Python can be installed by running the command:"
            echo "  - For Debian or based systems (Ubuntu):"
            echo "      'sudo apt-get -y install python3'"
            echo "  - For Red Hat Enterprise or based systems (CentOS, Fedora):"
            echo "      'dnf -y install python3'"
        fi
        exit 1
    fi
fi

SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
PATH="$SCRIPT_DIR/sk4d/bin":$PATH
$SCRIPT_EXECUTABLE "$SCRIPT_DIR/sk4d/scripts/build.py" --script-executable=$SCRIPT_EXECUTABLE $@