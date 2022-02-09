/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <algorithm>
#include <iterator>
#include <string.h>
#include <vector>

#include "include/c/sk4d_runtimeeffect.h"
#include "src/c/sk4d_mapping.h"

int32_t sk4d_runtimeeffect_get_child_count(const sk_runtimeeffect_t* self) {
    return static_cast<int32_t>(AsRuntimeEffect(self)->children().size());
}

const char* sk4d_runtimeeffect_get_child_name(const sk_runtimeeffect_t* self, int32_t index) {
    auto vector = AsRuntimeEffect(self)->children();
    auto item   = vector.begin() + index;
    return item->name.c_str();
}

sk_runtimeeffectchildtype_t sk4d_runtimeeffect_get_child_type(const sk_runtimeeffect_t* self, int32_t index) {
    auto vector = AsRuntimeEffect(self)->children();
    auto item   = vector.begin() + index;
    return ToRuntimeEffectChildType(item->type);
}

int32_t sk4d_runtimeeffect_get_uniform_count(const sk_runtimeeffect_t* self) {
    return static_cast<int32_t>(AsRuntimeEffect(self)->uniforms().size());
}

size_t sk4d_runtimeeffect_get_uniform_data_size(const sk_runtimeeffect_t* self) {
    return AsRuntimeEffect(self)->uniformSize();
}

const char* sk4d_runtimeeffect_get_uniform_name(const sk_runtimeeffect_t* self, int32_t index) {
    auto vector = AsRuntimeEffect(self)->uniforms();
    auto item   = vector.begin() + index;
    return item->name.c_str();
}

size_t sk4d_runtimeeffect_get_uniform_offset(const sk_runtimeeffect_t* self, int32_t index) {
    auto vector = AsRuntimeEffect(self)->uniforms();
    auto item   = vector.begin() + index;
    return item->offset;
}

sk_runtimeeffectuniformtype_t sk4d_runtimeeffect_get_uniform_type(const sk_runtimeeffect_t* self, int32_t index) {
    auto vector = AsRuntimeEffect(self)->uniforms();
    auto item   = vector.begin() + index;
    return ToRuntimeEffectUniformType(item->type);
}

int32_t sk4d_runtimeeffect_get_uniform_type_count(const sk_runtimeeffect_t* self, int32_t index) {
    auto vector = AsRuntimeEffect(self)->uniforms();
    auto item   = vector.begin() + index;
    return (item->isArray()) ? item->count : 1;
}

int32_t sk4d_runtimeeffect_index_of_child(const sk_runtimeeffect_t* self, const char name[]) {
    auto vector = AsRuntimeEffect(self)->children();
    auto len    = strlen(name);
    auto iter   = std::find_if(vector.begin(), vector.end(), [name, len](const SkRuntimeEffect::Child& item) {
        return item.name.equals(name, len);
    });
    return (iter == vector.end()) ? -1 : iter->index;
}

int32_t sk4d_runtimeeffect_index_of_uniform(const sk_runtimeeffect_t* self, const char name[]) {
    auto vector = AsRuntimeEffect(self)->uniforms();
    auto len    = strlen(name);
    auto iter   = std::find_if(vector.begin(), vector.end(), [name, len](const SkRuntimeEffect::Uniform& item) {
        return item.name.equals(name, len);
    });
    return (iter == vector.end()) ? -1 : static_cast<int32_t>(std::distance(vector.begin(), iter));
}

sk_blender_t* sk4d_runtimeeffect_make_blender(const sk_runtimeeffect_t* self, const void* uniforms, sk_blender_t* children[]) {
    auto count = AsRuntimeEffect(self)->children().size();
    SkSTArray<4, SkRuntimeEffect::ChildPtr> c(count);
    for (size_t i = 0; i < count; i++)
        c.emplace_back(sk_ref_sp(AsBlender(children[i])));
    return ToBlender(AsRuntimeEffect(self)->makeBlender(SkData::MakeWithoutCopy(uniforms, AsRuntimeEffect(self)->uniformSize()), SkMakeSpan(c)).release());
}

sk_colorfilter_t* sk4d_runtimeeffect_make_color_filter(const sk_runtimeeffect_t* self, const void* uniforms, sk_colorfilter_t* children[]) {
    auto count = AsRuntimeEffect(self)->children().size();
    std::vector<sk_sp<SkColorFilter>> c(count);
    for (size_t i = 0; i < count; i++)
        c[i] = sk_ref_sp(AsColorFilter(children[i]));
    return ToColorFilter(AsRuntimeEffect(self)->makeColorFilter(SkData::MakeWithoutCopy(uniforms, AsRuntimeEffect(self)->uniformSize()), c.data(), count).release());
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

sk_shader_t* sk4d_runtimeeffect_make_shader(const sk_runtimeeffect_t* self, const void* uniforms, sk_shader_t* children[], const sk_matrix_t* local_matrix, bool opaque) {
    auto count = AsRuntimeEffect(self)->children().size();
    std::vector<sk_sp<SkShader>> c(count);
    for (size_t i = 0; i < count; i++)
        c[i] = sk_ref_sp(AsShader(children[i]));
    SkMatrix m;
    if (local_matrix)
      m = AsMatrix(local_matrix);
    return ToShader(AsRuntimeEffect(self)->makeShader(SkData::MakeWithoutCopy(uniforms, AsRuntimeEffect(self)->uniformSize()), c.data(), count, (local_matrix) ? &m : nullptr, opaque).release());
}
