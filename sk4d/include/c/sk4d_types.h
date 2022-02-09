/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk4d_types_DEFINED
#define sk4d_types_DEFINED

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
    #define SK4D_C_PLUS_PLUS_BEGIN_GUARD extern "C" {
    #define SK4D_C_PLUS_PLUS_END_GUARD   }
#else
    #include <stdbool.h>
    #define SK4D_C_PLUS_PLUS_BEGIN_GUARD
    #define SK4D_C_PLUS_PLUS_END_GUARD
#endif

#ifndef SK4D_IMPLEMENTATION
    #define SK4D_IMPLEMENTATION 0
#endif

#ifndef SK4D_API
    #ifdef SK4D_DLL
        #ifdef _MSC_VER
            #if SK4D_IMPLEMENTATION
                #define SK4D_API __declspec(dllexport)
            #else
                #define SK4D_API __declspec(dllimport)
            #endif
        #else
            #define SK4D_API __attribute__((visibility("default")))
        #endif
    #else
        #define SK4D_API
    #endif
#endif

////////////////////////////////////////////////////////////////////////////////

SK4D_C_PLUS_PLUS_BEGIN_GUARD

typedef struct gr_backendformat_t            gr_backendformat_t;
typedef struct gr_backendrendertarget_t      gr_backendrendertarget_t;
typedef struct gr_backendtexture_t           gr_backendtexture_t;
typedef struct gr_directcontext_t            gr_directcontext_t;
typedef struct sk_animcodecplayer_t          sk_animcodecplayer_t;
typedef struct sk_blender_t                  sk_blender_t;
typedef struct sk_canvas_t                   sk_canvas_t;
typedef struct sk_codec_t                    sk_codec_t;
typedef struct sk_colorfilter_t              sk_colorfilter_t;
typedef struct sk_colorspace_t               sk_colorspace_t;
typedef struct sk_colorspaceiccprofile_t     sk_colorspaceiccprofile_t;
typedef struct sk_data_t                     sk_data_t;
typedef struct sk_document_t                 sk_document_t;
typedef struct sk_dynamicmemorywstream_t     sk_dynamicmemorywstream_t;
typedef struct sk_filestream_t               sk_filestream_t;
typedef struct sk_filewstream_t              sk_filewstream_t;
typedef struct sk_font_t                     sk_font_t;
typedef struct sk_fontmgr_t                  sk_fontmgr_t;
typedef struct sk_image_t                    sk_image_t;
typedef struct sk_imagefilter_t              sk_imagefilter_t;
typedef struct sk_maskfilter_t               sk_maskfilter_t;
typedef struct sk_memorystream_t             sk_memorystream_t;
typedef struct sk_opbuilder_t                sk_opbuilder_t;
typedef struct sk_paint_t                    sk_paint_t;
typedef struct sk_path_t                     sk_path_t;
typedef struct sk_pathbuilder_t              sk_pathbuilder_t;
typedef struct sk_patheffect_t               sk_patheffect_t;
typedef struct sk_pathiterator_t             sk_pathiterator_t;
typedef struct sk_pathmeasure_t              sk_pathmeasure_t;
typedef struct sk_pathrawiter_t              sk_pathrawiter_t;
typedef struct sk_picture_t                  sk_picture_t;
typedef struct sk_picturerecorder_t          sk_picturerecorder_t;
typedef struct sk_pixmap_t                   sk_pixmap_t;
typedef struct sk_refcnt_t                   sk_refcnt_t;
typedef struct sk_region_t                   sk_region_t;
typedef struct sk_regioncliperator_t         sk_regioncliperator_t;
typedef struct sk_regioniterator_t           sk_regioniterator_t;
typedef struct sk_regionspanerator_t         sk_regionspanerator_t;
typedef struct sk_rrect_t                    sk_rrect_t;
typedef struct sk_runtimeeffect_t            sk_runtimeeffect_t;
typedef struct sk_shader_t                   sk_shader_t;
typedef struct sk_stream_t                   sk_stream_t;
typedef struct sk_streamadapter_t            sk_streamadapter_t;
typedef struct sk_string_t                   sk_string_t;
typedef struct sk_surface_t                  sk_surface_t;
typedef struct sk_textblob_t                 sk_textblob_t;
typedef struct sk_tracememorydump_t          sk_tracememorydump_t;
typedef struct sk_tracememorydumpbaseclass_t sk_tracememorydumpbaseclass_t;
typedef struct sk_typeface_t                 sk_typeface_t;
typedef struct sk_vertices_t                 sk_vertices_t;
typedef struct sk_wstream_t                  sk_wstream_t;
typedef struct sk_wstreamadapter_t           sk_wstreamadapter_t;

