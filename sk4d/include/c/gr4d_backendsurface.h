/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef gr4d_backendsurface_DEFINED
#define gr4d_backendsurface_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API gr_backendrendertarget_t* gr4d_backendrendertarget_create_gl(int32_t width, int32_t height, int32_t sample_count, int32_t stencil_bits, const gr_gl_framebufferinfo_t* framebuffer_info);
SK4D_API gr_backendrendertarget_t* gr4d_backendrendertarget_create_mtl(int32_t width, int32_t height, const gr_mtl_textureinfo_t* texture_info);
SK4D_API void gr4d_backendrendertarget_destroy(gr_backendrendertarget_t* self);
SK4D_API gr_backendapi_t gr4d_backendrendertarget_get_backend_api(const gr_backendrendertarget_t* self);
SK4D_API int32_t gr4d_backendrendertarget_get_height(const gr_backendrendertarget_t* self);
SK4D_API int32_t gr4d_backendrendertarget_get_sample_count(const gr_backendrendertarget_t* self);
SK4D_API int32_t gr4d_backendrendertarget_get_stencil_bits(const gr_backendrendertarget_t* self);
SK4D_API int32_t gr4d_backendrendertarget_get_width(const gr_backendrendertarget_t* self);
SK4D_API bool gr4d_backendrendertarget_is_valid(const gr_backendrendertarget_t* self);
SK4D_API gr_backendtexture_t* gr4d_backendtexture_create_gl(int32_t width, int32_t height, bool is_mipmapped, const gr_gl_textureinfo_t* texture_info);
SK4D_API gr_backendtexture_t* gr4d_backendtexture_create_mtl(int32_t width, int32_t height, bool is_mipmapped, const gr_mtl_textureinfo_t* texture_info);
SK4D_API void gr4d_backendtexture_destroy(gr_backendtexture_t* self);
SK4D_API gr_backendapi_t gr4d_backendtexture_get_backend_api(const gr_backendtexture_t* self);
SK4D_API bool gr4d_backendtexture_get_gl_framebuffer_info(const gr_backendtexture_t* self, /*out*/ gr_gl_textureinfo_t* texture_info);
SK4D_API int32_t gr4d_backendtexture_get_height(const gr_backendtexture_t* self);
SK4D_API int32_t gr4d_backendtexture_get_width(const gr_backendtexture_t* self);
SK4D_API bool gr4d_backendtexture_has_mipmaps(const gr_backendtexture_t* self);
SK4D_API bool gr4d_backendtexture_is_valid(const gr_backendtexture_t* self);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
