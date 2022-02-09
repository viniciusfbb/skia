/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <type_traits>

#include "include/core/SkRefCnt.h"
#include "modules/svg/include/sk4d_svg_types.h"
#include "modules/svg/include/SkSVGDOM.h"
#include "modules/svg/include/SkSVGNode.h"
#include "modules/svg/include/SkSVGTypes.h"


/*
 * ASSERTIONS OF STRUCTURES
 */

static_assert(sizeof(SkSVGLength)              == sizeof(sk_svglength_t),              "");
static_assert(sizeof(SkSVGPreserveAspectRatio) == sizeof(sk_svgpreserveaspectratio_t), "");
static_assert(sizeof(SkSVGViewBoxType)         == sizeof(sk_rect_t),                   "");


/*
 * ASSERTIONS OF ENUMERATIONS
 */

// SkSVGLength::Unit
static_assert(static_cast<int>(SkSVGLength::Unit::kUnknown)    ==  static_cast<int>(UNKNOWN_SK_SVGLENGTHUNIT),    "");
static_assert(static_cast<int>(SkSVGLength::Unit::kNumber)     ==  static_cast<int>(NUMBER_SK_SVGLENGTHUNIT),     "");
static_assert(static_cast<int>(SkSVGLength::Unit::kPercentage) ==  static_cast<int>(PERCENTAGE_SK_SVGLENGTHUNIT), "");
static_assert(static_cast<int>(SkSVGLength::Unit::kEMS)        ==  static_cast<int>(EMS_SK_SVGLENGTHUNIT),        "");
static_assert(static_cast<int>(SkSVGLength::Unit::kEXS)        ==  static_cast<int>(EXS_SK_SVGLENGTHUNIT),        "");
static_assert(static_cast<int>(SkSVGLength::Unit::kPX)         ==  static_cast<int>(PX_SK_SVGLENGTHUNIT),         "");
static_assert(static_cast<int>(SkSVGLength::Unit::kCM)         ==  static_cast<int>(CM_SK_SVGLENGTHUNIT),         "");
static_assert(static_cast<int>(SkSVGLength::Unit::kMM)         ==  static_cast<int>(MM_SK_SVGLENGTHUNIT),         "");
static_assert(static_cast<int>(SkSVGLength::Unit::kIN)         ==  static_cast<int>(IN_SK_SVGLENGTHUNIT),         "");
static_assert(static_cast<int>(SkSVGLength::Unit::kPT)         ==  static_cast<int>(PT_SK_SVGLENGTHUNIT),         "");
static_assert(static_cast<int>(SkSVGLength::Unit::kPC)         ==  static_cast<int>(PC_SK_SVGLENGTHUNIT),         "");

// SkSVGPreserveAspectRatio::Align
static_assert(static_cast<int>(SkSVGPreserveAspectRatio::kXMinYMin) == static_cast<int>(X_MIN_Y_MIN_SVGASPECTALIGN), "");
static_assert(static_cast<int>(SkSVGPreserveAspectRatio::kXMidYMin) == static_cast<int>(X_MID_Y_MIN_SVGASPECTALIGN), "");
static_assert(static_cast<int>(SkSVGPreserveAspectRatio::kXMaxYMin) == static_cast<int>(X_MAX_Y_MIN_SVGASPECTALIGN), "");
static_assert(static_cast<int>(SkSVGPreserveAspectRatio::kXMinYMid) == static_cast<int>(X_MIN_Y_MID_SVGASPECTALIGN), "");
static_assert(static_cast<int>(SkSVGPreserveAspectRatio::kXMidYMid) == static_cast<int>(X_MID_Y_MID_SVGASPECTALIGN), "");
static_assert(static_cast<int>(SkSVGPreserveAspectRatio::kXMaxYMid) == static_cast<int>(X_MAX_Y_MID_SVGASPECTALIGN), "");
static_assert(static_cast<int>(SkSVGPreserveAspectRatio::kXMinYMax) == static_cast<int>(X_MIN_Y_MAX_SVGASPECTALIGN), "");
static_assert(static_cast<int>(SkSVGPreserveAspectRatio::kXMidYMax) == static_cast<int>(X_MID_Y_MAX_SVGASPECTALIGN), "");
static_assert(static_cast<int>(SkSVGPreserveAspectRatio::kXMaxYMax) == static_cast<int>(X_MAX_Y_MAX_SVGASPECTALIGN), "");
static_assert(static_cast<int>(SkSVGPreserveAspectRatio::kNone)     == static_cast<int>(NONE_SVGASPECTALIGN),        "");

// SkSVGPreserveAspectRatio::Scale
static_assert(static_cast<int>(SkSVGPreserveAspectRatio::kMeet)  == static_cast<int>(MEET_SK_SVGASPECTSCALE),  "");
static_assert(static_cast<int>(SkSVGPreserveAspectRatio::kSlice) == static_cast<int>(SLICE_SK_SVGASPECTSCALE), "");


/*
 * ASSERTIONS OF REFERENCED OBJECTS
 */

static_assert(std::is_base_of<SkRefCnt, SkSVGDOM>::value,  "");
static_assert(std::is_base_of<SkRefCnt, SkSVGNode>::value, "");
