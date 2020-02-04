#include "EventDispatcher.h"

namespace Aztec {
  Music *             EventDispatcher::PlayingMusic = NULL;
  stack<GameObject *> EventDispatcher::_mouseClickListeners;
  stack<GameObject *> EventDispatcher::_mouseMoveListeners;

  void HookMusicFinishedFunction()
  {
    EventDispatcher::doOnMusicFinished();
  }

  void EventDispatcher::doMouseClick(GameObject *obj)
  {
    obj->OnClick();
  }
  void EventDispatcher::doMouseMove(GameObject *obj)
  {
    obj->OnMouseMove();
  }

  void EventDispatcher::doOnDestroy(GameObject *obj)
  {
    for (GameObject *child : obj->getChildren()) {
      EventDispatcher::doOnDestroy(child);
    }
    
    obj->OnDestroy();
  }

  void EventDispatcher::doOnCreate(GameObject *obj)
  {
    obj->OnCreate();
  }


  void EventDispatcher::doUpdateEvent(GameObject *obj)
  {
    obj->OnUpdate();
  }


  void EventDispatcher::doBeforeDraw(GameObject *obj)
  {
    obj->OnBeforeDraw();
  }

  void EventDispatcher::doAfterDraw(GameObject *obj)
  {
    obj->OnAfterDraw();
  }

  void EventDispatcher::doOnMusicStarted(Music *music)
  {
    EventDispatcher::PlayingMusic = music;
    music->OnMusicStarted();
  }

  void EventDispatcher::doOnMusicFinished()
  {
    if (EventDispatcher::PlayingMusic) {
      EventDispatcher::PlayingMusic->OnMusicFinished();
      PlayingMusic = NULL;
    }
  }


  void EventDispatcher::doOnAnimationStarted(Sprite *sprite, Animation *animation)
  {
    sprite->OnAnimationStarted(animation);
  }


  void EventDispatcher::doOnAnimationFinished(Sprite *sprite, Animation *animation)
  {
    sprite->OnAnimationFinished(animation);
  }


  void EventDispatcher::registerForMouseClick(GameObject *obj)
  {
    if (!(obj->EventFlags & EventTypes::OnClick)) {
      return;
    }
    _mouseClickListeners.push(obj);
  }

  void EventDispatcher::registerForMouseMove(GameObject *obj)
  {
    if (!(obj->EventFlags & EventTypes::OnMouseMove)) {
      return;
    }
    _mouseMoveListeners.push(obj);
  }

  void EventDispatcher::dispatchMouseEvents()
  {
    GameStateController *game_state_controller = GameEngine::getInstance()->getCurrentGameState();

    if (Mouse::hasMovement) {
      if (game_state_controller) {
        if (game_state_controller->EventFlags & EventTypes::OnMouseMove)
          game_state_controller->OnMouseMove();
      }

      while (!_mouseMoveListeners.empty()) {
        GameObject *obj = _mouseMoveListeners.top();
        doMouseMove(obj);
        _mouseMoveListeners.pop();
      }
    }
    else {
      while (!_mouseMoveListeners.empty()) {
        _mouseMoveListeners.pop();
      }
    }

    if (Mouse::hasClick) {
      while (!_mouseClickListeners.empty()) {
        GameObject *obj = _mouseClickListeners.top();
        doMouseClick(obj);
        _mouseClickListeners.pop();
      }
    }
    else {
      while (!_mouseClickListeners.empty()) {
        _mouseClickListeners.pop();
      }
    }
  }

  void EventDispatcher::doKeyUp(int keyCode)
  {
    GameStateController *game_state_controller = GameEngine::getInstance()->getCurrentGameState();
    if (game_state_controller) {
      if (game_state_controller->EventFlags & EventTypes::OnKeyUp)
        game_state_controller->OnKeyUp(keyCode);
    }
  }

  void EventDispatcher::doKeyDown(int keyCode)
  {
    GameStateController *game_state_controller = GameEngine::getInstance()->getCurrentGameState();
    if (game_state_controller) {
      if (game_state_controller->EventFlags & EventTypes::OnKeyDown)
        game_state_controller->OnKeyDown(keyCode);
    }
  }

  void EventDispatcher::doMouseDown(int button)
  {
    GameStateController *game_state_controller = GameEngine::getInstance()->getCurrentGameState();
    if (game_state_controller) {
      if (game_state_controller->EventFlags & EventTypes::OnMouseDown)
        game_state_controller->OnMouseDown(button);
    }
  }

  void EventDispatcher::doMouseUp(int button)
  {
    GameStateController *game_state_controller = GameEngine::getInstance()->getCurrentGameState();
    if (game_state_controller) {
      if (game_state_controller->EventFlags & EventTypes::OnMouseUp)
        game_state_controller->OnMouseUp(button);
    }
  }

  void EventDispatcher::doBeginContact(GameObject *a, GameObject *b)
  {
    a->OnBeginContact(b);
  }

  void EventDispatcher::doEndContact(GameObject *a, GameObject *b)
  {
    a->OnEndContact(b);
  }

  void EventDispatcher::doOnLoad(GameStateController *state)
  {
    state->OnLoad();
  }

  void EventDispatcher::doOnUnload(GameStateController *state)
  {
    state->OnUnload();
  }

  void EventDispatcher::doOnStart(GameStateController *state)
  {
    state->OnStart();
  }

  void EventDispatcher::doOnStop(GameStateController *state)
  {
    state->OnStop();
  }

} // namespace Aztec