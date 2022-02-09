/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_rrect_DEFINED
#define sk4d_rrect_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API bool sk4d_rrect_contains(const sk_rrect_t* self, const sk_rect_t* rect);
SK4D_API sk_rrect_t* sk4d_rrect_create(void);
SK4D_API sk_rrect_t* sk4d_rrect_create2(const sk_rrect_t* rrect);
SK4D_API void sk4d_rrect_deflate(sk_rrect_t* self, float dx, float dy);
SK4D_API void sk4d_rrect_destroy(sk_rrect_t* self);
SK4D_API float sk4d_rrect_get_height(const sk_rrect_t* self);
SK4D_API void sk4d_rrect_get_radii(const sk_rrect_t* self, sk_rrectcorner_t corner, /*out*/ sk_vector_t* result);
SK4D_API void sk4d_rrect_get_rect(const sk_rrect_t* self, /*out*/ sk_rect_t* result);
SK4D_API void sk4d_rrect_get_simple_radii(const sk_rrect_t* self, /*out*/ sk_vector_t* result);
SK4D_API float sk4d_rrect_get_width(const sk_rrect_t* self);
SK4D_API void sk4d_rrect_inflate(sk_rrect_t* self, float dx, float dy);
SK4D_API bool sk4d_rrect_is_complex(const sk_rrect_t* self);
SK4D_API bool sk4d_rrect_is_empty(const sk_rrect_t* self);
SK4D_API bool sk4d_rrect_is_equal(const sk_rrect_t* self, const sk_rrect_t* rrect);
SK4D_API bool sk4d_rrect_is_nine_patch(const sk_rrect_t* self);
SK4D_API bool sk4d_rrect_is_oval(const sk_rrect_t* self);
SK4D_API bool sk4d_rrect_is_rect(const sk_rrect_t* self);
SK4D_API bool sk4d_rrect_is_simple(const sk_rrect_t* self);
SK4D_API bool sk4d_rrect_is_valid(const sk_rrect_t* self);
SK4D_API void sk4d_rrect_offset(sk_rrect_t* self, float dx, float dy);
SK4D_API void sk4d_rrect_set_empty(sk_rrect_t* self);
SK4D_API void sk4d_rrect_set_nine_patch(sk_rrect_t* self, const sk_rect_t* rect, float radius_left, float radius_top, float radius_right, float radius_bottom);
SK4D_API void sk4d_rrect_set_oval(sk_rrect_t* self, const sk_rect_t* rect);
SK4D_API void sk4d_rrect_set_rect(sk_rrect_t* self, const sk_rect_t* rect);
SK4D_API void sk4d_rrect_set_rect2(sk_rrect_t* self, const sk_rect_t* rect, const sk_vector_t* radii);
SK4D_API void sk4d_rrect_set_rect3(sk_rrect_t* self, const sk_rect_t* rect, float radius_x, float radius_y);
SK4D_API sk_rrect_t* sk4d_rrect_transform(const sk_rrect_t* self, const sk_matrix_t* matrix);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
