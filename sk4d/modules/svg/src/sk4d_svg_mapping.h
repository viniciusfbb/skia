/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_svg_mapping_DEFINED
#define sk4d_svg_mapping_DEFINED

#include "src/c/sk4d_mapping.h"
#include "modules/svg/include/sk4d_svg_types.h"
#include "modules/svg/include/SkSVGDOM.h"
#include "modules/svg/include/SkSVGNode.h"
#include "modules/svg/include/SkSVGRenderContext.h"
#include "modules/svg/include/SkSVGSVG.h"
#include "modules/svg/include/SkSVGTypes.h"

SK4D_DEF_CLASS_MAP(SkSVGDOM, sk_svgdom_t, SVGDOM)
SK4D_DEF_CLASS_MAP(SkSVGLength, sk_svglength_t, SVGLength)
SK4D_DEF_CLASS_MAP(SkSVGNode, sk_svgnode_t, SVGNode)
SK4D_DEF_CLASS_MAP(SkSVGPreserveAspectRatio, sk_svgpreserveaspectratio_t, SVGPreserveAspectRatio)
SK4D_DEF_CLASS_MAP(SkSVGSVG, sk_svgsvg_t, SVGSVG)
SK4D_DEF_CLASS_MAP(SkSVGViewBoxType, sk_rect_t, SVGViewBoxType) 

#endif
