/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_codec_DEFINED
#define sk4d_codec_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API void sk4d_codec_destroy(sk_codec_t* codec);
SK4D_API void sk4d_codec_get_dimensions(const sk_codec_t* self, /*out*/ sk_isize_t* result);
SK4D_API sk_image_t* sk4d_codec_get_image(sk_codec_t* self, sk_colortype_t color_type, sk_alphatype_t alpha_type, sk_colorspace_t* color_space);
SK4D_API bool sk4d_codec_get_pixels(sk_codec_t* self, void* pixels, size_t row_bytes, sk_colortype_t color_type, sk_alphatype_t alpha_type, sk_colorspace_t* color_space);
SK4D_API sk_codec_t* sk4d_codec_make_from_file(const char file_name[]);
SK4D_API sk_codec_t* sk4d_codec_make_with_copy(const void* data, size_t size);
SK4D_API sk_codec_t* sk4d_codec_make_without_copy(const void* data, size_t size);
SK4D_API void sk4d_animcodecplayer_destroy(sk_animcodecplayer_t* self);
SK4D_API void sk4d_animcodecplayer_get_dimensions(const sk_animcodecplayer_t* self, /*out*/ sk_isize_t* result);
SK4D_API uint32_t sk4d_animcodecplayer_get_duration(const sk_animcodecplayer_t* self);
SK4D_API sk_image_t* sk4d_animcodecplayer_get_frame(sk_animcodecplayer_t* self);
SK4D_API sk_animcodecplayer_t* sk4d_animcodecplayer_make_from_file(const char file_name[]);
SK4D_API sk_animcodecplayer_t* sk4d_animcodecplayer_make_from_stream(sk_stream_t* stream);
SK4D_API bool sk4d_animcodecplayer_seek(sk_animcodecplayer_t* self, uint32_t milliseconds);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
