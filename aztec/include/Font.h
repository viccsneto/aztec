#pragma once

#include <string>
#include <glm.hpp>
#include "ResourceManager.h"

namespace Aztec {
  /**
  * Font
  *
  * Represents a loaded TrueType font.
  *
  * \author	Vicente Neto
  */
  class Font {

  public:
    /**
    * Constructor
    *
    * @param filePath
    * path to the font (.ttf) file.
    * @param size
    * point size of the font.
    */
    Font(char *filePath, int size);

    /**
    * Constructor
    *
    * @param filePath
    * path to the font (.ttf) file.
    * @param size
    * point size of the font.
    * @param color
    * SDL_Color for the font
    */
    Font(char *filePath, int size, glm::vec4 color);

    /**
    * Destructor
    */
    ~Font();

    /**
    * Get Size
    *
    * @return
    * the point size of the font.
    */
    int getSize();

    /**
    * Get File Path
    *
    * @return
    * path to the font (.ttf) file.
    */
    const char *getFilePath();

    /**
    * Get getFontResource
    *
    * @return
    * The RESFont containing the opengl texture, and an array of all char positions and dimensions.
    */
    RESFont *getFontResource();


    /**
    * Unload
    *
    * unloads the font resources.
    */
    void unload();

    /**
    * Sets the font color to r,g,b
    *
    * @param r The red component of the font color
    * @param g The green component of the font color
    * @param b The blue component of the font color
    */
    void setColor(short r, short g, short b, short a);


    /**
    * getCharHeight
    *
    * @return
    * The height of each character in the map
    */
    float getCharHeight();

    /**
    * getCharHeight
    *
    * @return
    * The height of each character in the map
    */
    float getCharWidth();

  private:
    /**
    * _filePath
    *
    * Keeps the ttf file path that originated the font
    */
    string _filePath;

    /**
    * _color
    *
    * Keeps the SDL_Color of the font
    */
    glm::vec4 _color;

    /**
    * _fontResource
    *
    * The RESFont object that represents this font
    */
    RESFont *_fontResource;

    /**
    * createFontResource
    *
    * Makes the resource allocation/requisition of this font
    */
    void createFontResource();

    /**
    * _size
    *
    * The point size of this font
    */
    int _size;

    /**
    * Init
    *
    * Initializes the font
    */
    void Init(char *filePath, int size);
  };
} // namespace Aztec