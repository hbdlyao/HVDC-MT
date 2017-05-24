///////////////////////////////////////////////////////////
//  C3pVars.cpp
//  Implementation of the Class C3pVars
//  Created on:      18-5ÔÂ-2017 8:36:16
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pVars.h"

C3pDevGrid* C3pVars::pGrid = nullptr;
C3pOrder * C3pVars::p3pOrder = nullptr;

C3pVars::~C3pVars()
{
	Release();
}


void C3pVars::Release() 
{
	delete p3pOrder;
	p3pOrder = nullptr;

	delete pGrid;
	pGrid = nullptr;
}

void C3pVars::Init()
{
	doInitGrid();

	//
	p3pOrder = new C3pOrder();
	p3pOrder->Init();
}


void C3pVars::Clear()
{

	pGrid->Clear();
}


void C3pVars::doInitGrid()
{

	if (pGrid != nullptr)
		pGrid->Clear();
	else
	{
		pGrid = new C3pDevGrid();
		//
		pGrid->Init();
	}//else
}