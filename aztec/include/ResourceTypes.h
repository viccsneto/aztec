#pragma once

#include <string>
#include "Shader.h"
#include "Rectangle.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
namespace Aztec {

  using namespace std;
  /**
  * RESResource
  *
  * Is the base class of all resources controlled by the ResourceManager class.
  *
  * \author	Vicente Neto
  *
  */
  class RESResource {
  public:
    string path;
    int    ref_count;
    long   age;
    RESResource()
    {
      ref_count = 0;
    }
  };

  /**
  * RESShader
  *
  * Represents a OpenGL shader program
  */
  class RESShader : public RESResource {
  public:
    Shader *shader;
    string  vspath;
    string  fspath;
    RESShader(const GLchar *vs, const GLchar *fs) : RESResource()
    {

      if ((shader = Shader::createFromFiles(vs, fs)) != NULL) {
        vspath.assign(vs);
        fspath.assign(fs);
        path.assign(vspath).append(";").append(fspath);
      }
    }
  };


  /**
  * RESTexture
  *
  * Represents a OpenGL texture resource
  */
  class RESTexture : public RESResource {
  public:
    GLuint texture_id;
    float  originalWidth;
    float  originalHeight;
    float  width;
    float  height;

    RESTexture(float width, float height, float originalWidth, float originalHeight) : RESResource()
    {
      this->width          = width;
      this->height         = height;
      this->originalWidth  = originalWidth;
      this->originalHeight = originalHeight;
    }

    RESTexture() : RESResource()
    {
      width          = 0.0f;
      height         = 0.0;
      originalWidth  = 0.0;
      originalHeight = 0.0f;
      this->texture_id = -1;
    }
  };

  /**
  * RESFont
  *
  * Represents a Font resource
  */
  class RESFont : public RESResource {
  public:
    sf::Glyph charPositions[255];
    float charHeight;
    float charWidth;
    RESTexture *texture;
    RESFont(): RESResource()
    {
      charHeight = 0;
      charWidth  = 0;
    }
  };


  /**
  * RESMusic
  *
  * Represents a music loaded in memory
  */

  class RESMusic : public RESResource {
  public:
    sf::Music *music;
    RESMusic() : music(nullptr)
    {
    }

    ~RESMusic()
    {
      delete this->music;
    }
  };


  /**
  * RESChunk
  *
  * Represents a short sound effect(tipically a .wav file for explosion, lasers and other cool noises)
  */
  class RESChunk : public RESResource {
  public:
    sf::Sound *chunk;
    sf::SoundBuffer *chunk_buffer;
    RESChunk() : chunk(nullptr), chunk_buffer(nullptr)
    {
    }
    ~RESChunk()
    {
      delete this->chunk;
      delete this->chunk_buffer;
    }
  };
} // namespace CppPlay