#define UNDERLINE_THICKNESS_IS_VALID_SK_FONT_METRICS_FLAG  (1 << 0)
#define UNDERLINE_POSITION_IS_VALID_SK_FONT_METRICS_FLAG   (1 << 1)
#define STRIKEOUT_THICKNESS_IS_VALID_SK_FONT_METRICS_FLAG  (1 << 2)
#define STRIKEOUT_POSITION_IS_VALID_SK_FONT_METRICS_FLAG   (1 << 3)
#define BOUNDS_INVALID_SK_FONT_METRICS_FLAG                (1 << 4)

#define GET_POSITION_SK_PATH_MEASURE_MATRIX_FLAG           (1 << 0)
#define GET_TANGENT_SK_PATH_MEASURE_MATRIX_FLAG            (1 << 1)

#define LINE_SK_PATH_SEGMENT_MASK                          (1 << 0)
#define QUAD_SK_PATH_SEGMENT_MASK                          (1 << 1)
#define CONIC_SK_PATH_SEGMENT_MASK                         (1 << 2)
#define CUBIC_SK_PATH_SEGMENT_MASK                         (1 << 3)

#define USE_DEVICE_INDEPENDENT_FONTS_SK_SURFACE_PROPS_FLAG (1 << 0)
#define DYNAMIC_MSAA_SK_SURFACE_PROPS_FLAG                 (1 << 1)

typedef enum {
    OPEN_GL_GR_BACKENDAPI,
    METAL_GR_BACKENDAPI = 2,
} gr_backendapi_t;

typedef enum {
    TOP_LEFT_GR_SURFACEORIGIN,
    BOTTOM_LEFT_GR_SURFACEORIGIN,
} gr_surfaceorigin_t;

typedef enum {
    UNKNOWN_SK_ALPHATYPE,
    OPAQUE_SK_ALPHATYPE,
    PREMUL_SK_ALPHATYPE,
    UNPREMUL_SK_ALPHATYPE,
} sk_alphatype_t;

typedef enum {
    CLEAR_SK_BLENDMODE,
    SRC_SK_BLENDMODE,
    DEST_SK_BLENDMODE,
    SRC_OVER_SK_BLENDMODE,
    DEST_OVER_SK_BLENDMODE,
    SRC_IN_SK_BLENDMODE,
    DEST_IN_SK_BLENDMODE,
    SRC_OUT_SK_BLENDMODE,
    DEST_OUT_SK_BLENDMODE,
    SRC_A_TOP_SK_BLENDMODE,
    DEST_A_TOP_SK_BLENDMODE,
    XOR_SK_BLENDMODE,
    PLUS_SK_BLENDMODE,
    MODULATE_SK_BLENDMODE,
    SCREEN_SK_BLENDMODE,
    OVERLAY_SK_BLENDMODE,
    DARKEN_SK_BLENDMODE,
    LIGHTEN_SK_BLENDMODE,
    COLOR_DODGE_SK_BLENDMODE,
    COLOR_BURN_SK_BLENDMODE,
    HARD_LIGHT_SK_BLENDMODE,
    SOFT_LIGHT_SK_BLENDMODE,
    DIFFERENCE_SK_BLENDMODE,
    EXCLUSION_SK_BLENDMODE,
    MULTIPLY_SK_BLENDMODE,
    HUE_SK_BLENDMODE,
    SATURATION_SK_BLENDMODE,
    COLOR_SK_BLENDMODE,
    LUMINOSITY_SK_BLENDMODE,
} sk_blendmode_t;

typedef enum {
    NORMAL_SK_BLURSTYLE,
    SOLID_SK_BLURSTYLE,
    OUTER_SK_BLURSTYLE,
    INNER_SK_BLURSTYLE,
} sk_blurstyle_t;

typedef enum {
    DIFFERENCE_SK_CLIPOP,
    INTERSECT_SK_CLIPOP,
} sk_clipop_t;

