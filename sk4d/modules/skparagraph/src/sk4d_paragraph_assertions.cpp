/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <type_traits>

#include "include/core/SkRefCnt.h"
#include "modules/skparagraph/include/DartTypes.h"
#include "modules/skparagraph/include/sk4d_paragraph_types.h"
#include "modules/skparagraph/include/TextShadow.h"
#include "modules/skparagraph/include/TextStyle.h"
#include "modules/skparagraph/include/TypefaceFontProvider.h"


/*
 * ASSERTIONS OF DEFINITIONS
 */

static_assert(static_cast<int>(skia::textlayout::TextDecoration::kUnderline)   == UNDERLINE_SK_TEXT_DECORATION_FLAG,    "");
static_assert(static_cast<int>(skia::textlayout::TextDecoration::kOverline)    == OVERLINE_SK_TEXT_DECORATION_FLAG,     "");
static_assert(static_cast<int>(skia::textlayout::TextDecoration::kLineThrough) == LINE_THROUGH_SK_TEXT_DECORATION_FLAG, "");

static_assert(static_cast<int>(skia::textlayout::TextHeightBehavior::kDisableFirstAscent) == DISABLE_FIRST_ASCENT_SK_TEXT_HEIGHT_BEHAVIOR_FLAG, "");
static_assert(static_cast<int>(skia::textlayout::TextHeightBehavior::kDisableLastDescent) == DISABLE_LAST_DESCENT_SK_TEXT_HEIGHT_BEHAVIOR_FLAG, "");


/*
 * ASSERTIONS OF STRUCTURES
 *
 *  Custom mappings:
 *   - Metrics
 *
 */

static_assert(sizeof(skia::textlayout::PlaceholderStyle)     == sizeof(sk_placeholderstyle_t), "");
static_assert(sizeof(skia::textlayout::PositionWithAffinity) == sizeof(sk_positionaffinity_t), "");
static_assert(sizeof(skia::textlayout::TextBox)              == sizeof(sk_textbox_t),          "");
static_assert(sizeof(skia::textlayout::TextShadow)           == sizeof(sk_textshadow_t),       "");


/*
 * ASSERTIONS OF ENUMERATIONS
 */

// skia::textlayout::Affinity
static_assert(static_cast<int>(skia::textlayout::kUpstream)   == static_cast<int>(UPSTREAM_SK_AFFINITY),   "");
static_assert(static_cast<int>(skia::textlayout::kDownstream) == static_cast<int>(DOWNSTREAM_SK_AFFINITY), "");

// skia::textlayout::PlaceholderAlignment
static_assert(static_cast<int>(skia::textlayout::PlaceholderAlignment::kBaseline)      == static_cast<int>(BASELINE_SK_PLACEHOLDERALIGNMENT),       "");
static_assert(static_cast<int>(skia::textlayout::PlaceholderAlignment::kAboveBaseline) == static_cast<int>(ABOVE_BASELINE_SK_PLACEHOLDERALIGNMENT), "");
static_assert(static_cast<int>(skia::textlayout::PlaceholderAlignment::kBelowBaseline) == static_cast<int>(BELOW_BASELINE_SK_PLACEHOLDERALIGNMENT), "");
static_assert(static_cast<int>(skia::textlayout::PlaceholderAlignment::kTop)           == static_cast<int>(TOP_SK_PLACEHOLDERALIGNMENT),            "");
static_assert(static_cast<int>(skia::textlayout::PlaceholderAlignment::kBottom)        == static_cast<int>(BOTTOM_SK_PLACEHOLDERALIGNMENT),         "");
static_assert(static_cast<int>(skia::textlayout::PlaceholderAlignment::kMiddle)        == static_cast<int>(MIDDLE_SK_PLACEHOLDERALIGNMENT),         "");

