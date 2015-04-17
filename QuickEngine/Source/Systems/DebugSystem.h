#ifndef __DEBUGSYSTEM_H__
#define __DEBUGSYSTEM_H__

#include "EntityProcessingSystem.h"

class DebugSystem : public EntityProcessingSystem
{
protected:
	virtual void ProcessEntity(EntityManager* _pManager, Entity* _pEntity);

public:
	DebugSystem(EventManager* _pEventManager, EntityManager* _pEntityManager);
	virtual ~DebugSystem();
	bool HandleEvent(IEventData const& _Event);
};

#endif