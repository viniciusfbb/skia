/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_mapping_DEFINED
#define sk4d_mapping_DEFINED

#include "include/c/sk4d_types.h"
#include "include/codec/SkCodec.h"
#include "include/core/Sk4DStream.h"
#include "include/core/Sk4DTraceMemoryDump.h"
#include "include/core/SkBlender.h"
#include "include/core/SkBlendMode.h"
#include "include/core/SkBlurTypes.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkClipOp.h"
#include "include/core/SkColor.h"
#include "include/core/SkColorFilter.h"
#include "include/core/SkColorSpace.h"
#include "include/core/SkData.h"
#include "include/core/SkDocument.h"
#include "include/core/SkEncodedImageFormat.h"
#include "include/core/SkFont.h"
#include "include/core/SkFontMetrics.h"
#include "include/core/SkFontMgr.h"
#include "include/core/SkFontStyle.h"
#include "include/core/SkFontTypes.h"
#include "include/core/SkGraphics.h"
#include "include/core/SkImage.h"
#include "include/core/SkImageEncoder.h"
#include "include/core/SkImageFilter.h"
#include "include/core/SkImageInfo.h"
#include "include/core/SkM44.h"
#include "include/core/SkMaskFilter.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkMilestone.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPath.h"
#include "include/core/SkPathBuilder.h"
#include "include/core/SkPathEffect.h"
#include "include/core/SkPathMeasure.h"
#include "include/core/SkPathTypes.h"
#include "include/core/SkPicture.h"
#include "include/core/SkPictureRecorder.h"
#include "include/core/SkPixmap.h"
#include "include/core/SkPoint3.h"
#include "include/core/SkRefCnt.h"
#include "include/core/SkRegion.h"
#include "include/core/SkRRect.h"
#include "include/core/SkRSXform.h"
#include "include/core/SkSamplingOptions.h"
#include "include/core/SkScalar.h"
#include "include/core/SkShader.h"
#include "include/core/SkSize.h"
#include "include/core/SkStream.h"
#include "include/core/SkString.h"
#include "include/core/SkSurface.h"
#include "include/core/SkSurfaceProps.h"
#include "include/core/SkTextBlob.h"
#include "include/core/SkTileMode.h"
#include "include/core/SkTime.h"
#include "include/core/SkTraceMemoryDump.h"
#include "include/core/SkTypeface.h"
#include "include/core/SkTypes.h"
#include "include/core/SkVertices.h"
#include "include/docs/SkPDFDocument.h"
#include "include/effects/Sk1DPathEffect.h"
#include "include/effects/Sk2DPathEffect.h"
#include "include/effects/SkBlenders.h"
#include "include/effects/SkColorMatrix.h"
#include "include/effects/SkColorMatrixFilter.h"
#include "include/effects/SkCornerPathEffect.h"
#include "include/effects/SkDashPathEffect.h"
#include "include/effects/SkDiscretePathEffect.h"
#include "include/effects/SkGradientShader.h"
#include "include/effects/SkHighContrastFilter.h"
#include "include/effects/SkImageFilters.h"
#include "include/effects/SkLumaColorFilter.h"
#include "include/effects/SkOpPathEffect.h"
#include "include/effects/SkOverdrawColorFilter.h"
#include "include/effects/SkPerlinNoiseShader.h"
#include "include/effects/SkRuntimeEffect.h"
#include "include/effects/SkShaderMaskFilter.h"
#include "include/effects/SkStrokeAndFillPathEffect.h"
#include "include/effects/SkTableColorFilter.h"
#include "include/effects/SkTableMaskFilter.h"
#include "include/effects/SkTrimPathEffect.h"
#include "include/gpu/GrBackendSurface.h"
#include "include/gpu/GrTypes.h"
#include "include/pathops/SkPathOps.h"
#include "include/third_party/skcms/skcms.h"
#include "include/utils/SkAnimCodecPlayer.h"
#include "include/utils/SkParsePath.h"


// Auxiliary macro for mapping

#define SK4D_DEF_MAP(type, type_t, name, cast)                        \
    static inline type As##name(type_t t) { return cast<type>(t);   } \
    static inline type_t To##name(type t) { return cast<type_t>(t); }


// Generic mapping
//
// Parameters:
//   - C++ |  type
//   - C   |  type_t
//   - Map |  name

#define SK4D_DEF_TYPE_MAP(type, type_t, name) \
    SK4D_DEF_MAP(type, type_t, name, reinterpret_cast)


