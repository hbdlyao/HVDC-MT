///////////////////////////////////////////////////////////
//  CxbDevBase.cpp
//  Implementation of the Class CxbDevBase
//  Created on:      12-4ÔÂ-2017 14:00:36
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CHvdcDefs.h"

#include "CxbDevBase.h"
#include "CxbParams.h"


void CxbDevBase::Init()
{
	SetStaCount(1);
	SetDotCount(0);
	//
	InitData();
}

void CxbDevBase::InitData()
{
}

int CxbDevBase::GetPosOrNeg()
{
	return PosOrNeg;
}

void CxbDevBase::SetPosOrNeg(int newVal)
{

	PosOrNeg = newVal;
}


void CxbDevBase::Prepare_hRLC()
{

}

void CxbDevBase::Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim)
{

}

int CxbDevBase::hMax()
{
	return CxbParams::hMax;
}


double CxbDevBase::FreqRef()
{
	return CxbParams::Frequence;
}


double CxbDevBase::Omega()
{
	return 2 * PI*FreqRef();
}


string CxbDevBase::BusName(int vIndex)
{
	string vBus;
	
	vBus = GetStationName() + "---" + GetNodeName(vIndex);
	
	if (GetNodeName(vIndex) == "-1")
		vBus = "-1";
	
	return vBus;
}
