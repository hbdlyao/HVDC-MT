///////////////////////////////////////////////////////////
//  CHvdcMvcs.cpp
//  Implementation of the Class CHvdcMvcs
//  Created on:      24-3��-2017 20:58:52
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcMvcs.h"
#include "CmcParams.h"
#include "CmcVars.h"

#include "CmcRwOrderMvc.h"

void CmcMvcs::Init()
{			
}


void CmcMvcs::Clear()
{
}

void CmcMvcs::Release()
{		
}

void CmcMvcs::OnLoad(string vdbf)
{
	CmcRwMvc* vRwMvc;

	vRwMvc = new CmcRwMvc();
	vRwMvc->InitAdo(vdbf);
	vRwMvc->InitGrid(CmcVars::pmcHvdcGrid);

	vRwMvc->OnLoad(vdbf);

	delete vRwMvc;
}

void CmcMvcs::OnSave(string vdbf)
{
	CmcRwMvc* vRwMvc;

	vRwMvc = new CmcRwMvc();
	vRwMvc->InitAdo(vdbf);
	vRwMvc->InitGrid(CmcVars::pmcHvdcGrid);

	vRwMvc->OnSave(vdbf);

	delete vRwMvc;
}

void CmcMvcs::OnLoadOrder(string vdbf)
{
	CmcRwOrderMvc* vRwMvc = new CmcRwOrderMvc();

	vRwMvc->InitAdo(vdbf);
	vRwMvc->Init(CmcVars::pmcOrder);
	vRwMvc->OnLoad(vdbf);

	delete vRwMvc;
}
