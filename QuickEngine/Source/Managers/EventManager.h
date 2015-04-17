#ifndef __EVENTMANAGER_H__
#define __EVENTMANAGER_H__

#include "..\Utilities\Event.h"
#include <map>
#include <list>

class EventManager
{
protected:

	typedef std::list<IEventListener*> EventListenerList;
	typedef std::map<EventType, EventListenerList> EventListenerMap;
	typedef std::pair<EventType, EventListenerList> EventListenerMapPair;

	std::map<EventType, EventListenerList> m_Listeners;
	EventListenerList m_Globals;

public:

	EventManager();
	virtual ~EventManager();

	void AddListener(IEventListener* _pListener, EventType _Type);
	
	void RemoveListener(IEventListener* _pListener, EventType _Type);
	
	void AddGlobalListener(IEventListener* _pListener);
	
	void RemoveGlobalListener(IEventListener* _pListener);
	
	void RemoveAllListeners();
	
	bool FireEvent(IEventData const& _pEvent) const;
};

#endif