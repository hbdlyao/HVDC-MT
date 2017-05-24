///////////////////////////////////////////////////////////
//  CxbCalculate.cpp
//  Implementation of the Class CxbCalculate
//  Created on:      05-4ÔÂ-2017 18:31:46
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbCalculate.h"
#include "CxbDevBase.h"

void CxbCalculate::Init(CDevBase* vDev)
{
	pDevice = vDev;
}

void CxbCalculate::Init(CPowerProfile* vProfile)
{
	pProfile = vProfile;
	pxbProfile = dynamic_cast<CxbProfile *> (pProfile);

	//zkScan
	pzkProfile = dynamic_cast<CzkProfile *> (pProfile);

}

void CxbCalculate::Add(CxbCalculate * vItem)
{

}


void CxbCalculate::Remove(CxbCalculate * vItem)
{

}


void CxbCalculate::Prepare_zk()
{
//
}

void CxbCalculate::UpdateY()
{
	
}


void CxbCalculate::UpdateI()
{
	//
}


void CxbCalculate::Update_zkY()
{
	UpdateY();
}


void CxbCalculate::Update_zkI()
{
	UpdateI();
}

void CxbCalculate::SolveI()
{
	//
}

void CxbCalculate::SolveIeq()
{

}

