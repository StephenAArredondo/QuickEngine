#include <Common.h>
#include "CameraManager.h"
#include "..\Utilities\Camera.h"

Camera* CameraManager::m_pEmptyCamera;

CameraManager* CameraManager::GetInstance()
{
	static CameraManager pInstance;
	return &pInstance;
}

CameraManager::CameraManager()
{
	m_bInitialized = false;
	m_vCameras.clear();
	m_uiAcitveCameraIndex = 0;
	m_uiNextCameraID = 0;
}

CameraManager::~CameraManager()
{
	if(m_bInitialized)
		Shutdown();
}

void CameraManager::Initialize()
{
	m_pEmptyCamera = CreateCamera((PI / 3.0f), 0.1f, 1000.0f, (800.0f / 600.0f), false, true);
	m_bInitialized = true;
}

void CameraManager::Shutdown()
{
	std::map<unsigned int, Camera*>::iterator pIter = m_vCameras.begin();
	while(pIter != m_vCameras.end())
	{
		delete pIter->second;
		pIter->second = NULL;

		++pIter;
	}
	m_vCameras.clear();

	m_pEmptyCamera = NULL;

	m_uiAcitveCameraIndex = 0;
	m_uiNextCameraID = 0;
}

Camera* CameraManager::CreateCamera(float _fFieldOfView, float _fNearClippingPlane, float _fFarClippingPlane, float _fAspect, bool _bOrthographic, bool _bActive)
{
	unsigned int uiNewID = m_uiNextCameraID++;
	Camera* pCamera = new Camera();

	pCamera->SetViewPosition(0.0f, 0.0f, 0.0f);
	pCamera->BuildPerspective(_fFieldOfView, _fAspect, _fNearClippingPlane, _fFarClippingPlane);
	pCamera->SetCameraID(uiNewID);

	m_vCameras[uiNewID] = pCamera;

	if(_bActive)
		m_uiAcitveCameraIndex = uiNewID;

	return m_vCameras[uiNewID];
}

Camera* CameraManager::CreateCamera(float _fFieldOfView, float _fNearClippingPlane, float _fFarClippingPlane, float _fAspect, QVector3 _v3Position, bool _bOrthographic, bool _bActive)
{
	unsigned int uiNewID = m_uiNextCameraID++;
	Camera* pCamera = new Camera();

	pCamera->SetViewPosition(_v3Position);
	pCamera->BuildPerspective(_fFieldOfView, _fAspect, _fNearClippingPlane, _fFarClippingPlane);
	pCamera->SetCameraID(uiNewID);

	m_vCameras[uiNewID] = pCamera;

	if(_bActive)
		m_uiAcitveCameraIndex = uiNewID;

	return m_vCameras[uiNewID];
}

Camera* CameraManager::GetCamera(unsigned int _uiCameraID)
{
	std::map<unsigned int, Camera*>::iterator pIter = m_vCameras.find(_uiCameraID);

	if(pIter == m_vCameras.end())
		return m_pEmptyCamera;

	return m_vCameras[_uiCameraID]; 
}
