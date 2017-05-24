
#include "C3pCalculate.h"
#include "gbHead_3pDevice.h"


void C3pCalculate::Init(CDevBase * vDev)
{
	pDevice = vDev;
}

void C3pCalculate::Init(CPowerProfile * vProfile)
{
	pProfile = vProfile;

	p3pProfile = dynamic_cast<C3pProfile *> (pProfile);

}


void C3pCalculate::InitOrder(C3pOrder * vOrder)
{
	p3pOrder = vOrder;
}


void C3pCalculate::Sort3p(ValveMap& vValMap)
{
	Index3p = -2;
}

void C3pCalculate::Prepare()
{

}
