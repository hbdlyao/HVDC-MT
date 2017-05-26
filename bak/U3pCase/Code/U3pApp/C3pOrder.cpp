

#include "C3pOrder.h"

#include "CHvdcDefs.h"

#include "C3pDefs.h"
#include "C3pParams.h"

void C3pOrder::Init()
{
	CHvdcOrder::Init();
}


int C3pOrder::LoopTimes()
{
	return 0;
}

int C3pOrder::StaCount()
{
	return C3pParams::StationCount;
}
