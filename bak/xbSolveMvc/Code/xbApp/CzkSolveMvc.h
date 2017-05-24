#pragma once

#include "CxbSolveMvc.h"

#include "CzkSolves.h"
#include "CzkProfile.h"
#include "CzkResult.h"


class CzkSolveMvc : public CxbSolveMvc
{
protected:
	CzkProfile* pzkProfile;
	CzkSolves * pzkSolves;
	CzkResult* pzkResult;

	CxbHvdcGrid * pzkHvdc;

public:
	void Init(CxbHvdcGrid* vGrid) override;

	void Test(int vGNDType) override;

protected:
	void doPrepare_hRLC();

	void doRun() override;

	void doRecordResult() override;


};
