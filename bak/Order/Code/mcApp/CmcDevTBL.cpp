///////////////////////////////////////////////////////////
//  CmcDevTBL.cpp
//  Implementation of the Class CmcDevTBL
//  Created on:      21-5月-2017 0:51:42
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevTBL.h"
#include "CmcFunc.h"
#include "CmcDefs.h"
#include "gbHead_mcDevice.h"


string CmcDevTBL::TypeToName(int vDevType)
{

	string vName;
	vName = CmcFunc::mcTypeToName(vDevType);
	
	return vName;
}


CDevBase * CmcDevTBL::doNewDevice(int vDevType)
{
	return mcNewDevice(vDevType);
}

CDevBase * CmcDevTBL::mcNewDevice(int vDevType)
{

	CDevBase * vDev=nullptr; 
	
	switch (vDevType)
	{
	case CmcDefs::AcSys:
		//交流系统  
		vDev = new  CmcDevAcSys();
		break;
	
	case CmcDefs::ACF:
		//交流滤波器
		vDev = new  CmcDevAcFilter();
		break;
	
	case CmcDefs::Xf2:
		//双绕组变压器  
		vDev = new  CmcDevXf2();
		break;
	
	
	case CmcDefs::Convertor:
		//换流器  
		vDev = new  CmcDevConvertor();
		break;
	
	case CmcDefs::DcLine:
		//直流极线  
		vDev = new  CmcDevDcLine();
		break;
	
	
	case CmcDefs::GroundLine:
		//接地极线  
		vDev = new  CmcDevGroundLine();
		break;
	
	case CmcDefs::MetalLine:
		//金属回线  
		vDev = new  CmcDevMetalLine();
		break;
	
	case CmcDefs::Ground:
		//接地极  
		vDev = new  CmcDevGround();
		break;
	
	default:
		break;
	
	}//switch
	
	vDev->Init();
	
	return vDev;
}