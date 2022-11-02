/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_maskfilter_DEFINED
#define sk4d_maskfilter_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_maskfilter_t* sk4d_maskfilter_make_blur(sk_blurstyle_t style, float sigma, bool respect_ctm);
SK4D_API sk_maskfilter_t* sk4d_maskfilter_make_shader(sk_shader_t* shader);
SK4D_API sk_maskfilter_t* sk4d_maskfilter_make_table(const uint8_t* table);
SK4D_API sk_maskfilter_t* sk4d_maskfilter_make_table_clip(uint8_t min, uint8_t max);
SK4D_API sk_maskfilter_t* sk4d_maskfilter_make_table_gamma(float gamma);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
