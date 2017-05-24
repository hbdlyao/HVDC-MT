#pragma once

#include "CxbProfile.h"
#include "CzkOrder.h"

class CzkProfile : public CxbProfile
{
public:
	CzkOrder* pzkOrder;

	double zkFreq = 50;
	double * pzkReq;

	NodeMap NodeID;

public:
	~CzkProfile();

	void Init() override;

public:
	void Solve()  override;
	void Solve_zkReq();

protected:
	void doInitMatrix()  override;
	void doInitData() override;

};