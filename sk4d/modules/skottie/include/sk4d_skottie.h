/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_skottie_DEFINED
#define sk4d_skottie_DEFINED

#include "modules/skottie/include/sk4d_skottie_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API double sk4d_skottieanimation_get_duration(const sk_skottieanimation_t* self);
SK4D_API double sk4d_skottieanimation_get_fps(const sk_skottieanimation_t* self);
SK4D_API double sk4d_skottieanimation_get_in_point(const sk_skottieanimation_t* self);
SK4D_API double sk4d_skottieanimation_get_out_point(const sk_skottieanimation_t* self);
SK4D_API void sk4d_skottieanimation_get_size(const sk_skottieanimation_t* self, /*out*/ sk_size_t* result);
SK4D_API const char* sk4d_skottieanimation_get_version(const sk_skottieanimation_t* self);
SK4D_API sk_skottieanimation_t* sk4d_skottieanimation_make_from_file(const char file_name[]);
SK4D_API sk_skottieanimation_t* sk4d_skottieanimation_make_from_stream(sk_stream_t* stream, sk_resourceprovider_t* resource_provider);
SK4D_API void sk4d_skottieanimation_ref(const sk_skottieanimation_t* self);
SK4D_API void sk4d_skottieanimation_render(const sk_skottieanimation_t* self, sk_canvas_t* canvas, const sk_rect_t* dest, uint32_t render_flags);
SK4D_API void sk4d_skottieanimation_seek_frame(sk_skottieanimation_t* self, double tick);
SK4D_API void sk4d_skottieanimation_seek_frame_time(sk_skottieanimation_t* self, double tick);
SK4D_API void sk4d_skottieanimation_unref(const sk_skottieanimation_t* self);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
