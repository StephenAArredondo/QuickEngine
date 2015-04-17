#include <Common.h>
#include "Camera.h"

Camera::Camera(void)
{
	m_m4ProjectionMatrix.identity();
	m_m4ViewMatrix.identity();

	m_fSpeed = 1200.0f;
	m_uiCameraID = 0;
}

Camera::~Camera(void){}

QMatrix Camera::GetProjectionMatrix(void)
{
	return m_m4ProjectionMatrix;
}

void Camera::SetProjectionMatrix(QMatrix* _mMatrix)
{
	m_m4ProjectionMatrix = (*_mMatrix);
}

void Camera::BuildPerspective(float _fFieldOfView, float _fAspectRatio, float _fZNear, float _fZFar)
{
	m_m4ProjectionMatrix.perspective(_fFieldOfView, _fAspectRatio, _fZNear, _fZFar);
}

QMatrix Camera::GetViewMatrix(bool _bTranslate)
{
	QMatrix _mRotation(m_m4ViewMatrix), _mTransform;
	_mRotation.m[3][0] = _mRotation.m[3][1] = _mRotation.m[3][2] = 0;
	_mRotation.transpose();

	_mTransform.identity();
	_mTransform.m[3][0] = -(m_m4ViewMatrix.m[3][0]);
	_mTransform.m[3][1] = -(m_m4ViewMatrix.m[3][1]);
	_mTransform.m[3][2] = -(m_m4ViewMatrix.m[3][2]);

	_mTransform = _mTransform * _mRotation;
	return ( _bTranslate ? _mTransform : _mRotation );
}

void Camera::SetViewMatrix(QMatrix*_mMatrix)
{
	m_m4ViewMatrix = (*_mMatrix);
}

void Camera::NormalizeViewMatrix(void)
{
	/*=================================================================
	QVector3 xAxis,
	yAxis(0.0f, 1.0f, 0.0f),
	zAxis(m_m4ViewMatrix._31, m_m4ViewMatrix._32, m_m4ViewMatrix._33);

	D3DXVec3Normalize(&zAxis, &zAxis);
	D3DXVec3Cross(&xAxis, &zAxis, &yAxis); 
	D3DXVec3Normalize(&xAxis, &xAxis);
	D3DXVec3Cross(&yAxis, &xAxis, &zAxis);
	D3DXVec3Normalize(&yAxis, &yAxis);

	m_m4ViewMatrix._11 = xAxis.x; m_m4ViewMatrix._12 = xAxis.y; m_m4ViewMatrix._13 = xAxis.z; m_m4ViewMatrix._14 = 0;
	m_m4ViewMatrix._21 = yAxis.x; m_m4ViewMatrix._22 = yAxis.y; m_m4ViewMatrix._23 = yAxis.z; m_m4ViewMatrix._24 = 0;
	m_m4ViewMatrix._31 = zAxis.x; m_m4ViewMatrix._32 = zAxis.y; m_m4ViewMatrix._33 = zAxis.z; m_m4ViewMatrix._34 = 0;
	//===============================================================*/
}

QVector3 Camera::GetViewXAxis(void)
{
	return QVector3(m_m4ViewMatrix.m[0][0], m_m4ViewMatrix.m[0][1], m_m4ViewMatrix.m[0][2]);
}

void Camera::SetViewXAxis(QVector3 _vPosition)
{
	m_m4ViewMatrix.m[0][0] = _vPosition.x;
	m_m4ViewMatrix.m[0][1] = _vPosition.y;
	m_m4ViewMatrix.m[0][2] = _vPosition.z;
}

void Camera::SetViewXAxis(float _fX, float _fY, float _fZ)
{
	m_m4ViewMatrix.m[0][0] = _fX;
	m_m4ViewMatrix.m[0][1] = _fY;
	m_m4ViewMatrix.m[0][2] = _fZ;
}

