///////////////////////////////////////////////////////////
//  CmcDevShunt.cpp
//  Implementation of the Class CmcDevShunt
//  Created on:      13-4ÔÂ-2017 13:15:34
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevShunt.h"
//#include "CComplex.h"


void CmcDevShunt::Init() 
{
	SetStaCount(1);
	SetDotCount(1);

	structBranch.Zr = 0;
	structBranch.Zx_C = 0;
	structBranch.Zx_L = 0;
	structBranch.Z_C = 0;
	structBranch.Z_L = 0;
}

double CmcDevShunt::GetY()
{
	double vY = 0;

	if (GetZrN() != 0)
		vY = (1 / GetZrN());
	else
		vY = 0;

	return vY;
}


double CmcDevShunt::GetZ_C()
{

	return structBranch.Z_C;
}


double CmcDevShunt::GetZ_L()
{

	return structBranch.Z_L;
}


double CmcDevShunt::GetZx_C()
{

	return structBranch.Zx_C;
}


double CmcDevShunt::GetZx_L()
{

	return structBranch.Zx_L;
}


void CmcDevShunt::SetZ_C(double vValue)
{

	structBranch.Z_C = vValue;
}


void CmcDevShunt::SetZ_L(double vValue)
{

	structBranch.Z_L = vValue;
}


void CmcDevShunt::SetZx_C(double vValue)
{

	structBranch.Zx_C = vValue;
}


void CmcDevShunt::SetZx_L(double vValue)
{

	structBranch.Zx_L = vValue;
}


double CmcDevShunt::GetZr()
{

	return structBranch.Zr;
}


void CmcDevShunt::SetZr(double vValue)
{

	structBranch.Zr = vValue;
}

double CmcDevShunt::GetZrN()
{

	return structBranch.Zr;
}


void CmcDevShunt::SetZrN(double vValue)
{

	structBranch.Zr= vValue;
}