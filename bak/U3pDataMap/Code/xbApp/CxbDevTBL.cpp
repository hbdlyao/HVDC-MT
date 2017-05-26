///////////////////////////////////////////////////////////
//  CxbDevTBL.cpp
//  Implementation of the Class CxbDevTBL
//  Created on:      22-5ÔÂ-2017 14:08:15
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevTBL.h"

#include "CxbFunc.h"
#include "CxbDefs.h"
#include "gbHead_xbDevice.h"

string CxbDevTBL::TypeToName(int vDevType){

	string vName;
	vName = CxbFunc::xbTypeToName(vDevType);
	
	return vName;
}

CDevBase * CxbDevTBL::doNewDevice(int vDevType) {

	return CxbDevTBL::xbNewDevice(vDevType);
}


CDevBase * CxbDevTBL::xbNewDevice(int vDevType){

	CDevBase * vDev = nullptr;
	
	switch (vDevType)
	{
	case CxbDefs::Usrc3p:
		vDev = new CxbDevU3p();
		break;
	
	case CxbDefs::PbDKQ:
		vDev = new CxbDevPbDkq();
		break;
	
	case CxbDefs::DCF:
		vDev = new CxbDevDCF();
		break;
	
	case CxbDefs::DCF_RLC:
		vDev = new CxbDevDCF_RLC();
		break;
	
	case CxbDefs::DCLine:
		vDev = new CxbDevDcLine();
		break;
	
	case CxbDefs::GroundLine:
		vDev = new CxbDevGroundLine();
		break;
	
	case CxbDefs::DcLine_Seg:
		vDev = new CxbDevDcLine_Seg();
		break;
	
	case CxbDefs::GroundLine_Seg:
		vDev = new CxbDevGroundLine_Seg();
		break;
	
	case CxbDefs::Ground:
		vDev = new CxbDevGround();
		break;
	
	case CxbDefs::MetalLine:
		//vDev = new CxbDevMetalLine();
		break;
	
	case CxbDefs::XfC:
		vDev = new CxbDevXf_C();
		break;
	
	case CxbDefs::CoupleC:
		vDev = new CxbDevCouple_C();
		break;
	
	case CxbDefs::PulseC:
		vDev = new CxbDevPulse_C();
		break;
	
	case CxbDefs::Shunt:
		vDev = new CxbDevShunt();
		break;
	
	case CxbDefs::Branch:
		vDev = new CxbDevBranch();
		break;
	
	case CxbDefs::Trap:
		vDev = new CxbDevTrap();
		break;
	
	case CxbDefs::Monitor:
		vDev = new CxbDevMonitor();
		break;
	
	default:
		break;
	
	}//switch
	
	vDev->Init();
	
	return vDev;
}


void CxbDevTBL::Prepare_hRLC(){

	for each (CxbDevBase * vDev in  pChildren)
	{
		vDev->Prepare_hRLC();
	}
}


void CxbDevTBL::Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim){

	for each (CxbDevBase * vDev in  pChildren)
	{
		vDev->Prepare_hRLC(vFreStart, vFreStep, vFreDim);
	}
}