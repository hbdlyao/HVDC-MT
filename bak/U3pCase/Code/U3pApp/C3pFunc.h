#pragma once

#include "CMyFunc.h"
#include "CHvdcFunc.h"

class C3pFunc
{
	C3pFunc() {};
	virtual ~C3pFunc() {};
	C3pFunc(const C3pFunc& vFunc) {};

public:
	static string TypeToName(int vType);

	static string ValveName(int vIndex);
};
