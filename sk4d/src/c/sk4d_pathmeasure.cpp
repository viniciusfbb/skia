/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <memory>

#include "include/c/sk4d_pathmeasure.h"
#include "src/c/sk4d_mapping.h"

sk_pathmeasure_t* sk4d_pathmeasure_create(const sk_path_t* path, bool force_closed, float res_scale) {
    return ToPathMeasure(new SkPathMeasure(AsPath(*path), force_closed, res_scale));
}

void sk4d_pathmeasure_destroy(sk_pathmeasure_t* self) {
    delete AsPathMeasure(self);
}

float sk4d_pathmeasure_get_length(sk_pathmeasure_t* self) {
    return AsPathMeasure(self)->getLength();
}

bool sk4d_pathmeasure_get_matrix(sk_pathmeasure_t* self, float distance, sk_matrix_t* matrix, uint32_t matrix_flags) {
    SkMatrix m;
    bool result = AsPathMeasure(self)->getMatrix(distance, &m, AsPathMeasureMatrixFlags(matrix_flags));
    if (result)
      *matrix = ToMatrix(m);
    return result;
}

bool sk4d_pathmeasure_get_position_and_tangent(sk_pathmeasure_t* self, float distance, sk_point_t* position, sk_vector_t* tangent) {
    return AsPathMeasure(self)->getPosTan(distance, AsPoint(position), AsVector(tangent));
}

sk_path_t* sk4d_pathmeasure_get_segment(sk_pathmeasure_t* self, float start, float stop, bool start_with_move_to) {
    auto r = std::make_unique<SkPath>();
    return AsPathMeasure(self)->getSegment(start, stop, r.get(), start_with_move_to) ? ToPath(r.release()) : nullptr;
}

bool sk4d_pathmeasure_is_closed(sk_pathmeasure_t* self) {
    return AsPathMeasure(self)->isClosed();
}

bool sk4d_pathmeasure_next_contour(sk_pathmeasure_t* self) {
    return AsPathMeasure(self)->nextContour();
}
