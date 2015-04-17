#ifndef _GAMESTATEMANAGER_H_
#define _GAMESTATEMANAGER_H_

#include <vector>
class BaseGameState;

class GameStateManager
{
private:

	std::vector<BaseGameState*> m_vGameStateList;
	
	GameStateManager(){}
	~GameStateManager(){}
	GameStateManager(GameStateManager const&){}
	GameStateManager* operator=(const GameStateManager&){}

public:
	

	
	void Initialize();
	void AddState(BaseGameState* pGameState);
	void RemoveState();
	void ChangeState(BaseGameState* pGameState);
	void Update();
	void Shutdown();

	static GameStateManager* GetInstance();
};

#endif