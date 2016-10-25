/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2016 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

SDL_PROC(void, glActiveTexture, (GLenum))
SDL_PROC(void, glAttachShader, (GLuint, GLuint))
SDL_PROC(void, glBindAttribLocation, (GLuint, GLuint, const char *))
SDL_PROC(void, glBindTexture, (GLenum, GLuint))
SDL_PROC(void, glBlendFuncSeparate, (GLenum, GLenum, GLenum, GLenum))
SDL_PROC(void, glClear, (GLbitfield))
SDL_PROC(void, glClearColor, (GLclampf, GLclampf, GLclampf, GLclampf))
SDL_PROC(void, glCompileShader, (GLuint))
SDL_PROC(GLuint, glCreateProgram, (void))
SDL_PROC(GLuint, glCreateShader, (GLenum))
SDL_PROC(void, glDeleteProgram, (GLuint))
SDL_PROC(void, glDeleteShader, (GLuint))
SDL_PROC(void, glDeleteTextures, (GLsizei, const GLuint *))
SDL_PROC(void, glDisable, (GLenum))
SDL_PROC(void, glDisableVertexAttribArray, (GLuint))
SDL_PROC(void, glDrawArrays, (GLenum, GLint, GLsizei))
SDL_PROC(void, glEnable, (GLenum))
SDL_PROC(void, glEnableVertexAttribArray, (GLuint))
SDL_PROC(void, glFinish, (void))
SDL_PROC(void, glGenFramebuffers, (GLsizei, GLuint *))
SDL_PROC(void, glGenTextures, (GLsizei, GLuint *))
SDL_PROC(void, glGetBooleanv, (GLenum, GLboolean *))
SDL_PROC(const GLubyte *, glGetString, (GLenum))
SDL_PROC(GLenum, glGetError, (void))
SDL_PROC(void, glGetIntegerv, (GLenum, GLint *))
SDL_PROC(void, glGetProgramiv, (GLuint, GLenum, GLint *))
SDL_PROC(void, glGetShaderInfoLog, (GLuint, GLsizei, GLsizei *, char *))
SDL_PROC(void, glGetShaderiv, (GLuint, GLenum, GLint *))
SDL_PROC(GLint, glGetUniformLocation, (GLuint, const char *))
SDL_PROC(void, glLinkProgram, (GLuint))
SDL_PROC(void, glPixelStorei, (GLenum, GLint))
SDL_PROC(void, glReadPixels, (GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid*))
SDL_PROC(void, glScissor, (GLint, GLint, GLsizei, GLsizei))
SDL_PROC(void, glShaderBinary, (GLsizei, const GLuint *, GLenum, const void *, GLsizei))
SDL_PROC(void, glShaderSource, (GLuint, GLsizei, const GLchar* const*, const GLint *))
SDL_PROC(void, glTexImage2D, (GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *))
SDL_PROC(void, glTexParameteri, (GLenum, GLenum, GLint))
SDL_PROC(void, glTexSubImage2D, (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))
SDL_PROC(void, glUniform1i, (GLint, GLint))
SDL_PROC(void, glUniform4f, (GLint, GLfloat, GLfloat, GLfloat, GLfloat))
SDL_PROC(void, glUniformMatrix4fv, (GLint, GLsizei, GLboolean, const GLfloat *))
SDL_PROC(void, glUseProgram, (GLuint))
SDL_PROC(void, glVertexAttribPointer, (GLuint, GLint, GLenum, GLboolean, GLsizei, const void *))
SDL_PROC(void, glViewport, (GLint, GLint, GLsizei, GLsizei))
SDL_PROC(void, glBindFramebuffer, (GLenum, GLuint))
SDL_PROC(void, glFramebufferTexture2D, (GLenum, GLenum, GLenum, GLuint, GLint))
SDL_PROC(GLenum, glCheckFramebufferStatus, (GLenum))
SDL_PROC(void, glDeleteFramebuffers, (GLsizei, const GLuint *))
SDL_PROC(GLint, glGetAttribLocation, (GLuint, const GLchar *))
SDL_PROC(void, glGetProgramInfoLog, (GLuint, GLsizei, GLsizei*, GLchar*))
SDL_PROC(void, glGenBuffers, (GLsizei, GLuint *))
SDL_PROC(void, glBindBuffer, (GLenum, GLuint))
SDL_PROC(void, glBufferData, (GLenum, GLsizeiptr, const GLvoid *, GLenum))
SDL_PROC(void, glBufferSubData, (GLenum, GLintptr, GLsizeiptr, const GLvoid *))
/**
db0@qq.com added at 15.06.29 11:55:39
*/
//#ifdef linux
SDL_PROC(void, glBindRenderbuffer,(GLenum target,  GLuint renderbuffer))
SDL_PROC(void, glClearDepthf,(GLclampf depth))
SDL_PROC(void, glDeleteRenderbuffers,(GLsizei n,  const GLuint * renderbuffers))
SDL_PROC(void, glDepthRangef,(GLclampf nearVal,  GLclampf farVal))
SDL_PROC(void, glFramebufferRenderbuffer,(GLenum target,  GLenum attachment,  GLenum renderbuffertarget,  GLuint renderbuffer))
SDL_PROC(void, glGenRenderbuffers,(GLsizei n,  GLuint * renderbuffers))
SDL_PROC(void, glGenerateMipmap,(GLenum target))
SDL_PROC(void, glGetFramebufferAttachmentParameteriv,(GLenum target,  GLenum attachment,  GLenum pname,  GLint * params))
SDL_PROC(void, glGetRenderbufferParameteriv,(GLenum target,  GLenum pname,  GLint * params))
SDL_PROC(void, glGetShaderPrecisionFormat,(GLenum shaderType,  GLenum precisionType,  GLint *range,  GLint *precision))
SDL_PROC(GLboolean, glIsRenderbuffer,(GLuint renderbuffer))
SDL_PROC(GLboolean, glIsFramebuffer,(GLuint framebuffer))
SDL_PROC(void, glReleaseShaderCompiler,(void))
SDL_PROC(void, glRenderbufferStorage,(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height))
//#endif

