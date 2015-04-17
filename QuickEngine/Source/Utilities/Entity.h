#ifndef __ENTITY_H__
#define __ENTITY_H__

typedef unsigned int EntityID;

const EntityID NULL_ENTITY = 0;

class Entity
{
	friend class EntityManager;
	friend class EntitySystem;

private:

	EntityID m_EntityID;
	unsigned int m_uiIndex;
	unsigned int m_uiTypeBits;

	const char* m_szName;
	bool m_bActive;

	Entity(EntityID _EntityID) : m_EntityID(_EntityID), m_uiIndex(0), m_uiTypeBits(0) {}

public:

	~Entity() {}

	EntityID GetEntityID() { return m_EntityID; }
	const char* GetName() { return m_szName; }
	bool GetActive() { return m_bActive; }

	void SetActive(bool _bActive) { m_bActive = _bActive; }
	void SetName(const char* _strName) { m_szName = _strName; }
};

#endif//__ENTITY_H__