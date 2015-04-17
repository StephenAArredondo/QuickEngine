#include <Common.h>
#include "EventManager.h"
#include <assert.h>

EventManager::EventManager() { }

EventManager::~EventManager()
{
	RemoveAllListeners();
}

void EventManager::AddListener(IEventListener* _pListener, EventType _Type)
{
	EventListenerMap::iterator pIter = m_Listeners.find(_Type);

	if( pIter == m_Listeners.end() ) 
		pIter = m_Listeners.insert( EventListenerMapPair(_Type, EventListenerList())).first;

	EventListenerList& _pList = pIter->second;

#ifdef _DEBUG
	// Check for duplicates.
	for(EventListenerList::const_iterator pIter = _pList.begin(); pIter != _pList.end(); ++pIter)
	{
		if((*pIter) == _pListener)
			assert("Duplicate event listener registered!");
	}
#endif

	// Add the listener to the map.
	_pList.push_back(_pListener);
}

void EventManager::RemoveListener(IEventListener *_pListener, EventType _Type)
{
	EventListenerMap::iterator pIter = m_Listeners.find(_Type);

	if( pIter != m_Listeners.end() )
	{
		EventListenerList& pList = pIter->second;
		
		for(EventListenerList::iterator pIter2 = pList.begin(); pIter2 != pList.end(); ++pIter2)
		{
			if((*pIter2) == _pListener)
			{
				pList.erase(pIter2);
				break;
			}
		}
	}
}

void EventManager::AddGlobalListener(IEventListener* _pListener)
{
#ifdef _DEBUG
	for(EventListenerList::iterator pIter = m_Globals.begin(); pIter != m_Globals.end(); ++pIter)
	{
		if((*pIter) == _pListener)
			assert("Duplicate global listener registered!");
	}
#endif

	m_Globals.push_back(_pListener);
}

void EventManager::RemoveGlobalListener(IEventListener* _pListener)
{
	EventListenerList& pList = m_Globals;

	for( EventListenerList::iterator pIter = pList.begin(); pIter != pList.end(); ++pIter )
	{
		if( (*pIter) == _pListener )	
		{
			m_Globals.erase(pIter);
			return;
		}
	}
}

void EventManager::RemoveAllListeners()
{
	for(EventListenerMap::iterator pIter = m_Listeners.begin(); pIter != m_Listeners.end(); ++pIter)
		pIter->second.clear();

	m_Listeners.clear();
	m_Globals.clear();
}

bool EventManager::FireEvent(IEventData const& _pEvent) const
{
	// Notify all global listeners.
	for(EventListenerList::const_iterator pIter = m_Globals.begin(); pIter != m_Globals.end(); ++pIter)
	{
		if((*pIter)->HandleEvent(_pEvent))
			return true;
	}

	EventListenerMap::const_iterator pIter = m_Listeners.find(_pEvent.GetType());
	if(pIter != m_Listeners.end())
	{
		const EventListenerList& pList = pIter->second;
		for(EventListenerList::const_iterator pIter2 = pList.begin(); pIter2 != pList.end(); ++pIter2)
		{
			if((*pIter2)->HandleEvent(_pEvent)) 
				return true;
		}
	}

	return false;
}