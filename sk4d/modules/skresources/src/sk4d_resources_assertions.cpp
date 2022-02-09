/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <type_traits>

#include "include/core/SkRefCnt.h"
#include "modules/skresources/include/sk4d_resources_types.h"
#include "modules/skresources/include/Sk4DResources.h"


/*
 * ASSERTIONS OF STRUCTURES
 */

static_assert(sizeof(SkResourceProviderBaseClass::Procs) == sizeof(sk_resourceproviderbaseclass_procs_t), "");


/*
 * ASSERTIONS OF REFERENCED OBJECTS
 */

static_assert(std::is_base_of<SkRefCnt, SkResourceProviderBaseClass>::value, "");