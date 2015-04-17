#ifndef __BASE_MANAGER_H__
#define __BASE_MANAGER_H__

class BaseManager
{
protected:
	bool m_bInitialized;

public:

	BaseManager() { m_bInitialized = false; }
	virtual ~BaseManager() {}

	virtual void Initialize() = 0;
	virtual void Shutdown() = 0;

	inline bool IsInitialized() { return m_bInitialized; }
};

#endif