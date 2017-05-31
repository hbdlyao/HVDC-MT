///////////////////////////////////////////////////////////
//  CmcVars.cpp
//  Implementation of the Class CmcVars
//  Created on:      23-3月-2017 9:55:51
//  Original author: Administrator
///////////////////////////////////////////////////////////


#include "CmcVars.h"
#include "CmcParams.h"


/////////////////////////////////

CmcHvdcGrid * CmcVars::pmcHvdcGrid =nullptr;
CmcOrder * CmcVars::pmcOrder = nullptr;
CmcResult* CmcVars::pmcResult = nullptr;

///////////////////////////////////////////

CmcVars::~CmcVars()
{
	Release();
}

void CmcVars::Release()
{
	delete pmcOrder;
	pmcOrder = nullptr;

	delete pmcResult;
	pmcResult = nullptr;

	//
	delete pmcHvdcGrid;
	pmcHvdcGrid = nullptr;
	
}

void CmcVars::Clear()
{
	pmcHvdcGrid->Clear();

	//pmcOrder->Clear();

	pmcResult->Clear();
}

void CmcVars::Init()
{
	doInitGrid();	

	//
	pmcOrder = new CmcOrder();
	pmcOrder->Init();
	pmcOrder->CalName = "南网多端mc计算";

	//
	pmcResult = new CmcResult();
	pmcResult->Init();
	pmcResult->ResultName = "南网多端mc计算";
	//
}

void CmcVars::doInitGrid() 
{
	if (pmcHvdcGrid != nullptr)
		pmcHvdcGrid->Clear();
	else
	{
		pmcHvdcGrid = new CmcHvdcGrid();
		//
		pmcHvdcGrid->Init();
	}//else
	
}

