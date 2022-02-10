/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <type_traits>

#include "include/c/sk4d_types.h"
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
#include "include/core/SkFontStyle.h"
#include "include/core/SkFontTypes.h"
#include "include/core/SkImage.h"
#include "include/core/SkImageFilter.h"
#include "include/core/SkImageInfo.h"
#include "include/core/SkMaskFilter.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPathBuilder.h"
#include "include/core/SkPathEffect.h"
#include "include/core/SkPathMeasure.h"
#include "include/core/SkPathTypes.h"
#include "include/core/SkPicture.h"
#include "include/core/SkPoint.h"
#include "include/core/SkPoint3.h"
#include "include/core/SkRect.h"
#include "include/core/SkRefCnt.h"
#include "include/core/SkRegion.h"
#include "include/core/SkRSXform.h"
#include "include/core/SkSamplingOptions.h"
#include "include/core/SkShader.h"
#include "include/core/SkSize.h"
#include "include/core/SkSurface.h"
#include "include/core/SkSurfaceProps.h"
#include "include/core/SkTextBlob.h"
#include "include/core/SkTileMode.h"
#include "include/core/SkTime.h"
#include "include/core/SkTypeface.h"
#include "include/core/SkTypes.h"
#include "include/core/SkVertices.h"
#include "include/effects/Sk1DPathEffect.h"
#include "include/effects/SkColorMatrix.h"
#include "include/effects/SkHighContrastFilter.h"
#include "include/effects/SkImageFilters.h"
#include "include/effects/SkRuntimeEffect.h"
#include "include/effects/SkTrimPathEffect.h"
#include "include/gpu/GrTypes.h"
#include "include/pathops/SkPathOps.h"
#include "include/svg/SkSVGCanvas.h"
#include "include/third_party/skcms/skcms.h"

#if SK_SUPPORT_GPU
    #include "include/gpu/GrDirectContext.h"  
    #ifdef SK_GL
        #include "include/gpu/gl/GrGLInterface.h"
	    #include "include/gpu/gl/GrGLTypes.h"
	#endif
#endif

/*
 * ASSERTIONS OF DEFINITIONS
 */

static_assert(static_cast<int>(SkFontMetrics::kUnderlineThicknessIsValid_Flag) == UNDERLINE_THICKNESS_IS_VALID_SK_FONT_METRICS_FLAG, "");
static_assert(static_cast<int>(SkFontMetrics::kUnderlinePositionIsValid_Flag)  == UNDERLINE_POSITION_IS_VALID_SK_FONT_METRICS_FLAG,  "");
static_assert(static_cast<int>(SkFontMetrics::kStrikeoutThicknessIsValid_Flag) == STRIKEOUT_THICKNESS_IS_VALID_SK_FONT_METRICS_FLAG, "");
static_assert(static_cast<int>(SkFontMetrics::kStrikeoutPositionIsValid_Flag)  == STRIKEOUT_POSITION_IS_VALID_SK_FONT_METRICS_FLAG,  "");
static_assert(static_cast<int>(SkFontMetrics::kBoundsInvalid_Flag)             == BOUNDS_INVALID_SK_FONT_METRICS_FLAG,               "");

static_assert(static_cast<int>(SkPathMeasure::kGetPosition_MatrixFlag) == GET_POSITION_SK_PATH_MEASURE_MATRIX_FLAG, "");
static_assert(static_cast<int>(SkPathMeasure::kGetTangent_MatrixFlag)  == GET_TANGENT_SK_PATH_MEASURE_MATRIX_FLAG,  "");

static_assert(static_cast<int>(SkPathSegmentMask::kLine_SkPathSegmentMask)  == LINE_SK_PATH_SEGMENT_MASK,  "");
static_assert(static_cast<int>(SkPathSegmentMask::kQuad_SkPathSegmentMask)  == QUAD_SK_PATH_SEGMENT_MASK,  "");
static_assert(static_cast<int>(SkPathSegmentMask::kConic_SkPathSegmentMask) == CONIC_SK_PATH_SEGMENT_MASK, "");
static_assert(static_cast<int>(SkPathSegmentMask::kCubic_SkPathSegmentMask) == CUBIC_SK_PATH_SEGMENT_MASK, "");

static_assert(static_cast<int>(SkSurfaceProps::kUseDeviceIndependentFonts_Flag) == USE_DEVICE_INDEPENDENT_FONTS_SK_SURFACE_PROPS_FLAG, "");
static_assert(static_cast<int>(SkSurfaceProps::kDynamicMSAA_Flag)               == DYNAMIC_MSAA_SK_SURFACE_PROPS_FLAG, "");

static_assert(static_cast<int>(SkSVGCanvas::kConvertTextToPaths_Flag)   == CONVERT_TEXT_TO_PATHS_SK_SVG_CANVAS_FLAG,  "");
static_assert(static_cast<int>(SkSVGCanvas::kNoPrettyXML_Flag)          == NO_PRETTY_XML_SK_SVG_CANVAS_FLAG,          "");
static_assert(static_cast<int>(SkSVGCanvas::kRelativePathEncoding_Flag) == RELATIVE_PATH_ENCODING_SK_SVG_CANVAS_FLAG, "");


/*
 * ASSERTIONS OF STRUCTURES
 *
 *  Custom mappings:
 *   - FontStyle
 *   - GrContextOptions
 *   - GrMtlBackendContext
 *   - GrMtlTextureInfo
 *   - ImageInfo
 *   - Matrix
 *   - Matrix44
 *   - PDFMetadata
 *
 */

