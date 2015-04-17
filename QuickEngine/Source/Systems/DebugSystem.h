#ifndef __DEBUGSYSTEM_H__
#define __DEBUGSYSTEM_H__

class DebugSystem : public QSystem<DebugSystem>
{
public:

	DebugSystem() { }

	void update(QEntityManager& entities, QEventManager& events, QTimeDelta dt) override;

};

#endif