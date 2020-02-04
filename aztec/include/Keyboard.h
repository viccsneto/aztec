#pragma once

#include <GLFW\glfw3.h>
#include <map>
#include <list>
#include "Config.h"


namespace Aztec {
  using namespace std;
  /**
  * Keyboard
  *
  * Allows access to the state of the keyboard.
  *
  * \author	Vicente Neto
  *
  */

  class Keyboard {
  public:
    class Key {
    public:
      int  code;
      bool is_character;
      bool release_event;
      Key()
      {
        code          = 0;
        is_character  = false;
        release_event = false;
      }
      Key(int k, bool is_char, bool released)
      {
        code          = k;
        is_character  = is_char;
        release_event = released;
      }
    };
    Keyboard();


    /*old definitions (i'll keep these for compatibility purposes)*/
    static const int UP_KEY     = GLFW_KEY_UP;
    static const int DOWN_KEY   = GLFW_KEY_DOWN;
    static const int RIGHT_KEY  = GLFW_KEY_RIGHT;
    static const int LEFT_KEY   = GLFW_KEY_LEFT;
    static const int ESCAPE_KEY = GLFW_KEY_ESCAPE;
    static const int SPACE_KEY  = GLFW_KEY_SPACE;
    static const int ENTER_KEY  = GLFW_KEY_ENTER;
    static const int zero       = GLFW_KEY_0;
    static const int one        = GLFW_KEY_1;
    static const int two        = GLFW_KEY_2;
    static const int three      = GLFW_KEY_3;
    static const int four       = GLFW_KEY_4;
    static const int five       = GLFW_KEY_5;
    static const int six        = GLFW_KEY_6;
    static const int seven      = GLFW_KEY_7;
    static const int eight      = GLFW_KEY_8;
    static const int nine       = GLFW_KEY_9;

    /*ALL SDL => Aztec key mapping*/
    static const int KEY_UNKNOWN   = GLFW_KEY_UNKNOWN;
    static const int KEY_FIND      = GLFW_KEY_UNKNOWN;
    static const int KEY_BACKSPACE = GLFW_KEY_BACKSPACE;
    static const int KEY_TAB       = GLFW_KEY_TAB;
    static const int KEY_CLEAR     = GLFW_KEY_UNKNOWN;
    static const int KEY_RETURN    = GLFW_KEY_ENTER;
    static const int KEY_ENTER     = GLFW_KEY_ENTER;
    static const int KEY_PAUSE     = GLFW_KEY_PAUSE;
    static const int KEY_ESCAPE    = GLFW_KEY_ESCAPE;
    static const int KEY_SPACE     = GLFW_KEY_SPACE;


    static const int KEY_EXCLAIM    = GLFW_KEY_UNKNOWN; //GLFW_KEY_EXC;
    static const int KEY_QUOTEDBL   = GLFW_KEY_UNKNOWN; //GLFW_KEY_QUOTEDBL;
    static const int KEY_HASH       = GLFW_KEY_UNKNOWN; //GLFW_KEY_HASH;
    static const int KEY_DOLLAR     = GLFW_KEY_UNKNOWN; //GLFW_KEY_DOLLAR;
    static const int KEY_AMPERSAND  = GLFW_KEY_UNKNOWN; //GLFW_KEY_AMPERSAND;
    static const int KEY_QUOTE      = GLFW_KEY_UNKNOWN; //GLFW_KEY_QUOTE;
    static const int KEY_LEFTPAREN  = GLFW_KEY_UNKNOWN; //GLFW_KEY_LEFTPAREN;
    static const int KEY_RIGHTPAREN = GLFW_KEY_UNKNOWN; //GLFW_KEY_RIGHTPAREN;
    static const int KEY_ASTERISK   = GLFW_KEY_UNKNOWN; //GLFW_KEY_ASTERISK;
    static const int KEY_PLUS       = GLFW_KEY_KP_ADD; //GLFW_KEY_PLUS;
    static const int KEY_COLON      = GLFW_KEY_UNKNOWN; //GLFW_KEY_COLON;
    static const int KEY_LESS       = GLFW_KEY_UNKNOWN; //GLFW_KEY_LESS;
    static const int KEY_EQUALS     = GLFW_KEY_UNKNOWN; //GLFW_KEY_EQUALS;
    static const int KEY_GREATER    = GLFW_KEY_UNKNOWN; //GLFW_KEY_GREATER;
    static const int KEY_QUESTION   = GLFW_KEY_UNKNOWN; //GLFW_KEY_QUESTION;
    static const int KEY_AT         = GLFW_KEY_UNKNOWN; //GLFW_KEY_AT;
    static const int KEY_CARET      = GLFW_KEY_UNKNOWN; //GLFW_KEY_CARET;
    static const int KEY_UNDERSCORE = GLFW_KEY_UNKNOWN; //GLFW_KEY_UNDERSCORE;
    static const int KEY_BACKQUOTE  = GLFW_KEY_UNKNOWN; //GLFW_KEY_BACKQUOTE;
    static const int KEY_MODE       = GLFW_KEY_UNKNOWN; //GLFW_KEY_MODE;
    static const int KEY_HELP       = GLFW_KEY_UNKNOWN; //GLFW_KEY_HELP;
    static const int KEY_SYSREQ     = GLFW_KEY_UNKNOWN; //GLFW_KEY_SYSREQ;
    static const int KEY_POWER      = GLFW_KEY_UNKNOWN; //GLFW_KEY_POWER;
    static const int KEY_UNDO       = GLFW_KEY_UNKNOWN; //GLFW_KEY_UNDO;


