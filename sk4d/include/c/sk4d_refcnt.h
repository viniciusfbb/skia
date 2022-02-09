/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_refcnt_h
#define sk4d_refcnt_h

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API void sk4d_refcnt_ref(const sk_refcnt_t* self);
SK4D_API void sk4d_refcnt_unref(const sk_refcnt_t* self);

#ifdef __cplusplus
}
#endif

#endif
