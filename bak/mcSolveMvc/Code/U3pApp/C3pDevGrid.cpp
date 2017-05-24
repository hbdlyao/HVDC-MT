///////////////////////////////////////////////////////////
//  C3pDevGrid.cpp
//  Implementation of the Class C3pDevGrid
//  Created on:      18-5ÔÂ-2017 7:12:42
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pDefs.h"

#include "C3pDevGrid.h"

#include "C3pDevTBL.h"

#include "C3pFunc.h"

#include "gbHead_3pDevice.h"


void C3pDevGrid::Init(){

	int i;
	CDevTBL * vTBL;
	
	for (i = C3pDefs::AcSys; i <= C3pDefs::Convertor; i++)
	{
		vTBL = NewDevTBL(i);
	}
}


string C3pDevGrid::TypeToName(int vType){

	return C3pFunc::TypeToName(vType);
}


CDevTBL * C3pDevGrid::doNewDevTBL(int vType)
{
	C3pDevTBL * vTBL;

	vTBL = new C3pDevTBL();

	return vTBL;
}