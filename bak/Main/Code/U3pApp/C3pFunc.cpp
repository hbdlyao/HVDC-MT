///////////////////////////////////////////////////////////
//  C3pFunc.cpp
//  Implementation of the Class C3pFunc
//  Created on:      24-3��-2017 18:24:19
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "C3pDefs.h"

#include "C3pFunc.h"


string C3pFunc::TypeToName(int vType)
{
	switch (vType)
	{
	case C3pDefs::AcSys:
		return "����ϵͳ";
		break;

	case C3pDefs::ACF:
		return "�����˲���";
		break;

	case C3pDefs::Xf2:
		return "������";
		break;

	case C3pDefs::Convertor:
		return "������";
		break;


	default:
		return "C3pDevBase";
		break;

	}//switch

}

