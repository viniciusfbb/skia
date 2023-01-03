/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/gr4d_contextoptions.h"
#include "src/c/sk4d_mapping.h"

gr_persistentcachebaseclass_t* gr4d_persistentcachebaseclass_create(void* context) {
    return SK4D_ONLY_GPU(ToGrPersistentCacheBaseClass(new GrPersistentCacheBaseClass(context)), nullptr);
}

void gr4d_persistentcachebaseclass_destroy(gr_persistentcachebaseclass_t* self) {
    SK4D_ONLY_GPU(delete AsGrPersistentCacheBaseClass(self);)
}

void gr4d_persistentcachebaseclass_set_procs(const gr_persistentcachebaseclass_procs_t* procs) {
    SK4D_ONLY_GPU(GrPersistentCacheBaseClass::setProcs(AsGrPersistentCacheBaseClassProcs(*procs));)
}
