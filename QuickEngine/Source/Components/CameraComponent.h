#ifndef __CAMERACOMPONENT_H__
#define __CAMERACOMPONENT_H__

#include "BaseComponent.h"

class CameraComponent : public BaseComponent
{
public:
	CameraComponent() : BaseComponent(CT_CAMERA) {}
};

#endif