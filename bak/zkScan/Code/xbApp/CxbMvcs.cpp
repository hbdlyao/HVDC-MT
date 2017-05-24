///////////////////////////////////////////////////////////
//  CHvdcMvcs.cpp
//  Implementation of the Class CHvdcMvcs
//  Created on:      24-3ÔÂ-2017 20:58:52
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbMvcs.h"
#include "CxbParams.h"
#include "CxbVars.h"

#include "CxbRwOrderMvc.h"
#include "CzkRwOrderMvc.h"


CxbRwMvc * CxbMvcs::pxbRwMvc = nullptr;

void CxbMvcs::Init()
{			
	pxbRwMvc = new CxbRwMvc();
	pxbRwMvc->InitAdo(CxbParams::dbfFile);
	pxbRwMvc->InitGrid(CxbVars::pxbHvdcGrid);
}


void CxbMvcs::Clear()
{
	//pxbRwMvc->Clear();
}

void CxbMvcs::Release()
{		
	delete pxbRwMvc;
	pxbRwMvc = nullptr;
	//
}

void CxbMvcs::OnLoad(string vdbf)
{
	pxbRwMvc->OnLoad(vdbf);
}

void CxbMvcs::OnSave(string vdbf)
{
	pxbRwMvc->OnSave(vdbf);
}


void CxbMvcs::xbOnLoadOrder(string vdbf)
{
	CxbRwOrderMvc* vRwMvc = new CxbRwOrderMvc();

	vRwMvc->InitAdo(CxbParams::dbfFile);
	vRwMvc->Init(CxbVars::pxbOrder);
	vRwMvc->OnLoad(CxbParams::dbfFile);

	delete vRwMvc;
}


void CxbMvcs::zkOnLoadOrder(string vdbf)
{

	CzkRwOrderMvc* vRwMvc = new CzkRwOrderMvc();

	vRwMvc->InitAdo(CxbParams::dbfFile);
	vRwMvc->Init(CxbVars::pzkOrder);
	vRwMvc->OnLoad(CxbParams::dbfFile);

	delete vRwMvc;
}

