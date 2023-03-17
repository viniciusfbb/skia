/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/gr4d_backendsurfacemutablestate.h"
#include "src/c/sk4d_mapping.h"

gr_backendsurfacemutablestate_t* gr4d_backendsurfacemutablestate_create(gr_vk_imagelayout_t image_layout, uint32_t queue_family_index) {
    return SK4D_ONLY_VULKAN(ToGrBackendSurfaceMutableState(new GrBackendSurfaceMutableState(AsVkImageLayout(image_layout), queue_family_index)), nullptr);
}

void gr4d_backendsurfacemutablestate_destroy(gr_backendsurfacemutablestate_t* self) {
    SK4D_ONLY_VULKAN(delete AsGrBackendSurfaceMutableState(self);)
}
