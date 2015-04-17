#ifndef _GAME_H_
#define _GAME_H_

#include "Utilities\Common.h"
#include "Utilities\Config.h"
#include "Utilities\Renderer.h"
#include "Utilities\Timer.h"
#include "Utilities\OpenGL.h"
#include "Utilities\FPS.h"
#include "Utilities\Camera.h"
//#include "Utilities\Mesh.h"

#include "Systems\Systems.h"
#include "Managers\Managers.h"
#include "Components\Components.h"


class Game
{
private:

	// Systems
	std::map<int, std::vector<EntitySystem*>> m_vSystems;
	std::vector<BaseManager*> m_vManagers;

	// Managers
	EventManager* m_pEventManager;
	EntityManager* m_pEntityManager;
	GameStateManager* m_pGameStateManager;

	SDL_Window* m_Window;
	SDL_Event m_Event;
	bool m_bRunning;
	CTimer m_Timer;

	FPS m_FPS;

	Config* m_pConfig;
	OpenGL* m_pOpenGL;
	Renderer* m_pRenderer;

	Camera m_Camera;

	void CheckEvents();
	void SetWindowStyle();

public:

	Game();
	~Game();

	void Start();
	void LoadSystems();
	void UnloadSystems();

	void LoadManagers();
	void InitializeManagers();
	void UnloadManagers();

	void GameLoop();
	void Shutdown();
	void Draw();

	void DrawShapes();
	void DrawGrid();
};

#endif