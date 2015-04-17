#include "MathUtil.h"
#include "Math.h"

QVector2::QVector2()
{
	this->x = 0.0f;
	this->y = 0.0f;
}

QVector2::QVector2(float x)
{
	this->x = x;
	this->y = 0.0f;
}

QVector2::QVector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

void QVector2::one()
{
	x = 1.0f;
	y = 1.0f;
}

QVector2 QVector2::One()
{
	return QVector2(1.0f, 1.0f);
}

void QVector2::right()
{
	x = 1.0f;
	y = 0.0f;
}

QVector2 QVector2::Right()
{
	return QVector2(1.0f, 0.0f);
}

void QVector2::up()
{
	x = 0.0f;
	y = 1.0f;
}

QVector2 QVector2::Up()
{			
	return QVector2(0.0f, 1.0f);	
}

void QVector2::zero()
{
	x = 0.0f;
	y = 0.0f;
}

QVector2 QVector2::Zero()
{
	return QVector2(0.0f, 0.0f);
}

float QVector2::magnitude()
{
	return QMath::Sqrt((x * x) + (y * y));
}

float QVector2::Magnitude(const QVector2& vec)
{
	return QMath::Sqrt((vec.x * vec.x) + (vec.y * vec.y));
}

void QVector2::normalize()
{
	float magnitude = this->magnitude();
	(*this) = (magnitude > 1E-05f) ? ((*this) / magnitude) : QVector2::Zero();
}

QVector2 QVector2::Normalize(const QVector2& vec)
{
	QVector2 temp = vec;
	temp.normalize();
	return temp;
}

float QVector2::sqrMagnitude()
{
	return ((x * x) + (y * y));
}

float QVector2::SqrMagnitude(const QVector2& a)
{
	QVector2 temp = a;
	return ((temp.x * temp.x) + (temp.y * temp.y));
}

float QVector2::operator[](int index)
{
	switch (index)
	{
		case 0:	return x;
		case 1:	return y;
		default: return 0.0f;
	}
}

float QVector2::angle(const QVector2& to)
{
	QVector2 temp = to;
	return QMath::Acos(QMath::Clamp(QVector2::Dot(Normalize((*this)), Normalize(to)), -1.0f, 1.0f)) * 57.29578f;
}

float QVector2::Angle(const QVector2& from, const QVector2& to)
{
	return QMath::Acos(QMath::Clamp(QVector2::Dot(Normalize(from), Normalize(to)), -1.0f, 1.0f)) * 57.29578f;
}

QVector2 QVector2::ClampMagnitude(const QVector2& vec, float maxLength)
{
	QVector2 temp = vec;
	return (temp.sqrMagnitude() > (maxLength * maxLength)) ? (Normalize(temp) * maxLength) : temp;
}

float QVector2::Distance(QVector2 a, QVector2 b)
{
	return (a - b).magnitude();
}

float QVector2::Dot(const QVector2& lhs, const QVector2& rhs)
{
	return ((lhs.x * rhs.x) + (lhs.y * rhs.y));
}

QVector2 QVector2::Lerp(QVector2 from, QVector2 to, float t)
{
	t = QMath::Clamp01(t);
	return QVector2(from.x +(to.x - from.x) * t, from.y +(to.y - from.y) * t);
}

QVector2 QVector2::Max(QVector2 lhs, QVector2 rhs)
{
	return QVector2(QMath::Max(lhs.x, rhs.x), QMath::Max(lhs.y, rhs.y));
}

QVector2 QVector2::Min(QVector2 lhs, QVector2 rhs)
{
	return QVector2(QMath::Min(lhs.x, rhs.x), QMath::Min(lhs.y, rhs.y));
}

QVector2 QVector2::MoveTowards(QVector2 current, QVector2 target, float maxDistanceDelta)
{
	QVector2 a = target - current;
	float magnitude = a.magnitude();
	return (magnitude <= maxDistanceDelta || magnitude == 0.0f) ? target : (current + a / magnitude * maxDistanceDelta);
}

QVector2 QVector2::Scale(QVector2 a, QVector2 b)
{
	return QVector2(a.x * b.x, a.y * b.y);
}	

void QVector2::Scale(QVector2 scale)
{
	this->x *= scale.x;
	this->y *= scale.y;
}

void QVector2::Set(float new_x, float new_y)
{
	this->x = new_x;
	this->y = new_y;
}

QVector2 QVector2::operator+(const QVector2& rhs)
{
	return QVector2(rhs.x + this->x, rhs.y + this->y);
}

QVector2 QVector2::operator/(float d)
{
	return QVector2(this->x / d, this->y / d);
}

bool QVector2::operator==(const QVector2& rhs)
{
	return QVector2::SqrMagnitude((*this) - rhs) < 9.99999944E-11f;
}

bool QVector2::operator!=(const QVector2& rhs)
{
	return QVector2::SqrMagnitude((*this) - rhs) >= 9.99999944E-11f;
}

QVector2 operator*(float d, const QVector2& rhs)
{
	return QVector2(rhs.x * d, rhs.y * d);
}

QVector2 QVector2::operator*(float d)
{
	return QVector2(this->x * d, this->y * d);
}

QVector2 QVector2::operator-(const QVector2& rhs)
{
	return QVector2(rhs.x - this->x, rhs.y - this->y);
}