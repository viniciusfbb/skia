/*
 * Copyright (c) 1991-2022 Lucent Technologies.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_dtoa_DEFINED
#define sk4d_dtoa_DEFINED

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

double sk4d_strtod(const char* str, char** endptr);

#ifdef __cplusplus
}
#endif

#endif

