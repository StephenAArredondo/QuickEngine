#include <Common.h>
#include "RenderSystem.h"

#include "..\Managers\EntityManager.h"
#include "..\Managers\ComponentManager.h"
#include "..\Managers\CameraManager.h"

#include "..\Utilities\OpenGL.h"
#include "..\Utilities\EntityEvents.h"
#include "..\Utilities\Camera.h"

#include "..\Components\RenderComponent.h"
#include "..\Components\MeshComponent.h"
#include "..\Components\TransformComponent.h"

RenderSystem::RenderSystem(EventManager* _pEventManager, EntityManager* _pEntityManager) : EntityProcessingSystem(_pEventManager, _pEntityManager, CT_RENDERING_BIT | CT_MESH_BIT | CT_TRANSFORM_BIT){}

RenderSystem::~RenderSystem() {}

void RenderSystem::ProcessEntity(EntityManager* _pManager, Entity* _pEntity)
{
	ComponentManager<RenderComponent> RenderMapper = _pManager->GetComponentList(_pEntity, CT_RENDERING);
	ComponentManager<MeshComponent> MeshMapper = _pManager->GetComponentList(_pEntity, CT_MESH);
	ComponentManager<TransformComponent> TransformMapper = _pManager->GetComponentList(_pEntity, CT_TRANSFORM);

	glPushMatrix();

	glTranslatef(TransformMapper[0]->m_v3Translation.x, TransformMapper[0]->m_v3Translation.y, TransformMapper[0]->m_v3Translation.z);
	glRotatef(TransformMapper[0]->m_qRotation.w, TransformMapper[0]->m_qRotation.x, TransformMapper[0]->m_qRotation.y, TransformMapper[0]->m_qRotation.z);
	glScalef(TransformMapper[0]->m_v3Scale.x, TransformMapper[0]->m_v3Scale.y, TransformMapper[0]->m_v3Scale.z);

	Draw(MeshMapper[0]->m_pMesh);

	glPopMatrix();
}

void RenderSystem::Begin()
{
	// clear the buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);

	CameraManager::GetInstance()->GetActiveCamera()->Look();
}

void RenderSystem::End()
{

}

void RenderSystem::Draw(Mesh* _pMesh)
{
	glColor3ub(255, 0, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_TRIANGLES);

	for (int i = 0; i < _pMesh->GetNumTriangles(); ++i)
	{
		glTexCoord2f(_pMesh->GetUV1((GLuint)_pMesh->GetTriangle(i).x).x, _pMesh->GetUV1((GLuint)_pMesh->GetTriangle(i).x).y);
		glVertex3f(_pMesh->GetVert((GLuint)_pMesh->GetTriangle(i).x).x, _pMesh->GetVert((GLuint)_pMesh->GetTriangle(i).x).y, _pMesh->GetVert((GLuint)_pMesh->GetTriangle(i).x).z);

		glTexCoord2f(_pMesh->GetUV1((GLuint)_pMesh->GetTriangle(i).y).x, _pMesh->GetUV1((GLuint)_pMesh->GetTriangle(i).y).y);
		glVertex3f(_pMesh->GetVert((GLuint)_pMesh->GetTriangle(i).y).x, _pMesh->GetVert((GLuint)_pMesh->GetTriangle(i).y).y, _pMesh->GetVert((GLuint)_pMesh->GetTriangle(i).y).z);

		glTexCoord2f(_pMesh->GetUV1((GLuint)_pMesh->GetTriangle(i).z).x, _pMesh->GetUV1((GLuint)_pMesh->GetTriangle(i).z).y);
		glVertex3f(_pMesh->GetVert((GLuint)_pMesh->GetTriangle(i).z).x, _pMesh->GetVert((GLuint)_pMesh->GetTriangle(i).z).y, _pMesh->GetVert((GLuint)_pMesh->GetTriangle(i).z).z);
	}

	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}