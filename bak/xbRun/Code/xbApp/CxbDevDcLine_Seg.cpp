
#include "CxbDevDcLine_Seg.h"


void CxbDevDcLine_Seg::Init()
{
	SetStaCount(2);
	SetDotCount(4);

	InitData();
}

string CxbDevDcLine_Seg::BusName(int vIndex)
{

	string vBus;

	switch (vIndex)
	{
	case 0:
	case 1:
		vBus = GetStationName(0) + "---" + GetNodeName(vIndex);
		break;
	case 2:
	case 3:
		vBus = GetStationName(1) + "---" + GetNodeName(vIndex);
		break;

	default:
		break;
	}

	if (GetNodeName(vIndex) == "-1")
		vBus = "-1";

	return vBus;

}