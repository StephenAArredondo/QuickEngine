#include <Common.h>
#include "TransformSystem.h"

#include "..\Managers\EntityManager.h"
#include "..\Utilities\EntityEvents.h"
#include "..\Managers\ComponentManager.h"

#include "..\Components\TransformComponent.h"
#include "..\Components\InputComponent.h"

using namespace EComponentEvent;

TransformSystem::TransformSystem(EventManager* _pEventManager, EntityManager* _pEntityManager) : EntityProcessingSystem(_pEventManager, _pEntityManager, CT_TRANSFORM_BIT) {}

TransformSystem::~TransformSystem() {}

void TransformSystem::ProcessEntity(EntityManager* _pManager, Entity* _pEntity)
{
	ComponentManager<TransformComponent> transformMapper = _pManager->GetComponentList(_pEntity, CT_TRANSFORM);
}

void TransformSystem::Translate(Entity* _pEntity)
{
//	m_pEventManager->FireEvent(ComponentEvent(EVENT_TRANSFORM_TRANSLATED, _pEntity, ));
}

void TransformSystem::Rotate(Entity* _pEntity)
{

}

void TransformSystem::Scale(Entity* _pEntity)
{

}