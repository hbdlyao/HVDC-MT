///////////////////////////////////////////////////////////
//  CmcOrder.cpp
//  Implementation of the Class CmcOrder
//  Created on:      03-5ÔÂ-2017 19:32:53
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcOrder.h"

#include "CHvdcDefs.h"
#include "CmcParams.h"


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

int CmcOrder::StaCount()
{
	return CmcParams::mcStationCount;
}

