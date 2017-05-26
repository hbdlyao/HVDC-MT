///////////////////////////////////////////////////////////
//  CHvdcVars.cpp
//  Implementation of the Class CHvdcVars
//  Created on:      23-3ÔÂ-2017 9:55:51
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcVars.h"

/////////////////////////////////

///////////////////////////////////////////

CHvdcVars::~CHvdcVars()
{
	Release();
}

void CHvdcVars::Release()
{
	CmcVars::Release();

	CxbVars::Release();

	C3pVars::Release();

}


void CHvdcVars::Clear()
{
	CmcVars::Clear();

	CxbVars::Clear();

	C3pVars::Clear();
}


void CHvdcVars::Init()
{
	CmcVars::Init();

	CxbVars::Init();

	C3pVars::Init();
		
}

