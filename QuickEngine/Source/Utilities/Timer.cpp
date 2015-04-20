#include <Common.h>
#include "Timer.h"

QTimer::QTimer()
{
	m_startTime = 0;
	m_pausedTime = 0;
	m_started = false;
	m_paused = false;
}

QTimer::~QTimer(){}

void QTimer::start()
{
	m_started = true;
	m_paused = false;

	m_startTime = SDL_GetTicks();
	m_pausedTime = 0;
}

void QTimer::stop()
{
	m_started = false;
	m_paused = true;

	m_startTime = 0;
	m_pausedTime = 0;
}

void QTimer::pause()
{
	if(m_started && !m_paused)
	{
		m_paused = true;

		m_pausedTime = SDL_GetTicks() - m_startTime;
		m_startTime = 0;
	}
}

void QTimer::unpause()
{
	if(m_started && m_paused)
	{
		m_paused = false;

		m_startTime = SDL_GetTicks() - m_pausedTime;
		m_pausedTime = 0;
	}
}

uint32_t QTimer::getMilliseconds()
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

float QTimer::getSeconds()
{
	return getMilliseconds() * 0.001f;
}

bool QTimer::isStarted()
{ 
	return m_started; 
}

bool QTimer::isPaused()
{ 
	return m_paused; 
}