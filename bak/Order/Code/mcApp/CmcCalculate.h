#pragma once

#include "CmcProfile.h"

#include "CPowerCalculate.h"


class CmcCalculate : public CPowerCalculate
{
protected:
	//void doStationSort(StationMap & vStaMap) override;

protected:
	CmcProfile * pmcProfile;
	CmcOrder* pmcOrder;

public:
	void Init(CDevBase * vDev) override;
	void Init(CPowerProfile * vProfile) override;
	virtual void InitOrder(CmcOrder * vOrder);

public:


	virtual void Prepare();
	virtual void PrepareNormal();

	virtual void UpdateY();

	virtual void SaveNormal();

protected:

};
typedef vector<CmcCalculate *> pmcCalVector;
