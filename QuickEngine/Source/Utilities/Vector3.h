#ifndef __VEC3_H__
#define __VEC3_H__

struct QVector3
{
public:

	static const float fEpsilon;

	float z;
	float y;
	float x;

	static QVector3 back();

	static QVector3 down();

	static QVector3 forward();

	static QVector3 left();

	void identity();

	static QVector3 Identity();

	static QVector3 right();

	static QVector3 up();

	void zero();

	static QVector3 Zero();

	float magnitude();

	QVector3 normalized();

	float sqrMagnitude();

	float &operator[](int index);

	QVector3();

	QVector3(float x);

	QVector3(float x, float y);

	QVector3(float x, float y, float z);

	static float Angle(QVector3 from, QVector3 to);

	static QVector3 ClampMagnitude(QVector3 vector, float maxLength);

	static QVector3 Cross(QVector3 lhs, QVector3 rhs);

	static float Distance(QVector3 a, QVector3 b);

	static float Dot(QVector3 lhs, QVector3 rhs);

	static QVector3 Lerp(QVector3 from, QVector3 to, float t);

	static float Magnitude(QVector3 a);

	static QVector3 Max(QVector3 lhs, QVector3 rhs);

	static QVector3 Min(QVector3 lhs, QVector3 rhs);

	static QVector3 MoveTowards(QVector3 current, QVector3 target, float maxDistanceDelta);

	static QVector3 Normalize(const QVector3& a);

	static void Normalize(QVector3* a);

	// 	static void OrthoNormalize(ref QVector3 normal, ref QVector3 tangent)
	// 	{
	// 		QVector3::Internal_OrthoNormalize2(ref normal, ref tangent);
	// 	}
	// 
	// 	static void OrthoNormalize(ref QVector3 normal, ref QVector3 tangent, ref QVector3 binormal)
	// 	{
	// 		QVector3::Internal_OrthoNormalize3(ref normal, ref tangent, ref binormal);
	// 	}

	static QVector3 Project(QVector3 vector, QVector3 onNormal);

	static QVector3 ProjectOnPlane(QVector3 vector, QVector3 planeNormal);

	static QVector3 Reflect(QVector3 inDirection, QVector3 inNormal);

	// 	static QVector3 RotateTowards(QVector3 current, QVector3 target, float maxRadiansDelta, float maxMagnitudeDelta)
	// 	{
	// 		return QVector3::INTERNAL_CALL_RotateTowards(ref current, ref target, maxRadiansDelta, maxMagnitudeDelta);
	// 	}

	static QVector3 Scale(QVector3 a, QVector3 b);

	// 	static QVector3 Slerp(QVector3 from, QVector3 to, float t)
	// 	{
	// 		return QVector3::INTERNAL_CALL_Slerp(ref from, ref to, t);
	// 	}

	static float SqrMagnitude (QVector3 a);

	void Normalize ();

	void Scale(QVector3 scale);

	void Set(float new_x, float new_y, float new_z);

	QVector3 operator+(const QVector3& rhs);
	QVector3 operator/(float d);
	bool operator==(const QVector3& rhs);
	bool operator!=(const QVector3& rhs);
	QVector3 operator*(float d);
	QVector3 operator*(const QVector3& rhs);
	QVector3 operator-(const QVector3& rhs);
};

#endif//__VEC3_H__
