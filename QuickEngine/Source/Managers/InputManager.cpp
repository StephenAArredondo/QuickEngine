#include <Common.h>
#include "InputManager.h"

InputManager* InputManager::GetInstance()
{
	static InputManager pInstance;
	return &pInstance;
}

InputManager::InputManager()
{
	m_bInitialized = false;
	m_vKeys.reserve(16);
}

InputManager::~InputManager()
{
	if(m_bInitialized)
		Shutdown();
}

void InputManager::Initialize()
{
// 	m_vKeys[SDL_SCANCODE_A] = "A";
// 	m_vKeys[SDL_SCANCODE_B] = "B";
// 	m_vKeys[SDL_SCANCODE_C] = "C";
// 	m_vKeys[SDL_SCANCODE_D] = "D"; 
// 	m_vKeys[SDL_SCANCODE_E] = "E"; 
// 	m_vKeys[SDL_SCANCODE_F] = "F"; 
// 	m_vKeys[SDL_SCANCODE_G] = "G"; 
// 	m_vKeys[SDL_SCANCODE_H] = "H"; 
// 	m_vKeys[SDL_SCANCODE_I] = "I"; 
// 	m_vKeys[SDL_SCANCODE_J] = "J"; 
// 	m_vKeys[SDL_SCANCODE_K] = "K"; 
// 	m_vKeys[SDL_SCANCODE_L] = "L"; 
// 	m_vKeys[SDL_SCANCODE_M] = "M"; 
// 	m_vKeys[SDL_SCANCODE_N] = "N"; 
// 	m_vKeys[SDL_SCANCODE_O] = "O"; 
// 	m_vKeys[SDL_SCANCODE_P] = "P"; 
// 	m_vKeys[SDL_SCANCODE_Q] = "Q"; 
// 	m_vKeys[SDL_SCANCODE_R] = "R"; 
// 	m_vKeys[SDL_SCANCODE_S] = "S"; 
// 	m_vKeys[SDL_SCANCODE_T] = "T"; 
// 	m_vKeys[SDL_SCANCODE_U] = "U"; 
// 	m_vKeys[SDL_SCANCODE_V] = "V"; 
// 	m_vKeys[SDL_SCANCODE_W] = "W"; 
// 	m_vKeys[SDL_SCANCODE_X] = "X"; 
// 	m_vKeys[SDL_SCANCODE_Y] = "Y"; 
// 	m_vKeys[SDL_SCANCODE_Z] = "Z";
// 	m_vKeys[SDL_SCANCODE_0] = "Num0";
// 	m_vKeys[SDL_SCANCODE_1] = "Num1";
// 	m_vKeys[SDL_SCANCODE_2] = "Num2";
// 	m_vKeys[SDL_SCANCODE_3] = "Num3";
// 	m_vKeys[SDL_SCANCODE_4] = "Num4";
// 	m_vKeys[SDL_SCANCODE_5] = "Num5";
// 	m_vKeys[SDL_SCANCODE_6] = "Num6";
// 	m_vKeys[SDL_SCANCODE_7] = "Num7";
// 	m_vKeys[SDL_SCANCODE_8] = "Num8";
// 	m_vKeys[SDL_SCANCODE_9] = "Num9";
// 	m_vKeys[SDL_SCANCODE_ESCAPE] = "Escape";
// 	m_vKeys[SDL_SCANCODE_LCTRL] = "LControl";
// 	m_vKeys[SDL_SCANCODE_LSHIFT] = "LShift";
// 	m_vKeys[SDL_SCANCODE_LALT] = "LAlt";
// 	m_vKeys[SDL_SCANCODE_LGUI] = "LSystem";
// 	m_vKeys[SDL_SCANCODE_RCTRL] = "RControl";
// 	m_vKeys[SDL_SCANCODE_RSHIFT] = "RShift";
// 	m_vKeys[SDL_SCANCODE_RALT] = "RAlt";
// 	m_vKeys[SDL_SCANCODE_RGUI] = "RSystem";
// 	m_vKeys[SDL_SCANCODE_MENU] = "Menu";
// 	m_vKeys[SDL_SCANCODE_LEFTBRACKET] = "LBracket";
// 	m_vKeys[SDL_SCANCODE_RIGHTBRACKET] = "RBracket";
// 	m_vKeys[SDL_SCANCODE_SEMICOLON] = "SemiColon";
// 	m_vKeys[SDL_SCANCODE_COMMA] = "Comma";
// 	m_vKeys[SDL_SCANCODE_PERIOD] = "Period";
// 	m_vKeys[SDL_SCANCODE_APOSTROPHE] = "Apostrophe";
// 	m_vKeys[SDL_SCANCODE_SLASH] = "Slash";
// 	m_vKeys[SDL_SCANCODE_BACKSLASH] = "BackSlash";
// 	m_vKeys[SDL_SCANCODE_GRAVE] = "Tilde";
// 	m_vKeys[SDL_SCANCODE_EQUALS] = "Equal";
// 	m_vKeys[SDL_SCANCODE_MINUS] = "Minus";
// 	m_vKeys[SDL_SCANCODE_SPACE] = "Space";
// 	m_vKeys[SDL_SCANCODE_RETURN] = "Return";
// 	m_vKeys[SDL_SCANCODE_BACKSPACE] = "Backspace";
// 	m_vKeys[SDL_SCANCODE_TAB] = "Tab";
// 	m_vKeys[SDL_SCANCODE_PAGEUP] = "PageUp";
// 	m_vKeys[SDL_SCANCODE_PAGEDOWN] = "PageDown";
// 	m_vKeys[SDL_SCANCODE_END] = "End";
// 	m_vKeys[SDL_SCANCODE_HOME] = "Home";
// 	m_vKeys[SDL_SCANCODE_INSERT] = "Insert";
// 	m_vKeys[SDL_SCANCODE_DELETE] = "Delete";
// 	m_vKeys[SDL_SCANCODE_KP_PLUS] = "Add";
// 	m_vKeys[SDL_SCANCODE_KP_MINUS] = "Subtract";
// 	m_vKeys[SDL_SCANCODE_KP_MULTIPLY] = "Multiply";
// 	m_vKeys[SDL_SCANCODE_KP_DIVIDE] = "Divide";
// 	m_vKeys[SDL_SCANCODE_LEFT] = "Left";
// 	m_vKeys[SDL_SCANCODE_RIGHT] = "Right";
// 	m_vKeys[SDL_SCANCODE_UP] = "Up";
// 	m_vKeys[SDL_SCANCODE_DOWN] = "Down";
// 	m_vKeys[SDL_SCANCODE_KP_0] = "Numpad0";
// 	m_vKeys[SDL_SCANCODE_KP_1] = "Numpad1";
// 	m_vKeys[SDL_SCANCODE_KP_2] = "Numpad2";
// 	m_vKeys[SDL_SCANCODE_KP_3] = "Numpad3";
// 	m_vKeys[SDL_SCANCODE_KP_4] = "Numpad4";
// 	m_vKeys[SDL_SCANCODE_KP_5] = "Numpad5";
// 	m_vKeys[SDL_SCANCODE_KP_6] = "Numpad6";
// 	m_vKeys[SDL_SCANCODE_KP_7] = "Numpad7";
// 	m_vKeys[SDL_SCANCODE_KP_8] = "Numpad8";
// 	m_vKeys[SDL_SCANCODE_KP_9] = "Numpad9";
// 	m_vKeys[SDL_SCANCODE_F1] = "F1";
// 	m_vKeys[SDL_SCANCODE_F2] = "F2";
// 	m_vKeys[SDL_SCANCODE_F3] = "F3";
// 	m_vKeys[SDL_SCANCODE_F4] = "F4";
// 	m_vKeys[SDL_SCANCODE_F5] = "F5";
// 	m_vKeys[SDL_SCANCODE_F6] = "F6";
// 	m_vKeys[SDL_SCANCODE_F7] = "F7";
// 	m_vKeys[SDL_SCANCODE_F8] = "F8";
// 	m_vKeys[SDL_SCANCODE_F9] = "F9";
// 	m_vKeys[SDL_SCANCODE_F10] = "F10";
// 	m_vKeys[SDL_SCANCODE_F11] = "F11";
// 	m_vKeys[SDL_SCANCODE_F12] = "F12";
// 	m_vKeys[SDL_SCANCODE_F13] = "F13";
// 	m_vKeys[SDL_SCANCODE_F14] = "F14";
// 	m_vKeys[SDL_SCANCODE_F15] = "F15";
// 	m_vKeys[SDL_SCANCODE_PAUSE] = "Pause";

	m_bInitialized = true;
}

void InputManager::Shutdown()
{
	m_vKeys.clear();
	m_bInitialized = false;
}

std::string InputManager::ConvertToString(SDL_Scancode _key)
{
	return SDL_GetScancodeName(_key);

	//return "Unknown Key";
}