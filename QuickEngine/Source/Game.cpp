#include <Common.h>
#include "Game.h"

Game::Game()
{
	m_EntityManager = NULL;
	m_EventManager = NULL;
	m_SystemManager = NULL;
	
	m_pConfig = NULL;
	m_pOpenGL = NULL;
	//m_pGameStateManager = NULL;
	m_bRunning = true;
}

Game::~Game()
{

}

void Game::Start()
{
	m_pConfig = Config::GetInstance();
	m_pOpenGL = OpenGL::GetInstance();
	
	m_EventManager = new QEventManager();
	m_EntityManager = new QEntityManager((*m_EventManager));
	m_SystemManager = new QSystemManager((*m_EntityManager), (*m_EventManager));

	//m_pGameStateManager = GameStateManager::GetInstance();

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetSwapInterval(1);

	// create the window
	m_Window = SDL_CreateWindow("Quick Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);

	m_GLContext = SDL_GL_CreateContext(m_Window);

	SDL_InitSubSystem(SDL_INIT_EVENTS);

	LoadSystems();

	m_pConfig->LoadConfig();
	m_pOpenGL->Initialize();

	m_pOpenGL->InitGL();

	m_EventManager->subscribe<InputEvent>((*this));

	//m_pGameStateManager->Initialize();
}

void Game::GameLoop()
{
	int m_nFrames = 0;
	uint32_t currTime = 0;
	uint32_t prevTime = 0;
	uint32_t deltaTime = 0;

// 	Entity* entity = m_pEntityManager->CreateEntity();
// 	entity->SetName("PlayerEntity");
// 	m_pEntityManager->InsertComponent(entity, new MeshComponent(GetMeshManager->GetMesh("ton_lowpoly_3ds\\ton3_low.3ds", true)));
// 	m_pEntityManager->InsertComponent(entity, new RenderComponent());
// 	

	//test.assign<DebugComponent>("Test String");
	QEntity camera = m_EntityManager->create();
	camera.assign<CameraComponent>(QMatrix::Identity(), true, true);
	camera.assign<InputComponent>();

	QEntity test = m_EntityManager->create();
	test.assign<TransformComponent>(QVector3(0.0, 15.0, -10.0), QQuaternion::Zero(), QVector3::Identity());
	test.assign<RenderComponent>();
	
	while(m_bRunning)
	{
		currTime = SDL_GetTicks();

		if (currTime > prevTime)
		{
			deltaTime = currTime - prevTime;
			m_SystemManager->update_all(deltaTime);

			prevTime = currTime;
		}
	}

//	m_pEntityManager->DestroyEntity(entity);
}

void Game::CheckEvents()
{
	bool bAltPressed = false;
	bool bResized = false;

//	GetInputManager->ClearKeys();

	
}

void Game::SetWindowStyle()
{
#ifdef _WIN32
// 	HWND hWnd = m_Window.getSystemHandle();
// 	DWORD dwStyle = WS_VISIBLE;
// 
// 	if(m_pOpenGL->GetStyle() == sf::Style::None)
// 		dwStyle |= WS_POPUP;
// 	else
// 	{
// 		if(m_pOpenGL->GetStyle() & sf::Style::Titlebar)
// 			dwStyle |= WS_CAPTION | WS_MINIMIZEBOX;
// 
// 		if(m_pOpenGL->GetStyle() & sf::Style::Resize)
// 			dwStyle |= WS_THICKFRAME | WS_MAXIMIZEBOX;
// 
// 		if(m_pOpenGL->GetStyle() & sf::Style::Close)
// 			dwStyle |= WS_SYSMENU;
// 	}
// 
// 	SetWindowLongPtr(hWnd, GWL_STYLE, dwStyle);
// 
// 	SetWindowPos(hWnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_DRAWFRAME);

#endif
}

void Game::Shutdown()
{
	//UnloadSystems();
	//UnloadManagers();

	m_EventManager->unsubscribe<InputEvent>((*this));

	m_EventManager->~EventManager();
	m_EventManager = NULL;

	m_EntityManager->reset();
	m_EntityManager->~EntityManager();
	m_EntityManager = NULL;

	m_SystemManager->~SystemManager();
	m_SystemManager = NULL;

	m_pConfig->SaveConfig();
	m_pOpenGL->Shutdown();
//	m_pRenderer->Shutdown();

// 	m_pGameStateManager->Shutdown();
// 	m_pGameStateManager = NULL;

	m_pConfig = NULL;
	m_pOpenGL = NULL;
//	m_pRenderer = NULL;
}

void Game::LoadSystems()
{
	m_SystemManager->add<CameraSystem>(m_Window);
	m_SystemManager->add<InputSystem>();
	m_SystemManager->add<TransformSystem>();
	m_SystemManager->add<DebugSystem>();
	m_SystemManager->add<RenderSystem>(m_Window);
	m_SystemManager->configure();
}

void Game::UnloadSystems()
{
	
}

void Game::receive(const InputEvent& input)
{
	if (input.m_Input == SDL_SCANCODE_ESCAPE)
	{
		// end the program
		m_bRunning = false;		
	}
}