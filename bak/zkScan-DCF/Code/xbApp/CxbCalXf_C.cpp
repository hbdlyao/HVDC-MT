///////////////////////////////////////////////////////////
//  CxbCalXf_C.cpp
//  Implementation of the Class CxbCalXf_C
//  Created on:      05-4ÔÂ-2017 18:33:05
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbCalXf_C.h"

void CxbCalXf_C::Update_zkY()
{
	//¿ªÂ·
	CxbDevXf_C * vDev;

	vDev = dynamic_cast<CxbDevXf_C *>(pDevice);

	string vStation = pzkProfile->pzkOrder->ScanPortStation;
	int vPort = pzkProfile->pzkOrder->ScanPortPole;

	bool vIsScaned = (vStation == vDev->GetStationName());
	vIsScaned = vIsScaned && (vPort == vDev->GetPosOrNeg());

	//
	if (!vIsScaned)
		UpdateY();

}
