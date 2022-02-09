/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_unicode_mapping_DEFINED
#define sk4d_unicode_mapping_DEFINED

#include "src/c/sk4d_mapping.h"
#include "modules/skunicode/include/SkUnicode.h"
#include "modules/skunicode/include/sk4d_unicode_types.h"

SK4D_DEF_CLASS_MAP(SkUnicode, sk_unicode_t, Unicode)

SK4D_DEF_ENUM_MAP(SkBidiIterator::Direction, sk_direction_t, Direction)
SK4D_DEF_ENUM_MAP(SkUnicode::BreakType, sk_breaktype_t, BreakType)

#endif