static_assert(sizeof(SkCanvas::Lattice)                 == sizeof(sk_lattice_t),                        "");
static_assert(sizeof(skcms_TransferFunction)            == sizeof(sk_colorspacetransferfn_t),           "");
static_assert(sizeof(SkColor4f)                         == sizeof(sk_color4f_t),                        "");
static_assert(sizeof(SkColorMatrix)                     == sizeof(sk_colormatrix_t),                    "");
static_assert(sizeof(SkColorSpacePrimaries)             == sizeof(sk_colorspaceprimaries_t),            "");
static_assert(sizeof(SkCubicResampler)                  == sizeof(sk_cubicresampler_t),                 "");
static_assert(sizeof(SkFontMetrics)                     == sizeof(sk_fontmetrics_t),                    "");
static_assert(sizeof(SkHighContrastConfig)              == sizeof(sk_highcontrastconfig_t),             "");
static_assert(sizeof(SkIPoint)                          == sizeof(sk_ipoint_t),                         "");
static_assert(sizeof(SkIRect)                           == sizeof(sk_irect_t),                          "");
static_assert(sizeof(SkISize)                           == sizeof(sk_isize_t),                          "");
static_assert(sizeof(SkPoint)                           == sizeof(sk_point_t),                          "");
static_assert(sizeof(SkPoint3)                          == sizeof(sk_point3_t),                         "");
static_assert(sizeof(SkRect)                            == sizeof(sk_rect_t),                           "");
static_assert(sizeof(SkRSXform)                         == sizeof(sk_rotationscalematrix_t),            "");
static_assert(sizeof(SkSamplingOptions)                 == sizeof(sk_samplingoptions_t),                "");
static_assert(sizeof(SkSize)                            == sizeof(sk_size_t),                           "");
static_assert(sizeof(SkStreamAdapter::Procs)            == sizeof(sk_streamadapter_procs_t),            "");
static_assert(sizeof(SkSurfaceProps)                    == sizeof(sk_surfaceprops_t),                   "");
static_assert(sizeof(SkTime::DateTime)                  == sizeof(sk_datetime_t),                       "");
static_assert(sizeof(SkTraceMemoryDumpBaseClass::Procs) == sizeof(sk_tracememorydumpbaseclass_procs_t), "");
static_assert(sizeof(SkVector)                          == sizeof(sk_vector_t),                         "");
static_assert(sizeof(SkVector)                          == sizeof(sk_vector_t),                         "");
static_assert(sizeof(SkWStreamAdapter::Procs)           == sizeof(sk_wstreamadapter_procs_t),           "");

#if SK_SUPPORT_GPU
    #ifdef SK_GL
		static_assert(sizeof(GrGLFramebufferInfo) == sizeof(gr_gl_framebufferinfo_t), "");
		static_assert(sizeof(GrGLTextureInfo)     == sizeof(gr_gl_textureinfo_t),     "");
	#endif
#endif


/*
 * ASSERTIONS OF ENUMERATIONS
 */

// GrBackendApi
static_assert(static_cast<int>(GrBackendApi::kOpenGL) == static_cast<int>(OPEN_GL_GR_BACKENDAPI), "");
static_assert(static_cast<int>(GrBackendApi::kMetal)  == static_cast<int>(METAL_GR_BACKENDAPI),   "");

// GrMipmapped
static_assert(std::is_same<std::underlying_type_t<GrMipmapped>, bool>::value, "");

// GrSurfaceOrigin
static_assert(static_cast<int>(kTopLeft_GrSurfaceOrigin)    == static_cast<int>(TOP_LEFT_GR_SURFACEORIGIN),    "");
static_assert(static_cast<int>(kBottomLeft_GrSurfaceOrigin) == static_cast<int>(BOTTOM_LEFT_GR_SURFACEORIGIN), "");

// SkAlphaType
static_assert(static_cast<int>(kUnknown_SkAlphaType)  == static_cast<int>(UNKNOWN_SK_ALPHATYPE),  "");
static_assert(static_cast<int>(kOpaque_SkAlphaType)   == static_cast<int>(OPAQUE_SK_ALPHATYPE),   "");
static_assert(static_cast<int>(kPremul_SkAlphaType)   == static_cast<int>(PREMUL_SK_ALPHATYPE),   "");
static_assert(static_cast<int>(kUnpremul_SkAlphaType) == static_cast<int>(UNPREMUL_SK_ALPHATYPE), "");
static_assert(static_cast<int>(kLastEnum_SkAlphaType) == static_cast<int>(kUnpremul_SkAlphaType), "");

