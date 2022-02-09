/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_blender_DEFINED
#define sk4d_blender_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_blender_t* sk4d_blender_make_arithmetic(float k1, float k2, float k3, float k4, bool enforce_premultiplied_color);
SK4D_API sk_blender_t* sk4d_blender_make_mode(sk_blendmode_t mode);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
