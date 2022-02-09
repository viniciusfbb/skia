/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/gr4d_backendsurface.h"
#include "src/c/sk4d_mapping.h"

gr_backendrendertarget_t* gr4d_backendrendertarget_create_gl(int32_t width, int32_t height, int32_t sample_count, int32_t stencil_bits, const gr_gl_framebufferinfo_t* framebuffer_info) {
    return ToGrBackendRenderTarget(SK4D_ONLY_GL(new GrBackendRenderTarget(width, height, sample_count, stencil_bits, AsGrGLFramebufferInfo(*framebuffer_info)), new GrBackendRenderTarget()));
}

gr_backendrendertarget_t* gr4d_backendrendertarget_create_mtl(int32_t width, int32_t height, const gr_mtl_textureinfo_t* texture_info) {
    return ToGrBackendRenderTarget(SK4D_ONLY_METAL(new GrBackendRenderTarget(width, height, AsGrMtlTextureInfo(texture_info)), new GrBackendRenderTarget()));
}

void gr4d_backendrendertarget_destroy(gr_backendrendertarget_t* self) {
    delete AsGrBackendRenderTarget(self);
}

gr_backendapi_t gr4d_backendrendertarget_get_backend_api(const gr_backendrendertarget_t* self) {
    return SK4D_ONLY_GPU(ToGrBackendAPI(AsGrBackendRenderTarget(self)->backend()), (gr_backendapi_t)0);
}

int32_t gr4d_backendrendertarget_get_height(const gr_backendrendertarget_t* self) {
    return SK4D_ONLY_GPU(AsGrBackendRenderTarget(self)->height(), 0);
}

int32_t gr4d_backendrendertarget_get_sample_count(const gr_backendrendertarget_t* self) {
    return SK4D_ONLY_GPU(AsGrBackendRenderTarget(self)->sampleCnt(), 0);
}

int32_t gr4d_backendrendertarget_get_stencil_bits(const gr_backendrendertarget_t* self) {
    return SK4D_ONLY_GPU(AsGrBackendRenderTarget(self)->stencilBits(), 0);
}

int32_t gr4d_backendrendertarget_get_width(const gr_backendrendertarget_t* self) {
    return SK4D_ONLY_GPU(AsGrBackendRenderTarget(self)->width(), 0);
}

bool gr4d_backendrendertarget_is_valid(const gr_backendrendertarget_t* self) {
    return AsGrBackendRenderTarget(self)->isValid();
}

gr_backendtexture_t* gr4d_backendtexture_create_gl(int32_t width, int32_t height, bool is_mipmapped, const gr_gl_textureinfo_t* texture_info) {
    return ToGrBackendTexture(SK4D_ONLY_GL(new GrBackendTexture(width, height, AsGrMipmapped(is_mipmapped), AsGrGLTextureInfo(*texture_info)), new GrBackendTexture()));
}

gr_backendtexture_t* gr4d_backendtexture_create_mtl(int32_t width, int32_t height, bool is_mipmapped, const gr_mtl_textureinfo_t* texture_info) {
    return ToGrBackendTexture(SK4D_ONLY_METAL(new GrBackendTexture(width, height, AsGrMipmapped(is_mipmapped), AsGrMtlTextureInfo(texture_info)), new GrBackendTexture()));
}

void gr4d_backendtexture_destroy(gr_backendtexture_t* self) {
    delete AsGrBackendTexture(self);
}

gr_backendapi_t gr4d_backendtexture_get_backend_api(const gr_backendtexture_t* self) {
    return SK4D_ONLY_GPU(ToGrBackendAPI(AsGrBackendTexture(self)->backend()), (gr_backendapi_t)0);
}

bool gr4d_backendtexture_get_gl_framebuffer_info(const gr_backendtexture_t* self, gr_gl_textureinfo_t* texture_info) {
    return SK4D_ONLY_GL(AsGrBackendTexture(self)->getGLTextureInfo(AsGrGLTextureInfo(texture_info)), false);
}

int32_t gr4d_backendtexture_get_height(const gr_backendtexture_t* self) {
    return SK4D_ONLY_GPU(AsGrBackendTexture(self)->height(), 0);
}

int32_t gr4d_backendtexture_get_width(const gr_backendtexture_t* self) {
    return SK4D_ONLY_GPU(AsGrBackendTexture(self)->width(), 0);
}

bool gr4d_backendtexture_has_mipmaps(const gr_backendtexture_t* self) {
    return SK4D_ONLY_GPU(AsGrBackendTexture(self)->hasMipmaps(), false);
}

bool gr4d_backendtexture_is_valid(const gr_backendtexture_t* self) {
    return AsGrBackendTexture(self)->isValid();
}
