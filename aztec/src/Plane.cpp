#include <stdio.h>
#include "Plane.h"

namespace Aztec {
  Plane::Plane(Texture *texture) : Shape(NULL)
  {
    setTexture(0, texture);
  }

  Plane::Plane(Shader *shader, int width, int height, Texture *texture) : Shape(shader)
  {
    _vertex_vbo  = NULL;
    _texture_vbo = NULL;
    _width       = width;
    _height      = height;
    setTexture(0, texture);

    float textureHeight = 1.0f;
    float textureWidth  = 1.0f;

    GLfloat vertices[] = {_width, 0, 0, 0, 0, 0, 0, _height, 0, _width, _height, 0};

    _vertex_vbo = new VertexBufferObject(3, 12, vertices);

    //Sends geometry mesh to the vertex buffer
    _vertex_vbo->bindBuffer(GL_DYNAMIC_DRAW);
    _VAO->addVBO(_vertex_vbo);
    if (_textures[0] != NULL) {
      textureHeight = _textures[0]->getHeight();
      textureWidth  = _textures[0]->getWidth();

      GLfloat textures[] = {_width / textureWidth, 0, 0, 0, 0, _height / textureHeight, _width / textureWidth, _height / textureHeight};

      _texture_vbo = new VertexBufferObject(2, 8, textures);
      //Sends texture coordinates to the vertex buffer
      _texture_vbo->bindBuffer(GL_DYNAMIC_DRAW);

      _VAO->addVBO(_texture_vbo);
    }
    _VAO->generate();
    setDrawMode(GL_TRIANGLE_FAN, 0, 4);
  }

  Plane::~Plane()
  {
    delete _vertex_vbo;
    delete _texture_vbo;
  }
} // namespace Aztec