// SkBlendMode
static_assert(static_cast<int>(SkBlendMode::kClear)             == static_cast<int>(CLEAR_SK_BLENDMODE),       "");
static_assert(static_cast<int>(SkBlendMode::kSrc)               == static_cast<int>(SRC_SK_BLENDMODE),         "");
static_assert(static_cast<int>(SkBlendMode::kDst)               == static_cast<int>(DEST_SK_BLENDMODE),        "");
static_assert(static_cast<int>(SkBlendMode::kSrcOver)           == static_cast<int>(SRC_OVER_SK_BLENDMODE),    "");
static_assert(static_cast<int>(SkBlendMode::kDstOver)           == static_cast<int>(DEST_OVER_SK_BLENDMODE),   "");
static_assert(static_cast<int>(SkBlendMode::kSrcIn)             == static_cast<int>(SRC_IN_SK_BLENDMODE),      "");
static_assert(static_cast<int>(SkBlendMode::kDstIn)             == static_cast<int>(DEST_IN_SK_BLENDMODE),     "");
static_assert(static_cast<int>(SkBlendMode::kSrcOut)            == static_cast<int>(SRC_OUT_SK_BLENDMODE),     "");
static_assert(static_cast<int>(SkBlendMode::kDstOut)            == static_cast<int>(DEST_OUT_SK_BLENDMODE),    "");
static_assert(static_cast<int>(SkBlendMode::kSrcATop)           == static_cast<int>(SRC_A_TOP_SK_BLENDMODE),   "");
static_assert(static_cast<int>(SkBlendMode::kDstATop)           == static_cast<int>(DEST_A_TOP_SK_BLENDMODE),  "");
static_assert(static_cast<int>(SkBlendMode::kXor)               == static_cast<int>(XOR_SK_BLENDMODE),         "");
static_assert(static_cast<int>(SkBlendMode::kPlus)              == static_cast<int>(PLUS_SK_BLENDMODE),        "");
static_assert(static_cast<int>(SkBlendMode::kModulate)          == static_cast<int>(MODULATE_SK_BLENDMODE),    "");
static_assert(static_cast<int>(SkBlendMode::kScreen)            == static_cast<int>(SCREEN_SK_BLENDMODE),      "");
static_assert(static_cast<int>(SkBlendMode::kOverlay)           == static_cast<int>(OVERLAY_SK_BLENDMODE),     "");
static_assert(static_cast<int>(SkBlendMode::kDarken)            == static_cast<int>(DARKEN_SK_BLENDMODE),      "");
static_assert(static_cast<int>(SkBlendMode::kLighten)           == static_cast<int>(LIGHTEN_SK_BLENDMODE),     "");
static_assert(static_cast<int>(SkBlendMode::kColorDodge)        == static_cast<int>(COLOR_DODGE_SK_BLENDMODE), "");
static_assert(static_cast<int>(SkBlendMode::kColorBurn)         == static_cast<int>(COLOR_BURN_SK_BLENDMODE),  "");
static_assert(static_cast<int>(SkBlendMode::kHardLight)         == static_cast<int>(HARD_LIGHT_SK_BLENDMODE),  "");
static_assert(static_cast<int>(SkBlendMode::kSoftLight)         == static_cast<int>(SOFT_LIGHT_SK_BLENDMODE),  "");
static_assert(static_cast<int>(SkBlendMode::kDifference)        == static_cast<int>(DIFFERENCE_SK_BLENDMODE),  "");
static_assert(static_cast<int>(SkBlendMode::kExclusion)         == static_cast<int>(EXCLUSION_SK_BLENDMODE),   "");
static_assert(static_cast<int>(SkBlendMode::kMultiply)          == static_cast<int>(MULTIPLY_SK_BLENDMODE),    "");
static_assert(static_cast<int>(SkBlendMode::kHue)               == static_cast<int>(HUE_SK_BLENDMODE),         "");
static_assert(static_cast<int>(SkBlendMode::kSaturation)        == static_cast<int>(SATURATION_SK_BLENDMODE),  "");
static_assert(static_cast<int>(SkBlendMode::kColor)             == static_cast<int>(COLOR_SK_BLENDMODE),       "");
static_assert(static_cast<int>(SkBlendMode::kLuminosity)        == static_cast<int>(LUMINOSITY_SK_BLENDMODE),  "");
static_assert(static_cast<int>(SkBlendMode::kLastCoeffMode)     == static_cast<int>(SkBlendMode::kScreen),     "");
static_assert(static_cast<int>(SkBlendMode::kLastSeparableMode) == static_cast<int>(SkBlendMode::kMultiply),   "");
static_assert(static_cast<int>(SkBlendMode::kLastMode)          == static_cast<int>(SkBlendMode::kLuminosity), "");

// SkBlurStyle
static_assert(static_cast<int>(kNormal_SkBlurStyle)   == static_cast<int>(NORMAL_SK_BLURSTYLE), "");
static_assert(static_cast<int>(kSolid_SkBlurStyle)    == static_cast<int>(SOLID_SK_BLURSTYLE),  "");
static_assert(static_cast<int>(kOuter_SkBlurStyle)    == static_cast<int>(OUTER_SK_BLURSTYLE),  "");
static_assert(static_cast<int>(kInner_SkBlurStyle)    == static_cast<int>(INNER_SK_BLURSTYLE),  "");
static_assert(static_cast<int>(kLastEnum_SkBlurStyle) == static_cast<int>(kInner_SkBlurStyle),  "");

// SkBudgeted
static_assert(std::is_same<std::underlying_type_t<SkBudgeted>, bool>::value, "");

// SkCanvas::PointMode
static_assert(static_cast<int>(SkCanvas::kPoints_PointMode)  == static_cast<int>(POINTS_SK_DRAWPOINTSMODE),  "");
static_assert(static_cast<int>(SkCanvas::kLines_PointMode)   == static_cast<int>(LINES_SK_DRAWPOINTSMODE),   "");
static_assert(static_cast<int>(SkCanvas::kPolygon_PointMode) == static_cast<int>(POLYGON_DRAWPOINTSMODE), "");

