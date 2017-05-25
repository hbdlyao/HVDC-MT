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


void C3pMvcs::Init()
{
}


void C3pMvcs::Clear()
{

	//pRwMvc->Clear();
}


void C3pMvcs::Release()
{
}


void C3pMvcs::OnLoad(string vdbf)
{
	C3pRwMvc* vRwMvc;

	vRwMvc = new C3pRwMvc();
	vRwMvc->InitAdo(vdbf);
	vRwMvc->InitGrid(C3pVars::pGrid);

	vRwMvc->OnLoad(vdbf);

	delete vRwMvc;

}


void C3pMvcs::OnSave(string vdbf)
{
	C3pRwMvc* vRwMvc;

	vRwMvc = new C3pRwMvc();
	vRwMvc->InitAdo(vdbf);
	vRwMvc->InitGrid(C3pVars::pGrid);

	vRwMvc->OnSave(vdbf);

	delete vRwMvc;
}


void C3pMvcs::OnLoadOrder(string vdbf)
{
	C3pVars::p3pOrder->CalName = "²âÊÔ1495529378";

	C3pRwOrderMvc* vRwMvc;
	
	vRwMvc= new C3pRwOrderMvc();
	vRwMvc->InitAdo(vdbf);
	vRwMvc->Init(C3pVars::p3pOrder);
	vRwMvc->OnLoad(vdbf);

	delete vRwMvc;

}