#!/usr/bin/env python
#
# Copyright (c) 2011-2022 Google LLC.
# Copyright (c) 2021-2022 Skia4Delphi Project.
#
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

from __future__ import print_function

import argparse
import binascii
import os
import sys


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('input', help='Input ICU .dat file')
    parser.add_argument('output', help='Output Assembly file')
    parser.add_argument('--mac', action='store_true', default=False, help='Generate assembly file for Mac/iOS')
    parser.add_argument('--win', action='store_true', default=False, help='Generate assembly file for Windows')
    parser.add_argument('--cpp', action='store_true', default=False, help='Generate assembly file for CPP')
    parser.add_argument('--pu', action='store_true', default=False, help='Add underscore prefix')
    args = parser.parse_args()
    if not os.path.exists(args.input):
        sys.exit('Input file not found: "%s"' % args.input)
    if args.input.endswith('l.dat'):
        step = -1
    elif args.input.endswith('b.dat'):
        step = 1
    else:
        sys.exit('Invalid input file: "%s"' % args.input)
    with open(args.input, 'rb') as input_file:
        input_data = input_file.read()
    i = input_data.find('icudt'.encode('ascii'))
    if i == -1:
        sys.exit('Cannot find a version in input file: "%s"' % args.input)
    version = input_data[i + 5:i + 7].decode('ascii')
    pu = '_' if args.pu else ''
    with open(args.output, 'wb') as output_file:
        if args.cpp:
            output_file.write(('#include <cstdint>\n'
                               'extern "C" uint32_t icudt%s_dat[] '
                               '__attribute__((aligned(16))) = {' % version).encode('ascii'))
        elif args.mac:
            output_file.write(('.globl {1}icudt{0}_dat\n'
                               '#ifdef U_HIDE_DATA_SYMBOL\n'
                               '\t.private_extern {1}icudt{0}_dat\n'
                               '#endif\n'
                               '\t.data\n'
                               '\t.const\n'
                               '\t.align 4\n'
                               '{1}icudt{0}_dat:\n').format(version, pu).encode('ascii'))
        elif args.win:
            output_file.write(('.globl {1}icudt{0}_dat\n'
                               '\t.section .rdata\n'
                               '\t.balign 16\n'
                               '{1}icudt{0}_dat:\n').format(version, pu).encode('ascii'))
        else:
            output_file.write(('.globl {1}icudt{0}_dat\n'
                               '\t.section .note.GNU-stack,"",%progbits\n'
                               '\t.section .rodata\n'
                               '\t.balign 16\n'
                               '#ifdef U_HIDE_DATA_SYMBOL\n'
                               '\t.hidden {1}icudt{0}_dat\n'
                               '#endif\n'
                               '\t.type {1}icudt{0}_dat,%object\n'
                               '{1}icudt{0}_dat:\n').format(version, pu).encode('ascii'))

        split = []
        for i in range(0, len(input_data), 4):
            split.append(binascii.hexlify(input_data[i:i + 4][::step]).decode('ascii').upper().lstrip('0'))
        for i in range(len(split)):
            if len(split[i]) == 0:
                value = '0'
            elif len(split[i]) == 1:
                if not any((c in '123456789') for c in split[i]):
                    value = '0x0' + split[i]
                else:
                    value = split[i]
            elif len(split[i]) % 2 == 1:
                value = '0x0' + split[i]
            else:
                value = '0x' + split[i]
            if i % 32 == 0:
                if args.cpp:
                    if i >= 32:
                        output_file.write(','.encode('ascii'))
                    output_file.write('\n\t'.encode('ascii'))
                else:
                    output_file.write('\n.long '.encode('ascii'))
            else:
                output_file.write(','.encode('ascii'))
            output_file.write(value.encode('ascii'))
        output_file.write('\n'.encode('ascii'))
        if args.cpp:
            output_file.write('};'.encode('ascii'))
        output_file.close()
        print('Generated %s' % args.output)


if __name__ == '__main__':
    main()
