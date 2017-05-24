///////////////////////////////////////////////////////////
//  CxbVars.cpp
//  Implementation of the Class CxbVars
//  Created on:      23-3ÔÂ-2017 9:55:51
//  Original author: Administrator
///////////////////////////////////////////////////////////


#include "CxbVars.h"
#include "CxbParams.h"


/////////////////////////////////

//
CxbHvdcGrid * CxbVars::pxbHvdcGrid =nullptr;

///////////////////////////////////////////

CxbVars::~CxbVars()
{
	Release();
}

void CxbVars::Release()
{
	delete pxbHvdcGrid;
	pxbHvdcGrid = nullptr;
	
}


void CxbVars::Clear()
{
	pxbHvdcGrid->Clear();
}


void CxbVars::Init()
{
	doInitGrid();	
}

void CxbVars::doInitGrid() 
{
	if (pxbHvdcGrid != nullptr)
		pxbHvdcGrid->Clear();
	else
	{
		pxbHvdcGrid = new CxbHvdcGrid();
		//
		pxbHvdcGrid->Init();
	}//else
	
}

