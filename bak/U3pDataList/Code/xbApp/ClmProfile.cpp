///////////////////////////////////////////////////////////
//  ClmProfile.cpp
//  Implementation of the Class ClmProfile
//  Created on:      05-4ÔÂ-2017 18:22:21
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcDefs.h"

#include "ClmProfile.h"


void ClmProfile::InitOrder(ClmOrder * vOrder)
{
	pOrder = vOrder;
}

double ClmProfile::Omega()
{
	double vX;

	vX = xbFreq * hOrder * 2 * PI;

	return vX;

}

