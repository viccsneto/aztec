#include "Shader.h"
#include "Config.h"
#include <string>
#include "GameEngine.h"

using namespace std;
namespace Aztec {
  Shader *Shader::_defaultShader = NULL;
  Shader *Shader::_stencilShader = NULL;

#define DEFAULT_VS_SHADER                                                                                                                                                          \
  "#version 130                                                                  \n"                                                                                               \
  "in vec3 vertexPosition;                                                                     \n"                                                                                 \
  "in vec2 texCoord;                                                                           \n"                                                                                 \
  "uniform float texCoordX;                                                                    \n"                                                                                 \
  "uniform float texCoordY;                                                                    \n"                                                                                 \
  "uniform float time;                                                                         \n"                                                                                 \
  "uniform mat4 projectionMatrix,modelMatrix,viewMatrix;                                       \n"                                                                                 \
  "out vec2 texOffset;                                                                         \n"                                                                                 \
  "void main ()                                                                                \n"                                                                                 \
  "{                                                                                           \n"                                                                                 \
  "  gl_Position  = projectionMatrix * viewMatrix * modelMatrix * vec4(vertexPosition, 1);     \n"                                                                                 \
  "  texOffset = texCoord + vec2(texCoordX,texCoordY);                                         \n"                                                                                 \
  "}                                                                                           \n"


#define DEFAULT_FS_SHADER                                                                                                                                                          \
  "#version 130                                                       \n"                                                                                                          \
  "in  vec3 color;                                                                  \n"                                                                                            \
  "in vec2 texOffset;                                                               \n"                                                                                            \
  "out vec4 frag_color;                                                             \n"                                                                                            \
  "uniform vec4 color_balance = vec4(1,1,1,1);                                      \n"                                                                                            \
  "uniform vec4 camera_balance = vec4(1,1,1,1);                                     \n"                                                                                            \
  "uniform sampler2D texture1;                                                      \n"                                                                                            \
  "uniform float time;                                                              \n"                                                                                            \
  "void main()                                                                      \n"                                                                                            \
  "{                                                                                \n"                                                                                            \
  "   frag_color = texture(texture1, texOffset.xy) * color_balance * camera_balance;\n"                                                                                            \
  "}                                                                                \n"


#define STENCIL_FS_SHADER                                                                                                                                                          \
  "#version 130    \n"                                                                                                                                                             \
  "vec4 color=vec4(1,1,1,1);     \n"                                                                                                                                               \
  "out vec4 frag_color;          \n"                                                                                                                                               \
  "void main()                   \n"                                                                                                                                               \
  "{                             \n"                                                                                                                                               \
  "  frag_color = color;         \n"                                                                                                                                               \
  "}                             \n"

  Shader::Shader()
  {
    _className.assign("Shader");
    _message   = NULL;
    _ProgramID = glCreateProgram();
  }

  void Shader::setMessage(char *msg)
  {
    if (_message != NULL) {
      free(_message);
    }

    _message = msg;
  }
  GLint Shader::getID()
  {
    return _ProgramID;
  }
  void Shader::Load()
  {
    glUseProgram(_ProgramID);
  }

  Shader::~Shader()
  {
    glDeleteProgram(_ProgramID);
    free(_message);
  }

  std::string Shader::get_file_contents(const char *filename)
  {
    std::string   contents = "";
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (in) {

      in.seekg(0, std::ios::end);
      contents.resize(in.tellg());
      in.seekg(0, std::ios::beg);
      in.read(&contents[0], contents.size());
      in.close();
      return (contents);
    }
    GameEngine::getInstance()->registerWarning("Erro tentando obter conteudo do arquivo [%s]\n", filename);

    return (contents);
  }

  Shader *Shader::createDefaultShader()
  {
    Shader *default_shader = createFromSource(DEFAULT_VS_SHADER, DEFAULT_FS_SHADER);
    default_shader->SetUniform("texCoordX", 0);
    default_shader->SetUniform("texCoordY", 0);
    default_shader->SetUniform("time", 0);
    return default_shader;
  }


  Shader *Shader::getDefaultShader()
  {
    if (_defaultShader == NULL) {
      _defaultShader = createDefaultShader();
    }
    return _defaultShader;
  }

  Shader *Shader::getStencilShader()
  {
    if (_stencilShader == NULL) {
      _stencilShader = createFromSource(DEFAULT_VS_SHADER, STENCIL_FS_SHADER);
    }
    return _stencilShader;
  }

