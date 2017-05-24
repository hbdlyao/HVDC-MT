///////////////////////////////////////////////////////////
//  CmcOrder.cpp
//  Implementation of the Class CmcOrder
//  Created on:      03-5月-2017 19:32:53
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcOrder.h"

#include "CHvdcDefs.h"
#include "CmcParams.h"


int CmcOrder::CaseCount()
{

	int vCountGroundType = 0;
	int vCountUd = 0;
	int vCountRd = 0;
	int vCountUac = 0;
	
	for each (char flag in Flag_Ground)
		if (flag == '1')
			vCountGroundType++;
	
	for each (char flag in Flag_Ud)
		if (flag == '1')
			vCountUd++;
	
	if (IsUdCustom)
		vCountUd = 1;
	
	for each (char flag in Flag_Rd)
		if (flag == '1')
			vCountRd++;
	
	for each (char flag in Flag_Uac)
		if (flag == '1')
			vCountUac++;
	
	if (IsUacSwap)
		vCountUac = (int)pow(vCountUac, StaCount());
	
	//
	int vN = vCountGroundType*vCountUd*vCountRd*vCountUac;
	
	return vN;
}


int CmcOrder::StaCount()
{

	return CmcParams::mcStationCount;
}


string CmcOrder::CreateCaseID()
{

	//char buff[1];
	
	string CaseID = "";
	
	//阀组数:
	switch (nValNum)
	{
	case 1:
		CaseID.append("S");
		break;
	case 2:
		CaseID.append("D");
		break;
	}
	
	//接地:单极大地，单极金属，双极，双极并联
	switch (GroundType)
	{
	case Ground20:
		CaseID.append("B");
		break;
	case Ground11:
		CaseID.append("M");
		break;
	case Ground10:
		CaseID.append("G");
		break;
	case Ground21:
		CaseID.append("P");
		break;
	default:
		break;
	}
	
	//Ud:全压,80%,70%
	switch (UdLevel)
	{
	case Ud_Full:
		CaseID.append("F");
		break;
	case Ud_Per80:
		CaseID.append("R");
		break;
	case Ud_Per70:
		CaseID.append("S");
		break;
	
	case Ud_Custom:
		CaseID.append("C");
		break;
	
	default:
		break;
	}
	
	//Rd:高阻、低阻
	switch (RdLevel)
	{
	case Rd_High:
		CaseID.append("H");
		break;
	case Rd_Low:
		CaseID.append("L");
		break;
	default:
		break;
	}
	
	//交流Uac
	for (int i = 0; i < StaCount(); i++)
		CaseID = CaseID + ((char)(UacLevel[i] + 1 + '0'));
	
	//
	return CaseID;
}

void CmcOrder::Init()
{
	CHvdcOrder::Init();

	IsUdCustom = false;
	UdCustomMap.clear();
	IsUdCustomPre = false;
	UdCustom = 0;
	Is6Pulse = false;
}

void CmcOrder::InitNormal()
{
	CHvdcOrder::InitNormal();

	IsUdCustom = false;
	UdCustomMap.clear();
	IsUdCustomPre = false;
	UdCustom = 0;
	Is6Pulse = false;
}