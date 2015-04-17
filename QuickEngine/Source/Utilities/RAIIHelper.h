#ifndef _RAII_HELPER_H_
#define _RAII_HELPER_H_

#include <memory>

// template<class T, class D = std::default_delete<T>>
// struct shared_ptr_with_deleter : public std::shared_ptr<T>
{
	explicit shared_ptr_with_deleter(T* t = nullptr) : std::shared_ptr<T>(t, D()) {}

	void reset(T* t = nullptr) 
	{
		std::shared_ptr<T>::reset(t, D());
	}
};

#endif//_RAII_HELPER_H_