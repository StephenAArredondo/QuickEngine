#ifndef __TRANSFORM_COMPONENT_H__
#define __TRANSFORM_COMPONENT_H__

struct TransformComponent : public QComponent<TransformComponent>
{
	TransformComponent(QVector3 position, QQuaternion rotation, QVector3 scale) : m_Position(position), m_Rotation(rotation), m_Scale(scale) {}

	QVector3 m_Position;
	QQuaternion m_Rotation;
	QVector3 m_Scale;
};

#endif//__TRANSFORM_COMPONENT_H__