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

void C3pRwMvc::doLoad()
{
	CMyRwDev * vRw;

	//
	vRw = doNewRw(C3pDefs::AcSys);
	vRw->OnLoad();

	//
	vRw = doNewRw(C3pDefs::Convertor);
	vRw->OnLoad();

	//
	vRw = doNewRw(C3pDefs::Xf2);
	vRw->OnLoad();

	vRw = doNewRw(C3pDefs::StaData);
	vRw->OnLoad();

	//
	delete vRw;

}


void C3pRwMvc::doSave() 
{
	CMyRwDev * vRw;

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
	//vRw = doNewRw(C3pDefs::StaData);
	//vRw->OnSave();

	//
	delete vRw;
}


CMyRwDev * C3pRwMvc::doNewRw(int vtblType) 
{

	CMyRwDev* vRw;

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

	case C3pDefs::StaData:
		//换流器  
		vRw = new C3pRwStaData();

		vRw->InitAdo(RwAdo);
		vRw->InitTable("U3pStation");
		vRw->InitType(C3pDefs::StaData, C3pDefs::StaData);
		vRw->InitGrid(pGrid);

		break;

	default:
		vRw = nullptr;
		break;

	}

	return vRw;
}