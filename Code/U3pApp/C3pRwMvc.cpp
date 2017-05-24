///////////////////////////////////////////////////////////
//  C3pRwMvc.cpp
//  Implementation of the Class C3pRwMvc
//  Created on:      18-5月-2017 8:45:12
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pRwMvc.h"
#include "C3pDefs.h"
#include "gbHead_3pRw.h"

void C3pRwMvc::InitGrid(C3pDevGrid* vHvdc)
{
	pGrid = vHvdc;
}


void C3pRwMvc::InitAdo(string vDbf)
{
	dbfName = vDbf;

	RwAdo = new CRwAdo_Access();
	RwAdo->InitDbf(dbfName, "", "", "false");
}


void C3pRwMvc::doLoad()
{
	CRwDev * vRw;

	//
	vRw = doNewRw(C3pDefs::AcSys);
	vRw->OnLoad();

	//
	vRw = doNewRw(C3pDefs::Convertor);
	vRw->OnLoad();

	//
	vRw = doNewRw(C3pDefs::Xf2);
	vRw->OnLoad();

	//
	delete vRw;

}


void C3pRwMvc::doSave() 
{
	CRwDev * vRw;

	//
	vRw = doNewRw(C3pDefs::AcSys);
	vRw->OnSave();

	//
	vRw = doNewRw(C3pDefs::Convertor);
	vRw->OnSave();

	//
	vRw = doNewRw(C3pDefs::Xf2);
	vRw->OnSave();

	//
	delete vRw;
}


CRwDev * C3pRwMvc::doNewRw(int vtblType) {

	CRwDev* vRw;

	switch (vtblType)
	{
	case C3pDefs::AcSys:
		//交流系统  
		vRw = new C3pRwAcSys();

		vRw->InitAdo(RwAdo);
		vRw->InitTable("U3pAcSys");
		vRw->InitType(C3pDefs::AcSys, C3pDefs::AcSys);
		vRw->InitGrid(pGrid);

		break;

	case C3pDefs::Xf2:
		//双绕组变压器  
		vRw = new C3pRwXf2();

		vRw->InitAdo(RwAdo);
		vRw->InitTable("U3pTransformer");
		vRw->InitType(C3pDefs::Xf2, C3pDefs::Xf2);
		vRw->InitGrid(pGrid);

		break;

	case C3pDefs::Convertor:
		//换流器  
		vRw = new C3pRwConvertor();

		vRw->InitAdo(RwAdo);
		vRw->InitTable("U3pConvertor");
		vRw->InitType(C3pDefs::Convertor, C3pDefs::Convertor);
		vRw->InitGrid(pGrid);

		break;

	default:
		vRw = nullptr;
		break;

	}

	return vRw;
}