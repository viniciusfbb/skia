/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_maskfilter.h"
#include "src/c/sk4d_mapping.h"

sk_maskfilter_t* sk4d_maskfilter_make_blur(sk_blurstyle_t style, float sigma, bool respect_ctm) {
    return ToMaskFilter(SkMaskFilter::MakeBlur(AsBlurStyle(style), sigma, respect_ctm).release());
}

sk_maskfilter_t* sk4d_maskfilter_make_shader(sk_shader_t* shader) {
    return ToMaskFilter(SkShaderMaskFilter::Make(sk_ref_sp(AsShader(shader))).release());
}

sk_maskfilter_t* sk4d_maskfilter_make_table(const uint8_t* table) {
    return ToMaskFilter(SkTableMaskFilter::Create(table));
}

sk_maskfilter_t* sk4d_maskfilter_make_table_clip(uint8_t min, uint8_t max) {
    return ToMaskFilter(SkTableMaskFilter::CreateClip(min, max));
}

sk_maskfilter_t* sk4d_maskfilter_make_table_gamma(float gamma) {
    return ToMaskFilter(SkTableMaskFilter::CreateGamma(gamma));
}
