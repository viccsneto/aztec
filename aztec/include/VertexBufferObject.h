#pragma once
#include "LuaBinded.h"
#include <GL/glew.h>
namespace Aztec {
  /**
  * VertexBufferObject
  *
  * Represents a vertex buffer object which is a basic data containe of modern OpenGL programs that will be sent sequentially.
  * It is generally used to store vertex positions, vertex normal values and vertex colors but can store any value that the vertex shader can use with a particular vertex
  *
  * \author	Vicente Neto
  *
  */
  class VertexBufferObject : LuaBinded {
  private:
    GLuint   _vbo;
    GLfloat *_buffer;
    GLuint   _count;
    GLuint   _elementSize;

  public:
    /**
    * <DIV class="ah icona">Lua</DIV>
    * Constructor
    *
    * @param count The number of elements that this vertex buffer object will store
    */
    VertexBufferObject(GLuint count);
    /**
    * <DIV class="ah icona">Lua</DIV>
    * Constructor
    *
    * @param data The array of floats that will be stores in this vertex buffer object
    * @param size The size of each item that will be passed to the shaders
    * @param count The number of floats that this vertex buffer object will store
    */
    VertexBufferObject(GLuint size, GLuint count, GLfloat data[]);

    /**
    * Destructor
    */
    ~VertexBufferObject(void);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Gets the number of elements in this vertex buffer object
    *
    * @return the number of elements in this vertex buffer object
    */
    GLuint getCount();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Gets the id assigned to this vertex buffer object
    *
    * @return the id assigned to this vertex buffer object
    */
    GLuint getVBO();

    /**
    * Gets a pointer to the data assigned to this VBO
    * @return A pointer to the data assigned to this vertex buffer object
    */
    GLfloat *getBuffer();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Gets the memory size of the data assigned to this vertex buffer object
    * @return the memory size of the data assigned to this vertex buffer object
    */
    GLuint getBufferSize();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Gets the memory size of each element in in the VBO
    *
    * @return the memory size of each element
    */
    GLuint getElementSize();

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Binds the buffer with the specified usage method
    *
    * @param usage The usage method that will determine the way this buffer is stored on the GPU
    */

    void bindBuffer(GLenum usage);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Binds the buffer with the default GL_STATIC_DRAW usage method
    */
    void bindBuffer();

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Updates the Buffer
    *
    * @param count The number of elements in the array
    * @param data A pointer to an array of floats representing the data that will be copied to the buffer
    */
    void updateBuffer(GLuint count, GLfloat data[]);
  };

} // namespace Aztec