  Shader *Shader::createFromFiles(const GLchar *vextexSourceFile, const GLchar *fragmentSourceFile)
  {


    if ((vextexSourceFile == NULL) && (fragmentSourceFile == NULL)) {
      return getDefaultShader();
    }
    Shader *shader = new Shader();
    string  vertexShaderSource;
    string  fragmentShaderSource;

    if (vextexSourceFile != NULL) {
      vertexShaderSource = get_file_contents(vextexSourceFile);
    }

    if (vertexShaderSource == "") {
      vertexShaderSource.assign(DEFAULT_VS_SHADER);
    }

    if (fragmentSourceFile != NULL) {
      fragmentShaderSource = get_file_contents(fragmentSourceFile);
    }

    if (fragmentShaderSource == "") {
      fragmentShaderSource.assign(DEFAULT_FS_SHADER);
    }


    if (!shader->VertexShader(vertexShaderSource.c_str())) {
      GameEngine::getInstance()->registerWarning("Nao foi possivel compilar o vertex shader[%s] \n\n%s\n:\n%s\n", vextexSourceFile, vertexShaderSource.c_str(),
                                                 shader->GetMessage());

      delete shader;
      return getDefaultShader();
    }
    else if (!shader->FragmentShader(fragmentShaderSource.c_str())) {
      GameEngine::getInstance()->registerWarning("Nao foi possivel compilar o fragment shader [%s] \n\n%s\n:\n%s\n", fragmentSourceFile, fragmentShaderSource.c_str(),
                                                 shader->GetMessage());

      delete shader;
      return getDefaultShader();
    }
    else if (!shader->Link()) {
      GameEngine::getInstance()->registerWarning("Nao foi possivel linkar o programa de shader[vs:%s , fs:%s]:\n%s\n", vextexSourceFile, fragmentSourceFile, shader->GetMessage());

      delete shader;
      return getDefaultShader();
    }

    return shader;
  }

  Shader *Shader::createFromSource(const GLchar *vextexSourceCode, const GLchar *fragmentSourceCode)
  {
    Shader *shader = new Shader();
    string  vertexShaderSource;
    string  fragmentShaderSource;
    if (vextexSourceCode != NULL) {
      vertexShaderSource.assign(vextexSourceCode);
    }
    else {
      vertexShaderSource.assign(DEFAULT_VS_SHADER);
    }

    if (fragmentSourceCode != NULL) {
      fragmentShaderSource.assign(fragmentSourceCode);
    }
    else {
      fragmentShaderSource.assign(DEFAULT_FS_SHADER);
    }


    if (!shader->VertexShader(vertexShaderSource.c_str())) {
      GameEngine::getInstance()->registerWarning("Nao foi possivel compilar o vertex shader \n\n%s\n:\n%s\n", vertexShaderSource.c_str(), shader->GetMessage());
      delete shader;
      return NULL;
    }
    else if (!shader->FragmentShader(fragmentShaderSource.c_str())) {
      GameEngine::getInstance()->registerWarning("Nao foi possivel compilar o fragment shader \n\n%s\n:\n%s\n", fragmentShaderSource.c_str(), shader->GetMessage());
      delete shader;
      return NULL;
    }
    else if (!shader->Link()) {
      GameEngine::getInstance()->registerWarning("Nao foi possivel linkar o programa de shader\n[\nvs:\n%s\n\nfs:\n%s]:\n%s\n", vextexSourceCode, fragmentSourceCode,
                                                 shader->GetMessage());
      delete shader;
      return NULL;
    }

    return shader;
  }

  void Shader::Unload()
  {
    glUseProgram(0);
  }

  bool Shader::VertexShader(const char *source)
  {
    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &source, 0);
    if (!compileShader(vs)) {
      return false;
    }

