#ifndef __VEC4_H__
#define __VEC4_H__

struct QVector4
{
	static const float fEpsilon;

	float x;
	float y;
	float z;
	float w;

	QVector4();

	QVector4(float x, float y);

	QVector4(float x, float y, float z);

	QVector4(float x, float y, float z, float w);

	static QVector4 identity();

	static QVector4 zero();

	float magnitude();

	QVector4 normalize();

	float sqrtMagnitude();

	static float Distance(QVector4 a, QVector4 b);

	static float Dot(QVector4 a, QVector4 b);

	static QVector4 Lerp(QVector4 from, QVector4 to, float t);

	static float Magnitude(QVector4 a);

	static QVector4 Max(QVector4 lhs, QVector4 rhs);

	static QVector4 Min(QVector4 lhs, QVector4 rhs);

	static QVector4 MoveTowards(QVector4 current, QVector4 target, float maxDistanceDelta);

	static QVector4 Normalize(const QVector4& a);

	static void Normalize(QVector4* a);

	static QVector4 Project(QVector4 a, QVector4 b);

	static QVector4 Scale(QVector4 a, QVector4 b);

	static float SqrMagnitude(QVector4 a);

	void Normalize();

	void Scale(QVector4 scale);

	void Set(float new_x, float new_y, float new_z, float new_w);

	float SqrMagnitude();

	float &operator[](int index);
	QVector4 operator+(const QVector4& rhs);
	QVector4 operator/(float d);
	bool operator==(const QVector4& rhs);
	bool operator!=(const QVector4& rhs);
	QVector4 operator*(float d);
	QVector4 operator-(const QVector4& rhs);

};

#endif//__VEC4_H__