// SkCanvas::SrcRectConstraint
static_assert(static_cast<int>(SkCanvas::kStrict_SrcRectConstraint) == static_cast<int>(CLOSE_SK_SRCRECTCONSTRAINT), "");
static_assert(static_cast<int>(SkCanvas::kFast_SrcRectConstraint)   == static_cast<int>(FAST_SK_SRCRECTCONSTRAINT),  "");

// SkClipOp
static_assert(static_cast<int>(SkClipOp::kDifference) == static_cast<int>(DIFFERENCE_SK_CLIPOP), "");
static_assert(static_cast<int>(SkClipOp::kIntersect)  == static_cast<int>(INTERSECT_SK_CLIPOP),  "");

// SkColorChannel
static_assert(static_cast<int>(SkColorChannel::kR)        == static_cast<int>(R_SK_COLORCHANNEL),  "");
static_assert(static_cast<int>(SkColorChannel::kG)        == static_cast<int>(G_SK_COLORCHANNEL),  "");
static_assert(static_cast<int>(SkColorChannel::kB)        == static_cast<int>(B_SK_COLORCHANNEL),  "");
static_assert(static_cast<int>(SkColorChannel::kA)        == static_cast<int>(A_SK_COLORCHANNEL),  "");
static_assert(static_cast<int>(SkColorChannel::kLastEnum) == static_cast<int>(SkColorChannel::kA), "");

// SkColorType
static_assert(static_cast<int>(kUnknown_SkColorType)            == static_cast<int>(UNKNOWN_SK_COLORTYPE),        "");
static_assert(static_cast<int>(kAlpha_8_SkColorType)            == static_cast<int>(ALPHA8_SK_COLORTYPE),         "");
static_assert(static_cast<int>(kRGB_565_SkColorType)            == static_cast<int>(RGB565_SK_COLORTYPE),         "");
static_assert(static_cast<int>(kARGB_4444_SkColorType)          == static_cast<int>(ARGB4444_SK_COLORTYPE),       "");
static_assert(static_cast<int>(kRGBA_8888_SkColorType)          == static_cast<int>(RGBA8888_SK_COLORTYPE),       "");
static_assert(static_cast<int>(kRGB_888x_SkColorType)           == static_cast<int>(RGB888X_SK_COLORTYPE),        "");
static_assert(static_cast<int>(kBGRA_8888_SkColorType)          == static_cast<int>(BGRA8888_SK_COLORTYPE),       "");
static_assert(static_cast<int>(kRGBA_1010102_SkColorType)       == static_cast<int>(RGBA1010102_SK_COLORTYPE),    "");
static_assert(static_cast<int>(kBGRA_1010102_SkColorType)       == static_cast<int>(BGRA1010102_SK_COLORTYPE),    "");
static_assert(static_cast<int>(kRGB_101010x_SkColorType)        == static_cast<int>(RGB101010X_SK_COLORTYPE),     "");
static_assert(static_cast<int>(kBGR_101010x_SkColorType)        == static_cast<int>(BGR101010X_SK_COLORTYPE),     "");
static_assert(static_cast<int>(kGray_8_SkColorType)             == static_cast<int>(GRAY8_SK_COLORTYPE),          "");
static_assert(static_cast<int>(kRGBA_F16Norm_SkColorType)       == static_cast<int>(RGBAF16_SK_COLORTYPE),        "");
static_assert(static_cast<int>(kRGBA_F16_SkColorType)           == static_cast<int>(RGBAF16CLAMPED_SK_COLORTYPE), "");
static_assert(static_cast<int>(kRGBA_F32_SkColorType)           == static_cast<int>(RGBAF32_SK_COLORTYPE),        "");
static_assert(static_cast<int>(kR8G8_unorm_SkColorType)         == static_cast<int>(RG88_SK_COLORTYPE),           "");
static_assert(static_cast<int>(kA16_float_SkColorType)          == static_cast<int>(ALPHAF16_SK_COLORTYPE),       "");
static_assert(static_cast<int>(kR16G16_float_SkColorType)       == static_cast<int>(RGF16_SK_COLORTYPE),          "");
static_assert(static_cast<int>(kA16_unorm_SkColorType)          == static_cast<int>(ALPHA16_SK_COLORTYPE),        "");
static_assert(static_cast<int>(kR16G16_unorm_SkColorType)       == static_cast<int>(RG1616_SK_COLORTYPE),         "");
static_assert(static_cast<int>(kR16G16B16A16_unorm_SkColorType) == static_cast<int>(RGBA16161616_SK_COLORTYPE),   "");
static_assert(static_cast<int>(kSRGBA_8888_SkColorType)         == static_cast<int>(SRGBA8888_SK_COLORTYPE),      "");
static_assert(static_cast<int>(kLastEnum_SkColorType)           == static_cast<int>(kSRGBA_8888_SkColorType),     "");

