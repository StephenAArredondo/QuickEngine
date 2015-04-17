#ifndef __CAMERA_MANAGER_H__
#define __CAMERA_MANAGER_H__

#include "BaseManager.h"

class Camera;

class CameraManager : public BaseManager
{
private:

	std::map<unsigned int, Camera*> m_vCameras;
	unsigned int m_uiAcitveCameraIndex;

	static Camera* m_pEmptyCamera;
	unsigned int m_uiNextCameraID;

	CameraManager();
	~CameraManager();
	CameraManager(const CameraManager&) {}
	CameraManager* operator=(const CameraManager&) {}

public:
	void Initialize();
	void Shutdown();

	Camera* CreateCamera(float _fFieldOfView, float _fNearClippingPlane, float _fFarClippingPlane, float _fAspect, bool _bOrthographic, bool _bActive = false);
	Camera* CreateCamera(float _fFieldOfView, float _fNearClippingPlane, float _fFarClippingPlane, float _fAspect, QVector3 _v3Position, bool _bOrthographic, bool _bActive = false);
	Camera* GetActiveCamera() { return m_vCameras[m_uiAcitveCameraIndex]; }
	Camera* GetCamera(unsigned int _uiCameraID);

	static CameraManager* GetInstance();
};

#endif//__CAMERA_MANAGER_H__