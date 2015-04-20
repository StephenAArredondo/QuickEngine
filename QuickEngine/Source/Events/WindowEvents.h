#ifndef __WINDOW_EVENTS_H__
#define __WINDOW_EVENTS_H__

struct WindowCreationEvent : QEvent < WindowCreationEvent >
{
	WindowCreationEvent(QWindow* windowHandle) : m_WindowHandle(windowHandle) { }

	QWindow* m_WindowHandle;
};

#endif//__WINDOW_EVENTS_H__