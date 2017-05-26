#pragma once

#include "CMyFunc.h"
#include "CHvdcFunc.h"

class CxbFunc
{
	CxbFunc() {};
	virtual ~CxbFunc() {};
	CxbFunc(const CxbFunc& vFunc) {};

public:
	static string xbTypeToName(int vType);

};
