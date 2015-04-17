#ifndef __EVENT_H__
#define	__EVENT_H__

typedef unsigned int EventType;

class IEventData
{
private:

	EventType m_Type;

public:

	IEventData(EventType _Type) : m_Type(_Type) {}
	EventType GetType() const { return m_Type; }
};

class IEventListener
{
public:
	virtual ~IEventListener() {}
	virtual bool HandleEvent(IEventData const& _pEvent) = 0;
};

#endif