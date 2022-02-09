/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef gr4d_gl_interface_DEFINED
#define gr4d_gl_interface_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API bool gr4d_gl_interface_has_extension(const gr_gl_interface_t* self, const char name[]);
SK4D_API const gr_gl_interface_t* gr4d_gl_interface_make_assembled(void* context, gr_gl_get_proc proc);
SK4D_API const gr_gl_interface_t* gr4d_gl_interface_make_assembled_gl(void* context, gr_gl_get_proc proc);
SK4D_API const gr_gl_interface_t* gr4d_gl_interface_make_assembled_gles(void* context, gr_gl_get_proc proc);
SK4D_API const gr_gl_interface_t* gr4d_gl_interface_make_assembled_webgl(void* context, gr_gl_get_proc proc);
SK4D_API const gr_gl_interface_t* gr4d_gl_interface_make_native(void);
SK4D_API bool gr4d_gl_interface_validate(const gr_gl_interface_t* self);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
