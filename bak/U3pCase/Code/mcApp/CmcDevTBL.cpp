///////////////////////////////////////////////////////////
//  CmcDevTBL.cpp
//  Implementation of the Class CmcDevTBL
//  Created on:      21-5��-2017 0:51:42
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
		//����ϵͳ  
		vDev = new  CmcDevAcSys();
		break;
	
	case CmcDefs::ACF:
		//�����˲���
		vDev = new  CmcDevAcFilter();
		break;
	
	case CmcDefs::Xf2:
		//˫�����ѹ��  
		vDev = new  CmcDevXf2();
		break;
	
	
	case CmcDefs::Convertor:
		//������  
		vDev = new  CmcDevConvertor();
		break;
	
	case CmcDefs::DcLine:
		//ֱ������  
		vDev = new  CmcDevDcLine();
		break;
	
	
	case CmcDefs::GroundLine:
		//�ӵؼ���  
		vDev = new  CmcDevGroundLine();
		break;
	
	case CmcDefs::MetalLine:
		//��������  
		vDev = new  CmcDevMetalLine();
		break;
	
	case CmcDefs::Ground:
		//�ӵؼ�  
		vDev = new  CmcDevGround();
		break;
	
	default:
		break;
	
	}//switch
	
	vDev->Init();
	
	return vDev;
}