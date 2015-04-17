#ifndef _COMMON_H_
#define _COMMON_H_

#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <list>

//////////////////////////////////////////////////////////////////////////
// SFML Headers
#include <SDL_assert.h>
// #include <SDL_audio.h>
// #include <SDL_config.h>
// #include <SDL_cpuinfo.h>
// #include <SDL_error.h>
// #include <SDL_filesystem.h>
// #include <SDL_gamecontroller.h>
// #include <SDL_image.h>
// #include <SDL_joystick.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>
// #include <SDL_log.h>
#include <SDL_main.h>
// #include <SDL_mixer.h>
// #include <SDL_mouse.h>
// #include <SDL_mutex.h>
// #include <SDL_name.h>
// #include <SDL_net.h>
#include <SDL_opengl.h>
// #include <SDL_pixels.h>
// #include <SDL_platform.h>
// #include <SDL_quit.h>
#include <SDL_rect.h>
#include <SDL_render.h>
// #include <SDL_shape.h>
#include <SDL_surface.h>
// #include <SDL_system.h>
// #include <SDL_syswm.h>
// #include <SDL_thread.h>
#include <SDL_timer.h>
 #include <SDL_types.h>
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Other

#include "..\Utilities\MathUtil.h"

#include "..\Utilities\Math.h"

#define INVALID_RESOURCE_ID UINT_MAX

// Typedefs
typedef int8_t Qint8;
typedef uint8_t Quint8;
typedef int16_t Qint16;
typedef uint16_t Quint16;
typedef int32_t Qint32;
typedef uint32_t Quint32;

// Constants
//const double Q_PI = 3.14159265358979323846264338327950288;

#define QE_assert SDL_assert

#endif