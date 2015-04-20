#ifndef __TRANSFORM_EVENTS_H__
#define __TRANSFORM_EVENTS_H__

struct TranslationEvent : QEvent < TranslationEvent >
{
	TranslationEvent(QEntity* entity, QVector3 translation) : m_Entity(entity), m_Translation(translation) { }

	QEntity* m_Entity;
	QVector3 m_Translation;
};  

struct RotationEvent : QEvent < RotationEvent >
{
	RotationEvent(QEntity* entity, QVector3 rotation) : m_Entity(entity), m_Rotation(rotation) { }

	QEntity* m_Entity;
	QVector3 m_Rotation;
};

struct ScaleEvent : QEvent < ScaleEvent >
{
	ScaleEvent(QEntity* entity, QVector3 scale) : m_Entity(entity), m_Scale(scale) { }

	QEntity* m_Entity;
	QVector3 m_Scale;
};

#endif//__TRANSFORM_EVENTS_H__