// SkEncodedImageFormat
static_assert(static_cast<int>(SkEncodedImageFormat::kBMP)  == static_cast<int>(BMP_SK_ENCODEDIMAGEFORMAT),  "");
static_assert(static_cast<int>(SkEncodedImageFormat::kGIF)  == static_cast<int>(GIF_SK_ENCODEDIMAGEFORMAT),  "");
static_assert(static_cast<int>(SkEncodedImageFormat::kICO)  == static_cast<int>(ICO_SK_ENCODEDIMAGEFORMAT),  "");
static_assert(static_cast<int>(SkEncodedImageFormat::kJPEG) == static_cast<int>(JPEG_SK_ENCODEDIMAGEFORMAT), "");
static_assert(static_cast<int>(SkEncodedImageFormat::kPNG)  == static_cast<int>(PNG_SK_ENCODEDIMAGEFORMAT),  "");
static_assert(static_cast<int>(SkEncodedImageFormat::kWBMP) == static_cast<int>(WBMP_SK_ENCODEDIMAGEFORMAT), "");
static_assert(static_cast<int>(SkEncodedImageFormat::kWEBP) == static_cast<int>(WEBP_SK_ENCODEDIMAGEFORMAT), "");
static_assert(static_cast<int>(SkEncodedImageFormat::kPKM)  == static_cast<int>(PKM_SK_ENCODEDIMAGEFORMAT),  "");
static_assert(static_cast<int>(SkEncodedImageFormat::kKTX)  == static_cast<int>(KTX_SK_ENCODEDIMAGEFORMAT),  "");
static_assert(static_cast<int>(SkEncodedImageFormat::kASTC) == static_cast<int>(ASTC_SK_ENCODEDIMAGEFORMAT), "");
static_assert(static_cast<int>(SkEncodedImageFormat::kDNG)  == static_cast<int>(DNG_SK_ENCODEDIMAGEFORMAT),  "");
static_assert(static_cast<int>(SkEncodedImageFormat::kHEIF) == static_cast<int>(HEIF_SK_ENCODEDIMAGEFORMAT), "");
static_assert(static_cast<int>(SkEncodedImageFormat::kAVIF) == static_cast<int>(AVIF_SK_ENCODEDIMAGEFORMAT), "");

// SkFilterMode
static_assert(static_cast<int>(SkFilterMode::kNearest) == static_cast<int>(NEAREST_SK_FILTERMODE), "");
static_assert(static_cast<int>(SkFilterMode::kLinear)  == static_cast<int>(LINEAR_SK_FILTERMODE),  "");
static_assert(static_cast<int>(SkFilterMode::kLast)    == static_cast<int>(SkFilterMode::kLinear), "");

// SkFont::Edging
static_assert(static_cast<int>(SkFont::Edging::kAlias)             == static_cast<int>(ALIAS_SK_FONTEDGING),               "");
static_assert(static_cast<int>(SkFont::Edging::kAntiAlias)         == static_cast<int>(ANTI_ALIAS_SK_FONTEDGING),          "");
static_assert(static_cast<int>(SkFont::Edging::kSubpixelAntiAlias) == static_cast<int>(SUBPIXEL_ANTI_ALIAS_SK_FONTEDGING), "");

// SkFontHinting
static_assert(static_cast<int>(SkFontHinting::kNone)   == static_cast<int>(NONE_SK_FONTHINTING),   "");
static_assert(static_cast<int>(SkFontHinting::kSlight) == static_cast<int>(SLIGHT_SK_FONTHINTING), "");
static_assert(static_cast<int>(SkFontHinting::kNormal) == static_cast<int>(NORMAL_SK_FONTHINTING), "");
static_assert(static_cast<int>(SkFontHinting::kFull)   == static_cast<int>(FULL_SK_FONTHINTING),   "");

// SkFontStyle::Slant
static_assert(static_cast<int>(SkFontStyle::kUpright_Slant) == static_cast<int>(UPRIGHT_SK_FONTSLANT), "");
static_assert(static_cast<int>(SkFontStyle::kItalic_Slant)  == static_cast<int>(ITALIC_SK_FONTSLANT),  "");
static_assert(static_cast<int>(SkFontStyle::kOblique_Slant) == static_cast<int>(OBLIQUE_SK_FONTSLANT), "");

// SkHighContrastConfig::InvertStyle
static_assert(static_cast<int>(SkHighContrastConfig::InvertStyle::kNoInvert)         == static_cast<int>(NO_INVERT_SK_CONTRASTINVERTSTYLE),          "");
static_assert(static_cast<int>(SkHighContrastConfig::InvertStyle::kInvertBrightness) == static_cast<int>(INVERT_BRIGHTNESS_SK_CONTRASTINVERTSTYLE),  "");
static_assert(static_cast<int>(SkHighContrastConfig::InvertStyle::kInvertLightness)  == static_cast<int>(INVERT_LIGHTNESS_SK_CONTRASTINVERTSTYLE),   "");
static_assert(static_cast<int>(SkHighContrastConfig::InvertStyle::kLast)             == static_cast<int>(SkHighContrastConfig::InvertStyle::kInvertLightness), "");

// SkImage::CachingHint
static_assert(static_cast<int>(SkImage::kAllow_CachingHint)    == static_cast<int>(ALLOW_SK_IMAGECACHINGHINT),    "");
static_assert(static_cast<int>(SkImage::kDisallow_CachingHint) == static_cast<int>(DISALLOW_SK_IMAGECACHINGHINT), "");

// SkImageFilters::Dither
static_assert(std::is_same<std::underlying_type_t<SkImageFilters::Dither>, bool>::value, "");

