/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <vector>

#include "modules/skparagraph/include/sk4d_textstyle.h"
#include "modules/skparagraph/src/sk4d_paragraph_mapping.h"

void sk4d_textstyle_add_font_feature(sk_textstyle_t* self, const char feature[], int32_t value) {
    AsTextStyle(self)->addFontFeature(SkString(feature), value);
}

void sk4d_textstyle_add_shadow(sk_textstyle_t* self, const sk_textshadow_t* shadow) {
    AsTextStyle(self)->addShadow(*AsTextShadow(shadow));
}

void sk4d_textstyle_clear_background_color(sk_textstyle_t* self) {
    AsTextStyle(self)->clearBackgroundColor();
}

void sk4d_textstyle_clear_foreground_color(sk_textstyle_t* self) {
    AsTextStyle(self)->clearForegroundColor();
}

sk_textstyle_t* sk4d_textstyle_create(void) {
    return ToTextStyle(new skia::textlayout::TextStyle());
}

void sk4d_textstyle_destroy(sk_textstyle_t* self) {
    delete AsTextStyle(self);
}

sk_paint_t* sk4d_textstyle_get_background(const sk_textstyle_t* self) {
    return ToPaint(new SkPaint(AsTextStyle(self)->getBackground()));
}

sk_color_t sk4d_textstyle_get_color(const sk_textstyle_t* self) {
    return AsTextStyle(self)->getColor();
}

sk_color_t sk4d_textstyle_get_decoration_color(const sk_textstyle_t* self) {
    return AsTextStyle(self)->getDecorationColor();
}

sk_textdecorationstyle_t sk4d_textstyle_get_decoration_style(const sk_textstyle_t* self) {
    return ToTextDecorationStyle(AsTextStyle(self)->getDecorationStyle());
}

float sk4d_textstyle_get_decoration_thickness(const sk_textstyle_t* self) {
    return AsTextStyle(self)->getDecorationThicknessMultiplier();
}

uint32_t sk4d_textstyle_get_decorations(const sk_textstyle_t* self) {
    return ToTextDecoration(AsTextStyle(self)->getDecorationType());
}

size_t sk4d_textstyle_get_font_families(const sk_textstyle_t* self, const char* result[]) {
    const auto& families = AsTextStyle(self)->getFontFamilies();
    if (result) {
        for (size_t i = 0; i < families.size(); i++) {
            const auto& family = families[i];
            result[i] = family.c_str();
        }
    }
    return families.size();
}

void sk4d_textstyle_get_font_metrics(const sk_textstyle_t* self, sk_fontmetrics_t* result) {
    AsTextStyle(self)->getFontMetrics(AsFontMetrics(result));
}

float sk4d_textstyle_get_font_size(const sk_textstyle_t* self) {
    return AsTextStyle(self)->getFontSize();
}

void sk4d_textstyle_get_font_style(const sk_textstyle_t* self, sk_fontstyle_t* result) {
    *result = ToFontStyle(AsTextStyle(self)->getFontStyle());
}

sk_paint_t* sk4d_textstyle_get_foreground(const sk_textstyle_t* self) {
    return ToPaint(new SkPaint(AsTextStyle(self)->getForeground()));
}

bool sk4d_textstyle_get_half_leading(const sk_textstyle_t* self) {
    return AsTextStyle(self)->getHalfLeading();
}

float sk4d_textstyle_get_height_multiplier(const sk_textstyle_t* self) {
    return AsTextStyle(self)->getHeight();
}

float sk4d_textstyle_get_letter_spacing(const sk_textstyle_t* self) {
    return AsTextStyle(self)->getLetterSpacing();
}

sk_string_t* sk4d_textstyle_get_locale(const sk_textstyle_t* self) {
    return ToString(new SkString(AsTextStyle(self)->getLocale()));
}

float sk4d_textstyle_get_word_spacing(const sk_textstyle_t* self) {
    return AsTextStyle(self)->getWordSpacing();
}

bool sk4d_textstyle_is_equal(const sk_textstyle_t* self, const sk_textstyle_t* text_style) {
    return AsTextStyle(*self) == AsTextStyle(*text_style);
}

void sk4d_textstyle_reset_font_features(sk_textstyle_t* self) {
    AsTextStyle(self)->resetFontFeatures();
}

void sk4d_textstyle_reset_shadows(sk_textstyle_t* self) {
    AsTextStyle(self)->resetShadows();
}

void sk4d_textstyle_set_background_color(sk_textstyle_t* self, sk_paint_t* paint) {
    AsTextStyle(self)->setBackgroundColor(*AsPaint(paint));
}

void sk4d_textstyle_set_color(sk_textstyle_t* self, sk_color_t value) {
    AsTextStyle(self)->setColor(value);
}

void sk4d_textstyle_set_decoration_color(sk_textstyle_t* self, sk_color_t value) {
    AsTextStyle(self)->setDecorationColor(value);
}

void sk4d_textstyle_set_decoration_style(sk_textstyle_t* self, sk_textdecorationstyle_t value) {
    AsTextStyle(self)->setDecorationStyle(AsTextDecorationStyle(value));
}

void sk4d_textstyle_set_decoration_thickness(sk_textstyle_t* self, float value) {
    AsTextStyle(self)->setDecorationThicknessMultiplier(value);
}

void sk4d_textstyle_set_decorations(sk_textstyle_t* self, uint32_t value) {
    AsTextStyle(self)->setDecoration(AsTextDecoration(value));
}

void sk4d_textstyle_set_font_families(sk_textstyle_t* self, const char* values[], size_t count) {
    std::vector<SkString> families(count);
    for (size_t i = 0; i < count; i++)
        families[i] = SkString(values[i]);
    AsTextStyle(self)->setFontFamilies(families);
}

void sk4d_textstyle_set_font_size(sk_textstyle_t* self, float value) {
    AsTextStyle(self)->setFontSize(value);
}

void sk4d_textstyle_set_font_style(sk_textstyle_t* self, const sk_fontstyle_t* value) {
    AsTextStyle(self)->setFontStyle(AsFontStyle(value));
}

void sk4d_textstyle_set_foreground_color(sk_textstyle_t* self, sk_paint_t* paint) {
    AsTextStyle(self)->setForegroundColor(*AsPaint(paint));
}

void sk4d_textstyle_set_half_leading(sk_textstyle_t* self, bool value) {
    AsTextStyle(self)->setHalfLeading(value);
}

void sk4d_textstyle_set_height_multiplier(sk_textstyle_t* self, float value) {
    AsTextStyle(self)->setHeight(value);
    AsTextStyle(self)->setHeightOverride(value != 0);
}

void sk4d_textstyle_set_letter_spacing(sk_textstyle_t* self, float value) {
    AsTextStyle(self)->setLetterSpacing(value);
}

void sk4d_textstyle_set_locale(sk_textstyle_t* self, const char value[]) {
    AsTextStyle(self)->setLocale(SkString(value));
}

void sk4d_textstyle_set_word_spacing(sk_textstyle_t* self, float value) {
    AsTextStyle(self)->setWordSpacing(value);
}
