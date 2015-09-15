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

#define BUILDING_DLL 1

#include "emuGLES2.h"

#include "gl_core.h"

DLL_PUBLIC void      emu_glActiveTexture(GL_ENUM texture) {
	glActiveTexture(texture);
}
DLL_PUBLIC void      emu_glAttachShader(uint32 program, uint32 shader) {
	glAttachShader(program, shader);
}
DLL_PUBLIC void      emu_glBindAttribLocation(uint32 program, uint32 index, const char *name) {
	glBindAttribLocation(program, index, name);
}
DLL_PUBLIC void      emu_glBindBuffer(GL_ENUM target, uint32 buffer) {
	glBindBuffer(target, buffer);
}
DLL_PUBLIC void      emu_glBindFramebuffer(GL_ENUM target, uint32 framebuffer) {
	glBindFramebuffer(target, framebuffer);
}
DLL_PUBLIC void      emu_glBindRenderbuffer(GL_ENUM target, uint32 renderbuffer) {
	glBindRenderbuffer(target, renderbuffer);
}
DLL_PUBLIC void      emu_glBindTexture(GL_ENUM target, uint32 texture) {
	glBindTexture(target, texture);
}
DLL_PUBLIC void      emu_glBlendColor(float red, float green, float blue, float alpha) {
	glBlendColor(red, green, blue, alpha);
}
DLL_PUBLIC void      emu_glBlendEquation(GL_ENUM mode) {
	glBlendEquation(mode);
}
DLL_PUBLIC void      emu_glBlendEquationSeparate(GL_ENUM modeRGB, GL_ENUM modeAlpha) {
	glBlendEquationSeparate(modeRGB, modeAlpha);
}
DLL_PUBLIC void      emu_glBlendFunc(GL_ENUM sfactor, GL_ENUM dfactor) {
	glBlendFunc(sfactor, dfactor);
}
DLL_PUBLIC void      emu_glBlendFuncSeparate(GL_ENUM sfactorRGB, GL_ENUM dfactorRGB, GL_ENUM sfactorAlpha, GL_ENUM dfactorAlpha) {
	glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
DLL_PUBLIC void      emu_glBufferData(GL_ENUM target, uint32 size, const void *data, GL_ENUM usage) {
	glBufferData(target, size, data, usage);
}
DLL_PUBLIC void      emu_glBufferSubData(GL_ENUM target, uint32 offset, uint32 size, const void *data) {
	glBufferSubData(target, offset, size, data);
}
DLL_PUBLIC GL_ENUM   emu_glCheckFramebufferStatus(GL_ENUM target) {
	return glCheckFramebufferStatus(target);
}
DLL_PUBLIC void      emu_glClear(uint32 mask) {
	glClear(mask);
}
DLL_PUBLIC void      emu_glClearColor(float red, float green, float blue, float alpha) {
	glClearColor(red, green, blue, alpha);
}
DLL_PUBLIC void      emu_glClearDepthf(float d) {
	glClearDepth(d);
}
DLL_PUBLIC void      emu_glClearStencil(sint32 s) {
	glClearStencil(s);
}
DLL_PUBLIC void      emu_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
	glColorMask(red, green, blue, alpha);
}
DLL_PUBLIC void      emu_glCompileShader(uint32 shader) {
	glCompileShader(shader);
}
DLL_PUBLIC void      emu_glCompressedTexImage2D(GL_ENUM target, sint32 level, GL_ENUM internalformat, uint32 width, uint32 height, sint32 border, uint32 imageSize, const void *data) {
	glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}
