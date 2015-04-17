#include <Common.h>
#include "MainMenuState.h"

MainMenuState* MainMenuState::GetInstance()
{
	static MainMenuState pInstance;
	return &pInstance;
}

MainMenuState::MainMenuState() : BaseGameState(MAINMENU_STATE)
{
	m_uiCurrentSelection = 0;
}

void MainMenuState::Enter()
{

}

void MainMenuState::Update()
{

}

void MainMenuState::CheckInput()
{
// 	if(SDL_GetKey(sf::Keyboard::Down))
// 	{
// 		m_uiCurrentSelection += 1;
// 
// 		if(m_uiCurrentSelection > 5)
// 			m_uiCurrentSelection = 0;
// 	}
// 	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
// 	{
// 		m_uiCurrentSelection -= 1;
// 
// 		if(m_uiCurrentSelection < 0)
// 			m_uiCurrentSelection = 5;
// 	}
}

void MainMenuState::Exit()
{
	
}