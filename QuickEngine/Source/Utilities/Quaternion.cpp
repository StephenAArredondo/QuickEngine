#include "MathUtil.h"

QQuaternion::QQuaternion()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->w = 0.0f;
}

QQuaternion::QQuaternion(float x, float y)
{
	this->x = x;
	this->y = y;
	this->z = 0.0f;
	this->w = 0.0f;
}

QQuaternion::QQuaternion(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = 0.0f;
}

QQuaternion::QQuaternion(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

void QQuaternion::identity()
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
	w = 1.0f;
}

QQuaternion QQuaternion::Identity()
{
	QQuaternion quat;
	quat.identity();
	return quat;
}

void QQuaternion::zero()
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
	w = 1.0f;
}

QQuaternion QQuaternion::Zero()
{
	return QQuaternion(0.0f, 0.0f, 0.0f, 0.0f);
}

// 	QVector3 eulerAngles
// 	{
// 		get
// 		{
// 			return QQuaternion.Internal_ToEulerRad(this) * 57.29578f;
// 		}
// 		set
// 		{
// 			this = QQuaternion.Internal_FromEulerRad(value * 0.0174532924f);
// 		}
// 	}

float QQuaternion::&operator[](int index)
{
	if(index < 0 || index > 4)
	{
		// TODO: ASSERT Method
	}

	switch(index)
	{
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	case 3:
		return w;
	}
}

float QQuaternion::angle(const QQuaternion& quat)
{
	float f = dot(quat);
	return QMath::Acos(QMath::Min(QMath::Abs(f), 1.0f)) * 2.0f * 57.29578f;
}

float QQuaternion::Angle(const QQuaternion& a, const QQuaternion& b)
{
	float f = QQuaternion::Dot(a, b);
	return QMath::Acos(QMath::Min(QMath::Abs(f), 1.0f)) * 2.0f * 57.29578f;
}

// 	QQuaternion AngleAxis(float angle, QVector3 axis)
// 	{
// 		return QQuaternion.INTERNAL_CALL_AngleAxis(angle, ref axis);
// 	}

float QQuaternion::dot(QQuaternion quat)
{
	return x * quat.x + y * quat.y + z * quat.z + w * quat.w;
}

float QQuaternion::Dot(QQuaternion a, QQuaternion b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

// 	QQuaternion Euler(float x, float y, float z)
// 	{
// 		return QQuaternion.Internal_FromEulerRad(new QVector3(x, y, z) * 0.0174532924f);
// 	}
//
// 	QQuaternion Euler(QVector3 euler)
// 	{
// 		return QQuaternion.Internal_FromEulerRad(euler * 0.0174532924f);
// 	}
//
// 	QQuaternion FromToRotation(QVector3 fromDirection, QVector3 toDirection)
// 	{
// 		return QQuaternion.INTERNAL_CALL_FromToRotation(ref fromDirection, ref toDirection);
// 	}
// 
// 	QQuaternion Inverse(QQuaternion rotation)
// 	{
// 		return QQuaternion.INTERNAL_CALL_Inverse(ref rotation);
// 	}
// 
// 	QQuaternion Lerp(QQuaternion from, QQuaternion to, float t)
// 	{
// 		return QQuaternion.INTERNAL_CALL_Lerp(ref from, ref to, t);
// 	}
// 
// 	QQuaternion LookRotation(QVector3 forward, [DefaultValue("QVector3.up")] QVector3 upwards)
// 	{
// 		return QQuaternion.INTERNAL_CALL_LookRotation(ref forward, ref upwards);
// 	}

// 	QQuaternion RotateTowards(QQuaternion from, QQuaternion to, float maxDegreesDelta)
// 	{
// 		float num = QQuaternion::Angle(from, to);
// 		if(num == 0.0f)
// 		{
// 			return to;
// 		}
// 		float t = QMath::Min(1.0f, maxDegreesDelta / num);
// 		return QQuaternion::UnclampedSlerp(from, to, t);
// 	}

// 	QQuaternion Slerp(QQuaternion from, QQuaternion to, float t)
// 	{
// 		return QQuaternion.INTERNAL_CALL_Slerp(ref from, ref to, t);
// 	}

void QQuaternion::Set(float new_x, float new_y, float new_z, float new_w)
{
	x = new_x;
	y = new_y;
	z = new_z;
	w = new_w;
}

// 	void SetFromToRotation(QVector3 fromDirection, QVector3 toDirection)
// 	{
// 		this = QQuaternion.FromToRotation(fromDirection, toDirection);
// 	}
// 
// 	void SetLookRotation(QVector3 view, QVector3 up)
// 	{
// 		this = QQuaternion.LookRotation(view, up);
// 	}
// 
// 	void SetLookRotation(QVector3 view)
// 	{
// 		QVector3 up = QVector3.up;
// 		this.SetLookRotation(view, up);
// 	}
// 
// 	void ToAngleAxis(float angle, QVector3 axis)
// 	{
// 		QQuaternion.Internal_ToAxisAngleRad(this, out axis, out angle);
// 		angle *= 57.29578f;
// 	}

bool QQuaternion::operator==(const QQuaternion& rhs)
{
	return QQuaternion::Dot(this, rhs) > 0.999999f;
}

bool QQuaternion::operator!=(const QQuaternion& rhs)
{
	return QQuaternion::Dot(this, rhs) <= 0.999999f;
}

QQuaternion QQuaternion::operator*(const QQuaternion& rhs)
{
	return QQuaternion(this->w * rhs.x + this->x * rhs.w + this->y * rhs.z - this->z * rhs.y, this->w * rhs.y + this->y * rhs.w + this->z * rhs.x - this->x * rhs.z, this->w * rhs.z + this->z * rhs.w + this->x * rhs.y - this->y * rhs.x, this->w * rhs.w - this->x * rhs.x - this->y * rhs.y - this->z * rhs.z);
}

QVector3 QQuaternion::operator*(const QVector3& point)
{
	float num = rotation.x * 2.0f;
	float num2 = rotation.y * 2.0f;
	float num3 = rotation.z * 2.0f;
	float num4 = rotation.x * num;
	float num5 = rotation.y * num2;
	float num6 = rotation.z * num3;
	float num7 = rotation.x * num2;
	float num8 = rotation.x * num3;
	float num9 = rotation.y * num3;
	float num10 = rotation.w * num;
	float num11 = rotation.w * num2;
	float num12 = rotation.w * num3;
	QVector3 result;
	result.x =(1.0f -(num5 + num6)) * point.x +(num7 - num12) * point.y +(num8 + num11) * point.z;
	result.y =(num7 + num12) * point.x +(1.0f -(num4 + num6)) * point.y +(num9 - num10) * point.z;
	result.z =(num8 - num11) * point.x +(num9 + num10) * point.y +(1.0f -(num4 + num5)) * point.z;
	return result;
}

const float QQuaternion::fEpsilon = 1E-06f;