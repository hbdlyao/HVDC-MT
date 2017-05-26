///////////////////////////////////////////////////////////
//  CxbDevU3p.cpp
//  Implementation of the Class CxbDevU3p
//  Created on:      05-4ÔÂ-2017 18:01:58
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevU3p.h"

CxbDevU3p::~CxbDevU3p()
{
	delete[] zkYb;
}

void CxbDevU3p::ClearData()
{
	delete[] zkYb;
}

void CxbDevU3p::doInitData(int vDim)
{
	//DataList.DataName = "U3pRoot--"+ShowName();

	zkYb = new double[vDim];

}

void CxbDevU3p::Prepare_hRLC()
{
}

void CxbDevU3p::Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim)
{
	/*
	double vL = pU3pData->Yb[0] / Omega();

	delete[] pU3pData->Yb;

	pU3pData->Yb = new double[vFreDim];


	for (int i = 1; i <= vFreDim; i++)
	{
		pU3pData->Yb[i - 1] = vL * 2 * PI * (vFreStart + vFreStep * i);
	}
	*/
}

void CxbDevU3p::zkPrepare_hYb(double vFreStart, double vFreStep, int vFreDim)
{
	delete[] zkYb;
	zkYb = new double[vFreDim];

	//
	double vL, vW;
	vL = pU3pData->Yb[0] / Omega();
	for (int i = 1; i <= vFreDim; i++)
	{
		vW= (vFreStart + vFreStep * i);
		zkYb[i - 1] = 2 * PI * vW * vL;
	}

}

void CxbDevU3p::DataSelected(string  vCalName, string vCaseID, double vPdPercent)
{
	char vChar[5];
	sprintf_s(vChar, 5, "%-3.0f", vPdPercent);

	StrVector vNames;

	vNames.push_back(vCalName);
	vNames.push_back(vCaseID);
	vNames.push_back(vChar);

	//
	CxbU3pData * vData;
	
	vData = DataList.DataSelected(0, vNames);
	pU3pData= &(vData->pData);

}

void CxbDevU3p::NewU3pData(string vCalName,string vCaseID,double vPdPercent)
{
	char vChar[5];
	sprintf_s(vChar, 5, "%-3.0f", vPdPercent);

	StrVector vNames;

	vNames.push_back(vCalName);
	vNames.push_back(vCaseID);
	vNames.push_back(vChar);

	//
	CxbU3pData * vData;

	vData = DataList.NewU3pData(0, vNames);

	vData->DeviceName = GetDeviceName();

	vData->Set_hCalName(vCalName);
	vData->Set_hCaseID(vCaseID);
	vData->Set_hPdPer(vPdPercent);

	//
	DataVect.push_back(vData);

}

double CxbDevU3p::hUre(int vhOrder) 
{
	return  Get_hUrms(vhOrder) * cos(Get_hAngle(vhOrder));
}

double CxbDevU3p::hUim(int vhOrder) 
{
	return  Get_hUrms(vhOrder) * sin(Get_hAngle(vhOrder));
}


double CxbDevU3p::hIre(int vhOrder)
{//
	//pU3pData->Ire[vhOrder - 1] = hUim(vhOrder)*Get_hYb(vhOrder);
	return hUim(vhOrder)*Get_hYb(vhOrder);
}

double CxbDevU3p::hIim(int vhOrder)
{
	//pU3pData->Iim[vhOrder - 1] = -hUre(vhOrder)*Get_hYb(vhOrder);
	return -hUre(vhOrder)*Get_hYb(vhOrder);
}

double CxbDevU3p::hYg(int vhOrder)
{
	return 0;
}

double CxbDevU3p::hYb(int vhOrder)
{
	return pU3pData->Yb[vhOrder-1];
}

double CxbDevU3p::Get_hUrms(int vhOrder)
{
	return pU3pData->Urms[vhOrder-1];
}

void CxbDevU3p::Set_hUrms(int vhOrder, double vX)
{
	pU3pData->Urms[vhOrder-1] = vX;
}

double CxbDevU3p::Get_hAngle(int vhOrder)
{
	return pU3pData->Angle[vhOrder-1];
}

void CxbDevU3p::Set_hAngle(int vhOrder, double vX)
{
	pU3pData->Angle[vhOrder-1] = vX;
}

double CxbDevU3p::Get_hYb(int vhOrder)
{
	return pU3pData->Yb[vhOrder-1];
}

void CxbDevU3p::Set_hYb(int vhOrder, double vX)
{
	pU3pData->Yb[vhOrder-1] = vX;
}

void CxbDevU3p::Set_hCalName(string vName)
{
	pU3pData->CalName = vName;
}

void CxbDevU3p::Set_hCaseID(string vCaseID)
{
	pU3pData->CaseID = vCaseID;
}

void CxbDevU3p::Set_hPdPer(double vX)
{
	pU3pData->PdPercent = vX;
}



