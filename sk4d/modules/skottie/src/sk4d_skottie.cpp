/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <utility>

#include "src/utils/SkOSPath.h"
#include "modules/skottie/include/sk4d_skottie.h"
#include "modules/skottie/src/sk4d_skottie_mapping.h"
#include "modules/skresources/src/sk4d_resources_mapping.h"

double sk4d_skottieanimation_get_duration(const sk_skottieanimation_t* self) {
    return AsSkottieAnimation(self)->duration();
}

double sk4d_skottieanimation_get_fps(const sk_skottieanimation_t* self) {
    return AsSkottieAnimation(self)->fps();
}

double sk4d_skottieanimation_get_in_point(const sk_skottieanimation_t* self) {
    return AsSkottieAnimation(self)->inPoint();
}

double sk4d_skottieanimation_get_out_point(const sk_skottieanimation_t* self) {
    return AsSkottieAnimation(self)->outPoint();
}

void sk4d_skottieanimation_get_size(const sk_skottieanimation_t* self, sk_size_t* result) {
    *result = ToSize(AsSkottieAnimation(self)->size());
}

const char* sk4d_skottieanimation_get_version(const sk_skottieanimation_t* self) {
    return AsSkottieAnimation(self)->version().c_str();
}

sk_skottieanimation_t* sk4d_skottieanimation_make_from_file(const char file_name[]) {
    auto stream = SkStream::MakeFromFile(file_name);
    if (!stream)
        return nullptr;
    auto rp = skresources::DataURIResourceProviderProxy::Make(skresources::FileResourceProvider::Make(SkOSPath::Dirname(file_name), true), true);
    return ToSkottieAnimation(skottie::Animation::Builder().setResourceProvider(std::move(rp)).make(stream.get()).release());
}

sk_skottieanimation_t* sk4d_skottieanimation_make_from_stream(sk_stream_t* stream, sk_resourceprovider_t* resource_provider) {
    auto rp = skresources::DataURIResourceProviderProxy::Make(sk_ref_sp(AsResourceProvider(resource_provider)), true);
    return ToSkottieAnimation(skottie::Animation::Builder().setResourceProvider(std::move(rp)).make(AsStream(stream)).release());
}

void sk4d_skottieanimation_ref(const sk_skottieanimation_t* self) {
    AsSkottieAnimation(self)->ref();
}

void sk4d_skottieanimation_render(const sk_skottieanimation_t* self, sk_canvas_t* canvas, const sk_rect_t* dest, uint32_t render_flags) {
    AsSkottieAnimation(self)->render(AsCanvas(canvas), AsRect(dest), render_flags);
}

void sk4d_skottieanimation_seek_frame(sk_skottieanimation_t* self, double tick) {
    AsSkottieAnimation(self)->seekFrame(tick);
}

void sk4d_skottieanimation_seek_frame_time(sk_skottieanimation_t* self, double tick) {
    AsSkottieAnimation(self)->seekFrameTime(tick);
}

void sk4d_skottieanimation_unref(const sk_skottieanimation_t* self) {
    AsSkottieAnimation(self)->unref();
}
