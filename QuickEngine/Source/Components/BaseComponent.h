#ifndef __BASE_COMPONENT_H__
#define __BASE_COMPONENT_H__

#include <Common.h>
#include "ComponentType.h"

using namespace EComponentType;

class BaseComponent
{

private:

	eComponentType m_eType;
	unsigned int m_uiBit;

public:

	BaseComponent(eComponentType _eType) : m_eType(_eType), m_uiBit(GetBit(_eType)) {}
	virtual ~BaseComponent() {}

	eComponentType GetType(void) { return m_eType; }
	unsigned int GetTypeBit(void) { return m_uiBit; }
};

#endif//__BASE_COMPONENT_H__