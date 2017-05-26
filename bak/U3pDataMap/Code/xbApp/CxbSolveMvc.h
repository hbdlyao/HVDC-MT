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

	CxbOrder * pxbOrder;

public:
	virtual ~CxbSolveMvc();

	virtual void Clear();

	virtual void Init(CxbHvdcGrid* vGrid);
	virtual void InitOrder(CxbOrder * pxbOrder);


public:
	virtual void Test(int vGNDType);
	virtual void Run();;
protected:
	virtual void doNodeID() ;
	virtual void doStationSort() ;

	virtual void doNewSolves(int vGNDType);

protected:
	int StaCount();
	double hMax();
	double Frequence();

	virtual void doPrepare_hRLC();

	void doSolveIeq();
	//
	virtual void doInitRun();
	virtual void doInitMatrix();


	virtual void doRecordResult();


	virtual void doRun();
	//
	virtual void doRun_DCF();

	virtual void doDataSelected_U3p(string vCalName, string vCaseID, double vPdPersent);

};
