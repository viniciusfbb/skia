/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_animatedwebpencoder_DEFINED
#define sk4d_animatedwebpencoder_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API bool sk4d_animatedwebpencoder_encode_to_file(const char file_name[], const sk_frame_t src[], size_t count, int32_t quality);
SK4D_API bool sk4d_animatedwebpencoder_encode_to_stream(sk_wstream_t* w_stream, const sk_frame_t src[], size_t count, int32_t quality);

SK4D_C_PLUS_PLUS_END_GUARD

#endif