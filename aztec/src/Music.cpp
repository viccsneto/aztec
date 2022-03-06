#include "Music.h"
#include "GameEngine.h"
#include "Config.h"
#include "EventDispatcher.h"

namespace Aztec {

  Music::Music(const char *path)
  {

    _className.assign("Music");
    _music     = NULL;
    _isPlaying = false;
    Repeat     = true;

    if (Config::SOUND_CHANNELS != 0) {
      _music = ResourceManager::loadMusic(path);
      if (_music == NULL) {
        GameEngine::getInstance()->registerWarning("Couldn't load music: %s\n", path);
      }
    }
  }

  void Music::Play()
  {

    if (_music == NULL) {
      return;
    }

    if (EventDispatcher::PlayingMusic != NULL) {
      if (!EventDispatcher::PlayingMusic->equals(this)) {
        EventDispatcher::PlayingMusic->Stop();
        EventDispatcher::doOnMusicFinished();
      }
      else if (isPlaying())
        return;
    }

    EventDispatcher::doOnMusicStarted(this);
    _isPlaying = true;

    _music->setLoop(Repeat);
    _music->play();
  }

  void Music::Pause()
  {
    if (isPlaying()) {
      _isPlaying                                = false;
      EventDispatcher::PlayingMusic->_isPlaying = false;
      _music->pause();
    }
  }

  void Music::Stop()
  {
    if (isPlaying()) {
      Pause();
    }
    _music->stop();
  }

  void Music::Resume()
  {
    _isPlaying = true;
    _music->play();
  }

  bool Music::Seek(double time)
  {
    sf::Time sf_time = sf::seconds(time);
    _music->setPlayingOffset(sf_time);
    return true;
  }

  bool Music::setVolume(double value)
  {
    _music->setVolume(value * 100);
    return true;
  }

  Music::~Music(void)
  {
    if (_music != NULL) {
      Stop();
      ResourceManager::releaseMusic(_music);
    }
    tolua_release(GameEngine::LUA_STATE, this);
  }

  bool Music::isPlaying()
  {
    bool ret = false;
    if (EventDispatcher::PlayingMusic != NULL && EventDispatcher::PlayingMusic->_isPlaying)
      ret = this->equals(EventDispatcher::PlayingMusic);
    return ret;
  }

  EventHandler Music::OnMusicStarted()
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnMusicStarted");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "Music");

    if (lua_pcall(GameEngine::LUA_STATE, 1, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler Music::OnMusicFinished()
  {
    _isPlaying = false;
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnMusicFinished");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "Music");

    if (lua_pcall(GameEngine::LUA_STATE, 1, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }
} // namespace Aztec