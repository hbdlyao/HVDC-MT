#pragma once

#include "CPowerProfile.h"
#include "CPowerSolves.h"
#include "CPowerGrid.h"

class CPowerSolveMvc
{
public:
	virtual ~CPowerSolveMvc();

	virtual void Init(CPowerGrid * vGrid);

	virtual void Clear();
	virtual void Release();

public:
	virtual void NodeID();
	virtual void Run();
	
protected:

	CPowerProfile* pProfile;
	CPowerGrid* pGrid;
	CPowerSolves* pSolves;

	virtual void doNewSolves();

	virtual void doNodeID();
	virtual void doStationSort();

	virtual void doRun();


};
