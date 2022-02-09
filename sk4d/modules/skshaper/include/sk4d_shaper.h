/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_shaper_DEFINED
#define sk4d_shaper_DEFINED

#include "modules/skshaper/include/sk4d_shaper_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_shaper_t* sk4d_shaper_create(void);
SK4D_API void sk4d_shaper_destroy(sk_shaper_t* self);
SK4D_API sk_textblob_t* sk4d_shaper_shape(const sk_shaper_t* self, const char text[], size_t size, const sk_font_t* font, bool left_to_right, float width, const sk_point_t* offset, sk_point_t* end_point);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
