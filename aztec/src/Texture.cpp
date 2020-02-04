#include "Texture.h"
#include "ResourceManager.h"
namespace Aztec {
  GLuint Texture::DIFFUSE  = 0;
  GLuint Texture::NORMAL   = 1;
  GLuint Texture::TEXTURE0 = 0;
  GLuint Texture::TEXTURE1 = 1;
  GLuint Texture::TEXTURE2 = 2;
  GLuint Texture::TEXTURE3 = 3;
  GLuint Texture::TEXTURE4 = 4;
  GLuint Texture::TEXTURE5 = 5;
  GLuint Texture::TEXTURE6 = 6;
  GLuint Texture::TEXTURE7 = 7;
  GLuint Texture::TEXTURE8 = 8;
  Texture::Texture(const char *path, int width, int height, GLenum internal_format, GLenum format)
  {
    _className.assign("Texture");
    m_texture_data = nullptr;
    m_internal_format = internal_format;
    m_format          = format;
    _texture          = ResourceManager::loadImage(path);
    _texture->width   = width;
    _texture->height  = height;
  }

  Texture::Texture(RESTexture *rtexture, GLenum internal_format, GLenum format)
  {
    m_texture_data = nullptr;
    _className.assign("Texture");
    m_internal_format = internal_format;
    m_format          = format;
    _texture          = rtexture;
    _texture->ref_count++;
  }

  const int Texture::getWidth()
  {
    return _texture->width;
  }
  const int Texture::getHeight()
  {
    return _texture->height;
  }
  const int Texture::getOriginalWidth()
  {
    return _texture->originalWidth;
  }
  const int Texture::getOriginalHeight()
  {
    return _texture->originalHeight;
  }
  const char *Texture::getPath()
  {
    return _texture->path.c_str();
  }

  const unsigned int Texture::getTextureID()
  {
    return _texture->texture_id;
  }

  void Texture::UpdateTexture(const void *data)
  {    
    glBindTexture(GL_TEXTURE_2D, _texture->texture_id);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, (GLsizei)_texture->width, (GLsizei)_texture->height, m_format, GL_UNSIGNED_BYTE, data);
  }

  Texture::~Texture()
  {
    ResourceManager::releaseImage(_texture);
  }
} // namespace Aztec