    static const int KEY_COMMA  = GLFW_KEY_COMMA;
    static const int KEY_MINUS  = GLFW_KEY_MINUS;
    static const int KEY_PERIOD = GLFW_KEY_PERIOD;
    static const int KEY_SLASH  = GLFW_KEY_SLASH;
    static const int KEY_0      = GLFW_KEY_0;
    static const int KEY_1      = GLFW_KEY_1;
    static const int KEY_2      = GLFW_KEY_2;
    static const int KEY_3      = GLFW_KEY_3;
    static const int KEY_4      = GLFW_KEY_4;
    static const int KEY_5      = GLFW_KEY_5;
    static const int KEY_6      = GLFW_KEY_6;
    static const int KEY_7      = GLFW_KEY_7;
    static const int KEY_8      = GLFW_KEY_8;
    static const int KEY_9      = GLFW_KEY_9;

    static const int KEY_SEMICOLON = GLFW_KEY_SEMICOLON;

    static const int KEY_BACKSLASH    = GLFW_KEY_BACKSLASH;
    static const int KEY_LEFTBRACKET  = GLFW_KEY_LEFT_BRACKET;
    static const int KEY_RIGHTBRACKET = GLFW_KEY_RIGHT_BRACKET;


    static const int KEY_a      = GLFW_KEY_A;
    static const int KEY_b      = GLFW_KEY_B;
    static const int KEY_c      = GLFW_KEY_C;
    static const int KEY_d      = GLFW_KEY_D;
    static const int KEY_e      = GLFW_KEY_E;
    static const int KEY_f      = GLFW_KEY_F;
    static const int KEY_g      = GLFW_KEY_G;
    static const int KEY_h      = GLFW_KEY_H;
    static const int KEY_i      = GLFW_KEY_I;
    static const int KEY_j      = GLFW_KEY_J;
    static const int KEY_k      = GLFW_KEY_K;
    static const int KEY_l      = GLFW_KEY_L;
    static const int KEY_m      = GLFW_KEY_M;
    static const int KEY_n      = GLFW_KEY_N;
    static const int KEY_o      = GLFW_KEY_O;
    static const int KEY_p      = GLFW_KEY_P;
    static const int KEY_q      = GLFW_KEY_Q;
    static const int KEY_r      = GLFW_KEY_R;
    static const int KEY_s      = GLFW_KEY_S;
    static const int KEY_t      = GLFW_KEY_T;
    static const int KEY_u      = GLFW_KEY_U;
    static const int KEY_v      = GLFW_KEY_V;
    static const int KEY_w      = GLFW_KEY_W;
    static const int KEY_x      = GLFW_KEY_X;
    static const int KEY_y      = GLFW_KEY_Y;
    static const int KEY_z      = GLFW_KEY_Z;
    static const int KEY_DELETE = GLFW_KEY_DELETE;

