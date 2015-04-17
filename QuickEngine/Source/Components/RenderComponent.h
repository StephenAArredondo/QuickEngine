#ifndef __RENDERCOMPONENT_H__
#define __RENDERCOMPONENT_H__

#include "BaseComponent.h"

class RenderComponent : public BaseComponent
{
public:
	RenderComponent() : BaseComponent(CT_RENDERING) {}
};

#endif