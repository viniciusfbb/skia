/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_patheffect.h"
#include "src/c/sk4d_mapping.h"

sk_patheffect_t* sk4d_patheffect_make_1dpath(const sk_path_t* path, float advance, float phase, sk_patheffect1dstyle_t style) {
    return ToPathEffect(SkPath1DPathEffect::Make(AsPath(*path), advance, phase, AsPathEffect1DStyle(style)).release());
}

sk_patheffect_t* sk4d_patheffect_make_2dline(float width, const sk_matrix_t* matrix) {
    return ToPathEffect(SkLine2DPathEffect::Make(width, AsMatrix(matrix)).release());
}

sk_patheffect_t* sk4d_patheffect_make_2dpath(const sk_matrix_t* matrix, const sk_path_t* path) {
    return ToPathEffect(SkPath2DPathEffect::Make(AsMatrix(matrix), AsPath(*path)).release());
}

sk_patheffect_t* sk4d_patheffect_make_compose(sk_patheffect_t* outer, sk_patheffect_t* inner) {
    return ToPathEffect(SkPathEffect::MakeCompose(sk_ref_sp(AsPathEffect(outer)), sk_ref_sp(AsPathEffect(inner))).release());
}

sk_patheffect_t* sk4d_patheffect_make_corner(float radius) {
    return ToPathEffect(SkCornerPathEffect::Make(radius).release());
}

sk_patheffect_t* sk4d_patheffect_make_dash(const float intervals[], int32_t count, float phase) {
    return ToPathEffect(SkDashPathEffect::Make(intervals, count, phase).release());
}

sk_patheffect_t* sk4d_patheffect_make_discrete(float seg_length, float deviation, uint32_t seed_assist) {
    return ToPathEffect(SkDiscretePathEffect::Make(seg_length, deviation, seed_assist).release());
}

sk_patheffect_t* sk4d_patheffect_make_matrix(const sk_matrix_t* matrix) {
    return ToPathEffect(SkMatrixPathEffect::Make(AsMatrix(matrix)).release());
}

sk_patheffect_t* sk4d_patheffect_make_merge(sk_patheffect_t* effect1, sk_patheffect_t* effect2, sk_pathop_t op) {
    return ToPathEffect(SkMergePathEffect::Make(sk_ref_sp(AsPathEffect(effect1)), sk_ref_sp(AsPathEffect(effect2)), AsPathOp(op)).release());
}

sk_patheffect_t* sk4d_patheffect_make_stroke(float width, sk_strokejoin_t join, sk_strokecap_t cap, float miter) {
    return ToPathEffect(SkStrokePathEffect::Make(width, AsStrokeJoin(join), AsStrokeCap(cap), miter).release());
}

sk_patheffect_t* sk4d_patheffect_make_stroke_and_fill(void) {
    return ToPathEffect(SkStrokeAndFillPathEffect::Make().release());
}

sk_patheffect_t* sk4d_patheffect_make_sum(sk_patheffect_t* effect1, sk_patheffect_t* effect2) {
    return ToPathEffect(SkPathEffect::MakeSum(sk_ref_sp(AsPathEffect(effect1)), sk_ref_sp(AsPathEffect(effect2))).release());
}

sk_patheffect_t* sk4d_patheffect_make_translate(float dx, float dy) {
    return ToPathEffect(SkMatrixPathEffect::MakeTranslate(dx, dy).release());
}

sk_patheffect_t* sk4d_patheffect_make_trim(float start, float stop, sk_patheffecttrimmode_t mode) {
    return ToPathEffect(SkTrimPathEffect::Make(start, stop, AsPathEffectTrimMode(mode)).release());
}
