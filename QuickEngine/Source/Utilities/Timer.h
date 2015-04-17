#ifndef _TIMER_H_
#define _TIMER_H_

class CTimer
{
private:

	Quint32	m_startTime;
	Quint32	m_pausedTime;

	bool m_started;
	bool m_paused;

public:
	CTimer(void);
	~CTimer(void);

	void start();
	void stop();
	void pause();
	void unpause();

	Quint32 getMilliseconds();
	float getSeconds();

	bool isStarted();
	bool isPaused();
};

#endif