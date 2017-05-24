///////////////////////////////////////////////////////////
//  CxbDevBranch.cpp
//  Implementation of the Class CxbDevBranch
//  Created on:      19-4月-2017 23:19:31
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevBranch.h"

CxbDevBranch::~CxbDevBranch()
{
	Release();
}

void CxbDevBranch::Release()
{
	delete[] Yg;
	delete[] Yb;
}

void CxbDevBranch::Clear()
{
	CxbDevTwo::Clear();

	delete[] Yg;
	delete[] Yb;

}

void CxbDevBranch::InitData()
{
	CxbDevTwo::InitData();

	Yg = new double[hMax()];
	Yb = new double[hMax()];
}

void CxbDevBranch::Prepare_hRLC()
{
	//
	CComplex vY;
	double vZg, vZb;

	//
	for (int vh = 1; vh <= hMax(); vh++)
	{
		vZg = GetZr();
		vZb = vh * Omega() * GetZ_L();

		if (GetZ_C() != 0)
			vZb = vZb + -1.0 / (vh * Omega() * GetZ_C());

		//
		vY = CComplex(vZg, vZb).inverse();

		///////////////////////
		Yg[vh - 1] = vY.real();
		Yb[vh - 1] = vY.image();

	}
	//
	xbUI.IBranchRms = new double[hMax()];
	xbUI.IBranchVec = new double[hMax()];
	xbUI.UBranchRms = new double[hMax()];
	xbUI.UBranchVec = new double[hMax()];
}



void CxbDevBranch::Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim)

{

	CComplex vY;
	double vZg, vZb;

	Clear();

	Yg = new double[vFreDim];
	Yb = new double[vFreDim];
	//
	for (int vh = 1; vh <= vFreDim; vh++)
	{
		double vOmega = PI * 2 * (vFreStart + vh * vFreStep);

		vZg = GetZr();
		vZb = vOmega * GetZ_L();

		if (GetZ_C() != 0)
			vZb = vZb + -1.0 / (vOmega * GetZ_C());

		//
		vY = CComplex(vZg, vZb).inverse();

		///////////////////////
		Yg[vh - 1] = vY.real();
		Yb[vh - 1] = vY.image();

	}

}


double CxbDevBranch::GetZr()
{

	return structBranch.Zr;
}


double CxbDevBranch::GetZ_C()
{
	return structBranch.Z_C*1E-6;
}


double CxbDevBranch::GetZ_L()
{

	return structBranch.Z_L;
}


double CxbDevBranch::GetZx_C(){

	return structBranch.Zx_C;
}


double CxbDevBranch::GetZx_L()
{

	return structBranch.Zx_L;
}


void CxbDevBranch::SetZr(double vValue)
{

	structBranch.Zr = vValue;
}


void CxbDevBranch::SetZ_C(double vValue){

	structBranch.Z_C = vValue;
}


void CxbDevBranch::SetZ_L(double vValue)
{

	structBranch.Z_L = vValue;
}


void CxbDevBranch::SetZx_C(double vValue)
{

	structBranch.Zx_C = vValue;
}


void CxbDevBranch::SetZx_L(double vValue)
{

	structBranch.Zx_L = vValue;
}


/**
 * 马骏鹏
 */
double CxbDevBranch::GetYg(int vhOrder){

	//谐波次数从1开始
	return Yg[vhOrder - 1];
}


double CxbDevBranch::GetYb(int vhOrder){

	//谐波次数从1开始
	return Yb[vhOrder - 1];
}


