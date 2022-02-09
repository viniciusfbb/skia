/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_string.h"
#include "src/c/sk4d_mapping.h"

sk_string_t* sk4d_string_create(void) {
    return ToString(new SkString());
}
void sk4d_string_destroy(sk_string_t* self) {
    delete AsString(self);
}

const char* sk4d_string_get_text(const sk_string_t* self) {
    return AsString(self)->c_str();
}

void sk4d_string_set_text(sk_string_t* self, const char value[]) {
    AsString(self)->set(value);
}
