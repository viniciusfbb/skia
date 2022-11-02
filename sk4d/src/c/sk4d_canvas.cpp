/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk4d_canvas.h"
#include "src/c/sk4d_mapping.h"

void sk4d_canvas_clear(sk_canvas_t* self, sk_color_t color) {
    AsCanvas(self)->clear(color);
}

void sk4d_canvas_clear2(sk_canvas_t* self, const sk_color4f_t* color) {
    AsCanvas(self)->clear(AsColor4f(*color));
}

void sk4d_canvas_destroy(sk_canvas_t* self) {
    delete AsCanvas(self);
}

void sk4d_canvas_discard(sk_canvas_t* self) {
    AsCanvas(self)->discard();
}

void sk4d_canvas_clip_path(sk_canvas_t* self, const sk_path_t* path, sk_clipop_t op, bool anti_alias) {
    AsCanvas(self)->clipPath(AsPath(*path), AsClipOp(op), anti_alias);
}

void sk4d_canvas_clip_rect(sk_canvas_t* self, const sk_rect_t* rect, sk_clipop_t op, bool anti_alias) {
    AsCanvas(self)->clipRect(AsRect(*rect), AsClipOp(op), anti_alias);
}

void sk4d_canvas_clip_region(sk_canvas_t* self, const sk_region_t* region, sk_clipop_t op) {
    AsCanvas(self)->clipRegion(AsRegion(*region), AsClipOp(op));
}

void sk4d_canvas_clip_rrect(sk_canvas_t* self, const sk_rrect_t* rrect, sk_clipop_t op, bool anti_alias) {
    AsCanvas(self)->clipRRect(AsRRect(*rrect), AsClipOp(op), anti_alias);
}

void sk4d_canvas_clip_shader(sk_canvas_t* self, sk_shader_t* shader, sk_clipop_t op) {
    AsCanvas(self)->clipShader(sk_ref_sp(AsShader(shader)), AsClipOp(op));
}

void sk4d_canvas_concat(sk_canvas_t* self, const sk_matrix44_t* matrix) {
    AsCanvas(self)->concat(AsMatrix44(matrix));
}

void sk4d_canvas_concat2(sk_canvas_t* self, const sk_matrix_t* matrix) {
    AsCanvas(self)->concat(SkM44(AsMatrix(matrix)));
}

void sk4d_canvas_draw_annotation(sk_canvas_t* self, const sk_rect_t* rect, const char key[], const void* value, size_t size) {
    AsCanvas(self)->drawAnnotation(AsRect(*rect), key, SkData::MakeWithCopy(value, size));
}

void sk4d_canvas_draw_arc(sk_canvas_t* self, const sk_rect_t* oval, float start_angle, float sweep_angle, bool use_center, const sk_paint_t* paint) {
    AsCanvas(self)->drawArc(AsRect(*oval), start_angle, sweep_angle, use_center, AsPaint(*paint));
}

void sk4d_canvas_draw_atlas(sk_canvas_t* self, const sk_image_t* atlas, const sk_rotationscalematrix_t transforms[], const sk_rect_t sprites[], const sk_color_t colors[], int32_t count, sk_blendmode_t blend_mode, const sk_samplingoptions_t* sampling, const sk_rect_t* cull_rect, const sk_paint_t* paint) {
    AsCanvas(self)->drawAtlas(AsImage(atlas), AsRotationScaleMatrix(transforms), AsRect(sprites), colors, count, AsBlendMode(blend_mode), AsSamplingOptions(*sampling), AsRect(cull_rect), AsPaint(paint));
}

void sk4d_canvas_draw_circle(sk_canvas_t* self, const sk_point_t* center, float radius, const sk_paint_t* paint) {
    AsCanvas(self)->drawCircle(*AsPoint(center), radius, AsPaint(*paint));
}

void sk4d_canvas_draw_color(sk_canvas_t* self, sk_color_t color, sk_blendmode_t blend_mode) {
    AsCanvas(self)->drawColor(color, AsBlendMode(blend_mode));
}

void sk4d_canvas_draw_color2(sk_canvas_t* self, const sk_color4f_t* color, sk_blendmode_t blend_mode) {
    AsCanvas(self)->drawColor(AsColor4f(*color), AsBlendMode(blend_mode));
}

void sk4d_canvas_draw_glyphs(sk_canvas_t* self, int32_t count, const sk_glyphid_t glyphs[], const sk_point_t positions[], const sk_point_t* origin, const sk_font_t* font, const sk_paint_t* paint) {
    AsCanvas(self)->drawGlyphs(count, glyphs, AsPoint(positions), *AsPoint(origin), AsFont(*font), AsPaint(*paint));
}

