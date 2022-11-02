/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <algorithm>
#include <vector>

#include "include/c/sk4d_runtimeeffect.h"
#include "src/c/sk4d_mapping.h"

int32_t sk4d_runtimeeffect_get_child_count(const sk_runtimeeffect_t* self) {
    return static_cast<int32_t>(AsRuntimeEffect(self)->children().size());
}

const char* sk4d_runtimeeffect_get_child_name(const sk_runtimeeffect_t* self, int32_t index) {
    return AsRuntimeEffect(self)->children()[index].name.data();
}

sk_runtimeeffectchildtype_t sk4d_runtimeeffect_get_child_type(const sk_runtimeeffect_t* self, int32_t index) {
    return ToRuntimeEffectChildType(AsRuntimeEffect(self)->children()[index].type);
}

int32_t sk4d_runtimeeffect_get_uniform_count(const sk_runtimeeffect_t* self) {
    return static_cast<int32_t>(AsRuntimeEffect(self)->uniforms().size());
}

size_t sk4d_runtimeeffect_get_uniform_data_size(const sk_runtimeeffect_t* self) {
    return AsRuntimeEffect(self)->uniformSize();
}

const char* sk4d_runtimeeffect_get_uniform_name(const sk_runtimeeffect_t* self, int32_t index) {
    return AsRuntimeEffect(self)->uniforms()[index].name.data();
}

size_t sk4d_runtimeeffect_get_uniform_offset(const sk_runtimeeffect_t* self, int32_t index) {
    return AsRuntimeEffect(self)->uniforms()[index].offset;
}

sk_runtimeeffectuniformtype_t sk4d_runtimeeffect_get_uniform_type(const sk_runtimeeffect_t* self, int32_t index) {
    return ToRuntimeEffectUniformType(AsRuntimeEffect(self)->uniforms()[index].type);
}

int32_t sk4d_runtimeeffect_get_uniform_type_count(const sk_runtimeeffect_t* self, int32_t index) {
    const auto& uniform = AsRuntimeEffect(self)->uniforms()[index];
    return (uniform.isArray()) ? uniform.count : 1;
}

int32_t sk4d_runtimeeffect_index_of_child(const sk_runtimeeffect_t* self, const char name[]) {
    const auto children = AsRuntimeEffect(self)->children();
    auto iter = std::find_if(children.begin(), children.end(), [name](const SkRuntimeEffect::Child& child) {
        return child.name.compare(name) == 0;
    });
    return iter == children.end() ? -1 : static_cast<int32_t>(std::distance(children.begin(), iter));
}

int32_t sk4d_runtimeeffect_index_of_uniform(const sk_runtimeeffect_t* self, const char name[]) {
    const auto uniforms = AsRuntimeEffect(self)->uniforms();
    auto iter = std::find_if(uniforms.begin(), uniforms.end(), [name](const SkRuntimeEffect::Uniform& uniform) {
        return uniform.name.compare(name) == 0;
    });
    return iter == uniforms.end() ? -1 : static_cast<int32_t>(std::distance(uniforms.begin(), iter));
}

sk_blender_t* sk4d_runtimeeffect_make_blender(const sk_runtimeeffect_t* self, const void* uniforms, sk_blender_t* children[]) {
    std::vector<SkRuntimeEffect::ChildPtr> vector;
    vector.reserve(AsRuntimeEffect(self)->children().size());
    for (size_t i = 0; i < AsRuntimeEffect(self)->children().size(); i++)
        vector.emplace_back(sk_ref_sp(AsBlender(children[i])));
    return ToBlender(AsRuntimeEffect(self)->makeBlender(SkData::MakeWithoutCopy(uniforms, AsRuntimeEffect(self)->uniformSize()), SkSpan(vector)).release());
}

sk_colorfilter_t* sk4d_runtimeeffect_make_color_filter(const sk_runtimeeffect_t* self, const void* uniforms, sk_colorfilter_t* children[]) {
    std::vector<SkRuntimeEffect::ChildPtr> vector;
    vector.reserve(AsRuntimeEffect(self)->children().size());
    for (size_t i = 0; i < AsRuntimeEffect(self)->children().size(); i++)
        vector.emplace_back(sk_ref_sp(AsColorFilter(children[i])));
    return ToColorFilter(AsRuntimeEffect(self)->makeColorFilter(SkData::MakeWithoutCopy(uniforms, AsRuntimeEffect(self)->uniformSize()), SkSpan(vector)).release());
}

sk_runtimeeffect_t* sk4d_runtimeeffect_make_for_blender(const char sksl[], sk_string_t* error_text) {
    SkString input(sksl);
    auto [effect, error] = SkRuntimeEffect::MakeForBlender(input);
    if (!effect && error_text)
        AsString(error_text)->swap(error);
    return ToRuntimeEffect(effect.release());
}

sk_runtimeeffect_t* sk4d_runtimeeffect_make_for_color_filter(const char sksl[], sk_string_t* error_text) {
    SkString input(sksl);
    auto [effect, error] = SkRuntimeEffect::MakeForColorFilter(input);
    if (!effect && error_text)
        AsString(error_text)->swap(error);
    return ToRuntimeEffect(effect.release());
}

sk_runtimeeffect_t* sk4d_runtimeeffect_make_for_shader(const char sksl[], sk_string_t* error_text) {
    SkString input(sksl);
    auto [effect, error] = SkRuntimeEffect::MakeForShader(input);
    if (!effect && error_text)
        AsString(error_text)->swap(error);
    return ToRuntimeEffect(effect.release());
}

sk_image_t* sk4d_runtimeeffect_make_image(const sk_runtimeeffect_t* self, gr_directcontext_t* context, const void* uniforms, sk_shader_t* children[], const sk_matrix_t* local_matrix, const sk_imageinfo_t* image_info, bool mipmapped) {
    std::vector<SkRuntimeEffect::ChildPtr> vector;
    vector.reserve(AsRuntimeEffect(self)->children().size());
    for (size_t i = 0; i < AsRuntimeEffect(self)->children().size(); i++)
        vector.emplace_back(sk_ref_sp(AsShader(children[i])));
    SkMatrix m;
    if (local_matrix)
        m = AsMatrix(local_matrix);
    return ToImage(AsRuntimeEffect(self)->makeImage(SK4D_ONLY_GPU(AsGrDirectContext(context), nullptr), SkData::MakeWithoutCopy(uniforms, AsRuntimeEffect(self)->uniformSize()), SkSpan(vector), (local_matrix) ? &m : nullptr, AsImageInfo(image_info), mipmapped).release());
}

sk_shader_t* sk4d_runtimeeffect_make_shader(const sk_runtimeeffect_t* self, const void* uniforms, sk_shader_t* children[], const sk_matrix_t* local_matrix) {
    std::vector<SkRuntimeEffect::ChildPtr> vector;
    vector.reserve(AsRuntimeEffect(self)->children().size());
    for (size_t i = 0; i < AsRuntimeEffect(self)->children().size(); i++)
        vector.emplace_back(sk_ref_sp(AsShader(children[i])));
    SkMatrix m;
    if (local_matrix)
        m = AsMatrix(local_matrix);
    return ToShader(AsRuntimeEffect(self)->makeShader(SkData::MakeWithoutCopy(uniforms, AsRuntimeEffect(self)->uniformSize()), SkSpan(vector), (local_matrix) ? &m : nullptr).release());
}
