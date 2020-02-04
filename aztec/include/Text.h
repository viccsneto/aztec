#pragma once

#include "GameObject.h"
#include "Plane.h"
#include "Font.h"
#include <glm.hpp>
class b2Fixture;

namespace Aztec {
  /**
  * Text
  *
  * This class represents a renderizable text, that can be drawn anywhere on
  * the canvas.
  * It uses a True Type Font.
  *
  * \author	Vicente Neto
  *
  */
  class Text : public GameObject {
  private:
    Plane *_plane[255];

  public:
    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    Text();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @param r red color component
    * @param g green color component
    * @param b blue color component
    * @param fontPath path to the ttf file
    * @param fontSize point size of the font
    */
    Text(int r, int g, int b, char *fontPath, int fontSize);

    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    ~Text();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets the value of the Text
    *
    * @param text The string that will be rendered at the Canvas
    *
    */
    void setText(char *text);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @return The value of the Text
    *
    */
    char *getText();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @param r red color component
    * @param g green color component
    * @param b blue color component
    */
    void setColor(int r, int g, int b);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @return
    * the height in pixels of the text.
    */
    float getHeight();

    //Overrides
    /**
    * Draw
    *
    * Renders the text on the canvas
    */
    void draw();

    /**
    * Override Step
    *
    * This functions does nothing. The job of updating the position of the text
    * belongs to whoever posesses the Text.
    *
    */
    void step();

    /**
    * Override Load
    *
    * This function will load the ttf file.
    */
    void load();

    /**
    * Override unload
    *
    * This function will close the ttf file. And clean the surface vector.
    */
    void unload();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets the bounding box of the Text
    *
    * @param w The width of the bounding box
    *
    * @param h The height of the bounding box
    */
    void setDimension(float w, float h);

    /**
    * selectByClick
    *
    * Sets the cursor position based on mouse click position
    *
    * @param x The x coordinate of the click
    *
    * @param y The y coordinate of the click
    *
    */
    void selectByClick(float x, float y);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets the text cursor position to the specified parameter
    *
    * @param i The position to the text cursor
    *
    */
    void setCursorPosition(int i);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Gets the text current cursor position
    *
    * @return The current position of the text cursor
    *
    */
    int getCursorPosition();

    /**
    * getTarget
    *
    * Returns itself on contacts with the mouse cursor and the Camera
    */
    GameObject *getTarget();

  private:
    void drawCursor(float x, float y, RESFont *rfont);
    //keeps the file path to the ttf
    string _fontPath;
    //keeps size of font
    int _fontSize;
    //Keeps pointer to ttf
    Font *_font;
    //Keeps color of the text
    glm::vec4 _color;

    //Keeps the text
    char *_text;

    /**
    * Init Default
    *
    * Initializes the class with default values.
    */

    b2Fixture *_fixture;
    void       createFixture();
    void       drawChar(float x, float y, unsigned char c, RESFont *rfont);
    int        _cursorPosition;
    int        _lastcursorBlinkTime;
    int        _cursorBlinkInterval;
    bool       _cursorBlinkNow;

    void InitDefault();

  protected:
    void reScale();
  };
} // namespace Aztec
