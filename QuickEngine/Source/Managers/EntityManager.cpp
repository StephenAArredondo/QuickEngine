#include <Common.h>
#include "EntityManager.h"
#include "EventManager.h"
#include "..\Utilities\EntityEvents.h"
#include "..\Components\BaseComponent.h"

ComponentList EntityManager::EmptyList;

using namespace EComponentType;
using namespace EEntityEvent;

EntityManager* EntityManager::GetInstance()
{
	static EntityManager pInstance;
	return &pInstance;
}

EntityManager::EntityManager()
{
	m_pEventSystem = nullptr;
	m_vComponents.resize(CT_LAST);
	m_NextID = 0;
}

EntityManager::~EntityManager()
{
	if(m_bInitialized)
		Shutdown();
}

void EntityManager::Initialize()
{	
	m_bInitialized = true;
}

void EntityManager::Shutdown()
{
	DestroyAllEntities();

	// Clear the list of entities.
	m_vEntities.clear();
	m_vComponents.clear();
	m_vRemovedIndices.clear();
}

Entity *EntityManager::CreateEntity()
{
	Entity* pEntity = new Entity(m_NextID++);

	// Do we have previously removed slot indices that we can reuse?
	if(m_vRemovedIndices.size())
	{
		pEntity->m_uiIndex = m_vRemovedIndices.back();
		m_vRemovedIndices.pop_back();

		// Resize the vector if we need .
		if( pEntity->m_uiIndex >= m_vEntities.size() ) 
			m_vEntities.resize(pEntity->m_uiIndex+1, NULL);

		m_vEntities[pEntity->m_uiIndex] = pEntity;
	}
	else 
	{
		pEntity->m_uiIndex = m_vEntities.size();
		m_vEntities.push_back(pEntity);
	}

	// Inform the world that we just created an entity.
	m_pEventSystem->FireEvent(EntityEvent(EVENT_CREATE_ENTITY, pEntity));

	// Return a reference to the element itself.
	return pEntity;
}

void EntityManager::DestroyAllEntities()
{
	for(int nEntity = 0; nEntity < m_vEntities.size(); nEntity++)
		DestroyAllComponents(m_vEntities[nEntity]);
}

void EntityManager::DestroyEntity(Entity* _pEntity)
{
	m_vEntities[_pEntity->m_uiIndex] = NULL;
	m_vRemovedIndices.push_back(_pEntity->m_uiIndex);

	DestroyAllComponents(_pEntity);

	// Inform the world that we just destroyed an entity.
	m_pEventSystem->FireEvent(EntityEvent(EVENT_DESTROY_ENTITY, _pEntity));

	delete _pEntity;
}

void EntityManager::InsertComponent(Entity* _pEntity, BaseComponent* _pComponent)
{
	std::vector<ComponentList>& pEntities = m_vComponents[_pComponent->GetType()];

	// Resize the vector if we need to.
	if(_pEntity->m_uiIndex >= pEntities.size())
		pEntities.resize(_pEntity->m_uiIndex + 1);

	// Grab the component list for this entity and add the component.
	ComponentList& pList = pEntities[_pEntity->m_uiIndex];
	pList.push_back(_pComponent);

	// Set the entity's bit for this component.
	_pEntity->m_uiTypeBits |= _pComponent->GetTypeBit();

	// Inform the world that we just inserted a component.
	m_pEventSystem->FireEvent(ComponentEvent(EVENT_INSERT_COMPONENT, _pEntity, _pComponent->GetType()));
}

void EntityManager::RemoveComponent(Entity* _pEntity, BaseComponent* _pComponent)
{
	std::vector<ComponentList>& pEntities = m_vComponents[_pComponent->GetType()];

	// Skip if we don't even have the space allocated.
	if(_pEntity->m_uiIndex >= pEntities.size()) 
		return;

	// Grab the component list for this entity and remove the component.
	ComponentList& pList = pEntities[_pEntity->m_uiIndex];

	for(ComponentList::iterator pIter = pList.begin(); pIter != pList.end(); ++pIter)
	{
		if((*pIter) == _pComponent)
			pList.erase(pIter);
	}

	// Remove the component bit if we don't have any more of this component type.
	if(pList.size() == 0 ) 
		_pEntity->m_uiTypeBits &= ~_pComponent->GetTypeBit();

	// Inform the world that we just removed a component.
	m_pEventSystem->FireEvent(ComponentEvent(EVENT_REMOVE_COMPONENT, _pEntity, _pComponent->GetType()));
}

void EntityManager::DestroyAllComponents(Entity* _pEntity)
{
	for(int nType = 0; nType < CT_LAST; nType++)
		DestroyAllComponents(_pEntity, (eComponentType)nType);
}

void EntityManager::DestroyAllComponents(Entity* _pEntity, eComponentType _eType)
{
	std::vector<ComponentList>& pEntities = m_vComponents[_eType];

	// Skip if we don't even have the space allocated.
	if(_pEntity->m_uiIndex >= pEntities.size()) 
		return;

	// Grab the component list for this entity and remove the component.
	ComponentList& pList = pEntities[_pEntity->m_uiIndex];

	// Delete the components
	while(pList.size())
	{
		delete pList.back();
		pList.pop_back();

		// Remove the bit precisely when we get to the last component, prior to firing the event.
		if(pList.size() == 0) 
			_pEntity->m_uiTypeBits &= ~(1 << _eType);

		// Inform the world that we just removed a component.
		m_pEventSystem->FireEvent(ComponentEvent(EVENT_REMOVE_COMPONENT, _pEntity, (eComponentType)_eType));
	}	

	// Clear the list.
	pList.clear();
}

const ComponentList& EntityManager::GetComponentList(const Entity* _pEntity, eComponentType _eType) const
{
	const std::vector<ComponentList>& pEntities = m_vComponents[_eType];

	// Return a blank list if we don't even have the space allocated.
	if(_pEntity->m_uiIndex >= pEntities.size()) 
		return EmptyList;

	// Grab the component list for this entity and remove the component.
	return pEntities[_pEntity->m_uiIndex];
}