/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_vertices_DEFINED
#define sk4d_vertices_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_vertices_t* sk4d_vertices_make_copy(sk_vertexmode_t vertex_mode, int32_t vertex_count, const sk_point_t* positions, const sk_point_t* textures, const sk_color_t* colors, int32_t index_count, const uint16_t* indices);
SK4D_API void sk4d_vertices_ref(const sk_vertices_t* self);
SK4D_API void sk4d_vertices_unref(const sk_vertices_t* self);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
