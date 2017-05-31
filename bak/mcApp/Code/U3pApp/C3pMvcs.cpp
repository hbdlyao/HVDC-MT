///////////////////////////////////////////////////////////
//  C3pMvcs.cpp
//  Implementation of the Class C3pMvcs
//  Created on:      18-5ÔÂ-2017 8:36:00
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pMvcs.h"
#include "C3pParams.h"
#include "C3pVars.h"

#include "C3pRwOrderMvc.h"


C3pRwMvc* C3pMvcs::pRwMvc;


void C3pMvcs::Init(){

	pRwMvc = new C3pRwMvc();
	pRwMvc->InitAdo(C3pParams::dbfFile);
	pRwMvc->InitGrid(C3pVars::pGrid);
}


void C3pMvcs::Clear()
{

	//pRwMvc->Clear();
}


void C3pMvcs::Release()
{

	delete pRwMvc;
	pRwMvc = nullptr;
	//
}


void C3pMvcs::OnLoad(string vdbf)
{
	pRwMvc->OnLoad(vdbf);
}


void C3pMvcs::OnSave(string vdbf)
{
	pRwMvc->OnSave(vdbf);
}


void C3pMvcs::OnLoadOrder(string vdbf)
{
	C3pRwOrderMvc* vRwMvc = new C3pRwOrderMvc();

	vRwMvc->InitAdo(C3pParams::dbfFile);
	vRwMvc->Init(C3pVars::p3pOrder);
	vRwMvc->OnLoad(C3pParams::dbfFile);

	delete vRwMvc;

}