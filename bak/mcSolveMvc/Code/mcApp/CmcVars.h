#pragma once


#include "CmcHvdcGrid.h"


class CmcVars
{
public:

	static CmcHvdcGrid  * pmcHvdcGrid ;

	static void Init();
	static void Release();
	static void Clear();

protected:
	static void doInitGrid();

	CmcVars(const CmcVars& vInstance) {};

	CmcVars() {};
	~CmcVars();

};

//
