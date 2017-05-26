///////////////////////////////////////////////////////////
//  C3pDevTBL.cpp
//  Implementation of the Class C3pDevTBL
//  Created on:      18-5��-2017 7:12:38
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
		//����ϵͳ  
		vDev = new  C3pDevAcSys();
		break;
	
	case C3pDefs::StaData:
	//����·��������
		vDev = new  C3pDevStaData();
		break;
	
	case C3pDefs::Xf2:
		//˫�����ѹ��  
		vDev = new  C3pDevXf2();
		break;
	
	
	case C3pDefs::Convertor:
		//������  
		vDev = new  C3pDevConvertor();
		break;
	
	
	default:
		break;
	
	}//switch
	
	vDev->Init();
	
	return vDev;
}

void C3pDevTBL::Prepare3pData(int vDType, int vLoopTimes)
{
	for each (C3pDevBase * vDev in  pChildren)
	{
		vDev->Prepare3pData(vDType, vLoopTimes);
	}
}