QVector3 Camera::GetViewYAxis(void)
{
	return QVector3(m_m4ViewMatrix.m[1][0], m_m4ViewMatrix.m[1][1], m_m4ViewMatrix.m[1][2]);
}

void Camera::SetViewYAxis(QVector3 _vPosition)
{
	m_m4ViewMatrix.m[1][0] = _vPosition.x;
	m_m4ViewMatrix.m[1][1] = _vPosition.y;
	m_m4ViewMatrix.m[1][2] = _vPosition.z;
}

void Camera::SetViewYAxis(float _fX, float _fY, float _fZ)
{
	m_m4ViewMatrix.m[1][0] = _fX;
	m_m4ViewMatrix.m[1][1] = _fY;
	m_m4ViewMatrix.m[1][2] = _fZ;
}

QVector3 Camera::GetViewZAxis(void)
{
	return QVector3(m_m4ViewMatrix.m[2][0], m_m4ViewMatrix.m[2][1], m_m4ViewMatrix.m[2][2]);
}

void Camera::SetViewZAxis(QVector3 _vPosition)
{
	m_m4ViewMatrix.m[2][0] = _vPosition.x;
	m_m4ViewMatrix.m[2][1] = _vPosition.y;
	m_m4ViewMatrix.m[2][2] = _vPosition.z;
}

void Camera::SetViewZAxis(float _fX, float _fY, float _fZ)
{
	m_m4ViewMatrix.m[2][0] = _fX;
	m_m4ViewMatrix.m[2][1] = _fY;
	m_m4ViewMatrix.m[2][2] = _fZ;
}

QVector3 Camera::GetViewPosition(void)
{
	return QVector3(m_m4ViewMatrix.m[3][0], m_m4ViewMatrix.m[3][1], m_m4ViewMatrix.m[3][2]);
}

void Camera::SetViewPosition(QVector3 _vPosition)
{
	m_m4ViewMatrix.m[3][0] = _vPosition.x;
	m_m4ViewMatrix.m[3][1] = _vPosition.y;
	m_m4ViewMatrix.m[3][2] = _vPosition.z;
}

void Camera::SetViewPosition(float _fX, float _fY, float _fZ)
{
	m_m4ViewMatrix.m[3][0] = _fX;
	m_m4ViewMatrix.m[3][1] = _fY;
	m_m4ViewMatrix.m[3][2] = _fZ;
}

/*====================================================================/
Local Transform Functions
//===================================================================*/
void Camera::ViewRotateLocalX(float _fAngle)
{
	QMatrix  _mRotation;
	QVector3 _vLocalX(m_m4ViewMatrix.m[0][0], m_m4ViewMatrix.m[0][1], m_m4ViewMatrix.m[0][2]);
	_mRotation.rotationAxis(_vLocalX, _fAngle);

	QVector4 Position(m_m4ViewMatrix.m[3][0], m_m4ViewMatrix.m[3][1], m_m4ViewMatrix.m[3][2], m_m4ViewMatrix.m[3][3]);
	m_m4ViewMatrix.m[3][0] = m_m4ViewMatrix.m[3][1] = m_m4ViewMatrix.m[3][2] = 0.0f; 

	m_m4ViewMatrix = m_m4ViewMatrix * _mRotation;
	m_m4ViewMatrix.m[3][0] = Position.x; m_m4ViewMatrix.m[3][1] = Position.y;
	m_m4ViewMatrix.m[3][2] = Position.z; m_m4ViewMatrix.m[3][3] = Position.w;
}

