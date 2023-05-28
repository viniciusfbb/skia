/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef gr4d_directcontext_DEFINED
#define gr4d_directcontext_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API void gr4d_directcontext_abandon_context(gr_directcontext_t* self);
SK4D_API gr_backendtexture_t* gr4d_directcontext_create_texture(gr_directcontext_t* self, int32_t width, int32_t height, sk_colortype_t color_type, bool is_mipmapped, bool is_renderable, bool is_protected);
SK4D_API gr_backendtexture_t* gr4d_directcontext_create_texture2(gr_directcontext_t* self, int32_t width, int32_t height, sk_colortype_t color_type, sk_color_t color, bool is_mipmapped, bool is_renderable, bool is_protected);
SK4D_API gr_backendtexture_t* gr4d_directcontext_create_texture3(gr_directcontext_t* self, int32_t width, int32_t height, sk_colortype_t color_type, const sk_color4f_t* color, bool is_mipmapped, bool is_renderable, bool is_protected);
SK4D_API void gr4d_directcontext_delete_texture(gr_directcontext_t* self, gr_backendtexture_t* texture);
SK4D_API void gr4d_directcontext_dump_memory_statistics(const gr_directcontext_t* self, sk_tracememorydump_t* trace_memory_dump);
SK4D_API void gr4d_directcontext_flush(gr_directcontext_t* self);
SK4D_API void gr4d_directcontext_flush_and_submit(gr_directcontext_t* self, bool sync_cpu);
SK4D_API void gr4d_directcontext_free_gpu_resources(gr_directcontext_t* self);
SK4D_API gr_backendapi_t gr4d_directcontext_get_backend_api(const gr_directcontext_t* self);
SK4D_API int32_t gr4d_directcontext_get_max_surface_sample_count_for_color_type(const gr_directcontext_t* self, sk_colortype_t color_type);
SK4D_API size_t gr4d_directcontext_get_resource_cache_limit(const gr_directcontext_t* self);
SK4D_API void gr4d_directcontext_get_resource_cache_usage(const gr_directcontext_t* self, /*out*/ int32_t* resources, /*out*/ size_t* resources_bytes);
SK4D_API bool gr4d_directcontext_is_abandoned(gr_directcontext_t* self);
SK4D_API gr_directcontext_t* gr4d_directcontext_make_gl(const gr_gl_interface_t* gl_interface, const gr_contextoptions_t* options);
SK4D_API gr_directcontext_t* gr4d_directcontext_make_metal(const gr_mtl_backendcontext_t* backend_context, const gr_contextoptions_t* options);
SK4D_API gr_directcontext_t* gr4d_directcontext_make_vulkan(const gr_vk_backendcontext_t* backend_context, const gr_contextoptions_t* options);
SK4D_API void gr4d_directcontext_perform_deferred_cleanup(gr_directcontext_t* self, int64_t milliseconds);
SK4D_API void gr4d_directcontext_purge_unlocked_resources(gr_directcontext_t* self, bool scratch_resources_only);
SK4D_API void gr4d_directcontext_purge_unlocked_resources2(gr_directcontext_t* self, size_t bytes_to_purge, bool prefer_scratch_resources);
SK4D_API void gr4d_directcontext_release_resources_and_abandon_context(gr_directcontext_t* self);
SK4D_API void gr4d_directcontext_reset_context(gr_directcontext_t* self);
SK4D_API void gr4d_directcontext_set_resource_cache_limit(gr_directcontext_t* self, size_t value);
SK4D_API bool gr4d_directcontext_submit(gr_directcontext_t* self, bool sync_cpu);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
