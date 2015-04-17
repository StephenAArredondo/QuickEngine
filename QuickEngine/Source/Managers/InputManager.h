#ifndef __INPUTMANAGER_H__
#define __INPUTMANAGER_H__

#include "BaseManager.h"
#include "..\Utilities\Common.h"
#include <vector>

class InputManager : public BaseManager
{
private:

	std::vector<SDL_Scancode> m_vKeys;

	InputManager();
	~InputManager();
	InputManager(const InputManager&){}
	InputManager* operator=(const InputManager&){}

	//std::map<SDL_Scancode, std::string> m_vKeys;

public:

	void Initialize();
	void Shutdown();

	static InputManager* GetInstance();
	std::vector<SDL_Scancode>& GetKeys() { return m_vKeys; }

	void AddKey(SDL_Scancode _key) { m_vKeys.push_back(_key); }
	void ClearKeys() { m_vKeys.clear(); }

	std::string ConvertToString(SDL_Scancode _key);
};

#endif