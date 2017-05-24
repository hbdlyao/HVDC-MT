///////////////////////////////////////////////////////////
//  CHvdcMvcs.cpp
//  Implementation of the Class CHvdcMvcs
//  Created on:      24-3ÔÂ-2017 20:58:52
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcMvcs.h"
#include "CmcParams.h"
#include "CmcVars.h"

#include "CmcRwOrderMvc.h"


CmcRwMvc * CmcMvcs::pmcRwMvc = nullptr;

void CmcMvcs::Init()
{			
	pmcRwMvc = new CmcRwMvc();
	pmcRwMvc->InitAdo(CmcParams::dbfFile);
	pmcRwMvc->InitGrid(CmcVars::pmcHvdcGrid);
}


void CmcMvcs::Clear()
{
	//pmcRwMvc->Clear();
}

void CmcMvcs::Release()
{		
	delete pmcRwMvc;
	pmcRwMvc = nullptr;
	//
}

void CmcMvcs::OnLoad(string vdbf)
{
	pmcRwMvc->OnLoad(vdbf);
}

void CmcMvcs::OnSave(string vdbf)
{
	pmcRwMvc->OnSave(vdbf);
}

void CmcMvcs::OnLoadOrder(string vdbf)
{
	CmcRwOrderMvc* vRwMvc = new CmcRwOrderMvc();

	vRwMvc->InitAdo(CmcParams::dbfFile);
	vRwMvc->Init(CmcVars::pmcOrder);
	vRwMvc->OnLoad(CmcParams::dbfFile);

	delete vRwMvc;
}
