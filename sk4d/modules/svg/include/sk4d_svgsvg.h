/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_svgsvg_DEFINED
#define sk4d_svgsvg_DEFINED

#include "modules/svg/include/sk4d_svg_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API void sk4d_svgsvg_get_height(const sk_svgsvg_t* self, /*out*/ sk_svglength_t* result);
SK4D_API void sk4d_svgsvg_get_intrinsic_size(const sk_svgsvg_t* self, const sk_size_t* view_port, float dpi, /*out*/ sk_size_t* result);
SK4D_API void sk4d_svgsvg_get_preserve_aspect_ratio(const sk_svgsvg_t* self, /*out*/ sk_svgpreserveaspectratio_t* result);
SK4D_API bool sk4d_svgsvg_get_view_box(const sk_svgsvg_t* self, /*out*/ sk_rect_t* result);
SK4D_API void sk4d_svgsvg_get_width(const sk_svgsvg_t* self, /*out*/ sk_svglength_t* result);
SK4D_API void sk4d_svgsvg_get_x(const sk_svgsvg_t* self, /*out*/ sk_svglength_t* result);
SK4D_API void sk4d_svgsvg_get_y(const sk_svgsvg_t* self, /*out*/ sk_svglength_t* result);
SK4D_API void sk4d_svgsvg_set_height(sk_svgsvg_t* self, sk_svglength_t* value);
SK4D_API void sk4d_svgsvg_set_preserve_aspect_ratio(sk_svgsvg_t* self, sk_svgpreserveaspectratio_t* value);
SK4D_API void sk4d_svgsvg_set_view_box(sk_svgsvg_t* self, sk_rect_t* view_box);
SK4D_API void sk4d_svgsvg_set_width(sk_svgsvg_t* self, sk_svglength_t* value);
SK4D_API void sk4d_svgsvg_set_x(sk_svgsvg_t* self, sk_svglength_t* value);
SK4D_API void sk4d_svgsvg_set_y(sk_svgsvg_t* self, sk_svglength_t* value);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
