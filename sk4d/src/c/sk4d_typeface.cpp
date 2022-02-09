/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_typeface.h"
#include "src/c/sk4d_mapping.h"

sk_string_t* sk4d_typeface_get_family_name(const sk_typeface_t* self) {
    auto r = new SkString();
    AsTypeface(self)->getFamilyName(r);
    return ToString(r);
}

sk_fontslant_t sk4d_typeface_get_slant(const sk_typeface_t* self) {
    return ToFontSlant(AsTypeface(self)->fontStyle().slant());
}

void sk4d_typeface_get_style(const sk_typeface_t* self, sk_fontstyle_t* result) {
    *result = ToFontStyle(AsTypeface(self)->fontStyle());
}

int32_t sk4d_typeface_get_weight(const sk_typeface_t* self) {
    return AsTypeface(self)->fontStyle().weight();
}

int32_t sk4d_typeface_get_width(const sk_typeface_t* self) {
    return AsTypeface(self)->fontStyle().width();
}

sk_typeface_t* sk4d_typeface_make_default(void) {
    return ToTypeface(SkTypeface::MakeDefault().release());
}

sk_typeface_t* sk4d_typeface_make_from_file(const char file_name[], int32_t ttc_index) {
    return ToTypeface(SkTypeface::MakeFromFile(file_name, ttc_index).release());
}

sk_typeface_t* sk4d_typeface_make_from_stream(sk_stream_t* stream, int32_t ttc_index) {
    if (!AsStream(stream)->hasLength())
        return nullptr;
    auto data = SkData::MakeFromStream(AsStream(stream), AsStream(stream)->getLength());
    if (!data)
        return nullptr;
    return ToTypeface(SkTypeface::MakeFromData(data, ttc_index).release());
}

sk_typeface_t* sk4d_typeface_make_from_name(const char family_name[], const sk_fontstyle_t* style) {
    return ToTypeface(SkTypeface::MakeFromName(family_name, AsFontStyle(style)).release());
}
