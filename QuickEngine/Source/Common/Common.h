#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iostream>

//////////////////////////////////////////////////////////////////////////
// Utility Headers

#include "..\Utilities\SDLUtil.h"

typedef SDL_Scancode QKey;
using QGLContext = SDL_GLContext;
typedef SDL_Renderer QRenderContext;
typedef SDL_Window QWindow;

#include "..\ThirdParty\ThirdParties.h"

#include "..\Utilities\MathUtil.h"
#include "..\Utilities\Math.h"
#include "..\Utilities\Utilities.h"

#include "..\Components\Components.h"
#include "..\Events\Events.h"
#include "..\Systems\Systems.h"

#define INVALID_RESOURCE_ID UINT_MAX

// Typedefs
typedef int8_t Qint8;
typedef uint8_t Quint8;
typedef int16_t Qint16;
typedef uint16_t Quint16;
typedef int32_t Qint32;
typedef uint32_t Quint32;

#define QE_assert SDL_assert

static SDL_Color ToSDLColor(const QColor& color)
{
	SDL_Color sColor;
	sColor.r = (Uint8)color.R;
	sColor.g = (Uint8)color.G;
	sColor.b = (Uint8)color.B;
	sColor.a = (Uint8)color.A;
	return sColor;
}

#endif//__COMMON_H__