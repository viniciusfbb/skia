/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_svg_types_DEFINED
#define sk4d_svg_types_DEFINED

#include "include/c/sk4d_types.h"
#include "modules/skresources/include/sk4d_resources_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

typedef struct sk_svgdom_t  sk_svgdom_t;
typedef struct sk_svgnode_t sk_svgnode_t;
typedef struct sk_svgsvg_t  sk_svgsvg_t;

typedef enum {
    UNKNOWN_SK_SVGLENGTHUNIT,
    NUMBER_SK_SVGLENGTHUNIT,
    PERCENTAGE_SK_SVGLENGTHUNIT,
    EMS_SK_SVGLENGTHUNIT,
    EXS_SK_SVGLENGTHUNIT,
    PX_SK_SVGLENGTHUNIT,
    CM_SK_SVGLENGTHUNIT,
    MM_SK_SVGLENGTHUNIT,
    IN_SK_SVGLENGTHUNIT,
    PT_SK_SVGLENGTHUNIT,
    PC_SK_SVGLENGTHUNIT,
} sk_svglengthunit_t;

typedef enum {
    X_MIN_Y_MIN_SVGASPECTALIGN,
    X_MID_Y_MIN_SVGASPECTALIGN,
    X_MAX_Y_MIN_SVGASPECTALIGN,
    X_MIN_Y_MID_SVGASPECTALIGN = 4,
    X_MID_Y_MID_SVGASPECTALIGN,
    X_MAX_Y_MID_SVGASPECTALIGN,
    X_MIN_Y_MAX_SVGASPECTALIGN = 8,
    X_MID_Y_MAX_SVGASPECTALIGN,
    X_MAX_Y_MAX_SVGASPECTALIGN,
    NONE_SVGASPECTALIGN = 16,
} sk_svgaspectalign_t;

typedef enum {
    MEET_SK_SVGASPECTSCALE,
    SLICE_SK_SVGASPECTSCALE,
} sk_svgaspectscale_t;

typedef struct {
    float              value;
    sk_svglengthunit_t unit;
} sk_svglength_t;

typedef struct {
    sk_svgaspectalign_t align;
    sk_svgaspectscale_t scale;
} sk_svgpreserveaspectratio_t;

SK4D_C_PLUS_PLUS_END_GUARD

#endif
