#ifndef __MANAGERS_H__
#define __MANAGERS_H__

#include "ComponentManager.h"
#include "EntityManager.h"
#include "EventManager.h"

#include "GameStateManager.h"

#include "MeshManager.h"
#include "ModelManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "CameraManager.h"

#define GetMeshManager MeshManager::GetInstance()
#define GetTextureManager TextureManager::GetInstance()
#define GetInputManager InputManager::GetInstance()
#define GetCameraManager CameraManager::GetInstance()
#define GetEntityManager EntityManager::GetInstance()

#endif