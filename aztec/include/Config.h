#pragma once

#define AZTEC_PI b2_pi
#define GAMEOBJECT_CIRCLE_RADIUS (2.5f / Config::PHYSICS_PIXELS_METERS_RATIO)
#define DEGREE_TO_RADIAN (AZTEC_PI / 180.0f)
#define RADIAN_TO_DEGREE (180.0f / AZTEC_PI)
#define AZTEC_MINIMUM_SCALE_VALUE 0.001f
#define CLICK_INTERVAL (1.0f / 10)
namespace Aztec {
  /**
  * Config
  *
  * Represents the engine configuration properties.
  *
  * \author	Vicente Neto
  */
  class Config {
  public:
    /**
    * TITLE
    *
    * The window title parameter.
    */
    static char TITLE[255];

    /**
    * SCREEN_WIDTH
    *
    *  The Screen width in pixels. The default value is 1024.
    */
    static int SCREEN_WIDTH;

    /**
    * SCREEN_HEIGHT
    *
    *  The Screen height in pixels. The default value is 768.
    */
    static int SCREEN_HEIGHT;

    /**
    * FULLSCREEN
    *
    * Determines if the application will run on FULLSCREEN(true) or Windowed/DEFAULT(false).
    */
    static bool FULLSCREEN;

    /**
    * SOUND_CHANNELS
    *
    * The number of sound channels that will be used(0 = SOUND DISABLED, 1 = MONO, 2 = STEREO/DEFAULT)
    */
    static int SOUND_CHANNELS;

    /**
    * SOUND_FREQUENCY
    *
    * The sound frequency for the audio subsystem. The default value is 44100 Hz
    */
    static int SOUND_FREQUENCY;

    /**
    * SOUND_BUFFER_SIZE
    *
    * The size in bytes for the sound buffer. The default value is 8096 bytes
    */
    static int SOUND_BUFFER_SIZE;


    /**
    * Physics ratio between pixels/meters
    *
    */
    static float PHYSICS_PIXELS_METERS_RATIO;

    /**
    * Max elapsed time
    *
    * Prevents a long delta time when the loop has been paused (code debugging or user moving the Window for instance)
    */
    static double MAX_ELAPSEDTIME;

    /**
    * DEBUG_DRAW
    *
    * Determines if debug information will be drawn for the physics objects
    */
    static bool DEBUG_DRAW;

    /**
    * PHYSICS_TIME_STEP
    *
    * The time step that will be used each frame by Box2D
    *
    * Default value is 1/60.0f
    */
    static float PHYSICS_TIME_STEP;

    /**
    * PHYSICS_VELOCITY_ITERATIONS
    *
    * The number of velocity iterations that will be considered at each Box2D step
    *
    * Default value is 8
    */

    static int PHYSICS_VELOCITY_ITERATIONS;

    /**
    * PHYSICS_POSITION_ITERATIONS
    *
    * The number of position iterations that will be considered at each Box2D step
    *
    * WARNING: Since we are not using physics simulation, this value is kept as 0
    * Other values are making object positions to change(possibly because of aproximations) when near other objects, even if they are marked as sensors
    * When physics simulation support be added, this must be take in consideration
    */
    static int PHYSICS_POSITION_ITERATIONS;
  };
} // namespace Aztec
