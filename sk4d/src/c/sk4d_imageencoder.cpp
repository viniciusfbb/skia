/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_imageencoder.h"
#include "src/c/sk4d_mapping.h"

bool sk4d_imageencoder_encode_to_file(const char file_name[], const sk_pixmap_t* src, sk_encodedimageformat_t format, int32_t quality) {
    SkFILEWStream file(file_name);
    return SkEncodeImage(&file, AsPixmap(*src), AsEncodedImageFormat(format), quality);
}

bool sk4d_imageencoder_encode_to_stream(sk_wstream_t* w_stream, const sk_pixmap_t* src, sk_encodedimageformat_t format, int32_t quality) {
    return SkEncodeImage(AsWStream(w_stream), AsPixmap(*src), AsEncodedImageFormat(format), quality);
}
