/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
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

void sk4d_unicode_for_each_bidi_region(sk_unicode_t* self, const uint16_t utf16_text[], int32_t utf16_units, sk_direction_t direction, sk_unicode_bidi_region_proc proc, void* context) {
    AsUnicode(self)->forEachBidiRegion(utf16_text, utf16_units, AsDirection(direction), [proc, context](SkBidiIterator::Position start, SkBidiIterator::Position end, SkBidiIterator::Level level) {
       proc(start, end, level, context);
    });
}

void sk4d_unicode_for_each_break(sk_unicode_t* self, const char16_t utf16_text[], int32_t utf16_units, sk_breaktype_t type, sk_unicode_break_proc proc, void* context) {
    AsUnicode(self)->forEachBreak(utf16_text, utf16_units, AsBreakType(type), [proc, context](SkBreakIterator::Position position, SkBreakIterator::Status status) { 
        proc(position, status, context);
    });
}

void sk4d_unicode_for_each_codepoint(sk_unicode_t* self, const char16_t utf16_text[], int32_t utf16_units, sk_unicode_codepoint_proc proc, void* context) {
    AsUnicode(self)->forEachCodepoint(utf16_text, utf16_units, [proc, context](SkUnichar unichar, int32_t start, int32_t end) {
        proc(unichar, start, end, context);
    });
}

sk_unicodebreakiterator_t* sk4d_unicodebreakiterator_create(sk_unicode_t* unicode, sk_breaktype_t type, const char text[], int32_t units) {
    auto r = AsUnicode(unicode)->makeBreakIterator(AsBreakType(type));
    r->setText(text, units);
    return ToBreakIterator(r.release());
}

sk_unicodebreakiterator_t* sk4d_unicodebreakiterator_create2(sk_unicode_t* unicode, sk_breaktype_t type, const char16_t utf16_text[], int32_t utf16_units) {
    auto r = AsUnicode(unicode)->makeBreakIterator(AsBreakType(type));
    r->setText(utf16_text, utf16_units);
    return ToBreakIterator(r.release());
}

void sk4d_unicodebreakiterator_destroy(sk_unicodebreakiterator_t* self) {
    delete AsBreakIterator(self);
}

bool sk4d_unicodebreakiterator_next(sk_unicodebreakiterator_t* self, sk_unicodebreakiteratorelem_t* elem) {
    if (AsBreakIterator(self)->isDone())
        return false;
    elem->position = AsBreakIterator(self)->current();
    elem->status   = AsBreakIterator(self)->status();
    AsBreakIterator(self)->next();
    return true;
}