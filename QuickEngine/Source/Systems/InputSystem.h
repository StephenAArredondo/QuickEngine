#ifndef __INPUT_SYSTEM_H__
#define __INPUT_SYSTEM_H__

#include "EntityProcessingSystem.h"

class InputSystem : public EntityProcessingSystem
{
protected:

	virtual void Begin();
	virtual void ProcessEntity(EntityManager* _pManager, Entity* _pEntity);
	virtual void End();

public:
	
	InputSystem(EventManager* _pEventManager, EntityManager* _pEntityManager);
	virtual ~InputSystem();
};

#endif