/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_particles_types_DEFINED
#define sk4d_particles_types_DEFINED

#include "include/c/sk4d_types.h"
#include "modules/skresources/include/sk4d_resources_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

typedef struct sk_particleeffect_t sk_particleeffect_t;

typedef struct {
    int32_t columns;
    int32_t rows;
    int32_t slot;
} sk_particleuniform_t;

SK4D_C_PLUS_PLUS_END_GUARD

#endif
