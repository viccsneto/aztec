#pragma once
#include "LuaBinded.h"
#include "ResourceTypes.h"

namespace Aztec {
  class Texture : public LuaBinded {
  private:
    RESTexture *_texture;
    GLenum      m_internal_format;
    GLenum      m_format;
    void       *m_texture_data;

  public:
    static GLuint DIFFUSE;
    static GLuint NORMAL;
    static GLuint TEXTURE0;
    static GLuint TEXTURE1;
    static GLuint TEXTURE2;
    static GLuint TEXTURE3;
    static GLuint TEXTURE4;
    static GLuint TEXTURE5;
    static GLuint TEXTURE6;
    static GLuint TEXTURE7;
    static GLuint TEXTURE8;

    Texture(const char *path, int width, int height, GLenum internal_format = GL_RGBA, GLenum format = GL_RGBA);
    Texture(RESTexture *rtexture, GLenum internal_format = GL_RGBA, GLenum format = GL_RGBA);
    const int          getWidth();
    const int          getHeight();
    const int          getOriginalWidth();
    const int          getOriginalHeight();
    const char *       getPath();
    const unsigned int getTextureID();
    void               UpdateTexture(const void *data);

    ~Texture();
  };
} // namespace Aztec