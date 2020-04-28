#include "Config.h"

namespace Aztec {
  /* 	Default Screen Parameters */

  int Config::SCREEN_WIDTH  = 1024;
  int Config::SCREEN_HEIGHT = 768;

  bool Config::FULLSCREEN = false;
  bool Config::DEBUG_DRAW = false;

  /*Default Sound parameters*/
  int Config::SOUND_CHANNELS    = 2; //1 mono, 2 stereo
  int Config::SOUND_FREQUENCY   = 44100;
  int Config::SOUND_BUFFER_SIZE = 1024;


  /*Max elapsed time before redrawing and maximum step while dragging the window (thus suspending the execution)*/
  double Config::MAX_ELAPSEDTIME = 1.0f / 60.0f;

  /*Box2D parameters*/
  float Config::PHYSICS_PIXELS_METERS_RATIO = 60.0f;
  float Config::PHYSICS_TIME_STEP           = 1.0f / 60.0f;
  int   Config::PHYSICS_VELOCITY_ITERATIONS = 4;
  int   Config::PHYSICS_POSITION_ITERATIONS = 4;

  /*Game Title*/
  char Config::TITLE[255] = "Aztec";
} // namespace Aztec