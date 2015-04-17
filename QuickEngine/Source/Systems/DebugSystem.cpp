#include <Common.h>
#include "DebugSystem.h"
#include "..\Managers\EntityManager.h"
#include "EntitySystem.h"
#include "..\Managers\ComponentManager.h"
#include "..\Managers\InputManager.h"
#include "..\Managers\EventManager.h"

#include "..\Components\Components.h"
#include <iostream>
#include <iterator>
#include <string>

DebugSystem::DebugSystem(EventManager* _pEventManager, EntityManager* _pEntityManager) : EntityProcessingSystem(_pEventManager, _pEntityManager, CT_DEBUG_BIT | CT_INPUT_BIT) 
{
	GetEventManager()->AddListener(this, EComponentEvent::EVENT_TRANSFORM_TRANSLATED);
}

DebugSystem::~DebugSystem() 
{
	GetEventManager()->RemoveListener(this, EComponentEvent::EVENT_TRANSFORM_TRANSLATED);
}

void DebugSystem::ProcessEntity(EntityManager* _pManager, Entity* _pEntity)
{
	//ComponentManager<TransformComponent> transformMap = _pManager->GetComponentList(_pEntity, CT_TRANSFORM);
	ComponentManager<DebugComponent> vDebug = _pManager->GetComponentList(_pEntity, CT_DEBUG);
	ComponentManager<InputComponent> vInput = _pManager->GetComponentList(_pEntity, CT_INPUT);

	

	if(vDebug.GetSize() > 0 && vInput.GetSize() > 0)
	{
		for(unsigned int nIndex = 0; nIndex < vInput[0]->m_vKeys.size(); ++nIndex)
		{
			SDL_Scancode key = vInput[0]->m_vKeys[nIndex];
			std::cout << InputManager::GetInstance()->ConvertToString(key).c_str() << "\n";						
		}
	}
}

bool DebugSystem::HandleEvent(IEventData const& _Event)
{
	return false;
}
