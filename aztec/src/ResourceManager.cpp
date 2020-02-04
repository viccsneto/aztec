#include "ResourceManager.h"
#include "EventDispatcher.h"
#include "GameEngine.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Keyboard.h"

#define CHARACTERS_PER_LINE 16
#define CHARACTER_BORDER_WIDTH 8
#define FONT_DEFINITION_FORMAT_STRING "%s_%d"



namespace Aztec {
  list<RESFont *>    ResourceManager::_Fonts;
  list<RESTexture *> ResourceManager::_Surfaces;
  list<RESShader *>  ResourceManager::_Shaders;
  list<RESMusic *>   ResourceManager::_Musics;
  list<RESChunk *>   ResourceManager::_Chunks;

  multimap<GameObject *, list<GameObject *> *> ResourceManager::_toDestroy;
  multimap<GameObject *, list<GameObject *> *> ResourceManager::_toRemove;

  RESTexture *ResourceManager::createTexture(int width, int height, void *data)
  {
    GameEngine::getInstance()->getGameCanvas()->activateContext();
    GLenum texture_format = GL_RGBA;
    GLint  nOfColors      = 4;


    GLint originalWidth;
    GLint originalHeight;


    originalWidth  = width;
    originalHeight = height;

    
    RESTexture *rsurface = new RESTexture();

    for (GLuint i = 0; width < originalWidth; i++) {
      width = static_cast<int>(powl(2, i));
    }

    for (GLuint i = 0; height < originalHeight; i++) {
      height = static_cast<int>(powl(2, i));
    }


    GLuint texture;
    // Have OpenGL generate a texture object handle for us
    glGenTextures(1, &texture);
    // Bind the texture object
    glBindTexture(GL_TEXTURE_2D, texture);

    // Set the texture's stretching properties
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // Edit the texture object's image data using the information SDL_Surface gives us
    glTexImage2D(GL_TEXTURE_2D, 0, texture_format, width, height, 0, texture_format, GL_UNSIGNED_BYTE, data);


    rsurface->texture_id     = texture;
    rsurface->originalWidth  = static_cast<float>(originalWidth);
    rsurface->originalHeight = static_cast<float>(originalHeight);
    rsurface->width          = width;
    rsurface->height         = height;

    return rsurface;
  }


  RESTexture *ResourceManager::loadImage(const char *path)
  {
    RESTexture *rsurface;

    GLint originalWidth;
    GLint originalHeight;
    GLint channels;
    GLint width  = 0;
    GLint height = 0;


    for (list<RESTexture *>::iterator i = _Surfaces.begin(); i != _Surfaces.end(); ++i) {
      if ((*i)->path.compare(path) == 0) {
        (*i)->ref_count++;

        return (*i);
      }
    }

    auto image = new sf::Image();

    if (!image->loadFromFile(std::string(path))) {
      GameEngine::getInstance()->registerError("Image could not be loaded: %s -<%s [%d]>", path, __FILE__, __LINE__);
      return NULL;
    }


    originalWidth  = image->getSize().x;
    originalHeight = image->getSize().y;
    channels       = 4;

    width  = originalWidth;
    height = originalHeight;

    for (GLuint i = 0; width < originalWidth; i++) {
      width = static_cast<int>(powl(2, i));
    }

    for (GLuint i = 0; height < originalHeight; i++) {
      height = static_cast<int>(powl(2, i));
    }


    if (image) {
      rsurface = putImage(path, image->getPixelsPtr(), width, height, originalWidth, originalHeight, channels);
      return rsurface;
    }
  }


