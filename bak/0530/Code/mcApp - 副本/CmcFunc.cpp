///////////////////////////////////////////////////////////
//  CmcFunc.cpp
//  Implementation of the Class CmcFunc
//  Created on:      24-3��-2017 18:24:19
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcDefs.h"

#include "CmcFunc.h"


string CmcFunc::mcTypeToName(int vType)
{
	switch (vType)
	{
	case CmcDefs::AcSys:
		return "����ϵͳ";
		break;

	case CmcDefs::ACF:
		return "�����˲���";
		break;

	case CmcDefs::Xf2:
		return "������";
		break;

	case CmcDefs::Convertor:
		return "������";
		break;

	case CmcDefs::DcLine:
		return "ֱ������";
		break;

	case CmcDefs::Ground:
		return "�ӵؼ�";
		break;

	case CmcDefs::GroundLine:
		return "�ӵؼ���";
		break;

	case CmcDefs::MetalLine:
		return "��������";
		break;

	default:
		return "HvdcDevice";
		break;

	}//switch

}

