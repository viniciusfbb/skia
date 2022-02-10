/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_svgcanvas.h"
#include "src/c/sk4d_mapping.h"

sk_canvas_t* sk4d_svgcanvas_make(const sk_rect_t* bounds, sk_wstream_t* w_stream, uint32_t flags) {
    return ToCanvas(SkSVGCanvas::Make(AsRect(*bounds), AsWStream(w_stream), flags).release());
}