//SDL_PROC(void, glBindBuffer,(GLenum target,  GLuint buffer))
SDL_PROC(void, glBlendColor,(GLclampf red,  GLclampf green,  GLclampf blue,  GLclampf alpha))
SDL_PROC(void, glBlendEquation,(GLenum mode))
SDL_PROC(void, glBlendEquationSeparate,(GLenum modeRGB,  GLenum modeAlpha))
SDL_PROC(void, glBlendFunc,(GLenum sfactor,  GLenum dfactor))
//SDL_PROC(void, glBufferData,(GLenum target,  GLsizeiptr size,  const GLvoid * data,  GLenum usage))
//SDL_PROC(void, glBufferSubData,(GLenum target,  GLintptr offset,  GLsizeiptr size,  const GLvoid * data))
SDL_PROC(void, glClearStencil,(GLint s))
SDL_PROC(void, glColorMask,(GLboolean red,  GLboolean green,  GLboolean blue,  GLboolean alpha))
SDL_PROC(void, glCompressedTexImage2D,(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLsizei imageSize,  const GLvoid * data))
SDL_PROC(void, glCompressedTexSubImage2D,(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLsizei imageSize,  const GLvoid * data)) 
SDL_PROC(void, glCopyTexImage2D,(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLsizei height,  GLint border))
SDL_PROC(void, glCopyTexSubImage2D,(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height))
SDL_PROC(void, glCullFace,(GLenum mode))
SDL_PROC(void, glDeleteBuffers,(GLsizei n,  const GLuint * buffers))
SDL_PROC(void, glDepthFunc,(GLenum func))
SDL_PROC(void, glDepthMask,(GLboolean flag))
SDL_PROC(void, glDetachShader,(GLuint program,  GLuint shader))
SDL_PROC(void, glDrawElements,(GLenum mode,  GLsizei count,  GLenum type,  const GLvoid * indices))
SDL_PROC(void, glFlush,( void))
SDL_PROC(void, glFrontFace,(GLenum mode))
//SDL_PROC(void, glGenBuffers,(GLsizei n,  GLuint * buffers))
SDL_PROC(void, glGetFloatv,(GLenum pname,  GLfloat * params))
SDL_PROC(void, glGetActiveAttrib,(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLint *size,  GLenum *type,  char *name))
SDL_PROC(void, glGetActiveUniform,(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLint *size,  GLenum *type,  char *name))
SDL_PROC(void, glGetAttachedShaders,(GLuint program,  GLsizei maxCount,  GLsizei *count,  GLuint *shaders))
SDL_PROC(void, glGetBufferParameteriv,(GLenum target,  GLenum value,  GLint * data))
SDL_PROC(void, glGetShaderSource,(GLuint shader,  GLsizei bufSize,  GLsizei *length,  char *source))
SDL_PROC(void, glGetTexParameterfv,(GLenum target,  GLenum pname,  GLfloat * params)) 
SDL_PROC(void, glGetTexParameteriv,(GLenum target,  GLenum pname,  GLint * params))
SDL_PROC(void, glGetUniformfv,(GLuint program,  GLint location,  GLfloat *params)) 
SDL_PROC(void, glGetUniformiv,(GLuint program,  GLint location,  GLint *params))
SDL_PROC(void, glGetVertexAttribfv,(GLuint index,  GLenum pname,  GLfloat *params))
SDL_PROC(void, glGetVertexAttribiv,(GLuint index,  GLenum pname,  GLint *params))
SDL_PROC(void, glGetVertexAttribPointerv,(GLuint index,  GLenum pname,  GLvoid **pointer))
SDL_PROC(void, glHint,(GLenum target,  GLenum mode))
SDL_PROC(GLboolean, glIsBuffer,(GLuint buffer))
SDL_PROC(GLboolean, glIsEnabled,(GLenum cap))
SDL_PROC(GLboolean, glIsProgram,(GLuint program))
SDL_PROC(GLboolean, glIsShader,(GLuint shader))
SDL_PROC(GLboolean, glIsTexture,(GLuint texture))
SDL_PROC(void, glLineWidth,(GLfloat width))
SDL_PROC(void, glPolygonOffset,(GLfloat factor,  GLfloat units))
SDL_PROC(void, glSampleCoverage,(GLclampf value,  GLboolean invert)) 
SDL_PROC(void, glStencilFunc,(GLenum func,  GLint ref,  GLuint mask))
SDL_PROC(void, glStencilFuncSeparate,(GLenum face,  GLenum func,  GLint ref,  GLuint mask))
SDL_PROC(void, glStencilMask,(GLuint mask))
SDL_PROC(void, glStencilMaskSeparate,(GLenum face,  GLuint mask))
SDL_PROC(void, glStencilOp,(GLenum sfail,  GLenum dpfail,  GLenum dppass))
SDL_PROC(void, glStencilOpSeparate,(GLenum face,  GLenum sfail,  GLenum dpfail,  GLenum dppass))
SDL_PROC(void, glTexParameterf,(GLenum target,  GLenum pname,  GLfloat param)) 
SDL_PROC(void, glUniform1f,(GLint location,  GLfloat v0))
SDL_PROC(void, glUniform2f,(GLint location,  GLfloat v0,  GLfloat v1))
SDL_PROC(void, glUniform3f,(GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2))
SDL_PROC(void, glUniform2i,(GLint location,  GLint v0,  GLint v1))
SDL_PROC(void, glUniform3i,(GLint location,  GLint v0,  GLint v1,  GLint v2))
SDL_PROC(void, glUniform4i,(GLint location,  GLint v0,  GLint v1,  GLint v2,  GLint v3))
SDL_PROC(void, glUniform1fv,(GLint location,  GLsizei count,  const GLfloat *value))
SDL_PROC(void, glUniform2fv,(GLint location,  GLsizei count,  const GLfloat *value))
SDL_PROC(void, glUniform3fv,(GLint location,  GLsizei count,  const GLfloat *value))
SDL_PROC(void, glUniform4fv,(GLint location,  GLsizei count,  const GLfloat *value))
SDL_PROC(void, glUniform1iv,(GLint location,  GLsizei count,  const GLint *value))
SDL_PROC(void, glUniform2iv,(GLint location,  GLsizei count,  const GLint *value))
SDL_PROC(void, glUniform3iv,(GLint location,  GLsizei count,  const GLint *value))
SDL_PROC(void, glUniform4iv,(GLint location,  GLsizei count,  const GLint *value))
SDL_PROC(void, glUniformMatrix2fv,(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value))
SDL_PROC(void, glUniformMatrix3fv,(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value))
//SDL_PROC(void, glUniformMatrix4fv, (GLint, GLsizei, GLboolean, const GLfloat *))
SDL_PROC(void, glValidateProgram,(GLuint program))
SDL_PROC(void, glVertexAttrib1f,(GLuint index,  GLfloat v0))
SDL_PROC(void, glVertexAttrib2f,(GLuint index,  GLfloat v0,  GLfloat v1))
SDL_PROC(void, glVertexAttrib3f,(GLuint index,  GLfloat v0,  GLfloat v1,  GLfloat v2))
SDL_PROC(void, glVertexAttrib4f,(GLuint index,  GLfloat v0,  GLfloat v1,  GLfloat v2,  GLfloat v3))
//SDL_PROC(void, glGetProgramInfoLog,(GLuint program,  GLsizei maxLength,  GLsizei *length,  char *infoLog)) 
SDL_PROC(void, glVertexAttrib1fv,(GLuint index,  const GLfloat *v))
SDL_PROC(void, glVertexAttrib2fv,(GLuint index,  const GLfloat *v))
SDL_PROC(void, glVertexAttrib3fv,(GLuint index,  const GLfloat *v))
SDL_PROC(void, glVertexAttrib4fv,(GLuint index,  const GLfloat *v))
SDL_PROC(void, glTexParameterfv,(GLenum target,  GLenum pname,  const GLfloat * params))
SDL_PROC(void, glTexParameteriv,(GLenum target,  GLenum pname,  const GLint * params))
