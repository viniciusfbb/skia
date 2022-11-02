/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_unicode_types_DEFINED
#define sk4d_unicode_types_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

typedef struct sk_unicode_t sk_unicode_t;

typedef enum {
  WORDS_SK_BREAKTYPE,
  GRAPHEMES_SK_BREAKTYPE,
  LINES_SK_BREAKTYPE,
} sk_breaktype_t;

typedef enum {
    LEFT_TO_RIGHT_SK_DIRECTION,
    RIGHT_TO_LEFT_SK_DIRECTION,
} sk_direction_t;

typedef void (*sk_unicode_bidi_region_proc) (int32_t start, int32_t end, uint8_t level, void* context);
typedef void (*sk_unicode_break_proc)       (int32_t position, int32_t status, void* context);
typedef void (*sk_unicode_codepoint_proc)   (sk_unichar_t unichar, int32_t start, int32_t end, void* context);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
