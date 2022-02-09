/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_data.h"
#include "src/c/sk4d_mapping.h"

sk_data_t* sk4d_data_make_empty(void) {
    return ToData(SkData::MakeEmpty().release());
}

sk_data_t* sk4d_data_make_with_copy(const void* data, size_t size) {
    return ToData(SkData::MakeWithCopy(data, size).release());
}
