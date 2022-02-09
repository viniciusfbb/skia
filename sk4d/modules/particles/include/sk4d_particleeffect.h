/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_particleeffect_DEFINED
#define sk4d_particleeffect_DEFINED

#include "modules/particles/include/sk4d_particles_types.h"

SK4D_C_PLUS_PLUS_BEGIN_GUARD

SK4D_API void sk4d_particleeffect_get_position(const sk_particleeffect_t* self, /*out*/ sk_point_t* result);
SK4D_API float sk4d_particleeffect_get_rate(const sk_particleeffect_t* self);
SK4D_API void sk4d_particleeffect_get_uniform(const sk_particleeffect_t* self, size_t index, /*out*/ sk_particleuniform_t* result);
SK4D_API size_t sk4d_particleeffect_get_uniform_count(const sk_particleeffect_t* self);
SK4D_API float* sk4d_particleeffect_get_uniform_data(sk_particleeffect_t* self);
SK4D_API int32_t sk4d_particleeffect_get_uniform_data_count(const sk_particleeffect_t* self);
SK4D_API sk_string_t* sk4d_particleeffect_get_uniform_name(const sk_particleeffect_t* self, size_t index);
SK4D_API void sk4d_particleeffect_init(void);
SK4D_API sk_particleeffect_t* sk4d_particleeffect_make_from_file(const char file_name[]);
SK4D_API sk_particleeffect_t* sk4d_particleeffect_make_from_stream(sk_stream_t* stream, sk_resourceprovider_t* resource_provider);
SK4D_API void sk4d_particleeffect_render(sk_particleeffect_t* self, sk_canvas_t* canvas);
SK4D_API void sk4d_particleeffect_set_position(sk_particleeffect_t* self, const sk_point_t* value);
SK4D_API void sk4d_particleeffect_set_rate(sk_particleeffect_t* self, float value);
SK4D_API bool sk4d_particleeffect_set_uniform(sk_particleeffect_t* self, const char name[], const float data[], int32_t count);
SK4D_API void sk4d_particleeffect_start(sk_particleeffect_t* self, double now, bool looping);
SK4D_API void sk4d_particleeffect_update(sk_particleeffect_t* self, double now);

SK4D_C_PLUS_PLUS_END_GUARD

#endif
