///////////////////////////////////////////////////////////
//  C3pDevhData.cpp
//  Implementation of the Class C3pDevhData
//  Created on:      18-5ÔÂ-2017 11:51:00
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pDevhData.h"

C3pDevhData::~C3pDevhData()
{
	delete[] hData;
	hData = nullptr;
}

void C3pDevhData::Init()
{
	SetStaCount(1);
	SetDotCount(0);

	//
	nStaDim = 0;
	nCaseDim = 0;
	nPdPreDim = 0;
	
	hData = nullptr;

}

void C3pDevhData::Init(int vStaDim, int vCaseDim, int vPdPreDim)
{
	nStaDim = vStaDim;
	nCaseDim = vCaseDim;
	nPdPreDim = vPdPreDim;

	int vN = nStaDim*nCaseDim*nPdPreDim;
	hData = new struct_3p_hData[vN];

}
