/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef Gr4DShaderErrorHandler_DEFINED
#define Gr4DShaderErrorHandler_DEFINED

#include "include/gpu/ShaderErrorHandler.h"

class GrShaderErrorHandlerBaseClass final : public skgpu::ShaderErrorHandler {
public:
    struct Procs {
        void (*fCompileError) (void* context, const char* shader, const char* errors);
    };

    static void setProcs(const Procs& procs);

public:
    GrShaderErrorHandlerBaseClass(void* context);
    ~GrShaderErrorHandlerBaseClass() override;

    void compileError(const char* shader, const char* errors) override;

private:
    void*        fContext;
    static Procs fProcs;

    using INHERITED = skgpu::ShaderErrorHandler;
};

#endif