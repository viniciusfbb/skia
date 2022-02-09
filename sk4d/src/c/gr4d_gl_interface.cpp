/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/gr4d_gl_interface.h"
#include "src/c/sk4d_mapping.h"

bool gr4d_gl_interface_has_extension(const gr_gl_interface_t* self, const char name[]) {
    return SK4D_ONLY_GL(AsGrGLInterface(self)->hasExtension(name), false);
}

const gr_gl_interface_t* gr4d_gl_interface_make_assembled(void* context, gr_gl_get_proc proc) {
    return SK4D_ONLY_GL(ToGrGLInterface(GrGLMakeAssembledInterface(context, AsGrGLGetProc(proc)).release()), nullptr);
}

const gr_gl_interface_t* gr4d_gl_interface_make_assembled_gl(void* context, gr_gl_get_proc proc) {
    return SK4D_ONLY_GL(ToGrGLInterface(GrGLMakeAssembledGLInterface(context, AsGrGLGetProc(proc)).release()), nullptr);
}

const gr_gl_interface_t* gr4d_gl_interface_make_assembled_gles(void* context, gr_gl_get_proc proc) {
    return SK4D_ONLY_GL(ToGrGLInterface(GrGLMakeAssembledGLESInterface(context, AsGrGLGetProc(proc)).release()), nullptr);
}

const gr_gl_interface_t* gr4d_gl_interface_make_assembled_webgl(void* context, gr_gl_get_proc proc) {
    return SK4D_ONLY_GL(ToGrGLInterface(GrGLMakeAssembledWebGLInterface(context, AsGrGLGetProc(proc)).release()), nullptr);
}

const gr_gl_interface_t* gr4d_gl_interface_make_native(void) {
    return SK4D_ONLY_GL(ToGrGLInterface(GrGLMakeNativeInterface().release()), nullptr);
}

bool gr4d_gl_interface_validate(const gr_gl_interface_t* self) {
    return SK4D_ONLY_GL(AsGrGLInterface(self)->validate(), false);
}
