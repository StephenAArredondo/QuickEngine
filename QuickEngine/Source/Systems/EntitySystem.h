#ifndef __ENTITY_SYSTEM_H__
#define __ENTITY_SYSTEM_H__

#include "..\Utilities\Event.h"
#include "..\Utilities\Entity.h"
#include "..\Components\ComponentType.h"
#include <set>

class Entity;
class EntityManager;
class EventManager;

class EntitySystem : public IEventListener
{
private:

	// The bits representing the component types that we care about.
	unsigned int m_uiTypeBits;

	// The set of entities that this system cares about.
	std::set<Entity*> m_pActives;

	// The entity manager that we pull our information from.
	EntityManager* m_pEntityManager;

	// The event manager pointer.
	EventManager* m_pEventManager;

protected:

	// Should we update?
	virtual bool CheckProcessing() = 0;

	// A preprocessing update call.
	virtual void Begin() = 0;

	// A post processing update call.
	virtual void End() = 0;

	// Any implementing entity system must implement this method and the logic
	// to process the given entities of the system.
	virtual void ProcessEntities(EntityManager* _pManager, const std::set<Entity*>& _pEntities ) = 0;

	EventManager* GetEventManager() { return m_pEventManager; }

public:
	
	EntitySystem(EventManager* _pEventManager, EntityManager* _pEntityManager, unsigned int _uiTypeBits);
	virtual ~EntitySystem();

	// Event handler for the system.
	virtual bool HandleEvent(IEventData const& _Event);

	// The processing function that handles calling the pure virtual methods.
	void Process();
};

#endif//__ENTITY_SYSTEM_H__