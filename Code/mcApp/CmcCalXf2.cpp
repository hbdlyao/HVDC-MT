///////////////////////////////////////////////////////////
//  CmcCalXf2.cpp
//  Implementation of the Class CmcCalXf2
//  Created on:      02-4��-2017 14:41:57
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CMyFunc.h"

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

	//ʵ��ֵ
	//����
	pmcProfile->pmcStaData[vK].AngCtrl_Max = CMyFunc::D2R(vDev->GetAngleMax());
	pmcProfile->pmcStaData[vK].AngCtrl_Min = CMyFunc::D2R(vDev->GetAngleMin());
	pmcProfile->pmcStaData[vK].Uv = vDev->GetFixedURef()*vDev->GetUvN(); //�������ѹ�ο�ֵFixedURefΪ����ֵ
	pmcProfile->pmcStaData[vK].Tap_Max = vDev->GetTapMax();
	pmcProfile->pmcStaData[vK].Tap_Min = vDev->GetTapMin();
	pmcProfile->pmcStaData[vK].deltaK = vDev->GetTapSetup();
	pmcProfile->pmcStaData[vK].Uv_Max = vDev->GetUvMax()*vDev->GetUvN();//�����ѹ���ֵUvMaxΪ����ֵ
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

	pmcProfile->pmcStaDataN[vK].TapCtrlType =-1;// vDev->GetTapCtrlType()�õ����ǵ�ǰ�Ŀ����������ã����Ƕ������

	//�ֵ
	pmcProfile->pmcStaDataN[vK].AngCtrl_Max = CMyFunc::D2R(vDev->GetAngleMax());
	pmcProfile->pmcStaDataN[vK].AngCtrl_Min = CMyFunc::D2R(vDev->GetAngleMin());
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
	//������ڵ���
}


void CmcCalXf2::NodeID(NodeMap& vNodeID)
{
	//������ڵ���
}




void CmcCalXf2::NodeGround(NodeMap& vNodeMap)
{

	//������ڵ���
}