#ifndef __TRANSFORMCOMPONENT_H__
#define __TRANSFORMCOMPONENT_H__

#include <Common.h>
#include "BaseComponent.h"

namespace EComponentEvent
{
	enum eTransformEvent
	{
		EVENT_TRANSFORM_TRANSLATED = 1,
		EVENT_TRANSFORM_ROTATED,
		EVENT_TRANSFORM_SCALED
	};
}

class TransformComponent : public BaseComponent
{
public:
	TransformComponent() : BaseComponent(CT_TRANSFORM), m_v3Translation(QVector3::Zero()), m_qRotation(QQuaternion::Zero()), m_v3Scale(QVector3::Identity()) {}
	TransformComponent(QVector3 _pTranslation) : BaseComponent(CT_TRANSFORM), m_v3Translation(_pTranslation) {}
	TransformComponent(QVector3 _pTranslation, QQuaternion _pRotation) : BaseComponent(CT_TRANSFORM), m_v3Translation(_pTranslation), m_qRotation(_pRotation) {}
	TransformComponent(QVector3 _pTranslation, QQuaternion _pRotation, QVector3 _pScale) : BaseComponent(CT_TRANSFORM), m_v3Translation(_pTranslation), m_qRotation(_pRotation), m_v3Scale(_pScale) {}

	QVector3 m_v3Translation;
	QQuaternion m_qRotation;
	QVector3 m_v3Scale;

};

#endif