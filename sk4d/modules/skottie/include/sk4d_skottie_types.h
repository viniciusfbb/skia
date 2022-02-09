/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_skottie_types_DEFINED
#define sk4d_skottie_types_DEFINED

#include "include/c/sk4d_types.h"
#include "modules/skresources/include/sk4d_resources_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

typedef struct sk_skottieanimation_t sk_skottieanimation_t;

#define SK_SKIP_TOP_LEVEL_ISOLATION_SK_SKOTTIE_ANIMATION_RENDER_FLAG   (1 << 0)
#define SK_DISABLE_TOP_LEVEL_CLIPPING_SK_SKOTTIE_ANIMATION_RENDER_FLAG (1 << 1)

SK4D_C_PLUS_PLUS_END_GUARD

#endif
