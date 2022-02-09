/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_pathmeasure_DEFINED
#define sk4d_pathmeasure_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_pathmeasure_t* sk4d_pathmeasure_create(const sk_path_t* path, bool force_closed, float res_scale);
SK4D_API void sk4d_pathmeasure_destroy(sk_pathmeasure_t* self);
SK4D_API float sk4d_pathmeasure_get_length(sk_pathmeasure_t* self);
SK4D_API bool sk4d_pathmeasure_get_matrix(sk_pathmeasure_t* self, float distance, /*out*/ sk_matrix_t* matrix, uint32_t matrix_flags);
SK4D_API bool sk4d_pathmeasure_get_position_and_tangent(sk_pathmeasure_t* self, float distance, /*out*/ sk_point_t* position, /*out*/ sk_vector_t* tangent);
SK4D_API sk_path_t* sk4d_pathmeasure_get_segment(sk_pathmeasure_t* self, float start, float stop, bool start_with_move_to);
SK4D_API bool sk4d_pathmeasure_is_closed(sk_pathmeasure_t* self);
SK4D_API bool sk4d_pathmeasure_next_contour(sk_pathmeasure_t* self);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
