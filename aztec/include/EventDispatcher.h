#pragma once
#include "GameEngine.h"
#include "Animation.h"
#include "GameObject.h"
#include "GameStateController.h"
#include "Mouse.h"
#include "Music.h"
#include "EventTypes.h"
#include <stack>
#include <iostream>

namespace Aztec {

  /**
  * HookMusicFinishedFunction
  *
  * Callback function that is called when some SDL_Mixer music finish playing
  * Note that it must be a regular C function(not member of a class)
  *
  * \author	Vicente Neto
  */
  void HookMusicFinishedFunction();


  /**
  * EventDispatcher
  *
  * It is responsible to handle events/pass events to interested objects
  *
  * \author	Vicente Neto
  */
  class EventDispatcher {
  private:
    static stack<GameObject *> _mouseClickListeners;
    static stack<GameObject *> _mouseMoveListeners;

    /**
    * Dispatch an OnClick event for the GameObject
    * @param obj The GameObject that will receive the event call
    */
    static void doMouseClick(GameObject *obj);


    /**
    * Dispatch an OnMouseMove event for the GameObject
    * @param obj The GameObject that will receive the event call
    */
    static void doMouseMove(GameObject *obj);

  public:
    static Music *PlayingMusic;
    /**
    * Dispatch an OnDestroy event for the GameObject
    * @param obj The GameObject that will receive the event call
    */
    static void doOnDestroy(GameObject *obj);

    /**    
    * Dispatch an OnCreate event for the GameObject
    * @param obj The GameObject that will receive the event call
    */
    static void doOnCreate(GameObject *obj);

    /**
    * Dispatch an OnUpdate event for the GameObject
    * @param obj The GameObject that will receive the event call
    */
    static void doUpdateEvent(GameObject *obj);

    /**
    * Dispatch an OnBeforeDraw event for the GameObject
    * User can use OpenGL draw calls on this event to achieve advanced drawing effects
    * @param obj The GameObject that will receive the event call
    */

    static void doBeforeDraw(GameObject *obj);

    /**
    * Dispatch an OnAfterDraw event for the GameObject
    *
    * User can use OpenGL draw calls on this event to achieve advanced drawing effects
    * @param obj The GameObject that will receive the event call
    */
    static void doAfterDraw(GameObject *obj);

    /**
    * Dispatch an OnMusicStarted event for the Music
    */
    static void doOnMusicStarted(Music *music);

    /**
    * Dispatch an OnMusicFinished event for the Music
    */
    static void doOnMusicFinished();
    /**
    * Dispatch an OnAnimationStarted event for the Sprite
    *
    * @param sprite A pointer to the Sprite object whose the Animation has started
    * @param animation A pointer to the animation that started playing
    */
    static void doOnAnimationStarted(Sprite *sprite, Animation *animation);

    /**
    * Dispatch an OnAnimationFinished event for the Sprite
    *
    * @param sprite A pointer to the Sprite object whose the Animation has finished
    * @param animation A pointer to the animation that finished playing
    */
    static void doOnAnimationFinished(Sprite *sprite, Animation *animation);

    /**
    * registerForMouseClick
    *
    * Puts the object on a stack in such a way that top objects will receive(and possible handle) clicks before lower objects during the dispatchMouseEvents phase.
    * @param obj The GameObject that will be registered for future OnClick events.
    */
    static void registerForMouseClick(GameObject *obj);
    /**
    * registerForMouseMove
    *
    * Puts the object on a stack in such a way that top objects will receive(and possible handle) mouse movements before lower objects during the dispatchMouseEvents phase.
    * @param obj The GameObject that will be registered for future OnMouseMove events.
    */
    static void registerForMouseMove(GameObject *obj);
    /**
    * dispatchMouseEvents
    *
    * Dispatch events for the registered objects until the stacks get empty or some object marks the event as handled.
    *
    */
    static void dispatchMouseEvents();

    /**
    * doKeyUp
    *
    * Dispatch a KeyUp event to the current GameStateController    
    * @param keyCode The code of the released key
    */
    static void doKeyUp(int keyCode);

    /**
    * doKeyDown
    *
    * Dispatch a KeyDown event to the current GameStateController
    * @param keyCode The code of the pressed key
    */
    static void doKeyDown(int keyCode);

    /**
    * doMouseDown
    *
    * Dispatch a MouseDown event to the current GameStateController
    * @param button The code of the pressed button
    */
    static void doMouseDown(int button);

    /**
    * doMouseUp
    *
    * Dispatch a MouseUp event to the current GameStateController
    * @param button The code of the released button
    */
    static void doMouseUp(int button);
    /**
    * Dispatch an OnBeginContact event for the GameObject
    *
    * @param a The GameObject that will be notified of the collision
    * @param b The GameObject colliding with the GameObject
    */
    static void doBeginContact(GameObject *a, GameObject *b);

    /**
    * Dispatch an OnEndContact event for the GameObject
    *
    * @param a The GameObject that will be notified of the end of the collision
    * @param b The GameObject that stopped colliding with the GameObject
    */
    static void doEndContact(GameObject *a, GameObject *b);

    /**
    * Dispatch an GameStateController OnLoad event for the GameStateController
    *
    * @param state The GameStateController that will receive the event call
    */

    static void doOnLoad(GameStateController *state);

    /**
    * Dispatch an GameStateController OnUnLoad event for the GameStateController
    *
    * @param state The GameStateController that will receive the event call
    */
    static void doOnUnload(GameStateController *state);

    /**
    * Dispatch an GameStateController OnStart event for the GameStateController
    *
    * @param state The GameStateController that will receive the event call
    */
    static void doOnStart(GameStateController *state);

    /**
    * Dispatch an GameStateController OnStart event for the GameStateController
    *
    * @param state The GameStateController that will receive the event call
    */
    static void doOnStop(GameStateController *state);
  };
} // namespace Aztec
