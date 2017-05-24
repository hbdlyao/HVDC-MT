#pragma once

#include "C3pOrder.h"
#include "CPowerProfile.h"
#include "C3pDefs.h"

class C3pProfile :public CPowerProfile
{
public:
	int CellDim;
	int hIndex;

	C3pOrder * p3pOrder;

	struct_3p_hData * pData;

public:
	void InitData();	
	void InitOrder(C3pOrder * vOrder);
	void ReSetData();

public:
	void SolveMiu();
	void SolveU3p();
	void SolveL();

protected:
	void doSolveMiu(int vK);
	void doSolveU3p(int vK);
	void doSolveL(int vK);

};