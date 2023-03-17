/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef gr4d_backendsurfacemutablestate_DEFINED
#define gr4d_backendsurfacemutablestate_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API gr_backendsurfacemutablestate_t* gr4d_backendsurfacemutablestate_create(gr_vk_imagelayout_t image_layout, uint32_t queue_family_index);
SK4D_API void gr4d_backendsurfacemutablestate_destroy(gr_backendsurfacemutablestate_t* self);

SK4D_C_PLUS_PLUS_END_GUARD

#endif