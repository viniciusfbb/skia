/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef gr4d_shadererrorhandler_DEFINED
#define gr4d_shadererrorhandler_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API gr_shadererrorhandlerbaseclass_t* gr4d_shadererrorhandlerbaseclass_create(void* context);
SK4D_API void gr4d_shadererrorhandlerbaseclass_destroy(gr_shadererrorhandlerbaseclass_t* self);
SK4D_API void gr4d_shadererrorhandlerbaseclass_set_procs(const gr_shadererrorhandlerbaseclass_procs_t* procs);

SK4D_C_PLUS_PLUS_END_GUARD

#endif