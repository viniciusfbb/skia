/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_version.h"
#include "src/c/sk4d_mapping.h"

int32_t sk4d_library_version_get_build(void) {
    return SK4D_VERSION_BUILD;
}

int32_t sk4d_library_version_get_major(void) {
    return SK4D_VERSION_MAJOR;
}

int32_t sk4d_library_version_get_minor(void) {
    return SK4D_VERSION_MINOR;
}