void sk4d_canvas_draw_glyphs2(sk_canvas_t* self, int32_t count, const sk_glyphid_t glyphs[], const sk_rotationscalematrix_t matrices[], const sk_point_t* origin, const sk_font_t* font, const sk_paint_t* paint) {
    AsCanvas(self)->drawGlyphs(count, glyphs, AsRotationScaleMatrix(matrices), *AsPoint(origin), AsFont(*font), AsPaint(*paint));
}

void sk4d_canvas_draw_image(sk_canvas_t* self, const sk_image_t* image, float x, float y, const sk_samplingoptions_t* sampling, const sk_paint_t* paint) {
    AsCanvas(self)->drawImage(AsImage(image), x, y, AsSamplingOptions(*sampling), AsPaint(paint));
}

void sk4d_canvas_draw_image_lattice(sk_canvas_t* self, const sk_image_t* image, const sk_lattice_t* lattice, const sk_rect_t* dest, sk_filtermode_t filter_mode, const sk_paint_t* paint) {
    AsCanvas(self)->drawImageLattice(AsImage(image), AsLattice(*lattice), AsRect(*dest), AsFilterMode(filter_mode), AsPaint(paint));
}

void sk4d_canvas_draw_image_nine(sk_canvas_t* self, const sk_image_t* image, const sk_irect_t* center, const sk_rect_t* dest, sk_filtermode_t filter_mode, const sk_paint_t* paint) {
    AsCanvas(self)->drawImageNine(AsImage(image), AsIRect(*center), AsRect(*dest), AsFilterMode(filter_mode), AsPaint(paint));
}

void sk4d_canvas_draw_image_rect(sk_canvas_t* self, const sk_image_t* image, const sk_rect_t* src, const sk_rect_t* dest, const sk_samplingoptions_t* sampling, const sk_paint_t* paint, sk_srcrectconstraint_t constraint) {
    AsCanvas(self)->drawImageRect(AsImage(image), AsRect(*src), AsRect(*dest), AsSamplingOptions(*sampling), AsPaint(paint), AsSrcRectConstraint(constraint));
}

void sk4d_canvas_draw_line(sk_canvas_t* self, const sk_point_t* point1, const sk_point_t* point2, sk_paint_t* paint) {
    AsCanvas(self)->drawLine(AsPoint(*point1), AsPoint(*point2), AsPaint(*paint));
}

void sk4d_canvas_draw_oval(sk_canvas_t* self, const sk_rect_t* oval, const sk_paint_t* paint) {
    AsCanvas(self)->drawOval(AsRect(*oval), AsPaint(*paint));
}

void sk4d_canvas_draw_paint(sk_canvas_t* self, const sk_paint_t* paint) {
    AsCanvas(self)->drawPaint(AsPaint(*paint));
}

void sk4d_canvas_draw_patch(sk_canvas_t* self, const sk_point_t cubics[12], const sk_color_t colors[4], const sk_point_t tex_coords[4], sk_blendmode_t blend_mode, const sk_paint_t* paint) {
    AsCanvas(self)->drawPatch(AsPoint(cubics), colors, AsPoint(tex_coords), AsBlendMode(blend_mode), AsPaint(*paint));
}

void sk4d_canvas_draw_path(sk_canvas_t* self, const sk_path_t* path, const sk_paint_t* paint) {
    AsCanvas(self)->drawPath(AsPath(*path), AsPaint(*paint));
}

void sk4d_canvas_draw_picture(sk_canvas_t* self, const sk_picture_t* picture, const sk_matrix_t* matrix, const sk_paint_t* paint) {
    SkMatrix m;
    if (matrix)
      m = AsMatrix(matrix);
    AsCanvas(self)->drawPicture(AsPicture(picture), (matrix) ? &m : nullptr, AsPaint(paint));
}

void sk4d_canvas_draw_point(sk_canvas_t* self, const sk_point_t* point, const sk_paint_t* paint) {
    AsCanvas(self)->drawPoint(*AsPoint(point), AsPaint(*paint));
}

void sk4d_canvas_draw_points(sk_canvas_t* self, sk_drawpointsmode_t mode, size_t count, const sk_point_t points[], const sk_paint_t* paint) {
    AsCanvas(self)->drawPoints(AsDrawPointsMode(mode), count, AsPoint(points), AsPaint(*paint));
}

void sk4d_canvas_draw_rect(sk_canvas_t* self, const sk_rect_t* rect, const sk_paint_t* paint) {
    AsCanvas(self)->drawRect(AsRect(*rect), AsPaint(*paint));
}

void sk4d_canvas_draw_region(sk_canvas_t* self, const sk_region_t* region, const sk_paint_t* paint) {
    AsCanvas(self)->drawRegion(AsRegion(*region), AsPaint(*paint));
}

void sk4d_canvas_draw_rrect(sk_canvas_t* self, const sk_rrect_t* rrect, const sk_paint_t* paint) {
    AsCanvas(self)->drawRRect(AsRRect(*rrect), AsPaint(*paint));
}

