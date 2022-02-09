/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_picturerecorder_DEFINED
#define sk4d_picturerecorder_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_canvas_t* sk4d_picturerecorder_begin_recording(sk_picturerecorder_t* self, const sk_rect_t* bounds);
SK4D_API sk_picturerecorder_t* sk4d_picturerecorder_create(void);
SK4D_API void sk4d_picturerecorder_destroy(sk_picturerecorder_t* self);
SK4D_API sk_picture_t* sk4d_picturerecorder_finish_recording(sk_picturerecorder_t* self);
SK4D_API sk_picture_t* sk4d_picturerecorder_finish_recording2(sk_picturerecorder_t* self, const sk_rect_t* cull_rect);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
