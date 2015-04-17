#ifndef _OBJECT_H_
#define _OBJECT_H_

class Object
{
private:

	const char* m_szName;
	unsigned int m_uiObjID;
	bool m_bActive;


public:

	Object(const char* _szName, unsigned int _uiObjID, bool _bActive) : m_szName(_szName), m_uiObjID(_uiObjID), m_bActive(_bActive);
	virtual ~Object() = 0;

};

#endif