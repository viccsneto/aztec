#pragma once
#include "Shape.h"
#include "ResourceTypes.h"

namespace Aztec {
  /**
  * Plane
  *
  * A geometric plane used to render textures/quads through a Shader Program
  *
  * \author	Vicente Neto
  *
  */
  class Plane : public Shape {
  private:
    int                 _width;
    int                 _height;
    VertexBufferObject *_vertex_vbo;
    VertexBufferObject *_texture_vbo;

  public:
    /**
    * Constructor
    *
    * @param shader The shader program that will be used to render this plane
    * @param width The width of this plane
    * @param height The height of this plane
    * @param texture The texture that will be rendered into this plane
    */
    Plane(Shader *shader, int width, int height, Texture *texture);

    /**
    * Constructor
    *
    * @param texture The texture that will be rendered into this plane
    */

    Plane(Texture *texture);
    /**
    * Destructor
    */
    virtual ~Plane();
  };
} // namespace Aztec
