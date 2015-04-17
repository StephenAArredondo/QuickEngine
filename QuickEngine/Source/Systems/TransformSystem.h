#ifndef __TRANSFORM__SYSTEM_H__
#define __TRANSFORM__SYSTEM_H__

class TransformSystem : public QSystem<TransformSystem>
{
public:

	TransformSystem() { }
	
	void update(QEntityManager& entities, QEventManager& events, QTimeDelta dt) override;

};

#endif