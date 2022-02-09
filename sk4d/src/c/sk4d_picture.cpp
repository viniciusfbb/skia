/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_picture.h"
#include "src/c/sk4d_mapping.h"

void sk4d_picture_get_cull_rect(const sk_picture_t* self, sk_rect_t* result) {
    *result = ToRect(AsPicture(self)->cullRect());
}

sk_picture_t* sk4d_picture_make_from_stream(sk_stream_t* stream) {
    return ToPicture(SkPicture::MakeFromStream(AsStream(stream)).release());
}

sk_shader_t* sk4d_picture_make_shader(const sk_picture_t* self, sk_tilemode_t tile_mode_x, sk_tilemode_t tile_mode_y, sk_filtermode_t filter_mode, const sk_matrix_t* local_matrix, const sk_rect_t* tile_rect) {
    SkMatrix m;
    if (local_matrix)
      m = AsMatrix(local_matrix);
    return ToShader(AsPicture(self)->makeShader(AsTileMode(tile_mode_x), AsTileMode(tile_mode_y), AsFilterMode(filter_mode), (local_matrix) ? &m : nullptr, AsRect(tile_rect)).release());
}

void sk4d_picture_playback(const sk_picture_t* self, sk_canvas_t* canvas) {
    AsPicture(self)->playback(AsCanvas(canvas));
}

void sk4d_picture_serialize_to_stream(const sk_picture_t* self, sk_wstream_t* w_stream) {
    AsPicture(self)->serialize(AsWStream(w_stream));
}
