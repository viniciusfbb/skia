/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/gr4d_directcontext.h"
#include "src/c/sk4d_mapping.h"

void gr4d_directcontext_abandon_context(gr_directcontext_t* self) {
    SK4D_ONLY_GPU(AsGrDirectContext(self)->abandonContext();)
}

gr_backendtexture_t* gr4d_directcontext_create_texture(gr_directcontext_t* self, int32_t width, int32_t height, sk_colortype_t color_type, bool is_mipmapped, bool is_renderable, bool is_protected) {
    return SK4D_ONLY_GPU(ToGrBackendTexture(new GrBackendTexture(AsGrDirectContext(self)->createBackendTexture(width, height, AsColorType(color_type), AsGrMipmapped(is_mipmapped), AsGrRenderable(is_renderable), AsGrProtected(is_protected)))), nullptr); 
}

gr_backendtexture_t* gr4d_directcontext_create_texture2(gr_directcontext_t* self, int32_t width, int32_t height, sk_colortype_t color_type, sk_color_t color, bool is_mipmapped, bool is_renderable, bool is_protected) {
    return SK4D_ONLY_GPU(ToGrBackendTexture(new GrBackendTexture(AsGrDirectContext(self)->createBackendTexture(width, height, AsColorType(color_type), SkColor4f::FromColor(color), AsGrMipmapped(is_mipmapped), AsGrRenderable(is_renderable), AsGrProtected(is_protected)))), nullptr); 
}

gr_backendtexture_t* gr4d_directcontext_create_texture3(gr_directcontext_t* self, int32_t width, int32_t height, sk_colortype_t color_type, const sk_color4f_t* color, bool is_mipmapped, bool is_renderable, bool is_protected) {
    return SK4D_ONLY_GPU(ToGrBackendTexture(new GrBackendTexture(AsGrDirectContext(self)->createBackendTexture(width, height, AsColorType(color_type), AsColor4f(*color), AsGrMipmapped(is_mipmapped), AsGrRenderable(is_renderable), AsGrProtected(is_protected)))), nullptr); 
}

void gr4d_directcontext_delete_texture(gr_directcontext_t* self, gr_backendtexture_t* texture) {
    SK4D_ONLY_GPU(AsGrDirectContext(self)->deleteBackendTexture(*AsGrBackendTexture(texture));)
}

void gr4d_directcontext_dump_memory_statistics(const gr_directcontext_t* self, sk_tracememorydump_t* trace_memory_dump) {
    SK4D_ONLY_GPU(AsGrDirectContext(self)->dumpMemoryStatistics(AsTraceMemoryDump(trace_memory_dump));)
}

void gr4d_directcontext_flush(gr_directcontext_t* self) {
    SK4D_ONLY_GPU(AsGrDirectContext(self)->flush();)
}

void gr4d_directcontext_flush_and_submit(gr_directcontext_t* self, bool sync_cpu) {
    SK4D_ONLY_GPU(AsGrDirectContext(self)->flushAndSubmit(sync_cpu);)
}

void gr4d_directcontext_free_gpu_resources(gr_directcontext_t* self) {
    SK4D_ONLY_GPU(AsGrDirectContext(self)->freeGpuResources();)
}

gr_backendapi_t gr4d_directcontext_get_backend_api(const gr_directcontext_t* self) {
    return SK4D_ONLY_GPU(ToGrBackendAPI(AsGrDirectContext(self)->backend()), (gr_backendapi_t)0);
}

int32_t gr4d_directcontext_get_max_surface_sample_count_for_color_type(const gr_directcontext_t* self, sk_colortype_t color_type) {
    return SK4D_ONLY_GPU(AsGrDirectContext(self)->maxSurfaceSampleCountForColorType(AsColorType(color_type)), 0);
}

size_t gr4d_directcontext_get_resource_cache_limit(const gr_directcontext_t* self) {
    return SK4D_ONLY_GPU(AsGrDirectContext(self)->getResourceCacheLimit(), 0);
}

void gr4d_directcontext_get_resource_cache_usage(const gr_directcontext_t* self, int32_t* resources, size_t* resources_bytes) {
    SK4D_ONLY_GPU(AsGrDirectContext(self)->getResourceCacheUsage(resources, resources_bytes);)
}

bool gr4d_directcontext_is_abandoned(gr_directcontext_t* self) {
    return SK4D_ONLY_GPU(AsGrDirectContext(self)->abandoned(), false);
}

gr_directcontext_t* gr4d_directcontext_make_gl(const gr_gl_interface_t* gl_interface, const gr_contextoptions_t* options) {
    SK4D_ONLY_GL(GrContextOptions defaultOptions;)
    return SK4D_ONLY_GL(ToGrDirectContext(GrDirectContext::MakeGL(sk_ref_sp(AsGrGLInterface(gl_interface)), (options) ? AsGrContextOptions(options) : defaultOptions).release()), nullptr);
}

gr_directcontext_t* gr4d_directcontext_make_metal(const gr_mtl_backendcontext_t* backend_context, const gr_contextoptions_t* options) {
    SK4D_ONLY_METAL(GrContextOptions defaultOptions;)
    return SK4D_ONLY_METAL(ToGrDirectContext(GrDirectContext::MakeMetal(AsGrMtlBackendContext(backend_context), (options) ? AsGrContextOptions(options) : defaultOptions).release()), nullptr);
}

gr_directcontext_t* gr4d_directcontext_make_vulkan(const gr_vk_backendcontext_t* backend_context, const gr_contextoptions_t* options) {
    SK4D_ONLY_VULKAN(GrContextOptions defaultOptions;)
    return SK4D_ONLY_VULKAN(ToGrDirectContext(GrDirectContext::MakeVulkan(AsGrVkBackendContext(backend_context), (options) ? AsGrContextOptions(options) : defaultOptions).release()), nullptr);
}

void gr4d_directcontext_perform_deferred_cleanup(gr_directcontext_t* self, int64_t milliseconds) {
    SK4D_ONLY_GPU(AsGrDirectContext(self)->performDeferredCleanup(std::chrono::milliseconds(milliseconds));)
}

void gr4d_directcontext_purge_unlocked_resources(gr_directcontext_t* self, bool scratch_resources_only) {
    SK4D_ONLY_GPU(AsGrDirectContext(self)->purgeUnlockedResources(scratch_resources_only);)
}

void gr4d_directcontext_purge_unlocked_resources2(gr_directcontext_t* self, size_t bytes_to_purge, bool prefer_scratch_resources) {
    SK4D_ONLY_GPU(AsGrDirectContext(self)->purgeUnlockedResources(bytes_to_purge, prefer_scratch_resources);)
}

void gr4d_directcontext_release_resources_and_abandon_context(gr_directcontext_t* self) {
    SK4D_ONLY_GPU(AsGrDirectContext(self)->releaseResourcesAndAbandonContext();)
}

void gr4d_directcontext_reset_context(gr_directcontext_t* self) {
    SK4D_ONLY_GPU(AsGrDirectContext(self)->resetContext();)
}

void gr4d_directcontext_set_resource_cache_limit(gr_directcontext_t* self, size_t value) {
    SK4D_ONLY_GPU(AsGrDirectContext(self)->setResourceCacheLimit(value);)
}

bool gr4d_directcontext_submit(gr_directcontext_t* self, bool sync_cpu) {
    return SK4D_ONLY_GPU(AsGrDirectContext(self)->submit(sync_cpu), false);
}
