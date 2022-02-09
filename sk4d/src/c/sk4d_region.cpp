/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <memory>

#include "include/c/sk4d_region.h"
#include "src/c/sk4d_mapping.h"

bool sk4d_region_contains(const sk_region_t* self, const sk_region_t* region) {
    return AsRegion(self)->contains(AsRegion(*region));
}

bool sk4d_region_contains2(const sk_region_t* self, const sk_irect_t* rect) {
    return AsRegion(self)->contains(AsIRect(*rect));
}

bool sk4d_region_contains3(const sk_region_t* self, int32_t x, int32_t y) {
    return AsRegion(self)->contains(x, y);
}

sk_region_t* sk4d_region_create(void) {
    return ToRegion(new SkRegion());
}

sk_region_t* sk4d_region_create2(const sk_region_t* region) {
    return ToRegion(new SkRegion(AsRegion(*region)));
}

void sk4d_region_destroy(sk_region_t* self) {
    delete AsRegion(self);
}

sk_path_t* sk4d_region_get_boundary_path(const sk_region_t* self) {
    auto r = std::make_unique<SkPath>();
    return AsRegion(self)->getBoundaryPath(r.get()) ? ToPath(r.release()) : nullptr;
}

void sk4d_region_get_bounds(const sk_region_t* self, sk_irect_t* result) {
    *result = ToIRect(AsRegion(self)->getBounds());
}

bool sk4d_region_intersects(const sk_region_t* self, const sk_region_t* region) {
    return AsRegion(self)->intersects(AsRegion(*region));
}

bool sk4d_region_intersects2(const sk_region_t* self, const sk_irect_t* rect) {
    return AsRegion(self)->intersects(AsIRect(*rect));
}

bool sk4d_region_is_complex(const sk_region_t* self) {
    return AsRegion(self)->isComplex();
}

bool sk4d_region_is_empty(const sk_region_t* self) {
    return AsRegion(self)->isEmpty();
}

bool sk4d_region_is_equal(const sk_region_t* self, const sk_region_t* region) {
    return AsRegion(*region) == AsRegion(*region);
}

bool sk4d_region_is_rect(const sk_region_t* self) {
    return AsRegion(self)->isRect();
}

bool sk4d_region_op(sk_region_t* self, const sk_region_t* region, sk_regionop_t op) {
    return AsRegion(self)->op(AsRegion(*region), AsRegionOp(op));
}

bool sk4d_region_op2(sk_region_t* self, const sk_irect_t* rect, sk_regionop_t op) {
    return AsRegion(self)->op(AsIRect(*rect), AsRegionOp(op));
}

bool sk4d_region_quick_contains(const sk_region_t* self, const sk_irect_t* rect) {
    return AsRegion(self)->quickContains(AsIRect(*rect));
}

bool sk4d_region_quick_reject(const sk_region_t* self, const sk_region_t* region) {
    return AsRegion(self)->quickReject(AsRegion(*region));
}

bool sk4d_region_quick_reject2(const sk_region_t* self, const sk_irect_t* rect) {
    return AsRegion(self)->quickReject(AsIRect(*rect));
}

void sk4d_region_set_empty(sk_region_t* self) {
    AsRegion(self)->setEmpty();
}

bool sk4d_region_set_path(sk_region_t* self, const sk_path_t* path, const sk_region_t* clip) {
    return AsRegion(self)->setPath(AsPath(*path), AsRegion(*clip));
}

bool sk4d_region_set_rect(sk_region_t* self, const sk_irect_t* rect) {
    return AsRegion(self)->setRect(AsIRect(*rect));
}

bool sk4d_region_set_rects(sk_region_t* self, const sk_irect_t rects[], int32_t count) {
    return AsRegion(self)->setRects(AsIRect(rects), count);
}

void sk4d_region_translate(sk_region_t* self, int32_t x, int32_t y) {
    AsRegion(self)->translate(x, y);
}

sk_regioncliperator_t* sk4d_regioncliperator_create(const sk_region_t* region, const sk_irect_t* clip) {
    return ToRegionCliperator(new SkRegion::Cliperator(AsRegion(*region), AsIRect(*clip)));
}

void sk4d_regioncliperator_destroy(sk_regioncliperator_t* self) {
    delete AsRegionCliperator(self);
}

void sk4d_regioncliperator_get_current(const sk_regioncliperator_t* self, sk_irect_t* result) {
    *result = ToIRect(AsRegionCliperator(self)->rect());
}

bool sk4d_regioncliperator_move_next(sk_regioncliperator_t* self) {
    if (AsRegionCliperator(self)->done())
        return false;
    AsRegionCliperator(self)->next();
    return true;
}

sk_regioniterator_t* sk4d_regioniterator_create(const sk_region_t* region) {
    return ToRegionIterator(new SkRegion::Iterator(AsRegion(*region)));
}

void sk4d_regioniterator_destroy(sk_regioniterator_t* self) {
    delete AsRegionIterator(self);
}

void sk4d_regioniterator_get_current(const sk_regioniterator_t* self, sk_irect_t* result) {
    *result = ToIRect(AsRegionIterator(self)->rect());
}

bool sk4d_regioniterator_move_next(sk_regioniterator_t* self) {
    if (AsRegionIterator(self)->done())
        return false;
    AsRegionIterator(self)->next();
    return true;
}

void sk4d_regioniterator_reset(sk_regioniterator_t* self) {
    AsRegionIterator(self)->rewind();
}

sk_regionspanerator_t* sk4d_regionspanerator_create(const sk_region_t* region, int32_t y, int32_t left, int32_t right) {
    return ToRegionSpanerator(new SkRegion::Spanerator(AsRegion(*region), y, left, right));
}

void sk4d_regionspanerator_destroy(sk_regionspanerator_t* self) {
    delete AsRegionSpanerator(self);
}

bool sk4d_regionspanerator_next(sk_regionspanerator_t* self, sk_ipoint_t* elem) {
    return AsRegionSpanerator(self)->next(&AsIPoint(elem)->fX, &AsIPoint(elem)->fY);
}
