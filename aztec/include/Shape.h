#pragma once
#include <GL/glew.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>

#define _USE_MATH_DEFINES
#include <math.h>

#include "LuaBinded.h"
#include "Shader.h"
#include "VertexBufferObject.h"
#include "VertexArrayObject.h"
#include "Texture.h"

#define MAX_TEXTURE_PER_SHAPE 8
namespace Aztec {
  /**
  * Shape
  *
  * The base class for renderable geometric shapes using the array API and shader programs of modern OpenGL
  *
  * \author	Vicente Neto
  *
  */
  class Shape : public LuaBinded {
  private:
    glm::vec4 _color_balance;
    GLuint    _drawmode;
    GLuint    _first;
    GLuint    _count;
    GLboolean _fill;
    void      Init();

  protected:
    GLuint *_indices;

    VertexArrayObject *_VAO = NULL;
    Texture *          _textures[MAX_TEXTURE_PER_SHAPE];
    GLuint             _numIndices;
    Shader *           _shader;

    glm::vec3 _pivot;
    glm::vec3 _translation;
    glm::vec3 _rotation;
    glm::vec3 _postRotation;
    glm::vec3 _scale;

    void updateModel();

  public:
    static const int DRAW_QUADS;
    static const int DRAW_TRIANGLES;
    static const int DRAW_TRIANGLE_FAN;
    static const int DRAW_LINES;
    static const int DRAW_POINTS;

    void setDrawMode(GLuint mode, GLuint first, GLuint count);

    void setFillMode(bool active);
    /**
    * Constructor
    *
    * @param shader The shader program that will be used to draw the shape
    */
    Shape(Shader *shader);

    /**
    * Constructor
    *
    * Uses the default shader program
    */
    Shape();

    /**
    * setShader
    *
    * Sets the shader program that will be used to draw the shape
    *
    * @param shader The shader program that will be assigned to the shape
    */
    Shader *setShader(Shader *shader);

    /**
    * getShader
    *
    * Returns the shader program currently assigned to this shape
    */
    Shader *getShader();

    /**
    * getVAO
    *
    * Returns the vertex array object of this shape
    */
    VertexArrayObject *getVAO();

    /**
    * setVAO
    *
    * Sets the vertex array object of this shape
    */
    VertexArrayObject *setVAO(VertexArrayObject *VAO);
    /**
    * setTranslation
    *
    * Translates the shape to the given coordinates
    *
    * @param x a float representing the x coordinate
    * @param y a float representing the y coordinate
    * @param z a float representing the z coordinate
    */
    void setTranslation(GLfloat x, GLfloat y, GLfloat z);


    /**
    * setPivot
    *
    * Sets the pivot (origin) of the shape
    *
    * @param x a float representing the x coordinate of the pivot
    * @param y a float representing the y coordinate of the pivot
    * @param z a float representing the z coordinate of the pivot
    */
    void setPivot(GLfloat x, GLfloat y, GLfloat z);

    /**
    * setRotation
    *
    * Sets the rotation of the shape
    *
    * @param x a float representing the x rotation value of the shape
    * @param y a float representing the y rotation value of the shape
    * @param z a float representing the z rotation value of the shape
    */

    void setRotation(GLfloat x, GLfloat y, GLfloat z);

    /**
    * setPostRotation
    *
    * Sets the post rotation of the shape (after the translation occurs)
    *
    * @param x a float representing the x post rotation value of the shape
    * @param y a float representing the y post rotation value of the shape
    * @param z a float representing the z post rotation value of the shape
    */
    void setPostRotation(GLfloat x, GLfloat y, GLfloat z);

    /**
    * setScale
    *
    * Scales the shape by the specified dimensions
    *
    * @param x a float representing the x shape scale
    * @param y a float representing the y shape scale
    * @param z a float representing the z shape scale
    */
    void setScale(GLfloat x, GLfloat y, GLfloat z);

    /**
    * setScale
    *
    * Scales the shape in all axis by the specified dimension
    *
    * @param s a float representing the shape scale for all axis
    */
    void setScale(GLfloat s);

    void     setColorBalance(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    Texture *getTexture(GLuint idx);
    Texture *setTexture(GLuint idx, Texture *texture);

    /**
    * Destructor
    */
    virtual ~Shape();

    virtual void Draw();
  };

} // namespace Aztec