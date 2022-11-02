/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_colorfilter_DEFINED
#define sk4d_colorfilter_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_colorfilter_t* sk4d_colorfilter_make_blend(sk_color_t color, sk_blendmode_t mode);
SK4D_API sk_colorfilter_t* sk4d_colorfilter_make_compose(sk_colorfilter_t* outer, sk_colorfilter_t* inner);
SK4D_API sk_colorfilter_t* sk4d_colorfilter_make_high_contrast(const sk_highcontrastconfig_t* config);
SK4D_API sk_colorfilter_t* sk4d_colorfilter_make_hsla_matrix(const sk_colormatrix_t* matrix);
SK4D_API sk_colorfilter_t* sk4d_colorfilter_make_lighting(sk_color_t multiply, sk_color_t add);
SK4D_API sk_colorfilter_t* sk4d_colorfilter_make_linear_to_srgb_gamma(void);
SK4D_API sk_colorfilter_t* sk4d_colorfilter_make_luma_color(void);
SK4D_API sk_colorfilter_t* sk4d_colorfilter_make_matrix(const sk_colormatrix_t* matrix);
SK4D_API sk_colorfilter_t* sk4d_colorfilter_make_overdraw(const sk_color_t* colors);
SK4D_API sk_colorfilter_t* sk4d_colorfilter_make_table(const uint8_t* tablea_a, const uint8_t* tablea_r, const uint8_t* tablea_g, const uint8_t* tablea_b);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
