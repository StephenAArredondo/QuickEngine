#include "MathUtil.h"
#include "Math.h"

QVector3 QVector3::back()
{
	return QVector3(0.0f, 0.0f, -1.0f);
}

QVector3 QVector3::down()
{
	return QVector3(0.0f, -1.0, 0.0f);
}

QVector3 QVector3::forward()
{
	return QVector3(0.0f, 0.0f, 1.0f);
}

QVector3 QVector3::left()
{
	return QVector3(-1.0f, 0.0f, 0.0f);
}

void QVector3::identity()
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
}

QVector3 QVector3::Identity()
{
	return QVector3(1.0f, 1.0f, 1.0f);
}

QVector3 QVector3::right()
{
	return QVector3(1.0f, 0.0f, 0.0f);
}

QVector3 QVector3::up()
{
	return QVector3(0.0f, 1.0f, 0.0f);
}

void QVector3::zero()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

QVector3 QVector3::Zero()
{
	return QVector3(0.0f, 0.0f, 0.0f);
}

float QVector3::magnitude()
{
	return QMath::Sqrt(((this->x * this->x) + (this->y * this->y) + (this->z * this->z)));
}

QVector3 QVector3::normalized()
{
	return QVector3::Normalize((*this));
}

float QVector3::sqrMagnitude()
{
	return ((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

float QVector3::operator[](int index)
{
	switch (index)
	{
		case 0:	return x;
		case 1:	return y;
		case 2:	return z;
		default: return 0.0f;
	}
}

QVector3::QVector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

QVector3::QVector3(float x)
{
	this->x = x;
	this->y = 0.0f;
	this->z = 0.0f;
}

QVector3::QVector3(float x, float y)
{
	this->x = x;
	this->y = y;
	this->z = 0.0f;
}

QVector3::QVector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float QVector3::Angle(QVector3 from, QVector3 to)
{
	return QMath::Acos(QMath::Clamp(QVector3::Dot(from.normalized(), to.normalized()), -1.0f, 1.0f)) * 57.29578f;
}

QVector3 QVector3::ClampMagnitude(QVector3 vector, float maxLength)
{
	return (vector.sqrMagnitude() > maxLength * maxLength) ? (vector.normalized() * maxLength) : vector;
}

QVector3 QVector3::Cross(QVector3 lhs, QVector3 rhs)
{
	return QVector3((lhs.y * rhs.z) - (lhs.z * rhs.y), (lhs.z * rhs.x) - (lhs.x * rhs.z), (lhs.x * rhs.y) - (lhs.y * rhs.x));
}

float QVector3::Distance(QVector3 a, QVector3 b)
{
	QVector3 vector = QVector3((a.x - b.x), (a.y - b.y), (a.z - b.z));
	return QMath::Sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));
}

float QVector3::Dot(QVector3 lhs, QVector3 rhs)
{
	return ((lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z));
}

QVector3 QVector3::Lerp(QVector3 from, QVector3 to, float t)
{
	t = QMath::Clamp01(t);
	return QVector3(from.x + (to.x - from.x) * t, from.y + (to.y - from.y) * t, from.z + (to.z - from.z) * t);
}

float QVector3::Magnitude(QVector3 a)
{
	return QMath::Sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
}

QVector3 QVector3::Max(QVector3 lhs, QVector3 rhs)
{
	return QVector3(QMath::Max(lhs.x, rhs.x), QMath::Max(lhs.y, rhs.y), QMath::Max(lhs.z, rhs.z));
}

QVector3 QVector3::Min(QVector3 lhs, QVector3 rhs)
{
	return QVector3(QMath::Min(lhs.x, rhs.x), QMath::Min(lhs.y, rhs.y), QMath::Min(lhs.z, rhs.z));
}

QVector3 QVector3::MoveTowards(QVector3 current, QVector3 target, float maxDistanceDelta)
{
	QVector3 a = target - current;
	float magnitude = a.magnitude();
	return (magnitude <= maxDistanceDelta || magnitude == 0.0f) ? target : (current + a / magnitude * maxDistanceDelta);
}

QVector3 QVector3::Normalize(const QVector3& a)
{
	float num = QVector3::Magnitude(a);
	return (num > 1E-05f) ? (a / num) : QVector3::Zero();
}

void QVector3::Normalize(QVector3* a)
{
	float num = QVector3::Magnitude((*a));
	(*a) = (num > 1E-05f) ? ((*a) / num) : QVector3::Zero();
}

// 	void OrthoNormalize(ref QVector3 normal, ref QVector3 tangent)
// 	{
// 		QVector3::Internal_OrthoNormalize2(ref normal, ref tangent);
// 	}
// 
// 	void OrthoNormalize(ref QVector3 normal, ref QVector3 tangent, ref QVector3 binormal)
// 	{
// 		QVector3::Internal_OrthoNormalize3(ref normal, ref tangent, ref binormal);
// 	}

QVector3 QVector3::Project(QVector3 vector, QVector3 onNormal)
{
	float num = QVector3::Dot(onNormal, onNormal);
	return (num < EPSILON) ? QVector3::Zero() : (onNormal * QVector3::Dot(vector, onNormal) / num);
}

QVector3 QVector3::ProjectOnPlane(QVector3 vector, QVector3 planeNormal)
{
	return (vector - QVector3::Project(vector, planeNormal));
}

QVector3 QVector3::Reflect(QVector3 inDirection, QVector3 inNormal)
{
	return (-2.0f * QVector3::Dot(inNormal, inDirection) * inNormal + inDirection);
}

// 	QVector3 RotateTowards(QVector3 current, QVector3 target, float maxRadiansDelta, float maxMagnitudeDelta)
// 	{
// 		return QVector3::INTERNAL_CALL_RotateTowards(ref current, ref target, maxRadiansDelta, maxMagnitudeDelta);
// 	}

QVector3 QVector3::Scale(QVector3 a, QVector3 b)
{
	return QVector3(a.x * b.x, a.y * b.y, a.z * b.z);
}

// 	QVector3 Slerp(QVector3 from, QVector3 to, float t)
// 	{
// 		return QVector3::INTERNAL_CALL_Slerp(ref from, ref to, t);
// 	}

float QVector3::SqrMagnitude (QVector3 a)
{
	return ((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
}

void QVector3::Normalize ()
{
	float num = QVector3::Magnitude((*this));
	(*this) = (num > 1E-05f) ? ((*this) / num) : QVector3::Zero();
}

void QVector3::Scale(QVector3 scale)
{
	this->x *= scale.x;
	this->y *= scale.y;
	this->z *= scale.z;
}

void QVector3::Set(float new_x, float new_y, float new_z)
{
	this->x = new_x;
	this->y = new_y;
	this->z = new_z;
}

QVector3 QVector3::operator+(const QVector3& rhs)
{
	return QVector3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

QVector3 QVector3::operator/(float d)
{
	return QVector3(this->x / d, this->y / d, this->z / d);
}

QVector3 operator/(const QVector3& lhs, float d)
{
	return QVector3(lhs.x / d, lhs.y / d, lhs.z / d);
}

bool QVector3::operator==(const QVector3& rhs)
{
	return QVector3::SqrMagnitude((*this) - rhs) < 9.99999944E-11f;
}

bool QVector3::operator!=(const QVector3& rhs)
{
	return QVector3::SqrMagnitude((*this) - rhs) >= 9.99999944E-11f;
}

QVector3 QVector3::operator*(float d)
{
	return QVector3 (this->x * d, this->y * d, this->z * d);
}

QVector3 QVector3::operator-(const QVector3& rhs)
{
	return QVector3 (this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

QVector3 operator*(float d, const QVector3& rhs)
{
	return QVector3(d * rhs.x, d * rhs.y, d * rhs.z);
}