// Class mapping
//
// Parameters:
//   - C++ Class |  type
//   - C   Class |  type_t
//   - Map       |  name

#define SK4D_DEF_CLASS_MAP(type, type_t, name)          \
    SK4D_DEF_TYPE_MAP(type*, type_t*, name)             \
    SK4D_DEF_TYPE_MAP(type&, type_t&, name)             \
    SK4D_DEF_TYPE_MAP(const type*, const type_t*, name) \
    SK4D_DEF_TYPE_MAP(const type&, const type_t&, name)


// Enum mapping
//
// Parameters:
//   - C++ Enum |  type
//   - C   Enum |  type_t
//   - Map      |  name

#define SK4D_DEF_ENUM_MAP(type, type_t, name) \
    SK4D_DEF_MAP(type, type_t, name, static_cast)


SK4D_DEF_CLASS_MAP(GrBackendFormat, gr_backendformat_t, GrBackendFormat)
SK4D_DEF_CLASS_MAP(GrBackendRenderTarget, gr_backendrendertarget_t, GrBackendRenderTarget)
SK4D_DEF_CLASS_MAP(GrBackendTexture, gr_backendtexture_t, GrBackendTexture)
SK4D_DEF_CLASS_MAP(SkAnimCodecPlayer, sk_animcodecplayer_t, AnimCodecPlayer)
SK4D_DEF_CLASS_MAP(SkBlender, sk_blender_t, Blender)
SK4D_DEF_CLASS_MAP(SkCanvas, sk_canvas_t, Canvas)
SK4D_DEF_CLASS_MAP(SkCanvas::Lattice, sk_lattice_t, Lattice)
SK4D_DEF_CLASS_MAP(skcms_ICCProfile, sk_colorspaceiccprofile_t, ColorSpaceICCProfile)
SK4D_DEF_CLASS_MAP(skcms_Matrix3x3, sk_colorspacexyz_t, ColorSpaceXYZ)
SK4D_DEF_CLASS_MAP(skcms_TransferFunction, sk_colorspacetransferfn_t, ColorSpaceTransferFn)
SK4D_DEF_CLASS_MAP(SkCodec, sk_codec_t, Codec)
SK4D_DEF_CLASS_MAP(SkColor4f, sk_color4f_t, Color4f)
SK4D_DEF_CLASS_MAP(SkColorFilter, sk_colorfilter_t, ColorFilter)
SK4D_DEF_CLASS_MAP(SkColorMatrix, sk_colormatrix_t, ColorMatrix)
SK4D_DEF_CLASS_MAP(SkColorSpace, sk_colorspace_t, ColorSpace)
SK4D_DEF_CLASS_MAP(SkColorSpacePrimaries, sk_colorspaceprimaries_t, ColorSpacePrimaries)
SK4D_DEF_CLASS_MAP(SkCubicResampler, sk_cubicresampler_t, CubicResampler)
SK4D_DEF_CLASS_MAP(SkData, sk_data_t, Data)
SK4D_DEF_CLASS_MAP(SkDocument, sk_document_t, Document)
SK4D_DEF_CLASS_MAP(SkDynamicMemoryWStream, sk_dynamicmemorywstream_t, DynamicMemoryWStream)
SK4D_DEF_CLASS_MAP(SkFILEStream, sk_filestream_t, FileStream);
SK4D_DEF_CLASS_MAP(SkFILEWStream, sk_filewstream_t, FileWStream)
SK4D_DEF_CLASS_MAP(SkFont, sk_font_t, Font)
SK4D_DEF_CLASS_MAP(SkFontMetrics, sk_fontmetrics_t, FontMetrics)
SK4D_DEF_CLASS_MAP(SkFontMgr, sk_fontmgr_t, FontMgr)
SK4D_DEF_CLASS_MAP(SkHighContrastConfig, sk_highcontrastconfig_t, HighContrastConfig)
SK4D_DEF_CLASS_MAP(SkImage, sk_image_t, Image)
SK4D_DEF_CLASS_MAP(SkImageFilter, sk_imagefilter_t, ImageFilter)
SK4D_DEF_CLASS_MAP(SkIPoint, sk_ipoint_t, IPoint)
SK4D_DEF_CLASS_MAP(SkIRect, sk_irect_t, IRect)
SK4D_DEF_CLASS_MAP(SkISize, sk_isize_t, ISize)
SK4D_DEF_CLASS_MAP(SkMaskFilter, sk_maskfilter_t, MaskFilter)
SK4D_DEF_CLASS_MAP(SkMemoryStream, sk_memorystream_t, MemoryStream)
SK4D_DEF_CLASS_MAP(SkOpBuilder, sk_opbuilder_t, OpBuilder)
SK4D_DEF_CLASS_MAP(SkPaint, sk_paint_t, Paint)
SK4D_DEF_CLASS_MAP(SkPath, sk_path_t, Path)
SK4D_DEF_CLASS_MAP(SkPath::Iter, sk_pathiterator_t, PathIterator)
SK4D_DEF_CLASS_MAP(SkPath::RawIter, sk_pathrawiter_t, PathRawIter)
SK4D_DEF_CLASS_MAP(SkPathBuilder, sk_pathbuilder_t, PathBuilder)
SK4D_DEF_CLASS_MAP(SkPathEffect, sk_patheffect_t, PathEffect)
SK4D_DEF_CLASS_MAP(SkPathMeasure, sk_pathmeasure_t, PathMeasure)
SK4D_DEF_CLASS_MAP(SkPicture, sk_picture_t, Picture)
SK4D_DEF_CLASS_MAP(SkPictureRecorder, sk_picturerecorder_t, PictureRecorder)
SK4D_DEF_CLASS_MAP(SkPixmap, sk_pixmap_t, Pixmap)
SK4D_DEF_CLASS_MAP(SkPoint, sk_point_t, Point)
SK4D_DEF_CLASS_MAP(SkPoint3, sk_point3_t, Point3)
SK4D_DEF_CLASS_MAP(SkRect, sk_rect_t, Rect)
SK4D_DEF_CLASS_MAP(SkRefCnt, sk_refcnt_t, RefCnt)
SK4D_DEF_CLASS_MAP(SkRegion, sk_region_t, Region)
SK4D_DEF_CLASS_MAP(SkRegion::Cliperator, sk_regioncliperator_t, RegionCliperator)
SK4D_DEF_CLASS_MAP(SkRegion::Iterator, sk_regioniterator_t, RegionIterator)
SK4D_DEF_CLASS_MAP(SkRegion::Spanerator, sk_regionspanerator_t, RegionSpanerator)
SK4D_DEF_CLASS_MAP(SkRRect, sk_rrect_t, RRect);
SK4D_DEF_CLASS_MAP(SkRSXform, sk_rotationscalematrix_t, RotationScaleMatrix)
SK4D_DEF_CLASS_MAP(SkRuntimeEffect, sk_runtimeeffect_t, RuntimeEffect)
SK4D_DEF_CLASS_MAP(SkSamplingOptions, sk_samplingoptions_t, SamplingOptions)
SK4D_DEF_CLASS_MAP(SkShader, sk_shader_t, Shader)
SK4D_DEF_CLASS_MAP(SkSize, sk_size_t, Size)
SK4D_DEF_CLASS_MAP(SkStream, sk_stream_t, Stream)
SK4D_DEF_CLASS_MAP(SkStreamAdapter, sk_streamadapter_t, StreamAdapter)
SK4D_DEF_CLASS_MAP(SkStreamAdapter::Procs, sk_streamadapter_procs_t, StreamAdapterProcs)
SK4D_DEF_CLASS_MAP(SkString, sk_string_t, String)
SK4D_DEF_CLASS_MAP(SkSurface, sk_surface_t, Surface)
SK4D_DEF_CLASS_MAP(SkSurfaceProps, sk_surfaceprops_t, SurfaceProps)
SK4D_DEF_CLASS_MAP(SkTextBlob, sk_textblob_t, TextBlob)
SK4D_DEF_CLASS_MAP(SkTime::DateTime, sk_datetime_t, DateTime)
SK4D_DEF_CLASS_MAP(SkTraceMemoryDump, sk_tracememorydump_t, TraceMemoryDump)
SK4D_DEF_CLASS_MAP(SkTraceMemoryDumpBaseClass, sk_tracememorydumpbaseclass_t, TraceMemoryDumpBaseClass)
SK4D_DEF_CLASS_MAP(SkTraceMemoryDumpBaseClass::Procs, sk_tracememorydumpbaseclass_procs_t, TraceMemoryDumpBaseClassProcs)
SK4D_DEF_CLASS_MAP(SkTypeface, sk_typeface_t, Typeface)
SK4D_DEF_CLASS_MAP(SkVector, sk_vector_t, Vector)
SK4D_DEF_CLASS_MAP(SkVertices, sk_vertices_t, Vertices)
SK4D_DEF_CLASS_MAP(SkWStream, sk_wstream_t, WStream)
SK4D_DEF_CLASS_MAP(SkWStreamAdapter, sk_wstreamadapter_t, WStreamAdapter)
SK4D_DEF_CLASS_MAP(SkWStreamAdapter::Procs, sk_wstreamadapter_procs_t, WStreamAdapterProcs)

