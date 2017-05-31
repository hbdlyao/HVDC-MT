///////////////////////////////////////////////////////////
//  CHvdcOrder.cpp
//  Implementation of the Class CHvdcOrder
//  Created on:      03-4月-2017 18:55:02
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcOrder.h"
#include "CHvdcDefs.h"

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

	Flag_Ground = "1110";		//接地：单极大地/金属回线/双极/双极并联
	Flag_Ud = "111";			//直流电压：全压/80%/70%
	Flag_Rd = "110";			//直流电阻：高阻/低阻/额定
	Flag_Uac = "1111";			//交流电压：最大/额定/最小/极小

	IsUacSwap = true;			// 是否交流电压交叉
	IsUdCustom = false;			//直流电压预设情况，如预设则使用UdCustom作为电压指令，否则使用UdLevel
	IsUdToGround = false;		//直流电压对地或对中性线
								//string Flag_IsPdSingle = "0";//是否单功率水平，该成员可以不要，当成员BdSize取值为1时即为但功率水平
	PdStartPer = 10;			//起始功率水平
	PdIncrePer = 5;				//功率水平增量
	PdSize = 29;				//功率水平数

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


void CHvdcOrder::ParserOrder(string vCaseID)
{
	//DFBFH222表示双阀，正向，双极，全压，高阻，交流电压为额定的工况
	//SGFH1111%100

	//int vN = static_cast<int> (vCaseID.size());

	//pxbOrder->nValNum
	switch (vCaseID[0])
	{
	case 'D':
		nValNum = 2;
		break;

	case 'S':
		nValNum = 1;
		break;

	default:
		break;
	}

	//pxbOrder->GroundType
	switch (vCaseID[1])
	{
	case 'G':
		GroundType = Ground10;
		break;

	case 'M':
		GroundType = Ground11;
		break;

	case 'B':
		GroundType = Ground20;
		break;

	case 'P':
		GroundType = Ground21;
		break;

	default:
		break;
	}

	//pxbOrder->UdLevel
	switch (vCaseID[2])
	{
	case 'F':
		UdLevel = Ud_Full;
		break;

	case 'R':
		UdLevel = Ud_Per80;
		break;

	case 'S':
		UdLevel = Ud_Per70;
		break;

	case 'C':
		UdLevel = Ud_Custom;
		break;
	default:
		break;
	}

	//pxbOrder->RdLevel
	switch (vCaseID[3])
	{
	case 'H':
		RdLevel = Rd_High;
		break;

	case 'L':
		RdLevel = Rd_Low;
		break;

	case 'N':
		RdLevel = Rd_Normal;
		break;

	default:
		break;

	}

	//pxbOrder->UacLevel
	for (int i = 0; i < StaCount(); i++)
	{
		switch (vCaseID[4 + i])
		{
		case '1':
			UacLevel[i] = Uac_Max;
			break;

		case '2':
			UacLevel[i] = Uac_Norm;
			break;

		case '3':
			UacLevel[i] = Uac_Min;
			break;

		case '4':
			UacLevel[i] = Uac_ExMin;
			break;

		default:
			break;
		}
	}

	//pxbOrder->PdPer

}



void CHvdcOrder::AddCase(struct_Case vCase)
{
	CaseList.push_back(vCase);
}

string CHvdcOrder::CreateCaseID()
{

	//char buff[1];

	string CaseID = "";

	//阀组数:
	switch (nValNum)
	{
	case 1:
		CaseID.append("S");
		break;
	case 2:
		CaseID.append("D");
		break;
	}

	//接地:单极大地，单极金属，双极，双极并联
	switch (GroundType)
	{
	case Ground20:
		CaseID.append("B");
		break;
	case Ground11:
		CaseID.append("M");
		break;
	case Ground10:
		CaseID.append("G");
		break;
	case Ground21:
		CaseID.append("P");
		break;
	default:
		break;
	}

	//Ud:全压,80%,70%
	switch (UdLevel)
	{
	case Ud_Full:
		CaseID.append("F");
		break;
	case Ud_Per80:
		CaseID.append("R");
		break;
	case Ud_Per70:
		CaseID.append("S");
		break;

	case Ud_Custom:
		CaseID.append("C");
		break;

	default:
		break;
	}

	//Rd:高阻、低阻
	switch (RdLevel)
	{
	case Rd_High:
		CaseID.append("H");
		break;
	case Rd_Low:
		CaseID.append("L");
		break;

	case Rd_Normal:
		CaseID.append("N");
		break;

	default:
		break;
	}

	//交流Uac
	if (StaCount() > 0)
	{
		for (int i = 0; i < StaCount(); i++)
			CaseID = CaseID + ((char)(UacLevel[i] + 1 + '0'));
	}//if

	//
	//char vChar[5];
	//sprintf_s(vChar, 5,"%-3.0f", PdPer);

	//CaseID = CaseID+"%"+vChar;

	//
	return CaseID;
}

int CHvdcOrder::CaseCount()
{
	int vCountGroundType = 0;
	int vCountUd = 0;
	int vCountRd = 0;
	int vCountUac = 0;

	for each (char flag in Flag_Ground)
		if (flag == '1')
			vCountGroundType++;

	for each (char flag in Flag_Ud)
		if (flag == '1')
			vCountUd++;

	if (IsUdCustom)
		vCountUd = 1;

	for each (char flag in Flag_Rd)
		if (flag == '1')
			vCountRd++;

	for each (char flag in Flag_Uac)
		if (flag == '1')
			vCountUac++;

	if (IsUacSwap)
		vCountUac = (int)pow(vCountUac, StaCount());

	//
	int vN = vCountGroundType*vCountUd*vCountRd*vCountUac;

	return vN;
}

