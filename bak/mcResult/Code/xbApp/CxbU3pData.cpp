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
	if (pData.Urms != nullptr)
		delete[] pData.Urms;

	if (pData.Angle != nullptr)
		delete[] pData.Angle;

	//if (pData.Ire != nullptr)
	//	delete[] pData.Ire;

	//if (pData.Iim != nullptr)
	//	delete[] pData.Iim;

	if (pData.Yb != nullptr)
		delete[] pData.Yb;
	
}

void CxbU3pData::Clear()
{
	//ClearData();
}

void CxbU3pData::Init()
{
	InitData();
}

void CxbU3pData::ClearData()
{
	if (pData.Urms != nullptr)
		delete[] pData.Urms;

	if (pData.Angle != nullptr)
		delete[] pData.Angle;

	//if (pData.Ire != nullptr)
	//	delete[] pData.Ire;

	//if (pData.Iim != nullptr)
	//	delete[] pData.Iim;

	if (pData.Yb != nullptr)
		delete[] pData.Yb;

}


void CxbU3pData::InitData()
{
	FreqDim = hMax();
	//
	doInitData(FreqDim);

}

void CxbU3pData::doInitData(int vDim)
{
	//pData = new struct_xbU3PData[1];

	pData.Urms = new double[vDim];
	pData.Angle = new double[vDim];

	//pData.Ire = new double[vDim];
	//pData.Iim = new double[vDim];

	pData.Yb = new double[vDim];

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


double CxbU3pData::Get_hUrms(int vhOrder){

	return pData.Urms[vhOrder-1];
}


void CxbU3pData::Set_hUrms(int vhOrder, double vX){

	pData.Urms[vhOrder-1] = vX;
}


double CxbU3pData::Get_hAngle(int vhOrder){

	return pData.Angle[vhOrder-1];
}


void CxbU3pData::Set_hAngle(int vhOrder, double vX){

	pData.Angle[vhOrder-1] = vX;
}


double CxbU3pData::Get_hYb(int vhOrder){

	return pData.Yb[vhOrder-1];
}


void CxbU3pData::Set_hYb(int vhOrder, double vX){

	pData.Yb[vhOrder-1] = vX;
}


string CxbU3pData::Get_hCalName()
{
	return pData.CalName;
}

void CxbU3pData::Set_hCalName(string vName){

	pData.CalName = vName;
}


string CxbU3pData::Get_hCaseID()
{
	return pData.CaseID;
}

void CxbU3pData::Set_hCaseID(string vCaseID){

	pData.CaseID = vCaseID;
}


double CxbU3pData::Get_hPdPer()
{
	return pData.PdPercent;
}

void CxbU3pData::Set_hPdPer(double vX)
{
	pData.PdPercent = vX;
}