SK4D_DEF_ENUM_MAP(GrBackendApi, gr_backendapi_t, GrBackendAPI)
SK4D_DEF_ENUM_MAP(GrMipmapped, bool, GrMipmapped)
SK4D_DEF_ENUM_MAP(GrSurfaceOrigin, gr_surfaceorigin_t, GrSurfaceOrigin)
SK4D_DEF_ENUM_MAP(SkAlphaType, sk_alphatype_t, AlphaType)
SK4D_DEF_ENUM_MAP(SkBlendMode, sk_blendmode_t, BlendMode)
SK4D_DEF_ENUM_MAP(SkBlurStyle, sk_blurstyle_t, BlurStyle)
SK4D_DEF_ENUM_MAP(SkBudgeted, bool, Budgeted)
SK4D_DEF_ENUM_MAP(SkCanvas::PointMode, sk_drawpointsmode_t, DrawPointsMode)
SK4D_DEF_ENUM_MAP(SkCanvas::SrcRectConstraint, sk_srcrectconstraint_t, SrcRectConstraint)
SK4D_DEF_ENUM_MAP(SkClipOp, sk_clipop_t, ClipOp)
SK4D_DEF_ENUM_MAP(SkColorChannel, sk_colorchannel_t, ColorChannel)
SK4D_DEF_ENUM_MAP(SkColorType, sk_colortype_t, ColorType)
SK4D_DEF_ENUM_MAP(SkEncodedImageFormat, sk_encodedimageformat_t, EncodedImageFormat)
SK4D_DEF_ENUM_MAP(SkFilterMode, sk_filtermode_t, FilterMode)
SK4D_DEF_ENUM_MAP(SkFont::Edging, sk_fontedging_t, FontEdging)
SK4D_DEF_ENUM_MAP(SkFontHinting, sk_fonthinting_t, FontHinting)
SK4D_DEF_ENUM_MAP(SkFontStyle::Slant, sk_fontslant_t, FontSlant)
SK4D_DEF_ENUM_MAP(SkImage::CachingHint, sk_imagecachinghint_t, ImageCachingHint)
SK4D_DEF_ENUM_MAP(SkImageFilters::Dither, bool, ImageFiltersDither)
SK4D_DEF_ENUM_MAP(SkPaint::Cap, sk_strokecap_t, StrokeCap)
SK4D_DEF_ENUM_MAP(SkPaint::Join, sk_strokejoin_t, StrokeJoin)
SK4D_DEF_ENUM_MAP(SkPaint::Style, sk_paintstyle_t, PaintStyle)
SK4D_DEF_ENUM_MAP(SkPath::Verb, sk_pathverb_t, PathVerb)
SK4D_DEF_ENUM_MAP(SkPath1DPathEffect::Style, sk_patheffect1dstyle_t, PathEffect1DStyle)
SK4D_DEF_ENUM_MAP(SkPathBuilder::ArcSize, sk_patharcsize_t, PathArcSize)
SK4D_DEF_ENUM_MAP(SkPathDirection, sk_pathdirection_t, PathDirection)
SK4D_DEF_ENUM_MAP(SkPathFillType, sk_pathfilltype_t, PathFillType)
SK4D_DEF_ENUM_MAP(SkPathMeasure::MatrixFlags, uint32_t, PathMeasureMatrixFlags)
SK4D_DEF_ENUM_MAP(SkPathOp, sk_pathop_t, PathOp)
SK4D_DEF_ENUM_MAP(SkPixelGeometry, sk_pixelgeometry_t, PixelGeometry)
SK4D_DEF_ENUM_MAP(SkRegion::Op, sk_regionop_t, RegionOp)
SK4D_DEF_ENUM_MAP(SkRRect::Corner, sk_rrectcorner_t, RRectCorner)
SK4D_DEF_ENUM_MAP(SkRuntimeEffect::ChildType, sk_runtimeeffectchildtype_t, RuntimeEffectChildType)
SK4D_DEF_ENUM_MAP(SkRuntimeEffect::Uniform::Type, sk_runtimeeffectuniformtype_t, RuntimeEffectUniformType);
SK4D_DEF_ENUM_MAP(SkTextEncoding, sk_textencoding_t, TextEncoding)
SK4D_DEF_ENUM_MAP(SkTileMode, sk_tilemode_t, TileMode)
SK4D_DEF_ENUM_MAP(SkTrimPathEffect::Mode, sk_patheffecttrimmode_t, PathEffectTrimMode)
SK4D_DEF_ENUM_MAP(SkVertices::VertexMode, sk_vertexmode_t, VertexMode)


