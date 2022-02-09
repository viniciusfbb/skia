/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <utility>

#include "src/utils/SkOSPath.h"
#include "modules/particles/include/sk4d_particleeffect.h"
#include "modules/particles/src/sk4d_particles_mapping.h"
#include "modules/skresources/src/sk4d_resources_mapping.h"

void sk4d_particleeffect_get_position(const sk_particleeffect_t* self, sk_point_t* result) {
    *result = ToPoint(AsParticleEffect(self)->getPosition());
}

float sk4d_particleeffect_get_rate(const sk_particleeffect_t* self) {
    return AsParticleEffect(self)->getRate();
}

void sk4d_particleeffect_get_uniform(const sk_particleeffect_t* self, size_t index, sk_particleuniform_t* result) {
    auto info = AsParticleEffect(self)->uniformInfo();
    *result = ToParticleUniform(info->fUniforms[index]);
}

size_t sk4d_particleeffect_get_uniform_count(const sk_particleeffect_t* self) {
    auto info = AsParticleEffect(self)->uniformInfo();
    if (!info)
        return 0;
    return info->fUniforms.size();
}

float* sk4d_particleeffect_get_uniform_data(sk_particleeffect_t* self) {
    return AsParticleEffect(self)->uniformData();
}

int32_t sk4d_particleeffect_get_uniform_data_count(const sk_particleeffect_t* self) {
    auto info = AsParticleEffect(self)->uniformInfo();
    if (!info)
        return 0;
    return info->fUniformSlotCount;
}

sk_string_t* sk4d_particleeffect_get_uniform_name(const sk_particleeffect_t* self, size_t index) {
    return ToString(new SkString(AsParticleEffect(self)->uniformInfo()->fUniforms[index].fName));
}

void sk4d_particleeffect_init(void) {
    SkParticleEffect::RegisterParticleTypes();
}

sk_particleeffect_t* sk4d_particleeffect_make_from_file(const char file_name[]) {
    auto data = SkData::MakeFromFileName(file_name);
    if (!data)
        return nullptr;
    auto rp = skresources::DataURIResourceProviderProxy::Make(skresources::FileResourceProvider::Make(SkOSPath::Dirname(file_name), true), true);
    sk_sp<SkParticleEffectParams> params(new SkParticleEffectParams());
    skjson::DOM dom(reinterpret_cast<const char*>(data->data()), data->size());
    SkFromJsonVisitor fromJson(dom.root());
    params->visitFields(&fromJson);
    params->prepare(rp.get());
    return ToParticleEffect(new SkParticleEffect(std::move(params)));
}

sk_particleeffect_t* sk4d_particleeffect_make_from_stream(sk_stream_t* stream, sk_resourceprovider_t* resource_provider) {
    if (!AsStream(stream)->hasLength())
        return nullptr;
    auto data = SkData::MakeFromStream(AsStream(stream), AsStream(stream)->getLength());
    if (!data)
        return nullptr;
    auto rp = skresources::DataURIResourceProviderProxy::Make(sk_ref_sp(AsResourceProvider(resource_provider)), true);
    sk_sp<SkParticleEffectParams> params(new SkParticleEffectParams());
    skjson::DOM dom(static_cast<const char*>(data->data()), data->size());
    SkFromJsonVisitor fromJson(dom.root());
    params->visitFields(&fromJson);
    params->prepare(rp.get());
    return ToParticleEffect(new SkParticleEffect(params));
}

void sk4d_particleeffect_render(sk_particleeffect_t* self, sk_canvas_t* canvas) {
    AsParticleEffect(self)->draw(AsCanvas(canvas));
}

void sk4d_particleeffect_set_position(sk_particleeffect_t* self, const sk_point_t* value) {
    AsParticleEffect(self)->setPosition(*AsPoint(value));
}

void sk4d_particleeffect_set_rate(sk_particleeffect_t* self, float value) {
    AsParticleEffect(self)->setRate(value);
}

bool sk4d_particleeffect_set_uniform(sk_particleeffect_t* self, const char name[], const float data[], int32_t count) {
    return AsParticleEffect(self)->setUniform(name, data, count);
}

void sk4d_particleeffect_start(sk_particleeffect_t* self, double now, bool looping) {
    AsParticleEffect(self)->start(now, looping);
}

void sk4d_particleeffect_update(sk_particleeffect_t* self, double now) {
    AsParticleEffect(self)->update(now);
}
