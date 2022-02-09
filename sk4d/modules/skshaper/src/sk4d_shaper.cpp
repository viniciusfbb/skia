/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "modules/skshaper/include/sk4d_shaper.h"
#include "modules/skshaper/src/sk4d_shaper_mapping.h"

sk_shaper_t* sk4d_shaper_create(void) {
    return ToShaper(SkShaper::Make().release());
}

void sk4d_shaper_destroy(sk_shaper_t* self) {
    delete AsShaper(self);
}

sk_textblob_t* sk4d_shaper_shape(const sk_shaper_t* self, const char text[], size_t size, const sk_font_t* font, bool left_to_right, float width, const sk_point_t* offset, sk_point_t* end_point) {
    SkTextBlobBuilderRunHandler builder(text, (offset) ? *AsPoint(offset) : SkPoint::Make(0, 0));
    AsShaper(self)->shape(text, size, AsFont(*font), left_to_right, width, &builder);
    if (end_point)
        *end_point = ToPoint(builder.endPoint());
    return ToTextBlob(builder.makeBlob().release());
}
