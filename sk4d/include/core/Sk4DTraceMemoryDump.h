/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef Sk4DTraceMemoryDump_DEFINED
#define Sk4DTraceMemoryDump_DEFINED

#include "include/core/SkTraceMemoryDump.h"

class SkTraceMemoryDumpBaseClass final : public SkTraceMemoryDump {
public:
    struct Procs {
        void (*fDumpNumericValue) (void* context, const char* dumpName, const char* valueName, const char* units, uint64_t value);
        void (*fDumpStringValue)  (void* context, const char* dumpName, const char* valueName, const char* value);
    };

    static void setProcs(const Procs& procs);

public:
    SkTraceMemoryDumpBaseClass(SkTraceMemoryDump::LevelOfDetail levelOfDetail, bool shouldDumpWrappedObjects, void* context);
    ~SkTraceMemoryDumpBaseClass() override;

    void dumpNumericValue(const char* dumpName, const char* valueName, const char* units, uint64_t value) override;
    void dumpStringValue(const char* dumpName, const char* valueName, const char* value) override;
    SkTraceMemoryDump::LevelOfDetail getRequestedDetails() const override;
    void setDiscardableMemoryBacking(const char* dumpName, const SkDiscardableMemory& discardableMemoryObject) override;
    void setMemoryBacking(const char* dumpName, const char* backingType, const char* backingObjectId) override;
    bool shouldDumpWrappedObjects() const override;

private:
    void*                                  fContext;
    const SkTraceMemoryDump::LevelOfDetail fLevelOfDetail;
    const bool                             fShouldDumpWrappedObjects;
    static Procs                           fProcs;

    using INHERITED = SkTraceMemoryDump;
};

#endif
