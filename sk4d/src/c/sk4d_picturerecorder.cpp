/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_picturerecorder.h"
#include "src/c/sk4d_mapping.h"

sk_canvas_t* sk4d_picturerecorder_begin_recording(sk_picturerecorder_t* self, const sk_rect_t* bounds) {
    return ToCanvas(AsPictureRecorder(self)->beginRecording(AsRect(*bounds)));
}

sk_picturerecorder_t* sk4d_picturerecorder_create(void) {
    return ToPictureRecorder(new SkPictureRecorder);
}

void sk4d_picturerecorder_destroy(sk_picturerecorder_t* self) {
    delete AsPictureRecorder(self);
}

sk_picture_t* sk4d_picturerecorder_finish_recording(sk_picturerecorder_t* self) {
    return ToPicture(AsPictureRecorder(self)->finishRecordingAsPicture().release());
}

sk_picture_t* sk4d_picturerecorder_finish_recording2(sk_picturerecorder_t* self, const sk_rect_t* cull_rect) {
    return ToPicture(AsPictureRecorder(self)->finishRecordingAsPictureWithCull(AsRect(*cull_rect)).release());
}
