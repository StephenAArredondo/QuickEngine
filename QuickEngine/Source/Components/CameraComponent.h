#ifndef __CAMERA_COMPONENT_H__
#define __CAMERA_COMPONENT_H__

struct CameraComponent : QComponent<CameraComponent>
{
	CameraComponent(QMatrix& viewMatrix, bool isMain, bool isActive) : m_ViewMatrix(viewMatrix), m_IsMain(isMain), m_IsActive(isActive) { }
	CameraComponent() : m_ViewMatrix(QMatrix::Identity()), m_IsMain(false), m_IsActive(true) { }

	uint32_t m_FieldOfView;
	float m_NearClippingPlane;
	float m_FarClippingPlane;
	
	bool m_IsActive;
	bool m_IsMain;

	QRenderContext* m_RenderContext;
	QMatrix m_ProjectionMatrix;
	QMatrix m_ViewMatrix;

	Camera m_Camera;
};

#endif//__CAMERA_COMPONENT_H__