// SkMipmapMode
static_assert(static_cast<int>(SkMipmapMode::kNone)    == static_cast<int>(NONE_SK_MIPMAPMODE),    "");
static_assert(static_cast<int>(SkMipmapMode::kNearest) == static_cast<int>(NEAREST_SK_MIPMAPMODE), "");
static_assert(static_cast<int>(SkMipmapMode::kLinear)  == static_cast<int>(LINEAR_SK_MIPMAPMODE),  "");
static_assert(static_cast<int>(SkMipmapMode::kLast)    == static_cast<int>(SkMipmapMode::kLinear), "");

// SkPaint::Cap
static_assert(static_cast<int>(SkPaint::kButt_Cap)    == static_cast<int>(BUTT_SK_STROKECAP),    "");
static_assert(static_cast<int>(SkPaint::kRound_Cap)   == static_cast<int>(ROUND_SK_STROKECAP),   "");
static_assert(static_cast<int>(SkPaint::kSquare_Cap)  == static_cast<int>(SQUARE_SK_STROKECAP),  "");
static_assert(static_cast<int>(SkPaint::kLast_Cap)    == static_cast<int>(SkPaint::kSquare_Cap), "");
static_assert(static_cast<int>(SkPaint::kDefault_Cap) == static_cast<int>(SkPaint::kButt_Cap),   "");

// SkPaint::Join
static_assert(static_cast<int>(SkPaint::kMiter_Join)    == static_cast<int>(MITER_SK_STROKEJOIN),  "");
static_assert(static_cast<int>(SkPaint::kRound_Join)    == static_cast<int>(ROUND_SK_STROKEJOIN),  "");
static_assert(static_cast<int>(SkPaint::kBevel_Join)    == static_cast<int>(BEVEL_SK_STROKEJOIN),  "");
static_assert(static_cast<int>(SkPaint::kLast_Join)     == static_cast<int>(SkPaint::kBevel_Join), "");
static_assert(static_cast<int>(SkPaint::kDefault_Join)  == static_cast<int>(SkPaint::kMiter_Join), "");

// SkPaint::Style
static_assert(static_cast<int>(SkPaint::kFill_Style)              == static_cast<int>(FILL_SK_PAINTSTYLE),            "");
static_assert(static_cast<int>(SkPaint::kStroke_Style)            == static_cast<int>(STROKE_SK_PAINTSTYLE),          "");
static_assert(static_cast<int>(SkPaint::kStrokeAndFill_Style)     == static_cast<int>(STROKE_AND_FILL_SK_PAINTSTYLE), "");
static_assert(static_cast<int>(SkPaint::kStrokeAndFill_Style) + 1 == SkPaint::kStyleCount,                            "");

// SkPath1DPathEffect::Style
static_assert(static_cast<int>(SkPath1DPathEffect::kTranslate_Style) == static_cast<int>(TRANSLATE_SK_PATHEFFECT1DSTYLE),   "");
static_assert(static_cast<int>(SkPath1DPathEffect::kRotate_Style)    == static_cast<int>(ROTATE_SK_PATHEFFECT1DSTYLE),      "");
static_assert(static_cast<int>(SkPath1DPathEffect::kMorph_Style)     == static_cast<int>(MORPH_SK_PATHEFFECT1DSTYLE),       "");
static_assert(static_cast<int>(SkPath1DPathEffect::kLastEnum_Style)  == static_cast<int>(SkPath1DPathEffect::kMorph_Style), "");

// SkPathBuilder::ArcSize
static_assert(static_cast<int>(SkPathBuilder::kSmall_ArcSize) == static_cast<int>(SMALL_SK_ARCSIZE), "");
static_assert(static_cast<int>(SkPathBuilder::kLarge_ArcSize) == static_cast<int>(LARGE_SK_ARCSIZE), "");

// SkPathDirection
static_assert(static_cast<int>(SkPathDirection::kCW)  == static_cast<int>(CW_SK_PATHDIRECTION),  "");
static_assert(static_cast<int>(SkPathDirection::kCCW) == static_cast<int>(CCW_SK_PATHDIRECTION), "");

// SkPathFillType
static_assert(static_cast<int>(SkPathFillType::kWinding)        == static_cast<int>(WINDING_SK_PATHFILLTYPE),          "");
static_assert(static_cast<int>(SkPathFillType::kEvenOdd)        == static_cast<int>(EVEN_ODD_SK_PATHFILLTYPE),         "");
static_assert(static_cast<int>(SkPathFillType::kInverseWinding) == static_cast<int>(INVERSE_WINDING_SK_PATHFILLTYPE),  "");
static_assert(static_cast<int>(SkPathFillType::kInverseEvenOdd) == static_cast<int>(INVERSE_EVEN_ODD_SK_PATHFILLTYPE), "");

// SkPathOp
static_assert(static_cast<int>(kDifference_SkPathOp)        == static_cast<int>(DIFFERENCE_SK_PATHOP),         "");
static_assert(static_cast<int>(kIntersect_SkPathOp)         == static_cast<int>(INTERSECT_SK_PATHOP),          "");
static_assert(static_cast<int>(kUnion_SkPathOp)             == static_cast<int>(UNION_SK_PATHOP),              "");
static_assert(static_cast<int>(kXOR_SkPathOp)               == static_cast<int>(XOR_SK_PATHOP),                "");
static_assert(static_cast<int>(kReverseDifference_SkPathOp) == static_cast<int>(REVERSE_DIFFERENCE_SK_PATHOP), "");

