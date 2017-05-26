///////////////////////////////////////////////////////////
//  C3pDevStaData.cpp
//  Implementation of the Class C3pDevStaData
//  Created on:      18-5��-2017 11:51:00
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pDevSModeData.h"

C3pDevSModeData::~C3pDevSModeData()
{
	delete[] hData;
	hData = nullptr;
}

void C3pDevSModeData::Init()
{
	SetStaCount(1);
	SetDotCount(0);

	//
	nStaDim = 0;
	nCaseDim = 0;
	nPdPreDim = 0;
	
	hData = nullptr;

}

void C3pDevSModeData::Init(int vStaDim, int vCaseDim, int vPdPreDim)
{
	nStaDim = vStaDim;
	nCaseDim = vCaseDim;
	nPdPreDim = vPdPreDim;

	int vN = nStaDim * nCaseDim * nPdPreDim;
	hData = new struct_U3pStaData[vN];

}

void C3pDevSModeData::Prepare3pData(int vDType, int vLoopTimes)
{
	DType = vDType;
}