void sk4d_canvas_draw_rrect2(sk_canvas_t* self, const sk_rect_t* rect, float radius_x, float radius_y, const sk_paint_t* paint) {
    AsCanvas(self)->drawRoundRect(AsRect(*rect), radius_x, radius_y, AsPaint(*paint));
}

void sk4d_canvas_draw_rrect_difference(sk_canvas_t* self, const sk_rrect_t* outer, const sk_rrect_t* inner, const sk_paint_t* paint) {
    AsCanvas(self)->drawDRRect(AsRRect(*outer), AsRRect(*inner), AsPaint(*paint));
}

void sk4d_canvas_draw_simple_text(sk_canvas_t* self, const void* text, size_t size, sk_textencoding_t encoding, float x, float y, const sk_font_t* font, const sk_paint_t* paint) {
    AsCanvas(self)->drawSimpleText(text, size, AsTextEncoding(encoding), x, y, AsFont(*font), AsPaint(*paint));
}

void sk4d_canvas_draw_text_blob(sk_canvas_t* self, const sk_textblob_t* text_blob, float x, float y, const sk_paint_t* paint) {
    AsCanvas(self)->drawTextBlob(AsTextBlob(text_blob), x, y, AsPaint(*paint));
}

void sk4d_canvas_draw_vertices(sk_canvas_t* self, const sk_vertices_t* vertices, sk_blendmode_t blend_mode, const sk_paint_t* paint) {
    AsCanvas(self)->drawVertices(AsVertices(vertices), AsBlendMode(blend_mode), AsPaint(*paint));
}

void sk4d_canvas_get_device_clip_bounds(const sk_canvas_t* self, sk_irect_t* result) {
    *result = ToIRect(AsCanvas(self)->getDeviceClipBounds());
}

void sk4d_canvas_get_local_clip_bounds(const sk_canvas_t* self, sk_rect_t* result) {
    *result = ToRect(AsCanvas(self)->getLocalClipBounds());
}

void sk4d_canvas_get_local_to_device(const sk_canvas_t* self, sk_matrix44_t* result) {
    *result = ToMatrix44(AsCanvas(self)->getLocalToDevice());
}

void sk4d_canvas_get_local_to_device_as_3x3(const sk_canvas_t* self, sk_matrix_t* result) {
    *result = ToMatrix(AsCanvas(self)->getLocalToDevice().asM33());
}

int32_t sk4d_canvas_get_save_count(const sk_canvas_t* self) {
    return AsCanvas(self)->getSaveCount();
}

bool sk4d_canvas_quick_reject(const sk_canvas_t* self, const sk_rect_t* rect) {
    return AsCanvas(self)->quickReject(AsRect(*rect));
}

bool sk4d_canvas_quick_reject2(const sk_canvas_t* self, const sk_path_t* path) {
    return AsCanvas(self)->quickReject(AsPath(*path));
}

void sk4d_canvas_reset_matrix(sk_canvas_t* self) {
    AsCanvas(self)->resetMatrix();
}

void sk4d_canvas_restore(sk_canvas_t* self) {
    AsCanvas(self)->restore();
}

void sk4d_canvas_restore_to_count(sk_canvas_t* self, int32_t save_count) {
    AsCanvas(self)->restoreToCount(save_count);
}

void sk4d_canvas_rotate(sk_canvas_t* self, float degrees) {
    AsCanvas(self)->rotate(degrees);
}

void sk4d_canvas_rotate2(sk_canvas_t* self, float degrees, float px, float py) {
    AsCanvas(self)->rotate(degrees, px, py);
}

int32_t sk4d_canvas_save(sk_canvas_t* self) {
    return AsCanvas(self)->save();
}

int32_t sk4d_canvas_save_layer(sk_canvas_t* self, const sk_rect_t* rect, const sk_paint_t* paint) {
    return AsCanvas(self)->saveLayer(AsRect(rect), AsPaint(paint));
}

int32_t sk4d_canvas_save_layer_alpha(sk_canvas_t* self, const sk_rect_t* rect, uint8_t alpha) {
    return AsCanvas(self)->saveLayerAlpha(AsRect(rect), alpha);
}

void sk4d_canvas_scale(sk_canvas_t* self, float sx, float sy) {
    AsCanvas(self)->scale(sx, sy);
}

void sk4d_canvas_set_matrix(sk_canvas_t* self, const sk_matrix44_t* matrix) {
    AsCanvas(self)->setMatrix(AsMatrix44(matrix));
}

void sk4d_canvas_set_matrix2(sk_canvas_t* self, const sk_matrix_t* matrix) {
    AsCanvas(self)->setMatrix(SkM44(AsMatrix(matrix)));
}

void sk4d_canvas_skew(sk_canvas_t* self, float kx, float ky) {
    AsCanvas(self)->skew(kx, ky);
}

void sk4d_canvas_translate(sk_canvas_t* self, float dx, float dy) {
    AsCanvas(self)->translate(dx, dy);
}