typedef enum {
    R_SK_COLORCHANNEL,
    G_SK_COLORCHANNEL,
    B_SK_COLORCHANNEL,
    A_SK_COLORCHANNEL,
} sk_colorchannel_t;

typedef enum {
    UNKNOWN_SK_COLORTYPE,
    ALPHA8_SK_COLORTYPE,
    RGB565_SK_COLORTYPE,
    ARGB4444_SK_COLORTYPE,
    RGBA8888_SK_COLORTYPE,
    RGB888X_SK_COLORTYPE,
    BGRA8888_SK_COLORTYPE,
    RGBA1010102_SK_COLORTYPE,
    BGRA1010102_SK_COLORTYPE,
    RGB101010X_SK_COLORTYPE,
    BGR101010X_SK_COLORTYPE,
    GRAY8_SK_COLORTYPE,
    RGBAF16_SK_COLORTYPE,
    RGBAF16CLAMPED_SK_COLORTYPE,
    RGBAF32_SK_COLORTYPE,
    RG88_SK_COLORTYPE,
    ALPHAF16_SK_COLORTYPE,
    RGF16_SK_COLORTYPE,
    ALPHA16_SK_COLORTYPE,
    RG1616_SK_COLORTYPE,
    RGBA16161616_SK_COLORTYPE,
    SRGBA8888_SK_COLORTYPE,
} sk_colortype_t;

typedef enum {
    POINTS_SK_DRAWPOINTSMODE,
    LINES_SK_DRAWPOINTSMODE,
    POLYGON_DRAWPOINTSMODE,
} sk_drawpointsmode_t;

typedef enum {
    BMP_SK_ENCODEDIMAGEFORMAT,
    GIF_SK_ENCODEDIMAGEFORMAT,
    ICO_SK_ENCODEDIMAGEFORMAT,
    JPEG_SK_ENCODEDIMAGEFORMAT,
    PNG_SK_ENCODEDIMAGEFORMAT,
    WBMP_SK_ENCODEDIMAGEFORMAT,
    WEBP_SK_ENCODEDIMAGEFORMAT,
    PKM_SK_ENCODEDIMAGEFORMAT,
    KTX_SK_ENCODEDIMAGEFORMAT,
    ASTC_SK_ENCODEDIMAGEFORMAT,
    DNG_SK_ENCODEDIMAGEFORMAT,
    HEIF_SK_ENCODEDIMAGEFORMAT,
    AVIF_SK_ENCODEDIMAGEFORMAT,
} sk_encodedimageformat_t;

typedef enum {
    NEAREST_SK_FILTERMODE,
    LINEAR_SK_FILTERMODE,
} sk_filtermode_t;

typedef enum {
    ALIAS_SK_FONTEDGING,
    ANTI_ALIAS_SK_FONTEDGING,
    SUBPIXEL_ANTI_ALIAS_SK_FONTEDGING,
} sk_fontedging_t;

typedef enum {
    NONE_SK_FONTHINTING,
    SLIGHT_SK_FONTHINTING,
    NORMAL_SK_FONTHINTING,
    FULL_SK_FONTHINTING,
} sk_fonthinting_t;

typedef enum {
    UPRIGHT_SK_FONTSLANT,
    ITALIC_SK_FONTSLANT,
    OBLIQUE_SK_FONTSLANT,
} sk_fontslant_t;

typedef enum {
    NO_INVERT_SK_CONTRASTINVERTSTYLE,
    INVERT_BRIGHTNESS_SK_CONTRASTINVERTSTYLE,
    INVERT_LIGHTNESS_SK_CONTRASTINVERTSTYLE,
} sk_contrastinvertstyle_t;

typedef enum {
    ALLOW_SK_IMAGECACHINGHINT,
    DISALLOW_SK_IMAGECACHINGHINT,
} sk_imagecachinghint_t;

typedef enum {
    DEFAULT_SK_LATTICERECTTYPE,
    TRANSPARENT_SK_LATTICERECTTYPE,
    FIXED_COLOR_SK_LATTICERECTTYPE,
} sk_latticerecttype_t;

typedef enum {
    NONE_SK_MIPMAPMODE,
    NEAREST_SK_MIPMAPMODE,
    LINEAR_SK_MIPMAPMODE,
} sk_mipmapmode_t;

