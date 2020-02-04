#include "Shape.h"
#include "GameEngine.h"
namespace Aztec {
  const int Shape::DRAW_QUADS        = GL_QUADS;
  const int Shape::DRAW_TRIANGLES    = GL_TRIANGLES;
  const int Shape::DRAW_TRIANGLE_FAN = GL_TRIANGLE_FAN;
  const int Shape::DRAW_LINES        = GL_LINES;
  const int Shape::DRAW_POINTS       = GL_POINTS;

  void Shape::setColorBalance(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
  {
    _color_balance = glm::vec4(r, g, b, a);
  }
  void Shape::Init()
  {
    _color_balance = glm::vec4(1);
    _fill          = true;
    _indices       = NULL;
    _VAO           = new VertexArrayObject();

    for (int i = 0; i < MAX_TEXTURE_PER_SHAPE; i++) {
      _textures[i] = NULL;
    }
    setScale(1.0f, 1.0f, 1.0f);
    setRotation(0.0f, 0.0f, 0.0f);
    setPostRotation(0.0f, 0.0f, 0.0f);
    setPivot(0.0f, 0.0f, 0.0f);
    setTranslation(0.0f, 0.0f, 0.0f);
  }
  Shape::Shape()
  {
    _className.assign("Shape");
    Init();
    setShader(Shader::getDefaultShader());
  }

  Shape::Shape(Shader *shader)
  {
    _className.assign("Shape");
    Init();
    setShader(shader);
  }

  void Shape::setRotation(GLfloat x, GLfloat y, GLfloat z)
  {
    _rotation = glm::vec3(x, y, z);
  }

  void Shape::setPostRotation(GLfloat x, GLfloat y, GLfloat z)
  {
    _postRotation = glm::vec3(x, y, z);
  }

  void Shape::setScale(GLfloat s)
  {
    setScale(s, s, s);
  }

  void Shape::setScale(GLfloat x, GLfloat y, GLfloat z)
  {
    _scale = glm::vec3(x, y, z);
  }

  void Shape::setTranslation(GLfloat x, GLfloat y, GLfloat z)
  {
    _translation = glm::vec3(x, y, z);
  }

  void Shape::setPivot(GLfloat x, GLfloat y, GLfloat z)
  {
    _pivot = glm::vec3(x, y, z);
  }

  void Shape::updateModel()
  {
    _shader->Load();

    glm::mat4 model = glm::scale(glm::mat4(), glm::vec3(1.0f, 1.0f, 1.0f));
    model           = glm::translate(model, _translation);
    model           = glm::translate(model, -_pivot);

    if (_rotation.z != 0) {
      model = glm::translate(model, _pivot);
      model = glm::rotate(model, _rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
      model = glm::rotate(model, _rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
      model = glm::rotate(model, _rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
      model = glm::translate(model, -_pivot);
    }

    model = glm::rotate(model, _postRotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, _postRotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, _postRotation.z, glm::vec3(0.0f, 0.0f, 1.0f));


    model = glm::scale(model, _scale);

    GameEngine::getInstance()->getCurrentGameState()->getActiveCamera()->updateCameraUniforms(_shader);
    _shader->SetUniformMatrix("modelMatrix", 4, 4, 1, glm::value_ptr(model));
    _shader->SetUniform("color_balance", _color_balance.r, _color_balance.g, _color_balance.b, _color_balance.a);
  }


  Shape::~Shape()
  {
    delete _VAO;
  }


  VertexArrayObject *Shape::getVAO()
  {
    return _VAO;
  }

  Shader *Shape::setShader(Shader *shader)
  {
    if (!shader)
      shader = Shader::getDefaultShader();
    _shader = shader;
    return _shader;
  }

  Shader *Shape::getShader()
  {
    return _shader;
  }

  Texture *Shape::getTexture(GLuint idx)
  {
    return _textures[idx];
  }
  Texture *Shape::setTexture(GLuint idx, Texture *texture)
  {
    if (idx >= MAX_TEXTURE_PER_SHAPE)
      return NULL;
    if (_textures[idx] != texture) {
      if (_textures[idx] != NULL)
        delete _textures[idx];
      _textures[idx] = texture;
    }
    return _textures[idx];
  }

  VertexArrayObject *Shape::setVAO(VertexArrayObject *VAO)
  {
    _VAO = VAO;
    return _VAO;
  }
  void Shape::Draw()
  {
    //Updates modelMatrix
    Shape::updateModel();
    glBindVertexArray(_VAO->getId());

    for (int i = 0; i < MAX_TEXTURE_PER_SHAPE; i++) {
      if (_textures[i] != NULL) {
        glEnable(GL_TEXTURE_2D);
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, _textures[i]->getTextureID());
      }
    }

    if (_fill)
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    else
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glDrawArrays(_drawmode, _first, _count);
    _shader->Unload();
  }

  void Shape::setDrawMode(GLuint mode, GLuint first, GLuint count)
  {
    _drawmode = mode;
    _first    = first;
    _count    = count;
  }
} // namespace Aztec


void Shape::setFillMode(bool active)
{
  _fill = active;
}