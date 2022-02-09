/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/Sk4DTraceMemoryDump.h"

SkTraceMemoryDumpBaseClass::Procs SkTraceMemoryDumpBaseClass::fProcs;

SkTraceMemoryDumpBaseClass::SkTraceMemoryDumpBaseClass(SkTraceMemoryDump::LevelOfDetail levelOfDetail, bool shouldDumpWrappedObjects, void* context)
    : fContext(context)
    , fLevelOfDetail(levelOfDetail)
    , fShouldDumpWrappedObjects(shouldDumpWrappedObjects)
{
}

SkTraceMemoryDumpBaseClass::~SkTraceMemoryDumpBaseClass() {
}

void SkTraceMemoryDumpBaseClass::dumpNumericValue(const char* dumpName, const char* valueName, const char* units, uint64_t value) {
    fProcs.fDumpNumericValue(fContext, dumpName, valueName, units, value);
}

void SkTraceMemoryDumpBaseClass::dumpStringValue(const char* dumpName, const char* valueName, const char* value) {
    fProcs.fDumpStringValue(fContext, dumpName, valueName, value);
}

SkTraceMemoryDump::LevelOfDetail SkTraceMemoryDumpBaseClass::getRequestedDetails() const {
    return fLevelOfDetail;
}

void SkTraceMemoryDumpBaseClass::setDiscardableMemoryBacking(const char* dumpName, const SkDiscardableMemory& discardableMemoryObject) {
}

void SkTraceMemoryDumpBaseClass::setMemoryBacking(const char* dumpName, const char* backingType, const char* backingObjectId) {
}

void SkTraceMemoryDumpBaseClass::setProcs(const Procs& procs) {
    fProcs = procs;
}

bool SkTraceMemoryDumpBaseClass::shouldDumpWrappedObjects() const {
    return fShouldDumpWrappedObjects;
}