typedef enum {
    FILL_SK_PAINTSTYLE,
    STROKE_SK_PAINTSTYLE,
    STROKE_AND_FILL_SK_PAINTSTYLE,
} sk_paintstyle_t;

typedef enum {
    SMALL_SK_ARCSIZE,
    LARGE_SK_ARCSIZE,
} sk_patharcsize_t;

typedef enum {
    CW_SK_PATHDIRECTION,
    CCW_SK_PATHDIRECTION,
} sk_pathdirection_t;

typedef enum {
    TRANSLATE_SK_PATHEFFECT1DSTYLE,
    ROTATE_SK_PATHEFFECT1DSTYLE,
    MORPH_SK_PATHEFFECT1DSTYLE,
} sk_patheffect1dstyle_t;

typedef enum {
    NORMAL_SK_PATHEFFECTTRIMMODE,
    INVERTED_SK_PATHEFFECTTRIMMODE,
} sk_patheffecttrimmode_t;

typedef enum {
    WINDING_SK_PATHFILLTYPE,
    EVEN_ODD_SK_PATHFILLTYPE,
    INVERSE_WINDING_SK_PATHFILLTYPE,
    INVERSE_EVEN_ODD_SK_PATHFILLTYPE,
} sk_pathfilltype_t;

typedef enum {
    DIFFERENCE_SK_PATHOP,
    INTERSECT_SK_PATHOP,
    UNION_SK_PATHOP,
    XOR_SK_PATHOP,
    REVERSE_DIFFERENCE_SK_PATHOP,
} sk_pathop_t;

typedef enum {
    MOVE_SK_PATHVERB,
    LINE_SK_PATHVERB,
    QUAD_SK_PATHVERB,
    CONIC_SK_PATHVERB,
    CUBIC_SK_PATHVERB,
    CLOSE_SK_PATHVERB,
} sk_pathverb_t;

typedef enum {
    UNKNOWN_SK_PIXELGEOMETRY,
    RGB_HORIZONTAL_SK_PIXELGEOMETRY,
    BGR_HORIZONTAL_SK_PIXELGEOMETRY,
    RGB_VERTICAL_SK_PIXELGEOMETRY,
    BGR_VERTICAL_SK_PIXELGEOMETRY,
} sk_pixelgeometry_t;

typedef enum {
    DIFFERENCE_SK_REGIONOP,
    INTERSECT_SK_REGIONOP,
    UNION_SK_REGIONOP,
    XOR_SK_REGIONOP,
    REVERSE_DIFFERENCE_SK_REGIONOP,
    REPLACE_SK_REGIONOP,
} sk_regionop_t;

typedef enum {
    UPPER_LEFT_SK_RRECTCORNER,
    UPPER_RIGHT_SK_RRECTCORNER,
    LOWER_RIGHT_SK_RRECTCORNER,
    LOWER_LEFT_SK_RRECTCORNER,
} sk_rrectcorner_t;

typedef enum {
    SHADER_SK_RUNTIMEEFFECTCHILDTYPE,
    COLOR_FILTER_SK_RUNTIMEEFFECTCHILDTYPE,
    BLENDER_FILTER_SK_RUNTIMEEFFECTCHILDTYPE,
} sk_runtimeeffectchildtype_t;

typedef enum {
    FLOAT_SK_RUNTIMEEFFECTUNIFORMTYPE,
    FLOAT2_SK_RUNTIMEEFFECTUNIFORMTYPE,
    FLOAT3_SK_RUNTIMEEFFECTUNIFORMTYPE,
    FLOAT4_SK_RUNTIMEEFFECTUNIFORMTYPE,
    FLOAT2X2_SK_RUNTIMEEFFECTUNIFORMTYPE,
    FLOAT3X3_SK_RUNTIMEEFFECTUNIFORMTYPE,
    FLOAT4X4_SK_RUNTIMEEFFECTUNIFORMTYPE,
    INT_SK_RUNTIMEEFFECTUNIFORMTYPE,
    INT2_SK_RUNTIMEEFFECTUNIFORMTYPE,
    INT3_SK_RUNTIMEEFFECTUNIFORMTYPE,
    INT4_SK_RUNTIMEEFFECTUNIFORMTYPE,
} sk_runtimeeffectuniformtype_t;

