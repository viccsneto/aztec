#pragma once

#include <GL/glew.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include <fstream>
#include <string>
#include <cerrno>
#include "LuaBinded.h"

namespace Aztec {
  /**
  * Shader
  *
  * Represents an OpenGL program shader
  *
  * \author	Vicente Neto
  *
  */
  class Shader : public LuaBinded {
  private:
    static Shader *    _defaultShader;
    static Shader *    _stencilShader;
    GLuint             _ProgramID;
    char *             _message;
    void               setMessage(char *msg);
    bool               compileShader(GLuint shaderID);
    static std::string get_file_contents(const char *filename);

  public:
    /**
    * Constructor
    */
    Shader();

    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    ~Shader();

    /**
    * Load
    *
    * Loads the program shader into the OpenGL context
    */
    void Load();

    /**
    * Unload
    *
    * Unloads the program shader (equivalent to glUseProgram(0))
    */
    void Unload();

    /**
    * VertexShader
    *
    * Compiles the Vertex Shader for this program
    *
    * @param source The source code for the vertex shader
    */
    bool VertexShader(const char *source);

    /**
    * FragmentShader
    *
    * Compiles the Fragment Shader for this program
    *
    * @param source The source code for the fragment shader
    */
    bool FragmentShader(const char *source);

    /**
    * Link
    *
    * Links the Vertex and Fragment Shaders for this program
    *
    */
    bool Link();

    /**
    * Validate
    *
    * Checks if any error or warning ocurred during some OpenGL Operation
    */
    bool Validate();

    /**
    * GetMessage
    *
    * Retrieves any error or warning message from OpenGL
    */
    const char *GetMessage();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets an uniform float value in the program shader
    *
    * @param name the uniform name in the program shader
    * @param x a float value that will be assigned to the uniform
    */
    void SetUniform(const char *name, float x);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets uniform vec2 values in the program shader
    *
    * @param name the vec2 uniform name in the program shader
    * @param x a float value that will be assigned to the uniform
    * @param y a float value that will be assigned to the uniform
    */
    void SetUniform(const char *name, float x, float y);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets uniform vec3 values in the program shader
    *
    * @param name the vec3 uniform name in the program shader
    * @param x a float value that will be assigned to the uniform
    * @param y a float value that will be assigned to the uniform
    * @param z a float value that will be assigned to the uniform
    */
    void SetUniform(const char *name, float x, float y, float z);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets uniform vec4 values in the program shader
    *
    * @param name the vec3 uniform name in the program shader
    * @param x a float value that will be assigned to the uniform
    * @param y a float value that will be assigned to the uniform
    * @param z a float value that will be assigned to the uniform
    * @param w a float value that will be assigned to the uniform
    */
    void SetUniform(const char *name, float x, float y, float z, float w);


    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets a float array to an uniform array
    *
    * @param name the uniform name in the program shader
    * @param size the size of each array element
    * @param count the number of elements
    * @param v the array that will be assigned to the uniform
    */
    void SetUniform(const char *name, int size, int count, float *v);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets an uniform int value in the program shader
    *
    * @param name the uniform name in the program shader
    * @param x a int value that will be assigned to the uniform
    */
    void SetUniformI(const char *name, int x);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets uniform vec2 values in the program shader
    *
    * @param name the vec2 uniform name in the program shader
    * @param x a int value that will be assigned to the uniform
    * @param y a int value that will be assigned to the uniform
    */
    void SetUniformI(const char *name, int x, int y);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets uniform vec3 values in the program shader
    *
    * @param name the vec3 uniform name in the program shader
    * @param x a int value that will be assigned to the uniform
    * @param y a int value that will be assigned to the uniform
    * @param z a int value that will be assigned to the uniform
    */
    void SetUniformI(const char *name, int x, int y, int z);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets uniform vec4 values in the program shader
    *
    * @param name the vec4 uniform name in the program shader
    * @param x a int value that will be assigned to the uniform
    * @param y a int value that will be assigned to the uniform
    * @param z a int value that will be assigned to the uniform
    * @param w a int value that will be assigned to the uniform
    */
    void SetUniformI(const char *name, int x, int y, int z, int w);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets an int array to an uniform array
    *
    * @param name the vec3 uniform name in the program shader
    * @param size the size of each array element
    * @param count the number of elements
    * @param v the array that will be assigned to the uniform
    */
    void SetUniformI(const char *name, int size, int count, int *v);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets a float matrix to an uniform matrix
    *
    * @param name the uniform name in the program shader
    * @param row the number of rows of the matrix
    * @param col the number of cols of the matrix
    * @param count the number of elements
    * @param v the matrix that will be assigned to the uniform matrix
    */

    void SetUniformMatrix(const char *name, int row, int col, int count, float *v);


    /**
    * getID
    *
    * Returns the program shader id
    */
    GLint getID();

    /**
    * getDefaultShader
    *
    * Returns the system default shader for rendering images
    * it is used whenever an user shader is missing or fails to compile or when the user just wants to reset the shader of a rendering element
    */

    static Shader *getDefaultShader();

    /**
    * getDefaultShader
    *
    * Returns the system default shader for rendering images
    * it is used whenever an user shader is missing or fails to compile or when the user just wants to reset the shader of a rendering element
    */

    static Shader *createDefaultShader();

    /**
    * getStencilShader
    *
    * Returns the system stencil shader
    * it do not use a texture but only a quad to draw into the stencil buffer
    */
    static Shader *getStencilShader();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Creates a shader program from the specificied source code files
    *
    * @param vextexSourceFile the vertex shader source code path
    * @param fragmentSourceFile the fragment shader source code path
    */
    static Shader *createFromFiles(const GLchar *vextexSourceFile, const GLchar *fragmentSourceFile);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Creates a shader program from the specificied source codes
    *
    * @param vextexSourceCode the vertex shader source code
    * @param fragmentSourceCode the fragment shader source code
    */
    static Shader *createFromSource(const GLchar *vextexSourceCode, const GLchar *fragmentSourceCode);
  };
} // namespace Aztec