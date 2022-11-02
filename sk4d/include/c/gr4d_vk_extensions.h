/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef gr4d_vk_extensions_DEFINED
#define gr4d_vk_extensions_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API gr_vk_extensions_t* gr4d_vk_extensions_create(void);
SK4D_API void gr4d_vk_extensions_destroy(gr_vk_extensions_t* self);
SK4D_API bool gr4d_vk_extensions_has_extension(const gr_vk_extensions_t* self, const char name[], uint32_t min_version);
SK4D_API void gr4d_vk_extensions_init(gr_vk_extensions_t* self, void* context, gr_vk_get_proc proc, gr_vk_instance_t instance, gr_vk_physicaldevice_t physical_device, const char* instance_extensions[], int32_t instance_extension_count, const char* device_extensions[], int32_t device_extension_count);

SK4D_C_PLUS_PLUS_END_GUARD

#endif