/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_typeface_DEFINED
#define sk4d_typeface_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_string_t* sk4d_typeface_get_family_name(const sk_typeface_t* self);
SK4D_API sk_fontslant_t sk4d_typeface_get_slant(const sk_typeface_t* self);
SK4D_API void sk4d_typeface_get_style(const sk_typeface_t* self, /*out*/ sk_fontstyle_t* result);
SK4D_API int32_t sk4d_typeface_get_weight(const sk_typeface_t* self);
SK4D_API int32_t sk4d_typeface_get_width(const sk_typeface_t* self);
SK4D_API sk_typeface_t* sk4d_typeface_make_default(void);
SK4D_API sk_typeface_t* sk4d_typeface_make_from_file(const char file_name[], int32_t ttc_index);
SK4D_API sk_typeface_t* sk4d_typeface_make_from_stream(sk_stream_t* stream, int32_t ttc_index);
SK4D_API sk_typeface_t* sk4d_typeface_make_from_name(const char family_name[], const sk_fontstyle_t* style);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
