/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <vector>

#include "modules/skparagraph/include/sk4d_paragraphstyle.h"
#include "modules/skparagraph/src/sk4d_paragraph_mapping.h"

sk_paragraphstyle_t* sk4d_paragraphstyle_create(void) {
    return ToParagraphStyle(new skia::textlayout::ParagraphStyle());
}

void sk4d_paragraphstyle_destroy(sk_paragraphstyle_t* self) {
    delete AsParagraphStyle(self);
}

void sk4d_paragraphstyle_disable_hinting(sk_paragraphstyle_t* self) {
    AsParagraphStyle(self)->turnHintingOff();
}

sk_string_t* sk4d_paragraphstyle_get_ellipsis(const sk_paragraphstyle_t* self) {
    return ToString(new SkString(AsParagraphStyle(self)->getEllipsis()));
}

float sk4d_paragraphstyle_get_height(const sk_paragraphstyle_t* self) {
    return AsParagraphStyle(self)->getHeight();
}

size_t sk4d_paragraphstyle_get_max_lines(const sk_paragraphstyle_t* self) {
    return AsParagraphStyle(self)->getMaxLines();
}

const sk_strutstyle_t* sk4d_paragraphstyle_get_strut_style(const sk_paragraphstyle_t* self) {
    return ToStrutStyle(&AsParagraphStyle(self)->getStrutStyle());
}

sk_textalign_t sk4d_paragraphstyle_get_text_align(const sk_paragraphstyle_t* self) {
    return ToTextAlign(AsParagraphStyle(self)->getTextAlign());
}

sk_textdirection_t sk4d_paragraphstyle_get_text_direction(const sk_paragraphstyle_t* self) {
    return ToTextDirection(AsParagraphStyle(self)->getTextDirection());
}

uint32_t sk4d_paragraphstyle_get_text_height_behaviors(const sk_paragraphstyle_t* self) {
    return ToTextHeightBehavior(AsParagraphStyle(self)->getTextHeightBehavior());
}

const sk_textstyle_t* sk4d_paragraphstyle_get_text_style(const sk_paragraphstyle_t* self) {
    return ToTextStyle(&AsParagraphStyle(self)->getTextStyle());
}

void sk4d_paragraphstyle_set_ellipsis(sk_paragraphstyle_t* self, const char value[]) {
    AsParagraphStyle(self)->setEllipsis(SkString(value));
}

void sk4d_paragraphstyle_set_height(sk_paragraphstyle_t* self, float value) {
    AsParagraphStyle(self)->setHeight(value);
}

void sk4d_paragraphstyle_set_max_lines(sk_paragraphstyle_t* self, size_t value) {
    AsParagraphStyle(self)->setMaxLines(value);
}

void sk4d_paragraphstyle_set_strut_style(sk_paragraphstyle_t* self, const sk_strutstyle_t* value) {
    AsParagraphStyle(self)->setStrutStyle((value) ? *AsStrutStyle(value) : skia::textlayout::StrutStyle());
}

void sk4d_paragraphstyle_set_text_align(sk_paragraphstyle_t* self, sk_textalign_t value) {
    AsParagraphStyle(self)->setTextAlign(AsTextAlign(value));
}

void sk4d_paragraphstyle_set_text_direction(sk_paragraphstyle_t* self, sk_textdirection_t value) {
    AsParagraphStyle(self)->setTextDirection(AsTextDirection(value));
}

void sk4d_paragraphstyle_set_text_height_behaviors(sk_paragraphstyle_t* self, uint32_t value) {
    AsParagraphStyle(self)->setTextHeightBehavior(AsTextHeightBehavior(value));
}

void sk4d_paragraphstyle_set_text_style(sk_paragraphstyle_t* self, sk_textstyle_t* value) {
    skia::textlayout::TextStyle style;
    AsParagraphStyle(self)->setTextStyle((value) ? AsTextStyle(*value) : style);
}

sk_strutstyle_t* sk4d_strutstyle_create(void) {
    return ToStrutStyle(new skia::textlayout::StrutStyle());
}

void sk4d_strutstyle_destroy(sk_strutstyle_t* self) {
    delete AsStrutStyle(self);
}

bool sk4d_strutstyle_get_enabled(const sk_strutstyle_t* self) {
    return AsStrutStyle(self)->getStrutEnabled();
}

size_t sk4d_strutstyle_get_font_families(const sk_strutstyle_t* self, const char* result[]) {
    const auto& families = AsStrutStyle(self)->getFontFamilies();
    if (result) {
        for (size_t i = 0; i < families.size(); i++) {
            const auto& family = families[i];
            result[i] = family.c_str();
        }
    }
    return families.size();
}

float sk4d_strutstyle_get_font_size(const sk_strutstyle_t* self) {
    return AsStrutStyle(self)->getFontSize();
}

void sk4d_strutstyle_get_font_style(const sk_strutstyle_t* self, sk_fontstyle_t* result) {
    *result = ToFontStyle(AsStrutStyle(self)->getFontStyle());
}

bool sk4d_strutstyle_get_force_height(const sk_strutstyle_t* self) {
    return AsStrutStyle(self)->getForceStrutHeight();
}

bool sk4d_strutstyle_get_half_leading(const sk_strutstyle_t* self) {
    return AsStrutStyle(self)->getHalfLeading();
}

float sk4d_strutstyle_get_height_multiplier(const sk_strutstyle_t* self) {
    return AsStrutStyle(self)->getHeight();
}

float sk4d_strutstyle_get_leading(const sk_strutstyle_t* self) {
    return AsStrutStyle(self)->getLeading();
}

bool sk4d_strutstyle_is_equal(const sk_strutstyle_t* self, const sk_strutstyle_t* strut_style) {
    return AsStrutStyle(*self) == AsStrutStyle(*strut_style);
}

void sk4d_strutstyle_set_enabled(sk_strutstyle_t* self, bool value) {
    AsStrutStyle(self)->setStrutEnabled(value);
}

void sk4d_strutstyle_set_font_families(sk_strutstyle_t* self, const char* values[], size_t count) {
    std::vector<SkString> families(count);
    for (size_t i = 0; i < count; i++)
        families[i] = SkString(values[i]);
    AsStrutStyle(self)->setFontFamilies(families);
}

void sk4d_strutstyle_set_font_size(sk_strutstyle_t* self, float value) {
    AsStrutStyle(self)->setFontSize(value);
}

void sk4d_strutstyle_set_font_style(sk_strutstyle_t* self, sk_fontstyle_t* value) {
    AsStrutStyle(self)->setFontStyle(AsFontStyle(value));
}

void sk4d_strutstyle_set_force_height(sk_strutstyle_t* self, bool value) {
    AsStrutStyle(self)->setForceStrutHeight(value);
}

void sk4d_strutstyle_set_half_leading(sk_strutstyle_t* self, bool value) {
    AsStrutStyle(self)->setHalfLeading(value);
}

void sk4d_strutstyle_set_height_multiplier(sk_strutstyle_t* self, float value) {
    AsStrutStyle(self)->setHeight(value);
    AsStrutStyle(self)->setHeightOverride(value != 0);
}

void sk4d_strutstyle_set_leading(sk_strutstyle_t* self, float value) {
    AsStrutStyle(self)->setLeading(value);
}
