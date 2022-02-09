/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_textblob_DEFINED
#define sk4d_textblob_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API int32_t sk4d_textblob_get_intercepts(const sk_textblob_t* self, const float bounds[2], float result[], const sk_paint_t* paint);
SK4D_API sk_textblob_t* sk4d_textblob_make_from_text(const void* text, size_t size, const sk_font_t* font, sk_textencoding_t encoding);
SK4D_API sk_textblob_t* sk4d_textblob_make_from_text_horizontally_positioned(const void* text, size_t size, const float x_positions[], float y, const sk_font_t* font, sk_textencoding_t encoding);
SK4D_API sk_textblob_t* sk4d_textblob_make_from_text_positioned(const void* text, size_t size, const sk_point_t positions[], const sk_font_t* font, sk_textencoding_t encoding);
SK4D_API sk_textblob_t* sk4d_textblob_make_from_text_transform(const void* text, size_t size, const sk_rotationscalematrix_t matrices[], const sk_font_t* font, sk_textencoding_t encoding);
SK4D_API void sk4d_textblob_ref(const sk_textblob_t* self);
SK4D_API void sk4d_textblob_unref(const sk_textblob_t* self);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
