#include "VertexBufferObject.h"
#include <memory>
namespace Aztec {
  VertexBufferObject::VertexBufferObject(GLuint count)
  {
    _className.assign("VertexBufferObject");
    _count       = count;
    _buffer      = NULL;
    _elementSize = 1;
    glGenBuffers(1, &_vbo);
  }

  VertexBufferObject::VertexBufferObject(GLuint size, GLuint count, GLfloat data[])
  {
    _count       = count;
    _elementSize = size;
    _buffer      = NULL;
    glGenBuffers(1, &_vbo);
    updateBuffer(count, data);
  }

  VertexBufferObject::~VertexBufferObject(void)
  {
    delete[] _buffer;
  }

  GLuint VertexBufferObject::getCount()
  {
    return _count;
  }
  GLuint VertexBufferObject::getVBO()
  {
    return _vbo;
  }
  GLfloat *VertexBufferObject::getBuffer()
  {
    return _buffer;
  }

  GLuint VertexBufferObject::getBufferSize()
  {
    return _count * sizeof(GLfloat);
  }

  GLuint VertexBufferObject::getElementSize()
  {
    return _elementSize;
  }

  void VertexBufferObject::bindBuffer(GLenum usage)
  {
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, getBufferSize(), _buffer, usage);
  }

  void VertexBufferObject::bindBuffer()
  {
    bindBuffer(GL_STATIC_DRAW);
  }

  void VertexBufferObject::updateBuffer(GLuint count, GLfloat data[])
  {
    _count = count;
    if (_buffer) {
      delete[] _buffer;
    }
    _buffer = new GLfloat[_count]();
    memcpy(_buffer, data, sizeof(GLfloat) * _count);
    bindBuffer();
  }
} // namespace Aztec