/*
 * CUSTOM MAPPING
 */

static inline SkFontStyle AsFontStyle(const sk_fontstyle_t* style) {
    return SkFontStyle(style->weight, style->width, AsFontSlant(style->slant));
}
static inline sk_fontstyle_t ToFontStyle(const SkFontStyle& style) {
    return { style.weight(), style.width(), ToFontSlant(style.slant()) };
}

static inline SkImageInfo AsImageInfo(const sk_imageinfo_t* info) {
    return SkImageInfo::Make(
        info->width,
        info->height,
        AsColorType(info->color_type),
        AsAlphaType(info->alpha_type),
        sk_ref_sp(AsColorSpace(info->color_space)));
}
static inline sk_imageinfo_t ToImageInfo(const SkImageInfo& info) {
    return {
        info.width(),
        info.height(),
        ToColorType(info.colorType()),
        ToAlphaType(info.alphaType()),
        ToColorSpace(info.refColorSpace().release()),
    };
}

/* Converting from sk_matrix_t to SkMatrix:
* [ a b c ]      [ a d g ]
* [ d e f ]  ->  [ b e h ]
* [ g h i ]      [ c f i ]
*/

static inline SkMatrix AsMatrix(const sk_matrix_t* matrix) {
    return SkMatrix::MakeAll(
        matrix->m_11, matrix->m_21, matrix->m_31,
        matrix->m_12, matrix->m_22, matrix->m_32,
        matrix->m_13, matrix->m_23, matrix->m_33);
}
static inline sk_matrix_t ToMatrix(const SkMatrix& matrix) {
    return {
        matrix.get(SkMatrix::kMScaleX), matrix.get(SkMatrix::kMSkewY) , matrix.get(SkMatrix::kMPersp0),
        matrix.get(SkMatrix::kMSkewX) , matrix.get(SkMatrix::kMScaleY), matrix.get(SkMatrix::kMPersp1),
        matrix.get(SkMatrix::kMTransX), matrix.get(SkMatrix::kMTransY), matrix.get(SkMatrix::kMPersp2),
    };
}

