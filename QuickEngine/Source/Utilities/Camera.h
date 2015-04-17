#ifndef __CAMERA_H__
#define __CAMERA_H__

#define kSpeed	15.0f

class Camera
{

private:

	QMatrix	m_m4ProjectionMatrix;
	QMatrix	m_m4ViewMatrix;

	float	m_fSpeed;

	unsigned int m_uiCameraID;

public:

	Camera(void);
	~Camera(void);

	void SetCameraID(unsigned int _uiCameraID) { m_uiCameraID = _uiCameraID; }

	void Look();
	void CheckInput();

	/*=====================================================================
	Projection Matrix Functions
	//===================================================================*/
	QMatrix GetProjectionMatrix(void);
	void SetProjectionMatrix(QMatrix *_mMatrix);
	void BuildPerspective(float _fFieldOfView, float _fAspect, float _fZNear, float _fZFar);

	/*=====================================================================
	View Matrix Functions
	//===================================================================*/
	QMatrix GetViewMatrix(bool _bTranslate = true);
	void SetViewMatrix(QMatrix *_mMatrix);
	void NormalizeViewMatrix(void);

	QVector3 GetViewXAxis(void);
	void SetViewXAxis(QVector3 _vPosition);
	void SetViewXAxis(float _fX, float _fY, float _fZ);

	QVector3 GetViewYAxis(void);
	void SetViewYAxis(QVector3 _vPosition);
	void SetViewYAxis(float _fX, float _fY, float _fZ);

	QVector3 GetViewZAxis(void);
	void SetViewZAxis(QVector3 _vPosition);
	void SetViewZAxis(float _fX, float _fY, float _fZ);

	QVector3 GetViewPosition(void);
	void SetViewPosition(QVector3 _vPosition);
	void SetViewPosition(float _fX, float _fY, float _fZ);

	/*=================================================================
	Local Transform Functions
	//===============================================================*/
	void ViewRotateLocalX(float _fAngle);
	void ViewRotateLocalY(float _fAngle);
	void ViewRotateLocalZ(float _fAngle);

	void ViewTranslateLocal(QVector3 _vAxis, bool _bFPS = false);
	void ViewTranslateLocalX(float _fScale, bool _bFPS = false);
	void ViewTranslateLocalY(float _fScale, bool _bFPS = false);
	void ViewTranslateLocalZ(float _fScale, bool _bFPS = false);

	/*=================================================================
	Global Transform Functions
	//===============================================================*/
	void ViewRotateGlobalX(float _fAngle);
	void ViewRotateGlobalY(float _fAngle);
	void ViewRotateGlobalZ(float _fAngle);

	void ViewTranslateGlobal(QVector3 _vAxis);
	void ViewTranslateGlobalX(float _fScale);
	void ViewTranslateGlobalY(float _fScale);
	void ViewTranslateGlobalZ(float _fScale);
};

#endif//__CAMERA_H__