/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "modules/svg/include/sk4d_svgsvg.h"
#include "modules/svg/src/sk4d_svg_mapping.h"

void sk4d_svgsvg_get_height(const sk_svgsvg_t* self, sk_svglength_t* result) {
    *result = ToSVGLength(AsSVGSVG(self)->getHeight());
}

void sk4d_svgsvg_get_intrinsic_size(const sk_svgsvg_t* self, const sk_size_t* view_port, float dpi, sk_size_t* result) {
    *result = ToSize(AsSVGSVG(self)->intrinsicSize(SkSVGLengthContext(AsSize(*view_port), dpi)));
}

void sk4d_svgsvg_get_preserve_aspect_ratio(const sk_svgsvg_t* self, sk_svgpreserveaspectratio_t* result) {
    *result = ToSVGPreserveAspectRatio(AsSVGSVG(self)->getPreserveAspectRatio());
}

bool sk4d_svgsvg_get_view_box(const sk_svgsvg_t* self, sk_rect_t* result) {
    auto r = AsSVGSVG(self)->getViewBox();
    if (!r.isValid())
        return false;
    *result = *ToSVGViewBoxType(r.get());
    return true;
}

void sk4d_svgsvg_get_width(const sk_svgsvg_t* self, sk_svglength_t* result) {
    *result = ToSVGLength(AsSVGSVG(self)->getWidth());
}

void sk4d_svgsvg_get_x(const sk_svgsvg_t* self, sk_svglength_t* result) {
    *result = ToSVGLength(AsSVGSVG(self)->getX());
}

void sk4d_svgsvg_get_y(const sk_svgsvg_t* self, sk_svglength_t* result) {
    *result = ToSVGLength(AsSVGSVG(self)->getY());
}

void sk4d_svgsvg_set_height(sk_svgsvg_t* self, sk_svglength_t* value) {
    AsSVGSVG(self)->setHeight(AsSVGLength(*value));
}

void sk4d_svgsvg_set_preserve_aspect_ratio(sk_svgsvg_t* self, sk_svgpreserveaspectratio_t* value) {
    AsSVGSVG(self)->setPreserveAspectRatio(AsSVGPreserveAspectRatio(*value));
}

void sk4d_svgsvg_set_view_box(sk_svgsvg_t* self, sk_rect_t* view_box) {
    AsSVGSVG(self)->setViewBox(AsSVGViewBoxType(*view_box));
}

void sk4d_svgsvg_set_width(sk_svgsvg_t* self, sk_svglength_t* value) {
    AsSVGSVG(self)->setWidth(AsSVGLength(*value));
}

void sk4d_svgsvg_set_x(sk_svgsvg_t* self, sk_svglength_t* value) {
    AsSVGSVG(self)->setX(AsSVGLength(*value));
}

void sk4d_svgsvg_set_y(sk_svgsvg_t* self, sk_svglength_t* value) {
    AsSVGSVG(self)->setY(AsSVGLength(*value));
}