    glAttachShader(_ProgramID, vs);
    glDeleteShader(vs);
    return true;
  }

  bool Shader::FragmentShader(const char *source)
  {
    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &source, 0);

    if (!compileShader(fs)) {
      return false;
    }
    glAttachShader(_ProgramID, fs);
    glDeleteShader(fs);

    return true;
  }


  bool Shader::Link()
  {
    GLint status;
    glLinkProgram(_ProgramID);
    glGetProgramiv(_ProgramID, GL_LINK_STATUS, &status);
    if (!status) {
      GLint len;
      glGetProgramiv(_ProgramID, GL_INFO_LOG_LENGTH, &len);
      char *msg = (char *)malloc(len * sizeof(GLchar));
      glGetProgramInfoLog(_ProgramID, len, 0, msg);
      setMessage(msg);
      return false;
    }

    glm::mat4 proj = glm::ortho(0.0f, (float)(Config::SCREEN_WIDTH), (float)(Config::SCREEN_HEIGHT), 0.0f, 0.1f, 1000.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0, 0, 1), //camera is at 0,0,1 in the world space
                                 glm::vec3(0, 0, 0), //looks at the origin
                                 glm::vec3(0, 1, 0)); //head is up. (0,-1,0) to look upside-down.

    SetUniformMatrix("projectionMatrix", 4, 4, 1, glm::value_ptr(proj));
    SetUniformMatrix("viewMatrix", 4, 4, 1, glm::value_ptr(view));
    return true;
  }

  bool Shader::Validate()
  {
    Load();
    GLint status;
    glValidateProgram(_ProgramID);
    glGetProgramiv(_ProgramID, GL_VALIDATE_STATUS, &status);
    if (!status) {
      GLint len;
      glGetProgramiv(_ProgramID, GL_INFO_LOG_LENGTH, &len);
      char *msg = (char *)malloc(len * sizeof(GLchar));
      glGetProgramInfoLog(_ProgramID, len, 0, msg);
      setMessage(msg);
      return false;
    }


    return true;
  }

  const char *GetMessage()
  {
    return NULL;
  }


  void Shader::SetUniform(const char *name, float x)
  {
    Load();
    GLint location = glGetUniformLocation(getID(), name);
    glUniform1f(location, x);
  }

  void Shader::SetUniform(const char *name, float x, float y)
  {
    Load();
    GLint location = glGetUniformLocation(getID(), name);
    glUniform2f(location, x, y);
  }

  void Shader::SetUniform(const char *name, float x, float y, float z)
  {
    Load();
    GLint location = glGetUniformLocation(getID(), name);
    glUniform3f(location, x, y, z);
  }

  void Shader::SetUniform(const char *name, float x, float y, float z, float w)
  {
    Load();
    GLint location = glGetUniformLocation(getID(), name);
    glUniform4f(location, x, y, z, w);
  }

  void Shader::SetUniform(const char *name, int size, int count, float *v)
  {
    Load();
    GLint location = glGetUniformLocation(getID(), name);
    switch (size) {
      case 1:
        glUniform1fv(location, count, v);
        break;
      case 2:
        glUniform2fv(location, count, v);
        break;
      case 3:
        glUniform3fv(location, count, v);
        break;
      case 4:
        glUniform4fv(location, count, v);
        break;
    }
  }

  void Shader::SetUniformI(const char *name, int x)
  {
    Load();
    GLint location = glGetUniformLocation(getID(), name);
    glUniform1i(location, x);
  }

  void Shader::SetUniformI(const char *name, int x, int y)
  {
    Load();
    GLint location = glGetUniformLocation(getID(), name);
    glUniform2i(location, x, y);
  }

  void Shader::SetUniformI(const char *name, int x, int y, int z)
  {
    Load();
    GLint location = glGetUniformLocation(getID(), name);
    glUniform3i(location, x, y, z);
  }

  void Shader::SetUniformI(const char *name, int x, int y, int z, int w)
  {
    Load();
    GLint location = glGetUniformLocation(getID(), name);
    glUniform4i(location, x, y, z, w);
  }

  void Shader::SetUniformI(const char *name, int size, int count, int *v)
  {
    Load();
    GLint location = glGetUniformLocation(getID(), name);
    switch (size) {
      case 1:
        glUniform1iv(location, count, v);
        break;
      case 2:
        glUniform2iv(location, count, v);
        break;
      case 3:
        glUniform3iv(location, count, v);
        break;
      case 4:
        glUniform4iv(location, count, v);
        break;
    }
  }

  void Shader::SetUniformMatrix(const char *name, int row, int col, int count, float *v)
  {
    Load();
    GLint location = glGetUniformLocation(getID(), name);

    if (row == col) {
      switch (col) {
        case 2:
          glUniformMatrix2fv(location, count, GL_FALSE, v);
          break;
        case 3:
          glUniformMatrix3fv(location, count, GL_FALSE, v);
          break;
        case 4:
          glUniformMatrix4fv(location, count, GL_FALSE, v);
          break;
      }
    }
    else if (row == 2) {
      switch (col) {
        case 3:
          glUniformMatrix2x3fv(location, count, GL_FALSE, v);
          break;
        case 4:
          glUniformMatrix2x4fv(location, count, GL_FALSE, v);
          break;
      }
    }
    else if (row == 3) {
      switch (col) {
        case 2:
          glUniformMatrix3x2fv(location, count, GL_FALSE, v);
          break;
        case 4:
          glUniformMatrix3x4fv(location, count, GL_FALSE, v);
          break;
      }
    }
    else if (row == 4) {
      switch (col) {
        case 2:
          glUniformMatrix4x2fv(location, count, GL_FALSE, v);
          break;
        case 3:
          glUniformMatrix4x3fv(location, count, GL_FALSE, v);
          break;
      }
    }
  }

  bool Shader::compileShader(GLuint id)
  {
    GLint status;
    glCompileShader(id);
    glGetShaderiv(id, GL_COMPILE_STATUS, &status);
    if (!status) {
      GLint len;
      glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
      char *msg = (char *)malloc(len * sizeof(GLchar));
      glGetShaderInfoLog(id, len, 0, msg);
      setMessage(msg);
      return false;
    }

    return true;
  }


  const char *Shader::GetMessage()
  {
    return _message;
  }

} // namespace Aztec