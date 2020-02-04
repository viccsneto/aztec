#include "Sound.h"
#include "GameEngine.h"
#include "Config.h"

namespace Aztec {

  Sound::Sound(const char *path)
  {
    _className.assign("Sound");
    _chunk = NULL;
    if (Config::SOUND_CHANNELS != 0) {
      _chunk = ResourceManager::loadChunk(path);
      if (_chunk == NULL) {
        GameEngine::getInstance()->registerWarning("Couldn't load sound: %s\n", path);
      }
    }
  }

  void Sound::Play()
  {
    if (_chunk == NULL) {
      return;
    }
    _chunk->play();
  }

  Sound::~Sound(void)
  {
    if (_chunk != NULL) {
      ResourceManager::releaseChunk(_chunk);
    }
  }

} // namespace Aztec