void Camera::ViewRotateLocalY(float _fAngle)
{
	QMatrix  _mRotation;
	QVector3 _vLocalY(m_m4ViewMatrix.m[1][0], m_m4ViewMatrix.m[1][1], m_m4ViewMatrix.m[1][2]);
	_mRotation.rotationAxis(_vLocalY, _fAngle);

	QVector4 Position(m_m4ViewMatrix.m[3][0], m_m4ViewMatrix.m[3][1], m_m4ViewMatrix.m[3][2], m_m4ViewMatrix.m[3][3]);
	m_m4ViewMatrix.m[3][0] = m_m4ViewMatrix.m[3][1] = m_m4ViewMatrix.m[3][2] = 0.0f; 

	m_m4ViewMatrix = m_m4ViewMatrix * _mRotation;
	m_m4ViewMatrix.m[3][0] = Position.x; m_m4ViewMatrix.m[3][1] = Position.y;
	m_m4ViewMatrix.m[3][2] = Position.z; m_m4ViewMatrix.m[3][3] = Position.w;
}

void Camera::ViewRotateLocalZ(float _fAngle)
{
	QMatrix  _mRotation;
	QVector3 _vLocalZ(m_m4ViewMatrix.m[2][0], m_m4ViewMatrix.m[2][1], m_m4ViewMatrix.m[2][2]);
	_mRotation.rotationAxis(_vLocalZ, _fAngle);

	QVector4 Position(m_m4ViewMatrix.m[3][0], m_m4ViewMatrix.m[3][1], m_m4ViewMatrix.m[3][2], m_m4ViewMatrix.m[3][3]);
	m_m4ViewMatrix.m[3][0] = m_m4ViewMatrix.m[3][1] = m_m4ViewMatrix.m[3][2] = 0.0f; 

	m_m4ViewMatrix = m_m4ViewMatrix * _mRotation;
	m_m4ViewMatrix.m[3][0] = Position.x; m_m4ViewMatrix.m[3][1] = Position.y;
	m_m4ViewMatrix.m[3][2] = Position.z; m_m4ViewMatrix.m[3][3] = Position.w;
}

void Camera::ViewTranslateLocal(QVector3 _vAxis, bool _bFPS)
{
	if (_bFPS)
	{
		ViewTranslateLocalX(_vAxis.x, _bFPS);
		ViewTranslateLocalY(_vAxis.y, _bFPS);
		ViewTranslateLocalZ(_vAxis.z, _bFPS);
		return;
	}

	ViewTranslateLocalX(_vAxis.x);
	ViewTranslateLocalY(_vAxis.y);
	ViewTranslateLocalZ(_vAxis.z);
}

void Camera::ViewTranslateLocalX(float _fScale, bool _bFPS)
{
	if (_bFPS)
	{
		QVector3 _vTranslate(m_m4ViewMatrix.m[0][0], 0.0f, m_m4ViewMatrix.m[0][2]);
		QVector3::Normalize(*&_vTranslate);

		m_m4ViewMatrix.m[3][0] += _vTranslate.x * _fScale;
		m_m4ViewMatrix.m[3][1] += _vTranslate.y * _fScale;
		m_m4ViewMatrix.m[3][2] += _vTranslate.z * _fScale;

		return;
	}
	m_m4ViewMatrix.m[3][0] += (m_m4ViewMatrix.m[0][0] * _fScale);
	m_m4ViewMatrix.m[3][1] += (m_m4ViewMatrix.m[0][1] * _fScale);
	m_m4ViewMatrix.m[3][2] += (m_m4ViewMatrix.m[0][2] * _fScale);
}

void Camera::ViewTranslateLocalY(float _fScale, bool _bFPS)
{
	if (_bFPS)
	{
		QVector3 _vTranslate(m_m4ViewMatrix.m[1][0], 0.0f, m_m4ViewMatrix.m[1][2]);
		QVector3::Normalize(*&_vTranslate);

		m_m4ViewMatrix.m[3][0] += _vTranslate.x * _fScale;
		m_m4ViewMatrix.m[3][1] += _vTranslate.y * _fScale;
		m_m4ViewMatrix.m[3][2] += _vTranslate.z * _fScale;

		return;
	}
	m_m4ViewMatrix.m[3][0] += (m_m4ViewMatrix.m[1][0] * _fScale);
	m_m4ViewMatrix.m[3][1] += (m_m4ViewMatrix.m[1][1] * _fScale);
	m_m4ViewMatrix.m[3][2] += (m_m4ViewMatrix.m[1][2] * _fScale);
}

