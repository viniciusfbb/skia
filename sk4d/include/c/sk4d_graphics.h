/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_graphics_DEFINED
#define sk4d_graphics_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API void sk4d_graphics_allow_jit(void);
SK4D_API void sk4d_graphics_dump_memory_statistics(sk_tracememorydump_t* trace_memory_dump);
SK4D_API int32_t sk4d_graphics_get_font_cache_count_limit(void);
SK4D_API int32_t sk4d_graphics_get_font_cache_count_used(void);
SK4D_API size_t sk4d_graphics_get_font_cache_limit(void);
SK4D_API size_t sk4d_graphics_get_font_cache_used(void);
SK4D_API size_t sk4d_graphics_get_resource_cache_single_allocation_byte_limit(void);
SK4D_API size_t sk4d_graphics_get_resource_cache_total_byte_limit(void);
SK4D_API size_t sk4d_graphics_get_resource_cache_total_bytes_used(void);
SK4D_API void sk4d_graphics_init(void);
SK4D_API void sk4d_graphics_purge_all_caches(void);
SK4D_API void sk4d_graphics_purge_font_cache(void);
SK4D_API void sk4d_graphics_purge_resource_cache(void);
SK4D_API int32_t sk4d_graphics_set_font_cache_count_limit(int32_t value);
SK4D_API size_t sk4d_graphics_set_font_cache_limit(size_t value);
SK4D_API size_t sk4d_graphics_set_resource_cache_single_allocation_byte_limit(size_t value);
SK4D_API size_t sk4d_graphics_set_resource_cache_total_byte_limit(size_t value);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
