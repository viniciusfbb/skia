/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_path_DEFINED
#define sk4d_path_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API void sk4d_opbuilder_add(sk_opbuilder_t* self, const sk_path_t* path, sk_pathop_t op);
SK4D_API sk_opbuilder_t* sk4d_opbuilder_create(void);
SK4D_API void sk4d_opbuilder_destroy(sk_opbuilder_t* self);
SK4D_API sk_path_t* sk4d_opbuilder_detach(sk_opbuilder_t* self);
SK4D_API bool sk4d_path_contains(const sk_path_t* self, float x, float y);
SK4D_API int32_t sk4d_path_convert_conic_to_quads(const sk_point_t* point1, const sk_point_t* point2, const sk_point_t* point3, float weight, sk_point_t points[], int32_t power2);
SK4D_API sk_path_t* sk4d_path_create(const char svg[]);
SK4D_API sk_path_t* sk4d_path_create2(sk_stream_t* stream);
SK4D_API void sk4d_path_destroy(sk_path_t* self);
SK4D_API void sk4d_path_get_bounds(const sk_path_t* self, /*out*/ sk_rect_t* result);
SK4D_API sk_pathfilltype_t sk4d_path_get_fill_type(const sk_path_t* self);
SK4D_API bool sk4d_path_get_last_point(const sk_path_t* self, /*out*/ sk_point_t* result);
SK4D_API uint32_t sk4d_path_get_segment_masks(const sk_path_t* self);
SK4D_API void sk4d_path_get_tight_bounds(const sk_path_t* self, /*out*/ sk_rect_t* result);
SK4D_API sk_path_t* sk4d_path_interpolate(const sk_path_t* self, const sk_path_t* cending, float weight);
SK4D_API bool sk4d_path_is_convex(const sk_path_t* self);
SK4D_API bool sk4d_path_is_empty(const sk_path_t* self);
SK4D_API bool sk4d_path_is_finite(const sk_path_t* self);
SK4D_API bool sk4d_path_is_interpolatable(const sk_path_t* self, const sk_path_t* path);
SK4D_API bool sk4d_path_is_last_contour_closed(const sk_path_t* self);
SK4D_API bool sk4d_path_is_line(const sk_path_t* self, sk_point_t lines[2]);
SK4D_API bool sk4d_path_is_oval(const sk_path_t* self, sk_rect_t* oval);
SK4D_API bool sk4d_path_is_rect(const sk_path_t* self, sk_rect_t* rect);
SK4D_API bool sk4d_path_is_rrect(const sk_path_t* self, sk_rrect_t* rrect);
SK4D_API void sk4d_path_serialize_to_stream(const sk_path_t* self, sk_wstream_t* w_stream);
SK4D_API sk_string_t* sk4d_path_to_svg(const sk_path_t* self);
SK4D_API sk_path_t* sk4d_path_transform(const sk_path_t* self, const sk_matrix_t* matrix);
SK4D_API sk_pathiterator_t* sk4d_pathiterator_create(const sk_path_t* path, bool force_close);
SK4D_API void sk4d_pathiterator_destroy(sk_pathiterator_t* self);
SK4D_API bool sk4d_pathiterator_next(sk_pathiterator_t* self, /*out*/ sk_pathiteratorelem_t* elem);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
