///////////////////////////////////////////////////////////
//  CmcDevGroundLine.cpp
//  Implementation of the Class CmcDevGroundLine
//  Created on:      04-4ÔÂ-2017 7:27:19
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevGroundLine.h"

double CmcDevGroundLine::GetY(int RLevel)
{
	double vY = 0;
	double vR = 0;

	switch (RLevel)
	{
	case Rd_Normal:
		vR = GetZrN();
		break;
	case Rd_High:
		vR = GetZrMax();
		break;
	case Rd_Low:
		vR = GetZrMin();
		break;
	default:
		break;
	}

	if (vR != 0)
		vY = (1 / vR);
	else
		vY = 0;

	return vY;

}

double CmcDevGroundLine::GetZrMax() 
{

	return ZrMax;
}

double CmcDevGroundLine::GetZrMin()
{
	return ZrMin;
}

void CmcDevGroundLine::SetZrMax(double newVal)
{
	ZrMax = newVal;
}

void CmcDevGroundLine::SetZrMin(double newVal)
{
	ZrMin = newVal;
}

