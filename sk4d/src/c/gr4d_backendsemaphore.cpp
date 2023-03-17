/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/gr4d_backendsemaphore.h"
#include "src/c/sk4d_mapping.h"

gr_backendsemaphore_t* gr4d_backendsemaphore_create(void) {
    return SK4D_ONLY_GPU(ToGrBackendSemaphore(new GrBackendSemaphore()), nullptr);
}

void gr4d_backendsemaphore_destroy(gr_backendsemaphore_t* self) {
    SK4D_ONLY_GPU(delete AsGrBackendSemaphore(self);)
}

void gr4d_backendsemaphore_init_vulkan(gr_backendsemaphore_t* self, gr_vk_semaphore_t semaphore) {
    SK4D_ONLY_VULKAN(AsGrBackendSemaphore(self)->initVulkan(AsVkSemaphore(semaphore));)
}