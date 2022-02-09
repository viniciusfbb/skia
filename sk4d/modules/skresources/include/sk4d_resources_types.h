/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_resources_types_DEFINED
#define sk4d_resources_types_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

typedef struct sk_resourceprovider_t          sk_resourceprovider_t;
typedef struct sk_resourceproviderbaseclass_t sk_resourceproviderbaseclass_t;

typedef struct {
    sk_data_t* (*load) (void* context, const char path[], const char name[]);
} sk_resourceproviderbaseclass_procs_t;

SK4D_C_PLUS_PLUS_END_GUARD

#endif
