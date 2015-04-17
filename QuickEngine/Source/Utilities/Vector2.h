#ifndef __VEC2_H__
#define __VEC2_H__

struct QVector2
{
	static const float fEpsilon;
	
	float x;
	float y;

	QVector2();

	QVector2(float x);

	QVector2(float x, float y);

	void one();

	static QVector2 One();

	void right();

	static QVector2 Right();

	void up();

	static QVector2 Up();

	void zero();

	static QVector2 Zero();

	float magnitude();

	static float Magnitude(const QVector2& vec);

	void normalize();

	static QVector2 Normalize(const QVector2& vec);

	float sqrMagnitude();

	static float SqrMagnitude(const QVector2& a);

	float angle(const QVector2& to);

	static float Angle(const QVector2& from, const QVector2& to);

	static QVector2 ClampMagnitude(const QVector2& vec, float maxLength);

	static float Distance(QVector2 a, QVector2 b);

	static float Dot(const QVector2& lhs, const QVector2& rhs);

	static QVector2 Lerp(QVector2 from, QVector2 to, float t);

	static QVector2 Max(QVector2 lhs, QVector2 rhs);

	static QVector2 Min(QVector2 lhs, QVector2 rhs);

	static QVector2 MoveTowards(QVector2 current, QVector2 target, float maxDistanceDelta);

	static QVector2 Scale(QVector2 a, QVector2 b);

	void Scale(QVector2 scale);

	void Set(float new_x, float new_y);

	float operator[](int index);

	QVector2 operator+(const QVector2& rhs);
	QVector2 operator/(float d);
	bool operator==(const QVector2& rhs);
	bool operator!=(const QVector2& rhs);
	friend QVector2 operator*(float d, const QVector2& rhs);
	QVector2 operator*(float d);
	QVector2 operator-(const QVector2& rhs);
};

#endif//__VEC2_H__