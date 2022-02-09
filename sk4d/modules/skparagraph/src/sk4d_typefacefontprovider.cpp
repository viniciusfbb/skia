/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "modules/skparagraph/include/sk4d_typefacefontprovider.h"
#include "modules/skparagraph/src/sk4d_paragraph_mapping.h"

sk_typefacefontprovider_t* sk4d_typefacefontprovider_create(void) {
    return ToTypefaceFontProvider(new skia::textlayout::TypefaceFontProvider());
}

void sk4d_typefacefontprovider_register_typeface(sk_typefacefontprovider_t* self, sk_typeface_t* typeface) {
    AsTypefaceFontProvider(self)->registerTypeface(sk_ref_sp(AsTypeface(typeface)));
}

void sk4d_typefacefontprovider_register_typeface2(sk_typefacefontprovider_t* self, sk_typeface_t* typeface, const char family_name[]) {
    AsTypefaceFontProvider(self)->registerTypeface(sk_ref_sp(AsTypeface(typeface)), SkString(family_name));
}
