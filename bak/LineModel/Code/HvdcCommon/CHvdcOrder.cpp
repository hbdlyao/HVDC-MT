///////////////////////////////////////////////////////////
//  CHvdcOrder.cpp
//  Implementation of the Class CHvdcOrder
//  Created on:      03-4月-2017 18:55:02
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcOrder.h"


CHvdcOrder::~CHvdcOrder()
{
	Release();
}

void CHvdcOrder::Release()
{
	delete[] UacLevel;
	UacLevel = nullptr;

}

void CHvdcOrder::Clear()
{
	delete[] UacLevel;
	UacLevel = nullptr;
}

void CHvdcOrder::Init()
{
	//
	UacLevel = new int[StaCount()];

	//
	nValNum = 1;

	Flag_Ground = "1111";  //单极大地/金属回线/双极/双极并联
	Flag_Ud = "111";  //全压/80%/70%
	Flag_Rd = "110";    //高阻/低阻/额定
	Flag_Uac = "1111";  //最大/额定/最小/极小

	IsUdCustom = false;//直流电压预设情况，如预设则使用UdCustom作为电压指令，否则使用UdLevel
	IsUacSwap = true;// 是否交流电压交叉
	IsUdToGround = false;//直流电压对地或对中性线
						 //string Flag_IsPdSingle = "0";//是否单功率水平，该成员可以不要，当成员BdSize取值为1时即为但功率水平
	PdStartPer = 10;//起始功率水平
	PdIncrePer = 5;//功率水平增量
	PdSize = 29;//功率水平数

	IsNormal = false;
			   //Is6p = false;
			   //Is12pDouble = false;
}

void CHvdcOrder::InitNormal()
{
	//
	UacLevel = new int[StaCount()];

	//
	nValNum = 0;
	IsNormal = true;

	Flag_Ground = "0010";  //单极大地/金属回线/双极/双极并联
	Flag_Ud = "100";  //全压/80%/70%
	Flag_Rd = "001";    //高阻/低阻（额定）
	Flag_Uac = "0100";  //最大/额定/最小/极小

	IsUdCustom = false;//直流电压预设情况，如预设则使用UdCustom作为电压指令，否则使用UdLevel
	IsUacSwap = false;// 是否交流电压交叉
	IsUdToGround = false;//直流电压对地或对中性线
						 //string Flag_IsPdSingle = "0";//是否单功率水平，该成员可以不要，当成员BdSize取值为1时即为但功率水平
	PdStartPer = 100;//起始功率水平
	PdIncrePer = 0;//功率水平增量
	PdSize = 1;//功率水平数

}


void CHvdcOrder::UpdatePdPercent(int & vPdSize)
{
	PdPer = PdStartPer + PdIncrePer*vPdSize;

}



