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
#include "CmcRwResultMvc.h"

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
	//CmcVars::pmcOrder->CalName = "²âÊÔ1495529378";

	CmcRwOrderMvc* vRwMvc = new CmcRwOrderMvc();

	vRwMvc->InitAdo(vdbf);
	vRwMvc->Init(CmcVars::pmcOrder);
	vRwMvc->OnLoad(vdbf);

	delete vRwMvc;
}

void CmcMvcs::OnLoadResult(string vdbf)
{
	CmcResult* vResult=new CmcResult();	
	vResult->ResultName = "²âÊÔ1495529378";
	
	//
	CmcRwResultMvc* vRwMvc = new CmcRwResultMvc();

	vRwMvc->InitAdo(vdbf);
	vRwMvc->Init(vResult);
	vRwMvc->OnLoad(vdbf);

	delete vRwMvc;
}

void CmcMvcs::OnLoad_PRJ(string vdbf)
{
	CmcPRJ_RwMvc * vRwMvc;

	vRwMvc = new CmcPRJ_RwMvc();
	vRwMvc->InitAdo(CmcParams::PRJFile);

	vRwMvc->OnLoad(CmcParams::PRJFile);

	delete vRwMvc;
}

void CmcMvcs::OnSave_PRJ(string vdbf)
{
	CmcPRJ_RwMvc * vRwMvc;

	vRwMvc = new CmcPRJ_RwMvc();
	vRwMvc->InitAdo(CmcParams::PRJFile);

	vRwMvc->OnSave(CmcParams::PRJFile);

	delete vRwMvc;
}