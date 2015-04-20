#ifndef __CAMERA_SYSTEM_H__
#define __CAMERA_SYSTEM_H__

class CameraSystem : public QSystem<CameraSystem>, public QReceiver < CameraSystem >
{
public:

	CameraSystem(QWindow* windowHandle) : m_WindowHandle(windowHandle) { }

	void configure(QEventManager& evemts);
	void update(QEntityManager& entities, QEventManager& events, QTimeDelta dt) override;

	void receive(const TranslationEvent& translation);
	void receive(const RotationEvent& rotation);
	void receive(const ScaleEvent& scale);
	void receive(const KeyboardEvent& entityInput);

private:

	QWindow* m_WindowHandle;

	void draw();
	void drawGrid();
	void drawShapes();
};

#endif//__CAMERA_SYSTEM_H__