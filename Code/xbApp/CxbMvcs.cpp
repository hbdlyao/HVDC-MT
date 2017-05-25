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

void CxbMvcs::Init()
{
}


void CxbMvcs::Clear()
{
}

void CxbMvcs::Release()
{
}

void CxbMvcs::OnLoad(string vdbf)
{
	CxbRwMvc* vRwMvc;

	vRwMvc = new CxbRwMvc();
	vRwMvc->InitAdo(vdbf);
	vRwMvc->InitGrid(CxbVars::pxbHvdcGrid);

	vRwMvc->OnLoad(vdbf);

	delete vRwMvc;
}

void CxbMvcs::OnSave(string vdbf)
{
	CxbRwMvc* vRwMvc;

	vRwMvc = new CxbRwMvc();
	vRwMvc->InitAdo(vdbf);
	vRwMvc->InitGrid(CxbVars::pxbHvdcGrid);

	vRwMvc->OnSave(vdbf);

	delete vRwMvc;
}

void CxbMvcs::xbOnLoadOrder(string vdbf)
{
	CxbRwOrderMvc* vRwMvc = new CxbRwOrderMvc();
	CxbVars::pxbOrder->CalName = "xbU3p";

	vRwMvc->InitAdo(vdbf);
	vRwMvc->Init(CxbVars::pxbOrder);
	vRwMvc->OnLoad(vdbf);

	delete vRwMvc;
}


void CxbMvcs::zkOnLoadOrder(string vdbf)
{
	CzkRwOrderMvc* vRwMvc = new CzkRwOrderMvc();
	CxbVars::pzkOrder->CalName = "xbU3p";

	vRwMvc->InitAdo(vdbf);
	vRwMvc->Init(CxbVars::pzkOrder);
	vRwMvc->OnLoad(vdbf);

	delete vRwMvc;
}
