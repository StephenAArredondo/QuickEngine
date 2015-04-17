#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#include "BaseManager.h"

#include "..\Utilities\Entity.h"
#include "..\Components\ComponentType.h"

using namespace EComponentType;

class BaseComponent;
class EventManager;

typedef std::vector<BaseComponent*> ComponentList;


class EntityManager : public BaseManager
{
private:

	EventManager* m_pEventSystem;

	std::vector<unsigned int> m_vRemovedIndices;
	std::vector<Entity*> m_vEntities;
	std::vector<std::vector<ComponentList>> m_vComponents;

	EntityID m_NextID;

	static ComponentList EmptyList;

	EntityManager();
	~EntityManager();
	EntityManager(const EntityManager&) {}
	EntityManager* operator=(const EntityManager&) {}

public:

	void Initialize();
	void Shutdown();

	Entity* CreateEntity();

	void DestroyEntity(Entity* _pEntity);
	
	void DestroyAllEntities();

	void InsertComponent(Entity* _pEntity, BaseComponent* _pComponent);
	
	void RemoveComponent(Entity* _pEntity, BaseComponent* _pComponent);
	
	void DestroyAllComponents(Entity* _pEntity);
	
	void DestroyAllComponents(Entity* _pEntity, eComponentType _eType);

	const ComponentList& GetComponentList(const Entity* _pEntity, eComponentType _eType) const;

	static EntityManager* GetInstance();
};

#endif