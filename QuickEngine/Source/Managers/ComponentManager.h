#ifndef __COMPONENT_MANAGER_H__
#define __COMPONENT_MANAGER_H__

#include <vector>

class BaseComponent;

template<class T>
class ComponentManager
{
protected:
	const std::vector<BaseComponent*>* m_vList;

public:
	ComponentManager(const std::vector<BaseComponent*>& _List) : m_vList(&_List) {}
	virtual ~ComponentManager() {}

	// Get the size of the component list
	int GetSize() const { return m_vList->size(); }

	// Get a specific element of the component list.
	T *operator[](int nIndex) 
	{ 
		return static_cast<T*>((*m_vList)[nIndex]); 
	}
};

#endif