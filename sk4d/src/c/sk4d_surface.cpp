/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <memory>

#include "include/c/sk4d_surface.h"
#include "src/c/sk4d_mapping.h"

void sk4d_surface_draw(sk_surface_t* self, sk_canvas_t* canvas, float x, float y, sk_paint_t* paint) {
    AsSurface(self)->draw(AsCanvas(canvas), x, y, AsPaint(paint));
}

void sk4d_surface_flush(sk_surface_t* self) {
    AsSurface(self)->flush();
}

void sk4d_surface_flush_and_submit(sk_surface_t* self, bool sync_cpu) {
    AsSurface(self)->flushAndSubmit(sync_cpu);
}

sk_canvas_t* sk4d_surface_get_canvas(sk_surface_t* self) {
    return ToCanvas(AsSurface(self)->getCanvas());
}

void sk4d_surface_get_props(const sk_surface_t* self, sk_surfaceprops_t* result) {
    *result = ToSurfaceProps(AsSurface(self)->props());
}

sk_surface_t* sk4d_surface_make_from_ca_metal_layer(gr_directcontext_t* context, gr_mtl_handle_t layer, gr_surfaceorigin_t origin, int32_t sample_count, sk_colortype_t color_type, sk_colorspace_t* color_space, const sk_surfaceprops_t* props, gr_mtl_handle_t* drawable) {
    return SK4D_ONLY_METAL(ToSurface(SkSurface::MakeFromCAMetalLayer(AsGrDirectContext(context), layer, AsGrSurfaceOrigin(origin), sample_count, AsColorType(color_type), sk_ref_sp(AsColorSpace(color_space)), AsSurfaceProps(props), drawable).release()), nullptr);
}

sk_surface_t* sk4d_surface_make_from_mtk_view(gr_directcontext_t* context, gr_mtl_handle_t view, gr_surfaceorigin_t origin, int32_t sample_count, sk_colortype_t color_type, sk_colorspace_t* color_space, const sk_surfaceprops_t* props) {
    return SK4D_ONLY_METAL(ToSurface(SkSurface::MakeFromMTKView(AsGrDirectContext(context), view, AsGrSurfaceOrigin(origin), sample_count, AsColorType(color_type), sk_ref_sp(AsColorSpace(color_space)), AsSurfaceProps(props)).release()), nullptr);
}

sk_surface_t* sk4d_surface_make_from_render_target(gr_directcontext_t* context, const gr_backendrendertarget_t* render_target, gr_surfaceorigin_t origin, sk_colortype_t color_type, sk_colorspace_t* color_space, const sk_surfaceprops_t* props) {
    return SK4D_ONLY_GPU(ToSurface(SkSurface::MakeFromBackendRenderTarget(AsGrDirectContext(context), AsGrBackendRenderTarget(*render_target), AsGrSurfaceOrigin(origin), AsColorType(color_type), sk_ref_sp(AsColorSpace(color_space)), AsSurfaceProps(props)).release()), nullptr);
}

sk_surface_t* sk4d_surface_make_from_texture(gr_directcontext_t* context, const gr_backendtexture_t* texture, gr_surfaceorigin_t origin, int32_t sample_count, sk_colortype_t color_type, sk_colorspace_t* color_space, const sk_surfaceprops_t* props) {
    return SK4D_ONLY_GPU(ToSurface(SkSurface::MakeFromBackendTexture(AsGrDirectContext(context), AsGrBackendTexture(*texture), AsGrSurfaceOrigin(origin), sample_count, AsColorType(color_type), sk_ref_sp(AsColorSpace(color_space)), AsSurfaceProps(props)).release()), nullptr);
}

sk_image_t* sk4d_surface_make_image_snapshot(sk_surface_t* self) {
    return ToImage(AsSurface(self)->makeImageSnapshot().release());
}

sk_image_t* sk4d_surface_make_image_snapshot2(sk_surface_t* self, const sk_irect_t* bounds) {
    return ToImage(AsSurface(self)->makeImageSnapshot(AsIRect(*bounds)).release());
}

sk_surface_t* sk4d_surface_make_raster(const sk_imageinfo_t* image_info, size_t row_bytes, const sk_surfaceprops_t* props) {
    return ToSurface(SkSurface::MakeRaster(AsImageInfo(image_info), row_bytes, AsSurfaceProps(props)).release());
}

sk_surface_t* sk4d_surface_make_raster_direct(const sk_pixmap_t* pixmap, sk_surface_raster_release_proc proc, void* proc_context, const sk_surfaceprops_t* props) {
    return ToSurface(SkSurface::MakeRasterDirectReleaseProc(AsPixmap(pixmap)->info(), AsPixmap(pixmap)->writable_addr(), AsPixmap(pixmap)->rowBytes(), proc, proc_context, AsSurfaceProps(props)).release());
}

sk_surface_t* sk4d_surface_make_render_target(gr_directcontext_t* context, bool is_budgeted, const sk_imageinfo_t *image_info, int32_t sample_count, gr_surfaceorigin_t origin, const sk_surfaceprops_t* props, bool should_create_with_mips) {
    return SK4D_ONLY_GPU(ToSurface(SkSurface::MakeRenderTarget(AsGrDirectContext(context), AsBudgeted(is_budgeted), AsImageInfo(image_info), sample_count, AsGrSurfaceOrigin(origin), AsSurfaceProps(props), should_create_with_mips).release()), nullptr);
}

sk_pixmap_t* sk4d_surface_peek_pixels(sk_surface_t* self) {
    auto r = std::make_unique<SkPixmap>();
    return AsSurface(self)->peekPixels(r.get()) ? ToPixmap(r.release()) : nullptr;
}

bool sk4d_surface_read_pixels(sk_surface_t* self, const sk_pixmap_t* dest, int32_t src_x, int32_t src_y) {
    return AsSurface(self)->readPixels(AsPixmap(*dest), src_x, src_y);
}
