#pragma once

#include "CxbSolveMvc.h"

#include "CzkSolves.h"
#include "CzkProfile.h"
#include "CzkResult.h"


class CzkSolveMvc : public CxbSolveMvc
{
protected:
	CxbHvdcGrid * pzkHvdc;
	CzkProfile* pzkProfile;
	CzkSolves * pzkSolves;
	CzkResult* pzkResult;
	CzkOrder* pzkOrder;

public:
	void Init(CxbHvdcGrid* vGrid) override;
	void InitOrder(CzkOrder * vOrder);

	void Run() override;

	void Test(int vGNDtype) override;

protected:
	void doPrepare_hRLC();

	void doRun() override;

	void doRecordResult() override;

	void doDataSelected_U3p(string vCalName, string vCaseID, double vPdPersent) override;


};