DLL_PUBLIC void      emu_glCompressedTexSubImage2D(GL_ENUM target, sint32 level, sint32 xoffset, sint32 yoffset, uint32 width, uint32 height, GL_ENUM format, uint32 imageSize, const void *data) {
	glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
DLL_PUBLIC void      emu_glCopyTexImage2D(GL_ENUM target, sint32 level, GL_ENUM internalformat, sint32 x, sint32 y, uint32 width, uint32 height, sint32 border) {
	glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
DLL_PUBLIC void      emu_glCopyTexSubImage2D(GL_ENUM target, sint32 level, sint32 xoffset, sint32 yoffset, sint32 x, sint32 y, uint32 width, uint32 height) {
	glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
DLL_PUBLIC uint32    emu_glCreateProgram() {
	return glCreateProgram();
}
DLL_PUBLIC uint32    emu_glCreateShader(GL_ENUM type) {
	return glCreateShader(type);
}
DLL_PUBLIC void      emu_glCullFace(GL_ENUM mode) {
	glCullFace(mode);
}
DLL_PUBLIC void      emu_glDeleteBuffers(uint32 n, const uint32 *buffers) {
	glDeleteBuffers(n, buffers);
}
DLL_PUBLIC void      emu_glDeleteFramebuffers(uint32 n, const uint32 *framebuffers) {
	glDeleteFramebuffers(n, framebuffers);
}
DLL_PUBLIC void      emu_glDeleteProgram(uint32 program) {
	glDeleteProgram(program);
}
DLL_PUBLIC void      emu_glDeleteRenderbuffers(uint32 n, const uint32 *renderbuffers) {
	glDeleteRenderbuffers(n, renderbuffers);
}
DLL_PUBLIC void      emu_glDeleteShader(uint32 shader) {
	glDeleteShader(shader);
}
DLL_PUBLIC void      emu_glDeleteTextures(uint32 n, const uint32 *textures) {
	glDeleteTextures(n, textures);
}
DLL_PUBLIC void      emu_glDepthFunc(GL_ENUM func) {
	glDepthFunc(func);
}
DLL_PUBLIC void      emu_glDepthMask(GLboolean flag) {
	glDepthMask(flag);
}
DLL_PUBLIC void      emu_glDepthRangef(float n, float f) {
	glDepthRange(n, f);
}
DLL_PUBLIC void      emu_glDetachShader(uint32 program, uint32 shader) {
	glDetachShader(program, shader);
}
DLL_PUBLIC void      emu_glDisable(GL_ENUM cap) {
	glDisable(cap);
}
DLL_PUBLIC void      emu_glDisableVertexAttribArray(uint32 index) {
	glDisableVertexAttribArray(index);
}
DLL_PUBLIC void      emu_glDrawArrays(GL_ENUM mode, sint32 first, uint32 count) {
	glDrawArrays(mode, first, count);
}
DLL_PUBLIC void      emu_glDrawElements(GL_ENUM mode, uint32 count, GL_ENUM type, const void *indices) {
	glDrawElements(mode, count, type, indices);
}
DLL_PUBLIC void      emu_glEnable(GL_ENUM cap) {
	glEnable(cap);
}
DLL_PUBLIC void      emu_glEnableVertexAttribArray(uint32 index) {
	glEnableVertexAttribArray(index);
}
DLL_PUBLIC void      emu_glFinish() {
	glFinish();
}
DLL_PUBLIC void      emu_glFlush() {
	glFlush();
}
DLL_PUBLIC void      emu_glFramebufferRenderbuffer(GL_ENUM target, GL_ENUM attachment, GL_ENUM renderbuffertarget, uint32 renderbuffer) {
	glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
DLL_PUBLIC void      emu_glFramebufferTexture2D(GL_ENUM target, GL_ENUM attachment, GL_ENUM textarget, uint32 texture, sint32 level) {
	glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
DLL_PUBLIC void      emu_glFrontFace(GL_ENUM mode) {
	glFrontFace(mode);
}
DLL_PUBLIC void      emu_glGenBuffers(uint32 n, uint32 *buffers) {
	glGenBuffers(n, buffers);
}
DLL_PUBLIC void      emu_glGenerateMipmap(GL_ENUM target) {
	glGenerateMipmap(target);
}
DLL_PUBLIC void      emu_glGenFramebuffers(uint32 n, uint32 *framebuffers) {
	glGenFramebuffers(n, framebuffers);
}
DLL_PUBLIC void      emu_glGenRenderbuffers(uint32 n, uint32 *renderbuffers) {
	glGenRenderbuffers(n, renderbuffers);
}
DLL_PUBLIC void      emu_glGenTextures(uint32 n, uint32 *textures) {
	glGenTextures(n, textures);
}
DLL_PUBLIC void      emu_glGetActiveAttrib(uint32 program, uint32 index, uint32 bufSize, sint32 *length, sint32 *size, GL_ENUM *type, char *name) {
	glGetActiveAttrib(program, index, bufSize, length, size, (GLenum*)type, name);
}
DLL_PUBLIC void      emu_glGetActiveUniform(uint32 program, uint32 index, uint32 bufSize, sint32 *length, sint32 *size, GL_ENUM *type, char *name) {
	glGetActiveUniform(program, index, bufSize, length, size, (GLenum*)type, name);
}
DLL_PUBLIC void      emu_glGetAttachedShaders(uint32 program, uint32 maxCount, sint32 *count, uint32 *shaders) {
	glGetAttachedShaders(program, maxCount, count, shaders);
}
DLL_PUBLIC sint32    emu_glGetAttribLocation(uint32 program, const char *name) {
	return glGetAttribLocation(program, name);
}
DLL_PUBLIC void      emu_glGetBooleanv(GL_ENUM pname, GLboolean *data) {
	glGetBooleanv(pname, data);
}
DLL_PUBLIC void      emu_glGetBufferParameteriv(GL_ENUM target, GL_ENUM pname, sint32 *params) {
	glGetBufferParameteriv(target, pname, params);
}
DLL_PUBLIC GL_ENUM   emu_glGetError() {
	return glGetError();
}
DLL_PUBLIC void      emu_glGetFloatv(GL_ENUM pname, float *data) {
	glGetFloatv(pname, data);
}
DLL_PUBLIC void      emu_glGetFramebufferAttachmentParameteriv(GL_ENUM target, GL_ENUM attachment, GL_ENUM pname, sint32 *params) {
	glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
DLL_PUBLIC void      emu_glGetIntegerv(GL_ENUM pname, sint32 *data) {
	glGetIntegerv(pname, data);
}
DLL_PUBLIC void      emu_glGetProgramiv(uint32 program, GL_ENUM pname, sint32 *params) {
	glGetProgramiv(program, pname, params);
}
DLL_PUBLIC void      emu_glGetProgramInfoLog(uint32 program, uint32 bufSize, uint32 *length, char *infoLog) {
	glGetProgramInfoLog(program, bufSize, length, infoLog);
}
DLL_PUBLIC void      emu_glGetRenderbufferParameteriv(GL_ENUM target, GL_ENUM pname, sint32 *params) {
	glGetRenderbufferParameteriv(target, pname, params);
}
DLL_PUBLIC void      emu_glGetShaderiv(uint32 shader, GL_ENUM pname, sint32 *params) {
	glGetShaderiv(shader, pname, params);
}
DLL_PUBLIC void      emu_glGetShaderInfoLog(uint32 shader, uint32 bufSize, uint32 *length, char *infoLog) {
	glGetShaderInfoLog(shader, bufSize, length, infoLog);
}
DLL_PUBLIC void      emu_glGetShaderPrecisionFormat(GL_ENUM shadertype, GL_ENUM precisiontype, sint32 *range, sint32 *precision) {
	if (range ) *range = 0;
	if (precision) *precision = 0;
	return; /*glGetShaderPrecisionFormat	(shadertype, precisiontype, range, precision);*/
}
DLL_PUBLIC void      emu_glGetShaderSource(uint32 shader, uint32 bufSize, uint32 *length, char *source) {
	glGetShaderSource(shader, bufSize, length, source);
}
DLL_PUBLIC const GLubyte *emu_glGetString(GL_ENUM name) {
	return glGetString(name);
}
DLL_PUBLIC void      emu_glGetTexParameterfv(GL_ENUM target, GL_ENUM pname, float *params) {
	glGetTexParameterfv(target, pname, params);
}
DLL_PUBLIC void      emu_glGetTexParameteriv(GL_ENUM target, GL_ENUM pname, sint32 *params) {
	glGetTexParameteriv(target, pname, params);
}
DLL_PUBLIC void      emu_glGetUniformfv(uint32 program, sint32 location, float *params) {
	glGetUniformfv(program, location, params);
}
DLL_PUBLIC void      emu_glGetUniformiv(uint32 program, sint32 location, sint32 *params) {
	glGetUniformiv(program, location, params);
}
DLL_PUBLIC sint32    emu_glGetUniformLocation(uint32 program, const char *name) {
	return glGetUniformLocation(program, name);
}
DLL_PUBLIC void      emu_glGetVertexAttribfv(uint32 index, GL_ENUM pname, float *params) {
	glGetVertexAttribfv(index, pname, params);
}
DLL_PUBLIC void      emu_glGetVertexAttribiv(uint32 index, GL_ENUM pname, sint32 *params) {
	glGetVertexAttribiv(index, pname, params);
}
DLL_PUBLIC void      emu_glGetVertexAttribPointerv(uint32 index, GL_ENUM pname, void **pointer) {
	glGetVertexAttribPointerv(index, pname, pointer);
}
DLL_PUBLIC void      emu_glHint(GL_ENUM target, GL_ENUM mode) {
	glHint(target, mode);
}
DLL_PUBLIC GLboolean emu_glIsBuffer(uint32 buffer) {
	return glIsBuffer(buffer);
}
DLL_PUBLIC GLboolean emu_glIsEnabled(GL_ENUM cap) {
	return glIsEnabled(cap);
}
DLL_PUBLIC GLboolean emu_glIsFramebuffer(uint32 framebuffer) {
	return glIsFramebuffer(framebuffer);
}
DLL_PUBLIC GLboolean emu_glIsProgram(uint32 program) {
	return glIsProgram(program);
}
DLL_PUBLIC GLboolean emu_glIsRenderbuffer(uint32 renderbuffer) {
	return glIsRenderbuffer(renderbuffer);
}
DLL_PUBLIC GLboolean emu_glIsShader(uint32 shader) {
	return glIsShader(shader);
}
DLL_PUBLIC GLboolean emu_glIsTexture(uint32 texture) {
	return glIsTexture(texture);
}
DLL_PUBLIC void      emu_glLineWidth(float width) {
	glLineWidth(width);
}
DLL_PUBLIC void      emu_glLinkProgram(uint32 program) {
	glLinkProgram(program);
}
DLL_PUBLIC void      emu_glPixelStorei(GL_ENUM pname, sint32 param) {
	glPixelStorei(pname, param);
}
DLL_PUBLIC void      emu_glPolygonOffset(float factor, float units) {
	glPolygonOffset(factor, units);
}
DLL_PUBLIC void      emu_glReadPixels(sint32 x, sint32 y, uint32 width, uint32 height, GL_ENUM format, GL_ENUM type, void *pixels) {
	glReadPixels(x, y, width, height, format, type, pixels);
}
DLL_PUBLIC void      emu_glReleaseShaderCompiler() {
	/*glReleaseShaderCompiler	();*/
}
DLL_PUBLIC void      emu_glRenderbufferStorage(GL_ENUM target, GL_ENUM internalformat, uint32 width, uint32 height) {
	glRenderbufferStorage(target, internalformat, width, height);
}
DLL_PUBLIC void      emu_glSampleCoverage(float value, GLboolean invert) {
	glSampleCoverage(value, invert);
}
DLL_PUBLIC void      emu_glScissor(sint32 x, sint32 y, uint32 width, uint32 height) {
	glScissor(x, y, width, height);
}
DLL_PUBLIC void      emu_glShaderBinary(uint32 count, const uint32 *shaders, GL_ENUM binaryformat, const void *binary, uint32 length) {
	/*glShaderBinary		(count, shaders, binaryformat, binary, length);*/
}
DLL_PUBLIC void      emu_glShaderSource(uint32 shader, uint32 count, const char *const*string, const sint32 *length) {
	glShaderSource(shader, count, string, length);
}
DLL_PUBLIC void      emu_glStencilFunc(GL_ENUM func, sint32 ref, uint32 mask) {
	glStencilFunc(func, ref, mask);
}
DLL_PUBLIC void      emu_glStencilFuncSeparate(GL_ENUM face, GL_ENUM func, sint32 ref, uint32 mask) {
	glStencilFuncSeparate(face, func, ref, mask);
}
DLL_PUBLIC void      emu_glStencilMask(uint32 mask) {
	glStencilMask(mask);
}
DLL_PUBLIC void      emu_glStencilMaskSeparate(GL_ENUM face, uint32 mask) {
	glStencilMaskSeparate(face, mask);
}
DLL_PUBLIC void      emu_glStencilOp(GL_ENUM fail, GL_ENUM zfail, GL_ENUM zpass) {
	glStencilOp(fail, zfail, zpass);
}
DLL_PUBLIC void      emu_glStencilOpSeparate(GL_ENUM face, GL_ENUM sfail, GL_ENUM dpfail, GL_ENUM dppass) {
	glStencilOpSeparate(face, sfail, dpfail, dppass);
}
DLL_PUBLIC void      emu_glTexImage2D(GL_ENUM target, sint32 level, sint32 internalformat, uint32 width, uint32 height, sint32 border, GL_ENUM format, GL_ENUM type, const void *pixels) {
	glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}
DLL_PUBLIC void      emu_glTexParameterf(GL_ENUM target, GL_ENUM pname, float param) {
	glTexParameterf(target, pname, param);
}
DLL_PUBLIC void      emu_glTexParameterfv(GL_ENUM target, GL_ENUM pname, const float *params) {
	glTexParameterfv(target, pname, params);
}
DLL_PUBLIC void      emu_glTexParameteri(GL_ENUM target, GL_ENUM pname, sint32 param) {
	glTexParameteri(target, pname, param);
}
DLL_PUBLIC void      emu_glTexParameteriv(GL_ENUM target, GL_ENUM pname, const sint32 *params) {
	glTexParameteriv(target, pname, params);
}
DLL_PUBLIC void      emu_glTexSubImage2D(GL_ENUM target, sint32 level, sint32 xoffset, sint32 yoffset, uint32 width, uint32 height, GL_ENUM format, GL_ENUM type, const void *pixels) {
	glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
DLL_PUBLIC void      emu_glUniform1f(sint32 location, float v0) {
	glUniform1f(location, v0);
}
DLL_PUBLIC void      emu_glUniform1fv(sint32 location, uint32 count, const float *value) {
	glUniform1fv(location, count, value);
}
DLL_PUBLIC void      emu_glUniform1i(sint32 location, sint32 v0) {
	glUniform1i(location, v0);
}
DLL_PUBLIC void      emu_glUniform1iv(sint32 location, uint32 count, const sint32 *value) {
	glUniform1iv(location, count, value);
}
DLL_PUBLIC void      emu_glUniform2f(sint32 location, float v0, float v1) {
	glUniform2f(location, v0, v1);
}
DLL_PUBLIC void      emu_glUniform2fv(sint32 location, uint32 count, const float *value) {
	glUniform2fv(location, count, value);
}
DLL_PUBLIC void      emu_glUniform2i(sint32 location, sint32 v0, sint32 v1) {
	glUniform2i(location, v0, v1);
}
DLL_PUBLIC void      emu_glUniform2iv(sint32 location, uint32 count, const sint32 *value) {
	glUniform2iv(location, count, value);
}
DLL_PUBLIC void      emu_glUniform3f(sint32 location, float v0, float v1, float v2) {
	glUniform3f(location, v0, v1, v2);
}
DLL_PUBLIC void      emu_glUniform3fv(sint32 location, uint32 count, const float *value) {
	glUniform3fv(location, count, value);
}
DLL_PUBLIC void      emu_glUniform3i(sint32 location, sint32 v0, sint32 v1, sint32 v2) {
	glUniform3i(location, v0, v1, v2);
}
DLL_PUBLIC void      emu_glUniform3iv(sint32 location, uint32 count, const sint32 *value) {
	glUniform3iv(location, count, value);
}
DLL_PUBLIC void      emu_glUniform4f(sint32 location, float v0, float v1, float v2, float v3) {
	glUniform4f(location, v0, v1, v2, v3);
}
DLL_PUBLIC void      emu_glUniform4fv(sint32 location, uint32 count, const float *value) {
	glUniform4fv(location, count, value);
}
DLL_PUBLIC void      emu_glUniform4i(sint32 location, sint32 v0, sint32 v1, sint32 v2, sint32 v3) {
	glUniform4i(location, v0, v1, v2, v3);
}
DLL_PUBLIC void      emu_glUniform4iv(sint32 location, uint32 count, const sint32 *value) {
	glUniform4iv(location, count, value);
}
DLL_PUBLIC void      emu_glUniformMatrix2fv(sint32 location, uint32 count, GLboolean transpose, const float *value) {
	glUniformMatrix2fv(location, count, transpose, value);
}
DLL_PUBLIC void      emu_glUniformMatrix3fv(sint32 location, uint32 count, GLboolean transpose, const float *value) {
	glUniformMatrix3fv(location, count, transpose, value);
}
DLL_PUBLIC void      emu_glUniformMatrix4fv(sint32 location, uint32 count, GLboolean transpose, const float *value) {
	glUniformMatrix4fv(location, count, transpose, value);
}
DLL_PUBLIC void      emu_glUseProgram(uint32 program) {
	glUseProgram(program);
}
DLL_PUBLIC void      emu_glValidateProgram(uint32 program) {
	glValidateProgram(program);
}
DLL_PUBLIC void      emu_glVertexAttrib1f(uint32 index, float x) {
	glVertexAttrib1f(index, x);
}
DLL_PUBLIC void      emu_glVertexAttrib1fv(uint32 index, const float *v) {
	glVertexAttrib1fv(index, v);
}
DLL_PUBLIC void      emu_glVertexAttrib2f(uint32 index, float x, float y) {
	glVertexAttrib2f(index, x, y);
}
DLL_PUBLIC void      emu_glVertexAttrib2fv(uint32 index, const float *v) {
	glVertexAttrib2fv(index, v);
}
DLL_PUBLIC void      emu_glVertexAttrib3f(uint32 index, float x, float y, float z) {
	glVertexAttrib3f(index, x, y, z);
}
DLL_PUBLIC void      emu_glVertexAttrib3fv(uint32 index, const float *v) {
	glVertexAttrib3fv(index, v);
}
DLL_PUBLIC void      emu_glVertexAttrib4f(uint32 index, float x, float y, float z, float w) {
	glVertexAttrib4f(index, x, y, z, w);
}
DLL_PUBLIC void      emu_glVertexAttrib4fv(uint32 index, const float *v) {
	glVertexAttrib4fv(index, v);
}
DLL_PUBLIC void      emu_glVertexAttribPointer(uint32 index, sint32 size, GL_ENUM type, GLboolean normalized, uint32 stride, const void *pointer) {
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
DLL_PUBLIC void      emu_glViewport(sint32 x, sint32 y, uint32 width, uint32 height) {
	glViewport(x, y, width, height);
}
