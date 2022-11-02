/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <utility>

#include "src/utils/SkOSPath.h"
#include "modules/svg/include/sk4d_svgdom.h"
#include "modules/skresources/src/sk4d_resources_mapping.h"
#include "modules/svg/src/sk4d_svg_mapping.h"

sk_svgnode_t* sk4d_svgdom_find_node_by_id(sk_svgdom_t* self, const char id[]) {
    const auto ref = AsSVGDOM(self)->findNodeById(id);
    return (ref) ? ToSVGNode(ref->get()) : nullptr;
}

sk_svgsvg_t* sk4d_svgdom_get_root(const sk_svgdom_t* self) {
    return ToSVGSVG(AsSVGDOM(self)->getRoot());
}

sk_svgdom_t* sk4d_svgdom_make_from_file(const char file_name[]) {
    auto stream = SkStream::MakeFromFile(file_name);
    if (!stream)
        return nullptr;
    auto rp = skresources::DataURIResourceProviderProxy::Make(skresources::FileResourceProvider::Make(SkOSPath::Dirname(file_name), true), true);
    return ToSVGDOM(SkSVGDOM::Builder().setResourceProvider(std::move(rp)).make(*stream).release());
}

sk_svgdom_t* sk4d_svgdom_make_from_stream(sk_stream_t* stream, sk_resourceprovider_t* resource_provider) {
    auto rp = skresources::DataURIResourceProviderProxy::Make(sk_ref_sp(AsResourceProvider(resource_provider)), true);
    return ToSVGDOM(SkSVGDOM::Builder().setResourceProvider(std::move(rp)).make(AsStream(*stream)).release());
}

void sk4d_svgdom_render(const sk_svgdom_t* self, sk_canvas_t* canvas) {
    AsSVGDOM(self)->render(AsCanvas(canvas));
}

void sk4d_svgdom_set_container_size(sk_svgdom_t* self, const sk_size_t* size) {
    AsSVGDOM(self)->setContainerSize(AsSize(*size));
}
