/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <type_traits>

#include "include/core/SkRefCnt.h"
#include "modules/particles/include/sk4d_particles_types.h"
#include "modules/particles/include/SkParticleEffect.h"


/*
 * ASSERTIONS OF STRUCTURES
 *
 *  Custom mappings:
 *   - ParticleUniform
 *
 */



/*
 * ASSERTIONS OF REFERENCED OBJECTS
 */

static_assert(std::is_base_of<SkRefCnt, SkParticleEffect>::value, "");
