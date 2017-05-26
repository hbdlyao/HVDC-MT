#pragma once

#include "CMyFunc.h"
#include "CHvdcFunc.h"

class CmcFunc
{
	CmcFunc() {};
	virtual ~CmcFunc() {};
	CmcFunc(const CmcFunc& vFunc) {};

public:
	static string mcTypeToName(int vType);

};