void Camera::ViewTranslateLocalZ(float _fScale, bool _bFPS)
{
	if (_bFPS)
	{
		QVector3 _vTranslate(m_m4ViewMatrix.m[2][0], 0.0f, m_m4ViewMatrix.m[2][2]);
		QVector3::Normalize(*&_vTranslate);

		m_m4ViewMatrix.m[3][0] += _vTranslate.x * _fScale;
		m_m4ViewMatrix.m[3][1] += _vTranslate.y * _fScale;
		m_m4ViewMatrix.m[3][2] += _vTranslate.z * _fScale;

		return;
	}
	m_m4ViewMatrix.m[3][0] += (m_m4ViewMatrix.m[2][0] * _fScale);
	m_m4ViewMatrix.m[3][1] += (m_m4ViewMatrix.m[2][1] * _fScale);
	m_m4ViewMatrix.m[3][2] += (m_m4ViewMatrix.m[2][2] * _fScale);
}

/*====================================================================/
Global Transform Functions
//===================================================================*/
void Camera::ViewRotateGlobalX(float _fAngle)
{
	QMatrix _mRotation;
	QVector4 Position(m_m4ViewMatrix.m[3][0], m_m4ViewMatrix.m[3][1], m_m4ViewMatrix.m[3][2], m_m4ViewMatrix.m[3][3]);
	_mRotation.rotateX(_fAngle);

	m_m4ViewMatrix.m[3][0] = m_m4ViewMatrix.m[3][1] = m_m4ViewMatrix.m[3][2] = 0.0f; 

	m_m4ViewMatrix = m_m4ViewMatrix * _mRotation;
	m_m4ViewMatrix.m[3][0] = Position.x; m_m4ViewMatrix.m[3][1] = Position.y;
	m_m4ViewMatrix.m[3][2] = Position.z; m_m4ViewMatrix.m[3][3] = Position.w;
}

void Camera::ViewRotateGlobalY(float _fAngle)
{
	QMatrix _mRotation;
	QVector4 Position(m_m4ViewMatrix.m[3][0], m_m4ViewMatrix.m[3][1], m_m4ViewMatrix.m[3][2], m_m4ViewMatrix.m[3][3]);
	_mRotation.rotateY(_fAngle);

	m_m4ViewMatrix.m[3][0] = m_m4ViewMatrix.m[3][1] = m_m4ViewMatrix.m[3][2] = 0.0f; 

	m_m4ViewMatrix = m_m4ViewMatrix * _mRotation;
	m_m4ViewMatrix.m[3][0] = Position.x; m_m4ViewMatrix.m[3][1] = Position.y;
	m_m4ViewMatrix.m[3][2] = Position.z; m_m4ViewMatrix.m[3][3] = Position.w;
}

void Camera::ViewRotateGlobalZ(float _fAngle)
{
	QMatrix _mRotation;
	QVector4 Position(m_m4ViewMatrix.m[3][0], m_m4ViewMatrix.m[3][1], m_m4ViewMatrix.m[3][2], m_m4ViewMatrix.m[3][3]);
	_mRotation.rotateZ(_fAngle);

	m_m4ViewMatrix.m[3][0] = m_m4ViewMatrix.m[3][1] = m_m4ViewMatrix.m[3][2] = 0.0f; 

	m_m4ViewMatrix = m_m4ViewMatrix * _mRotation;
	m_m4ViewMatrix.m[3][0] = Position.x; m_m4ViewMatrix.m[3][1] = Position.y;
	m_m4ViewMatrix.m[3][2] = Position.z; m_m4ViewMatrix.m[3][3] = Position.w;
}

void Camera::ViewTranslateGlobal(QVector3 _vAxis)
{
	m_m4ViewMatrix.m[3][0] += _vAxis.x;
	m_m4ViewMatrix.m[3][1] += _vAxis.y;
	m_m4ViewMatrix.m[3][2] += _vAxis.z;
}

