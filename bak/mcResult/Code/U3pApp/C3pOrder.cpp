

#include "C3pOrder.h"

#include "CHvdcDefs.h"

#include "C3pDefs.h"
#include "C3pParams.h"

void C3pOrder::Init()
{
	CHvdcOrder::Init();

	ValveKId = 0.008;
	ValveKUv = 0.00084;
}

double C3pOrder::GetValveKId()
{
	return ValveKId;
}

double C3pOrder::GetValveKUv()
{
	return ValveKUv;
}

void C3pOrder::SetValveKId(double vVal)
{
	ValveKId = vVal;
}

void C3pOrder::SetValveKUv(double vVal)
{
	ValveKUv = vVal;
}

int C3pOrder::LoopTimes()
{
	if (DType == C3pDefs::DRandom)
		return RandTimes;
	return 1;
}

int C3pOrder::StaCount()
{
	return C3pParams::StationCount;
}
