/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "modules/skresources/include/sk4d_resources.h"
#include "modules/skresources/src/sk4d_resources_mapping.h"

sk_resourceproviderbaseclass_t* sk4d_resourceproviderbaseclass_create(bool predecode, void* context) {
    return ToResourceProviderBaseClass(new SkResourceProviderBaseClass(predecode, context));
}

void sk4d_resourceproviderbaseclass_set_procs(const sk_resourceproviderbaseclass_procs_t* procs) {
    SkResourceProviderBaseClass::setProcs(AsResourceProviderBaseClassProcs(*procs));
}

