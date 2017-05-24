#pragma once

#include "CxbHvdcGrid.h"

#include "CxbOrder.h"
#include "CzkOrder.h"
#include "ClmOrder.h"

class CxbVars
{
public:
	static 	CxbOrder * pxbOrder;
	static 	ClmOrder * plmOrder;
	static 	CzkOrder * pzkOrder;


	static CxbHvdcGrid  * pxbHvdcGrid ;

	static void Init();
	static void Release();
	static void Clear();

protected:
	static void doInitGrid();
	static void doInitOrder();

protected:
	CxbVars(const CxbVars& vInstance) {};

	CxbVars() {};
	~CxbVars();

};

//
