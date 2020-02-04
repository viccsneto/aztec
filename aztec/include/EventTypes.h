#pragma once

typedef void EventHandler;

namespace Aztec {
  /**
  * EventType
  *
  * Represents each event types that the GameObjects can handle.
  *
  * \author	Vicente Neto
  */
  class EventTypes {
  public:
    /**
    * NONE
    *
    * The object has none event handlers at all.
    */
    const static int NONE;

    /**
    * OnUpdate
    *
    * The object has an OnUpdate event handler.
    */
    const static int OnUpdate;

    /**
    * OnClick
    *
    * The object has an OnClick event handler.
    */
    const static int OnClick;

    /**
    * OnMouseMove
    *
    * The object has an OnMouseMove event handler.
    */
    const static int OnMouseMove;

    /**
    * OnMouseDown
    *
    * The object has an OnMouseDown event handler.
    */
    const static int OnMouseDown;

    /**
    * OnMouseUp
    *
    * The object has an OnMouseUp event handler.
    */
    const static int OnMouseUp;

    /**
    * OnKeyDown
    *
    * The object has an OnKeyDown event handler.
    */
    const static int OnKeyDown;

    /**
    * OnKeyUp
    *
    * The object has an OnKeyUp event handler.
    */
    const static int OnKeyUp;

    /**
    * OnBeginContact
    *
    * The object start to collide with another object
    */
    const static int OnBeginContact;

    /**
    * OnEndContact
    *
    * The object is no longer colliding with another object
    */
    const static int OnEndContact;

    /**
    * OnMusicStarted
    *
    * Occurs when the music execution begins
    */
    const static int OnMusicStarted;

    /**
    * OnMusicFinished
    *
    * Occurs when the music execution ends
    */
    const static int OnMusicFinished;

    /**
    * OnAnimationStarted
    *
    * Occurs when the music execution ends
    */
    const static int OnAnimationStarted;
    /**
    * OnAnimationFinished
    *
    * Occurs when the music execution ends
    */
    const static int OnAnimationFinished;

    /**
    * OnBeforeDraw
    *
    * Occurs just before a game object is drawn
    */
    const static int OnBeforeDraw;
    /**
    * OnAfterDraw
    *
    * Occurs just after a game object is drawn
    */
    const static int OnAfterDraw;

    /**
    * ALL
    *
    * The object has all event handlers.
    * Initially(at the first iteration of the gameloop over the object) all GameObjects have this flag setted. After the engine realizes that the GameObject don't have an event handler for any particullar event, it removes the corresponding flag preventing future attempts.
    */
    const static int ALL;
  };
} // namespace Aztec