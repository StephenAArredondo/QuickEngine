#include <Common.h>
#include "InputSystem.h"

#include "..\Managers\EntityManager.h"
#include "..\Managers\ComponentManager.h"
#include "..\Managers\InputManager.h"
#include "..\Managers\CameraManager.h"

#include "..\Components\InputComponent.h"

#include "..\Utilities\Camera.h"

using namespace EComponentEvent;

InputSystem::InputSystem(EventManager* _pEventManager, EntityManager* _pEntityManager) : EntityProcessingSystem(_pEventManager, _pEntityManager, CT_INPUT_BIT) {}

InputSystem::~InputSystem() {}

void InputSystem::Begin()
{
	CameraManager::GetInstance()->GetActiveCamera()->CheckInput();
}

void InputSystem::ProcessEntity(EntityManager* _pManager, Entity* _pEntity)
{
	ComponentManager<InputComponent> vInput = _pManager->GetComponentList(_pEntity, CT_INPUT);

	if(vInput.GetSize() > 0)
	{
		vInput[0]->m_vKeys.clear();
		vInput[0]->m_vKeys = InputManager::GetInstance()->GetKeys();
	}
}

void InputSystem::End()
{

}
