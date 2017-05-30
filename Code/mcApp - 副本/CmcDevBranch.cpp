///////////////////////////////////////////////////////////
//  CmcDevBranch.cpp
//  Implementation of the Class CmcDevBranch
//  Created on:      13-4ÔÂ-2017 13:15:44
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevBranch.h"
//#include "CComplex.h"

void CmcDevBranch::Init()
{
	SetStaCount(1);
	SetDotCount(2);
	
	//
	structBranch.Zr = 0;
	structBranch.Zx_C = 0;
	structBranch.Zx_L = 0;
	structBranch.Z_C = 0;
	structBranch.Z_L = 0;

}

double CmcDevBranch::GetY()
{
	double vY = 0;

	if (GetZrN() != 0)
		vY = (1 / GetZrN());
	else
		vY = 0;

	return vY;
}


double CmcDevBranch::GetZ_C(){

	return structBranch.Z_C;
}


double CmcDevBranch::GetZ_L(){

	return structBranch.Z_L;
}


double CmcDevBranch::GetZx_C(){

	return structBranch.Zx_C;
}


double CmcDevBranch::GetZx_L(){

	return structBranch.Zx_L;
}


void CmcDevBranch::SetZ_C(double vValue){

	structBranch.Z_C = vValue;
}


void CmcDevBranch::SetZ_L(double vValue){

	structBranch.Z_L = vValue;
}


void CmcDevBranch::SetZx_C(double vValue){

	structBranch.Zx_C = vValue;
}


void CmcDevBranch::SetZx_L(double vValue){

	structBranch.Zx_L = vValue;
}


double CmcDevBranch::GetZr() {

	return structBranch.Zr;
}


void CmcDevBranch::SetZr(double vValue) {

	structBranch.Zr = vValue;
}


double CmcDevBranch::GetZrN(){

	return structBranch.Zr;
}


void CmcDevBranch::SetZrN(double vValue){

	structBranch.Zr= vValue;
}


