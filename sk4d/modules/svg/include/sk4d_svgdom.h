/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_svgdom_DEFINED
#define sk4d_svgdom_DEFINED

#include "modules/svg/include/sk4d_svg_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_svgnode_t* sk4d_svgdom_find_node_by_id(sk_svgdom_t* self, const char id[]);
SK4D_API sk_svgsvg_t* sk4d_svgdom_get_root(const sk_svgdom_t* self);
SK4D_API sk_svgdom_t* sk4d_svgdom_make_from_file(const char file_name[]);
SK4D_API sk_svgdom_t* sk4d_svgdom_make_from_stream(sk_stream_t* stream, sk_resourceprovider_t* resource_provider);
SK4D_API void sk4d_svgdom_render(const sk_svgdom_t* self, sk_canvas_t* canvas);
SK4D_API void sk4d_svgdom_set_container_size(sk_svgdom_t* self, const sk_size_t* size);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
