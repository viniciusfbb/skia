/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_rrect.h"
#include "src/c/sk4d_mapping.h"

bool sk4d_rrect_contains(const sk_rrect_t* self, const sk_rect_t* rect) {
    return AsRRect(self)->contains(AsRect(*rect));
}

sk_rrect_t* sk4d_rrect_create(void) {
    return ToRRect(new SkRRect());
}

sk_rrect_t* sk4d_rrect_create2(const sk_rrect_t* rrect) {
    return ToRRect(new SkRRect(AsRRect(*rrect)));
}

void sk4d_rrect_deflate(sk_rrect_t* self, float dx, float dy) {
    AsRRect(self)->inset(dy, dy);
}

void sk4d_rrect_destroy(sk_rrect_t* self) {
    delete AsRRect(self);
}

float sk4d_rrect_get_height(const sk_rrect_t* self) {
    return AsRRect(self)->height();
}

void sk4d_rrect_get_radii(const sk_rrect_t* self, sk_rrectcorner_t corner, sk_vector_t* result) {
    *result = ToVector(AsRRect(self)->radii(AsRRectCorner(corner)));
}

void sk4d_rrect_get_rect(const sk_rrect_t* self, sk_rect_t* result) {
    *result = ToRect(AsRRect(self)->rect());
}

void sk4d_rrect_get_simple_radii(const sk_rrect_t* self, sk_vector_t* result) {
    *result = ToVector(AsRRect(self)->getSimpleRadii());
}

float sk4d_rrect_get_width(const sk_rrect_t* self) {
    return AsRRect(self)->width();
}

void sk4d_rrect_inflate(sk_rrect_t* self, float dx, float dy) {
    AsRRect(self)->outset(dx, dy);
}

bool sk4d_rrect_is_complex(const sk_rrect_t* self) {
    return AsRRect(self)->isComplex();
}

bool sk4d_rrect_is_empty(const sk_rrect_t* self) {
    return AsRRect(self)->isEmpty();
}

bool sk4d_rrect_is_equal(const sk_rrect_t* self, const sk_rrect_t* rrect) {
    return AsRRect(*self) == AsRRect(*rrect);
}

bool sk4d_rrect_is_nine_patch(const sk_rrect_t* self) {
    return AsRRect(self)->isNinePatch();
}

bool sk4d_rrect_is_oval(const sk_rrect_t* self) {
    return AsRRect(self)->isOval();
}

bool sk4d_rrect_is_rect(const sk_rrect_t* self) {
    return AsRRect(self)->isRect();
}

bool sk4d_rrect_is_simple(const sk_rrect_t* self) {
    return AsRRect(self)->isSimple();
}

bool sk4d_rrect_is_valid(const sk_rrect_t* self) {
    return AsRRect(self)->isValid();
}

void sk4d_rrect_offset(sk_rrect_t* self, float dx, float dy) {
    AsRRect(self)->offset(dx, dy);
}

void sk4d_rrect_set_empty(sk_rrect_t* self) {
    AsRRect(self)->setEmpty();
}

void sk4d_rrect_set_nine_patch(sk_rrect_t* self, const sk_rect_t* rect, float radius_left, float radius_top, float radius_right, float radius_bottom) {
    AsRRect(self)->setNinePatch(AsRect(*rect), radius_left, radius_top, radius_right, radius_bottom);
}

void sk4d_rrect_set_oval(sk_rrect_t* self, const sk_rect_t* rect) {
    AsRRect(self)->setOval(AsRect(*rect));
}

void sk4d_rrect_set_rect(sk_rrect_t* self, const sk_rect_t* rect) {
    AsRRect(self)->setRect(AsRect(*rect));
}

void sk4d_rrect_set_rect2(sk_rrect_t* self, const sk_rect_t* rect, const sk_vector_t* radii) {
    AsRRect(self)->setRectRadii(AsRect(*rect), AsVector(radii));
}

void sk4d_rrect_set_rect3(sk_rrect_t* self, const sk_rect_t* rect, float radius_x, float radius_y) {
    AsRRect(self)->setRectXY(AsRect(*rect), radius_x, radius_y);
}

sk_rrect_t* sk4d_rrect_transform(const sk_rrect_t* self, const sk_matrix_t* matrix) {
    auto r = std::make_unique<SkRRect>();
    return AsRRect(self)->transform(AsMatrix(matrix), r.get()) ? ToRRect(r.release()) : nullptr;
}
