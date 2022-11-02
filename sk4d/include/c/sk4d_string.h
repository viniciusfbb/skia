/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_string_DEFINED
#define sk4d_string_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_string_t* sk4d_string_create(void);
SK4D_API void sk4d_string_destroy(sk_string_t* self);
SK4D_API const char* sk4d_string_get_text(const sk_string_t* self);
SK4D_API void sk4d_string_set_text(sk_string_t* self, const char value[]);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