    static const int KEY_KP0         = GLFW_KEY_KP_0;
    static const int KEY_KP1         = GLFW_KEY_KP_1;
    static const int KEY_KP2         = GLFW_KEY_KP_2;
    static const int KEY_KP3         = GLFW_KEY_KP_3;
    static const int KEY_KP4         = GLFW_KEY_KP_4;
    static const int KEY_KP5         = GLFW_KEY_KP_5;
    static const int KEY_KP6         = GLFW_KEY_KP_6;
    static const int KEY_KP7         = GLFW_KEY_KP_7;
    static const int KEY_KP8         = GLFW_KEY_KP_8;
    static const int KEY_KP9         = GLFW_KEY_KP_9;
    static const int KEY_KP_PERIOD   = GLFW_KEY_PERIOD;
    static const int KEY_KP_DIVIDE   = GLFW_KEY_KP_DIVIDE;
    static const int KEY_KP_MULTIPLY = GLFW_KEY_KP_MULTIPLY;
    static const int KEY_KP_MINUS    = GLFW_KEY_KP_SUBTRACT;
    static const int KEY_KP_PLUS     = GLFW_KEY_KP_ADD;
    static const int KEY_KP_ENTER    = GLFW_KEY_KP_ENTER;
    static const int KEY_KP_EQUALS   = GLFW_KEY_KP_EQUAL;
    static const int KEY_UP          = GLFW_KEY_UP;
    static const int KEY_DOWN        = GLFW_KEY_DOWN;
    static const int KEY_RIGHT       = GLFW_KEY_RIGHT;
    static const int KEY_LEFT        = GLFW_KEY_LEFT;
    static const int KEY_INSERT      = GLFW_KEY_INSERT;
    static const int KEY_HOME        = GLFW_KEY_HOME;
    static const int KEY_END         = GLFW_KEY_END;
    static const int KEY_PAGEUP      = GLFW_KEY_PAGE_UP;
    static const int KEY_PAGEDOWN    = GLFW_KEY_PAGE_DOWN;
    static const int KEY_F1          = GLFW_KEY_F1;
    static const int KEY_F2          = GLFW_KEY_F2;
    static const int KEY_F3          = GLFW_KEY_F3;
    static const int KEY_F4          = GLFW_KEY_F4;
    static const int KEY_F5          = GLFW_KEY_F5;
    static const int KEY_F6          = GLFW_KEY_F6;
    static const int KEY_F7          = GLFW_KEY_F7;
    static const int KEY_F8          = GLFW_KEY_F8;
    static const int KEY_F9          = GLFW_KEY_F9;
    static const int KEY_F10         = GLFW_KEY_F10;
    static const int KEY_F11         = GLFW_KEY_F11;
    static const int KEY_F12         = GLFW_KEY_F12;
    static const int KEY_F13         = GLFW_KEY_F13;
    static const int KEY_F14         = GLFW_KEY_F14;
    static const int KEY_F15         = GLFW_KEY_F15;
    static const int KEY_NUMLOCK     = GLFW_KEY_NUM_LOCK;
    static const int KEY_CAPSLOCK    = GLFW_KEY_CAPS_LOCK;
    static const int KEY_SCROLLLOCK  = GLFW_KEY_SCROLL_LOCK;
    static const int KEY_RSHIFT      = GLFW_KEY_RIGHT_SHIFT;
    static const int KEY_LSHIFT      = GLFW_KEY_LEFT_SHIFT;
    static const int KEY_RCTRL       = GLFW_KEY_RIGHT_CONTROL;
    static const int KEY_LCTRL       = GLFW_KEY_LEFT_CONTROL;
    static const int KEY_RALT        = GLFW_KEY_RIGHT_ALT;
    static const int KEY_LALT        = GLFW_KEY_LEFT_ALT;
    static const int KEY_PRINT       = GLFW_KEY_PRINT_SCREEN;
    static const int KEY_MENU        = GLFW_KEY_MENU;


    Keyboard::Key readVKBuffer();
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * This method answers if the given key is being pressed "true" or not
    * "false".
    *
    * @param keyCode
    * key code of the key you want to know if is being pressed.
    *
    * @return
    * "true" if the key is being pressed.\n
    * "false" if the key is NOT being pressed.
    */
    bool keyIsDown(int keyCode);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * This method answers if the given key is not being pressed "true" or not
    * "false".
    *
    * @param keyCode
    * key code of the key you want to know if is not being pressed.
    *
    * @return
    * "true" if the key is NOT being pressed.\n
    * "false" if the key is being pressed.
    */
    bool keyIsUp(int keyCode);

    /**
    * keyPressed
    *
    * Notifies the keyboard that the key "keycode" was pressed.
    *
    * @param keyCode Code of the key you want to inform.
    */
    void keyPressed(int keyCode);

    /**
    * keyReleased
    *
    * Notifies the keyboard that the key "keycode" was released.
    *
    * @param keyCode Code of the key you want to inform.
    */
    void keyReleased(int keyCode);


    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * The number of keycodes actually in the buffer "queue"
    */
    int bufferLength();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Reads the next keycode from the keyboard buffer
    */
    int readBuffer();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Cleans the keyboard buffer
    */
    void cleanBuffer();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Cleans the keyboard pressed keys map
    */
    void cleanPressed();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Resets keyboard buffer and keys pressed map
    */
    void reset();

    /**
    * putOnKeyboardBuffer
    *
    * Inserts a key into the keyboard buffer
    * @param k the keyCode
    */
    void putOnKeyboardBuffer(Key k);

    int getModifiers(bool &extended);

  private:
    /**
    *unicodeToCodePage
    *
    * Converts an unicode string to ANSI
    *
    * @param codePage code page number for the character encoding
    * @param src the string that will be converted
    */
    char *unicodeToCodePage(int codePage, const wchar_t *src);

    /**
    *codePageToUnicode
    *
    * Converts an ANSI string to Unicode
    *
    * @param codePage code page number for the character encoding
    * @param src the ansi string that will be converted
    */
    wchar_t *codePageToUnicode(int codePage, const char *src);


    /**
    * _keysPressed
    *
    * hash map containg all the keys that are being pressed at this moment on
    * the keyboard.
    */
    map<int, int> _keysPressed;
    list<Key>     _keyBuffer;
    unsigned int  _bufferMaxSize;
  };
} // namespace Aztec
