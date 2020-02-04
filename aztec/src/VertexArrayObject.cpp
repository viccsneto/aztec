#include "VertexArrayObject.h"
namespace Aztec {
  VertexArrayObject::VertexArrayObject()
  {
    _className.assign("VertexArrayObject");
    _id    = 0;
    _count = 0;
    for (int i = 0; i < MAX_VBO_PER_ARRAY; i++)
      _vbo[i] = NULL;
  }

  VertexArrayObject::~VertexArrayObject()
  {
    if (_id != 0) {
      glBindVertexArray(_id);
      for (int i = 0; i < _count; i++) {
        glDisableVertexAttribArray(i);
      }
      glDeleteVertexArrays(1, &_id);
    }
  }

  bool VertexArrayObject::addVBO(VertexBufferObject *vbo)
  {
    if (_id != 0 || _count >= MAX_VBO_PER_ARRAY)
      return false;
    _vbo[_count++] = vbo;
    return true;
  }

  GLuint VertexArrayObject::generate()
  {
    if (_id == 0) {
      glGenVertexArrays(1, &_id);
      glBindVertexArray(_id);
      for (int i = 0; i < _count; i++) {
        glBindBuffer(GL_ARRAY_BUFFER, _vbo[i]->getVBO());
        glVertexAttribPointer(i, _vbo[i]->getElementSize(), GL_FLOAT, GL_FALSE, 0, NULL);
      }
      for (int i = 0; i < _count; i++) {
        glEnableVertexAttribArray(i);
      }
    }
    return _id;
  }
  GLuint VertexArrayObject::getId()
  {
    return _id;
  }

  VertexBufferObject *VertexArrayObject::getVBO(int idx)
  {
    if (idx >= MAX_VBO_PER_ARRAY)
      return NULL;
    return _vbo[idx];
  }
} // namespace Aztec