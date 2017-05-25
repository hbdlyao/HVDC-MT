///////////////////////////////////////////////////////////
//  CmcRwMvc.cpp
//  Implementation of the Class CmcRwMvc
//  Created on:      18-4月-2017 21:32:02
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDefs.h"
#include "CmcRwMvc.h"
#include "gbHead_mcRw.h"


void CmcRwMvc::InitGrid(CmcHvdcGrid* vHvdc)
{
	pGrid = vHvdc;
}

CMyRwDev* CmcRwMvc::doNewRw(int vtblType)
{
	CMyRwDev* vRw;

	switch (vtblType)
	{
	case CmcDefs::AcSys:
		//交流系统  
		vRw = new CmcRwAcSys();

		vRw->InitAdo(RwAdo);
		vRw->InitTable("mcAcSystem");
		vRw->InitType(CmcDefs::AcSys, CmcDefs::AcSys);
		vRw->InitGrid(pGrid);

		break;

	case CmcDefs::ACF:
		//交流滤波器
		vRw = new CmcRwAcfilter();

		vRw->InitAdo(RwAdo);
		vRw->InitTable("mcAcFilter");
		vRw->InitType(CmcDefs::ACF, CmcDefs::ACF);
		vRw->InitGrid(pGrid);

		break;

	case CmcDefs::Xf2:
		//双绕组变压器  
		vRw = new CmcRwXf2();

		vRw->InitAdo(RwAdo);
		vRw->InitTable("mcTransformer");
		vRw->InitType(CmcDefs::Xf2, CmcDefs::Xf2);
		vRw->InitGrid(pGrid);

		break;

	case CmcDefs::Convertor:
		//换流器  
		vRw = new CmcRwConvertor();

		vRw->InitAdo(RwAdo);
		vRw->InitTable("mcConvertor");
		vRw->InitType(CmcDefs::Convertor, CmcDefs::Convertor);
		vRw->InitGrid(pGrid);

		break;

	case CmcDefs::DcLine:
		//直流极线  
		vRw = new CmcRwDcLine();

		vRw->InitAdo(RwAdo);
		vRw->InitTable("mcDcLine");
		vRw->InitType(CmcDefs::DcLine, CmcDefs::DcLine);
		vRw->InitGrid(pGrid);

		break;

	case CmcDefs::GroundLine:
		//接地极线  
		vRw = new CmcRwGroundLine();

		vRw->InitAdo(RwAdo);
		vRw->InitTable("mcGroundLine");
		vRw->InitType(CmcDefs::GroundLine, CmcDefs::GroundLine);
		vRw->InitGrid(pGrid);

		break;

	case CmcDefs::MetalLine:
		//金属回线  
		vRw = new CmcRwMetalLine();

		vRw->InitAdo(RwAdo);
		vRw->InitTable("mcMetalLine");
		vRw->InitType(CmcDefs::MetalLine, CmcDefs::MetalLine);
		vRw->InitGrid(pGrid);

		break;

	case CmcDefs::Ground:
		//接地极  
		vRw = new CmcRwGround();

		vRw->InitAdo(RwAdo);
		vRw->InitTable("mcGround");
		vRw->InitType(CmcDefs::Ground, CmcDefs::Ground);
		vRw->InitGrid(pGrid);

		break;

	default:
		vRw = nullptr;
		break;

	}

	return vRw;

}


void CmcRwMvc::doLoad()
{
	CMyRwDev * vRw;
	int i1, i2;

	i1 = CmcDefs::AcSys;
	i2 = CmcDefs::MetalLine;
	//i2 = CmcDefs::Ground;

	for (int i = i1; i <= i2; i++)
	{
		vRw = doNewRw(i);
		vRw->OnLoad();

		delete vRw;
	}

}


void CmcRwMvc::doSave()
{
	CMyRwDev * vRw;
	int i1, i2;


	i1 = CmcDefs::AcSys;
	i2 = CmcDefs::MetalLine;
	//i2 = CmcDefs::Ground;

	
	for (int i = i1; i <= i2; i++)
	{
		vRw = doNewRw(i);
		vRw->OnSave();

		delete vRw;
	}
	

}
