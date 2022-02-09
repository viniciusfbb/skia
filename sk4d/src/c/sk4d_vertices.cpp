/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_vertices.h"
#include "src/c/sk4d_mapping.h"

sk_vertices_t* sk4d_vertices_make_copy(sk_vertexmode_t vertex_mode, int32_t vertex_count, const sk_point_t* positions, const sk_point_t* textures, const sk_color_t* colors, int32_t index_count, const uint16_t* indices) {
    return ToVertices(SkVertices::MakeCopy(AsVertexMode(vertex_mode), vertex_count, AsPoint(positions), AsPoint(textures), colors, index_count, indices).release());
}

void sk4d_vertices_ref(const sk_vertices_t* self) {
    AsVertices(self)->ref();
}

void sk4d_vertices_unref(const sk_vertices_t* self) {
    AsVertices(self)->unref();
}
