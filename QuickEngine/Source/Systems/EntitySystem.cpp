#include <Common.h>
#include "EntitySystem.h"
#include "..\Utilities\EntityEvents.h"
#include "..\Managers\EventManager.h"

using namespace EEntityEvent;

EntitySystem::EntitySystem(EventManager* _pEventManager, EntityManager* _pEntityManager, unsigned int _uiTypeBits)
{
	m_pEventManager = _pEventManager;
	m_pEntityManager = _pEntityManager;
	m_uiTypeBits = _uiTypeBits;

	// Register this system for component events.
	m_pEventManager->AddListener(this, EVENT_INSERT_COMPONENT);
	m_pEventManager->AddListener(this, EVENT_REMOVE_COMPONENT);
}

EntitySystem::~EntitySystem()
{
	m_pEventManager->RemoveListener(this, EVENT_INSERT_COMPONENT);
	m_pEventManager->RemoveListener(this, EVENT_REMOVE_COMPONENT);

	m_pActives.clear();
}

void EntitySystem::Process()
{
	if(CheckProcessing())
	{
		Begin();
		ProcessEntities(m_pEntityManager, m_pActives);
		End();
	}
}

bool EntitySystem::HandleEvent(IEventData const& _pEvent)
{
	EventType pType = _pEvent.GetType();
	switch(pType)
	{
	case EVENT_INSERT_COMPONENT:
	case EVENT_REMOVE_COMPONENT:
		{
			const EntityEvent& pData = static_cast<const EntityEvent&>(_pEvent);
			Entity* pEntity = pData.m_pEntity;

			// Does this entity meet our requirements?
			if((pEntity->m_uiTypeBits & m_uiTypeBits ) == m_uiTypeBits)
				m_pActives.insert(pEntity);
			else
				m_pActives.erase(pEntity);

			break;
		}
	}

	return false;
}