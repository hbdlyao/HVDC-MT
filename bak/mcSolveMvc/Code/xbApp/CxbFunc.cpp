///////////////////////////////////////////////////////////
//  CxbFunc.cpp
//  Implementation of the Class CxbFunc
//  Created on:      24-3月-2017 18:24:19
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbDefs.h"

#include "CxbFunc.h"

string CxbFunc::xbTypeToName(int vType)
{

	switch (vType)
	{
	case CxbDefs::Usrc3p:
		return "3脉动电压源";
		break;

	case CxbDefs::PbDKQ:
		return "平波电抗器";
		break;

	case CxbDefs::DCF:
		return "直流滤波器";
		break;

	case CxbDefs::DCF_RLC:
		return "直流滤波器RLC";
		break;

	case CxbDefs::DCLine:
		return "直流极线";
		break;

	case CxbDefs::GroundLine:
		return "接地极线";
		break;

	case CxbDefs::DcLine_Seg:
		return "直流极线Seg";
		break;

	case CxbDefs::GroundLine_Seg:
		return "接地极线Seg";
		break;

	case CxbDefs::Ground:
		return "接地电阻";
		break;

	case CxbDefs::MetalLine:
		return "金属回线";
		break;

	case CxbDefs::XfC:
		return "杂散电容";
		break;

	case CxbDefs::CoupleC:
		return "耦合电容器";
		break;

	case CxbDefs::PulseC:
		return "冲激电容器";
		break;

	case CxbDefs::Shunt:
		return "并联支路";
		break;

	case CxbDefs::Branch:
		return "串联支路";
		break;

	case CxbDefs::Trap:
		return "阻波器";
		break;

	case CxbDefs::Monitor:
		return "监控装置";
		break;

	default:
		return "xbDevice";
		break;

	}//switch
}