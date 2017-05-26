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
	double vLac, vLs, vLf;

	C3pDevAcSys * vDev;

	vDev = dynamic_cast<C3pDevAcSys *>(pDevice);

	int vIndex = Index3p;

	vLs = vDev->GetLs();

	//vLf = vDev->GetLf();

	//p3pProfile->pData[vIndex].Lac = vLac;
}
