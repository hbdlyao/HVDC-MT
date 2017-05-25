///////////////////////////////////////////////////////////
//  ClmSolves.cpp
//  Implementation of the Class ClmSolves
//  Created on:      21-4月-2017 20:29:55
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CHvdcDefs.h"

#include "ClmSolves.h"

#include "gbHead_lmCal.h"

void ClmSolves::Init(ClmProfile* vProfile, CxbHvdcGrid * vGrid)
{
	CPowerSolves::Init(vProfile, vGrid);

	plmHvdc = vGrid;

	plmProfile = vProfile;

}


void ClmSolves::InitOrder(ClmOrder * vOrder)
{
	plmOrder = vOrder;
}

void ClmSolves::NewSolves()
{
	doNewItem(CxbDefs::GroundLine);

	doNewItem(CxbDefs::DCLine);

}


void ClmSolves::doNewItem(int vtblType)
{
	CDevTBL * vTBL;

	vTBL = plmHvdc->DeviceTBL(vtblType);

	doNewItem(vTBL);
}


void ClmSolves::doNewItem(CDevTBL * vTBL)
{

	for each (CDevBase * vDev in  vTBL->Children())
	{
		NewCal_Tree_1(vDev);
	}

}

CPowerCalculate * ClmSolves::doNewCal(CDevBase* vDev)
{
	int vType;
	ClmCalculate * vCal = nullptr;

	vType = vDev->GetDeviceType();

	switch (vType)
	{

	//case CxbDefs::DCLine:
	//	vCal = new CxbCalDcLine();
	//	break;

	//case CxbDefs::GroundLine:
	//	vCal = new CxbCalGroundLine();
	//	break;

	case CxbDefs::DcLine_Seg:
		vCal = new ClmCalDcLine_Seg();
		break;

	case CxbDefs::GroundLine_Seg:
		vCal = new ClmCalGroundLine_Seg();
		break;

	default:
		break;

	}//switch

	 //
	vCal->Init(vDev);
	vCal->Init(plmProfile);
	vCal->InitOrder(plmOrder);

	//
	Add(vCal);

	//
	return vCal;
}

void ClmSolves::Run()
{
	//注意：重新定义了ClmCalculate,取代 CxbCalculate
	//现在需要补充 ClmCalculate的 Prepare();
	for each (ClmCalculate * vCal in pChildren)
	{
		//vCal->Prepare();
		
		//plmProfile->Run();
		
	}
}

