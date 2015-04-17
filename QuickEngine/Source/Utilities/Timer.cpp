#include <Common.h>
#include "Timer.h"

CTimer::CTimer()
{
	m_startTime = 0;
	m_pausedTime = 0;
	m_started = false;
	m_paused = false;
}

CTimer::~CTimer(){}

void CTimer::start()
{
	m_started = true;
	m_paused = false;

	m_startTime = SDL_GetTicks();
	m_pausedTime = 0;
}

void CTimer::stop()
{
	m_started = false;
	m_paused = true;

	m_startTime = 0;
	m_pausedTime = 0;
}

void CTimer::pause()
{
	if(m_started && !m_paused)
	{
		m_paused = true;

		m_pausedTime = SDL_GetTicks() - m_startTime;
		m_startTime = 0;
	}
}

void CTimer::unpause()
{
	if(m_started && m_paused)
	{
		m_paused = false;

		m_startTime = SDL_GetTicks() - m_pausedTime;
		m_pausedTime = 0;
	}
}

Uint32 CTimer::getMilliseconds()
{
	Uint32 time = 0;

	if(m_started)
	{
		if(m_paused)
		{
			time = m_pausedTime;
		}
		else
		{
			time = SDL_GetTicks() - m_startTime;
		}
	}

	return time;
}

float CTimer::getSeconds()
{
	return getMilliseconds() * 0.001f;
}

bool CTimer::isStarted()
{ 
	return m_started; 
}

bool CTimer::isPaused()
{ 
	return m_paused; 
}