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

	virtual void NewSolves(int vGndType);

protected:
	virtual void doNewXbSolvers10();
	virtual void doNewXbSolvers11();
	virtual void doNewXbSolvers20();

	void doNewItem(int vtblType)  override;
	void doNewItem(CDevTBL * vTBL) override;

	CPowerCalculate * doNewCal(CDevBase* vDev)  override;


public:
	void Sort3p();
	void Run() override;

protected:
	int GroundType();

	void doSolveMiu();
	void doSolveU3p();
	void doSolveL();

};