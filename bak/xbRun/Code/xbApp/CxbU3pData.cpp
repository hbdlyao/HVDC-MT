///////////////////////////////////////////////////////////
//  CxbU3pData.cpp
//  Implementation of the Class CxbU3pData
//  Created on:      25-5ÔÂ-2017 15:03:36
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbU3pData.h"
#include "CxbParams.h"

CxbU3pData::~CxbU3pData()
{
	Release();
}

void CxbU3pData::Release()
{
	if (pU3pData.Urms != nullptr)
		delete[] pU3pData.Urms;

	if (pU3pData.Angle != nullptr)
		delete[] pU3pData.Angle;

	if (pU3pData.Ire != nullptr)
		delete[] pU3pData.Ire;

	if (pU3pData.Iim != nullptr)
		delete[] pU3pData.Iim;

	if (pU3pData.Yb != nullptr)
		delete[] pU3pData.Yb;
}

void CxbU3pData::Clear()
{
	ClearData();
}

void CxbU3pData::Init()
{
	InitData();
}

void CxbU3pData::ClearData()
{
	if (pU3pData.Urms != nullptr)
		delete[] pU3pData.Urms;

	if (pU3pData.Angle != nullptr)
		delete[] pU3pData.Angle;

	if (pU3pData.Ire != nullptr)
		delete[] pU3pData.Ire;

	if (pU3pData.Iim != nullptr)
		delete[] pU3pData.Iim;

	if (pU3pData.Yb != nullptr)
		delete[] pU3pData.Yb;
}



void CxbU3pData::InitData()
{
	FreqDim = hMax();
	//
	doInitData(FreqDim);

}

void CxbU3pData::doInitData(int vDim)
{
	pU3pData.Urms = new double[vDim];
	pU3pData.Angle = new double[vDim];

	//pU3pData.Ure = new double[vDim];
	//pU3pData.Uim = new double[vDim];

	pU3pData.Ire = new double[vDim];
	pU3pData.Iim = new double[vDim];

	pU3pData.Yb = new double[vDim];

}

int CxbU3pData::hMax()
{
	return CxbParams::hMax;
}

bool CxbU3pData::IsLeaf()
{
	return true;
}


void CxbU3pData::Add(CxbU3pData* vItem)
{

}


void CxbU3pData::Remove(CxbU3pData* vItem)
{

	//
}


