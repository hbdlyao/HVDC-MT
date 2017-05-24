#pragma once


#include "CxbHvdcGrid.h"


class CxbVars
{
public:

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
