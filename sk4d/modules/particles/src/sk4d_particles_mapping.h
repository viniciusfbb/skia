/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_particles_mapping_DEFINED
#define sk4d_particles_mapping_DEFINED

#include "src/c/sk4d_mapping.h"
#include "src/sksl/codegen/SkSLVMCodeGenerator.h"
#include "modules/particles/include/sk4d_particles_types.h"
#include "modules/particles/include/SkParticleEffect.h"
#include "modules/particles/include/SkParticleSerialization.h"

SK4D_DEF_CLASS_MAP(SkParticleEffect, sk_particleeffect_t, ParticleEffect)


/*
 * CUSTOM MAPPING
 */

static inline sk_particleuniform_t ToParticleUniform(const SkSL::UniformInfo::Uniform& uniform) {
    return {
        uniform.fColumns,
        uniform.fRows,
        uniform.fSlot,
    };
}

#endif
