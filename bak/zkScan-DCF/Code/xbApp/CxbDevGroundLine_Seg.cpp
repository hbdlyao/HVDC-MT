///////////////////////////////////////////////////////////
//  CxbDevDcLine.cpp
//  Implementation of the Class CxbDevDcLine
//  Created on:      05-4ÔÂ-2017 17:00:36
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevGroundLine_Seg.h"


CxbDevGroundLine_Seg::~CxbDevGroundLine_Seg()
{
	Release();
}

void CxbDevGroundLine_Seg::Release()
{
	//delete pLineParam;
}

void CxbDevGroundLine_Seg::Clear()
{
	CxbDevTwo::Clear();

	//pLineParam.Clear();

	delete[] xbILine.IBranch1;
	delete[] xbILine.IBranch2;

	delete[] xbILine.Ieq_P;
	delete[] xbILine.Ieq_C;
	delete[] xbILine.Ieq_N;
}


void CxbDevGroundLine_Seg::Init()
{
	SetStaCount(1);
	SetDotCount(4);

	InitData();
}

void CxbDevGroundLine_Seg::doInitData(int vDim)
{
	xbILine.IBranch1 = new double[vDim];
	xbILine.IBranch2 = new double[vDim];

	xbILine.Ieq_P = new double[2];
	xbILine.Ieq_C = new double[2];
	xbILine.Ieq_N = new double[2];

}

void CxbDevGroundLine_Seg::Prepare_hRLC()
{
	double vStart = FreqRef();
	double vStep = FreqRef();
	double vDim = hMax();

	Prepare_hRLC(vStart, vStep, vDim);

}

void CxbDevGroundLine_Seg::Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim)
{
	FreqDim = vFreDim;

	Clear();
	doInitData(FreqDim);

	//
	pLineParam.Clear();
	pLineParam.Init_ImScanY(vFreStart, vFreStep, vFreDim);
}

/**
* ·µ»ØYÕó
*/
CMatrix CxbDevGroundLine_Seg::GetYMatrix(int hOrder)
{
	//??
	/*		 0		  1		  1		  2
	0	Ys11	Ys12	Ym11	Ym12
	1	Ys12	Ys11	Ym12	Ym11
	2	Ym11	Ym12	Ys11	Ys12
	3	Ym12	Ym11	Ys12	Ys11
	*/

	//CMatrix vY(4);
	//CComplex vC;

	//vC = CComplex(GetYs11re(hOrder), GetYs11im(hOrder));
	//vY._mat[0][0] = vC;
	//vY._mat[1][1] = vC;
	//vY._mat[2][2] = vC;
	//vY._mat[3][3] = vC;

	//vC = CComplex(GetYs12re(hOrder), GetYs12im(hOrder));
	//vY._mat[0][1] = vC;
	//vY._mat[1][0] = vC;
	//vY._mat[2][3] = vC;
	//vY._mat[3][2] = vC;

	//vC = CComplex(GetYm11re(hOrder), GetYm11im(hOrder));
	//vY._mat[0][2] = vC;
	//vY._mat[1][3] = vC;
	//vY._mat[2][0] = vC;
	//vY._mat[3][1] = vC;

	//vC = CComplex(GetYm12re(hOrder), GetYm12im(hOrder));
	//vY._mat[0][3] = vC;
	//vY._mat[1][2] = vC;
	//vY._mat[2][1] = vC;
	//vY._mat[3][0] = vC;

	//
	return pLineParam.get_AllLine_Y(hOrder - 1);

}

double CxbDevGroundLine_Seg::GetYs11re(int vhOrder)
{
	return 0;
	//return pLineParam[vhOrder - 1].Ys11re;

}

double CxbDevGroundLine_Seg::GetYs12re(int vhOrder)
{
	return 0;
	//return pLineParam[vhOrder - 1].Ys12re;

}


double CxbDevGroundLine_Seg::GetYs11im(int vhOrder)
{
	return 0;
	//return pLineParam[vhOrder - 1].Ys11im;

}

double CxbDevGroundLine_Seg::GetYs12im(int vhOrder)
{
	return 0;
	//return pLineParam[vhOrder - 1].Ys12im;
}

double CxbDevGroundLine_Seg::GetYm11re(int vhOrder)
{
	return 0;
	//return pLineParam[vhOrder - 1].Ym11re;
}

double CxbDevGroundLine_Seg::GetYm12re(int vhOrder)
{
	return 0;
	//return pLineParam[vhOrder - 1].Ym12re;
}


double CxbDevGroundLine_Seg::GetYm11im(int vhOrder)
{
	return 0;
	//return pLineParam[vhOrder - 1].Ym11im;
}

double CxbDevGroundLine_Seg::GetYm12im(int vhOrder)
{
	return 0;
	//return pLineParam[vhOrder - 1].Ym12im;
}


void CxbDevGroundLine_Seg::SetYs11re(int vhOrder, double vY)
{

	//pLineParam[vhOrder - 1].Ys11re = vY;
}

void CxbDevGroundLine_Seg::SetYs12re(int vhOrder, double vY)
{
	//pLineParam[vhOrder - 1].Ys12re = vY;
}


void CxbDevGroundLine_Seg::SetYs11im(int vhOrder, double vY)
{
	//pLineParam[vhOrder - 1].Ys11im = vY;
}

void CxbDevGroundLine_Seg::SetYs12im(int vhOrder, double vY)
{
	//pLineParam[vhOrder - 1].Ys12im = vY;
}


void CxbDevGroundLine_Seg::SetYm11re(int vhOrder, double vY)
{
	//pLineParam[vhOrder - 1].Ym11re = vY;

}

void CxbDevGroundLine_Seg::SetYm12re(int vhOrder, double vY)
{
	//pLineParam[vhOrder - 1].Ym12re = vY;

}


void CxbDevGroundLine_Seg::SetYm11im(int vhOrder, double vY)
{
	//pLineParam[vhOrder - 1].Ym11im = vY;

}

void CxbDevGroundLine_Seg::SetYm12im(int vhOrder, double vY)
{
	//pLineParam[vhOrder - 1].Ym12im = vY;

}


string CxbDevGroundLine_Seg::BusName(int vIndex)
{

	string vBus;

	switch (vIndex)
	{
	case 0:
	case 1:
		vBus = GetStationName(0) + "---" + GetNodeName(vIndex);
		break;
	case 2:
	case 3:
		vBus = GetStationName(0) + "---" + GetNodeName(vIndex);
		break;

	default:
		break;
	}

	if (GetNodeName(vIndex) == "-1")
		vBus = "-1";

	return vBus;

}