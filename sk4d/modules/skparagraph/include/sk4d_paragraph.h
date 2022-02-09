/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_paragraph_DEFINED
#define sk4d_paragraph_DEFINED

#include "modules/skparagraph/include/sk4d_paragraph_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API void sk4d_paragraph_destroy(sk_paragraph_t* self);
SK4D_API bool sk4d_paragraph_did_exceed_max_lines(sk_paragraph_t* self);
SK4D_API float sk4d_paragraph_get_alphabetic_baseline(sk_paragraph_t* self);
SK4D_API void sk4d_paragraph_get_glyph_position_at_coordinate(sk_paragraph_t* self, float dx, float dy, /*out*/ sk_positionaffinity_t* result);
SK4D_API float sk4d_paragraph_get_height(sk_paragraph_t* self);
SK4D_API float sk4d_paragraph_get_ideographic_baseline(sk_paragraph_t* self);
SK4D_API size_t sk4d_paragraph_get_line_metrics(sk_paragraph_t* self, sk_metrics_t result[]);
SK4D_API float sk4d_paragraph_get_longest_line(sk_paragraph_t* self);
SK4D_API float sk4d_paragraph_get_max_intrinsic_width(sk_paragraph_t* self);
SK4D_API float sk4d_paragraph_get_max_width(sk_paragraph_t* self);
SK4D_API float sk4d_paragraph_get_min_intrinsic_width(sk_paragraph_t* self);
SK4D_API size_t sk4d_paragraph_get_rects_for_placeholders(sk_paragraph_t* self, sk_textbox_t result[]);
SK4D_API size_t sk4d_paragraph_get_rects_for_range(sk_paragraph_t* self, uint32_t start, uint32_t end, sk_rectheightstyle_t rect_height_style, sk_rectwidthstyle_t rect_width_style, sk_textbox_t result[]);
SK4D_API void sk4d_paragraph_get_word_boundary(sk_paragraph_t* self, uint32_t offset, /*out*/ uint32_t* start, /*out*/ uint32_t* end);
SK4D_API void sk4d_paragraph_layout(sk_paragraph_t* self, float width);
SK4D_API void sk4d_paragraph_paint(sk_paragraph_t* self, sk_canvas_t* canvas, float x, float y);
SK4D_API sk_path_t* sk4d_paragraph_to_path(sk_paragraph_t* self);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
