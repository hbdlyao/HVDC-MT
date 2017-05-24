#pragma once

#include "CxbHvdcGrid.h"
#include "CxbSolves.h"

#include "CxbSolves.h"

class CxbSolveMvc 
{

protected:
	CxbProfile* pxbProfile;
	CxbSolves * pxbSolves;
	
	CxbHvdcGrid * pxbHvdc;

	CxbResult* pxbResult;

public:
	virtual ~CxbSolveMvc();

	virtual void Init(CxbHvdcGrid* vGrid);
	virtual void Clear();
	virtual void InitOrder();


public:
	virtual void Test(int vGNDType);
	virtual void Run();
protected:
	virtual void doNodeID() ;
	virtual void doStationSort() ;

	virtual void doNewSolves(int vGNDType);

protected:
	int StaCount();
	double hMax();
	double Frequence();


	virtual void doPrepare_U3p(string vCondition);
	virtual void doPrepare_hRLC();

	void doSolveIeq();
	//
	virtual void doInitRun();
	virtual void doInitMatrix();


	virtual void doRecordResult();


	virtual void doRun();

	virtual void doRun_Ground(string vFlag);
	virtual void doRun_Rd(string vFlag);
	virtual void doRun_Ud(string vFlag);
	virtual void doRun_UdCustom();
	virtual void doRun_Uac(string vFlag);
	virtual void doRun_UacSwap(string vFlag, int vIndex, int vStaCount);
	virtual void doRun_Pd();

	//
	virtual void doRun_DCF();


};
