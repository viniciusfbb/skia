/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <utility>

#include "include/c/sk4d_codec.h"
#include "src/c/sk4d_mapping.h"

void sk4d_codec_destroy(sk_codec_t* codec) {
    delete AsCodec(codec);
}

void sk4d_codec_get_dimensions(const sk_codec_t* self, sk_isize_t* result) {
    *result = ToISize(AsCodec(self)->dimensions());
}

sk_image_t* sk4d_codec_get_image(sk_codec_t* self, sk_colortype_t color_type, sk_alphatype_t alpha_type, sk_colorspace_t* color_space) {
    auto [image, result] = AsCodec(self)->getImage(SkImageInfo::Make(AsCodec(self)->dimensions(), AsColorType(color_type), AsAlphaType(alpha_type), sk_ref_sp(AsColorSpace(color_space))));
    return (result == SkCodec::kSuccess) ? ToImage(image.release()) : nullptr;
}

bool sk4d_codec_get_pixels(sk_codec_t* self, void* pixels, size_t row_bytes, sk_colortype_t color_type, sk_alphatype_t alpha_type, sk_colorspace_t* color_space) {
    return (AsCodec(self)->getPixels(SkImageInfo::Make(AsCodec(self)->dimensions(), AsColorType(color_type), AsAlphaType(alpha_type), sk_ref_sp(AsColorSpace(color_space))), pixels, row_bytes) == SkCodec::kSuccess);
}

sk_codec_t* sk4d_codec_make_from_file(const char file_name[]) {
    auto s = std::make_unique<SkFILEStream>(file_name);
    return ToCodec(SkCodec::MakeFromStream(std::move(s)).release());
}

sk_codec_t* sk4d_codec_make_with_copy(const void* data, size_t size) {
    return ToCodec(SkCodec::MakeFromData(SkData::MakeWithCopy(data, size)).release());
}

sk_codec_t* sk4d_codec_make_without_copy(const void* data, size_t size) {
    return ToCodec(SkCodec::MakeFromData(SkData::MakeWithoutCopy(data, size)).release());
}

void sk4d_animcodecplayer_destroy(sk_animcodecplayer_t* self) {
    delete AsAnimCodecPlayer(self);
}

void sk4d_animcodecplayer_get_dimensions(const sk_animcodecplayer_t* self, sk_isize_t* result) {
    *result = ToISize(AsAnimCodecPlayer(self)->dimensions());
}

uint32_t sk4d_animcodecplayer_get_duration(const sk_animcodecplayer_t* self) {
    return AsAnimCodecPlayer(self)->duration();
}

sk_image_t* sk4d_animcodecplayer_get_frame(sk_animcodecplayer_t* self) {
    return ToImage(AsAnimCodecPlayer(self)->getFrame().release());
}

sk_animcodecplayer_t* sk4d_animcodecplayer_make_from_file(const char file_name[]) {
    auto s = std::make_unique<SkFILEStream>(file_name);
    if (auto codec = SkCodec::MakeFromStream(std::move(s))) {
        return ToAnimCodecPlayer(new SkAnimCodecPlayer(std::move(codec)));
    }
    return nullptr;
}

sk_animcodecplayer_t* sk4d_animcodecplayer_make_from_stream(sk_stream_t* stream) {
    std::unique_ptr<SkStream> s(AsStream(stream));
    if (auto codec = SkCodec::MakeFromStream(std::move(s))) {
        return ToAnimCodecPlayer(new SkAnimCodecPlayer(std::move(codec)));
    }
    return nullptr;
}

bool sk4d_animcodecplayer_seek(sk_animcodecplayer_t* self, uint32_t milliseconds) {
    return AsAnimCodecPlayer(self)->seek(milliseconds);
}
