#pragma once

#include "C3pDevGrid.h"

class C3pVars
{

public:
	static C3pDevGrid* pGrid;

	static void Init();
	static void Release();
	static void Clear();

protected:
	C3pVars(const C3pVars& vInstance){}
	C3pVars(){}
	~C3pVars();

	static void doInitGrid();

};