// SkPathVerb
static_assert(static_cast<int>(SkPathVerb::kMove)  == static_cast<int>(MOVE_SK_PATHVERB),  "");
static_assert(static_cast<int>(SkPathVerb::kLine)  == static_cast<int>(LINE_SK_PATHVERB),  "");
static_assert(static_cast<int>(SkPathVerb::kQuad)  == static_cast<int>(QUAD_SK_PATHVERB),  "");
static_assert(static_cast<int>(SkPathVerb::kConic) == static_cast<int>(CONIC_SK_PATHVERB), "");
static_assert(static_cast<int>(SkPathVerb::kCubic) == static_cast<int>(CUBIC_SK_PATHVERB), "");
static_assert(static_cast<int>(SkPathVerb::kClose) == static_cast<int>(CLOSE_SK_PATHVERB), "");

// SkPixelGeometry
static_assert(static_cast<int>(kUnknown_SkPixelGeometry) == static_cast<int>(UNKNOWN_SK_PIXELGEOMETRY),        "");
static_assert(static_cast<int>(kRGB_H_SkPixelGeometry)   == static_cast<int>(RGB_HORIZONTAL_SK_PIXELGEOMETRY), "");
static_assert(static_cast<int>(kBGR_H_SkPixelGeometry)   == static_cast<int>(BGR_HORIZONTAL_SK_PIXELGEOMETRY), "");
static_assert(static_cast<int>(kRGB_V_SkPixelGeometry)   == static_cast<int>(RGB_VERTICAL_SK_PIXELGEOMETRY),   "");
static_assert(static_cast<int>(kBGR_V_SkPixelGeometry)   == static_cast<int>(BGR_VERTICAL_SK_PIXELGEOMETRY),   "");

// SkRegion::Op
static_assert(static_cast<int>(SkRegion::kDifference_Op)        == static_cast<int>(DIFFERENCE_SK_REGIONOP),         "");
static_assert(static_cast<int>(SkRegion::kIntersect_Op)         == static_cast<int>(INTERSECT_SK_REGIONOP),          "");
static_assert(static_cast<int>(SkRegion::kUnion_Op)             == static_cast<int>(UNION_SK_REGIONOP),              "");
static_assert(static_cast<int>(SkRegion::kXOR_Op)               == static_cast<int>(XOR_SK_REGIONOP),                "");
static_assert(static_cast<int>(SkRegion::kReverseDifference_Op) == static_cast<int>(REVERSE_DIFFERENCE_SK_REGIONOP), "");
static_assert(static_cast<int>(SkRegion::kReplace_Op)           == static_cast<int>(REPLACE_SK_REGIONOP),            "");
static_assert(static_cast<int>(SkRegion::kLastOp)               == static_cast<int>(SkRegion::kReplace_Op),          "");

// SkRRect::Corner
static_assert(static_cast<int>(SkRRect::kUpperLeft_Corner)  == static_cast<int>(UPPER_LEFT_SK_RRECTCORNER),  "");
static_assert(static_cast<int>(SkRRect::kUpperRight_Corner) == static_cast<int>(UPPER_RIGHT_SK_RRECTCORNER), "");
static_assert(static_cast<int>(SkRRect::kLowerRight_Corner) == static_cast<int>(LOWER_RIGHT_SK_RRECTCORNER), "");
static_assert(static_cast<int>(SkRRect::kLowerLeft_Corner)  == static_cast<int>(LOWER_LEFT_SK_RRECTCORNER),  "");

// SkRuntimeEffect::ChildType
static_assert(static_cast<int>(SkRuntimeEffect::ChildType::kShader)      == static_cast<int>(SHADER_SK_RUNTIMEEFFECTCHILDTYPE),         "");
static_assert(static_cast<int>(SkRuntimeEffect::ChildType::kColorFilter) == static_cast<int>(COLOR_FILTER_SK_RUNTIMEEFFECTCHILDTYPE),   "");
static_assert(static_cast<int>(SkRuntimeEffect::ChildType::kBlender)     == static_cast<int>(BLENDER_FILTER_SK_RUNTIMEEFFECTCHILDTYPE), "");

// SkRuntimeEffect::Uniform::Type
static_assert(static_cast<int>(SkRuntimeEffect::Uniform::Type::kFloat)    == static_cast<int>(FLOAT_SK_RUNTIMEEFFECTUNIFORMTYPE),    "");
static_assert(static_cast<int>(SkRuntimeEffect::Uniform::Type::kFloat2)   == static_cast<int>(FLOAT2_SK_RUNTIMEEFFECTUNIFORMTYPE),   "");
static_assert(static_cast<int>(SkRuntimeEffect::Uniform::Type::kFloat3)   == static_cast<int>(FLOAT3_SK_RUNTIMEEFFECTUNIFORMTYPE),   "");
static_assert(static_cast<int>(SkRuntimeEffect::Uniform::Type::kFloat4)   == static_cast<int>(FLOAT4_SK_RUNTIMEEFFECTUNIFORMTYPE),   "");
static_assert(static_cast<int>(SkRuntimeEffect::Uniform::Type::kFloat2x2) == static_cast<int>(FLOAT2X2_SK_RUNTIMEEFFECTUNIFORMTYPE), "");
static_assert(static_cast<int>(SkRuntimeEffect::Uniform::Type::kFloat3x3) == static_cast<int>(FLOAT3X3_SK_RUNTIMEEFFECTUNIFORMTYPE), "");
static_assert(static_cast<int>(SkRuntimeEffect::Uniform::Type::kFloat4x4) == static_cast<int>(FLOAT4X4_SK_RUNTIMEEFFECTUNIFORMTYPE), "");
static_assert(static_cast<int>(SkRuntimeEffect::Uniform::Type::kInt)      == static_cast<int>(INT_SK_RUNTIMEEFFECTUNIFORMTYPE),      "");
static_assert(static_cast<int>(SkRuntimeEffect::Uniform::Type::kInt2)     == static_cast<int>(INT2_SK_RUNTIMEEFFECTUNIFORMTYPE),     "");
static_assert(static_cast<int>(SkRuntimeEffect::Uniform::Type::kInt3)     == static_cast<int>(INT3_SK_RUNTIMEEFFECTUNIFORMTYPE),     "");
static_assert(static_cast<int>(SkRuntimeEffect::Uniform::Type::kInt4)     == static_cast<int>(INT4_SK_RUNTIMEEFFECTUNIFORMTYPE),     "");

