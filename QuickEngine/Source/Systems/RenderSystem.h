#ifndef __RENDERSYSTEM_H__
#define __RENDERSYSTEM_H__

class RenderSystem : public QSystem<RenderSystem>
{
public:

	RenderSystem() { }

	void update(QEntityManager& entities, QEventManager& events, QTimeDelta dt) override;

};

#endif