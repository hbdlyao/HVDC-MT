///////////////////////////////////////////////////////////
//  CxbVars.cpp
//  Implementation of the Class CxbVars
//  Created on:      23-3ÔÂ-2017 9:55:51
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbVars.h"
#include "CxbParams.h"


/////////////////////////////////

CxbHvdcGrid * CxbVars::pxbHvdcGrid = nullptr;

CxbOrder * CxbVars::pxbOrder = nullptr;
CzkOrder * CxbVars::pzkOrder = nullptr;
ClmOrder * CxbVars::plmOrder = nullptr;

///////////////////////////////////////////

CxbVars::~CxbVars()
{
	Release();
}

void CxbVars::Release()
{
	delete pxbOrder;
	pxbOrder = nullptr;

	delete pzkOrder;
	pzkOrder = nullptr;

	delete plmOrder;
	plmOrder = nullptr;

	//
	delete pxbHvdcGrid;
	pxbHvdcGrid = nullptr;

}

void CxbVars::Clear()
{
	pxbHvdcGrid->Clear();

	//pxbOrder->Clear();
}

void CxbVars::Init()
{
	doInitGrid();

	doInitOrder();
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

void CxbVars::doInitOrder()
{
	//
	pxbOrder = new CxbOrder();
	pxbOrder->Init();
	//
	pzkOrder = new CzkOrder();
	pzkOrder->Init();
	//
	plmOrder = new ClmOrder();
	plmOrder->Init();

}
