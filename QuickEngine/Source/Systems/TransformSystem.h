#ifndef __TRANSFORMSYSTEM_H__
#define __TRANSFORMSYSTEM_H__

#include "EntityProcessingSystem.h"

class TransformSystem : public EntityProcessingSystem
{
protected:
	virtual void ProcessEntity(EntityManager* _pManager, Entity* _pEntity);

public:
	TransformSystem(EventManager* _pEventManager, EntityManager* _pEntityManager);
	virtual ~TransformSystem();

	void Translate(Entity* _pEntity);
	void Rotate(Entity* _pEntity);
	void Scale(Entity* _pEntity);

};

#endif