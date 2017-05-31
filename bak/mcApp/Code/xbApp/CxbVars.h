#pragma once


#include "CxbHvdcGrid.h"
#include "CxbOrder.h"

class CxbVars
{
public:
	static 	CxbOrder * pxbOrder;

	static CxbHvdcGrid  * pxbHvdcGrid ;

	static void Init();
	static void Release();
	static void Clear();

protected:
	static void doInitGrid();

	CxbVars(const CxbVars& vInstance) {};

	CxbVars() {};
	~CxbVars();

};

//
