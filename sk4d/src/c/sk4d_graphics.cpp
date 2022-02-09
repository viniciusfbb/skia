/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_graphics.h"
#include "src/c/sk4d_mapping.h"

void sk4d_graphics_allow_jit(void) {
    SkGraphics::AllowJIT();
}

void sk4d_graphics_dump_memory_statistics(sk_tracememorydump_t* trace_memory_dump) {
    SkGraphics::DumpMemoryStatistics(AsTraceMemoryDump(trace_memory_dump));
}

int32_t sk4d_graphics_get_font_cache_count_limit(void) {
    return SkGraphics::GetFontCacheCountLimit();
}

int32_t sk4d_graphics_get_font_cache_count_used(void) {
    return SkGraphics::GetFontCacheCountUsed();
}

size_t sk4d_graphics_get_font_cache_limit(void) {
    return SkGraphics::GetFontCacheLimit();
}

size_t sk4d_graphics_get_font_cache_used(void) {
    return SkGraphics::GetFontCacheUsed();
}

size_t sk4d_graphics_get_resource_cache_single_allocation_byte_limit(void) {
    return SkGraphics::GetResourceCacheSingleAllocationByteLimit();
}

size_t sk4d_graphics_get_resource_cache_total_byte_limit(void) {
    return SkGraphics::GetResourceCacheTotalByteLimit();
}

size_t sk4d_graphics_get_resource_cache_total_bytes_used(void) {
    return SkGraphics::GetResourceCacheTotalBytesUsed();
}

void sk4d_graphics_init(void) {
    SkGraphics::Init();
}

void sk4d_graphics_purge_all_caches(void) {
    SkGraphics::PurgeAllCaches();
}

void sk4d_graphics_purge_font_cache(void) {
    SkGraphics::PurgeFontCache();
}

void sk4d_graphics_purge_resource_cache(void) {
    SkGraphics::PurgeResourceCache();
}

int32_t sk4d_graphics_set_font_cache_count_limit(int32_t value) {
    return SkGraphics::SetFontCacheCountLimit(value);
}

size_t sk4d_graphics_set_font_cache_limit(size_t value) {
    return SkGraphics::SetFontCacheLimit(value);
}

size_t sk4d_graphics_set_resource_cache_single_allocation_byte_limit(size_t value) {
    return SkGraphics::SetResourceCacheSingleAllocationByteLimit(value);
}

size_t sk4d_graphics_set_resource_cache_total_byte_limit(size_t value) {
    return SkGraphics::SetResourceCacheTotalByteLimit(value);
}
