#!/bin/bash
#
# Copyright (c) 2011-2022 Google LLC.
# Copyright (c) 2021-2022 Skia4Delphi Project.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
#

python --version >/dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Python not found."
    python3 --version >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo "Python 3 is installed but an alias has not been set for it."
        echo ""
        echo "It can possibly be fixed by running the command:"
        echo "  - For Debian or based systems (Ubuntu):"
        echo "      'sudo apt-get -y install python-is-python3'"
        echo "  - For Red Hat Enterprise or based systems (CentOS, Fedora):"
        echo "      'sudo alternatives --set python /usr/bin/python3'"
    else
        echo "Python can be installed by running the command:"
        echo "  - For Debian or based systems (Ubuntu):"
        echo "      'sudo apt-get -y install python3'"
        echo "  - For Red Hat Enterprise or based systems (CentOS, Fedora):"
        echo "      'dnf -y install python3'"
    fi
    exit 1
fi

SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
PATH="$SCRIPT_DIR/sk4d/bin":$PATH
python "$SCRIPT_DIR/sk4d/scripts/build.py" $@