void Camera::ViewTranslateGlobalX(float _fScale)
{
	m_m4ViewMatrix.m[3][0] += _fScale;
}

void Camera::ViewTranslateGlobalY(float _fScale)
{
	m_m4ViewMatrix.m[3][1] += _fScale;
}

void Camera::ViewTranslateGlobalZ(float _fScale)
{
	m_m4ViewMatrix.m[3][2] += _fScale;
}

void Camera::Look()
{
	QMatrix m4MVP = QMatrix::Inverse(m_m4ViewMatrix);/* * m_m4ProjectionMatrix*/;
	glLoadMatrixf(&m4MVP.m[0][0]);

	//////////////////////////////////////////////////////////////////////////
	// Model View Projection
	// Mat4 MVP = Projection * View * Model
}

void Camera::CheckInput()
{
	// 		//Once we have the frame interval, we find the current speed
	// 		float speed = m_fSpeed * .00001f;
	// 	
	// 		// Check if we hit the Up arrow or the 'w' key
	// 		if(GetKeyState(VK_UP) & 0x80 || GetKeyState('W') & 0x80) {				
	// 	
	// 			// Move our camera forward by a positive SPEED
	// 			ViewTranslateLocalZ(-speed);				
	// 		}
	// 	
	// 		// Check if we hit the Down arrow or the 's' key
	// 		if(GetKeyState(VK_DOWN) & 0x80 || GetKeyState('S') & 0x80) {			
	// 	
	// 			// Move our camera backward by a negative SPEED
	// 			ViewTranslateLocalZ(speed);				
	// 		}
	// 	
	// 		// Check if we hit the 'r' key
	// 		if(GetKeyState(VK_SPACE) & 0x80) {			
	// 	
	// 			// Move our camera backward by a negative SPEED
	// 			ViewTranslateLocalY(speed);				
	// 		}
	// 	
	// 		// Check if we hit the 'f' key
	// 		if(GetKeyState(VK_SHIFT) & 0x80) {			
	// 	
	// 			// Move our camera backward by a negative SPEED
	// 			ViewTranslateLocalY(-speed);				
	// 		}
	// 	
	// 		// Check if we hit the Left arrow or the 'a' key
	// 		if(GetKeyState(VK_LEFT) & 0x80 || GetKeyState('A') & 0x80) {			
	// 	
	// 			// Strafe the camera left
	// 			ViewTranslateLocalX(-speed);
	// 		}
	// 	
	// 		// Check if we hit the Right arrow or the 'd' key
	// 		if(GetKeyState(VK_RIGHT) & 0x80 || GetKeyState('D') & 0x80) {			
	// 	
	// 			// Strafe the camera right
	// 			ViewTranslateLocalX(speed);
	// 		}
	// 	
	// 		if(GetKeyState('Q') & 0x80) {
	// 	
	// 			// Strafe the camera right
	// 			ViewRotateLocalY(m_fSpeed * 0.0001f);
	// 		}
	// 	
	// 		if(GetKeyState('E') & 0x80) {
	// 	
	// 			// Strafe the camera right
	// 			ViewRotateLocalY(-m_fSpeed * 0.0001f);
	// 		}
	// 	
	// 		if(GetKeyState(VK_ADD) & 0x80) {
	// 			m_fSpeed += 0.5f;
	// 		}
	// 	
	// 		if(GetKeyState(VK_SUBTRACT) & 0x80) {
	// 			m_fSpeed -= 0.5f;
	// 		}
	// 	
	// 		if(GetKeyState(VK_MULTIPLY) & 0x80) {
	// 			m_fSpeed = 1200;
	// 		}
	// 	
	// 		m_fSpeed = (m_fSpeed > 1800.0f) ? 1800.0f : (m_fSpeed <= 20) ? 20 : m_fSpeed;
}