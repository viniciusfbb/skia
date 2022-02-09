/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_runtimeeffect_DEFINED
#define sk4d_runtimeeffect_DEFINED

#include "include/c/sk4d_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD


SK4D_API int32_t sk4d_runtimeeffect_get_child_count(const sk_runtimeeffect_t* self);
SK4D_API const char* sk4d_runtimeeffect_get_child_name(const sk_runtimeeffect_t* self, int32_t index);
SK4D_API sk_runtimeeffectchildtype_t sk4d_runtimeeffect_get_child_type(const sk_runtimeeffect_t* self, int32_t index);
SK4D_API int32_t sk4d_runtimeeffect_get_uniform_count(const sk_runtimeeffect_t* self);
SK4D_API size_t sk4d_runtimeeffect_get_uniform_data_size(const sk_runtimeeffect_t* self);
SK4D_API const char* sk4d_runtimeeffect_get_uniform_name(const sk_runtimeeffect_t* self, int32_t index);
SK4D_API size_t sk4d_runtimeeffect_get_uniform_offset(const sk_runtimeeffect_t* self, int32_t index);
SK4D_API sk_runtimeeffectuniformtype_t sk4d_runtimeeffect_get_uniform_type(const sk_runtimeeffect_t* self, int32_t index);
SK4D_API int32_t sk4d_runtimeeffect_get_uniform_type_count(const sk_runtimeeffect_t* self, int32_t index);
SK4D_API int32_t sk4d_runtimeeffect_index_of_child(const sk_runtimeeffect_t* self, const char name[]);
SK4D_API int32_t sk4d_runtimeeffect_index_of_uniform(const sk_runtimeeffect_t* self, const char name[]);
SK4D_API sk_blender_t* sk4d_runtimeeffect_make_blender(const sk_runtimeeffect_t* self, const void* uniforms, sk_blender_t* children[]);
SK4D_API sk_colorfilter_t* sk4d_runtimeeffect_make_color_filter(const sk_runtimeeffect_t* self, const void* uniforms, sk_colorfilter_t* children[]);
SK4D_API sk_runtimeeffect_t* sk4d_runtimeeffect_make_for_blender(const char sksl[], sk_string_t* error_text);
SK4D_API sk_runtimeeffect_t* sk4d_runtimeeffect_make_for_color_filter(const char sksl[], sk_string_t* error_text);
SK4D_API sk_runtimeeffect_t* sk4d_runtimeeffect_make_for_shader(const char sksl[], sk_string_t* error_text);
SK4D_API sk_shader_t* sk4d_runtimeeffect_make_shader(const sk_runtimeeffect_t* self, const void* uniforms, sk_shader_t* children[], const sk_matrix_t* local_matrix, bool opaque);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
