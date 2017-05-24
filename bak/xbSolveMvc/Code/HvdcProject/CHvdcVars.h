#pragma once


#include "CmcVars.h"
#include "CxbVars.h"
#include "C3pVars.h"

class CHvdcVars
{
public:
	static void Init();
	static void Release();
	static void Clear();

protected:

	CHvdcVars(const CHvdcVars& vInstance) {};

	CHvdcVars() {};
	~CHvdcVars();

};

//
