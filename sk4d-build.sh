#!/bin/bash
#
# Copyright (c) 2011-2022 Google LLC.
# Copyright (c) 2021-2022 Skia4Delphi Project.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
#

python3 --version >/dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Python not found."
    echo ""
    echo "Python can be installed by running the command:"
    echo "  - For Debian or based systems (Ubuntu):"
    echo "      'sudo apt-get -y install python3'"
    echo "  - For Red Hat Enterprise or based systems (CentOS, Fedora):"
    echo "      'dnf -y install python3'"
    echo "  - For MacOS:"
    echo "      'xcode-select --install'"
    exit 1
fi

SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
PATH="$SCRIPT_DIR/sk4d/bin":$PATH
python3 "$SCRIPT_DIR/sk4d/scripts/build.py" $@