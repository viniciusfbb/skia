/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_image_DEFINED
#define sk4d_image_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API void sk4d_image_encode_to_file(const sk_image_t* self, const char file_name[], sk_encodedimageformat_t format, int32_t quality);
SK4D_API void sk4d_image_encode_to_stream(const sk_image_t* self, sk_wstream_t* w_stream, sk_encodedimageformat_t format, int32_t quality);
SK4D_API sk_alphatype_t sk4d_image_get_alpha_type(const sk_image_t* self);
SK4D_API sk_colorspace_t* sk4d_image_get_color_space(const sk_image_t* self);
SK4D_API sk_colortype_t sk4d_image_get_color_type(const sk_image_t* self);
SK4D_API int32_t sk4d_image_get_height(const sk_image_t* self);
SK4D_API void sk4d_image_get_image_info(const sk_image_t* self, /*out*/ sk_imageinfo_t* result);
SK4D_API uint32_t sk4d_image_get_unique_id(const sk_image_t* self);
SK4D_API int32_t sk4d_image_get_width(const sk_image_t* self);
SK4D_API bool sk4d_image_is_lazy_generated(const sk_image_t* self);
SK4D_API bool sk4d_image_is_texture_backed(const sk_image_t* self);
SK4D_API bool sk4d_image_is_valid(const sk_image_t* self, gr_directcontext_t* context);
SK4D_API sk_image_t* sk4d_image_make_from_adopted_texture(gr_directcontext_t* context, const gr_backendtexture_t* texture, gr_surfaceorigin_t origin, sk_colortype_t color_type, sk_alphatype_t alpha_type, sk_colorspace_t* color_space);
SK4D_API sk_image_t* sk4d_image_make_from_encoded_file(const char file_name[]);
SK4D_API sk_image_t* sk4d_image_make_from_encoded_stream(sk_stream_t* stream);
SK4D_API sk_image_t* sk4d_image_make_from_raster(const sk_pixmap_t* pixmap, sk_image_raster_release_proc proc, void* proc_context);
SK4D_API sk_image_t* sk4d_image_make_from_texture(gr_directcontext_t* context, const gr_backendtexture_t* texture, gr_surfaceorigin_t origin, sk_colortype_t color_type, sk_alphatype_t alpha_type, sk_colorspace_t* color_space, sk_image_texture_release_proc proc, void* proc_context);
SK4D_API sk_image_t* sk4d_image_make_non_texture_image(const sk_image_t* self);
SK4D_API sk_image_t* sk4d_image_make_raster_copy(const sk_pixmap_t* pixmap);
SK4D_API sk_image_t* sk4d_image_make_raster_image(const sk_image_t* self);
SK4D_API sk_shader_t* sk4d_image_make_shader(const sk_image_t* self, sk_tilemode_t tile_mode_x, sk_tilemode_t tile_mode_y, const sk_samplingoptions_t* sampling, const sk_matrix_t* local_matrix);
SK4D_API sk_image_t* sk4d_image_make_subset(const sk_image_t* self, const sk_irect_t* subset, gr_directcontext_t* context);
SK4D_API sk_image_t* sk4d_image_make_texture_image(const sk_image_t* self, gr_directcontext_t* context, bool is_mipmapped);
SK4D_API sk_image_t* sk4d_image_make_with_filter(const sk_image_t* self, gr_directcontext_t* context, const sk_imagefilter_t* filter, const sk_irect_t* subset, const sk_irect_t* clip_bounds, /*out*/ sk_irect_t* out_subset, /*out*/ sk_ipoint_t* offset);
SK4D_API sk_pixmap_t* sk4d_image_peek_pixels(const sk_image_t* self);
SK4D_API bool sk4d_image_read_pixels(const sk_image_t* self, gr_directcontext_t* context, const sk_pixmap_t* dest, int32_t src_x, int32_t src_y, sk_imagecachinghint_t caching_hint);
SK4D_API bool sk4d_image_scale_pixels(const sk_image_t* self, const sk_pixmap_t* dest, const sk_samplingoptions_t* sampling, sk_imagecachinghint_t caching_hint);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
