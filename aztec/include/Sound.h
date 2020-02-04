#pragma once
#include <SFML/Audio.hpp>

#include "LuaBinded.h"
#include "ResourceManager.h"

namespace Aztec {
  /**
  * Sound
  *
  * Allow several sound effects to be played through an SDL_Mixer abstraction
  *
  * \author	Vicente Neto
  */
  class Sound : public LuaBinded {
  private:
    sf::Sound *_chunk;

  public:
    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    Sound(const char *path);
    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    ~Sound(void);

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Plays the Sound
    */
    void Play();
  };
} // namespace Aztec