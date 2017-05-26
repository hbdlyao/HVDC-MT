#pragma once

#include "CPowerCalculate.h"

#include "ClmProfile.h"
#include "gbHead_xbDevice.h"

class ClmCalculate : public CPowerCalculate
{
protected:
	ClmOrder * plmOrder;
	ClmProfile * plmProfile;

public:
	void Init(CDevBase * vDev) override;

	void Init(ClmProfile* vProfile) ;
	void InitOrder(ClmOrder * vOrder);

public:
	void Prepare() override;

};

typedef vector<ClmCalculate*> plmCalVector;

