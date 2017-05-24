#pragma once

#include "CxbSolves.h"
#include "CzkProfile.h"

class CzkSolves :public CxbSolves
{
protected:
	CzkProfile * pzkProfile;

public:
	void Init(CxbProfile* vProfile, CxbHvdcGrid * vGrid) override;

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
