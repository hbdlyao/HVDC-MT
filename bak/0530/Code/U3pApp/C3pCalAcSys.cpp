///////////////////////////////////////////////////////////
//  C3pCalAcSys.cpp
//  Implementation of the Class C3pCalAcSys
//  Created on:      18-5ÔÂ-2017 13:04:12
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pCalAcSys.h"

#include "C3pDevAcSys.h"
void C3pCalAcSys::Prepare()
{

}


void C3pCalAcSys::Update3pData(int vLoop)
{
	double vLac;

	int vhCount;

	C3pDevAcSys * vDev;

	vDev = dynamic_cast<C3pDevAcSys *>(pDevice);

	vLac = vDev->GetLeq();

	vhCount = vDev->GethCount();

	int vStaIndex = StationIndex;
	int vDim = p3pProfile->n6pValor;

	for (int i = 0; i < vDim; i++)
	{
		if (p3pProfile->pU3pData[i].StaIndex == vStaIndex)
		{
			p3pProfile->pU3pData[i].Lac = vLac;

			//½»Á÷±³¾°Ð³²¨
			if (p3pProfile->pU3pData[i].hUv != nullptr)
				delete[] p3pProfile->pU3pData[i].hUv;
			p3pProfile->pU3pData[i].hUv = new struct_AcSysXb[vhCount];
			for (int j = 0; j < vhCount; j++)
			{
				p3pProfile->pU3pData[i].hUv[i].hIndex = vDev->Get_hIndex(i);
				p3pProfile->pU3pData[i].hUv[i].hUrms = vDev->Get_hUrms(i);
				p3pProfile->pU3pData[i].hUv[i].hAngle = vDev->Get_hAngle(i);
			}
		}

	}
}

