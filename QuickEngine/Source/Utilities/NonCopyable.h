#ifndef __NON_COPYABLE_H__
#define __NON_COPYABLE_H__

class NonCopyable
{
protected:

	NonCopyable() = default;
	~NonCopyable() = default;

	NonCopyable(const NonCopyable&) = delete;
	NonCopyable& operator=(const NonCopyable&) = delete;

};

#endif//__NON_COPYABLE_H__