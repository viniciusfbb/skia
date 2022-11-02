/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/gpu/Gr4DShaderErrorHandler.h"

GrShaderErrorHandlerBaseClass::Procs GrShaderErrorHandlerBaseClass::fProcs;

GrShaderErrorHandlerBaseClass::GrShaderErrorHandlerBaseClass(void* context) : fContext(context) {
}

GrShaderErrorHandlerBaseClass::~GrShaderErrorHandlerBaseClass() {
}

void GrShaderErrorHandlerBaseClass::compileError(const char* shader, const char* errors) {
    fProcs.fCompileError(fContext, shader, errors);
}

void GrShaderErrorHandlerBaseClass::setProcs(const Procs& procs) {
    fProcs = procs;
}
