#pragma once

#include "C3pDevGrid.h"
#include "C3pResult.h"
#include "C3pSolves.h"

#include "CmcResult.h"
#include "CmcCase.h"
#include "CmcCasePack.h"

class C3pSolveMvc
{
protected:
	C3pDevGrid * p3pHvdc;
	C3pProfile* p3pProfile;
	C3pResult* p3pResult;
	C3pSolves * p3pSolves;

	C3pOrder * p3pOrder;

	CmcResult * pmcCase;

public:
	~C3pSolveMvc();

	void Clear();

	void Init(C3pDevGrid* vGrid);

	void InitOrder(C3pOrder * vOrder);


protected:

	void doNewSolves(int vGNDType);

protected:
	int StaCount();

	double hMax();
	double Frequence();


	void doInitRun();

	void doRun();
	void doRunCal(CmcCasePack & vRoot);
	void doRunCase(CmcCasePack * vCasePack);
	void doRunPd(CmcCase * vPdCase);

	void doRecordResult();

	void doSetStationData(struct_mcResultData * vData);

	void doPrepare3pData(int vDType, int vLoopTimes);

	void doStationSort();


public:
	void Run(CmcResult * vResult);

};
