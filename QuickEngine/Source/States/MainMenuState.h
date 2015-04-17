#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_

#include "BaseGameState.h"

class MainMenuState : public BaseGameState
{
private:

	unsigned int m_uiCurrentSelection;

	MainMenuState();
	~MainMenuState(){}
	MainMenuState(MainMenuState const&){}
	MainMenuState* operator=(const MainMenuState&){}
	
public:

	void Enter();
	void Update();
	void CheckInput();
	void Exit();

	static MainMenuState* GetInstance();
	
};

#endif