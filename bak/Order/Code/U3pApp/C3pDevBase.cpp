///////////////////////////////////////////////////////////
//  C3pDevBase.cpp
//  Implementation of the Class C3pDevBase
//  Created on:      18-5��-2017 7:44:19
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

/**
 * �����򸺼�
 */
int C3pDevBase::GetPosOrNeg()
{
	return PosOrNeg;
}

/**
 * �����򸺼�
 */
void C3pDevBase::SetPosOrNeg(int newVal)
{

	PosOrNeg = newVal;
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

