#pragma once

#include <OpenGL\gl_core_4_4.hpp>
#include "..\Common\Definitions.h"

/* Implements persistent OpenGL buffer with EXPLICIT layout, e.g.
   (std140) Uniform Buffers or (std430) Shader Storage Buffers */
template <GLenum T>
class GLPersistentBuffer {
public:
    GLPersistentBuffer() = delete;
    RULE_OF_FIVE(GLPersistentBuffer);
    // Creates a persistent buffer of specified size
    explicit GLPersistentBuffer(const size_t byte_sz);
    // Returns the pointer to the beginning of the buffer
    void* data();
    // Returns the pointer to the beginning of the buffer (read-only)
    const void* data() const;
    // Binds buffer to buffer binding point
    void bind(const GLuint bind_idx) const;
private:
    void*  m_buffer;     // Pointer used to write to the buffer
    size_t m_byte_sz;    // Buffer size in bytes
    GLuint m_handle;     // Unique OpenGL handle
};

using GLPSB430 = GLPersistentBuffer<gl::SHADER_STORAGE_BUFFER>;
using GLPUB140 = GLPersistentBuffer<gl::UNIFORM_BUFFER>;