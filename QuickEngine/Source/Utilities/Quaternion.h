#ifndef __QUAT_H__
#define __QUAT_H__

struct QQuaternion
{
	static const float fEpsilon;

	float x;
	float y;
	float z;
	float w;

	QQuaternion();

	QQuaternion(float x, float y);

	QQuaternion(float x, float y, float z);

	QQuaternion(float x, float y, float z, float w);

	void identity();

	static QQuaternion Identity();

	void zero();

	static QQuaternion Zero();

	float angle(const QQuaternion& quat);

	static float Angle(const QQuaternion& a, const QQuaternion& b);

	float dot(QQuaternion quat);

	static float Dot(QQuaternion a, QQuaternion b);

	void Set(float new_x, float new_y, float new_z, float new_w);

	float operator[](int index);
	bool operator==(const QQuaternion& rhs);
	bool operator!=(const QQuaternion& rhs);
	QQuaternion operator*(const QQuaternion& rhs);
	QVector3 operator*(const QVector3& point);
};

#endif//__QUATERNION_H__