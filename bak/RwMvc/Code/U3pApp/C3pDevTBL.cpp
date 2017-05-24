///////////////////////////////////////////////////////////
//  C3pDevTBL.cpp
//  Implementation of the Class C3pDevTBL
//  Created on:      18-5月-2017 7:12:38
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pDevTBL.h"

#include "C3pDefs.h"
#include "C3pFunc.h"

#include "gbHead_3pDevice.h"


string C3pDevTBL::TypeToName(int vDevType) {

	string vName;
	vName = C3pFunc::TypeToName(vDevType);

	return vName;
}

CDevBase * C3pDevTBL::doNewDevice(int vDevType)
{
	return C3pDevTBL::NewDevice(vDevType);
}




CDevBase * C3pDevTBL::NewDevice(int vDevType){

	CDevBase * vDev=nullptr; 
	
	switch (vDevType)
	{
	case C3pDefs::AcSys:
		//交流系统  
		vDev = new  C3pDevAcSys();
		break;
	
	//case C3pDefs::ACF:
	//	//交流滤波器
	//	vDev = new  C3pDevAcFilter();
	//	break;
	
	case C3pDefs::Xf2:
		//双绕组变压器  
		vDev = new  C3pDevXf2();
		break;
	
	
	case C3pDefs::Convertor:
		//换流器  
		vDev = new  C3pDevConvertor();
		break;
	
	
	default:
		break;
	
	}//switch
	
	vDev->Init();
	
	return vDev;
}