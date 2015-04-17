#include <Common.h>
#include "EntityProcessingSystem.h"

EntityProcessingSystem::EntityProcessingSystem(EventManager* _pEventManager, EntityManager* _pEntityManager, unsigned int _uiTypeBits) : EntitySystem(_pEventManager, _pEntityManager, _uiTypeBits) {}

EntityProcessingSystem::~EntityProcessingSystem() {}

bool EntityProcessingSystem::CheckProcessing() 
{ 
	return true; 
}

void EntityProcessingSystem::Begin() {}

void EntityProcessingSystem::ProcessEntities( EntityManager *manager, const std::set<Entity*> &entities )
{
	for( std::set<Entity*>::const_iterator it = entities.begin(); it != entities.end(); ++it )
	{
		ProcessEntity(manager, *it);
	}
}

void EntityProcessingSystem::End() {}