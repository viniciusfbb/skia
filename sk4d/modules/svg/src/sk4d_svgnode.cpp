/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "modules/svg/include/sk4d_svgnode.h"
#include "modules/svg/src/sk4d_svg_mapping.h"

bool sk4d_svgnode_set_attribute(sk_svgnode_t* self, const char name[], const char value[]) {
    return AsSVGNode(self)->setAttribute(name, value);
}
