/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_resources_DEFINED
#define sk4d_resources_DEFINED

#include "modules/skresources/include/sk4d_resources_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_resourceproviderbaseclass_t* sk4d_resourceproviderbaseclass_create(bool predecode, void* context);
SK4D_API void sk4d_resourceproviderbaseclass_set_procs(const sk_resourceproviderbaseclass_procs_t* procs);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
