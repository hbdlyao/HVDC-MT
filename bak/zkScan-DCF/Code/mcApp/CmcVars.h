#pragma once


#include "CmcHvdcGrid.h"
#include "CmcOrder.h"

class CmcVars
{
public:

	static CmcHvdcGrid  * pmcHvdcGrid ;
	static 	CmcOrder * pmcOrder;

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
