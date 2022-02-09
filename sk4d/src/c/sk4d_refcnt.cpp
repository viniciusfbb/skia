/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_refcnt.h"
#include "src/c/sk4d_mapping.h"

void sk4d_refcnt_ref(const sk_refcnt_t* self) {
    AsRefCnt(self)->ref();
}

void sk4d_refcnt_unref(const sk_refcnt_t* self) {
    AsRefCnt(self)->unref();
}