/* Converting from sk_matrix44_t to SkM44:
* [ a b c d ]      [ a e i m ]
* [ e f g h ]  ->  [ b f j n ]
* [ i j k l ]      [ c g k o ]
* [ m n o p ]      [ d h l p ]
*/

static inline SkM44 AsMatrix44(const sk_matrix44_t* matrix) {
    return SkM44(
        matrix->m_11, matrix->m_12, matrix->m_13, matrix->m_14,
        matrix->m_21, matrix->m_22, matrix->m_23, matrix->m_24,
        matrix->m_31, matrix->m_32, matrix->m_33, matrix->m_34,
        matrix->m_41, matrix->m_42, matrix->m_43, matrix->m_44);
}
static inline sk_matrix44_t ToMatrix44(const SkM44& matrix) {
    return {
        matrix.rc(0, 0), matrix.rc(0, 1), matrix.rc(0, 2), matrix.rc(0, 3),
        matrix.rc(1, 0), matrix.rc(1, 1), matrix.rc(1, 2), matrix.rc(1, 3),
        matrix.rc(2, 0), matrix.rc(2, 1), matrix.rc(2, 2), matrix.rc(2, 3),
        matrix.rc(3, 0), matrix.rc(3, 1), matrix.rc(3, 2), matrix.rc(3, 3),
    };
}

static inline SkPDF::Metadata AsPDFMetadata(const sk_pdfmetadata_t* metadata) {
    return {
        SkString(metadata->title),
        SkString(metadata->author),
        SkString(metadata->subject),
        SkString(metadata->keywords),
        SkString(metadata->creator),
        SkString(metadata->producer),
        AsDateTime(metadata->creation),
        AsDateTime(metadata->modified),
        metadata->raster_dpi,
        metadata->pdfa,
        metadata->encoding_quality,
    };
}


