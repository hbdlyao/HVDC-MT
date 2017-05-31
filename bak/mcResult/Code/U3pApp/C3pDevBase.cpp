///////////////////////////////////////////////////////////
//  C3pDevBase.cpp
//  Implementation of the Class C3pDevBase
//  Created on:      18-5月-2017 7:44:19
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CHvdcDefs.h"

#include "C3pDevBase.h"
#include "C3pParams.h"

void C3pDevBase::Init()
{
	SetStaCount(1);
	SetDotCount(0);

	InitData();
}

void C3pDevBase::InitData()
{
}

void C3pDevBase::Sort3p(ValveMap & vValMap)
{

}

/**
 * 正极或负极
 */
int C3pDevBase::GetPosOrNeg()
{
	return PosOrNeg;
}

/**
 * 正极或负极
 */
void C3pDevBase::SetPosOrNeg(int newVal)
{

	PosOrNeg = newVal;
}

void C3pDevBase::SetValveName(string vNewVal)
{
	ValveName = vNewVal;
}

string C3pDevBase::GetValveName()
{
	return ValveName;
}


int C3pDevBase::hMax()
{
	return C3pParams::hMax;
}


double C3pDevBase::FreqRef()
{
	return C3pParams::Frequence;
}


double C3pDevBase::Omega()
{
	return 2 * PI*FreqRef();
}

void C3pDevBase::Prepare3pData(int vDType, int vLoopTimes)
{
}

void C3pDevBase::DataSelected(string  vCalName, string vCaseID, double vPdPersent)
{

}