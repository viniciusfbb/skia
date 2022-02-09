#!/usr/bin/env python
#
# Copyright (c) 2011-2022 Google LLC.
# Copyright (c) 2021-2022 Skia4Delphi Project.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import argparse
import os
import sys


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('input', help='Input Assembly file')
    parser.add_argument('output', help='Output CC file')
    args = parser.parse_args()
    if not os.path.exists(args.input):
        sys.exit('Input file not found: "%s"' % args.input)
    with open(args.input, 'r') as input_file, open(args.output, 'wb') as output_file:
        output_file.write('__asm__(\n'.encode('ascii'))
        for i in input_file:
            out_line = '  "%s\\n"\n' % i.replace('"', '\\"').rstrip()
            output_file.write(out_line.encode('ascii'))
        output_file.write(');\n'.encode('ascii'))


if __name__ == '__main__':
    main()
