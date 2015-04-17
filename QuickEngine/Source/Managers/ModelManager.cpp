#include <Common.h>
#include "ModelManager.h"

ModelManager* ModelManager::GetInstance(void)
{
	static ModelManager pInstance;
	return &pInstance;
}
