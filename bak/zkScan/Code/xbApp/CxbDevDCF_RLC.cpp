///////////////////////////////////////////////////////////
//  CxbDevDCF_RLC.cpp
//  Implementation of the Class CxbDevDCF_RLC
//  Created on:      20-4月-2017 21:29:23
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevDCF_RLC.h"
#include "CComplex.h"
#include "CRand.h"


CxbDevDCF_RLC::~CxbDevDCF_RLC()
{
	delete[] NoneDevYg;
	delete[] NoneDevYb;

	//delete[] ConstDevYg;
	//delete[] ConstDevYb;

	//delete[] RandDevYg;
	//delete[] RandDevYb;
}

void CxbDevDCF_RLC::Clear()
{
	//CxbDevBranch::Clear();

	//
	delete[] NoneDevYg;
	delete[] NoneDevYb;

	//delete[] ConstDevYg;
	//delete[] ConstDevYb;

	//delete[] RandDevYg;
	//delete[] RandDevYb;
}

void CxbDevDCF_RLC::InitData()
{
	Yg = new double[hMax()];
	Yb = new double[hMax()];

	//
	NoneDevYg = new double[hMax()];
	NoneDevYb = new double[hMax()];

	ConstDevYg = new double[3 * hMax()];
	ConstDevYb = new double[3 * hMax()];

	RandDevYg = new double[GetSampleNum()*hMax()];
	RandDevYb = new double[GetSampleNum()*hMax()];

}

void CxbDevDCF_RLC::Prepare_hRLC()
{
	//
	doDelta_None();

	//doDelta_Ref_None();

	//doDelta_Ref_Max();

	//doDelta_Ref_Min();

	//doDelta_Rand();

	xbUI.IBranchRms = new double[hMax()];
	xbUI.IBranchVec = new double[hMax()];
	xbUI.UBranchRms = new double[hMax()];
	xbUI.UBranchVec = new double[hMax()];

}

void CxbDevDCF_RLC::Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim)
{
	Clear();

	Yg = new double[vFreDim];
	Yb = new double[vFreDim];

	NoneDevYg = new double[vFreDim];
	NoneDevYb = new double[vFreDim];

	doDelta_None(vFreStart, vFreStep, vFreDim);
}

void CxbDevDCF_RLC::doDelta_None()
{
	ddC = 0;
	ddL = 0;
	ddR = 0;
	ddf = 0;

	doDelta();

	//
	for (int vhOrder = 1; vhOrder <= hMax(); vhOrder++)
	{
		NoneDevYg[vhOrder - 1] = Yg[vhOrder - 1];
		NoneDevYb[vhOrder - 1] = Yb[vhOrder - 1];
	}

}

void CxbDevDCF_RLC::doDelta_None(double vFreStart, double vFreStep, int vFreDim)
{
	Clear();

	ddC = 0;
	ddL = 0;
	ddR = 0;
	ddf = 0;

	doDelta(vFreStart, vFreStep, vFreDim);

	//
	for (int vhOrder = 1; vhOrder <= vFreDim; vhOrder++)
	{
		NoneDevYg[vhOrder - 1] = Yg[vhOrder - 1];
		NoneDevYb[vhOrder - 1] = Yb[vhOrder - 1];
	}

}

void CxbDevDCF_RLC::doDelta_Ref_None()
{
	ddC = 0;
	ddL = 0;
	ddR = 0;
	ddf = 0;

	doDelta();

	//
	for (int vhOrder = 1; vhOrder <= hMax(); vhOrder++)
	{
		ConstDevYg[vhOrder - 1] = Yg[vhOrder - 1];
		ConstDevYg[vhOrder - 1] = Yb[vhOrder - 1];
	}

}

void CxbDevDCF_RLC::doDelta_Ref_Max()
{
	ddC = MaxCDelta * GetZ_C();
	ddL = MaxLDelta * GetZ_L();
	ddR = MaxRDelta * GetZr();

	ddf = MaxFreqDelta;

	doDelta();

	int vK = hMax();
	for (int vhOrder = 1; vhOrder <= hMax(); vhOrder++)
	{
		ConstDevYg[vK + vhOrder - 1] = Yg[vhOrder - 1];
		ConstDevYb[vK + vhOrder - 1] = Yb[vhOrder - 1];
	}

}


void CxbDevDCF_RLC::doDelta_Ref_Min()
{
	ddC = MinCDelta * GetZ_C();
	ddL = MinLDelta * GetZ_L();
	ddR = MinRDelta * GetZr();

	ddf = MinFreqDelta;

	doDelta();

	//
	int vK = 2 * hMax();
	for (int vhOrder = 1; vhOrder <= hMax(); vhOrder++)
	{
		ConstDevYg[vK + vhOrder - 1] = Yg[vhOrder - 1];
		ConstDevYb[vK + vhOrder - 1] = Yb[vhOrder - 1];
	}

}

