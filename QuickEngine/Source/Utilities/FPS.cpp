#include <Common.h>
#include "FPS.h"

void FPS::Update()
{
	currentTime = SDL_GetTicks();

	if(currentTime >= previousTime + 1000)
	{
		m_uiFPS = m_uiFrame;
		m_uiFrame = 0;
		previousTime = currentTime;
	}

	++ m_uiFrame;
}