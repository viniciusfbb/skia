/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/gr4d_shadererrorhandler.h"
#include "src/c/sk4d_mapping.h"

gr_shadererrorhandlerbaseclass_t* gr4d_shadererrorhandlerbaseclass_create(void* context) {
    return SK4D_ONLY_GPU(ToGrShaderErrorHandlerBaseClass(new GrShaderErrorHandlerBaseClass(context)), nullptr);
}

void gr4d_shadererrorhandlerbaseclass_destroy(gr_shadererrorhandlerbaseclass_t* self) {
    return SK4D_ONLY_GPU(delete AsGrShaderErrorHandlerBaseClass(self);)
}

void gr4d_shadererrorhandlerbaseclass_set_procs(const gr_shadererrorhandlerbaseclass_procs_t* procs) {
    SK4D_ONLY_GPU(GrShaderErrorHandlerBaseClass::setProcs(AsGrShaderErrorHandlerBaseClassProcs(*procs));)
}
