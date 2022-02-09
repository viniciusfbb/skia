/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_pixmap_DEFINED
#define sk4d_pixmap_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_pixmap_t* sk4d_pixmap_create(const sk_imageinfo_t* image_info, const void* pixels, size_t row_bytes);
SK4D_API void sk4d_pixmap_destroy(sk_pixmap_t* self);
SK4D_API bool sk4d_pixmap_erase(const sk_pixmap_t* self, sk_color_t color, const sk_irect_t* area);
SK4D_API bool sk4d_pixmap_erase2(const sk_pixmap_t* self, const sk_color4f_t* color, sk_colorspace_t* color_space, const sk_irect_t* area);
SK4D_API bool sk4d_pixmap_extract_subset(const sk_pixmap_t* self, sk_pixmap_t* dest, const sk_irect_t* area);
SK4D_API float sk4d_pixmap_get_alpha(const sk_pixmap_t* self, int32_t x, int32_t y);
SK4D_API sk_alphatype_t sk4d_pixmap_get_alpha_type(const sk_pixmap_t* self);
SK4D_API sk_color_t sk4d_pixmap_get_color(const sk_pixmap_t* self, int32_t x, int32_t y);
SK4D_API sk_colorspace_t* sk4d_pixmap_get_color_space(const sk_pixmap_t* self);
SK4D_API sk_colortype_t sk4d_pixmap_get_color_type(const sk_pixmap_t* self);
SK4D_API int32_t sk4d_pixmap_get_height(const sk_pixmap_t* self);
SK4D_API void sk4d_pixmap_get_image_info(const sk_pixmap_t* self, /*out*/ sk_imageinfo_t* result);
SK4D_API void* sk4d_pixmap_get_pixel_addr(const sk_pixmap_t* self, int32_t x, int32_t y);
SK4D_API void* sk4d_pixmap_get_pixels(const sk_pixmap_t* self);
SK4D_API size_t sk4d_pixmap_get_row_bytes(const sk_pixmap_t* self);
SK4D_API int32_t sk4d_pixmap_get_width(const sk_pixmap_t* self);
SK4D_API bool sk4d_pixmap_read_pixels(const sk_pixmap_t* self, const sk_pixmap_t* dest, int32_t src_x, int32_t src_y);
SK4D_API bool sk4d_pixmap_scale_pixels(const sk_pixmap_t* self, const sk_pixmap_t* dest, const sk_samplingoptions_t* sampling);
SK4D_API void sk4d_pixmap_set_colorspace(sk_pixmap_t* self, sk_colorspace_t* value);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
