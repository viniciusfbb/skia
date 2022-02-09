/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_tracememorydump.h"
#include "src/c/sk4d_mapping.h"

sk_tracememorydumpbaseclass_t* sk4d_tracememorydumpbaseclass_create(bool detailed_dump, bool dump_wrapped_objects, void* context) {
    return ToTraceMemoryDumpBaseClass(new SkTraceMemoryDumpBaseClass(detailed_dump ? SkTraceMemoryDump::LevelOfDetail::kObjectsBreakdowns_LevelOfDetail : SkTraceMemoryDump::LevelOfDetail::kLight_LevelOfDetail, dump_wrapped_objects, context));
}

void sk4d_tracememorydumpbaseclass_destroy(sk_tracememorydumpbaseclass_t* self) {
    delete AsTraceMemoryDumpBaseClass(self);
}

void sk4d_tracememorydumpbaseclass_set_procs(const sk_tracememorydumpbaseclass_procs_t* procs) {
    SkTraceMemoryDumpBaseClass::setProcs(AsTraceMemoryDumpBaseClassProcs(*procs));
}
