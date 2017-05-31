#pragma once

#include "C3pDevGrid.h"
#include "C3pResult.h"
#include "C3pSolves.h"


class C3pSolveMvc
{
protected:
	C3pDevGrid * p3pHvdc;
	C3pProfile* p3pProfile;
	C3pResult* p3pResult;
	C3pSolves * p3pSolves;

	C3pOrder * p3pOrder;

public:
	virtual ~C3pSolveMvc();

	virtual void Init(C3pDevGrid* vGrid);

	virtual void Clear();
	virtual void InitOrder(C3pOrder * vOrder);

public:
	virtual void Test(int vGNDType);
	virtual void Run();
protected:

	virtual void doNewSolves(int vGNDType);



protected:
	int StaCount();

	double hMax();
	double Frequence();


	//
	void doInitRun();

	virtual void doRecordResult();

	void doDataSelected(string vCalName, string vCaseID, double vPdPersent);

	virtual void doRun();

	void doPrepare3pData(int vDType, int vLoopTimes);

	void doStationSort();

};