void CxbDevDCF_RLC::doDelta_Rand()
{
	CRand randC(MinCDelta * GetZ_C(), MaxCDelta * GetZ_C(), Real_Dis);
	CRand randL(MinLDelta * GetZ_L(), MaxLDelta * GetZ_L(), Real_Dis);
	CRand randR(MinRDelta * GetZr(), MaxRDelta * GetZr(), Real_Dis);

	CRand randf(MinFreqDelta, MaxFreqDelta, Real_Dis);

	//
	int vK = 0;
	for (int i = 0; i < GetSampleNum(); i++)
	{
		ddC = randC.getVal() * GetZ_C();
		ddL = randL.getVal() * GetZ_L();
		ddR = randR.getVal() * GetZr();
		ddf = randf.getVal();

		doDelta();

		vK = i*hMax();
		for (int vhOrder = 1; vhOrder <= hMax(); vhOrder++)
		{
			RandDevYg[vK + vhOrder - 1] = Yg[vhOrder - 1];
			RandDevYg[vK + vhOrder - 1] = Yb[vhOrder - 1];
		}//hOrder

	}// for i

}


void CxbDevDCF_RLC::doDelta()
{
	CComplex vY;
	double vZg, vZb;

	for (int vhOrder = 1; vhOrder <= hMax(); vhOrder++)
	{
		vZg = GetR();
		vZb = vhOrder* GetOmega0() * GetL();

		if (GetZ_C() != 0)
			vZb = vZb + -1.0 / (vhOrder * GetOmega0() *  GetC());

		//
		vY = CComplex(vZg, vZb).inverse();

		///////////////////////
		Yg[vhOrder - 1] = vY.real();
		Yb[vhOrder - 1] = vY.image();
	}
}

void CxbDevDCF_RLC::doDelta(double vFreStart, double vFreStep, int vFreDim)
{
	CComplex vY;
	double vZg, vZb;

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

double CxbDevDCF_RLC::GetC()
{

	return ddC + GetZ_C();


}

double CxbDevDCF_RLC::GetL()
{
	return ddL + GetZ_L();
}

double CxbDevDCF_RLC::GetR()
{
	return ddR + GetZr();
}

double CxbDevDCF_RLC::GetOmega0()
{
	return (ddf + FreqRef()) * 2 * PI;

}

double CxbDevDCF_RLC::GetYg(int vhOrder)
{
	return CxbDevBranch::GetYg(vhOrder);
}

double CxbDevDCF_RLC::GetYb(int vhOrder)
{
	return CxbDevBranch::GetYb(vhOrder);
}


void CxbDevDCF_RLC::selectNoneDevY()
{
	Yg = NoneDevYg;
	Yb = NoneDevYb;
}

void CxbDevDCF_RLC::selectConsDevY(int vCount)
{
	Yg = ConstDevYg + vCount * hMax();
	Yb = ConstDevYb + vCount * hMax();
}

void CxbDevDCF_RLC::selectRandDevY(int vCount)
{
	Yg = RandDevYg + vCount * hMax();
	Yb = RandDevYb + vCount * hMax();
}


double CxbDevDCF_RLC::GetMaxFreqDelta()
{
	return MaxFreqDelta;
}


void CxbDevDCF_RLC::SetMaxFreqDelta(double newVal) {

	MaxFreqDelta = newVal;
}


double CxbDevDCF_RLC::GetMinFreqDelta() {

	return MinFreqDelta;
}


void CxbDevDCF_RLC::SetMinFreqDelta(double newVal) {

	MinFreqDelta = newVal;
}


int CxbDevDCF_RLC::GetSampleNum() {

	return SampleNum;
}


void CxbDevDCF_RLC::SetSampleNum(int newVal) {

	SampleNum = newVal;
}


/**
* 输入参数，正负偏差
*/
double CxbDevDCF_RLC::GetMaxCDelta() {

	return MaxCDelta;
}


/**
* 输入参数，正负偏差
*/
void CxbDevDCF_RLC::SetMaxCDelta(double newVal) {

	MaxCDelta = newVal;
}


double CxbDevDCF_RLC::GetMaxLDelta() {

	return MaxLDelta;
}


void CxbDevDCF_RLC::SetMaxLDelta(double newVal) {

	MaxLDelta = newVal;
}


double CxbDevDCF_RLC::GetMaxRDelta() {

	return MaxRDelta;
}


void CxbDevDCF_RLC::SetMaxRDelta(double newVal) {

	MaxRDelta = newVal;
}


double CxbDevDCF_RLC::GetMinCDelta() {

	return MinCDelta;
}


void CxbDevDCF_RLC::SetMinCDelta(double newVal) {

	MinCDelta = newVal;
}


double CxbDevDCF_RLC::GetMinLDelta() {

	return MinLDelta;
}


void CxbDevDCF_RLC::SetMinLDelta(double newVal) {

	MinLDelta = newVal;
}


double CxbDevDCF_RLC::GetMinRDelta() {

	return MinRDelta;
}


void CxbDevDCF_RLC::SetMinRDelta(double newVal) {

	MinRDelta = newVal;
}