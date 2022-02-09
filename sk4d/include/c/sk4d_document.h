/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_document_DEFINED
#define sk4d_document_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API sk_canvas_t* sk4d_document_begin_page(sk_document_t* self, float width, float height, const sk_rect_t* content);
SK4D_API void sk4d_document_close(sk_document_t* self);
SK4D_API void sk4d_document_end_page(sk_document_t* self);
SK4D_API sk_document_t* sk4d_document_make_pdf(sk_wstream_t* w_stream);
SK4D_API sk_document_t* sk4d_document_make_pdf2(sk_wstream_t* w_stream, const sk_pdfmetadata_t* metadata);
SK4D_API sk_document_t* sk4d_document_make_xps(sk_wstream_t* w_stream, float dpi);
SK4D_API void sk4d_document_terminate(sk_document_t* self);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
