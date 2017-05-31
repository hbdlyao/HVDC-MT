///////////////////////////////////////////////////////////
//  CHvdcMvcs.cpp
//  Implementation of the Class CHvdcMvcs
//  Created on:      24-3ÔÂ-2017 20:58:52
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcMvcs.h"
#include "CHvdcParams.h"
#include "CHvdcVars.h"

CHvdcPRJ_RwMvc *  CHvdcMvcs::PRJ_RwMvc = nullptr;

void CHvdcMvcs::Init()
{	
	PRJ_RwMvc = new CHvdcPRJ_RwMvc();
	PRJ_RwMvc->InitAdo(CMyParams::PRJFile);

	//
	CmcMvcs::Init();
	//
	CxbMvcs::Init();

	C3pMvcs::Init();

}


void CHvdcMvcs::Clear()
{
	//pProjectRw->Clear();

	CmcMvcs::Clear();

	CxbMvcs::Clear();

	C3pMvcs::Clear();

}

void CHvdcMvcs::Release()
{
	
	delete PRJ_RwMvc;
	PRJ_RwMvc = nullptr;
	
	CmcMvcs::Release();

	CxbMvcs::Release();
	//
	C3pMvcs::Release();

}

void CHvdcMvcs::OnLoad()
{

	PRJ_RwMvc->OnLoad(CHvdcParams::PRJFile);

	//CmcMvcs::OnLoad(CmcParams::dbfFile);

	//CxbMvcs::OnLoad(CxbParams::dbfFile);

	//
	//C3pMvcs::OnLoad(C3pParams::dbfFile);

}

void CHvdcMvcs::OnSave()
{
	PRJ_RwMvc->OnSave(CHvdcParams::PRJFile);

	//CmcMvcs::OnSave(CmcParams::dbfFile);

	//CxbMvcs::OnSave(CxbParams::dbfFile);

	//
	//C3pMvcs::OnSave(C3pParams::dbfFile);

}
