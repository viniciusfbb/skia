/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_picture_DEFINED
#define sk4d_picture_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API void sk4d_picture_get_cull_rect(const sk_picture_t* self, /*out*/ sk_rect_t* result);
SK4D_API sk_picture_t* sk4d_picture_make_from_stream(sk_stream_t* stream);
SK4D_API sk_shader_t* sk4d_picture_make_shader(const sk_picture_t* self, sk_tilemode_t tile_mode_x, sk_tilemode_t tile_mode_y, sk_filtermode_t filter_mode, const sk_matrix_t* local_matrix, const sk_rect_t* tile_rect);
SK4D_API void sk4d_picture_playback(const sk_picture_t* self, sk_canvas_t* canvas);
SK4D_API void sk4d_picture_serialize_to_stream(const sk_picture_t* self, sk_wstream_t* w_stream);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
