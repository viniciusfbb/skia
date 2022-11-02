/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_paragraph_types_DEFINED
#define sk4d_paragraph_types_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

typedef struct sk_paragraph_t            sk_paragraph_t;
typedef struct sk_paragraphbuilder_t     sk_paragraphbuilder_t;
typedef struct sk_paragraphstyle_t       sk_paragraphstyle_t;
typedef struct sk_strutstyle_t           sk_strutstyle_t;
typedef struct sk_textstyle_t            sk_textstyle_t;
typedef struct sk_typefacefontprovider_t sk_typefacefontprovider_t;

#define UNDERLINE_SK_TEXT_DECORATION_FLAG                 (1 << 0)
#define OVERLINE_SK_TEXT_DECORATION_FLAG                  (1 << 1)
#define LINE_THROUGH_SK_TEXT_DECORATION_FLAG              (1 << 2)

#define DISABLE_FIRST_ASCENT_SK_TEXT_HEIGHT_BEHAVIOR_FLAG (1 << 0)
#define DISABLE_LAST_DESCENT_SK_TEXT_HEIGHT_BEHAVIOR_FLAG (1 << 1)

typedef enum {
    UPSTREAM_SK_AFFINITY,
    DOWNSTREAM_SK_AFFINITY,
} sk_affinity_t;

typedef enum {
    BASELINE_SK_PLACEHOLDERALIGNMENT,
    ABOVE_BASELINE_SK_PLACEHOLDERALIGNMENT,
    BELOW_BASELINE_SK_PLACEHOLDERALIGNMENT,
    TOP_SK_PLACEHOLDERALIGNMENT,
    BOTTOM_SK_PLACEHOLDERALIGNMENT,
    MIDDLE_SK_PLACEHOLDERALIGNMENT,
} sk_placeholderalignment_t;

typedef enum {
    TIGHT_SK_RECTHEIGHTSTYLE,
    MAX_SK_RECTHEIGHTSTYLE,
    INCLUDE_LINE_SPACING_MIDDLE_SK_RECTHEIGHTSTYLE,
    INCLUDE_LINE_SPACING_TOP_SK_RECTHEIGHTSTYLE,
    INCLUDE_LINE_SPACING_BOTTOM_SK_RECTHEIGHTSTYLE,
    STRUT_SK_RECTHEIGHTSTYLE,
} sk_rectheightstyle_t;

typedef enum {
    TIGHT_SK_RECTWIDTHSTYLE,
    MAX_SK_RECTWIDTHSTYLE,
} sk_rectwidthstyle_t;

typedef enum {
    LEFT_SK_TEXTALIGN,
    RIGHT_SK_TEXTALIGN,
    CENTER_SK_TEXTALIGN,
    JUSTIFY_SK_TEXTALIGN,
    START_SK_TEXTALIGN,
    TERMINATE_SK_TEXTALIGN,
} sk_textalign_t;

typedef enum {
    ALPHABETIC_SK_TEXTBASELINE,
    IDEOGRAPHIC_SK_TEXTBASELINE,
} sk_textbaseline_t;

typedef enum {
    SOLID_SK_TEXTDECORATIONSTYLE,
    DOUBLE_SK_TEXTDECORATIONSTYLE,
    DOTTED_SK_TEXTDECORATIONSTYLE,
    DASHED_SK_TEXTDECORATIONSTYLE,
    WAVY_SK_TEXTDECORATIONSTYLE,
} sk_textdecorationstyle_t;

typedef enum {
    RIGHT_TO_LEFT_SK_TEXTDIRECTION,
    LEFT_TO_RIGHT_SK_TEXTDIRECTION,
} sk_textdirection_t;

typedef struct {
    size_t start_index;
    size_t end_index;
    size_t end_excluding_whitespaces;
    size_t end_including_newline;
    bool   is_hard_break;
    double ascent;
    double descent;
    double height;
    double width;
    double left;
    double baseline;
    size_t line_number;
} sk_metrics_t;

typedef struct {
    float                     width;
    float                     height;
    sk_placeholderalignment_t alignment;
    sk_textbaseline_t         baseline;
    float                     baseline_offset;
} sk_placeholderstyle_t;

typedef struct {
    int32_t       position;
    sk_affinity_t affinity;
} sk_positionaffinity_t;

typedef struct {
    sk_rect_t          rect;
    sk_textdirection_t direction;
} sk_textbox_t;

typedef struct {
    sk_color_t color;
    sk_point_t offset;
    double     blur_radius;
} sk_textshadow_t;

SK4D_C_PLUS_PLUS_END_GUARD

#endif
