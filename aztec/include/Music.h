#pragma once
#include "LuaBinded.h"
#include "ResourceManager.h"
#include "EventTypes.h"

namespace Aztec {
  /**
  * Music
  *
  * Allow several music formats to be played through an SDL_Mixer abstraction
  *
  * \author	Vicente Neto
  *
  */
  class Music : public LuaBinded {
  public:
    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    Music(const char *path);
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Plays the music
    */
    void Play();
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Stops the music
    */
    void Stop();
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Pauses the music allowing it to be resumed later
    */
    void Pause();
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Resumes a paused music (or start it if not previously started)
    */
    void Resume();


    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets the music position in seconds
    * @param time A double specifying the desired position to seek
    * @return A bool indicating if the operation was completed successfully
    */
    bool Seek(double time);


    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets the music volume 
    * @param value A double specifying the desired music volume
    * @return A bool indicating if the operation was completed successfully
    */
    bool setVolume(double value);

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Determines if the music should repeat (must be set before a call to Play)
    */
    bool Repeat;

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Returns the Playing status of the Music
    * @return a boolean value indicating if the music is playing or not
    */
    bool isPlaying();

    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    ~Music(void);

    /// Events

    virtual EventHandler OnMusicStarted();
    virtual EventHandler OnMusicFinished();
    bool                 equals(Music *other)
    {
      bool ret = false;
      if (other != NULL) {
        ret = _music == other->_music;
      }

      return ret;
    }

  private:
    sf::Music *_music;
    bool       _isPlaying;
  };
} // namespace Aztec