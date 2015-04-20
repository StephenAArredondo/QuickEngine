#ifndef __RENDER_SYSTEM_H__
#define __RENDER_SYSTEM_H__

class RenderSystem : public QSystem<RenderSystem>, public QReceiver < RenderSystem >

{
public:

	RenderSystem(QWindow* windowHandle) : m_WindowHandle(windowHandle) { }

	void update(QEntityManager& entities, QEventManager& events, QTimeDelta dt) override;

private:

	QWindow* m_WindowHandle;
	
	void draw();
	void drawGrid();
	void drawShapes();

};

#endif//__RENDER_SYSTEM_H__