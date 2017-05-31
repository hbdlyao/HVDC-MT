///////////////////////////////////////////////////////////
//  CmcFunc.cpp
//  Implementation of the Class CmcFunc
//  Created on:      24-3月-2017 18:24:19
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcDefs.h"

#include "CmcFunc.h"


string CmcFunc::mcTypeToName(int vType)
{
	switch (vType)
	{
	case CmcDefs::AcSys:
		return "交流系统";
		break;

	case CmcDefs::ACF:
		return "交流滤波器";
		break;

	case CmcDefs::Xf2:
		return "换流变";
		break;

	case CmcDefs::Convertor:
		return "换流器";
		break;

	case CmcDefs::DcLine:
		return "直流极线";
		break;

	case CmcDefs::Ground:
		return "接地极";
		break;

	case CmcDefs::GroundLine:
		return "接地极线";
		break;

	case CmcDefs::MetalLine:
		return "金属回线";
		break;

	default:
		return "HvdcDevice";
		break;

	}//switch

}

