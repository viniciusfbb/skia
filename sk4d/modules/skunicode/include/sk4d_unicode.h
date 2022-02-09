/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_unicode_DEFINED
#define sk4d_unicode_DEFINED

#include "modules/skunicode/include/sk4d_unicode_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_unicode_t* sk4d_unicode_create(void);
SK4D_API void sk4d_unicode_destroy(sk_unicode_t* self);
SK4D_API void sk4d_unicode_for_each_bidi_region(sk_unicode_t* self, const uint16_t text[], int32_t units, sk_direction_t direction, sk_unicode_bidi_region_proc proc, void* context);
SK4D_API void sk4d_unicode_for_each_break(sk_unicode_t* self, const char16_t text[], int32_t units, sk_breaktype_t type, sk_unicode_break_proc proc, void* context);
SK4D_API void sk4d_unicode_for_each_codepoint(sk_unicode_t* self, const char16_t text[], int32_t units, sk_unicode_codepoint_proc proc, void* context);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
