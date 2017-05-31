#pragma once

#include "CPowerCalculate.h"
#include "CxbProfile.h"
#include "CzkProfile.h"

#include "gbHead_xbDevice.h"

class CxbCalculate : public CPowerCalculate
{
protected:
	CxbOrder * pxbOrder;
	CxbProfile * pxbProfile;
	CzkProfile * pzkProfile;
public:
	void Init(CPowerProfile* vProfile) override;
	void Init(CDevBase * vDev) override;
	virtual void InitOrder(CxbOrder * vOrder);

public:
	virtual void Add(CxbCalculate * vItem);
	virtual void Remove(CxbCalculate * vItem);

public:
	virtual void Prepare_zk();

	virtual void UpdateY();
	virtual void UpdateI();
	virtual void SolveI();
	virtual void SolveIeq();

	virtual void Update_zkY();
	virtual void Update_zkI();
};


typedef vector<CxbCalculate*> pxbCalVector;
