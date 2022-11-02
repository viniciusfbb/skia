/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_textblob.h"
#include "src/c/sk4d_mapping.h"

int32_t sk4d_textblob_get_intercepts(const sk_textblob_t* self, const float bounds[2], float result[], const sk_paint_t* paint) {
    return AsTextBlob(self)->getIntercepts(bounds, result, AsPaint(paint));
}

sk_textblob_t* sk4d_textblob_make_from_text(const void* text, size_t size, const sk_font_t* font, sk_textencoding_t encoding) {
    return ToTextBlob(SkTextBlob::MakeFromText(text, size, AsFont(*font), AsTextEncoding(encoding)).release());
}

sk_textblob_t* sk4d_textblob_make_from_text_horizontally_positioned(const void* text, size_t size, const float x_positions[], float y, const sk_font_t* font, sk_textencoding_t encoding) {
    return ToTextBlob(SkTextBlob::MakeFromPosTextH(text, size, x_positions, y, AsFont(*font), AsTextEncoding(encoding)).release());
}

sk_textblob_t* sk4d_textblob_make_from_text_positioned(const void* text, size_t size, const sk_point_t positions[], const sk_font_t* font, sk_textencoding_t encoding) {
    return ToTextBlob(SkTextBlob::MakeFromPosText(text, size, AsPoint(positions), AsFont(*font), AsTextEncoding(encoding)).release());
}

sk_textblob_t* sk4d_textblob_make_from_text_transform(const void* text, size_t size, const sk_rotationscalematrix_t matrices[], const sk_font_t* font, sk_textencoding_t encoding) {
    return ToTextBlob(SkTextBlob::MakeFromRSXform(text, size, AsRotationScaleMatrix(matrices), AsFont(*font), AsTextEncoding(encoding)).release());
}

void sk4d_textblob_ref(const sk_textblob_t* self) {
    AsTextBlob(self)->ref();
}

void sk4d_textblob_unref(const sk_textblob_t* self) {
    AsTextBlob(self)->unref();
}
