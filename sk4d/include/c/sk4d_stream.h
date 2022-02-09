/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_stream_DEFINED
#define sk4d_stream_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_streamadapter_t* sk4d_streamadapter_create(void* context);
SK4D_API void sk4d_streamadapter_destroy(sk_streamadapter_t* self);
SK4D_API void sk4d_streamadapter_set_procs(const sk_streamadapter_procs_t* procs);
SK4D_API sk_wstreamadapter_t* sk4d_wstreamadapter_create(void* context);
SK4D_API void sk4d_wstreamadapter_destroy(sk_wstreamadapter_t* self);
SK4D_API void sk4d_wstreamadapter_set_procs(const sk_wstreamadapter_procs_t* procs);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
