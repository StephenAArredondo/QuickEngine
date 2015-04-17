#ifndef _COMMON_H_
#define _COMMON_H_

#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <list>

//////////////////////////////////////////////////////////////////////////
// SDL Headers
#include "..\Utilities\SDLUtil.h"
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Other

#include "..\Utilities\MathUtil.h"
#include "..\Utilities\Math.h"

#include "..\ThirdParty\EntityX\EntityXWrapper.h"


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

static SDL_Color ToSDLColor(const QColor& color)
{
	SDL_Color sColor;
	sColor.r = (Uint8)color.R;
	sColor.g = (Uint8)color.G;
	sColor.b = (Uint8)color.B;
	sColor.a = (Uint8)color.A;
	return sColor;
}

#endif