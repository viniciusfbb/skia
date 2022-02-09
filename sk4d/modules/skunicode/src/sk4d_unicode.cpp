/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "modules/skunicode/include/sk4d_unicode.h"
#include "modules/skunicode/src/sk4d_unicode_mapping.h"

sk_unicode_t* sk4d_unicode_create(void) {
    return ToUnicode(SkUnicode::Make().release());
}

void sk4d_unicode_destroy(sk_unicode_t* self) {
    delete AsUnicode(self);
}

void sk4d_unicode_for_each_bidi_region(sk_unicode_t* self, const uint16_t text[], int32_t units, sk_direction_t direction, sk_unicode_bidi_region_proc proc, void* context) {
    AsUnicode(self)->forEachBidiRegion(text, units, AsDirection(direction), [proc, context](SkBidiIterator::Position start, SkBidiIterator::Position end, SkBidiIterator::Level level) {
       proc(start, end, level, context);
    });
}

void sk4d_unicode_for_each_break(sk_unicode_t* self, const char16_t text[], int32_t units, sk_breaktype_t type, sk_unicode_break_proc proc, void* context) {
    AsUnicode(self)->forEachBreak(text, units, AsBreakType(type), [proc, context](SkBreakIterator::Position position, SkBreakIterator::Status status) { 
        proc(position, status, context);
    });
}

void sk4d_unicode_for_each_codepoint(sk_unicode_t* self, const char16_t text[], int32_t units, sk_unicode_codepoint_proc proc, void* context) {
    AsUnicode(self)->forEachCodepoint(text, units, [proc, context](SkUnichar unichar, int32_t start, int32_t end) {
        proc(unichar, start, end, context);
    });
}

