#pragma once
#include <stack>
#include "GameObject.h"
#include "Vector2.h"
#include "Config.h"

namespace Aztec {
  /**
	* Mouse
	*
	* This class allows access to the state of the mouse.
	*
	* \author	Vicente Neto
	*
	*/
  class Mouse {
  public:
    /*
		*Constructor
		*/
    Mouse();
    /**
		* <DIV class="ah icona">Lua</DIV>
		* Get X Position
		*
		* @return horizontal position of the mouse on the canvas, in pixels.
		*/
    int getPosX();
    /**
		* <DIV class="ah icona">Lua</DIV>
		* Get Y Position
		*
		* @return vertical position of the mouse on the canvas, in pixels.
		*/
    int getPosY();

    /**
		* <DIV class="ah icona">Lua</DIV>
		* Get scrolled X value
		*
		* @return horizontal position of the mouse on the canvas, in pixels.
		*/
    double getScrolledX();
    /**
		* <DIV class="ah icona">Lua</DIV>
		* Get scrolled Y value
		*
		* @return vertical position of the mouse on the canvas, in pixels.
		*/
    double getScrolledY();

    /**
		* <DIV class="ah icona">Lua</DIV>
		* Is Left Button Pressed
		*
		* @return
		* "true" if the left mouse button is being pressed.\n
		* "false" if the left mouse button is NOT being pressed.
		*/
    bool isLeftButtonPressed();

    /**
		* <DIV class="ah icona">Lua</DIV>
		* Is Right Button Pressed
		*
		* @return
		* "true" if the right mouse button is being pressed.\n
		* "false" if the right mouse button is NOT being pressed.
		*/
    bool isRightButtonPressed();

    /**
		* Is Middle Button Pressed
		*
		* @return
		* "true" if the middle mouse button is being pressed.\n
		* "false" if the middle mouse button is NOT being pressed.
		*/
    bool isMiddleButtonPressed();

    /**
		* <DIV class="ah icona">Lua</DIV>
		* Is Left Button Pressed
		*
		* @return
		* "true" if the left mouse button is being pressed.\n
		* "false" if the left mouse button is NOT being pressed.
		*/
    bool LeftButtonJustReleased();

    /**
		* <DIV class="ah icona">Lua</DIV>
		* Is Right Button Pressed
		*
		* @return
		* "true" if the right mouse button is being pressed.\n
		* "false" if the right mouse button is NOT being pressed.
		*/
    bool RightButtonJustReleased();

    /**
		* Is Middle Button Pressed
		*
		* @return
		* "true" if the middle mouse button is being pressed.\n
		* "false" if the middle mouse button is NOT being pressed.
		*/
    bool MiddleButtonJustReleased();

    bool LeftButtonJustPressed();

    /**
		* <DIV class="ah icona">Lua</DIV>
		* Is Right Button Pressed
		*
		* @return
		* "true" if the right mouse button is being pressed.\n
		* "false" if the right mouse button is NOT being pressed.
		*/
    bool RightButtonJustPressed();

    /**
		* Is Middle Button Pressed
		*
		* @return
		* "true" if the middle mouse button is being pressed.\n
		* "false" if the middle mouse button is NOT being pressed.
		*/
    bool MiddleButtonJustPressed();

    /**
		*
		* Moved
		*
		* Notifies the mouse that it has moved. The Mouse will then open the event
		* object it received in search for the new location of the mouse cursor on
		* the canvas.
		*
		* @param x The x component of the movement
		* @param y The y component of the movement
		*/
    void moved(int x, int y);

    /**
		* Button Pressed
		*
		* Notifies the mouse that the button given by buttonCode was pressed.
		*
		* @param buttonCode
		*/
    void buttonPressed(int buttonCode);

    /**
		* Button Released
		*
		* Notifies the mouse that the button given by buttonCode was released.
		*
		* @param buttonCode
		*/
    void buttonReleased(int buttonCode);

    /**
		* <DIV class="ah icona">Lua</DIV>
		* Hides the mouse cursor
		*/
    void hideCursor();
    /**
		*<DIV class = "ah icona">Lua</DIV>
		* Shows the mouse cursor
		*/
    void        showCursor();
    void        Reset();
    void        scrolled(double x, double y);
    static bool hasClick;
    static bool hasReleased;
    static bool hasMovement;
    static bool hasWheel;

  private:
    int    _x;
    int    _y;
    double _scrolled_x;
    double _scrolled_y;
    int    _leftButtonPressed;
    int    _rightButtonPressed;
    int    _middleButtonPressed;

    bool   _leftButtonJustPressed;
    bool   _rightButtonJustPressed;
    bool   _middleButtonJustPressed;
    double _lastTime;
    bool   _leftButtonJustReleased;
    bool   _rightButtonJustReleased;
    bool   _middleButtonJustReleased;
  };
} // namespace Aztec
