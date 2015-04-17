#ifndef __ENTITY_PROCESSING_SYSTEM_H__
#define __ENTITY_PROCESSING_SYSTEM_H__

#include "..\Components\ComponentType.h"
#include "EntitySystem.h"

class EventManager;
class EntityManager;

class EntityProcessingSystem : public EntitySystem
{
protected:

	// A preprocessing update call.
	virtual void Begin();

	// Process an entity this system is interested in.
	virtual void ProcessEntity(EntityManager* _pManager, Entity* _pEntity) = 0;

	// A post processing update call.
	virtual void End();

	// Should we update?
	virtual bool CheckProcessing();

	// Any implementing entity system must implement this method and the logic
	// to process the given entities of the system.
	virtual void ProcessEntities(EntityManager* _pManager, const std::set<Entity*>& _pEntities);

public:

	EntityProcessingSystem(EventManager* _pEventManager, EntityManager* _pEntityManager, unsigned int _uiTypeBits);
	virtual ~EntityProcessingSystem();
};

#endif