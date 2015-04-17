#include "MathUtil.h"

float QMatrix::&operator[](int index)
{
	if(index < 0 || index > 15)
	{
		// TODO: ASSERT Method
	}

	switch(index)
	{
	case 0:
		return m[0][0];
	case 1:
		return m[1][0];
	case 2:
		return m[2][0];
	case 3:
		return m[3][0];
	case 4:
		return m[0][1];
	case 5:
		return m[1][1];
	case 6:
		return m[2][1];
	case 7:
		return m[3][1];
	case 8:
		return m[0][2];
	case 9:
		return m[1][2];
	case 10:
		return m[2][2];
	case 11:
		return m[3][2];
	case 12:
		return m[0][3];
	case 13:
		return m[1][3];
	case 14:
		return m[2][3];
	case 15:
		return m[3][3];
	}
}

void QMatrix::identity()
{
	m[0][0] = 1.0f;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;

	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 1.0f;
	m[2][3] = 0.0f;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

QMatrix QMatrix::Identity()
{
	QMatrix mat;
	mat.identity();			
	return mat;		
}

void QMatrix::zero()
{
	m[0][0] = 0.0f;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;
	m[1][0] = 0.0f;
	m[1][1] = 0.0f;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;
	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 0.0f;
	m[2][3] = 0.0f;
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 0.0f;
}

QMatrix QMatrix::Zero()
{
	QMatrix mat;
	mat.zero();
	return mat;
}

bool QMatrix::inverse()
{
	QMatrix mat;
	mat.identity();

	QMatrix copy;

	for(int col = 0; col < 4; ++col)
		for(int row = 0; row < 4; ++row)
			copy.m[col][row] = m[col][row];

	for(int col = 0; col < 4; ++col)
	{
		for(int row = col; row < 4; ++row)
		{
			if (copy.isRowZero(row))
				return false;

			if (copy.m[col][row] != 0.0)
			{
				copy.divideRow(row, copy.m[col][row]);
			}
		}

		if(copy.isColumnZero(col))
			return false;

		for(int row = col + 1; row < 4; ++row)
		{
			if (copy.m[col][row] == 1.0)
			{
				mat.swapRows(col, row);
				copy.swapRows(col, row);

				break;
			}
		}

		for (int row = col + 1; row < 4; ++row)
		{
			if (copy.m[col][row] != 0.0)
			{
				mat.addRows(row, col, -1.0);
				copy.addRows(row, col, -1.0);
			}
		}
	}

	for(int col = 3; col >= 0; --col)
	{
		for(int row = col - 1; row >= 0; --row)
		{
			if (copy.m[col][row] != 0.0)
			{
				mat.addRows(row, col, -copy.m[col][row]);
				copy.addRows(row, col, -copy.m[col][row]);
			}
		}
	}

	for(int col = 0; col < 4; ++col)
		for(int row = 0; row < 4; ++row)
			m[col][row] = mat.m[col][row];

	return true;
}

QMatrix QMatrix::Inverse(const QMatrix& mat)
{
	QMatrix temp = mat;
	temp.inverse();
	return temp;
}

void QMatrix::transpose()
{
	QMatrix mat;
	mat = (*this);

	for(int col = 0; col < 4; ++col)
		for(int row = 0; row < 4; ++row)
			m[row][col] = mat.m[col][row]; 
}

QMatrix QMatrix::Transpose(const QMatrix& mat)
{
	QMatrix temp = mat;
	temp.transpose();
	return temp;
}

bool QMatrix::orthogonal(float left, float right, float bottom, float top, float nearPlane, float farPlane)
{
	if((right - left) == 0.0f || (top - bottom) == 0.0f || (farPlane - nearPlane) == 0.0f)
		return false;

	m[0][0] = 2.0f / (right - left);
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;
	m[1][0] = 0.0f;
	m[1][1] = 2.0f / (top - bottom);
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;
	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = -2.0f / (farPlane - nearPlane);
	m[2][3] = 0.0f;
	m[3][0] = -(right + left) / (right - left);
	m[3][1] = -(top + bottom) / (top - bottom);
	m[3][2] = -(farPlane + nearPlane) / (farPlane - nearPlane);
	m[3][3] = 1.0f;

	return true;
}

QMatrix QMatrix::Orthogonal(const QMatrix& mat, float left, float right, float bottom, float top, float nearPlane, float farPlane)
{
	QMatrix temp = mat;
	temp.orthogonal(left, right, bottom, top, nearPlane, farPlane);
	return temp;
}

bool QMatrix::frustum(float left, float right, float bottom, float top, float nearPlane, const float farPlane)
{
	if ((right - left) == 0.0f || (top - bottom) == 0.0f || (farPlane - nearPlane) == 0.0f)
		return false;

	m[0][0] = 2.0f * nearPlane / (right - left);
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;
	m[1][0] = 0.0f;
	m[1][1] = 2.0f * nearPlane / (top - bottom);
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;
	m[2][0] = (right + left) / (right - left);
	m[2][1] = (top + bottom) / (top - bottom);
	m[2][2] = -(farPlane + nearPlane) / (farPlane - nearPlane);
	m[2][3] = -1.0f;
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = -(2.0f * farPlane * nearPlane) / (farPlane - nearPlane);
	m[3][3] = 0.0f;

	return true;
}

QMatrix QMatrix::Frustum(const QMatrix& mat, float left, float right, float bottom, float top, float nearPlane, const float farPlane)
{
	QMatrix temp = mat;
	temp.frustum(left, right, bottom, top, nearPlane, farPlane);
	return temp;
}

bool QMatrix::perspective(float fov, float aspect, float nearPlane, float farPlane)
{
	float xmin, xmax, ymin, ymax;

	if(fov <= 0.0f || fov >= 180.0f)
		return false;

	ymax = nearPlane * QMath::Tan(fov * QMath::PI() / 360.0f);
	ymin = -ymax;
	xmin = ymin * aspect;
	xmax = ymax * aspect;

	return frustum(xmin, xmax, ymin, ymax, nearPlane, farPlane);
}

QMatrix QMatrix::Perspective(const QMatrix& mat, float fov, float aspect, float nearPlane, float farPlane)
{
	QMatrix temp = mat;
	temp.perspective(fov, aspect, nearPlane, farPlane);
	return temp;
}

QMatrix QMatrix::Scale(QVector3 v)
{
	QMatrix mat;

	mat.m[0][0] = v.x;
	mat.m[0][1] = 0.0f;
	mat.m[0][2] = 0.0f;
	mat.m[0][3] = 0.0f;

	mat.m[1][0] = 0.0f;
	mat.m[1][1] = v.y;
	mat.m[1][2] = 0.0f;
	mat.m[1][3] = 0.0f;

	mat.m[2][0] = 0.0f;
	mat.m[2][1] = 0.0f;
	mat.m[2][2] = v.z;
	mat.m[2][3] = 0.0f;

	mat.m[3][0] = 0.0f;
	mat.m[3][1] = 0.0f;
	mat.m[3][2] = 0.0f;
	mat.m[3][3] = 1.0f;

	return mat;
}

bool QMatrix::isRowZero(int row)
{
	if(row < 0 || row > 3)
		return true;

	for(int col = 0; col < 4; ++col)
	{
		if(m[col][row] != 0.0)
			return false;
	}

	return true;
}

bool QMatrix::IsRowZero(const QMatrix& mat, int row)
{
	QMatrix temp = mat;
	return temp.isRowZero(row);
}

bool QMatrix::isColumnZero(int col)
{
	if(col < 0 || col > 3)
		return true;

	for(int row = 0; row < 4; ++row)
	{
		if(m[col][row] != 0.0)
			return false;
	}

	return true;
}

bool QMatrix::IsColumnZero(const QMatrix& mat, int col)
{
	QMatrix temp = mat;
	return temp.isColumnZero(col);
}

QVector3 QMatrix::multiplyPoint(QVector3 v)
{
	QVector3 result;
	result.zero();

	result.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3];
	result.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3];
	result.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3];

	float num = m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3];
	num = 1.0f / num;
	result.x *= num;
	result.y *= num;
	result.z *= num;

	return result;
}

