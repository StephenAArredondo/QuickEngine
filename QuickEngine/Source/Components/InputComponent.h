#ifndef __INPUTCOMPONENT_H__
#define __INPUTCOMPONENT_H__

#include "BaseComponent.h"
#include <SDL_events.h>

namespace EComponentEvent
{
	enum eInputEvent
	{
		EVENT_INPUT_ARROW_UP = 1,
		EVENT_INPUT_ARROW_DOWN,
		EVENT_INPUT_ARROW_LEFT,
		EVENT_INPUT_ARROW_RIGHT
	};
}

class InputComponent : public BaseComponent
{
public:

	InputComponent() : BaseComponent(CT_INPUT) 
	{
		m_vKeys.clear();
		m_vKeys.reserve(16);
	}

	virtual ~InputComponent() 
	{
		m_vKeys.clear();
	}

	std::vector<SDL_Scancode> m_vKeys;
};

#endif
