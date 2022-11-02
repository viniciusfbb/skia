/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <utility>

#include "modules/skresources/include/Sk4DResources.h"

SkResourceProviderBaseClass::Procs SkResourceProviderBaseClass::fProcs;

SkResourceProviderBaseClass::SkResourceProviderBaseClass(bool predecode, void* context)
    : fContext(context)
    , fPredecode(predecode)
{
}

sk_sp<SkData> SkResourceProviderBaseClass::load(const char path[], const char name[]) const {
    return sk_sp<SkData>(fProcs.fLoad(fContext, path, name));
}

sk_sp<skresources::ImageAsset> SkResourceProviderBaseClass::loadImageAsset(const char path[], const char name[], const char id[]) const {
    auto data = this->load(path, name);

    if (auto image = skresources::MultiFrameImageAsset::Make(data, fPredecode))
        return std::move(image);

#if defined(HAVE_VIDEO_DECODER)
    if (auto video = skresources::VideoAsset::Make(data))
        return std::move(video);
#endif

    return nullptr;
}

void SkResourceProviderBaseClass::setProcs(const Procs& procs) {
    fProcs = procs;
}
