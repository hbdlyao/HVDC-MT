///////////////////////////////////////////////////////////
//  CmcCalConvertor.cpp
//  Implementation of the Class CmcCalConvertor
//  Created on:      02-4月-2017 14:42:20
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcFunc.h"

#include "CmcCalConvertor.h"

void CmcCalConvertor::StationSort(StationMap& vStaMap)
{
	CmcCalTwoDot::StationSort(vStaMap);

	int vN, vID;
	string vName;

	CmcDevConvertor* vDev = static_cast<CmcDevConvertor*>(pDevice);
	vName = vDev->GetMeasureStation();
	vN = static_cast<int> (vStaMap.count(vName));

	if (vN == 0)
	{//不存在 vName
		vID = static_cast<int> (vStaMap.size());
		vStaMap[vName] = vID;
	}

	MeasureStationIndex = vStaMap[vName];
}

int CmcCalConvertor::GetNodeID(int vIndex)
{
	return pDevice->GetNodeID(vIndex);
}

void CmcCalConvertor::Prepare()
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	pmcProfile->pmcStaData[vK].iNodeID = vDev->GetNodeID(0);
	pmcProfile->pmcStaData[vK].jNodeID = vDev->GetNodeID(1);
	pmcProfile->pmcStaData[vK].RefStaIndex = MeasureStationIndex;

	pmcProfile->pmcStaData[vK].WorkState = vDev->GetStationType();
	if (pmcOrder->IsNormal)
		pmcProfile->pmcStaData[vK].StaCtrlType = vDev->GetStationCtrlTypeN();
	else
		pmcProfile->pmcStaData[vK].StaCtrlType = vDev->GetStationCtrlType();
	pmcProfile->pmcStaData[vK].J_Index = -1;


	//参数
	pmcProfile->pmcStaData[vK].StationName = vDev->GetStationName();
	pmcProfile->pmcStaData[vK].Pconv = vDev->GetPconvN();
	pmcProfile->pmcStaData[vK].Qconv = vDev->GetQconvN();
	pmcProfile->pmcStaData[vK].miu = CHvdcFunc::D2R(vDev->GetmiuN());
	pmcProfile->pmcStaData[vK].Ang_Min = CHvdcFunc::D2R(vDev->GetAngleMin());
	pmcProfile->pmcStaData[vK].Udio = vDev->GetUdioN();
	pmcProfile->pmcStaData[vK].UT = vDev->GetUT();

	if (vDev->GetUdN() > pmcProfile->Ud_Max)
		pmcProfile->Ud_Max = vDev->GetUdN();//直流电压上限为全网最高额定直流电压

	if (pmcProfile->pmcStaData[vK].StaCtrlType == StaCtrl_ConstantAngle)
		pmcProfile->pmcStaData[vK].alphaOrgamma = CHvdcFunc::D2R(vDev->GetAngleRef());
	else
		pmcProfile->pmcStaData[vK].alphaOrgamma = CHvdcFunc::D2R(vDev->GetAlpha_gamaN());

	//指令相关

	pmcProfile->pmcStaData[vK].PdPer = pmcOrder->PdPer;
	if (pmcOrder->IsNormal)
		pmcProfile->pmcStaData[vK].nT = 2 * vDev->GetValvor12Count();
	else
		pmcProfile->pmcStaData[vK].nT = 2 * pmcOrder->nValNum;

	if (pmcOrder->Is6Pulse)
		pmcProfile->pmcStaData[vK].nT /= 2;



	if (pmcOrder->GroundType == Ground20 || pmcOrder->GroundType == Ground21)
		pmcProfile->pmcStaData[vK].nPoleNum = 2;
	else
		pmcProfile->pmcStaData[vK].nPoleNum = 1;


	//指令相关(冗余)
	switch (pmcOrder->UdLevel)
	{
	case  Ud_Per80:
		pmcProfile->pmcStaData[vK].Ud = vDev->GetUdN()*0.8;
		pmcProfile->pmcStaData[vK].UdL = vDev->GetUdN()*0.8;
		break;
	case  Ud_Per70:
		pmcProfile->pmcStaData[vK].Ud = vDev->GetUdN()*0.7;
		pmcProfile->pmcStaData[vK].UdL = vDev->GetUdN()*0.7;
		break;
	default:
		pmcProfile->pmcStaData[vK].Ud = vDev->GetUdN();
		pmcProfile->pmcStaData[vK].UdL = vDev->GetUdN();
		break;
	}

	if (pmcOrder->IsUdCustomPre)
	{
		pmcProfile->pmcStaData[vK].Ud = pmcOrder->UdCustom;
		pmcProfile->pmcStaData[vK].UdL = pmcOrder->UdCustom;
	}

	pmcProfile->pmcStaData[vK].Id = vDev->GetPdN() / vDev->GetUdN()*pmcOrder->PdPer / 100.0;
	pmcProfile->pmcStaData[vK].Pd = vDev->GetPdN()*pmcOrder->PdPer / 100.0;

	if (!pmcOrder->IsNormal)
	{
		pmcProfile->pmcStaData[vK].Ud *= pmcOrder->nValNum / (double)vDev->GetValvor12Count();
		pmcProfile->pmcStaData[vK].UdL *= pmcOrder->nValNum / (double)vDev->GetValvor12Count();
		pmcProfile->Ud_Max *= pmcOrder->nValNum / (double)vDev->GetValvor12Count();
		pmcProfile->pmcStaData[vK].Pd *= pmcOrder->nValNum / (double)vDev->GetValvor12Count();
		pmcProfile->pmcStaData[vK].Id *= pmcOrder->nValNum / (double)vDev->GetValvor12Count();
	}
}