  RESTexture *ResourceManager::putImage(const char *path, const sf::Uint8 *data, int width, int height, int originalWidth, int originalHeight, int channels)
  {

    GameEngine::getInstance()->getGameCanvas()->activateContext();

    RESTexture *rsurface;

    GLenum texture_format = GL_RGBA;
    GLint  nOfColors      = 4;
    GLuint texture        = 0;

    for (list<RESTexture *>::iterator i = _Surfaces.begin(); i != _Surfaces.end(); ++i) {
      if ((*i)->path.compare(path) == 0) {
        (*i)->ref_count++;
        return (*i);
      }
    }

    rsurface = new RESTexture();

    rsurface->originalWidth  = originalWidth;
    rsurface->originalHeight = originalHeight;

    rsurface->width  = width;
    rsurface->height = height;


    // get the number of channels in the SDL surface
    if (channels == 4) // contains an alpha channel
    {
      texture_format = GL_RGBA;
    }
    else if (channels == 3) // no alpha channel
    {
      texture_format = GL_RGB;
    }
    else {
      GameEngine::getInstance()->registerWarning("warning: the image %s is not truecolor..  this will probably break\n", path);
    }

    if (data != NULL) {
      glEnable(GL_TEXTURE_2D);

      // Have OpenGL generate a texture object handle for us
      glGenTextures(1, &texture);

      if (texture == 0) {
        GLenum err = glGetError();
        throw err;
      }

      // Bind the texture object
      glBindTexture(GL_TEXTURE_2D, texture);

      // Set the texture's stretching properties
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

      // Edit the texture object's image data using the information SDL_Surface gives us
      glTexImage2D(GL_TEXTURE_2D, 0, texture_format, originalWidth, originalHeight, 0, texture_format, GL_UNSIGNED_BYTE, data);

      glBindTexture(GL_TEXTURE_2D, 0);

      rsurface->texture_id = texture;

      if (rsurface->texture_id == 0) {
        delete rsurface;
        return NULL;
      }
    }

    rsurface->path.assign(path);
    rsurface->ref_count  = 1;
    _Surfaces.push_front(rsurface);
    rsurface->originalWidth  = static_cast<float>(originalWidth);
    rsurface->originalHeight = static_cast<float>(originalHeight);

    return rsurface;
  }

  void ResourceManager::releaseImage(const char *path)
  {
    for (list<RESTexture *>::iterator i = _Surfaces.begin(); i != _Surfaces.end(); ++i) {
      if ((*i)->path.compare(path) == 0) {
        (*i)->ref_count--;
        if ((*i)->ref_count == 0) {
          glDeleteTextures(1, &(*i)->texture_id);
          delete ((*i));
          _Surfaces.remove((*i));
        }
        return;
      }
    }
  }

  void ResourceManager::releaseImage(RESTexture *surface)
  {
    for (list<RESTexture *>::iterator i = _Surfaces.begin(); i != _Surfaces.end(); ++i) {
      if ((*i) == surface) {
        (*i)->ref_count--;
        if ((*i)->ref_count == 0) {
          glDeleteTextures(1, &(*i)->texture_id);
          delete ((*i));
          _Surfaces.remove((*i));
        }
        return;
      }
    }
  }

  sf::Music *ResourceManager::loadMusic(const char *path)
  {
    for (list<RESMusic *>::iterator i = _Musics.begin(); i != _Musics.end(); ++i) {
      if ((*i)->path.compare(path) == 0) {
        (*i)->ref_count++;
        return (*i)->music;
      }
    }

    RESMusic *rmusic = new RESMusic();

    rmusic->music = new sf::Music();
    rmusic->music->openFromFile(std::string(path));

    if (rmusic->music == NULL) {
      delete rmusic;
      return NULL;
    }

    rmusic->path.assign(path);

    rmusic->ref_count = 1;
    _Musics.push_front(rmusic);
    return rmusic->music;
  }

  sf::Sound *ResourceManager::loadChunk(const char *path)
  {

    for (list<RESChunk *>::iterator i = _Chunks.begin(); i != _Chunks.end(); ++i) {
      if ((*i)->path.compare(path) == 0) {
        (*i)->ref_count++;
        return (*i)->chunk;
      }
    }
    RESChunk *rchunk = new RESChunk();

    rchunk->chunk                 = new sf::Sound();
    sf::SoundBuffer *sound_buffer = new sf::SoundBuffer();
    sound_buffer->loadFromFile(std::string(path));

    rchunk->chunk->setBuffer(*sound_buffer);
    rchunk->chunk_buffer = sound_buffer;
    if (rchunk->chunk == NULL) {
      delete rchunk;
      return NULL;
    }

    rchunk->path.assign(path);

    rchunk->ref_count = 1;
    _Chunks.push_front(rchunk);
    return rchunk->chunk;
  }

