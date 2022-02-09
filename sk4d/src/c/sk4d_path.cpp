/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <memory>

#include "include/c/sk4d_path.h"
#include "src/c/sk4d_mapping.h"

void sk4d_opbuilder_add(sk_opbuilder_t* self, const sk_path_t* path, sk_pathop_t op) {
    AsOpBuilder(self)->add(AsPath(*path), AsPathOp(op));
}

sk_opbuilder_t* sk4d_opbuilder_create(void) {
    return ToOpBuilder(new SkOpBuilder());
}

void sk4d_opbuilder_destroy(sk_opbuilder_t* self) {
    delete AsOpBuilder(self);
}

sk_path_t* sk4d_opbuilder_detach(sk_opbuilder_t* self) {
    auto r = std::make_unique<SkPath>();
    return AsOpBuilder(self)->resolve(r.get()) ? ToPath(r.release()) : nullptr;
}

bool sk4d_path_contains(const sk_path_t* self, float x, float y) {
    return AsPath(self)->contains(x, y);
}

int32_t sk4d_path_convert_conic_to_quads(const sk_point_t* point1, const sk_point_t* point2, const sk_point_t* point3, float weight, sk_point_t points[], int32_t power2) {
    return SkPath::ConvertConicToQuads(AsPoint(*point1), AsPoint(*point2), AsPoint(*point3), weight, AsPoint(points), power2);
}

sk_path_t* sk4d_path_create(const char svg[]) {
    auto r = new SkPath();
    SkParsePath::FromSVGString(svg, r);
    return ToPath(r);
}

sk_path_t* sk4d_path_create2(sk_stream_t* stream) {
    auto r = new SkPath();
    if (AsStream(stream)->hasLength()) {
        auto data = SkData::MakeFromStream(AsStream(stream), AsStream(stream)->getLength());
        if (data)
            r->readFromMemory(data->data(), data->size());
    }
    return ToPath(r);
}

void sk4d_path_destroy(sk_path_t* self) {
    delete AsPath(self);
}

void sk4d_path_get_bounds(const sk_path_t* self, sk_rect_t* result) {
    *result = ToRect(AsPath(self)->getBounds());
}

sk_pathfilltype_t sk4d_path_get_fill_type(const sk_path_t* self) {
    return ToPathFillType(AsPath(self)->getFillType());
}

bool sk4d_path_get_last_point(const sk_path_t* self, sk_point_t* result) {
    return AsPath(self)->getLastPt(AsPoint(result));
}

uint32_t sk4d_path_get_segment_masks(const sk_path_t* self) {
    return AsPath(self)->getSegmentMasks();
}

void sk4d_path_get_tight_bounds(const sk_path_t* self, sk_rect_t* result) {
    *result = ToRect(AsPath(self)->computeTightBounds());
}

sk_path_t* sk4d_path_interpolate(const sk_path_t* self, const sk_path_t* cending, float weight) {
    auto r = std::make_unique<SkPath>();
    return AsPath(self)->interpolate(AsPath(*cending), weight, r.get()) ? ToPath(r.release()) : nullptr;
}

bool sk4d_path_is_convex(const sk_path_t* self) {
    return AsPath(self)->isConvex();
}

bool sk4d_path_is_empty(const sk_path_t* self) {
    return AsPath(self)->isEmpty();
}

bool sk4d_path_is_finite(const sk_path_t* self) {
    return AsPath(self)->isFinite();
}

bool sk4d_path_is_interpolatable(const sk_path_t* self, const sk_path_t* path) {
    return AsPath(self)->isInterpolatable(AsPath(*path));
}

bool sk4d_path_is_last_contour_closed(const sk_path_t* self) {
    return AsPath(self)->isLastContourClosed();
}

bool sk4d_path_is_line(const sk_path_t* self, sk_point_t lines[2]) {
    return AsPath(self)->isLine(AsPoint(lines));
}

bool sk4d_path_is_oval(const sk_path_t* self, sk_rect_t* oval) {
    return AsPath(self)->isOval(AsRect(oval));
}

bool sk4d_path_is_rect(const sk_path_t* self, sk_rect_t* rect) {
    return AsPath(self)->isOval(AsRect(rect));
}

bool sk4d_path_is_rrect(const sk_path_t* self, sk_rrect_t* rrect) {
    return AsPath(self)->isRRect(AsRRect(rrect));
}

void sk4d_path_serialize_to_stream(const sk_path_t* self, sk_wstream_t* w_stream) {
    sk_sp<SkData> data(AsPath(self)->serialize());
    AsWStream(w_stream)->write(data->data(), data->size());
}

sk_string_t* sk4d_path_to_svg(const sk_path_t* self) {
    auto r = new SkString();
    SkParsePath::ToSVGString(AsPath(*self), r);
    return ToString(r);
}

sk_path_t* sk4d_path_transform(const sk_path_t* self, const sk_matrix_t* matrix) {
    auto r = new SkPath();
    AsPath(self)->transform(AsMatrix(matrix), r);
    return ToPath(r);
}

sk_pathiterator_t* sk4d_pathiterator_create(const sk_path_t* path, bool force_close) {
    return ToPathIterator(new SkPath::Iter(AsPath(*path), force_close));
}

void sk4d_pathiterator_destroy(sk_pathiterator_t* self) {
    delete AsPathIterator(self);
}

bool sk4d_pathiterator_next(sk_pathiterator_t* self, sk_pathiteratorelem_t* elem) {
    SkPoint points[4];
    auto verb = AsPathIterator(self)->next(AsPoint(&elem->points[0]));
    if (verb == SkPath::kDone_Verb)
        return false;
    elem->verb = ToPathVerb(verb);
    if (verb == SkPath::kConic_Verb)
        elem->conic_weight = AsPathIterator(self)->conicWeight();
    return true;
}
