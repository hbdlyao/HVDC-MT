
#include "ClmCalculate.h"

#include "CxbDevBase.h"

void ClmCalculate::Init(CDevBase* vDev)
{
	pDevice = vDev;
}

void ClmCalculate::Init(ClmProfile* vProfile)
{
	pProfile = vProfile;
	plmProfile = dynamic_cast<ClmProfile *> (pProfile);

}

void ClmCalculate::InitOrder(ClmOrder * vOrder)
{
	plmOrder = vOrder;
}


void ClmCalculate::Prepare()
{
	//
}
