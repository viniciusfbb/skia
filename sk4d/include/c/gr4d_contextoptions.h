/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef gr4d_contextoptions_DEFINED
#define gr4d_contextoptions_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API gr_persistentcachebaseclass_t* gr4d_persistentcachebaseclass_create(void* context);
SK4D_API void gr4d_persistentcachebaseclass_destroy(gr_persistentcachebaseclass_t* self);
SK4D_API void gr4d_persistentcachebaseclass_set_procs(const gr_persistentcachebaseclass_procs_t* procs);

SK4D_C_PLUS_PLUS_END_GUARD

#endif