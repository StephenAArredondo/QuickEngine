#ifndef __INPUT_SYSTEM_H__
#define __INPUT_SYSTEM_H__

class InputSystem : public QSystem<InputSystem>
{
public:

	InputSystem() { };

	void update(QEntityManager& entities, QEventManager& events, QTimeDelta dt) override;

};

#endif