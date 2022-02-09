/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <vector>

#include "modules/skparagraph/include/sk4d_paragraph.h"
#include "modules/skparagraph/src/sk4d_paragraph_mapping.h"

void sk4d_paragraph_destroy(sk_paragraph_t* self) {
    delete AsParagraph(self);
}

bool sk4d_paragraph_did_exceed_max_lines(sk_paragraph_t* self) {
    return AsParagraph(self)->didExceedMaxLines();
}

float sk4d_paragraph_get_alphabetic_baseline(sk_paragraph_t* self) {
    return AsParagraph(self)->getAlphabeticBaseline();
}

void sk4d_paragraph_get_glyph_position_at_coordinate(sk_paragraph_t* self, float dx, float dy, sk_positionaffinity_t* result) {
    *result = ToPositionAffinity(AsParagraph(self)->getGlyphPositionAtCoordinate(dx, dy));
}

float sk4d_paragraph_get_height(sk_paragraph_t* self) {
    return AsParagraph(self)->getHeight();
}

float sk4d_paragraph_get_ideographic_baseline(sk_paragraph_t* self) {
    return AsParagraph(self)->getIdeographicBaseline();
}

size_t sk4d_paragraph_get_line_metrics(sk_paragraph_t* self, sk_metrics_t result[]) {
    if (result) {
        std::vector<skia::textlayout::LineMetrics> r;
        AsParagraph(self)->getLineMetrics(r);
        for (size_t i = 0; i < r.size(); i++)
            result[i] = ToMetrics(r[i]);
    }
    return AsParagraph(self)->lineNumber();
}

float sk4d_paragraph_get_longest_line(sk_paragraph_t* self) {
    return AsParagraph(self)->getLongestLine();
}

float sk4d_paragraph_get_max_intrinsic_width(sk_paragraph_t* self) {
    return AsParagraph(self)->getMaxIntrinsicWidth();
}

float sk4d_paragraph_get_max_width(sk_paragraph_t* self) {
    return AsParagraph(self)->getMaxWidth();
}

float sk4d_paragraph_get_min_intrinsic_width(sk_paragraph_t* self) {
    return AsParagraph(self)->getMinIntrinsicWidth();
}

size_t sk4d_paragraph_get_rects_for_placeholders(sk_paragraph_t* self, sk_textbox_t result[]) {
    auto r = AsParagraph(self)->getRectsForPlaceholders();
    size_t count = r.size();
    if (result) {
        for (size_t i = 0; i < count; i++)
            result[i] = ToTextBox(r[i]);
    }
    return count;
}

size_t sk4d_paragraph_get_rects_for_range(sk_paragraph_t* self, uint32_t start, uint32_t end, sk_rectheightstyle_t rect_height_style, sk_rectwidthstyle_t rect_width_style, sk_textbox_t result[]) {
    auto r = AsParagraph(self)->getRectsForRange(start, end, AsRectHeightStyle(rect_height_style), AsRectWidthStyle(rect_width_style));
    size_t count = r.size();
    if (result) {
        for (size_t i = 0; i < count; i++)
            result[i] = ToTextBox(r[i]);
    }
    return count;
}

void sk4d_paragraph_get_word_boundary(sk_paragraph_t* self, uint32_t offset, uint32_t* start, uint32_t* end) {
    auto result = AsParagraph(self)->getWordBoundary(offset);
    *start = result.start;
    *end   = result.end;
}

void sk4d_paragraph_layout(sk_paragraph_t* self, float width) {
    AsParagraph(self)->layout(width);
}

void sk4d_paragraph_paint(sk_paragraph_t* self, sk_canvas_t* canvas, float x, float y) {
    AsParagraph(self)->paint(AsCanvas(canvas), x, y);
}

sk_path_t* sk4d_paragraph_to_path(sk_paragraph_t* self) {
    auto r = new SkPath();
    AsParagraph(self)->visit([&](int, const skia::textlayout::Paragraph::VisitorInfo* info) {
        if (!info)
            return;

        struct Rec {
            SkPath*         fPath;
            const SkPoint&  fOrigin;
            const SkPoint*  fPositions;
        } rec = { r, info->origin, info->positions };

        info->font.getPaths(info->glyphs, info->count, [](const SkPath* path, const SkMatrix& matrix, void* ctx) {
            Rec* rec = reinterpret_cast<Rec*>(ctx);
            if (path) {
                SkMatrix m(matrix);
                m.postTranslate(rec->fPositions->fX + rec->fOrigin.fX, rec->fPositions->fY + rec->fOrigin.fY);
                rec->fPath->addPath(*path, m);
            }
            rec->fPositions += 1;
        }, &rec);
    });
    return ToPath(r);
}