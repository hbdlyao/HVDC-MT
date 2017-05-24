///////////////////////////////////////////////////////////
//  CmcCalXf2.cpp
//  Implementation of the Class CmcCalXf2
//  Created on:      02-4月-2017 14:41:57
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcFunc.h"

#include "CmcCalXf2.h"
#include "CmcDevXf2.h"

void CmcCalXf2::Prepare()
{
	int vK = 0;
	CmcDevXf2 * vDev;

	vK = StationIndex;
	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);

	if (pmcOrder->IsNormal)
		pmcProfile->pmcStaData[vK].TapCtrlType = xfCtrl_FixedAngle;
	else
		pmcProfile->pmcStaData[vK].TapCtrlType = vDev->GetTapCtrlType();

	//实际值
	//参数
	pmcProfile->pmcStaData[vK].AngCtrl_Max = CHvdcFunc::D2R(vDev->GetAngleMax());
	pmcProfile->pmcStaData[vK].AngCtrl_Min = CHvdcFunc::D2R(vDev->GetAngleMin());
	pmcProfile->pmcStaData[vK].Uv = vDev->GetFixedURef()*vDev->GetUvN(); //定阀侧电压参考值FixedURef为标幺值
	pmcProfile->pmcStaData[vK].Tap_Max = vDev->GetTapMax();
	pmcProfile->pmcStaData[vK].Tap_Min = vDev->GetTapMin();
	pmcProfile->pmcStaData[vK].deltaK = vDev->GetTapSetup();
	pmcProfile->pmcStaData[vK].Uv_Max = vDev->GetUvMax()*vDev->GetUvN();//阀侧电压最大值UvMax为标幺值
	pmcProfile->pmcStaData[vK].dx = vDev->GetUkp() / 2.0;
	pmcProfile->pmcStaData[vK].dr = vDev->GetUrp();
	pmcProfile->pmcStaData[vK].Nnom = vDev->GetTkN();
	pmcProfile->pmcStaData[vK].TC = vDev->GetTapN();
}

void CmcCalXf2::PrepareNormal()
{
	int vK = 0;
	CmcDevXf2 * vDev;

	vK = StationIndex;
	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);

	pmcProfile->pmcStaDataN[vK].TapCtrlType =-1;// vDev->GetTapCtrlType()得到的是当前的控制类型设置，而非额定工况的

	//额定值
	pmcProfile->pmcStaDataN[vK].AngCtrl_Max = CHvdcFunc::D2R(vDev->GetAngleMax());
	pmcProfile->pmcStaDataN[vK].AngCtrl_Min = CHvdcFunc::D2R(vDev->GetAngleMin());
	pmcProfile->pmcStaDataN[vK].Tap_Max = vDev->GetTapMax();
	pmcProfile->pmcStaDataN[vK].Tap_Min = vDev->GetTapMin();
	pmcProfile->pmcStaDataN[vK].TC = vDev->GetTapN();
	pmcProfile->pmcStaDataN[vK].deltaK = vDev->GetTapSetup();
	pmcProfile->pmcStaDataN[vK].Nnom = vDev->GetTkN();
	pmcProfile->pmcStaDataN[vK].dx = vDev->GetUkp() / 2.0;
	pmcProfile->pmcStaDataN[vK].dr = vDev->GetUrp();
	pmcProfile->pmcStaDataN[vK].Uv = vDev->GetUvN();
	pmcProfile->pmcStaDataN[vK].Uv_Max = 10000;

}

void CmcCalXf2::SaveNormal()
{
	int vK = 0;
	CmcDevXf2 * vDev;

	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);
	vK = StationIndex;

	vDev->SetTapN(pmcProfile->pmcStaData[vK].TC);
	vDev->SetTkN(pmcProfile->pmcStaData[vK].Nnom);
	vDev->SetUvN(pmcProfile->pmcStaData[vK].Uv);
}


void CmcCalXf2::NodeSort(NodeMap& vNodeMap)
{
	//不参与节点编号
}


void CmcCalXf2::NodeID(NodeMap& vNodeID)
{
	//不参与节点编号
}




void CmcCalXf2::NodeGround(NodeMap& vNodeMap)
{

	//不参与节点编号
}