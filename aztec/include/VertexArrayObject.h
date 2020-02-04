#pragma once
#include "LuaBinded.h"
#include "VertexBufferObject.h"
#define MAX_VBO_PER_ARRAY 8
namespace Aztec {
  class VertexArrayObject : public LuaBinded {
  public:
    VertexArrayObject();
    ~VertexArrayObject();
    bool                addVBO(VertexBufferObject *vbo);
    VertexBufferObject *getVBO(int idx);
    GLuint              generate();
    GLuint              getId();

  private:
    VertexBufferObject *_vbo[MAX_VBO_PER_ARRAY];
    GLuint              _count;
    GLuint              _id;
  };
} // namespace Aztec