///////////////////////////////////////////////////////////
//  CxbOrder.cpp
//  Implementation of the Class CxbOrder
//  Created on:      05-4ÔÂ-2017 18:22:10
//  Original author: Administrator
///////////////////////////////////////////////////////////


#include "CHvdcDefs.h"

#include "CxbOrder.h"
#include "CxbDefs.h"
#include "CxbParams.h"

void CxbOrder::Init()
{
	CHvdcOrder::Init();
}

int CxbOrder::StaCount()
{
	return CxbParams::xbStationCount;
}
