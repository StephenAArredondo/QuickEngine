#ifndef _FPS_H_
#define _FPS_H_

#include <Common.h>

class FPS
{
private:

	unsigned int previousTime;
	unsigned int currentTime;

	unsigned int m_uiFrame;
	unsigned int m_uiFPS;
	
public:

	FPS() : m_uiFrame(0), m_uiFPS(0), previousTime(0), currentTime(0) {}

	inline const unsigned int getFPS() { return m_uiFPS; }
	/*inline const float getTime()	{ return m_Clock.getElapsedTime().asSeconds(); }*/
	//inline const std::string getFPSString() { return std::to_string(m_uiFPS); }

	void Update();
};

#endif
