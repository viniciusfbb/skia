/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_pathbuilder_DEFINED
#define sk4d_pathbuilder_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API void sk4d_pathbuilder_add_arc(sk_pathbuilder_t* self, const sk_rect_t* oval, float start_angle, float sweep_angle);
SK4D_API void sk4d_pathbuilder_add_circle(sk_pathbuilder_t* self, float center_x, float center_y, float radius, sk_pathdirection_t direction);
SK4D_API void sk4d_pathbuilder_add_oval(sk_pathbuilder_t* self, const sk_rect_t* oval, sk_pathdirection_t direction, uint32_t start_index);
SK4D_API void sk4d_pathbuilder_add_path(sk_pathbuilder_t* self, const sk_path_t* path);
SK4D_API void sk4d_pathbuilder_add_polygon(sk_pathbuilder_t* self, sk_point_t polygon[], int32_t count, bool is_closed);
SK4D_API void sk4d_pathbuilder_add_rect(sk_pathbuilder_t* self, const sk_rect_t* rect, sk_pathdirection_t direction, uint32_t start_index);
SK4D_API void sk4d_pathbuilder_add_rrect(sk_pathbuilder_t* self, const sk_rrect_t* rrect, sk_pathdirection_t direction, uint32_t start_index);
SK4D_API void sk4d_pathbuilder_arc_to(sk_pathbuilder_t* self, const sk_point_t* radius, float x_axis_rotate, sk_patharcsize_t large_arc, sk_pathdirection_t sweep, const sk_point_t* xy);
SK4D_API void sk4d_pathbuilder_arc_to2(sk_pathbuilder_t* self, const sk_rect_t* oval, float start_angle, float sweep_angle, bool force_move_to);
SK4D_API void sk4d_pathbuilder_arc_to3(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2, float radius);
SK4D_API void sk4d_pathbuilder_close(sk_pathbuilder_t* self);
SK4D_API void sk4d_pathbuilder_conic_to(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2, float weight);
SK4D_API sk_pathbuilder_t* sk4d_pathbuilder_create(void);
SK4D_API sk_pathbuilder_t* sk4d_pathbuilder_create2(const sk_pathbuilder_t* path_builder);
SK4D_API void sk4d_pathbuilder_cubic_to(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2, const sk_point_t* point3);
SK4D_API void sk4d_pathbuilder_destroy(sk_pathbuilder_t* self);
SK4D_API sk_path_t* sk4d_pathbuilder_detach(sk_pathbuilder_t* self);
SK4D_API void sk4d_pathbuilder_get_bounds(const sk_pathbuilder_t* self, /*out*/ sk_rect_t* result);
SK4D_API sk_pathfilltype_t sk4d_pathbuilder_get_fill_type(const sk_pathbuilder_t* self);
SK4D_API void sk4d_pathbuilder_inc_reserve(sk_pathbuilder_t* self, int32_t extra_point_count, int32_t extra_verb_count);
SK4D_API void sk4d_pathbuilder_line_to(sk_pathbuilder_t* self, const sk_point_t* cpoint);
SK4D_API void sk4d_pathbuilder_move_to(sk_pathbuilder_t* self, const sk_point_t* cpoint);
SK4D_API void sk4d_pathbuilder_offset(sk_pathbuilder_t* self, float dx, float dy);
SK4D_API void sk4d_pathbuilder_polyline_to(sk_pathbuilder_t* self, const sk_point_t points[], int32_t count);
SK4D_API void sk4d_pathbuilder_quad_to(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2);
SK4D_API void sk4d_pathbuilder_r_conic_to(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2, float weight);
SK4D_API void sk4d_pathbuilder_r_cubic_to(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2, const sk_point_t* point3);
SK4D_API void sk4d_pathbuilder_r_line_to(sk_pathbuilder_t* self, const sk_point_t* point);
SK4D_API void sk4d_pathbuilder_r_quad_to(sk_pathbuilder_t* self, const sk_point_t* point1, const sk_point_t* point2);
SK4D_API void sk4d_pathbuilder_reset(sk_pathbuilder_t* self);
SK4D_API void sk4d_pathbuilder_set_filltype(sk_pathbuilder_t* self, sk_pathfilltype_t value);
SK4D_API sk_path_t* sk4d_pathbuilder_snapshot(const sk_pathbuilder_t* self);
SK4D_API void sk4d_pathbuilder_toggle_inverse_filltype(sk_pathbuilder_t* self);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
