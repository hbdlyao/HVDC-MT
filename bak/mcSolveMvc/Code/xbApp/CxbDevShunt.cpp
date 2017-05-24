///////////////////////////////////////////////////////////
//  CxbDevShunt.cpp
//  Implementation of the Class CxbDevShunt
//  Created on:      12-4月-2017 12:00:41
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevShunt.h"
#include "CComplex.h"


CxbDevShunt::~CxbDevShunt()
{
	Release();
}

void CxbDevShunt::Release()
{
	delete[] Yg;
	delete[] Yb;
}

void CxbDevShunt::Clear()
{
	CxbDevOne::Clear();

	delete[] Yg;
	delete[] Yb;

}

void CxbDevShunt::InitData()
{
	CxbDevOne::InitData();

	Yg = new double[hMax()];
	Yb = new double[hMax()];
}


void CxbDevShunt::Prepare_hRLC()
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



void CxbDevShunt::Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim)

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


double CxbDevShunt::GetZr() {

	return structBranch.Zr;
}


double CxbDevShunt::GetZ_C() {

	return structBranch.Z_C*1E-6;
}


double CxbDevShunt::GetZ_L() {

	return structBranch.Z_L;
}


double CxbDevShunt::GetZx_C() {

	return structBranch.Zx_C;
}


double CxbDevShunt::GetZx_L() {

	return structBranch.Zx_L;
}


void CxbDevShunt::SetZr(double vValue) {

	structBranch.Zr = vValue;
}


void CxbDevShunt::SetZ_C(double vValue) {

	structBranch.Z_C = vValue;
}


void CxbDevShunt::SetZ_L(double vValue) {

	structBranch.Z_L = vValue;
}


void CxbDevShunt::SetZx_C(double vValue) {

	structBranch.Zx_C = vValue;
}


void CxbDevShunt::SetZx_L(double vValue) 
{
	structBranch.Zx_L = vValue;
}


/**
 * 马骏鹏
 */
double CxbDevShunt::GetYg(int vhOrder)
{
	//谐波次数从1开始
	return Yg[vhOrder - 1];
}


double CxbDevShunt::GetYb(int vhOrder)
{
	//谐波次数从1开始
	return Yb[vhOrder - 1];
}



