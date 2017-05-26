
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


void C3pCalculate::Prepare()
{

}


void C3pCalculate::Update3pData(int vLoop)
{
}

void C3pCalculate::do3pIndex(ValveMap & vValMap)
{
	C3pDevBase * vDev = dynamic_cast<C3pDevBase *>(pDevice);

	Index3p = vValMap.find(vDev->GetValveName())->second;
}
