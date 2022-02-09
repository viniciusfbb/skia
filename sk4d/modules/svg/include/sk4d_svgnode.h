/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_svgnode_DEFINED
#define sk4d_svgnode_DEFINED

#include "modules/svg/include/sk4d_svg_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API bool sk4d_svgnode_set_attribute(sk_svgnode_t* self, const char name[], const char value[]);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