typedef enum {
    CLOSE_SK_SRCRECTCONSTRAINT,
    FAST_SK_SRCRECTCONSTRAINT,
} sk_srcrectconstraint_t;

typedef enum {
    BUTT_SK_STROKECAP,
    ROUND_SK_STROKECAP,
    SQUARE_SK_STROKECAP,
} sk_strokecap_t;

typedef enum {
    MITER_SK_STROKEJOIN,
    ROUND_SK_STROKEJOIN,
    BEVEL_SK_STROKEJOIN,
} sk_strokejoin_t;

typedef enum {
    UTF8_SK_TEXTENCODING,
    UTF16_SK_TEXTENCODING,
    UTF32_SK_TEXTENCODING,
    GLYPH_ID_SK_TEXTENCODING,
} sk_textencoding_t;

typedef enum {
    CLAMP_SK_TILEMODE,
    REPEAT_SK_TILEMODE,
    MIRROR_SK_TILEMODE,
    DECAL_SK_TILEMODE,
} sk_tilemode_t;

typedef enum {
    TRIANGLES_SK_VERTEXMODE,
    TRIANGLE_STRIP_SK_VERTEXMODE,
    TRIANGLE_FAN_SK_VERTEXMODE,
} sk_vertexmode_t;

typedef uint32_t sk_color_t;
typedef uint16_t sk_glyphid_t;
typedef int32_t  sk_unichar_t;

typedef struct {
    float r;
    float g;
    float b;
    float a;
} sk_color4f_t;

typedef struct {
	float m_11;
	float m_12;
	float m_13;
	float m_14;
	float m_15;
	float m_21;
	float m_22;
	float m_23;
	float m_24;
	float m_25;
	float m_31;
	float m_32;
	float m_33;
	float m_34;
	float m_35;
	float m_41;
	float m_42;
	float m_43;
	float m_44;
	float m_45;
} sk_colormatrix_t;

typedef struct {
    float rx;
    float ry;
    float gx;
    float gy;
    float bx;
    float by;
    float wx;
    float wy;
} sk_colorspaceprimaries_t;

typedef struct {
    float g;
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
} sk_colorspacetransferfn_t;

typedef struct {
	float m_11;
	float m_12;
	float m_13;
	float m_21;
	float m_22;
	float m_23;
	float m_31;
	float m_32;
	float m_33;
} sk_colorspacexyz_t;

typedef struct {
    float b;
    float c;
} sk_cubicresampler_t;

typedef struct {
    int16_t  time_zone_minutes;
    uint16_t year;
    uint8_t  month;
    uint8_t  day_of_week;
    uint8_t  day;
    uint8_t  hour;
    uint8_t  minute;
    uint8_t  second;
} sk_datetime_t;

typedef struct {
    uint32_t flags;
    float    top;
    float    ascent;
    float    descent;
    float    bottom;
    float    leading;
    float    avg_char_width;
    float    max_char_width;
    float    x_min;
    float    x_max;
    float    x_height;
    float    cap_height;
    float    underline_thickness;
    float    underline_position;
    float    strikeout_thickness;
    float    strikeout_position;
} sk_fontmetrics_t;

typedef struct {
    int32_t        weight;
    int32_t        width;
    sk_fontslant_t slant;
} sk_fontstyle_t;

typedef struct {
    bool                     grayscale;
    sk_contrastinvertstyle_t invert_style;
    float                    contrast;
} sk_highcontrastconfig_t;

typedef struct {
    int32_t          width;
    int32_t          height;
    sk_colortype_t   color_type;
    sk_alphatype_t   alpha_type;
    sk_colorspace_t* color_space;
} sk_imageinfo_t;

typedef struct {
    int32_t x;
    int32_t y;
} sk_ipoint_t;

typedef struct {
    int32_t left;
    int32_t top;
    int32_t right;
    int32_t bottom;
} sk_irect_t;

typedef struct {
    int32_t width;
    int32_t height;
} sk_isize_t;

typedef struct {
    const int32_t*              x_divs;
    const int32_t*              y_divs;
    const sk_latticerecttype_t* rect_types;
    int32_t                     x_count;
    int32_t                     y_count;
    const sk_irect_t*           bounds;
    const sk_color_t*           colors;
} sk_lattice_t;

