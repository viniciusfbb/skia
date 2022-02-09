/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_colorfilter.h"
#include "src/c/sk4d_mapping.h"

sk_colorfilter_t* sk4d_colorfilter_make_blend(sk_color_t color, sk_blendmode_t mode) {
    return ToColorFilter(SkColorFilters::Blend(color, AsBlendMode(mode)).release());
}

sk_colorfilter_t* sk4d_colorfilter_make_compose(sk_colorfilter_t* outer, sk_colorfilter_t* inner) {
    return ToColorFilter(SkColorFilters::Compose(sk_ref_sp(AsColorFilter(outer)), sk_ref_sp(AsColorFilter(inner))).release());
}

sk_colorfilter_t* sk4d_colorfilter_make_high_contrast(const sk_highcontrastconfig_t* config) {
    return ToColorFilter(SkHighContrastFilter::Make(AsHighContrastConfig(*config)).release());
}

sk_colorfilter_t* sk4d_colorfilter_make_hsla_matrix(const sk_colormatrix_t* matrix) {
    return ToColorFilter(SkColorFilters::HSLAMatrix(AsColorMatrix(*matrix)).release());
}

sk_colorfilter_t* sk4d_colorfilter_make_lighting(sk_color_t multiply, sk_color_t add) {
    return ToColorFilter(SkColorMatrixFilter::MakeLightingFilter(multiply, add).release());
}

sk_colorfilter_t* sk4d_colorfilter_make_linear_to_srgb_gamma(void) {
    return ToColorFilter(SkColorFilters::LinearToSRGBGamma().release());
}

sk_colorfilter_t* sk4d_colorfilter_make_luma_color(void) {
    return ToColorFilter(SkLumaColorFilter::Make().release());
}

sk_colorfilter_t* sk4d_colorfilter_make_matrix(const sk_colormatrix_t* matrix) {
    return ToColorFilter(SkColorFilters::Matrix(AsColorMatrix(*matrix)).release());
}

sk_colorfilter_t* sk4d_colorfilter_make_overdraw(const sk_color_t* colors) {
    return ToColorFilter(SkOverdrawColorFilter::MakeWithSkColors(colors).release());
}

sk_colorfilter_t* sk4d_colorfilter_make_table(const uint8_t* tablea_a, const uint8_t* tablea_r, const uint8_t* tablea_g, const uint8_t* tablea_b) {
    return ToColorFilter(SkTableColorFilter::MakeARGB(tablea_a, tablea_r, tablea_g, tablea_b).release());
}
