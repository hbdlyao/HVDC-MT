#pragma once

#include "C3pOrder.h"
#include "CPowerProfile.h"
#include "C3pDefs.h"


class C3pProfile :public CPowerProfile
{
public:
	int CellDim;
	int hIndex;
	int n6pValor;

	C3pOrder * p3pOrder;

	struct_3p_hData * pU3pData;

	//ValveMap ValMap;

public:
	void ClearData();

	void InitOrder(C3pOrder * vOrder);

	void ReSetData();

public:
	void NewU3pData(int vGNDType);

protected:
	int StaCount();
	int ValvorNum();

	void doNewU3pData1();
	void doNewU3pData2();

public:
	void SolveMiu();
	void SolveU3p();
	void SolveU3p0();
	void SolveL();
	void SaveU3pMax();

protected:
	void doSolveMiu(int vK);

	void doSolveU3p(int vK);

	void doSolveU3p0(int vK);

	void doSolveL(int vK);

	double doSolveOneAnRec(int vK, double va[3], double vu[3], int j);

	double doSolveOneAnInv(int vK, double va[3], double vu[3], int j);

	double doSolveOneBnRec(int vK, double va[3], double vu[3], int j);

	double doSolveOneBnInv(int vK, double va[3], double vu[3], int j);

	double doOneMiuRec(double vR, double vL1, double vL2, double vId, double va, double vomega, double vu, double vU1);
	double doOneMiuInv(double vR, double vL1, double vL2, double vId, double va, double vomega, double vu, double vU1);
};