void CmcCalConvertor::PrepareNormal()
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	//额定值中的很多数据都用不到，但由于这些数据项仍然存在，为了保证数据有效，以防用到，这里还是统一都准备了
	pmcProfile->pmcStaDataN[vK].iNodeID = -1;//vDev->GetNodeID()得到的是当前工况下的节点编号，而非额定工况的
	pmcProfile->pmcStaDataN[vK].jNodeID = -1;//vDev->GetNodeID()得到的是当前工况下的节点编号，而非额定工况的
	pmcProfile->pmcStaDataN[vK].RefStaIndex = MeasureStationIndex;

	pmcProfile->pmcStaDataN[vK].WorkState = vDev->GetStationType();
	pmcProfile->pmcStaDataN[vK].StaCtrlType = -1;// vDev->GetStationCtrlType()得到的是当前的控制类型设置，而非额定工况的
	pmcProfile->pmcStaDataN[vK].J_Index = -1;

	//额定值
	pmcProfile->pmcStaDataN[vK].StationName = vDev->GetStationName();
	pmcProfile->pmcStaDataN[vK].Pconv = vDev->GetPconvN();
	pmcProfile->pmcStaDataN[vK].Qconv = vDev->GetQconvN();
	pmcProfile->pmcStaDataN[vK].miu = CHvdcFunc::D2R(vDev->GetmiuN());
	pmcProfile->pmcStaDataN[vK].alphaOrgamma = CHvdcFunc::D2R(vDev->GetAlpha_gamaN());
	pmcProfile->pmcStaDataN[vK].Ang_Min = CHvdcFunc::D2R(vDev->GetAngleMin());
	pmcProfile->pmcStaDataN[vK].Pd = vDev->GetPdN();
	pmcProfile->pmcStaDataN[vK].Ud = vDev->GetUdN();
	pmcProfile->pmcStaDataN[vK].UdL = vDev->GetUdN();
	pmcProfile->pmcStaDataN[vK].UT = vDev->GetUT();
	pmcProfile->pmcStaDataN[vK].nT = 2 * vDev->GetValvor12Count();
	pmcProfile->pmcStaDataN[vK].Udio = vDev->GetUdioN();
	pmcProfile->pmcStaDataN[vK].Id = vDev->GetIdN();
	pmcProfile->pmcStaDataN[vK].nPoleNum = 2;
	pmcProfile->pmcStaDataN[vK].PdPer = 100;

}

void CmcCalConvertor::SaveNormal()
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	vK = StationIndex;

	//? 
	vDev->SetPconvN(pmcProfile->pmcStaData[vK].Pconv);
	vDev->SetQconvN(pmcProfile->pmcStaData[vK].Qconv);
	vDev->SetmiuN(CHvdcFunc::R2D(pmcProfile->pmcStaData[vK].miu));
	vDev->SetAlpha_gamaN(CHvdcFunc::R2D(pmcProfile->pmcStaData[vK].alphaOrgamma));
	vDev->SetUdioN(pmcProfile->pmcStaData[vK].Udio);
	vDev->SetUvN(pmcProfile->pmcStaData[vK].Uv);
	vDev->SetIdN(pmcProfile->pmcStaData[vK].Id);
}

void CmcCalConvertor::NodeGround(NodeMap & vNodeMap)
{

	pDevice->NodeGround(vNodeMap);

	///////////////////////////////////////////
	bool vGround;
	string vName;
	CmcDevConvertor  * vDev;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	//双极
	vGround = pmcProfile->IsBiPole();
	if (vGround)
	{
		vName = vDev->BusName(1);
		vNodeMap[vName] = -1; //-1表示接地
	}

	//金属回线
	vGround = pmcProfile->IsMetalLine();
	vGround = vGround && (vDev->GetIsGround() == 1);
	if (vGround)
	{
		vName = vDev->BusName(1);
		vNodeMap[vName] = -1; //-1表示接地
	}

}