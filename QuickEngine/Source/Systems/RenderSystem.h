#ifndef __RENDERSYSTEM_H__
#define __RENDERSYSTEM_H__

#include "EntityProcessingSystem.h"

class Mesh;

class RenderSystem : public EntityProcessingSystem
{
protected:

	virtual void Begin();
	virtual void ProcessEntity(EntityManager* _pManager, Entity* _pEntity);
	virtual void End();

	virtual void Draw(Mesh* _pMesh);

public:
	RenderSystem(EventManager* _pEventManager, EntityManager* _pEntityManager);
	virtual ~RenderSystem();

};

#endif