QVector3 QMatrix::multiplyPoint3x4(QVector3 v)
{
	QVector3 result;
	result.zero();

	result.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3];
	result.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3];
	result.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3];

	return result;
}

QVector3 QMatrix::multiplyVector(QVector3 v)
{
	QVector3 result;
	result.zero();

	result.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z;
	result.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z;
	result.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z;

	return result;
}

QVector4 QMatrix::getColumn(int i)
{
	return QVector4(m[0][i], m[1][i], m[2][i], m[3][i]);
}

QVector4 QMatrix::getRow(int i)
{
	return QVector4(m[i][0], m[i][1], m[i][2], m[i][3]);
}

void QMatrix::setColumn(int i, QVector4 v)
{
	m[0][i] = v.x;
	m[1][i] = v.y;
	m[2][i] = v.z;
	m[3][i] = v.w;
}

void QMatrix::setRow(int i, QVector4 v)
{
	m[i][0] = v.x;
	m[i][1] = v.y;
	m[i][2] = v.z;
	m[i][3] = v.w;
}

void QMatrix::swapRows(int rowA, int rowB)
{
	float temp;

	for(int col = 0; col < 4; ++col)
	{
		temp = m[col][rowA];
		m[col][rowA] = m[col][rowB];
		m[col][rowB] = temp;
	}
}

