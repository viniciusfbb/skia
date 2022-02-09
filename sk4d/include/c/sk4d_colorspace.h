/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_colorspace_DEFINED
#define sk4d_colorspace_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API bool sk4d_colorspace_gamma_close_to_srgb(const sk_colorspace_t* self);
SK4D_API bool sk4d_colorspace_gamma_is_linear(const sk_colorspace_t* self);
SK4D_API bool sk4d_colorspace_is_equal(const sk_colorspace_t* self, const sk_colorspace_t* color_space);
SK4D_API bool sk4d_colorspace_is_numerical_transfer_fn(const sk_colorspace_t* self, /*out*/ sk_colorspacetransferfn_t* transfer_function);
SK4D_API bool sk4d_colorspace_is_srgb(const sk_colorspace_t* self);
SK4D_API sk_colorspace_t* sk4d_colorspace_make(const sk_colorspaceiccprofile_t* profile);
SK4D_API sk_colorspace_t* sk4d_colorspace_make_linear_gamma(const sk_colorspace_t* self);
SK4D_API sk_colorspace_t* sk4d_colorspace_make_rgb(const sk_colorspacetransferfn_t* transfer_function, const sk_colorspacexyz_t* xyz);
SK4D_API sk_colorspace_t* sk4d_colorspace_make_srgb(void);
SK4D_API sk_colorspace_t* sk4d_colorspace_make_srgb_gamma(const sk_colorspace_t* self);
SK4D_API sk_colorspace_t* sk4d_colorspace_make_srgb_linear(void);
SK4D_API void sk4d_colorspace_ref(const sk_colorspace_t* self);
SK4D_API sk_colorspaceiccprofile_t* sk4d_colorspace_to_profile(const sk_colorspace_t* self);
SK4D_API bool sk4d_colorspace_to_xyz(const sk_colorspace_t* self, /*out*/ sk_colorspacexyz_t* xyz);
SK4D_API void sk4d_colorspace_unref(const sk_colorspace_t* self);
SK4D_API void sk4d_colorspaceiccprofile_destroy(sk_colorspaceiccprofile_t* self);
SK4D_API const uint8_t* sk4d_colorspaceiccprofile_get_buffer(const sk_colorspaceiccprofile_t* self, uint32_t* size);
SK4D_API sk_colorspaceiccprofile_t* sk4d_colorspaceiccprofile_make_with_parse(const void* buffer, size_t size);
SK4D_API bool sk4d_colorspaceiccprofile_to_xyz(const sk_colorspaceiccprofile_t* self, /*out*/ sk_colorspacexyz_t* dest);
SK4D_API bool sk4d_colorspaceprimaries_to_xyz(const sk_colorspaceprimaries_t* self, /*out*/ sk_colorspacexyz_t* xyz);
SK4D_API bool sk4d_colorspacetransferfn_invert(const sk_colorspacetransferfn_t* self, sk_colorspacetransferfn_t* transfer_function);
SK4D_API float sk4d_colorspacetransferfn_transform(const sk_colorspacetransferfn_t* self, float x);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
