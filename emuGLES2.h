/*
** Emulated GLES2 for .Net
** Copyright (C) 2015  Wael El Oraiby
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU Affero General Public License as
** published by the Free Software Foundation, either version 3 of the
** License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU Affero General Public License for more details.
**
** You should have received a copy of the GNU Affero General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EMULATEDGLES2_H
#define EMULATEDGLES2_H


#ifndef WAEL_DEFINED_TYPES
#define WAEL_DEFINED_TYPES
#include <stdint.h>
typedef uint8_t		uint8;
typedef uint16_t	uint16;
typedef uint32_t	uint32;
typedef uint64_t	uint64;

typedef int8_t		sint8;
typedef int16_t		sint16;
typedef int32_t		sint32;
typedef int64_t		sint64;
#endif

typedef uint8_t	GLubyte;
typedef uint32_t GLuint;
typedef int32_t GLint;
typedef unsigned char GLboolean;

#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_DLL
    #ifdef __GNUC__
      #define DLL_PUBLIC __attribute__ ((dllexport))
    #else
      #define DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define DLL_PUBLIC __attribute__ ((dllimport))
    #else
      #define DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define DLL_PUBLIC __attribute__ ((visibility ("default")))
    #define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define DLL_PUBLIC
    #define DLL_LOCAL
  #endif
#endif


typedef enum {
	GL_DEPTH_BUFFER_BIT               = 0x00000100,
	GL_STENCIL_BUFFER_BIT             = 0x00000400,
	GL_COLOR_BUFFER_BIT               = 0x00004000,
	GL_FALSE                          = 0	  ,
	GL_TRUE                           = 1	  ,
	GL_POINTS                         = 0x0000,
	GL_LINES                          = 0x0001,
	GL_LINE_LOOP                      = 0x0002,
	GL_LINE_STRIP                     = 0x0003,
	GL_TRIANGLES                      = 0x0004,
	GL_TRIANGLE_STRIP                 = 0x0005,
	GL_TRIANGLE_FAN                   = 0x0006,
	GL_ZERO                           = 0	  ,
	GL_ONE                            = 1	  ,
	GL_SRC_COLOR                      = 0x0300,
	GL_ONE_MINUS_SRC_COLOR            = 0x0301,
	GL_SRC_ALPHA                      = 0x0302,
	GL_ONE_MINUS_SRC_ALPHA            = 0x0303,
	GL_DST_ALPHA                      = 0x0304,
	GL_ONE_MINUS_DST_ALPHA            = 0x0305,
	GL_DST_COLOR                      = 0x0306,
	GL_ONE_MINUS_DST_COLOR            = 0x0307,
	GL_SRC_ALPHA_SATURATE             = 0x0308,
	GL_FUNC_ADD                       = 0x8006,
	GL_BLEND_EQUATION                 = 0x8009,
	GL_BLEND_EQUATION_RGB             = 0x8009,
	GL_BLEND_EQUATION_ALPHA           = 0x883D,
	GL_FUNC_SUBTRACT                  = 0x800A,
	GL_FUNC_REVERSE_SUBTRACT          = 0x800B,
	GL_BLEND_DST_RGB                  = 0x80C8,
	GL_BLEND_SRC_RGB                  = 0x80C9,
	GL_BLEND_DST_ALPHA                = 0x80CA,
	GL_BLEND_SRC_ALPHA                = 0x80CB,
	GL_CONSTANT_COLOR                 = 0x8001,
	GL_ONE_MINUS_CONSTANT_COLOR       = 0x8002,
	GL_CONSTANT_ALPHA                 = 0x8003,
	GL_ONE_MINUS_CONSTANT_ALPHA       = 0x8004,
	GL_BLEND_COLOR                    = 0x8005,
	GL_ARRAY_BUFFER                   = 0x8892,
	GL_ELEMENT_ARRAY_BUFFER           = 0x8893,
	GL_ARRAY_BUFFER_BINDING           = 0x8894,
	GL_ELEMENT_ARRAY_BUFFER_BINDING   = 0x8895,
	GL_STREAM_DRAW                    = 0x88E0,
	GL_STATIC_DRAW                    = 0x88E4,
	GL_DYNAMIC_DRAW                   = 0x88E8,
	GL_BUFFER_SIZE                    = 0x8764,
	GL_BUFFER_USAGE                   = 0x8765,
	GL_CURRENT_VERTEX_ATTRIB          = 0x8626,
	GL_FRONT                          = 0x0404,
	GL_BACK                           = 0x0405,
	GL_FRONT_AND_BACK                 = 0x0408,
	GL_TEXTURE_2D                     = 0x0DE1,
	GL_CULL_FACE                      = 0x0B44,
	GL_BLEND                          = 0x0BE2,
	GL_DITHER                         = 0x0BD0,
	GL_STENCIL_TEST                   = 0x0B90,
	GL_DEPTH_TEST                     = 0x0B71,
	GL_SCISSOR_TEST                   = 0x0C11,
	GL_POLYGON_OFFSET_FILL            = 0x8037,
	GL_SAMPLE_ALPHA_TO_COVERAGE       = 0x809E,
	GL_SAMPLE_COVERAGE                = 0x80A0,
	GL_NO_ERROR                       = 0	  ,
	GL_INVALID_ENUM                   = 0x0500,
	GL_INVALID_VALUE                  = 0x0501,
	GL_INVALID_OPERATION              = 0x0502,
	GL_OUT_OF_MEMORY                  = 0x0505,
	GL_CW                             = 0x0900,
	GL_CCW                            = 0x0901,
	GL_LINE_WIDTH                     = 0x0B21,
	GL_ALIASED_POINT_SIZE_RANGE       = 0x846D,
	GL_ALIASED_LINE_WIDTH_RANGE       = 0x846E,
	GL_CULL_FACE_MODE                 = 0x0B45,
	GL_FRONT_FACE                     = 0x0B46,
	GL_DEPTH_RANGE                    = 0x0B70,
	GL_DEPTH_WRITEMASK                = 0x0B72,
	GL_DEPTH_CLEAR_VALUE              = 0x0B73,
	GL_DEPTH_FUNC                     = 0x0B74,
	GL_STENCIL_CLEAR_VALUE            = 0x0B91,
	GL_STENCIL_FUNC                   = 0x0B92,
	GL_STENCIL_FAIL                   = 0x0B94,
	GL_STENCIL_PASS_DEPTH_FAIL        = 0x0B95,
	GL_STENCIL_PASS_DEPTH_PASS        = 0x0B96,
	GL_STENCIL_REF                    = 0x0B97,
	GL_STENCIL_VALUE_MASK             = 0x0B93,
	GL_STENCIL_WRITEMASK              = 0x0B98,
	GL_STENCIL_BACK_FUNC              = 0x8800,
	GL_STENCIL_BACK_FAIL              = 0x8801,
	GL_STENCIL_BACK_PASS_DEPTH_FAIL   = 0x8802,
	GL_STENCIL_BACK_PASS_DEPTH_PASS   = 0x8803,
	GL_STENCIL_BACK_REF               = 0x8CA3,
	GL_STENCIL_BACK_VALUE_MASK        = 0x8CA4,
	GL_STENCIL_BACK_WRITEMASK         = 0x8CA5,
	GL_VIEWPORT                       = 0x0BA2,
	GL_SCISSOR_BOX                    = 0x0C10,
	GL_COLOR_CLEAR_VALUE              = 0x0C22,
	GL_COLOR_WRITEMASK                = 0x0C23,
	GL_UNPACK_ALIGNMENT               = 0x0CF5,
	GL_PACK_ALIGNMENT                 = 0x0D05,
	GL_MAX_TEXTURE_SIZE               = 0x0D33,
	GL_MAX_VIEWPORT_DIMS              = 0x0D3A,
	GL_SUBPIXEL_BITS                  = 0x0D50,
	GL_RED_BITS                       = 0x0D52,
	GL_GREEN_BITS                     = 0x0D53,
	GL_BLUE_BITS                      = 0x0D54,
	GL_ALPHA_BITS                     = 0x0D55,
	GL_DEPTH_BITS                     = 0x0D56,
	GL_STENCIL_BITS                   = 0x0D57,
	GL_POLYGON_OFFSET_UNITS           = 0x2A00,
	GL_POLYGON_OFFSET_FACTOR          = 0x8038,
	GL_TEXTURE_BINDING_2D             = 0x8069,
	GL_SAMPLE_BUFFERS                 = 0x80A8,
	GL_SAMPLES                        = 0x80A9,
	GL_SAMPLE_COVERAGE_VALUE          = 0x80AA,
	GL_SAMPLE_COVERAGE_INVERT         = 0x80AB,
	GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2,
	GL_COMPRESSED_TEXTURE_FORMATS     = 0x86A3,
	GL_DONT_CARE                      = 0x1100,
	GL_FASTEST                        = 0x1101,
	GL_NICEST                         = 0x1102,
	GL_GENERATE_MIPMAP_HINT           = 0x8192,
	GL_BYTE                           = 0x1400,
	GL_UNSIGNED_BYTE                  = 0x1401,
	GL_SHORT                          = 0x1402,
	GL_UNSIGNED_SHORT                 = 0x1403,
	GL_INT                            = 0x1404,
	GL_UNSIGNED_INT                   = 0x1405,
	GL_FLOAT                          = 0x1406,
	GL_FIXED                          = 0x140C,
	GL_DEPTH_COMPONENT                = 0x1902,
	GL_ALPHA                          = 0x1906,
	GL_RGB                            = 0x1907,
	GL_RGBA                           = 0x1908,
	GL_LUMINANCE                      = 0x1909,
	GL_LUMINANCE_ALPHA                = 0x190A,
	GL_UNSIGNED_SHORT_4_4_4_4         = 0x8033,
	GL_UNSIGNED_SHORT_5_5_5_1         = 0x8034,
	GL_UNSIGNED_SHORT_5_6_5           = 0x8363,
	GL_FRAGMENT_SHADER                = 0x8B30,
	GL_VERTEX_SHADER                  = 0x8B31,
	GL_MAX_VERTEX_ATTRIBS             = 0x8869,
	GL_MAX_VERTEX_UNIFORM_VECTORS     = 0x8DFB,
	GL_MAX_VARYING_VECTORS            = 0x8DFC,
	GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D,
	GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C,
	GL_MAX_TEXTURE_IMAGE_UNITS        = 0x8872,
	GL_MAX_FRAGMENT_UNIFORM_VECTORS   = 0x8DFD,
	GL_SHADER_TYPE                    = 0x8B4F,
	GL_DELETE_STATUS                  = 0x8B80,
	GL_LINK_STATUS                    = 0x8B82,
	GL_VALIDATE_STATUS                = 0x8B83,
	GL_ATTACHED_SHADERS               = 0x8B85,
	GL_ACTIVE_UNIFORMS                = 0x8B86,
	GL_ACTIVE_UNIFORM_MAX_LENGTH      = 0x8B87,
	GL_ACTIVE_ATTRIBUTES              = 0x8B89,
	GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    = 0x8B8A,
	GL_SHADING_LANGUAGE_VERSION       = 0x8B8C,
	GL_CURRENT_PROGRAM                = 0x8B8D,
	GL_NEVER                          = 0x0200,
	GL_LESS                           = 0x0201,
	GL_EQUAL                          = 0x0202,
	GL_LEQUAL                         = 0x0203,
	GL_GREATER                        = 0x0204,
	GL_NOTEQUAL                       = 0x0205,
	GL_GEQUAL                         = 0x0206,
	GL_ALWAYS                         = 0x0207,
	GL_KEEP                           = 0x1E00,
	GL_REPLACE                        = 0x1E01,
	GL_INCR                           = 0x1E02,
	GL_DECR                           = 0x1E03,
	GL_INVERT                         = 0x150A,
	GL_INCR_WRAP                      = 0x8507,
	GL_DECR_WRAP                      = 0x8508,
	GL_VENDOR                         = 0x1F00,
	GL_RENDERER                       = 0x1F01,
	GL_VERSION                        = 0x1F02,
	GL_EXTENSIONS                     = 0x1F03,
	GL_NEAREST                        = 0x2600,
	GL_LINEAR                         = 0x2601,
	GL_NEAREST_MIPMAP_NEAREST         = 0x2700,
	GL_LINEAR_MIPMAP_NEAREST          = 0x2701,
	GL_NEAREST_MIPMAP_LINEAR          = 0x2702,
	GL_LINEAR_MIPMAP_LINEAR           = 0x2703,
	GL_TEXTURE_MAG_FILTER             = 0x2800,
	GL_TEXTURE_MIN_FILTER             = 0x2801,
	GL_TEXTURE_WRAP_S                 = 0x2802,
	GL_TEXTURE_WRAP_T                 = 0x2803,
	GL_TEXTURE                        = 0x1702,
	GL_TEXTURE_CUBE_MAP               = 0x8513,
	GL_TEXTURE_BINDING_CUBE_MAP       = 0x8514,
	GL_TEXTURE_CUBE_MAP_POSITIVE_X    = 0x8515,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_X    = 0x8516,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Y    = 0x8517,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    = 0x8518,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Z    = 0x8519,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    = 0x851A,
	GL_MAX_CUBE_MAP_TEXTURE_SIZE      = 0x851C,
	GL_TEXTURE0                       = 0x84C0,
	GL_TEXTURE1                       = 0x84C1,
	GL_TEXTURE2                       = 0x84C2,
	GL_TEXTURE3                       = 0x84C3,
	GL_TEXTURE4                       = 0x84C4,
	GL_TEXTURE5                       = 0x84C5,
	GL_TEXTURE6                       = 0x84C6,
	GL_TEXTURE7                       = 0x84C7,
	GL_TEXTURE8                       = 0x84C8,
	GL_TEXTURE9                       = 0x84C9,
	GL_TEXTURE10                      = 0x84CA,
	GL_TEXTURE11                      = 0x84CB,
	GL_TEXTURE12                      = 0x84CC,
	GL_TEXTURE13                      = 0x84CD,
	GL_TEXTURE14                      = 0x84CE,
	GL_TEXTURE15                      = 0x84CF,
	GL_TEXTURE16                      = 0x84D0,
	GL_TEXTURE17                      = 0x84D1,
	GL_TEXTURE18                      = 0x84D2,
	GL_TEXTURE19                      = 0x84D3,
	GL_TEXTURE20                      = 0x84D4,
	GL_TEXTURE21                      = 0x84D5,
	GL_TEXTURE22                      = 0x84D6,
	GL_TEXTURE23                      = 0x84D7,
	GL_TEXTURE24                      = 0x84D8,
	GL_TEXTURE25                      = 0x84D9,
	GL_TEXTURE26                      = 0x84DA,
	GL_TEXTURE27                      = 0x84DB,
	GL_TEXTURE28                      = 0x84DC,
	GL_TEXTURE29                      = 0x84DD,
	GL_TEXTURE30                      = 0x84DE,
	GL_TEXTURE31                      = 0x84DF,
	GL_ACTIVE_TEXTURE                 = 0x84E0,
	GL_REPEAT                         = 0x2901,
	GL_CLAMP_TO_EDGE                  = 0x812F,
	GL_MIRRORED_REPEAT                = 0x8370,
	GL_FLOAT_VEC2                     = 0x8B50,
	GL_FLOAT_VEC3                     = 0x8B51,
	GL_FLOAT_VEC4                     = 0x8B52,
	GL_INT_VEC2                       = 0x8B53,
	GL_INT_VEC3                       = 0x8B54,
	GL_INT_VEC4                       = 0x8B55,
	GL_BOOL                           = 0x8B56,
	GL_BOOL_VEC2                      = 0x8B57,
	GL_BOOL_VEC3                      = 0x8B58,
	GL_BOOL_VEC4                      = 0x8B59,
	GL_FLOAT_MAT2                     = 0x8B5A,
	GL_FLOAT_MAT3                     = 0x8B5B,
	GL_FLOAT_MAT4                     = 0x8B5C,
	GL_SAMPLER_2D                     = 0x8B5E,
	GL_SAMPLER_CUBE                   = 0x8B60,
	GL_VERTEX_ATTRIB_ARRAY_ENABLED    = 0x8622,
	GL_VERTEX_ATTRIB_ARRAY_SIZE       = 0x8623,
	GL_VERTEX_ATTRIB_ARRAY_STRIDE     = 0x8624,
	GL_VERTEX_ATTRIB_ARRAY_TYPE       = 0x8625,
	GL_VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A,
	GL_VERTEX_ATTRIB_ARRAY_POINTER    = 0x8645,
	GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F,
	GL_IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A,
	GL_IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B,
	GL_COMPILE_STATUS                 = 0x8B81,
	GL_INFO_LOG_LENGTH                = 0x8B84,
	GL_SHADER_SOURCE_LENGTH           = 0x8B88,
	GL_SHADER_COMPILER                = 0x8DFA,
	GL_SHADER_BINARY_FORMATS          = 0x8DF8,
	GL_NUM_SHADER_BINARY_FORMATS      = 0x8DF9,
	GL_LOW_FLOAT                      = 0x8DF0,
	GL_MEDIUM_FLOAT                   = 0x8DF1,
	GL_HIGH_FLOAT                     = 0x8DF2,
	GL_LOW_INT                        = 0x8DF3,
	GL_MEDIUM_INT                     = 0x8DF4,
	GL_HIGH_INT                       = 0x8DF5,
	GL_FRAMEBUFFER                    = 0x8D40,
	GL_RENDERBUFFER                   = 0x8D41,
	GL_RGBA4                          = 0x8056,
	GL_RGB5_A1                        = 0x8057,
	GL_RGB565                         = 0x8D62,
	GL_DEPTH_COMPONENT16              = 0x81A5,
	GL_STENCIL_INDEX8                 = 0x8D48,
	GL_RENDERBUFFER_WIDTH             = 0x8D42,
	GL_RENDERBUFFER_HEIGHT            = 0x8D43,
	GL_RENDERBUFFER_INTERNAL_FORMAT   = 0x8D44,
	GL_RENDERBUFFER_RED_SIZE          = 0x8D50,
	GL_RENDERBUFFER_GREEN_SIZE        = 0x8D51,
	GL_RENDERBUFFER_BLUE_SIZE         = 0x8D52,
	GL_RENDERBUFFER_ALPHA_SIZE        = 0x8D53,
	GL_RENDERBUFFER_DEPTH_SIZE        = 0x8D54,
	GL_RENDERBUFFER_STENCIL_SIZE      = 0x8D55,
	GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0,
	GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1,
	GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2,
	GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3,
	GL_COLOR_ATTACHMENT0              = 0x8CE0,
	GL_DEPTH_ATTACHMENT               = 0x8D00,
	GL_STENCIL_ATTACHMENT             = 0x8D20,
	GL_NONE                           = 0	  ,
	GL_FRAMEBUFFER_COMPLETE           = 0x8CD5,
	GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6,
	GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7,
	GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 0x8CD9,
	GL_FRAMEBUFFER_UNSUPPORTED        = 0x8CDD,
	GL_FRAMEBUFFER_BINDING            = 0x8CA6,
	GL_RENDERBUFFER_BINDING           = 0x8CA7,
	GL_MAX_RENDERBUFFER_SIZE          = 0x84E8,
	GL_INVALID_FRAMEBUFFER_OPERATION  = 0x0506,
} GL_ENUM;

DLL_PUBLIC void      emu_glActiveTexture		(GL_ENUM texture);
DLL_PUBLIC void      emu_glAttachShader			(uint32 program, uint32 shader);
DLL_PUBLIC void      emu_glBindAttribLocation		(uint32 program, uint32 index, const char *name);
DLL_PUBLIC void      emu_glBindBuffer			(GL_ENUM target, uint32 buffer);
DLL_PUBLIC void      emu_glBindFramebuffer		(GL_ENUM target, uint32 framebuffer);
DLL_PUBLIC void      emu_glBindRenderbuffer		(GL_ENUM target, uint32 renderbuffer);
DLL_PUBLIC void      emu_glBindTexture			(GL_ENUM target, uint32 texture);
DLL_PUBLIC void      emu_glBlendColor			(float red, float green, float blue, float alpha);
DLL_PUBLIC void      emu_glBlendEquation		(GL_ENUM mode);
DLL_PUBLIC void      emu_glBlendEquationSeparate	(GL_ENUM modeRGB, GL_ENUM modeAlpha);
DLL_PUBLIC void      emu_glBlendFunc			(GL_ENUM sfactor, GL_ENUM dfactor);
DLL_PUBLIC void      emu_glBlendFuncSeparate		(GL_ENUM sfactorRGB, GL_ENUM dfactorRGB, GL_ENUM sfactorAlpha, GL_ENUM dfactorAlpha);
DLL_PUBLIC void      emu_glBufferData			(GL_ENUM target, uint32 size, const void *data, GL_ENUM usage);
DLL_PUBLIC void      emu_glBufferSubData		(GL_ENUM target, uint32 offset, uint32 size, const void *data);
DLL_PUBLIC GL_ENUM   emu_glCheckFramebufferStatus	(GL_ENUM target);
DLL_PUBLIC void      emu_glClear			(uint32 mask);
DLL_PUBLIC void      emu_glClearColor			(float red, float green, float blue, float alpha);
DLL_PUBLIC void      emu_glClearDepthf			(float d);
DLL_PUBLIC void      emu_glClearStencil			(sint32 s);
DLL_PUBLIC void      emu_glColorMask			(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
DLL_PUBLIC void      emu_glCompileShader		(uint32 shader);
DLL_PUBLIC void      emu_glCompressedTexImage2D		(GL_ENUM target, sint32 level, GL_ENUM internalformat, uint32 width, uint32 height, sint32 border, uint32 imageSize, const void *data);
DLL_PUBLIC void      emu_glCompressedTexSubImage2D	(GL_ENUM target, sint32 level, sint32 xoffset, sint32 yoffset, uint32 width, uint32 height, GL_ENUM format, uint32 imageSize, const void *data);
DLL_PUBLIC void      emu_glCopyTexImage2D		(GL_ENUM target, sint32 level, GL_ENUM internalformat, sint32 x, sint32 y, uint32 width, uint32 height, sint32 border);
DLL_PUBLIC void      emu_glCopyTexSubImage2D		(GL_ENUM target, sint32 level, sint32 xoffset, sint32 yoffset, sint32 x, sint32 y, uint32 width, uint32 height);
DLL_PUBLIC uint32    emu_glCreateProgram		();
DLL_PUBLIC uint32    emu_glCreateShader			(GL_ENUM type);
DLL_PUBLIC void      emu_glCullFace			(GL_ENUM mode);
DLL_PUBLIC void      emu_glDeleteBuffers		(uint32 n, const uint32 *buffers);
DLL_PUBLIC void      emu_glDeleteFramebuffers		(uint32 n, const uint32 *framebuffers);
DLL_PUBLIC void      emu_glDeleteProgram		(uint32 program);
DLL_PUBLIC void      emu_glDeleteRenderbuffers		(uint32 n, const uint32 *renderbuffers);
DLL_PUBLIC void      emu_glDeleteShader			(uint32 shader);
DLL_PUBLIC void      emu_glDeleteTextures		(uint32 n, const uint32 *textures);
DLL_PUBLIC void      emu_glDepthFunc			(GL_ENUM func);
DLL_PUBLIC void      emu_glDepthMask			(GLboolean flag);
DLL_PUBLIC void      emu_glDepthRangef			(float n, float f);
DLL_PUBLIC void      emu_glDetachShader			(uint32 program, uint32 shader);
DLL_PUBLIC void      emu_glDisable			(GL_ENUM cap);
DLL_PUBLIC void      emu_glDisableVertexAttribArray	(uint32 index);
DLL_PUBLIC void      emu_glDrawArrays			(GL_ENUM mode, sint32 first, uint32 count);
DLL_PUBLIC void      emu_glDrawElements			(GL_ENUM mode, uint32 count, GL_ENUM type, const void *indices);
DLL_PUBLIC void      emu_glEnable			(GL_ENUM cap);
DLL_PUBLIC void      emu_glEnableVertexAttribArray	(uint32 index);
DLL_PUBLIC void      emu_glFinish			();
DLL_PUBLIC void      emu_glFlush			();
DLL_PUBLIC void      emu_glFramebufferRenderbuffer	(GL_ENUM target, GL_ENUM attachment, GL_ENUM renderbuffertarget, uint32 renderbuffer);
DLL_PUBLIC void      emu_glFramebufferTexture2D		(GL_ENUM target, GL_ENUM attachment, GL_ENUM textarget, uint32 texture, sint32 level);
DLL_PUBLIC void      emu_glFrontFace			(GL_ENUM mode);
DLL_PUBLIC void      emu_glGenBuffers			(uint32 n, uint32 *buffers);
DLL_PUBLIC void      emu_glGenerateMipmap		(GL_ENUM target);
DLL_PUBLIC void      emu_glGenFramebuffers		(uint32 n, uint32 *framebuffers);
DLL_PUBLIC void      emu_glGenRenderbuffers		(uint32 n, uint32 *renderbuffers);
DLL_PUBLIC void      emu_glGenTextures			(uint32 n, uint32 *textures);
DLL_PUBLIC void      emu_glGetActiveAttrib		(uint32 program, uint32 index, uint32 bufSize, sint32 *length, sint32 *size, GL_ENUM *type, char *name);
DLL_PUBLIC void      emu_glGetActiveUniform		(uint32 program, uint32 index, uint32 bufSize, sint32 *length, sint32 *size, GL_ENUM *type, char *name);
DLL_PUBLIC void      emu_glGetAttachedShaders		(uint32 program, uint32 maxCount, sint32 *count, uint32 *shaders);
DLL_PUBLIC sint32    emu_glGetAttribLocation		(uint32 program, const char *name);
DLL_PUBLIC void      emu_glGetBooleanv			(GL_ENUM pname, GLboolean *data);
DLL_PUBLIC void      emu_glGetBufferParameteriv		(GL_ENUM target, GL_ENUM pname, sint32 *params);
DLL_PUBLIC GL_ENUM   emu_glGetError			();
DLL_PUBLIC void      emu_glGetFloatv			(GL_ENUM pname, float *data);
DLL_PUBLIC void      emu_glGetFramebufferAttachmentParameteriv (GL_ENUM target, GL_ENUM attachment, GL_ENUM pname, sint32 *params);
DLL_PUBLIC void      emu_glGetIntegerv			(GL_ENUM pname, sint32 *data);
DLL_PUBLIC void      emu_glGetProgramiv			(uint32 program, GL_ENUM pname, sint32 *params);
DLL_PUBLIC void      emu_glGetProgramInfoLog		(uint32 program, uint32 bufSize, uint32 *length, char *infoLog);
DLL_PUBLIC void      emu_glGetRenderbufferParameteriv	(GL_ENUM target, GL_ENUM pname, sint32 *params);
DLL_PUBLIC void      emu_glGetShaderiv			(uint32 shader, GL_ENUM pname, sint32 *params);
DLL_PUBLIC void      emu_glGetShaderInfoLog		(uint32 shader, uint32 bufSize, uint32 *length, char *infoLog);
DLL_PUBLIC void      emu_glGetShaderPrecisionFormat	(GL_ENUM shadertype, GL_ENUM precisiontype, sint32 *range, sint32 *precision);
DLL_PUBLIC void      emu_glGetShaderSource		(uint32 shader, uint32 bufSize, uint32 *length, char *source);
DLL_PUBLIC const GLubyte *emu_glGetString		(GL_ENUM name);
DLL_PUBLIC void      emu_glGetTexParameterfv		(GL_ENUM target, GL_ENUM pname, float *params);
DLL_PUBLIC void      emu_glGetTexParameteriv		(GL_ENUM target, GL_ENUM pname, sint32 *params);
DLL_PUBLIC void      emu_glGetUniformfv			(uint32 program, sint32 location, float *params);
DLL_PUBLIC void      emu_glGetUniformiv			(uint32 program, sint32 location, sint32 *params);
DLL_PUBLIC sint32    emu_glGetUniformLocation		(uint32 program, const char *name);
DLL_PUBLIC void      emu_glGetVertexAttribfv		(uint32 index, GL_ENUM pname, float *params);
DLL_PUBLIC void      emu_glGetVertexAttribiv		(uint32 index, GL_ENUM pname, sint32 *params);
DLL_PUBLIC void      emu_glGetVertexAttribPointerv	(uint32 index, GL_ENUM pname, void **pointer);
DLL_PUBLIC void      emu_glHint				(GL_ENUM target, GL_ENUM mode);
DLL_PUBLIC GLboolean emu_glIsBuffer			(uint32 buffer);
DLL_PUBLIC GLboolean emu_glIsEnabled			(GL_ENUM cap);
DLL_PUBLIC GLboolean emu_glIsFramebuffer		(uint32 framebuffer);
DLL_PUBLIC GLboolean emu_glIsProgram			(uint32 program);
DLL_PUBLIC GLboolean emu_glIsRenderbuffer		(uint32 renderbuffer);
DLL_PUBLIC GLboolean emu_glIsShader			(uint32 shader);
DLL_PUBLIC GLboolean emu_glIsTexture			(uint32 texture);
DLL_PUBLIC void      emu_glLineWidth			(float width);
DLL_PUBLIC void      emu_glLinkProgram			(uint32 program);
DLL_PUBLIC void      emu_glPixelStorei			(GL_ENUM pname, sint32 param);
DLL_PUBLIC void      emu_glPolygonOffset		(float factor, float units);
DLL_PUBLIC void      emu_glReadPixels			(sint32 x, sint32 y, uint32 width, uint32 height, GL_ENUM format, GL_ENUM type, void *pixels);
DLL_PUBLIC void      emu_glReleaseShaderCompiler	();
DLL_PUBLIC void      emu_glRenderbufferStorage		(GL_ENUM target, GL_ENUM internalformat, uint32 width, uint32 height);
DLL_PUBLIC void      emu_glSampleCoverage		(float value, GLboolean invert);
DLL_PUBLIC void      emu_glScissor			(sint32 x, sint32 y, uint32 width, uint32 height);
DLL_PUBLIC void      emu_glShaderBinary			(uint32 count, const uint32 *shaders, GL_ENUM binaryformat, const void *binary, uint32 length);
DLL_PUBLIC void      emu_glShaderSource			(uint32 shader, uint32 count, const char *const*string, const sint32 *length);
DLL_PUBLIC void      emu_glStencilFunc			(GL_ENUM func, sint32 ref, uint32 mask);
DLL_PUBLIC void      emu_glStencilFuncSeparate		(GL_ENUM face, GL_ENUM func, sint32 ref, uint32 mask);
DLL_PUBLIC void      emu_glStencilMask			(uint32 mask);
DLL_PUBLIC void      emu_glStencilMaskSeparate		(GL_ENUM face, uint32 mask);
DLL_PUBLIC void      emu_glStencilOp			(GL_ENUM fail, GL_ENUM zfail, GL_ENUM zpass);
DLL_PUBLIC void      emu_glStencilOpSeparate		(GL_ENUM face, GL_ENUM sfail, GL_ENUM dpfail, GL_ENUM dppass);
DLL_PUBLIC void      emu_glTexImage2D			(GL_ENUM target, sint32 level, sint32 internalformat, uint32 width, uint32 height, sint32 border, GL_ENUM format, GL_ENUM type, const void *pixels);
DLL_PUBLIC void      emu_glTexParameterf		(GL_ENUM target, GL_ENUM pname, float param);
DLL_PUBLIC void      emu_glTexParameterfv		(GL_ENUM target, GL_ENUM pname, const float *params);
DLL_PUBLIC void      emu_glTexParameteri		(GL_ENUM target, GL_ENUM pname, sint32 param);
DLL_PUBLIC void      emu_glTexParameteriv		(GL_ENUM target, GL_ENUM pname, const sint32 *params);
DLL_PUBLIC void      emu_glTexSubImage2D		(GL_ENUM target, sint32 level, sint32 xoffset, sint32 yoffset, uint32 width, uint32 height, GL_ENUM format, GL_ENUM type, const void *pixels);
DLL_PUBLIC void      emu_glUniform1f			(sint32 location, float v0);
DLL_PUBLIC void      emu_glUniform1fv			(sint32 location, uint32 count, const float *value);
DLL_PUBLIC void      emu_glUniform1i			(sint32 location, sint32 v0);
DLL_PUBLIC void      emu_glUniform1iv			(sint32 location, uint32 count, const sint32 *value);
DLL_PUBLIC void      emu_glUniform2f			(sint32 location, float v0, float v1);
DLL_PUBLIC void      emu_glUniform2fv			(sint32 location, uint32 count, const float *value);
DLL_PUBLIC void      emu_glUniform2i			(sint32 location, sint32 v0, sint32 v1);
DLL_PUBLIC void      emu_glUniform2iv			(sint32 location, uint32 count, const sint32 *value);
DLL_PUBLIC void      emu_glUniform3f			(sint32 location, float v0, float v1, float v2);
DLL_PUBLIC void      emu_glUniform3fv			(sint32 location, uint32 count, const float *value);
DLL_PUBLIC void      emu_glUniform3i			(sint32 location, sint32 v0, sint32 v1, sint32 v2);
DLL_PUBLIC void      emu_glUniform3iv			(sint32 location, uint32 count, const sint32 *value);
DLL_PUBLIC void      emu_glUniform4f			(sint32 location, float v0, float v1, float v2, float v3);
DLL_PUBLIC void      emu_glUniform4fv			(sint32 location, uint32 count, const float *value);
DLL_PUBLIC void      emu_glUniform4i			(sint32 location, sint32 v0, sint32 v1, sint32 v2, sint32 v3);
DLL_PUBLIC void      emu_glUniform4iv			(sint32 location, uint32 count, const sint32 *value);
DLL_PUBLIC void      emu_glUniformMatrix2fv		(sint32 location, uint32 count, GLboolean transpose, const float *value);
DLL_PUBLIC void      emu_glUniformMatrix3fv		(sint32 location, uint32 count, GLboolean transpose, const float *value);
DLL_PUBLIC void      emu_glUniformMatrix4fv		(sint32 location, uint32 count, GLboolean transpose, const float *value);
DLL_PUBLIC void      emu_glUseProgram			(uint32 program);
DLL_PUBLIC void      emu_glValidateProgram		(uint32 program);
DLL_PUBLIC void      emu_glVertexAttrib1f		(uint32 index, float x);
DLL_PUBLIC void      emu_glVertexAttrib1fv		(uint32 index, const float *v);
DLL_PUBLIC void      emu_glVertexAttrib2f		(uint32 index, float x, float y);
DLL_PUBLIC void      emu_glVertexAttrib2fv		(uint32 index, const float *v);
DLL_PUBLIC void      emu_glVertexAttrib3f		(uint32 index, float x, float y, float z);
DLL_PUBLIC void      emu_glVertexAttrib3fv		(uint32 index, const float *v);
DLL_PUBLIC void      emu_glVertexAttrib4f		(uint32 index, float x, float y, float z, float w);
DLL_PUBLIC void      emu_glVertexAttrib4fv		(uint32 index, const float *v);
DLL_PUBLIC void      emu_glVertexAttribPointer		(uint32 index, sint32 size, GL_ENUM type, GLboolean normalized, uint32 stride, const void *pointer);
DLL_PUBLIC void      emu_glViewport			(sint32 x, sint32 y, uint32 width, uint32 height);

#ifndef BUILDING_DLL
#define glActiveTexture			emu_glActiveTexture
#define glAttachShader			emu_glAttachShader
#define glBindAttribLocation		emu_glBindAttribLocation
#define glBindBuffer			emu_glBindBuffer
#define glBindFramebuffer		emu_glBindFramebuffer
#define glBindRenderbuffer		emu_glBindRenderbuffer
#define glBindTexture			emu_glBindTexture
#define glBlendColor			emu_glBlendColor
#define glBlendEquation			emu_glBlendEquation
#define glBlendEquationSeparate		emu_glBlendEquationSeparate
#define glBlendFunc			emu_glBlendFunc
#define glBlendFuncSeparate		emu_glBlendFuncSeparate
#define glBufferData			emu_glBufferData
#define glBufferSubData			emu_glBufferSubData
#define glCheckFramebufferStatus	emu_glCheckFramebufferStatus
#define glClear				emu_glClear
#define glClearColor			emu_glClearColor
#define glClearDepthf			emu_glClearDepthf
#define glClearStencil			emu_glClearStencil
#define glColorMask			emu_glColorMask
#define glCompileShader			emu_glCompileShader
#define glCompressedTexImage2D		emu_glCompressedTexImage2D
#define glCompressedTexSubImage2D	emu_glCompressedTexSubImage2D
#define glCopyTexImage2D		emu_glCopyTexImage2D
#define glCopyTexSubImage2D		emu_glCopyTexSubImage2D
#define glCreateProgram			emu_glCreateProgram
#define glCreateShader			emu_glCreateShader
#define glCullFace			emu_glCullFace
#define glDeleteBuffers			emu_glDeleteBuffers
#define glDeleteFramebuffers		emu_glDeleteFramebuffers
#define glDeleteProgram			emu_glDeleteProgram
#define glDeleteRenderbuffers		emu_glDeleteRenderbuffers
#define glDeleteShader			emu_glDeleteShader
#define glDeleteTextures		emu_glDeleteTextures
#define glDepthFunc			emu_glDepthFunc
#define glDepthMask			emu_glDepthMask
#define glDepthRangef			emu_glDepthRangef
#define glDetachShader			emu_glDetachShader
#define glDisable			emu_glDisable
#define glDisableVertexAttribArray	emu_glDisableVertexAttribArray
#define glDrawArrays			emu_glDrawArrays
#define glDrawElements			emu_glDrawElements
#define glEnable			emu_glEnable
#define glEnableVertexAttribArray	emu_glEnableVertexAttribArray
#define glFinish			emu_glFinish
#define glFlush				emu_glFlush
#define glFramebufferRenderbuffer	emu_glFramebufferRenderbuffer
#define glFramebufferTexture2D		emu_glFramebufferTexture2D
#define glFrontFace			emu_glFrontFace
#define glGenBuffers			emu_glGenBuffers
#define glGenerateMipmap		emu_glGenerateMipmap
#define glGenFramebuffers		emu_glGenFramebuffers
#define glGenRenderbuffers		emu_glGenRenderbuffers
#define glGenTextures			emu_glGenTextures
#define glGetActiveAttrib		emu_glGetActiveAttrib
#define glGetActiveUniform		emu_glGetActiveUniform
#define glGetAttachedShaders		emu_glGetAttachedShaders
#define glGetAttribLocation		emu_glGetAttribLocation
#define glGetBooleanv			emu_glGetBooleanv
#define glGetBufferParameteriv		emu_glGetBufferParameteriv
#define glGetError			emu_glGetError
#define glGetFloatv			emu_glGetFloatv
#define glGetFramebufferAttachmentParameteriv emu_glGetFramebufferAttachmentParamteriv
#define glGetIntegerv			emu_glGetIntegerv
#define glGetProgramiv			emu_glGetProgramiv
#define glGetProgramInfoLog		emu_glGetProgramInfoLog
#define glGetRenderbufferParameteriv	emu_glGetRenderbufferParameteriv
#define glGetShaderiv			emu_glGetShaderiv
#define glGetShaderInfoLog		emu_glGetShaderInfoLog
#define glGetShaderPrecisionFormat	emu_glGetShaderPrecisionFormat
#define glGetShaderSource		emu_glGetShaderSource
#define glGetString			emu_glGetString
#define glGetTexParameterfv		emu_glGetTexParameterfv
#define glGetTexParameteriv		emu_glGetTexParameteriv
#define glGetUniformfv			emu_glGetUniformfv
#define glGetUniformiv			emu_glGetUniformiv
#define glGetUniformLocation		emu_glGetUniformLocation
#define glGetVertexAttribfv		emu_glGetVertexAttribfv
#define glGetVertexAttribiv		emu_glGetVertexAttribiv
#define glGetVertexAttribPointerv	emu_glGetVertexAttribPointerv
#define glHint				emu_glHint
#define glIsBuffer			emu_glIsBuffer
#define glIsEnabled			emu_glIsEnabled
#define glIsFramebuffer			emu_glIsFramebuffer
#define glIsProgram			emu_glIsProgram
#define glIsRenderbuffer		emu_glIsRenderbuffer
#define glIsShader			emu_glIsShader
#define glIsTexture			emu_glIsTexture
#define glLineWidth			emu_glLineWidth
#define glLinkProgram			emu_glLinkProgram
#define glPixelStorei			emu_glPixelStorei
#define glPolygonOffset			emu_glPolygonOffset
#define glReadPixels			emu_glReadPixels
#define glReleaseShaderCompiler		emu_glReleaseShaderCompiler
#define glRenderbufferStorage		emu_glRenderbufferStorage
#define glSampleCoverage		emu_glSampleCoverage
#define glScissor			emu_glScissor
#define glShaderBinary			emu_glShaderBinary
#define glShaderSource			emu_glShaderSource
#define glStencilFunc			emu_glStencilFunc
#define glStencilFuncSeparate		emu_glStencilFuncSeparate
#define glStencilMask			emu_glStencilMask
#define glStencilMaskSeparate		emu_glStencilMaskSeparate
#define glStencilOp			emu_glStencilOp
#define glStencilOpSeparate		emu_glStencilOpSeparate
#define glTexImage2D			emu_glTexImage2D
#define glTexParameterf			emu_glTexParameterf
#define glTexParameterfv		emu_glTexParameterfv
#define glTexParameteri			emu_glTexParameteri
#define glTexParameteriv		emu_glTexParameteriv
#define glTexSubImage2D			emu_glTexSubImage2D
#define glUniform1f			emu_glUniform1f
#define glUniform1fv			emu_glUniform1fv
#define glUniform1i			emu_glUniform1i
#define glUniform1iv			emu_glUniform1iv
#define glUniform2f			emu_glUniform2f
#define glUniform2fv			emu_glUniform2fv
#define glUniform2i			emu_glUniform2i
#define glUniform2iv			emu_glUniform2iv
#define glUniform3f			emu_glUniform3f
#define glUniform3fv			emu_glUniform3fv
#define glUniform3i			emu_glUniform3i
#define glUniform3iv			emu_glUniform3iv
#define glUniform4f			emu_glUniform4f
#define glUniform4fv			emu_glUniform4fv
#define glUniform4i			emu_glUniform4i
#define glUniform4iv			emu_glUniform4iv
#define glUniformMatrix2fv		emu_glUniformMatrix2fv
#define glUniformMatrix3fv		emu_glUniformMatrix3fv
#define glUniformMatrix4fv		emu_glUniformMatrix4fv
#define glUseProgram			emu_glUseProgram
#define glValidateProgram		emu_glValidateProgram
#define glVertexAttrib1f		emu_glVertexAttrib1f
#define glVertexAttrib1fv		emu_glVertexAttrib1fv
#define glVertexAttrib2f		emu_glVertexAttrib2f
#define glVertexAttrib2fv		emu_glVertexAttrib2fv
#define glVertexAttrib3f		emu_glVertexAttrib3f
#define glVertexAttrib3fv		emu_glVertexAttrib3fv
#define glVertexAttrib4f		emu_glVertexAttrib4f
#define glVertexAttrib4fv		emu_glVertexAttrib4fv
#define glVertexAttribPointer		emu_glVertexAttribPointer
#define glViewport			emu_glViewport
#endif

#endif // EMULATEDGLES2_H
