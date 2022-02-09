/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_colorspace_DEFINED
#define sk4d_colorspace_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_patheffect_t* sk4d_patheffect_make_1dpath(const sk_path_t* path, float advance, float phase, sk_patheffect1dstyle_t style);
SK4D_API sk_patheffect_t* sk4d_patheffect_make_2dline(float width, const sk_matrix_t* matrix);
SK4D_API sk_patheffect_t* sk4d_patheffect_make_2dpath(const sk_matrix_t* matrix, const sk_path_t* path);
SK4D_API sk_patheffect_t* sk4d_patheffect_make_compose(sk_patheffect_t* outer, sk_patheffect_t* inner);
SK4D_API sk_patheffect_t* sk4d_patheffect_make_corner(float radius);
SK4D_API sk_patheffect_t* sk4d_patheffect_make_dash(const float intervals[], int32_t count, float phase);
SK4D_API sk_patheffect_t* sk4d_patheffect_make_discrete(float seg_length, float deviation, uint32_t seed_assist);
SK4D_API sk_patheffect_t* sk4d_patheffect_make_matrix(const sk_matrix_t* matrix);
SK4D_API sk_patheffect_t* sk4d_patheffect_make_merge(sk_patheffect_t* effect1, sk_patheffect_t* effect2, sk_pathop_t op);
SK4D_API sk_patheffect_t* sk4d_patheffect_make_stroke(float width, sk_strokejoin_t join, sk_strokecap_t cap, float miter);
SK4D_API sk_patheffect_t* sk4d_patheffect_make_stroke_and_fill(void);
SK4D_API sk_patheffect_t* sk4d_patheffect_make_sum(sk_patheffect_t* effect1, sk_patheffect_t* effect2);
SK4D_API sk_patheffect_t* sk4d_patheffect_make_translate(float dx, float dy);
SK4D_API sk_patheffect_t* sk4d_patheffect_make_trim(float start, float stop, sk_patheffecttrimmode_t mode);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
