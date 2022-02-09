/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_paragraphbuilder_DEFINED
#define sk4d_paragraphbuilder_DEFINED

#include "modules/skparagraph/include/sk4d_paragraph_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API void sk4d_paragraphbuilder_add_placeholder(sk_paragraphbuilder_t* self, const sk_placeholderstyle_t* placeholder);
SK4D_API void sk4d_paragraphbuilder_add_text(sk_paragraphbuilder_t* self, const char* text, size_t size);
SK4D_API sk_paragraph_t* sk4d_paragraphbuilder_build(sk_paragraphbuilder_t* self);
SK4D_API sk_paragraphbuilder_t* sk4d_paragraphbuilder_create(const sk_paragraphstyle_t* paragraph_style);
SK4D_API sk_paragraphbuilder_t* sk4d_paragraphbuilder_create2(const sk_paragraphstyle_t* paragraph_style, sk_typefacefontprovider_t* font_provider, bool enable_font_fallback);
SK4D_API void sk4d_paragraphbuilder_destroy(sk_paragraphbuilder_t* self);
SK4D_API void sk4d_paragraphbuilder_pop(sk_paragraphbuilder_t* self);
SK4D_API void sk4d_paragraphbuilder_push_style(sk_paragraphbuilder_t* self, const sk_textstyle_t* text_style);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
