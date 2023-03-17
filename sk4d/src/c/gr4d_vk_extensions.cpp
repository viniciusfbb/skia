/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/gr4d_vk_extensions.h"
#include "src/c/sk4d_mapping.h"

gr_vk_extensions_t* gr4d_vk_extensions_create(void) {
    return SK4D_ONLY_VULKAN(ToGrVkExtensions(new GrVkExtensions()), nullptr);
}

void gr4d_vk_extensions_destroy(gr_vk_extensions_t* self) {
    SK4D_ONLY_VULKAN(delete AsGrVkExtensions(self);)
}

bool gr4d_vk_extensions_has_extension(const gr_vk_extensions_t* self, const char name[], uint32_t min_api_version) {
    return SK4D_ONLY_VULKAN(AsGrVkExtensions(self)->hasExtension(name, min_api_version), false);
}

void gr4d_vk_extensions_init(gr_vk_extensions_t* self, void* context, gr_vk_get_proc proc, gr_vk_instance_t instance, gr_vk_physicaldevice_t physical_device, int32_t instance_extension_count, const char* instance_extensions[], int32_t device_extension_count, const char* device_extensions[]) {
    SK4D_ONLY_VULKAN(
        AsGrVkExtensions(self)->init(
            [context, proc](const char name[], VkInstance instance, VkDevice device) {
                return AsPFN_vkVoidFunction(proc(context, name, ToVkInstance(instance), ToVkDevice(device)));
            },
            AsVkInstance(instance), AsVkPhysicalDevice(physical_device), instance_extension_count, instance_extensions, device_extension_count, device_extensions);)
}
