/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef Gr4DContextOptions_DEFINED
#define Gr4DContextOptions_DEFINED

#include "include/gpu/GrContextOptions.h"

class GrPersistentCacheBaseClass final : public GrContextOptions::PersistentCache {
public:
    struct Procs {
        SkData* (*fLoad)  (void* context, const void* keyData, size_t keySize);
        void    (*fStore) (void* context, const void* keyData, size_t keySize, const void* data, size_t size);
    };

    static void setProcs(const Procs& procs);

public:
    GrPersistentCacheBaseClass(void* context);
    ~GrPersistentCacheBaseClass() override;

    sk_sp<SkData> load(const SkData& key) override;
    void store(const SkData& key, const SkData& data) override;


private:
    void*        fContext;
    static Procs fProcs;

    using INHERITED = GrContextOptions::PersistentCache;
};

#endif