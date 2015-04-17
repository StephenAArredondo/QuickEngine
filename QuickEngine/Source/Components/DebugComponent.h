#ifndef __DEBUGCOMPONENT_H__
#define __DEBUGCOMPONENT_H__

#include "BaseComponent.h"

class DebugComponent : public BaseComponent
{
public:
	DebugComponent() : BaseComponent(CT_DEBUG), m_strDebugString("") {}
	
	std::string m_strDebugString;

};

#endif