/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_region_DEFINED
#define sk4d_region_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API bool sk4d_region_contains(const sk_region_t* self, const sk_region_t* region);
SK4D_API bool sk4d_region_contains2(const sk_region_t* self, const sk_irect_t* rect);
SK4D_API bool sk4d_region_contains3(const sk_region_t* self, int32_t x, int32_t y);
SK4D_API sk_region_t* sk4d_region_create(void);
SK4D_API sk_region_t* sk4d_region_create2(const sk_region_t* region);
SK4D_API void sk4d_region_destroy(sk_region_t* self);
SK4D_API sk_path_t* sk4d_region_get_boundary_path(const sk_region_t* self);
SK4D_API void sk4d_region_get_bounds(const sk_region_t* self, /*out*/ sk_irect_t* result);
SK4D_API bool sk4d_region_intersects(const sk_region_t* self, const sk_region_t* region);
SK4D_API bool sk4d_region_intersects2(const sk_region_t* self, const sk_irect_t* rect);
SK4D_API bool sk4d_region_is_complex(const sk_region_t* self);
SK4D_API bool sk4d_region_is_empty(const sk_region_t* self);
SK4D_API bool sk4d_region_is_equal(const sk_region_t* self, const sk_region_t* region);
SK4D_API bool sk4d_region_is_rect(const sk_region_t* self);
SK4D_API bool sk4d_region_op(sk_region_t* self, const sk_region_t* region, sk_regionop_t op);
SK4D_API bool sk4d_region_op2(sk_region_t* self, const sk_irect_t* rect, sk_regionop_t op);
SK4D_API bool sk4d_region_quick_contains(const sk_region_t* self, const sk_irect_t* rect);
SK4D_API bool sk4d_region_quick_reject(const sk_region_t* self, const sk_region_t* region);
SK4D_API bool sk4d_region_quick_reject2(const sk_region_t* self, const sk_irect_t* rect);
SK4D_API void sk4d_region_set_empty(sk_region_t* self);
SK4D_API bool sk4d_region_set_path(sk_region_t* self, const sk_path_t* path, const sk_region_t* clip);
SK4D_API bool sk4d_region_set_rect(sk_region_t* self, const sk_irect_t* rect);
SK4D_API bool sk4d_region_set_rects(sk_region_t* self, const sk_irect_t rects[], int32_t count);
SK4D_API void sk4d_region_translate(sk_region_t* self, int32_t x, int32_t y);
SK4D_API sk_regioncliperator_t* sk4d_regioncliperator_create(const sk_region_t* region, const sk_irect_t* clip);
SK4D_API void sk4d_regioncliperator_destroy(sk_regioncliperator_t* self);
SK4D_API void sk4d_regioncliperator_get_current(const sk_regioncliperator_t* self, /*out*/ sk_irect_t* result);
SK4D_API bool sk4d_regioncliperator_move_next(sk_regioncliperator_t* self);
SK4D_API sk_regioniterator_t* sk4d_regioniterator_create(const sk_region_t* region);
SK4D_API void sk4d_regioniterator_destroy(sk_regioniterator_t* self);
SK4D_API void sk4d_regioniterator_get_current(const sk_regioniterator_t* self, /*out*/ sk_irect_t* result);
SK4D_API bool sk4d_regioniterator_move_next(sk_regioniterator_t* self);
SK4D_API void sk4d_regioniterator_reset(sk_regioniterator_t* self);
SK4D_API sk_regionspanerator_t* sk4d_regionspanerator_create(const sk_region_t* region, int32_t y, int32_t left, int32_t right);
SK4D_API void sk4d_regionspanerator_destroy(sk_regionspanerator_t* self);
SK4D_API bool sk4d_regionspanerator_next(sk_regionspanerator_t* self, /*out*/ sk_ipoint_t* elem);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
