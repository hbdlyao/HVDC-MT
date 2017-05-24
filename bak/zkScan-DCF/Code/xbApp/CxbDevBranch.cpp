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

	delete[] xbUI.IBranchRms;
	delete[] xbUI.IBranchVec;

	delete[] xbUI.UBranchRms;
	delete[] xbUI.UBranchVec;

}

void CxbDevBranch::Clear()
{
	CxbDevTwo::Clear();

	delete[] Yg;
	delete[] Yb;

	delete[] xbUI.IBranchRms;
	delete[] xbUI.IBranchVec;

	delete[] xbUI.UBranchRms;
	delete[] xbUI.UBranchVec;

}

void CxbDevBranch::doInitData(int vDim)
{
	Yg = new double[vDim];
	Yb = new double[vDim];

	//
	xbUI.IBranchRms = new double[vDim];
	xbUI.IBranchVec = new double[vDim];
	xbUI.UBranchRms = new double[vDim];
	xbUI.UBranchVec = new double[vDim];
}

void CxbDevBranch::Prepare_hRLC()
{
	double vStart = FreqRef();
	double vStep = FreqRef();
	double FreqDim = hMax();

	Prepare_hRLC(vStart, vStep, FreqDim);

}


void CxbDevBranch::Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim)
{

	CComplex vY;
	double vZg, vZb;

	FreqDim = vFreDim;

	Clear();
	doInitData(vFreDim);

	//
	for (int vh = 0; vh < vFreDim; vh++)
	{
		double vOmega = PI * 2 * (vFreStart + vh * vFreStep);

		vZg = GetZr();
		vZb = vOmega * GetZ_L();

		if (GetZ_C() != 0)
			vZb = vZb + -1.0 / (vOmega * GetZ_C());

		//
		vY = CComplex(vZg, vZb).inverse();

		///////////////////////
		Yg[vh] = vY.real();
		Yb[vh] = vY.image();

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


