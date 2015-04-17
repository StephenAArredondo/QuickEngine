#include "MathUtil.h"
#include "Math.h"

QVector4::QVector4()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->w = 0.0f;
}

QVector4::QVector4(float x, float y)
{
	this->x = x;
	this->y = y;
	this->z = 0.0f;
	this->w = 0.0f;
}

QVector4::QVector4(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = 0.0f;
}

QVector4::QVector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

QVector4 QVector4::identity() { return QVector4(1.0f, 1.0f, 1.0f, 1.0f); }

QVector4 QVector4::zero() { return QVector4(0.0f, 0.0f, 0.0f, 0.0f); }

float QVector4::magnitude()
{
	return QMath::Sqrt(QVector4::Dot((*this), (*this)));
}

QVector4 QVector4::normalize()
{
	return QVector4::Normalize((*this));
}

float QVector4::sqrtMagnitude()
{
	return QVector4::Dot((*this), (*this));
}

float QVector4::operator[](int index)
{
	switch (index)
	{
		case 0:	return x;
		case 1:	return y;
		case 2:	return z;
		case 3:	return w;
		default: return 0.0f;
	}
}

float QVector4::Distance(QVector4 a, QVector4 b)
{ 
	return QVector4::Magnitude(a - b);
}

float QVector4::Dot(QVector4 a, QVector4 b) 
{ 
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w)); 
}

QVector4 QVector4::Lerp(QVector4 from, QVector4 to, float t) 
{ 
	t = QMath::Clamp01(t);
	return QVector4(from.x + (to.x = from.x) * t, from.y + (to.y = from.y) * t, from.z + (to.z = from.z) * t, from.w + (to.w = from.w) * t);
}

float QVector4::Magnitude(QVector4 a)
{
	return QMath::Sqrt(QVector4::Dot(a, a));
}

QVector4 QVector4::Max(QVector4 lhs, QVector4 rhs)
{
	return QVector4(QMath::Max(lhs.x, rhs.x), QMath::Max(lhs.y, rhs.y), QMath::Max(lhs.z, rhs.z), QMath::Max(lhs.w, rhs.w));
}

QVector4 QVector4::Min(QVector4 lhs, QVector4 rhs)
{
	return QVector4(QMath::Min(lhs.x, rhs.x), QMath::Min(lhs.y, rhs.y), QMath::Min(lhs.z, rhs.z), QMath::Min(lhs.w, rhs.w));
}

QVector4 QVector4::MoveTowards(QVector4 current, QVector4 target, float maxDistanceDelta)
{
	QVector4 a = target - current;
	float magnitude = a.magnitude();
	return (magnitude <= maxDistanceDelta || magnitude == 0.0f) ? target : (current + a / magnitude * maxDistanceDelta);
}

QVector4 QVector4::Normalize(const QVector4& a)
{
	float num = QVector4::Magnitude(a);
	return (num > fEpsilon) ? ((a) / num) : QVector4::zero();
}

void QVector4::Normalize(QVector4* a)
{
	float num = QVector4::Magnitude((*a));
	(*a) = (num > fEpsilon) ? ((*a) / num) : QVector4::zero();
}

QVector4 QVector4::Project(QVector4 a, QVector4 b)
{
	return b * QVector4::Dot(a, b) / QVector4::Dot(b, b);
}

QVector4 QVector4::Scale(QVector4 a, QVector4 b)
{
	return QVector4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

float QVector4::SqrMagnitude(QVector4 a)
{
	return QVector4::Dot(a, a);
}

void QVector4::Scale(QVector4 scale)
{
	this->x *= scale.x;
	this->y *= scale.y;
	this->z *= scale.z;
	this->w *= scale.w;
}

void QVector4::Set(float new_x, float new_y, float new_z, float new_w)
{
	this->x = new_x;
	this->y = new_y;
	this->z = new_z;
	this->w = new_w;
}

float QVector4::SqrMagnitude()
{
	return QVector4::Dot((*this), (*this));
}

QVector4 QVector4::operator+(const QVector4& rhs)
{
	return QVector4(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w);
}

QVector4 QVector4::operator/(float d)
{
	return QVector4(this->x / d, this->y / d, this->z / d, this->w / d);
}

QVector4 operator/(const QVector4& lhs, float d)
{
	return QVector4(lhs.x / d, lhs.y / d, lhs.z / d, lhs.w / d);
}

bool QVector4::operator==(const QVector4& rhs)
{
	return QVector4::SqrMagnitude((*this) - rhs) < 9.99999944E-11f;
}

bool QVector4::operator!=(const QVector4& rhs)
{
	return QVector4::SqrMagnitude((*this) - rhs) >= 9.99999944E-11f;
}

QVector4 QVector4::operator*(float d)
{
	return QVector4(this->x * d, this->y * d, this->z * d, this->w * d);
}

QVector4 QVector4::operator-(const QVector4& rhs)
{
	return QVector4(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w - rhs.w);
}

const float QVector4::fEpsilon = 1.401298E-45f;