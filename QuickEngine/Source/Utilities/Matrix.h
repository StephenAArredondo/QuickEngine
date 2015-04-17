#ifndef __MAT4_H__
#define __MAT4_H__

struct QMatrix
{
	float m[4][4];

	// float m00, float m01, float m02, float m03,
	// float m10, float m11, float m12, float m13,
	// float m20, float m21, float m22, float m23,
	// float m30, float m31, float m32, float m33

	void identity();

	static QMatrix Identity();
	
	void zero();

	static QMatrix Zero();

	bool inverse();

	static QMatrix Inverse(const QMatrix& mat);

	void transpose();

	static QMatrix Transpose(const QMatrix& mat);

	bool orthogonal(float left, float right, float bottom, float top, float nearPlane, float farPlane);

	static QMatrix Orthogonal(const QMatrix& mat, float left, float right, float bottom, float top, float nearPlane, float farPlane);

	bool frustum(float left, float right, float bottom, float top, float nearPlane, const float farPlane);

	static QMatrix Frustum(const QMatrix& mat, float left, float right, float bottom, float top, float nearPlane, const float farPlane);

	bool perspective(float fov, float aspect, float nearPlane, float farPlane);

	static QMatrix Perspective(const QMatrix& mat, float fov, float aspect, float nearPlane, float farPlane);

	static QMatrix Scale(QVector3 v);

	// 
	// 		static QMatrix TRS(QVector3 pos, QQuaternion q, QVector3 s)
	// 		{
	// 			return QMatrix::INTERNAL_CALL_TRS(ref pos, ref q, ref s);
	// 		}

	bool isRowZero(int row);

	static bool IsRowZero(const QMatrix& mat, int row);

	bool isColumnZero(int col);

	static bool IsColumnZero(const QMatrix& mat, int col);

	QVector3 multiplyPoint(QVector3 v);

	QVector3 multiplyPoint3x4(QVector3 v);

	QVector3 multiplyVector(QVector3 v);

	QVector4 getColumn(int i);

	QVector4 getRow(int i);

	void setColumn(int i, QVector4 v);

	void setRow(int i, QVector4 v);

	void swapRows(int rowA, int rowB);

	void addRows(int rowA, int rowB, float factor);

	void divideRow(int row, float scalar);

	void rotationAxis(const QVector3& vec, float angle);

	static QMatrix RotationAxis(const QMatrix& mat, const QVector3& vec, float angle);

	void rotateX(float angle);

	void rotateY(float angle);

	void rotateZ(float angle);

	float operator[](int index);

	bool operator==(const QMatrix& rhs) const;

	bool operator!=(const QMatrix& rhs) const;

	QVector4 operator*(const QVector4& v);

	QMatrix operator*(const QMatrix& rhs);
};

#endif//__MAT4_H__

/*
Matrix
[0], [4], [8],  [12],	[0,0], [1,0], [2,0], [3,0],
[1], [5], [9],  [13],	[0,1], [1,1], [2,1], [3,1],
[2], [6], [10], [14],	[0,2], [1,2], [2,2], [3,2],
[3], [7], [11], [15]	[0,3], [1,3], [2,3], [3,3]
^    ^    ^     ^
|    |    |     |
X    Y    Z     T

Rotate X
1,    0,     0,
0, cosO, -sinO,
0, sinO,  cosO

Rotate Y
cosO, 0, sinO,
0, 1,    0,
-sinO, 0, cosO

Rotate Z
cosO, -sinO, 0,
sinO,  cosO, 0,
0,     0, 1

Translate(X, Y, Z) [W]
1, 0, 0, x,
0, 1, 0, y,
0, 0, 1, z,
0, 0, 0, w

Scale(X, Y, Z) [W]
x, 0, 0, 0,
0, y, 0, 0,
0, 0, z, 0,
0, 0, 0, w

*/
//////////////////////////////////////////////////////////////////////////