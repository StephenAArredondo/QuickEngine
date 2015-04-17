#include <Common.h>
#include "Game.h"
#include <iostream>

Game::Game()
{
	m_pEntityManager = NULL;
	m_pEventManager = NULL;
	
	m_pConfig = NULL;
	m_pOpenGL = NULL;
	m_pRenderer = NULL;
	m_pGameStateManager = NULL;
	m_bRunning = true;

	m_vSystems.clear();
	m_vManagers.clear();
}
Game::~Game()
{

}

void Game::Start()
{
	m_pConfig = Config::GetInstance();
	m_pOpenGL = OpenGL::GetInstance();
	m_pRenderer = Renderer::GetInstance();

	m_pGameStateManager = GameStateManager::GetInstance();
	m_pEventManager = new EventManager();
	
	LoadSystems();

	m_pConfig->LoadConfig();
	m_pOpenGL->Initialize();

	LoadManagers();

	// create the window
	m_Window = SDL_CreateWindow("Quick Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	m_pOpenGL->InitGL();

	InitializeManagers();
	m_pGameStateManager->Initialize();
}

void Game::GameLoop()
{
	int m_nFrames = 0;
	float m_fCurrTime = 0.0f;

// 	Entity* entity = m_pEntityManager->CreateEntity();
// 	entity->SetName("PlayerEntity");
// 	m_pEntityManager->InsertComponent(entity, new InputComponent());
// 	m_pEntityManager->InsertComponent(entity, new TransformComponent(QVector3(1.0f, 3.0f, -3.0f), QQuaternion(0.0f, 0.4f, 0.0f, 4.0f), QVector3(5.0f, 5.0f, 5.0f)));
// 	m_pEntityManager->InsertComponent(entity, new DebugComponent());
// 	m_pEntityManager->InsertComponent(entity, new MeshComponent(GetMeshManager->GetMesh("ton_lowpoly_3ds\\ton3_low.3ds", true)));
// 	m_pEntityManager->InsertComponent(entity, new RenderComponent());
// 	m_pEntityManager->InsertComponent(entity, new CameraComponent());
// 	
	while(m_bRunning)
	{
		CheckEvents();

		std::map<int, std::vector<EntitySystem*>>::iterator pSystemIter = m_vSystems.begin();
		while(pSystemIter != m_vSystems.end())
		{
			for(unsigned int nIndex = 0; nIndex < pSystemIter->second.size(); ++nIndex)
				pSystemIter->second[nIndex]->Process();

			++pSystemIter;
		}		
	}

//	m_pEntityManager->DestroyEntity(entity);
}

void Game::CheckEvents()
{
	bool bAltPressed = false;
	bool bResized = false;

	GetInputManager->ClearKeys();

	// handle events
	while (m_bRunning && SDL_PollEvent(&m_Event))
	{
		// If the red X button was pressed
		if (m_Event.type == SDL_QUIT)
		{
			// end the program
			m_bRunning = false;
			continue;
		}

		else if(m_Event.type == SDL_WINDOWEVENT)
		{
			if(m_Event.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
			{
				m_pRenderer->SetWindowHasFocus(false);
				continue;
			}
			else if(m_Event.type == SDL_WINDOWEVENT_FOCUS_GAINED)
			{
				m_pRenderer->SetWindowHasFocus(true);
				continue;
			}
		}

		//////////////////////////////////////////////////////////////////////////
		// Any Keys pressed
		else if (m_Event.type == SDL_KEYDOWN)
		{
			GetInputManager->AddKey(m_Event.key.keysym.scancode);

			//////////////////////////////////////////////////////////////////////////
			// Window Close Event
			if(m_Event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				m_bRunning = false; 
				continue;
			}
			//////////////////////////////////////////////////////////////////////////


			//////////////////////////////////////////////////////////////////////////
			// Platform Specific Window Closing
#ifdef _WIN32
			if(m_Event.key.keysym.scancode == SDL_SCANCODE_LALT)
			{
				bAltPressed = true;
				continue;
			}
				
			if (bAltPressed && m_Event.key.keysym.scancode == SDL_SCANCODE_F4)
			{
				m_bRunning = false;
				bAltPressed = false;
				continue;
			}
#endif // WIN32

#ifdef __APPLE__
			if(m_Event.key.keysym.scancode == SDL_SCANCODE_LGUI) 
			{
				bAltPressed = true;
				continue;
			}

			if(bAltPressed && m_Event.key.keysym.scancode == SDL_SCANCODE_Q)
			{
				m_bRunning = false; 
				bAltPressed = false;
				continue;
			}
#endif // MAC
			//////////////////////////////////////////////////////////////////////////


			//////////////////////////////////////////////////////////////////////////
			// Handless changing the window between being borderless or not
			if(m_Event.key.keysym.scancode == SDL_SCANCODE_F10)
			{
				if(m_pConfig->GetFullScreen())
					continue;

				bool _bBorderless = !m_pConfig->GetBorderless();
				m_pConfig->SetBorderless(_bBorderless);

				//UINT _uiStyle = (_bBorderless) ? SDL_WINDOW_BORDERLESS : sf::Style::None;
// 				m_pOpenGL->SetStyle(_uiStyle);
// 				sf::Vector2i _v2iPosition = m_Window.getPosition();
// 
// 				m_Window.setPosition(_v2iPosition);
// 
// 				SetWindowStyle();
			}
			//////////////////////////////////////////////////////////////////////////


			//////////////////////////////////////////////////////////////////////////
			// Handles changing the window between being fullscreen or not
			if(m_Event.key.keysym.scancode == SDL_SCANCODE_F11)
			{
				bool _bFullScreen = !m_pConfig->GetFullScreen();
				m_pConfig->SetFullScreen(_bFullScreen);

				if(!_bFullScreen)
				{
				}

				//m_Window.create(sf::VideoMode(m_pConfig->GetScreenWidth(), m_pConfig->GetScreenHeight()), "Phantasy Engine", m_pOpenGL->GetStyle(), m_pOpenGL->GetContextSettings());
				m_pOpenGL->InitGL();
			}
			//////////////////////////////////////////////////////////////////////////
		}

		// If the window was resized
		else if (m_Event.type == SDL_WINDOWEVENT_RESIZED)
		{
			m_pConfig->SetScreenWidth(m_Event.window.data1);
			m_pConfig->SetScreenHeight(m_Event.window.data2);
			bResized = true;
		}

		bAltPressed = false;
	}

	if(bResized)
	{
		// adjust the viewport when the window is resized
		glViewport(0, 0, m_pConfig->GetScreenWidth(), m_pConfig->GetScreenHeight());
		m_pOpenGL->InitGL();
		SetWindowStyle();
	}
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
	UnloadSystems();
	UnloadManagers();

	delete m_pEventManager;

	m_pEventManager = NULL;

	m_pConfig->SaveConfig();
	m_pOpenGL->Shutdown();
	m_pRenderer->Shutdown();

	m_pGameStateManager->Shutdown();
	m_pGameStateManager = NULL;

	m_pConfig = NULL;
	m_pOpenGL = NULL;
	m_pRenderer = NULL;
}

void Game::DrawGrid()
{

	// Turn the lines GREEN
	glColor3ub(0, 255, 255);

	// Draw a 1x1 grid along the X and Z axis'
	for(float i = -50; i <= 50; i += 1)
	{
		// Start drawing some lines
		glBegin(GL_LINES);

		// Do the horizontal lines (along the X)
		glVertex3f(-50, 0, i);
		glVertex3f(50, 0, i);

		// Do the vertical lines (along the Z)
		glVertex3f(i, 0, -50);
		glVertex3f(i, 0, 50);

		// Stop drawing lines
		glEnd();
	}
}

void Game::DrawShapes()
{
	glTranslatef(-1.5f,2.0f,-6.0f);				// Move Left 1.5 Units And Into The Screen 6.0
	glColor3f(0.0f,1.0f,0.0f);					// Set The Color To Green

	// draw...
	glBegin(GL_TRIANGLES);
	glVertex3f( 0.0f, 1.0f, 0.0f);              // Top
	glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
	glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
	glEnd();

	glTranslatef(3.0f,0.0f,0.0f);                   // Move Right 3 Units

	glColor3f(0.5f,0.5f,1.0f);              // Set The Color To Blue One Time Only
	glBegin(GL_QUADS);                      // Draw A Quad
	glVertex3f(-1.0f, 1.0f, 0.0f);              // Top Left
	glVertex3f( 1.0f, 1.0f, 0.0f);              // Top Right
	glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
	glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
	glEnd();                            // Done Drawing The Quad
}

//////////////////////////////////////////////////////////////////////////
//						Systems and Managers
//////////////////////////////////////////////////////////////////////////

void Game::LoadSystems()
{
	m_vSystems[0].push_back(new InputSystem(m_pEventManager, m_pEntityManager));
	m_vSystems[1].push_back(new TransformSystem(m_pEventManager, m_pEntityManager));
	m_vSystems[3].push_back(new DebugSystem(m_pEventManager, m_pEntityManager));
	m_vSystems[5].push_back(new RenderSystem(m_pEventManager, m_pEntityManager));
}

void Game::UnloadSystems()
{
	std::map<int, std::vector<EntitySystem*>>::iterator pSystemIter = m_vSystems.begin();
	while(pSystemIter != m_vSystems.end())
	{
		for(unsigned int nIndex = 0; nIndex < pSystemIter->second.size(); ++nIndex)
		{
			delete pSystemIter->second[nIndex];
			pSystemIter->second[nIndex] = NULL;
		}

		pSystemIter->second.clear();

		++pSystemIter;
	}

	m_vSystems.clear();
}

void Game::LoadManagers()
{
	m_vManagers.push_back(GetTextureManager);
	m_vManagers.push_back(GetInputManager);
	m_vManagers.push_back(GetMeshManager);
	m_vManagers.push_back(GetCameraManager);
}

void Game::InitializeManagers()
{
	for(unsigned int nIndex = 0; nIndex < m_vManagers.size(); ++nIndex)
		m_vManagers[nIndex]->Initialize();
}

void Game::UnloadManagers()
{
	for(unsigned int nIndex = 0; nIndex < m_vManagers.size(); ++nIndex)
	{
		m_vManagers[nIndex]->Shutdown();
		m_vManagers[nIndex] = NULL;
	}

	m_vManagers.clear();
}