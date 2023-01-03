/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/gpu/Gr4DContextOptions.h"

GrPersistentCacheBaseClass::Procs GrPersistentCacheBaseClass::fProcs;

GrPersistentCacheBaseClass::GrPersistentCacheBaseClass(void* context) : fContext(context) {
}

GrPersistentCacheBaseClass::~GrPersistentCacheBaseClass() {
}

sk_sp<SkData> GrPersistentCacheBaseClass::load(const SkData& key) {
    return sk_sp<SkData>(fProcs.fLoad(fContext, key.data(), key.size()));
}

void GrPersistentCacheBaseClass::setProcs(const Procs& procs) {
    fProcs = procs;
}

void GrPersistentCacheBaseClass::store(const SkData& key, const SkData& data) {
    fProcs.fStore(fContext, key.data(), key.size(), data.data(), data.size());
}
