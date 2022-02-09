/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_stream.h"
#include "src/c/sk4d_mapping.h"

sk_streamadapter_t* sk4d_streamadapter_create(void* context) {
    return ToStreamAdapter(new SkStreamAdapter(context));
}

void sk4d_streamadapter_destroy(sk_streamadapter_t* self) {
    delete AsStreamAdapter(self);
}

void sk4d_streamadapter_set_procs(const sk_streamadapter_procs_t* procs) {
    SkStreamAdapter::setProcs(AsStreamAdapterProcs(*procs));
}

sk_wstreamadapter_t* sk4d_wstreamadapter_create(void* context) {
    return ToWStreamAdapter(new SkWStreamAdapter(context));
}

void sk4d_wstreamadapter_destroy(sk_wstreamadapter_t* self) {
    delete AsWStreamAdapter(self);
}

void sk4d_wstreamadapter_set_procs(const sk_wstreamadapter_procs_t* procs) {
    SkWStreamAdapter::setProcs(AsWStreamAdapterProcs(*procs));
}
