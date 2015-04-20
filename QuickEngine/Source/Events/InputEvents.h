#ifndef __INPUT_EVENTS_H__
#define __INPUT_EVENTS_H__

struct InputEvent : QEvent < InputEvent >
{
	InputEvent(QKey input) : m_Input(input) { }

	QKey m_Input;
};

struct KeyboardEvent : QEvent<KeyboardEvent>
{
	KeyboardEvent(QEntity* entity, const uint8_t* keyboardInput) : m_Entity(entity), m_KeyboardInputs(keyboardInput) { }

	QEntity* m_Entity;
	const uint8_t* m_KeyboardInputs;
};

struct EntityInputEvent : QEvent< EntityInputEvent >
{
	EntityInputEvent(QEntity* entity, QKey input) : m_Entity(entity), m_Input(input) { }

	QEntity* m_Entity;
	QKey m_Input;
};

#endif//__INPUT_EVENTS_H__