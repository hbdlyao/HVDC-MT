#pragma once

#include "CPowerSolves.h"
#include "CxbHvdcGrid.h"
#include "ClmProfile.h"

class ClmSolves : public CPowerSolves
{
protected:
	CxbHvdcGrid * plmHvdc;
	ClmProfile * plmProfile;
	ClmOrder * plmOrder;

public:
	virtual void Init(ClmProfile* vProfile, CxbHvdcGrid * vGrid) ;

public:
	virtual void InitOrder(ClmOrder * vOrder);
	virtual void NewSolves();

protected:
	void doNewItem(int vtblType)  override;
	void doNewItem(CDevTBL * vTBL) override;

	CPowerCalculate * doNewCal(CDevBase* vDev) override;

public:
	void Run() override;

};
