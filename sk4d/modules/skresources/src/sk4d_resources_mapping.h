/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_resources_mapping_DEFINED
#define sk4d_resources_mapping_DEFINED

#include "src/c/sk4d_mapping.h"
#include "modules/skresources/include/sk4d_resources_types.h"
#include "modules/skresources/include/Sk4DResources.h"
#include "modules/skresources/include/SkResources.h"

SK4D_DEF_CLASS_MAP(skresources::ResourceProvider, sk_resourceprovider_t, ResourceProvider)
SK4D_DEF_CLASS_MAP(SkResourceProviderBaseClass, sk_resourceproviderbaseclass_t, ResourceProviderBaseClass)
SK4D_DEF_CLASS_MAP(SkResourceProviderBaseClass::Procs, sk_resourceproviderbaseclass_procs_t, ResourceProviderBaseClassProcs)

#endif
