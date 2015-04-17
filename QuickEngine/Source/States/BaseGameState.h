#ifndef _BASEGAMESTATE_H_ 
#define	_BASEGAMESTATE_H_

enum eGameStateID{UNITIALIZED = 0, SPLASH_STATE, MAINMENU_STATE, OPTIONS_STATE, GAMEPLAY_STATE};

class BaseGameState
{
private:
	eGameStateID m_eGameStateID;

public:
	BaseGameState(){}
	BaseGameState(eGameStateID eGameStateID) : m_eGameStateID(eGameStateID) {}
	~BaseGameState(){};
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void CheckInput() = 0;
	virtual void Exit() = 0;

};

#endif