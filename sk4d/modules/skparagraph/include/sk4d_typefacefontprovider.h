/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_typefacefontprovider_DEFINED
#define sk4d_typefacefontprovider_DEFINED

#include "modules/skparagraph/include/sk4d_paragraph_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_typefacefontprovider_t* sk4d_typefacefontprovider_create(void);
SK4D_API void sk4d_typefacefontprovider_register_typeface(sk_typefacefontprovider_t* self, sk_typeface_t* typeface);
SK4D_API void sk4d_typefacefontprovider_register_typeface2(sk_typefacefontprovider_t* self, sk_typeface_t* typeface, const char family_name[]);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
