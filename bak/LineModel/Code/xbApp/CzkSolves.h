#pragma once

#include "CxbSolves.h"
#include "CzkProfile.h"

class CzkSolves :public CxbSolves
{
protected:
	CzkProfile * pzkProfile;
	CxbHvdcGrid * pzkHvdc;

public:
	void Init(CzkProfile* vProfile, CxbHvdcGrid * vGrid) ;

public:
	void NodeID() override;

	void Run() override;

protected:
	void doPrepare() override;
	void doSolve()  override;

	void Update_zkY();
	void Update_zkI();
	void Solve_zkU();
	void Solve_zkReq();
};
