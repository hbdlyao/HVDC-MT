///////////////////////////////////////////////////////////
//  CxbDev3pVSrc.cpp
//  Implementation of the Class CxbDev3pVSrc
//  Created on:      05-4ÔÂ-2017 18:01:58
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDev3pVSrc.h"

CxbDev3pVSrc::~CxbDev3pVSrc()
{
	delete[] zkYb;
}

void CxbDev3pVSrc::ClearData()
{
	delete[] zkYb;
}

void CxbDev3pVSrc::doInitData(int vDim)
{
	//DataList.DataName = "U3pRoot--"+ShowName();

	zkYb = new double[vDim];

}

void CxbDev3pVSrc::Prepare_hRLC()
{
}

void CxbDev3pVSrc::Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim)
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

void CxbDev3pVSrc::zkPrepare_hYb(double vFreStart, double vFreStep, int vFreDim)
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

void CxbDev3pVSrc::DataSelected(string  vCalName, string vCaseID, double vPdPercent)
{
	StrVector vNames;

	vNames.push_back(vCalName);
	vNames.push_back(vCaseID);
	vNames.push_back(to_string(vPdPercent));

	//
	CxbU3pData * vData;
	
	vData = DataList.DataSelected(0, vNames);
	pU3pData= &(vData->pData);

}

void CxbDev3pVSrc::NewU3pData(string vCalName,string vCaseID,double vPdPercent)
{
	StrVector vNames;

	vNames.push_back(vCalName);
	vNames.push_back(vCaseID);
	vNames.push_back(to_string(vPdPercent));

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

double CxbDev3pVSrc::hUre(int vhOrder) 
{
	return  Get_hUrms(vhOrder) * cos(Get_hAngle(vhOrder));
}

double CxbDev3pVSrc::hUim(int vhOrder) 
{
	return  Get_hUrms(vhOrder) * sin(Get_hAngle(vhOrder));
}


double CxbDev3pVSrc::hIre(int vhOrder)
{//
	//pU3pData->Ire[vhOrder - 1] = hUim(vhOrder)*Get_hYb(vhOrder);
	return hUim(vhOrder)*Get_hYb(vhOrder);
}

double CxbDev3pVSrc::hIim(int vhOrder)
{
	//pU3pData->Iim[vhOrder - 1] = -hUre(vhOrder)*Get_hYb(vhOrder);
	return -hUre(vhOrder)*Get_hYb(vhOrder);
}

double CxbDev3pVSrc::hYg(int vhOrder)
{
	return 0;
}

double CxbDev3pVSrc::hYb(int vhOrder)
{
	return pU3pData->Yb[vhOrder-1];
}

double CxbDev3pVSrc::Get_hUrms(int vhOrder)
{
	return pU3pData->Urms[vhOrder-1];
}

void CxbDev3pVSrc::Set_hUrms(int vhOrder, double vX)
{
	pU3pData->Urms[vhOrder-1] = vX;
}

double CxbDev3pVSrc::Get_hAngle(int vhOrder)
{
	return pU3pData->Angle[vhOrder-1];
}

void CxbDev3pVSrc::Set_hAngle(int vhOrder, double vX)
{
	pU3pData->Angle[vhOrder-1] = vX;
}

double CxbDev3pVSrc::Get_hYb(int vhOrder)
{
	return pU3pData->Yb[vhOrder-1];
}

void CxbDev3pVSrc::Set_hYb(int vhOrder, double vX)
{
	pU3pData->Yb[vhOrder-1] = vX;
}

void CxbDev3pVSrc::Set_hCalName(string vName)
{
	pU3pData->CalName = vName;
}

void CxbDev3pVSrc::Set_hCaseID(string vCaseID)
{
	pU3pData->CaseID = vCaseID;
}

void CxbDev3pVSrc::Set_hPdPer(double vX)
{
	pU3pData->PdPercent = vX;
}



