///////////////////////////////////////////////////////////
//  C3pFunc.cpp
//  Implementation of the Class C3pFunc
//  Created on:      24-3月-2017 18:24:19
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "C3pDefs.h"

#include "C3pFunc.h"


string C3pFunc::TypeToName(int vType)
{
	switch (vType)
	{
	case C3pDefs::AcSys:
		return "交流系统";
		break;

	case C3pDefs::ACF:
		return "交流滤波器";
		break;

	case C3pDefs::Xf2:
		return "换流变";
		break;

	case C3pDefs::Convertor:
		return "换流器";
		break;


	default:
		return "C3pDevBase";
		break;

	}//switch

}

