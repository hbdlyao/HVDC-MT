///////////////////////////////////////////////////////////
//  CxbSolves.h
//  Implementation of the Class CxbSolves
//  Created on:      21-4ÔÂ-2017 20:29:55
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_469A6E19_8342_4c51_AFFC_903C552DC24F__INCLUDED_)
#define EA_469A6E19_8342_4c51_AFFC_903C552DC24F__INCLUDED_

#include "CPowerSolves.h"
#include "CxbHvdcGrid.h"
#include "CxbProfile.h"

class CxbSolves : public CPowerSolves
{
protected:
	CxbHvdcGrid * pHvdc;
	CxbProfile * pxbProfile;

public:
	int GroundType();

	virtual void Init(CxbProfile* vProfile, CxbHvdcGrid * vGrid) ;

public:
	virtual void NewSolves(int vGndType);

protected:
	virtual void doNewXbSolvers10();
	virtual void doNewXbSolvers11();
	virtual void doNewXbSolvers20();
	
	void doNewItem(int vtblType) override;
	void doNewItem(CDevTBL * vTBL) override;
	
	CPowerCalculate * doNewCal(CDevBase* vDev) override;

public:
	void Run() override;

	virtual void SolveIeq();

protected:
	virtual void doSolve();

	virtual void doSolveU();
	virtual void doSolveI();

	virtual void doUpdateY();
	virtual void doUpdateI();

};

#endif // !defined(EA_469A6E19_8342_4c51_AFFC_903C552DC24F__INCLUDED_)
