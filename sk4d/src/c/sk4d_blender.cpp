/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_blender.h"
#include "src/c/sk4d_mapping.h"

sk_blender_t* sk4d_blender_make_arithmetic(float k1, float k2, float k3, float k4, bool enforce_premultiplied_color) {
    return ToBlender(SkBlenders::Arithmetic(k1, k2, k3, k4, enforce_premultiplied_color).release());
}

sk_blender_t* sk4d_blender_make_mode(sk_blendmode_t mode) {
    return ToBlender(SkBlender::Mode(AsBlendMode(mode)).release());
}
