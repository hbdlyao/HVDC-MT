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

	delete[] ConstDevYg;
	delete[] ConstDevYb;

	delete[] RandDevYg;
	delete[] RandDevYb;
}

void CxbDevDCF_RLC::Clear()
{
	CxbDevBranch::Clear();

	//
	delete[] NoneDevYg;
	delete[] NoneDevYb;

	delete[] ConstDevYg;
	delete[] ConstDevYb;

	delete[] RandDevYg;
	delete[] RandDevYb;
}

void CxbDevDCF_RLC::InitData()
{
	FreqDim = hMax();
	//
	doInitData(FreqDim);

}

void CxbDevDCF_RLC::doInitData(int vDim)
{
	//
	Yg = new double[vDim];
	Yb = new double[vDim];

	//
	NoneDevYg = new double[vDim];
	NoneDevYb = new double[vDim];

	ConstDevYg = new double[3 * vDim];
	ConstDevYb = new double[3 * vDim];

	RandDevYg = new double[GetSampleNum()*vDim];
	RandDevYb = new double[GetSampleNum()*vDim];

}


void CxbDevDCF_RLC::Prepare_hRLC()
{
	//Yao ?	
	FreqDim = hMax(); 
	
	Clear();
	doInitData(FreqDim);

	//
	doDelta_None();

	//doDelta_Ref_None();
	//doDelta_Ref_Max();
	//doDelta_Ref_Min();
	//doDelta_Rand();

	xbUI.IBranchRms = new double[FreqDim];
	xbUI.IBranchVec = new double[FreqDim];
	xbUI.UBranchRms = new double[FreqDim];
	xbUI.UBranchVec = new double[FreqDim];

}

void CxbDevDCF_RLC::Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim)
{
	//
	FreqDim = vFreDim;

	Clear();
	doInitData(FreqDim);

	//
	doDelta_None(vFreStart, vFreStep, FreqDim);

}

void CxbDevDCF_RLC::doDelta_None()
{
	double vStart = FreqRef();
	double vStep = FreqRef();
	
	FreqDim = hMax();
	doDelta_None(vStart, vStep, FreqDim);

}

void CxbDevDCF_RLC::doDelta_None(double vFreStart, double vFreStep, int vFreDim)
{
	ddC = 0;
	ddL = 0;
	ddR = 0;
	ddf = 0;

	FreqDim = vFreDim;

	doDelta(vFreStart, vFreStep, vFreDim,Yg,Yb);

	//
	for (int vhOrder = 0; vhOrder < vFreDim; vhOrder++)
	{
		NoneDevYg[vhOrder] = Yg[vhOrder];
		NoneDevYb[vhOrder] = Yb[vhOrder];
	}

}

void CxbDevDCF_RLC::doDelta_Ref_None()
{
	ddC = 0;
	ddL = 0;
	ddR = 0;
	ddf = 0;

	doDelta(Yg, Yb);

	//
	for (int vhOrder = 1; vhOrder <= FreqDim; vhOrder++)
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

	doDelta(Yg, Yb);

	int vK = FreqDim;
	for (int vhOrder = 1; vhOrder <= FreqDim; vhOrder++)
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

	doDelta(Yg, Yb);

	//
	int vK = 2 * FreqDim;
	for (int vhOrder = 1; vhOrder <= FreqDim; vhOrder++)
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

		doDelta(Yg, Yb);

		vK = i*FreqDim;
		for (int vhOrder = 1; vhOrder <= FreqDim; vhOrder++)
		{
			RandDevYg[vK + vhOrder - 1] = Yg[vhOrder - 1];
			RandDevYg[vK + vhOrder - 1] = Yb[vhOrder - 1];
		}//hOrder

	}// for i

}


void CxbDevDCF_RLC::doDelta(double* vYg, double * vYb)
{
	double vStart = FreqRef();
	double vStep = FreqRef();
	double vDim = hMax();

	doDelta(vStart, vStep, vDim,vYg,vYb);

}

void CxbDevDCF_RLC::doDelta(double vFreStart, double vFreStep, int vFreDim, double* vYg, double * vYb)
{
	CComplex vY;
	double vZg, vZb;

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
		vYg[vh] = vY.real();
		vYb[vh] = vY.image();

	}
}

void CxbDevDCF_RLC::selectNoneDevY()
{
	//Yg = NoneDevYg;
	//Yb = NoneDevYb;

	for (int i = 0; i < FreqDim; i++)
	{
		Yg[i] = NoneDevYg[i];
		Yb[i] = NoneDevYb[i];
	}
}

void CxbDevDCF_RLC::selectConsDevY(int vCount)
{
	//Yg = ConstDevYg + vCount * hMax();
	//Yb = ConstDevYb + vCount * hMax();

	for (int i = 0; i < FreqDim; i++)
	{
		Yg[i] = ConstDevYg[i + vCount * FreqDim];
		Yb[i] = ConstDevYb[i + vCount * FreqDim];
	}

}

void CxbDevDCF_RLC::selectRandDevY(int vCount)
{
	//Yg = RandDevYg + vCount * hMax();
	//Yb = RandDevYb + vCount * hMax();

	for (int i = 0; i < FreqDim; i++)
	{
		Yg[i] = RandDevYg[i + vCount * FreqDim];
		Yb[i] = RandDevYb[i + vCount * FreqDim];
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