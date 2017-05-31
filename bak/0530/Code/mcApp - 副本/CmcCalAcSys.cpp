///////////////////////////////////////////////////////////
//  CmcCalAcSys.cpp
//  Implementation of the Class CmcCalAcSys
//  Created on:      02-4��-2017 14:41:33
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
	//�豸����
	pmcProfile->pmcStaData[vK].QacInMax = vDev->GetQinMax();
	pmcProfile->pmcStaData[vK].QacOutMax = vDev->GetQoutMax();
	pmcProfile->pmcStaData[vK].Qf_max = vDev->GetQfMaxN();
	pmcProfile->pmcStaData[vK].Qf_min = vDev->GetQfMinN();

	//ָ�����
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

	//�ֵ
	//�豸����
	pmcProfile->pmcStaDataN[vK].QacInMax = vDev->GetQinMax();
	pmcProfile->pmcStaDataN[vK].QacOutMax = vDev->GetQoutMax();
	pmcProfile->pmcStaDataN[vK].Qf_max = vDev->GetQfMaxN();
	pmcProfile->pmcStaDataN[vK].Qf_min = vDev->GetQfMinN();

	//ָ�����
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
	//������ڵ���
}


void CmcCalAcSys::NodeID(NodeMap& vNodeID)
{
	//������ڵ���
}




void CmcCalAcSys::NodeGround(NodeMap& vNodeMap){

	//������ڵ���
}