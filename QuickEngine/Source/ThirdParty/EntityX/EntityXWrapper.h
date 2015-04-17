#ifndef __ENTITYX_WRAPPER_H__
#define __ENTITYX_WRAPPER_H__

#include "..\ThirdParty\EntityX\Event.h"
#include "..\ThirdParty\EntityX\Entity.h"
#include "..\ThirdParty\EntityX\System.h"

using QEntity = entityx::Entity;

template<typename Derived>
using QEvent = entityx::Event<Derived>;

template<typename Derived>
using QSystem = entityx::System<Derived>;

using QEntityManager = entityx::EntityManager;

using QEventManager = entityx::EventManager;

using QSystemManager = entityx::SystemManager;

using QTimeDelta = entityx::TimeDelta;

template<typename Derived>
using QComponentHandle = entityx::ComponentHandle < Derived > ;

#endif//__ENTITYX_WRAPPER_H__