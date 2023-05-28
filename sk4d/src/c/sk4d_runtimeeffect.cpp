/*
 * Copyright (c) 2011-2023 Google LLC.
 * Copyright (c) 2021-2023 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <algorithm>
#include <vector>

#include "include/c/sk4d_runtimeeffect.h"
#include "src/c/sk4d_mapping.h"

sk_runtimeblendbuilder_t* sk4d_runtimeblendbuilder_create(sk_runtimeeffect_t* effect) {
    return ToRuntimeBlendBuilder(new SkRuntimeBlendBuilder(sk_ref_sp(AsRuntimeEffect(effect)))); 
}

void sk4d_runtimeblendbuilder_destroy(sk_runtimeblendbuilder_t* self) {
    delete AsRuntimeBlendBuilder(self);
}

sk_blender_t* sk4d_runtimeblendbuilder_make_blender(sk_runtimeblendbuilder_t* self) {
    return ToBlender(AsRuntimeBlendBuilder(self)->makeBlender().release());
}

int32_t sk4d_runtimeeffect_get_child_count(const sk_runtimeeffect_t* self) {
    return static_cast<int32_t>(AsRuntimeEffect(self)->children().size());
}

sk_string_t* sk4d_runtimeeffect_get_child_name(const sk_runtimeeffect_t* self, int32_t index) {
    return ToString(new SkString(AsRuntimeEffect(self)->children()[index].name.data(), AsRuntimeEffect(self)->children()[index].name.size()));
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

sk_string_t* sk4d_runtimeeffect_get_uniform_name(const sk_runtimeeffect_t* self, int32_t index) {
    return ToString(new SkString(AsRuntimeEffect(self)->uniforms()[index].name.data(), AsRuntimeEffect(self)->uniforms()[index].name.size()));
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

sk_blender_t* sk4d_runtimeeffect_make_blender(const sk_runtimeeffect_t* self, const void* uniforms, sk_flattenable_t* children[]) {
    std::vector<SkRuntimeEffect::ChildPtr> vector;
    vector.reserve(AsRuntimeEffect(self)->children().size());
    for (size_t i = 0; i < AsRuntimeEffect(self)->children().size(); i++)
        vector.emplace_back(sk_ref_sp(AsFlattenable(children[i])));
    return ToBlender(AsRuntimeEffect(self)->makeBlender(SkData::MakeWithoutCopy(uniforms, AsRuntimeEffect(self)->uniformSize()), SkSpan(vector)).release());
}

sk_colorfilter_t* sk4d_runtimeeffect_make_color_filter(const sk_runtimeeffect_t* self, const void* uniforms, sk_flattenable_t* children[]) {
    std::vector<SkRuntimeEffect::ChildPtr> vector;
    vector.reserve(AsRuntimeEffect(self)->children().size());
    for (size_t i = 0; i < AsRuntimeEffect(self)->children().size(); i++)
        vector.emplace_back(sk_ref_sp(AsFlattenable(children[i])));
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

sk_image_t* sk4d_runtimeeffect_make_image(const sk_runtimeeffect_t* self, gr_directcontext_t* context, const void* uniforms, sk_flattenable_t* children[], const sk_matrix_t* local_matrix, const sk_imageinfo_t* image_info, bool mipmapped) {
    std::vector<SkRuntimeEffect::ChildPtr> vector;
    vector.reserve(AsRuntimeEffect(self)->children().size());
    for (size_t i = 0; i < AsRuntimeEffect(self)->children().size(); i++)
        vector.emplace_back(sk_ref_sp(AsFlattenable(children[i])));
    SkMatrix m;
    if (local_matrix)
        m = AsMatrix(local_matrix);
    return ToImage(AsRuntimeEffect(self)->makeImage(SK4D_ONLY_GPU(AsGrDirectContext(context), nullptr), SkData::MakeWithoutCopy(uniforms, AsRuntimeEffect(self)->uniformSize()), SkSpan(vector), (local_matrix) ? &m : nullptr, AsImageInfo(image_info), mipmapped).release());
}

sk_shader_t* sk4d_runtimeeffect_make_shader(const sk_runtimeeffect_t* self, const void* uniforms, sk_flattenable_t* children[], const sk_matrix_t* local_matrix) {
    std::vector<SkRuntimeEffect::ChildPtr> vector;
    vector.reserve(AsRuntimeEffect(self)->children().size());
    for (size_t i = 0; i < AsRuntimeEffect(self)->children().size(); i++)
        vector.emplace_back(sk_ref_sp(AsFlattenable(children[i])));
    SkMatrix m;
    if (local_matrix)
        m = AsMatrix(local_matrix);
    return ToShader(AsRuntimeEffect(self)->makeShader(SkData::MakeWithoutCopy(uniforms, AsRuntimeEffect(self)->uniformSize()), SkSpan(vector), (local_matrix) ? &m : nullptr).release());
}

void sk4d_runtimeeffectbuilder_set_child(sk_runtimeeffectbuilder_t* self, const char name[], sk_shader_t* shader) {
    AsRuntimeEffectBuilder(self)->child(name) = std::move(sk_ref_sp(AsShader(shader)));
}

void sk4d_runtimeeffectbuilder_set_child2(sk_runtimeeffectbuilder_t* self, const char name[], sk_colorfilter_t* color_filter) {
    AsRuntimeEffectBuilder(self)->child(name) = std::move(sk_ref_sp(AsColorFilter(color_filter)));
}

void sk4d_runtimeeffectbuilder_set_child3(sk_runtimeeffectbuilder_t* self, const char name[], sk_blender_t* blender) {
    AsRuntimeEffectBuilder(self)->child(name) = std::move(sk_ref_sp(AsBlender(blender)));
}

void sk4d_runtimeeffectbuilder_set_uniform(sk_runtimeeffectbuilder_t* self, const char name[], const void* data) {
    AsRuntimeEffectBuilder(self)->setUniform(name, data);
}

const sk_runtimeeffect_t* sk4d_runtimeeffectbuilder_get_effect(const sk_runtimeeffectbuilder_t* self) {
    return ToRuntimeEffect(AsRuntimeEffectBuilder(self)->effect());
}

sk_runtimeshaderbuilder_t* sk4d_runtimeshaderbuilder_create(sk_runtimeeffect_t* effect) {
    return ToRuntimeShaderBuilder(new SkRuntimeShaderBuilder(sk_ref_sp(AsRuntimeEffect(effect)))); 
}

void sk4d_runtimeshaderbuilder_destroy(sk_runtimeshaderbuilder_t* self) {
    delete AsRuntimeShaderBuilder(self);
}

sk_image_t* sk4d_runtimeshaderbuilder_make_image(sk_runtimeshaderbuilder_t* self, gr_directcontext_t* context, const sk_matrix_t* local_matrix, const sk_imageinfo_t* image_info, bool mipmapped) {
    SkMatrix m;
    if (local_matrix)
        m = AsMatrix(local_matrix);
    return ToImage(AsRuntimeShaderBuilder(self)->makeImage(SK4D_ONLY_GPU(AsGrDirectContext(context), nullptr), (local_matrix) ? &m : nullptr, AsImageInfo(image_info), mipmapped).release());
}

sk_shader_t* sk4d_runtimeshaderbuilder_make_shader(sk_runtimeshaderbuilder_t* self, const sk_matrix_t* local_matrix) {
    SkMatrix m;
    if (local_matrix)
        m = AsMatrix(local_matrix);
    return ToShader(AsRuntimeShaderBuilder(self)->makeShader((local_matrix) ? &m : nullptr).release());
}
