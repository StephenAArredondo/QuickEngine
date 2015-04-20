#ifndef _TIMER_H_
#define _TIMER_H_

struct QTimer
{
	uint32_t	m_startTime;
	uint32_t	m_pausedTime;
	bool m_started;
	bool m_paused;

	QTimer(void);
	~QTimer(void);

	void start();
	void stop();
	void pause();
	void unpause();

	uint32_t getMilliseconds();
	float getSeconds();

	bool isStarted();
	bool isPaused();
};

#endif