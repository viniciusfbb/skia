/*
* Copyright 2019 Google LLC
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#include "modules/particles/include/SkReflected.h"

#if defined(__MINGW32__)
SkSTArray<16, const SkReflected::Type*, true>* SkReflected::gTypes;
#else
SkSTArray<16, const SkReflected::Type*, true> SkReflected::gTypes;
#endif

void SkReflected::VisitTypes(std::function<void(const Type*)> visitor) {
#if defined(__MINGW32__)
    for (const Type* type : *gTypes) {
#else
    for (const Type* type : gTypes) {
#endif
        visitor(type);
    }
}
