#include <Common.h>
#include "GameStateManager.h"
#include "..\States\States.h"

GameStateManager* GameStateManager::GetInstance()
{
	static GameStateManager pInstance;
	return &pInstance;
}

void GameStateManager::Initialize()
{
	m_vGameStateList.clear();
	AddState(MainMenuState::GetInstance());
}

void GameStateManager::AddState(BaseGameState* pGameState)
{
	if(pGameState)
	{
		m_vGameStateList.push_back(pGameState);
		m_vGameStateList.back()->Enter();
	}
}

void GameStateManager::RemoveState()
{
	if(!m_vGameStateList.empty())
	{
		m_vGameStateList.back()->Exit();
		m_vGameStateList.pop_back();
	}
}

void GameStateManager::ChangeState(BaseGameState* pGameState)
{
	unsigned int uiSize = m_vGameStateList.size();

	for(unsigned int nState = 0; nState < uiSize; ++nState)
	{
		m_vGameStateList.back()->Exit();
		m_vGameStateList.pop_back();
	}

	m_vGameStateList.push_back(pGameState);
	m_vGameStateList.back()->Enter();
}

void GameStateManager::Update()
{
	if(m_vGameStateList.size() > 0)
	{
		m_vGameStateList.back()->CheckInput();
		m_vGameStateList.back()->Update();
	}
}

void GameStateManager::Shutdown()
{
	unsigned int uiSize = m_vGameStateList.size();

	for(unsigned int nState = 0; nState < uiSize; ++nState)
	{
		m_vGameStateList.back()->Exit();
		m_vGameStateList.pop_back();
	}

	m_vGameStateList.clear();
}