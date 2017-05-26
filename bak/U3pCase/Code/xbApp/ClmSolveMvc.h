#pragma once

#include "ClmSolves.h"
#include "ClmProfile.h"
#include "ClmOrder.h"
#include "ClmResult.h"

class ClmSolveMvc
{

public:
	virtual ~ClmSolveMvc();
	virtual void Clear();
	virtual void Init(CxbHvdcGrid* vGrid);
	virtual void InitOrder(ClmOrder* plmOrder);

public:
	void Run();

	void doNewSolves();

protected:
	ClmProfile* plmProfile;
	ClmSolves* plmSolves;
	CxbHvdcGrid* plmHvdc;
	ClmResult* plmResult;
	ClmOrder* plmOrder;

protected:
	double hMax();
	double Frequence();
	void doRun();

};
