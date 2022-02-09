/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * 
 */

#ifdef SK_SUPPORT_XPS
    #include <cstdlib>
    #include <mutex>
    #include <XpsObjectModel.h>
#endif

#include "include/c/sk4d_document.h"
#include "src/c/sk4d_mapping.h"

#ifdef SK_SUPPORT_XPS
    static IXpsOMObjectFactory* g_xps_factory = nullptr;

    static void destroy_xps_factory(void) {
        if (g_xps_factory)
            g_xps_factory->Release();
    }

    static void create_xps_factory(IXpsOMObjectFactory** factory) {
        if (SUCCEEDED(CoCreateInstance(CLSID_XpsOMObjectFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(factory))))
            atexit(destroy_xps_factory);
    }

    static IXpsOMObjectFactory* get_xps_factory(void) {
        static std::once_flag flag;
        std::call_once(flag, create_xps_factory, &g_xps_factory);
        return g_xps_factory;
    }
#endif

sk_canvas_t* sk4d_document_begin_page(sk_document_t* self, float width, float height, const sk_rect_t* content) {
    return ToCanvas(AsDocument(self)->beginPage(width, height, AsRect(content)));
}

void sk4d_document_close(sk_document_t* self) {
    AsDocument(self)->close();
}

void sk4d_document_end_page(sk_document_t* self) {
    AsDocument(self)->endPage();
}

sk_document_t* sk4d_document_make_pdf(sk_wstream_t* w_stream) {
    return ToDocument(SkPDF::MakeDocument(AsWStream(w_stream)).release());
}

sk_document_t* sk4d_document_make_pdf2(sk_wstream_t* w_stream, const sk_pdfmetadata_t* metadata) {
    return ToDocument(SkPDF::MakeDocument(AsWStream(w_stream), AsPDFMetadata(metadata)).release());
}

sk_document_t* sk4d_document_make_xps(sk_wstream_t* w_stream, float dpi) {
    SK4D_ONLY_XPS(
        IXpsOMObjectFactory* factory = get_xps_factory();
        if (!factory)
            return nullptr;)
    return SK4D_ONLY_XPS(ToDocument(SkXPS::MakeDocument(AsWStream(w_stream), factory, dpi).release()), nullptr);
}

void sk4d_document_terminate(sk_document_t* self) {
    AsDocument(self)->abort();
}
