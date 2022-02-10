/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_svgcanvas_DEFINED
#define sk4d_svgcanvas_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_canvas_t* sk4d_svgcanvas_make(const sk_rect_t* bounds, sk_wstream_t* w_stream, uint32_t flags);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
