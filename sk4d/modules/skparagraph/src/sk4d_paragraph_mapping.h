/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_paragraph_mapping_DEFINED
#define sk4d_paragraph_mapping_DEFINED

#include "src/c/sk4d_mapping.h"
#include "modules/skparagraph/include/DartTypes.h"
#include "modules/skparagraph/include/Paragraph.h"
#include "modules/skparagraph/include/ParagraphBuilder.h"
#include "modules/skparagraph/include/ParagraphStyle.h"
#include "modules/skparagraph/include/sk4d_paragraph_types.h"
#include "modules/skparagraph/include/TextShadow.h"
#include "modules/skparagraph/include/TextStyle.h"
#include "modules/skparagraph/include/TypefaceFontProvider.h"

SK4D_DEF_CLASS_MAP(skia::textlayout::Paragraph, sk_paragraph_t, Paragraph)
SK4D_DEF_CLASS_MAP(skia::textlayout::ParagraphBuilder, sk_paragraphbuilder_t, ParagraphBuilder)
SK4D_DEF_CLASS_MAP(skia::textlayout::ParagraphStyle, sk_paragraphstyle_t, ParagraphStyle)
SK4D_DEF_CLASS_MAP(skia::textlayout::PlaceholderStyle, sk_placeholderstyle_t, PlaceholderStyle)
SK4D_DEF_CLASS_MAP(skia::textlayout::PositionWithAffinity, sk_positionaffinity_t, PositionAffinity)
SK4D_DEF_CLASS_MAP(skia::textlayout::StrutStyle, sk_strutstyle_t, StrutStyle)
SK4D_DEF_CLASS_MAP(skia::textlayout::TextBox, sk_textbox_t, TextBox)
SK4D_DEF_CLASS_MAP(skia::textlayout::TextShadow, sk_textshadow_t, TextShadow)
SK4D_DEF_CLASS_MAP(skia::textlayout::TextStyle, sk_textstyle_t, TextStyle)
SK4D_DEF_CLASS_MAP(skia::textlayout::TypefaceFontProvider, sk_typefacefontprovider_t, TypefaceFontProvider)

SK4D_DEF_ENUM_MAP(skia::textlayout::RectHeightStyle, sk_rectheightstyle_t, RectHeightStyle)
SK4D_DEF_ENUM_MAP(skia::textlayout::RectWidthStyle, sk_rectwidthstyle_t, RectWidthStyle)
SK4D_DEF_ENUM_MAP(skia::textlayout::TextAlign, sk_textalign_t, TextAlign) 
SK4D_DEF_ENUM_MAP(skia::textlayout::TextBaseline, sk_textbaseline_t, TextBaseline)
SK4D_DEF_ENUM_MAP(skia::textlayout::TextDecoration, uint32_t, TextDecoration)
SK4D_DEF_ENUM_MAP(skia::textlayout::TextDecorationStyle, sk_textdecorationstyle_t, TextDecorationStyle)
SK4D_DEF_ENUM_MAP(skia::textlayout::TextDirection, sk_textdirection_t, TextDirection) 
SK4D_DEF_ENUM_MAP(skia::textlayout::TextHeightBehavior, uint32_t, TextHeightBehavior)


/*
 * CUSTOM MAPPING
 */

static inline sk_metrics_t ToMetrics(const skia::textlayout::LineMetrics& metrics) {
    return {
        metrics.fStartIndex,
        metrics.fEndIndex,
        metrics.fEndExcludingWhitespaces,
        metrics.fEndIncludingNewline,
        metrics.fHardBreak,
        metrics.fAscent,
        metrics.fDescent,
        metrics.fHeight,
        metrics.fWidth,
        metrics.fLeft,
        metrics.fBaseline,
        metrics.fLineNumber,
    };
}

#endif