void QMatrix::addRows(int rowA, int rowB, float factor)
{
	for(int col = 0; col < 4; ++col)
		m[col][rowA] += m[col][rowB] * factor;
}

void QMatrix::divideRow(int row, float scalar)
{
	for(int col = 0; col < 4; ++col)
		m[col][row] /= scalar;
}

void QMatrix::rotationAxis(const QVector3& vec, float angle)
{
	float cosine = QMath::Sin(2.0f * QMath::PI() * angle / 360.0f);
	float sine = QMath::Cos(2.0f * QMath::PI() * angle / 360.0f);

	QVector3 axis(QVector3::Normalize(vec));

	QMatrix temp;
	temp.identity();

	temp.m[0][0] = axis.x * axis.x * (1 - cosine) + cosine;
	temp.m[0][1] = axis.x * axis.y * (1 - cosine) + axis.z * sine;
	temp.m[0][2] = axis.x * axis.z * (1 - cosine) - axis.y * sine;
	temp.m[1][0] = axis.x * axis.y * (1 - cosine) - axis.z * sine;
	temp.m[1][1] = axis.y * axis.y * (1 - cosine) + cosine;
	temp.m[1][2] = axis.y * axis.z * (1 - cosine) + axis.x * sine;
	temp.m[2][0] = axis.x * axis.z * (1 - cosine) + axis.y * sine;
	temp.m[2][1] = axis.y * axis.z * (1 - cosine) - axis.x * sine;
	temp.m[2][2] = axis.z * axis.z * (1 - cosine) + cosine;

	(*this) = (*this) * temp;
}

QMatrix QMatrix::RotationAxis(const QMatrix& mat, const QVector3& vec, float angle)
{
	QMatrix temp = mat;
	temp.rotationAxis(vec, angle);
	return temp;
}

void QMatrix::rotateX(float angle)
{
	float sine = QMath::Sin(QMath::DegreeToRadian(angle));
	float cosine = QMath::Cos(QMath::DegreeToRadian(angle));

	identity();

	m[1][1] = cosine;
	m[1][2] = sine;
	m[2][1] = -sine;
	m[2][2] = cosine;
}

void QMatrix::rotateY(float angle)
{
	float sine = QMath::Sin(QMath::DegreeToRadian(angle));
	float cosine = QMath::Cos(QMath::DegreeToRadian(angle));

	identity();

	m[0][0] = cosine;
	m[0][2] = sine;
	m[2][0] = -sine;
	m[2][2] = cosine;
}

void QMatrix::rotateZ(float angle)
{
	float sine = QMath::Sin(QMath::DegreeToRadian(angle));
	float cosine = QMath::Cos(QMath::DegreeToRadian(angle));

	identity();

	m[0][0] = cosine;
	m[0][1] = sine;
	m[1][0] = -sine;
	m[1][1] = cosine;
}

bool QMatrix::operator==(QMatrix rhs)
{
	return ((this->getColumn(0) == rhs.getColumn(0)) && (this->getColumn(1) == rhs.getColumn(1)) && (this->getColumn(2) == rhs.getColumn(2)) && (this->getColumn(3) == rhs.getColumn(3)));
}

bool QMatrix::operator!=(const QMatrix& rhs)
{
	return !(this == rhs);
}

