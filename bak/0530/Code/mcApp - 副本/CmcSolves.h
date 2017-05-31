///////////////////////////////////////////////////////////
//  CmcSolves.h
//  Implementation of the Class CmcSolves
//  Created on:      21-5ÔÂ-2017 0:25:45
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_CB699AD3_67BB_4b40_A792_CFDDEA675C19__INCLUDED_)
#define EA_CB699AD3_67BB_4b40_A792_CFDDEA675C19__INCLUDED_

#include "CmcCalculate.h"
#include "CmcProfile.h"
#include "CmcHvdcGrid.h"
#include "CPowerSolves.h"

class CmcSolves : public CPowerSolves
{
public:
	CmcProfile *  pmcProfile ;
	CmcHvdcGrid * pmcHvdc ;
	CmcOrder* pmcOrder;

public:
	string TypeToName(int vType);
	void Init(CmcProfile* vProfile, CmcHvdcGrid* vGrid);

	virtual void InitOrder(CmcOrder * vOrder);

public:
	virtual void NewSolves(int vGndType);

protected:
	CPowerCalculate * doNewCal(CDevBase * vDev) override;

	void doNewSolvers10();
	void doNewSolvers11();
	void doNewSolvers20();
	void doNewSolvers21();

public:
	void PrepareNormal();
	void Run() override;

protected:
	void doPrepare() override;

	double doGetMaxdX();
	void doOffsetSort();
	void doSaveX();

	 
	void doInit_XVect();
	void doSovleDcNet();
	void doSolve_dX();
	void doUpdateF();
	void doUpdateJ();
	void doUpdateY();
	void doUpdateX();

	void doUpdateUdio();
	void doLimitUd();

	virtual void doCalStation();

};


#endif // !defined(EA_CB699AD3_67BB_4b40_A792_CFDDEA675C19__INCLUDED_)
