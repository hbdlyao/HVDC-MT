///////////////////////////////////////////////////////////
//  CmcVars.cpp
//  Implementation of the Class CmcVars
//  Created on:      23-3ÔÂ-2017 9:55:51
//  Original author: Administrator
///////////////////////////////////////////////////////////


#include "CmcVars.h"
#include "CmcParams.h"


/////////////////////////////////

CmcHvdcGrid * CmcVars::pmcHvdcGrid =nullptr;

///////////////////////////////////////////

CmcVars::~CmcVars()
{
	Release();
}

void CmcVars::Release()
{
	delete pmcHvdcGrid;
	pmcHvdcGrid = nullptr;
	
}

void CmcVars::Clear()
{
	pmcHvdcGrid->Clear();
}

void CmcVars::Init()
{
	doInitGrid();	
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