/*
 * SPECIFIC
 */

#define SK4D_SKIP_ARG__(keep, skip, ...) skip
#define SK4D_SKIP_ARG_(args) SK4D_SKIP_ARG__ args
#define SK4D_SKIP_ARG(...) SK4D_SKIP_ARG_((__VA_ARGS__, ))

#define SK4D_FIRST_ARG__(keep, skip, ...) keep
#define SK4D_FIRST_ARG_(args) SK4D_FIRST_ARG__ args
#define SK4D_FIRST_ARG(...) SK4D_FIRST_ARG_((__VA_ARGS__, ))


// XPS

#ifdef SK_SUPPORT_XPS
    #define SK4D_ONLY_XPS(...) SK4D_FIRST_ARG(__VA_ARGS__)

    #include "include/docs/SkXPSDocument.h"
#else
    #define SK4D_ONLY_XPS(...) SK4D_SKIP_ARG(__VA_ARGS__)
#endif


// GPU

#if SK_SUPPORT_GPU
    #define SK4D_ONLY_GPU(...) SK4D_FIRST_ARG(__VA_ARGS__)

    #include "include/gpu/GrDirectContext.h"    
    #include "include/gpu/GrContextOptions.h"

    SK4D_DEF_CLASS_MAP(GrDirectContext, gr_directcontext_t, GrDirectContext)

    static inline GrContextOptions AsGrContextOptions(const gr_contextoptions_t* options) {
        GrContextOptions result;
        result.fBufferMapThreshold            = options->buffer_map_threshold;
        result.fDoManualMipmapping            = options->do_manual_mipmapping;
        result.fAllowPathMaskCaching          = options->allow_path_mask_caching;
        result.fGlyphCacheTextureMaximumBytes = options->glyph_cache_texture_maximum_bytes;
        result.fAvoidStencilBuffers           = options->avoid_stencil_buffers;
        result.fRuntimeProgramCacheSize       = options->runtime_program_cache_size;
        return result;
    }

    #ifdef SK_GL
        #define SK4D_ONLY_GL(...) SK4D_FIRST_ARG(__VA_ARGS__)

        #include "include/gpu/gl/GrGLAssembleInterface.h"
        #include "include/gpu/gl/GrGLConfig.h"
        #include "include/gpu/gl/GrGLInterface.h"
        #include "include/gpu/gl/GrGLTypes.h"

        SK4D_DEF_TYPE_MAP(GrGLGetProc, gr_gl_get_proc, GrGLGetProc)

        SK4D_DEF_CLASS_MAP(GrGLFramebufferInfo, gr_gl_framebufferinfo_t, GrGLFramebufferInfo)
        SK4D_DEF_CLASS_MAP(GrGLInterface, gr_gl_interface_t, GrGLInterface)
        SK4D_DEF_CLASS_MAP(GrGLTextureInfo, gr_gl_textureinfo_t, GrGLTextureInfo)
    #else
        #define SK4D_ONLY_GL(...) SK4D_SKIP_ARG(__VA_ARGS__)
    #endif

    #ifdef SK_METAL
        #define SK4D_ONLY_METAL(...) SK4D_FIRST_ARG(__VA_ARGS__)

        #include "include/gpu/mtl/GrMtlBackendContext.h"
        #include "include/gpu/mtl/GrMtlTypes.h"

        static inline GrMtlBackendContext AsGrMtlBackendContext(const gr_mtl_backendcontext_t* context) {
            GrMtlBackendContext result = {};
            result.fDevice.reset(context->device);
            result.fQueue.reset(context->queue);
            result.fBinaryArchive.reset(context->binary_archive);
            return result;
        }

        static inline GrMtlTextureInfo AsGrMtlTextureInfo(const gr_mtl_textureinfo_t* info) {
            GrMtlTextureInfo result;
            result.fTexture.retain(info->texture);
            return result;
        }
    #else
        #define SK4D_ONLY_METAL(...) SK4D_SKIP_ARG(__VA_ARGS__)
    #endif
#else
    #define SK4D_ONLY_GPU(...) SK4D_SKIP_ARG(__VA_ARGS__)
    #define SK4D_ONLY_GL(...) SK4D_SKIP_ARG(__VA_ARGS__)
    #define SK4D_ONLY_METAL(...) SK4D_SKIP_ARG(__VA_ARGS__)
#endif

#endif
