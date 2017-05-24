///////////////////////////////////////////////////////////
//  CHvdcMvcs.cpp
//  Implementation of the Class CHvdcMvcs
//  Created on:      24-3ÔÂ-2017 20:58:52
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcMvcs.h"
#include "CHvdcParams.h"
#include "CHvdcVars.h"

void CHvdcMvcs::Init()
{	
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
	CmcMvcs::Release();

	CxbMvcs::Release();
	//
	C3pMvcs::Release();

}


void CHvdcMvcs::OnLoad()
{
	OnLoad_PRJ(CMyParams::PRJFile);

	//CmcMvcs::OnLoad(CmcParams::dbfFile);

	//CxbMvcs::OnLoad(CxbParams::dbfFile);

	//
	//C3pMvcs::OnLoad(C3pParams::dbfFile);

}

void CHvdcMvcs::OnSave()
{
	OnSave_PRJ(CMyParams::PRJFile);

	//CmcMvcs::OnSave(CmcParams::dbfFile);

	//CxbMvcs::OnSave(CxbParams::dbfFile);
	//
	//C3pMvcs::OnSave(C3pParams::dbfFile);

}


void CHvdcMvcs::OnLoad_PRJ(string vdbf)
{
	CHvdcPRJ_RwMvc * vRwMvc;

	vRwMvc = new CHvdcPRJ_RwMvc();
	vRwMvc->InitAdo(CMyParams::PRJFile);

	vRwMvc->OnLoad(CHvdcParams::PRJFile);

	delete vRwMvc;
}

void CHvdcMvcs::OnSave_PRJ(string vdbf)
{
	CHvdcPRJ_RwMvc * vRwMvc;

	vRwMvc = new CHvdcPRJ_RwMvc();
	vRwMvc->InitAdo(CMyParams::PRJFile);

	vRwMvc->OnSave(CHvdcParams::PRJFile);

	delete vRwMvc;
}


