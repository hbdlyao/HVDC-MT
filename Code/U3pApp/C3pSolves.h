#pragma once

#include "C3pProfile.h"
#include "C3pCalculate.h"
#include "C3pDevGrid.h"

#include "CPowerSolves.h"

class C3pSolves : public CPowerSolves
{
public:
	C3pProfile* p3pProfile;
	C3pDevGrid* p3pHvdc;
	C3pOrder * p3pOrder;

	//
	void InitOrder(C3pOrder * vOrder);
	void Init(C3pProfile * vProfile, C3pDevGrid * vGrid);
		
public:

	void NewSolves(int vGndType);

protected:
	void doNewSolvers10();
	void doNewSolvers11();
	void doNewSolvers20();
	void doNewSolvers21();

	void doNewItem(int vtblType)  override;
	void doNewItem(CDevTBL * vTBL) override;

	CPowerCalculate * doNewCal(CDevBase* vDev)  override;


public:
	void Sort3p();
	void Run() override;

protected:
	int GroundType();

	void doUpdate3pData(int i);

	void doSolveMiu();
	void doSolveU3p();
	void doSaveU3pMax();
	void doSolveU3p0();
	void doSolveL();

};