typedef struct {
    float m_11;
    float m_12;
    float m_13;
    float m_21;
    float m_22;
    float m_23;
    float m_31;
    float m_32;
    float m_33;
} sk_matrix_t;

typedef struct {
    float m_11;
    float m_12;
    float m_13;
    float m_14;
    float m_21;
    float m_22;
    float m_23;
    float m_24;
    float m_31;
    float m_32;
    float m_33;
    float m_34;
    float m_41;
    float m_42;
    float m_43;
    float m_44;
} sk_matrix44_t;

typedef struct {
    float x;
    float y;
} sk_point_t;

typedef struct {
    sk_pathverb_t verb;
    sk_point_t    points[4];
    float         conic_weight;
} sk_pathiteratorelem_t;

typedef struct {
    const char*   title;
    const char*   author;
    const char*   subject;
    const char*   keywords;
    const char*   creator;
    const char*   producer;
    sk_datetime_t creation;
    sk_datetime_t modified;
    float         raster_dpi;
    bool          pdfa;
    int32_t       encoding_quality;
} sk_pdfmetadata_t;

typedef struct {
    float x;
    float y;
    float z;
} sk_point3_t;

typedef struct {
    float left;
    float top;
    float right;
    float bottom;
} sk_rect_t;

typedef struct {
    float s_cos;
    float s_sin;
    float t_x;
    float t_y;
} sk_rotationscalematrix_t;

typedef struct {
    const bool                use_cubic;
    const sk_cubicresampler_t cubic;
    const sk_filtermode_t     filter;
    const sk_mipmapmode_t     mipmap;
} sk_samplingoptions_t;

typedef struct {
    float width;
    float height;
} sk_size_t;

typedef struct {
    uint32_t           flags;
    sk_pixelgeometry_t pixel_geometry;
} sk_surfaceprops_t;

typedef sk_point_t sk_vector_t;

typedef void (*sk_font_path_proc)              (const sk_path_t* path, const sk_matrix_t* matrix, void* context);
typedef void (*sk_image_raster_release_proc)   (const void* pixels, void* context);
typedef void (*sk_image_texture_release_proc)  (void* context);
typedef void (*sk_surface_raster_release_proc) (void* pixels, void* context);

typedef struct {
    size_t (*get_length)   (void* context);
    size_t (*get_position) (void* context);
    size_t (*read)         (void* context, void* buffer, size_t size);
    bool   (*seek)         (void* context, size_t position);
} sk_streamadapter_procs_t;

typedef struct {
    bool (*write)   (void* context, const void* buffer, size_t size);
} sk_wstreamadapter_procs_t;

typedef struct {
    void (*dump_numeric_value) (void* context, const char dump_name[], const char value_name[], const char units[], uint64_t value);
    void (*dump_string_value)  (void* context, const char dump_name[], const char value_name[], const char value[]);
} sk_tracememorydumpbaseclass_procs_t;

// GPU

typedef struct {
    int32_t buffer_map_threshold;
    bool    do_manual_mipmapping;
    bool    allow_path_mask_caching;
    size_t  glyph_cache_texture_maximum_bytes;
    bool    avoid_stencil_buffers;
    int32_t runtime_program_cache_size;
} gr_contextoptions_t;

// GPU - OpenGL

typedef struct gr_gl_interface_t gr_gl_interface_t;

typedef uint32_t gl_enum_t;
typedef uint32_t gl_uint_t;

typedef struct {
    gl_uint_t fboid;
    gl_enum_t format;
} gr_gl_framebufferinfo_t;

typedef struct {
    gl_enum_t target;
    gl_uint_t id;
    gl_enum_t format;
} gr_gl_textureinfo_t;

typedef void* (*gr_gl_get_proc) (void* context, const char name[]);

// GPU - Metal

typedef const void*  gr_mtl_handle_t;

typedef struct {
    gr_mtl_handle_t texture;
} gr_mtl_textureinfo_t;

typedef struct {
    gr_mtl_handle_t device;
    gr_mtl_handle_t queue;
    gr_mtl_handle_t binary_archive;
} gr_mtl_backendcontext_t;

SK4D_C_PLUS_PLUS_END_GUARD

#endif
