#include <Common.h>
#include "InputSystem.h"

#include <SDL.h>

void InputSystem::update(QEntityManager& entities, QEventManager& events, QTimeDelta dt)
{
	SDL_Event inputEvent;
	while (SDL_PollEvent(&inputEvent))
	{
		if (inputEvent.type == SDL_KEYDOWN)
		{
			InputEvent newInput(inputEvent.key.keysym.scancode);
			events.emit<InputEvent>(newInput);

			for (auto entity : entities.entities_with_components<InputComponent>())
			{
				EntityInputEvent newEntityInput(&entity, inputEvent.key.keysym.scancode);
				events.emit<EntityInputEvent>(newEntityInput);
			}
		}
	}

	const uint8_t* keys = SDL_GetKeyboardState(nullptr);
	for (auto entity : entities.entities_with_components<InputComponent>())
	{
		KeyboardEvent keyboardevent(&entity, keys);
		events.emit<KeyboardEvent>(keyboardevent);
	}
}

/*
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

	else if (m_Event.type == SDL_WINDOWEVENT)
	{
		if (m_Event.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
		{
			m_pRenderer->SetWindowHasFocus(false);
			continue;
		}
		else if (m_Event.type == SDL_WINDOWEVENT_FOCUS_GAINED)
		{
			m_pRenderer->SetWindowHasFocus(true);
			continue;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	// Any Keys pressed
	else if (m_Event.type == SDL_KEYDOWN)
	{
		//GetInputManager->AddKey(m_Event.key.keysym.scancode);

		//////////////////////////////////////////////////////////////////////////
		// Window Close Event
		if (m_Event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		{
			m_bRunning = false;
			continue;
		}
		//////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////
		// Platform Specific Window Closing
#ifdef _WIN32
		if (m_Event.key.keysym.scancode == SDL_SCANCODE_LALT)
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
		if (m_Event.key.keysym.scancode == SDL_SCANCODE_LGUI)
		{
			bAltPressed = true;
			continue;
		}

		if (bAltPressed && m_Event.key.keysym.scancode == SDL_SCANCODE_Q)
		{
			m_bRunning = false;
			bAltPressed = false;
			continue;
		}
#endif // MAC
		//////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////
		// Handless changing the window between being borderless or not
		if (m_Event.key.keysym.scancode == SDL_SCANCODE_F10)
		{
			if (m_pConfig->GetFullScreen())
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
		if (m_Event.key.keysym.scancode == SDL_SCANCODE_F11)
		{
			bool _bFullScreen = !m_pConfig->GetFullScreen();
			m_pConfig->SetFullScreen(_bFullScreen);

			if (!_bFullScreen)
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

if (bResized)
{
	// adjust the viewport when the window is resized
	glViewport(0, 0, m_pConfig->GetScreenWidth(), m_pConfig->GetScreenHeight());
	m_pOpenGL->InitGL();
	SetWindowStyle();
}

*/