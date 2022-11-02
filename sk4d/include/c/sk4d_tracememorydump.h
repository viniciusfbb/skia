/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_tracememorydump_DEFINED
#define sk4d_tracememorydump_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_tracememorydumpbaseclass_t* sk4d_tracememorydumpbaseclass_create(bool detailed_dump, bool dump_wrapped_objects, void* context);
SK4D_API void sk4d_tracememorydumpbaseclass_destroy(sk_tracememorydumpbaseclass_t* self);
SK4D_API void sk4d_tracememorydumpbaseclass_set_procs(const sk_tracememorydumpbaseclass_procs_t* procs);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
