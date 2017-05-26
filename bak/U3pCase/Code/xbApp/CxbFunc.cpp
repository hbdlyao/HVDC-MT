///////////////////////////////////////////////////////////
//  CxbFunc.cpp
//  Implementation of the Class CxbFunc
//  Created on:      24-3��-2017 18:24:19
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbDefs.h"

#include "CxbFunc.h"

string CxbFunc::xbTypeToName(int vType)
{

	switch (vType)
	{
	case CxbDefs::Usrc3p:
		return "3������ѹԴ";
		break;

	case CxbDefs::PbDKQ:
		return "ƽ���翹��";
		break;

	case CxbDefs::DCF:
		return "ֱ���˲���";
		break;

	case CxbDefs::DCF_RLC:
		return "ֱ���˲���RLC";
		break;

	case CxbDefs::DCLine:
		return "ֱ������";
		break;

	case CxbDefs::GroundLine:
		return "�ӵؼ���";
		break;

	case CxbDefs::DcLine_Seg:
		return "ֱ������Seg";
		break;

	case CxbDefs::GroundLine_Seg:
		return "�ӵؼ���Seg";
		break;

	case CxbDefs::Ground:
		return "�ӵص���";
		break;

	case CxbDefs::MetalLine:
		return "��������";
		break;

	case CxbDefs::XfC:
		return "��ɢ����";
		break;

	case CxbDefs::CoupleC:
		return "��ϵ�����";
		break;

	case CxbDefs::PulseC:
		return "�弤������";
		break;

	case CxbDefs::Shunt:
		return "����֧·";
		break;

	case CxbDefs::Branch:
		return "����֧·";
		break;

	case CxbDefs::Trap:
		return "�貨��";
		break;

	case CxbDefs::Monitor:
		return "���װ��";
		break;

	default:
		return "xbDevice";
		break;

	}//switch
}