// skia::textlayout::RectHeightStyle
static_assert(static_cast<int>(skia::textlayout::RectHeightStyle::kTight)                    == static_cast<int>(TIGHT_SK_RECTHEIGHTSTYLE),                       "");
static_assert(static_cast<int>(skia::textlayout::RectHeightStyle::kMax)                      == static_cast<int>(MAX_SK_RECTHEIGHTSTYLE),                         "");
static_assert(static_cast<int>(skia::textlayout::RectHeightStyle::kIncludeLineSpacingMiddle) == static_cast<int>(INCLUDE_LINE_SPACING_MIDDLE_SK_RECTHEIGHTSTYLE), "");
static_assert(static_cast<int>(skia::textlayout::RectHeightStyle::kIncludeLineSpacingTop)    == static_cast<int>(INCLUDE_LINE_SPACING_TOP_SK_RECTHEIGHTSTYLE),    "");
static_assert(static_cast<int>(skia::textlayout::RectHeightStyle::kIncludeLineSpacingBottom) == static_cast<int>(INCLUDE_LINE_SPACING_BOTTOM_SK_RECTHEIGHTSTYLE), "");
static_assert(static_cast<int>(skia::textlayout::RectHeightStyle::kStrut)                    == static_cast<int>(STRUT_SK_RECTHEIGHTSTYLE),                       "");

// skia::textlayout::RectWidthStyle
static_assert(static_cast<int>(skia::textlayout::RectWidthStyle::kTight) == static_cast<int>(TIGHT_SK_RECTWIDTHSTYLE), "");
static_assert(static_cast<int>(skia::textlayout::RectWidthStyle::kMax)   == static_cast<int>(MAX_SK_RECTWIDTHSTYLE),   "");

// skia::textlayout::TextAlign
static_assert(static_cast<int>(skia::textlayout::TextAlign::kLeft)    == static_cast<int>(LEFT_SK_TEXTALIGN),      "");
static_assert(static_cast<int>(skia::textlayout::TextAlign::kRight)   == static_cast<int>(RIGHT_SK_TEXTALIGN),     "");
static_assert(static_cast<int>(skia::textlayout::TextAlign::kCenter)  == static_cast<int>(CENTER_SK_TEXTALIGN),    "");
static_assert(static_cast<int>(skia::textlayout::TextAlign::kJustify) == static_cast<int>(JUSTIFY_SK_TEXTALIGN),   "");
static_assert(static_cast<int>(skia::textlayout::TextAlign::kStart)   == static_cast<int>(START_SK_TEXTALIGN),     "");
static_assert(static_cast<int>(skia::textlayout::TextAlign::kEnd)     == static_cast<int>(TERMINATE_SK_TEXTALIGN), "");

// skia::textlayout::TextBaseline
static_assert(static_cast<int>(skia::textlayout::TextBaseline::kAlphabetic)  == static_cast<int>(ALPHABETIC_SK_TEXTBASELINE),  "");
static_assert(static_cast<int>(skia::textlayout::TextBaseline::kIdeographic) == static_cast<int>(IDEOGRAPHIC_SK_TEXTBASELINE), "");

// skia::textlayout::TextDecorationStyle
static_assert(static_cast<int>(skia::textlayout::kSolid)  == static_cast<int>(SOLID_SK_TEXTDECORATIONSTYLE),  "");
static_assert(static_cast<int>(skia::textlayout::kDouble) == static_cast<int>(DOUBLE_SK_TEXTDECORATIONSTYLE), "");
static_assert(static_cast<int>(skia::textlayout::kDotted) == static_cast<int>(DOTTED_SK_TEXTDECORATIONSTYLE), "");
static_assert(static_cast<int>(skia::textlayout::kDashed) == static_cast<int>(DASHED_SK_TEXTDECORATIONSTYLE), "");
static_assert(static_cast<int>(skia::textlayout::kWavy)   == static_cast<int>(WAVY_SK_TEXTDECORATIONSTYLE),   "");

// skia::textlayout::TextDirection
static_assert(static_cast<int>(skia::textlayout::TextDirection::kRtl) == static_cast<int>(RIGHT_TO_LEFT_SK_TEXTDIRECTION), "");
static_assert(static_cast<int>(skia::textlayout::TextDirection::kLtr) == static_cast<int>(LEFT_TO_RIGHT_SK_TEXTDIRECTION), "");


/*
 * ASSERTIONS OF REFERENCED OBJECTS
 */

static_assert(std::is_base_of<SkRefCnt, skia::textlayout::TypefaceFontProvider>::value, "");
