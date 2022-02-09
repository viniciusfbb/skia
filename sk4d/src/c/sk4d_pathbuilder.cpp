/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_pathbuilder.h"
#include "src/c/sk4d_mapping.h"

void sk4d_pathbuilder_add_arc(sk_pathbuilder_t* self, const sk_rect_t* oval, float start_angle, float sweep_angle) {
    AsPathBuilder(self)->addArc(AsRect(*oval), start_angle, sweep_angle);
}

void sk4d_pathbuilder_add_circle(sk_pathbuilder_t* self, float center_x, float center_y, float radius, sk_pathdirection_t direction) {
    AsPathBuilder(self)->addCircle(center_x, center_y, radius, AsPathDirection(direction));
}

void sk4d_pathbuilder_add_oval(sk_pathbuilder_t* self, const sk_rect_t* oval, sk_pathdirection_t direction, uint32_t start_index) {
    AsPathBuilder(self)->addOval(AsRect(*oval), AsPathDirection(direction), start_index);
}

void sk4d_pathbuilder_add_path(sk_pathbuilder_t* self, const sk_path_t* path) {
    AsPathBuilder(self)->addPath(AsPath(*path));
}

void sk4d_pathbuilder_add_polygon(sk_pathbuilder_t* self, sk_point_t polygon[], int32_t count, bool is_closed) {
    AsPathBuilder(self)->addPolygon(AsPoint(polygon), count, is_closed);
}

void sk4d_pathbuilder_add_rect(sk_pathbuilder_t* self, const sk_rect_t* rect, sk_pathdirection_t direction, uint32_t start_index) {
    AsPathBuilder(self)->addRect(AsRect(*rect), AsPathDirection(direction), start_index);
}

void sk4d_pathbuilder_add_rrect(sk_pathbuilder_t* self, const sk_rrect_t* rrect, sk_pathdirection_t direction, uint32_t start_index) {
    AsPathBuilder(self)->addRRect(AsRRect(*rrect), AsPathDirection(direction), start_index);
}

void sk4d_pathbuilder_arc_to(sk_pathbuilder_t* self, const sk_point_t* radius, float x_axis_rotate, sk_patharcsize_t large_arc, sk_pathdirection_t sweep, const sk_point_t* xy) {
    AsPathBuilder(self)->arcTo(*AsPoint(radius), x_axis_rotate, AsPathArcSize(large_arc), AsPathDirection(sweep), *AsPoint(xy));
}

void sk4d_pathbuilder_arc_to2(sk_pathbuilder_t* self, const sk_rect_t* oval, float start_angle, float sweep_angle, bool force_move_to) {
    AsPathBuilder(self)->arcTo(AsRect(*oval), start_angle, sweep_angle, force_move_to);
}

void sk4d_pathbuilder_arc_to3(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2, float radius) {
    AsPathBuilder(self)->arcTo(*AsPoint(point1), *AsPoint(point2), radius);
}

void sk4d_pathbuilder_close(sk_pathbuilder_t* self) {
    AsPathBuilder(self)->close();
}

void sk4d_pathbuilder_conic_to(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2, float weight) {
    AsPathBuilder(self)->conicTo(*AsPoint(point1), *AsPoint(point2), weight);
}

sk_pathbuilder_t* sk4d_pathbuilder_create(void) {
    return ToPathBuilder(new SkPathBuilder());
}

sk_pathbuilder_t* sk4d_pathbuilder_create2(const sk_pathbuilder_t* path_builder) {
    return ToPathBuilder(new SkPathBuilder(AsPathBuilder(*path_builder)));
}

void sk4d_pathbuilder_cubic_to(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2, const sk_point_t* point3) {
    AsPathBuilder(self)->cubicTo(*AsPoint(point1), *AsPoint(point2), *AsPoint(point3));
}

void sk4d_pathbuilder_destroy(sk_pathbuilder_t* self) {
    delete AsPathBuilder(self);
}

sk_path_t* sk4d_pathbuilder_detach(sk_pathbuilder_t* self) {
    return ToPath(new SkPath(AsPathBuilder(self)->detach()));
}

void sk4d_pathbuilder_get_bounds(const sk_pathbuilder_t* self, sk_rect_t* result) {
    *AsRect(result) = AsPathBuilder(self)->computeBounds();
}

sk_pathfilltype_t sk4d_pathbuilder_get_fill_type(const sk_pathbuilder_t* self) {
    return ToPathFillType(AsPathBuilder(self)->fillType());
}

void sk4d_pathbuilder_inc_reserve(sk_pathbuilder_t* self, int32_t extra_point_count, int32_t extra_verb_count) {
    AsPathBuilder(self)->incReserve(extra_point_count, extra_verb_count);
}

void sk4d_pathbuilder_line_to(sk_pathbuilder_t* self, const sk_point_t* cpoint) {
    AsPathBuilder(self)->lineTo(*AsPoint(cpoint));
}

void sk4d_pathbuilder_move_to(sk_pathbuilder_t* self, const sk_point_t* cpoint) {
    AsPathBuilder(self)->moveTo(*AsPoint(cpoint));
}

void sk4d_pathbuilder_offset(sk_pathbuilder_t* self, float dx, float dy) {
    AsPathBuilder(self)->offset(dx, dy);
}

void sk4d_pathbuilder_polyline_to(sk_pathbuilder_t* self, const sk_point_t points[], int32_t count) {
    AsPathBuilder(self)->polylineTo(AsPoint(points), count);
}

void sk4d_pathbuilder_quad_to(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2) {
    AsPathBuilder(self)->quadTo(*AsPoint(point1), *AsPoint(point2));
}

void sk4d_pathbuilder_r_conic_to(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2, float weight) {
    AsPathBuilder(self)->rConicTo(*AsPoint(point1), *AsPoint(point2), weight);
}

void sk4d_pathbuilder_r_cubic_to(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2, const sk_point_t* point3) {
    AsPathBuilder(self)->rCubicTo(*AsPoint(point1), *AsPoint(point2), *AsPoint(point3));
}

void sk4d_pathbuilder_r_line_to(sk_pathbuilder_t* self, const sk_point_t* point) {
    AsPathBuilder(self)->rLineTo(*AsPoint(point));
}

void sk4d_pathbuilder_r_quad_to(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2) {
    AsPathBuilder(self)->rQuadTo(*AsPoint(point1), *AsPoint(point2));
}

void sk4d_pathbuilder_reset(sk_pathbuilder_t* self) {
    AsPathBuilder(self)->reset();
}

void sk4d_pathbuilder_set_filltype(sk_pathbuilder_t* self, sk_pathfilltype_t value) {
    AsPathBuilder(self)->setFillType(AsPathFillType(value));
}

sk_path_t* sk4d_pathbuilder_snapshot(const sk_pathbuilder_t* self) {
    return ToPath(new SkPath(AsPathBuilder(self)->snapshot()));
}

void sk4d_pathbuilder_toggle_inverse_filltype(sk_pathbuilder_t* self) {
    AsPathBuilder(self)->toggleInverseFillType();
}