  RESFont *ResourceManager::loadFont(const char *path, glm::vec4 color, int size)
  {
    size_t font_definition_size  = snprintf(nullptr, 0, FONT_DEFINITION_FORMAT_STRING, path, size);
    char * fontDefinition = new char[font_definition_size];

    sprintf(fontDefinition, FONT_DEFINITION_FORMAT_STRING, path, size);

    for (list<RESFont *>::iterator it = _Fonts.begin(); it != _Fonts.end(); ++it) {
      if ((*it)->path.compare(fontDefinition) == 0) {
        (*it)->ref_count++;

        return (*it);
      }
    }

    RESFont *resFont   = new RESFont();
    resFont->ref_count = 1;
    sf::Font *ttfFont = new sf::Font();

    if (!ttfFont->loadFromFile(path)) {
      GameEngine::getInstance()->registerError("Font could not be loaded: %s -<%s [%d]>", path, __FILE__, __LINE__);
      exit(1);
    }

    int width, height, powerWidth, powerHeight;

    int lineWidth  = 0;
    int lineHeight = 0;

    int totalWidth  = 0;
    int totalHeight = 0;

    for (int i = 0; i < 255; i++) {
      ttfFont->getGlyph(getWideChar((char)i), size, false);
    }

    for (int i = 0; i < 255; i++) {
      sf::Glyph glyph = ttfFont->getGlyph(getWideChar((char)i), size, false);
      resFont->charPositions[i] = glyph;

      if (glyph.textureRect.height > lineHeight) {
        lineHeight          =  glyph.textureRect.height;
        resFont->charHeight = static_cast<float>(lineHeight);
      }

      if (glyph.textureRect.width > resFont->charWidth) {
        resFont->charWidth = static_cast<float>(glyph.textureRect.width);
      }
    }

    resFont->path = fontDefinition;
    sf::Image fontMap = ttfFont->getTexture(size).copyToImage();

    resFont->texture = ResourceManager::putImage(fontDefinition, fontMap.getPixelsPtr(), fontMap.getSize().x, fontMap.getSize().y, fontMap.getSize().x, fontMap.getSize().y, 4);

    _Fonts.push_front(resFont);

    return resFont;
  }

  void ResourceManager::releaseFont(RESFont *font)
  {
    for (list<RESFont *>::iterator i = _Fonts.begin(); i != _Fonts.end(); ++i) {
      if ((*i) == font) {
        (*i)->ref_count--;

        if ((*i)->ref_count == 0) {
          releaseImage(font->path.c_str());
          delete ((*i));
          _Fonts.remove((*i));
        }
        return;
      }
    }
  }


  void ResourceManager::releaseMusic(sf::Music *music)
  {
    for (list<RESMusic *>::iterator i = _Musics.begin(); i != _Musics.end(); ++i) {
      if ((*i)->music == music) {
        (*i)->ref_count--;
        if ((*i)->ref_count == 0) {
          delete ((*i));
          _Musics.remove((*i));
        }
        return;
      }
    }
  }

  void ResourceManager::releaseChunk(const char *path)
  {
    for (list<RESChunk *>::iterator i = _Chunks.begin(); i != _Chunks.end(); ++i) {
      if ((*i)->path.compare(path) == 0) {
        (*i)->ref_count--;
        if ((*i)->ref_count == 0) {
          delete ((*i));
          _Chunks.remove((*i));
        }
        return;
      }
    }
  }

  void ResourceManager::releaseChunk(sf::Sound *chunk)
  {
    for (list<RESChunk *>::iterator i = _Chunks.begin(); i != _Chunks.end(); ++i) {
      if ((*i)->chunk == chunk) {
        (*i)->ref_count--;
        if ((*i)->ref_count == 0) {
          delete ((*i));
          _Chunks.remove((*i));
        }
        return;
      }
    }
  }

  void ResourceManager::registerForDestruction(GameObject *obj)
  {
    _toDestroy.insert(pair<GameObject *, list<GameObject *> *>(obj, obj->getOwnerList()));
  }

  void ResourceManager::registerForRemove(GameObject *obj)
  {
    _toRemove.insert(pair<GameObject *, list<GameObject *> *>(obj, obj->getOwnerList()));
  }

  void ResourceManager::destroyObjects()
  {
    for (multimap<GameObject *, list<GameObject *> *>::iterator i = _toDestroy.begin(); i != _toDestroy.end(); ++i) {
      (*i).second->remove((*i).first);
      delete (*i).first;
    }
    _toDestroy.clear();
  }

  void ResourceManager::removeObjects()
  {
    for (multimap<GameObject *, list<GameObject *> *>::iterator i = _toRemove.begin(); i != _toRemove.end(); ++i) {
      if ((*i).first->getOwnerList() != (*i).second) {
        (*i).second->remove((*i).first);
      }
    }
    _toRemove.clear();
  }


  void ResourceManager::freeAll()
  {
    for (RESChunk *chunk : _Chunks)
      delete chunk;
    _Chunks.clear();

    for (RESMusic *music  : _Musics)
      delete music;
    _Musics.clear();
    
    for (RESFont *resfont : _Fonts)
      delete resfont;
    _Fonts.clear();
    
    for (RESTexture *ressurface : _Surfaces)
      delete ressurface;
    _Surfaces.clear();
  }

  wchar_t ResourceManager::getWideChar(char c)
  {
    std::string aux = " ";
    aux[0] = c;

    std::wstring s(aux.begin(), aux.end());
    return s[0];
  }

} // namespace Aztec