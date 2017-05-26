///////////////////////////////////////////////////////////
//  CmcCalAcSys.cpp
//  Implementation of the Class CmcCalAcSys
//  Created on:      02-4月-2017 14:41:33
//  Original author: Administrator
///////////////////////////////////////////////////////////


#include "CmcCalAcSys.h"
#include "CmcDevAcSys.h"

void CmcCalAcSys::Prepare()
{
	int vK = 0;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(pDevice);
	vK = StationIndex;

	//
	//设备参数
	pmcProfile->pmcStaData[vK].QacInMax = vDev->GetQinMax();
	pmcProfile->pmcStaData[vK].QacOutMax = vDev->GetQoutMax();
	pmcProfile->pmcStaData[vK].Qf_max = vDev->GetQfMaxN();
	pmcProfile->pmcStaData[vK].Qf_min = vDev->GetQfMinN();

	//指令相关
	switch (pmcOrder->UacLevel[vK])
	{
	case Uac_Max:
		pmcProfile->pmcStaData[vK].Uac = vDev->GetUacMax();
		break;
	case Uac_Min:
		pmcProfile->pmcStaData[vK].Uac = vDev->GetUacMin();
		break;
	case Uac_ExMin:
		pmcProfile->pmcStaData[vK].Uac = vDev->GetUacExMin();
		break;

	default:
		pmcProfile->pmcStaData[vK].Uac = vDev->GetUacN();
		break;
	}

}

void CmcCalAcSys::PrepareNormal() 
{
	int vK = 0;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(pDevice);
	vK = StationIndex;

	//额定值
	//设备参数
	pmcProfile->pmcStaDataN[vK].QacInMax = vDev->GetQinMax();
	pmcProfile->pmcStaDataN[vK].QacOutMax = vDev->GetQoutMax();
	pmcProfile->pmcStaDataN[vK].Qf_max = vDev->GetQfMaxN();
	pmcProfile->pmcStaDataN[vK].Qf_min = vDev->GetQfMinN();

	//指令相关
	pmcProfile->pmcStaDataN[vK].Uac = vDev->GetUacN();

}

void CmcCalAcSys::SaveNormal()
{
	int vK = 0;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(pDevice);
	vK = StationIndex;

	vDev->SetQfMaxN(pmcProfile->pmcStaData[vK].Qf_max);
	vDev->SetQfMinN(pmcProfile->pmcStaData[vK].Qf_min);
	vDev->SetUacN(pmcProfile->pmcStaData[vK].Uac);
}


void CmcCalAcSys::NodeSort(NodeMap& vNodeMap)
{
	//不参与节点编号
}


void CmcCalAcSys::NodeID(NodeMap& vNodeID)
{
	//不参与节点编号
}




void CmcCalAcSys::NodeGround(NodeMap& vNodeMap){

	//不参与节点编号
}