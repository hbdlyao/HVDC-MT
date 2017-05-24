///////////////////////////////////////////////////////////
//  CmcCalculate.cpp
//  Implementation of the Class CmcCalculate
//  Created on:      02-4ÔÂ-2017 14:40:28
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalculate.h"

void CmcCalculate::Init(CDevBase * vDev)
{
	pDevice = vDev;
}


void CmcCalculate::Init(CPowerProfile * vProfile)
{
	pProfile = vProfile;
	pmcProfile = dynamic_cast<CmcProfile *> (pProfile);
}

void CmcCalculate::InitOrder(CmcOrder * vOrder)
{
	//pmcOrder = vOrder;
}

void CmcCalculate::SaveNormal()
{

}

void CmcCalculate::UpdateY()
{

}


void CmcCalculate::Prepare()
{

}

void CmcCalculate::PrepareNormal()
{

}