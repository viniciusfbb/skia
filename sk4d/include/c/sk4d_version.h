/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_version_DEFINED
#define sk4d_version_DEFINED

#include "include/c/sk4d_types.h"

#define SK4D_VERSION_MAJOR SK_MILESTONE
#define SK4D_VERSION_MINOR 0
#define SK4D_VERSION_BUILD 0

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API int32_t sk4d_library_version_get_build(void);
SK4D_API int32_t sk4d_library_version_get_major(void);
SK4D_API int32_t sk4d_library_version_get_minor(void);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
