/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_data_DEFINED
#define sk4d_data_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_data_t* sk4d_data_make_empty(void);
SK4D_API sk_data_t* sk4d_data_make_with_copy(const void* data, size_t size);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
