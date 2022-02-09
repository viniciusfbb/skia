/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef Sk4DResources_DEFINED
#define Sk4DResources_DEFINED

#include "modules/skresources/include/SkResources.h"

class SkResourceProviderBaseClass final : public skresources::ResourceProvider {
public:
    struct Procs {
        SkData* (*fLoad) (void* context, const char path[], const char name[]);
    };

    static void setProcs(const Procs& procs);

public:
    SkResourceProviderBaseClass(bool predecode, void* context);

    sk_sp<SkData> load(const char path[], const char name[]) const override;
    sk_sp<skresources::ImageAsset> loadImageAsset(const char path[], const char name[], const char id[]) const override;

private:
    void*        fContext;
    const bool   fPredecode;
    static Procs fProcs;

    using INHERITED = skresources::ResourceProvider;
};

#endif