QVector4 QMatrix::operator*(const QVector4& v)
{
	QVector4 result;
	result.identity();

	result.x = this->m[0][0] * v.x + this->m[0][1] * v.y + this->m[0][2] * v.z + this->m[0][3] * v.w;
	result.y = this->m[1][0] * v.x + this->m[1][1] * v.y + this->m[1][2] * v.z + this->m[1][3] * v.w;
	result.z = this->m[2][0] * v.x + this->m[2][1] * v.y + this->m[2][2] * v.z + this->m[2][3] * v.w;
	result.w = this->m[3][0] * v.x + this->m[3][1] * v.y + this->m[3][2] * v.z + this->m[3][3] * v.w;
	return result;
}

QMatrix QMatrix::operator*(const QMatrix& rhs)
{
	QMatrix mat;
	mat.m[0][0] = this->m[0][0] * rhs.m[0][0] + this->m[0][1] * rhs.m[1][0] + this->m[0][2] * rhs.m[2][0] + this->m[0][3] * rhs.m[3][0];
	mat.m[0][1] = this->m[0][0] * rhs.m[0][1] + this->m[0][1] * rhs.m[1][1] + this->m[0][2] * rhs.m[2][1] + this->m[0][3] * rhs.m[3][1];
	mat.m[0][2] = this->m[0][0] * rhs.m[0][2] + this->m[0][1] * rhs.m[1][2] + this->m[0][2] * rhs.m[2][2] + this->m[0][3] * rhs.m[3][2];
	mat.m[0][3] = this->m[0][0] * rhs.m[0][3] + this->m[0][1] * rhs.m[1][3] + this->m[0][2] * rhs.m[2][3] + this->m[0][3] * rhs.m[3][3];
	mat.m[1][0] = this->m[1][0] * rhs.m[0][0] + this->m[1][1] * rhs.m[1][0] + this->m[1][2] * rhs.m[2][0] + this->m[1][3] * rhs.m[3][0];
	mat.m[1][1] = this->m[1][0] * rhs.m[0][1] + this->m[1][1] * rhs.m[1][1] + this->m[1][2] * rhs.m[2][1] + this->m[1][3] * rhs.m[3][1];
	mat.m[1][2] = this->m[1][0] * rhs.m[0][2] + this->m[1][1] * rhs.m[1][2] + this->m[1][2] * rhs.m[2][2] + this->m[1][3] * rhs.m[3][2];
	mat.m[1][3] = this->m[1][0] * rhs.m[0][3] + this->m[1][1] * rhs.m[1][3] + this->m[1][2] * rhs.m[2][3] + this->m[1][3] * rhs.m[3][3];
	mat.m[2][0] = this->m[2][0] * rhs.m[0][0] + this->m[2][1] * rhs.m[1][0] + this->m[2][2] * rhs.m[2][0] + this->m[2][3] * rhs.m[3][0];
	mat.m[2][1] = this->m[2][0] * rhs.m[0][1] + this->m[2][1] * rhs.m[1][1] + this->m[2][2] * rhs.m[2][1] + this->m[2][3] * rhs.m[3][1];
	mat.m[2][2] = this->m[2][0] * rhs.m[0][2] + this->m[2][1] * rhs.m[1][2] + this->m[2][2] * rhs.m[2][2] + this->m[2][3] * rhs.m[3][2];
	mat.m[2][3] = this->m[2][0] * rhs.m[0][3] + this->m[2][1] * rhs.m[1][3] + this->m[2][2] * rhs.m[2][3] + this->m[2][3] * rhs.m[3][3];
	mat.m[3][0] = this->m[3][0] * rhs.m[0][0] + this->m[3][1] * rhs.m[1][0] + this->m[3][2] * rhs.m[2][0] + this->m[3][3] * rhs.m[3][0];
	mat.m[3][1] = this->m[3][0] * rhs.m[0][1] + this->m[3][1] * rhs.m[1][1] + this->m[3][2] * rhs.m[2][1] + this->m[3][3] * rhs.m[3][1];
	mat.m[3][2] = this->m[3][0] * rhs.m[0][2] + this->m[3][1] * rhs.m[1][2] + this->m[3][2] * rhs.m[2][2] + this->m[3][3] * rhs.m[3][2];
	mat.m[3][3] = this->m[3][0] * rhs.m[0][3] + this->m[3][1] * rhs.m[1][3] + this->m[3][2] * rhs.m[2][3] + this->m[3][3] * rhs.m[3][3];
	return mat;
}