// SkTextEncoding
static_assert(static_cast<int>(SkTextEncoding::kUTF8)    == static_cast<int>(UTF8_SK_TEXTENCODING),     "");
static_assert(static_cast<int>(SkTextEncoding::kUTF16)   == static_cast<int>(UTF16_SK_TEXTENCODING),    "");
static_assert(static_cast<int>(SkTextEncoding::kUTF32)   == static_cast<int>(UTF32_SK_TEXTENCODING),    "");
static_assert(static_cast<int>(SkTextEncoding::kGlyphID) == static_cast<int>(GLYPH_ID_SK_TEXTENCODING), "");

// SkTileMode
static_assert(static_cast<int>(SkTileMode::kClamp)        == static_cast<int>(CLAMP_SK_TILEMODE),     "");
static_assert(static_cast<int>(SkTileMode::kRepeat)       == static_cast<int>(REPEAT_SK_TILEMODE),    "");
static_assert(static_cast<int>(SkTileMode::kMirror)       == static_cast<int>(MIRROR_SK_TILEMODE),    "");
static_assert(static_cast<int>(SkTileMode::kDecal)        == static_cast<int>(DECAL_SK_TILEMODE),     "");
static_assert(static_cast<int>(SkTileMode::kLastTileMode) == static_cast<int>(SkTileMode::kDecal),    "");

// SkTrimPathEffect::Mode
static_assert(static_cast<int>(SkTrimPathEffect::Mode::kNormal)   == static_cast<int>(NORMAL_SK_PATHEFFECTTRIMMODE),   "");
static_assert(static_cast<int>(SkTrimPathEffect::Mode::kInverted) == static_cast<int>(INVERTED_SK_PATHEFFECTTRIMMODE), "");

// SkVertices::VertexMode
static_assert(static_cast<int>(SkVertices::kTriangles_VertexMode)     == static_cast<int>(TRIANGLES_SK_VERTEXMODE),             "");
static_assert(static_cast<int>(SkVertices::kTriangleStrip_VertexMode) == static_cast<int>(TRIANGLE_STRIP_SK_VERTEXMODE),        "");
static_assert(static_cast<int>(SkVertices::kTriangleFan_VertexMode)   == static_cast<int>(TRIANGLE_FAN_SK_VERTEXMODE),          "");
static_assert(static_cast<int>(SkVertices::kLast_VertexMode)          == static_cast<int>(SkVertices::kTriangleFan_VertexMode), "");


/*
 * ASSERTIONS OF REFERENCED OBJECTS
 */

static_assert(std::is_base_of<SkRefCnt, SkBlender>::value,       "");
static_assert(std::is_base_of<SkRefCnt, SkColorFilter>::value,   "");
static_assert(std::is_base_of<SkRefCnt, SkDocument>::value,      "");
static_assert(std::is_base_of<SkRefCnt, SkImage>::value,         "");
static_assert(std::is_base_of<SkRefCnt, SkImageFilter>::value,   "");
static_assert(std::is_base_of<SkRefCnt, SkMaskFilter>::value,    "");
static_assert(std::is_base_of<SkRefCnt, SkPathEffect>::value,    "");
static_assert(std::is_base_of<SkRefCnt, SkPicture>::value,       "");
static_assert(std::is_base_of<SkRefCnt, SkRuntimeEffect>::value, "");
static_assert(std::is_base_of<SkRefCnt, SkShader>::value,        "");
static_assert(std::is_base_of<SkRefCnt, SkSurface>::value,       "");
static_assert(std::is_base_of<SkRefCnt, SkTypeface>::value,      "");

#if SK_SUPPORT_GPU
    static_assert(std::is_base_of<SkRefCnt, GrDirectContext>::value, "");
    #ifdef SK_GL
        static_assert(std::is_base_of<SkRefCnt, GrGLInterface>::value, "");
	#endif
#endif


/*
 * ASSERTIONS OF REFERENCED OBJECT0S (NON-VIRTUAL)
 */

static_assert(!std::is_base_of<SkRefCnt, SkColorSpace>::value, "");
static_assert(!std::is_base_of<SkRefCnt, SkData>::value,       "");
static_assert(!std::is_base_of<SkRefCnt, SkTextBlob>::value,   "");
static_assert(!std::is_base_of<SkRefCnt, SkVertices>::value,   "");
