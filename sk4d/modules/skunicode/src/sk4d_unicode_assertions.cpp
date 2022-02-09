/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#include "include/core/SkString.h"
#include "modules/skunicode/include/SkUnicode.h"
#include "modules/skunicode/include/sk4d_unicode_types.h"

/*
 * ASSERTIONS OF ENUMERATIONS
 */

// SkBidiIterator::Direction
static_assert(static_cast<int>(SkBidiIterator::kLTR) == static_cast<int>(LEFT_TO_RIGHT_SK_DIRECTION), "");
static_assert(static_cast<int>(SkBidiIterator::kRTL) == static_cast<int>(RIGHT_TO_LEFT_SK_DIRECTION), "");

// SkUnicode::BreakType
static_assert(static_cast<int>(SkUnicode::BreakType::kWords)     == static_cast<int>(WORDS_SK_BREAKTYPE),     "");
static_assert(static_cast<int>(SkUnicode::BreakType::kGraphemes) == static_cast<int>(GRAPHEMES_SK_BREAKTYPE), "");
static_assert(static_cast<int>(SkUnicode::BreakType::kLines)     == static_cast<int>(LINES_SK_BREAKTYPE),     "");
