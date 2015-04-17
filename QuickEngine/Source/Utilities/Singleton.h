#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template<class T>
class Singleton
{
public:
	
	Singleton() { }
	
	static T* getInstance()
	{
		static T pInstance;
		return pInstance;
	}
};

#endif//__SINGLETON_H__