#pragma once

#include <GL/glew.h>
#include <glm.hpp>
#include <string.h>
#include "ResourceTypes.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <map>

namespace Aztec {

  /**
	 * ResourceManager
	 *
	 * Represents a resource manager that prevents resources from being loaded more than once
	 *
	 * \author	Vicente Neto
	 */
  class ResourceManager {
  private:
    static list<RESFont *>    _Fonts;
    static list<RESTexture *> _Surfaces;
    static list<RESShader *>  _Shaders;
    static list<RESMusic *>   _Musics;
    static list<RESChunk *>   _Chunks;

    static multimap<GameObject *, list<GameObject *> *> _toDestroy;
    static multimap<GameObject *, list<GameObject *> *> _toRemove;

  public:
    /**
			* loadImage
			*
			* Loads a image resource and associate it with a RESSurface object which mantains it's dimension for future use (texture mapping).
			* @param
			* path The path for the image file
			* @return
			* a RESSurface object
			*/
    static RESTexture *loadImage(const char *path);

    static RESTexture *createTexture(int width, int height, void *data);

    /**
			* putImage
			*
			* Converts a SDL_Surface to a glTexture and put it under control of the ResourceManager
			* @param path The path string for this texture representation
			* @param sdlSurface The SDL_Surface that will be converted to a OpenGL texture
			* @return a RESSurface object
			*/
    static RESTexture *putImage(const char *path, const sf::Uint8 *data, int width, int height, int originalWidth, int originalHeight, int channels);


    /**
			* releaseImage
			*
			* Decrease the reference count of an Image and deallocate it when the counter achieve 0 references
			* @param path The path representing the image resource
			*/
    static void releaseImage(const char *path);

    /**
			* releaseImage
			*
			* Decrease the reference count of an Image and deallocate it when the counter achieve 0 references
			* @param rsurface The rsurface representing the image
			*/
    static void releaseImage(RESTexture *rsurface);


    /**
    * loadMusic
    *
    * Loads a music resource(file formats supported by SDL_Mixer library such as .mp3, .ogg)
    * @param path The path for the music file
    * @return a Mix_Music struct
    */
    static sf::Music *loadMusic(const char *path);

    /**
    * loadChunk
    *
    * Loads a short(uncompressed) sound effect resource(tipically a .wav file for explosion, lasers, etc)
    * @param path The path for the sound effect resource
    * @return a Mix_Chunk structure
    */
    static sf::Sound *loadChunk(const char *path);


    /**
			* loadFont
			*
			* Loads a TrueType font
			*
			* @param path The path for the .ttf font file
			*
			* @param color A SDL_Color structure for the resulting font texture
			*
			* @param size The point size of the font
			*
			* @return a RESFont pointer
			*/
    static RESFont *loadFont(const char *path, glm::vec4 color, int size);

    /**
			* releaseFont
			*
			* Decrease the reference count of a font and deallocate it when the counter achieve 0 references
			*
			* @param font The Font Resource
			*/
    static void releaseFont(RESFont *font);

    /**
    * releaseMusic
    *
    * Decrease the reference count of a Music resource and deallocate it when the counter achieve 0 references
    * @param path The path representing the music resource
    */
    static void releaseMusic(const char *path);

    /**
    * releaseMusic
    *
    * Decrease the reference count of a Music and deallocate it when the counter achieve 0 references
    * @param music The Mix_Music representing the music resource
    */
    static void releaseMusic(sf::Music *music);

    /**
    * releaseChunk
    *
    * Decrease the reference count of a sound effect and deallocate it when the counter achieve 0 references
    * @param path The path representing the sound effect resource
    */
    void releaseChunk(const char *path);

    /**
    * releaseChunk
    *
    * Decrease the reference count of a sound effect and deallocate it when the counter achieve 0 references
    * @param chunk The Mix_Chunk representing the sound effect resource
    */
    static void releaseChunk(sf::Sound *chunk);

    /**
			* registerForDestruction
			*
			* Puts a L3DEObject in the list of objects to be destroyed after this L3DE loop iteration
			*/
    static void registerForDestruction(GameObject *obj);

    /**
			* registerForRemove
			*
			* Puts a L3DEObject in the list of objects to be removed from its owner after this L3DE loop iteration
			*/
    static void registerForRemove(GameObject *obj);


    /**
			* destroyObjects
			*
			* Effectively destroy the objects that were marked to be destroyed in the last L3DE loop iteration
			*/
    static void destroyObjects();

    /**
			* removeObjects
			*
			* Effectively remove the objects that were marked to be destroyed in the last L3DE loop iteration
			*/
    static void removeObjects();

    /**
			* freeAll
			*
			* deallocate all resources
			*/
    static void freeAll();
private:
  static wchar_t getWideChar(char c);
  };
} // namespace Aztec