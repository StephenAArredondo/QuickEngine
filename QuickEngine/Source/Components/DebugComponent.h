#ifndef __DEBUG_COMPONENT_H__
#define __DEBUG_COMPONENT_H__

struct DebugComponent : QComponent < DebugComponent >
{
	DebugComponent(QString debugString) : m_DebugString(debugString) { }

	QString m_DebugString;
};

#endif//__TRANSFORM_COMPONENT_H__