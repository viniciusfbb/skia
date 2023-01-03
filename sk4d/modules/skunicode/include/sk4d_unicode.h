/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
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
SK4D_API void sk4d_unicode_for_each_bidi_region(sk_unicode_t* self, const uint16_t utf16_text[], int32_t utf16_units, sk_direction_t direction, sk_unicode_bidi_region_proc proc, void* context);
SK4D_API void sk4d_unicode_for_each_break(sk_unicode_t* self, const char16_t utf16_text[], int32_t utf16_units, sk_breaktype_t type, sk_unicode_break_proc proc, void* context);
SK4D_API void sk4d_unicode_for_each_codepoint(sk_unicode_t* self, const char16_t utf16_text[], int32_t utf16_units, sk_unicode_codepoint_proc proc, void* context);
SK4D_API sk_unicodebreakiterator_t* sk4d_unicodebreakiterator_create(sk_unicode_t* unicode, sk_breaktype_t type, const char text[], int32_t units);
SK4D_API sk_unicodebreakiterator_t* sk4d_unicodebreakiterator_create2(sk_unicode_t* unicode, sk_breaktype_t type, const char16_t utf16_text[], int32_t utf16_units);
SK4D_API void sk4d_unicodebreakiterator_destroy(sk_unicodebreakiterator_t* self);
SK4D_API bool sk4d_unicodebreakiterator_next(sk_unicodebreakiterator_t* self, sk_unicodebreakiteratorelem_t* elem);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
