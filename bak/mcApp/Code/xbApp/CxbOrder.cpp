///////////////////////////////////////////////////////////
//  CxbOrder.cpp
//  Implementation of the Class CxbOrder
//  Created on:      05-4��-2017 18:22:10
//  Original author: Administrator
///////////////////////////////////////////////////////////


#include "CHvdcDefs.h"

#include "CxbOrder.h"
#include "CxbDefs.h"
#include "CxbParams.h"

void CxbOrder::Init()
{
	UacLevel = new int[StaCount()];
	
	//
	nValNum = 2;
	
	Flag_Ground = "100";  //�������/��������/˫��
	Flag_Ud = "100";  //ȫѹ/80%/70%
	Flag_Rd = "001";    //����/����
	Flag_Uac = "0100";  //���/�/��С/��С
	
	IsUdCustom = false;//ֱ����ѹԤ���������Ԥ����ʹ��UdCustom��Ϊ��ѹָ�����ʹ��UdLevel
	IsUacSwap = true;// �Ƿ�����ѹ����
	IsUdToGround = false;//ֱ����ѹ�Եػ��������
					 //string Flag_IsPdSingle = "0";//�Ƿ񵥹���ˮƽ���ó�Ա���Բ�Ҫ������ԱBdSizeȡֵΪ1ʱ��Ϊ������ˮƽ
	PdStartPer = 100;//��ʼ����ˮƽ
	PdIncrePer = 5;//����ˮƽ����
	PdSize = 1;//����ˮƽ��
}


int CxbOrder::CaseCount()
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

int CxbOrder::StaCount()
{
	return CxbParams::xbStationCount;
}


string CxbOrder::CreateCaseID() 
{

	//char buff[1];

	string CaseID = "";

	//������:
	switch (nValNum)
	{
	case 1:
		CaseID.append("S");
		break;
	case 2:
		CaseID.append("D");
		break;
	}

	//�ӵ�:������أ�����������˫����˫������
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

	//Ud:ȫѹ,80%,70%
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

	//Rd:���衢����
	switch (RdLevel)
	{
	case Rd_High:
		CaseID.append("H");
		break;
	case Rd_Low:
		CaseID.append("L");
		break;
	default:
		break;
	}

	//����Uac
	if (StaCount() > 0)
	{
		for (int i = 0; i < StaCount() ; i++)
			CaseID = CaseID + ((char)(UacLevel[i] + 1 + '0'));
	}//if

	
	 //����
	CaseID += "%" + to_string(PdPer);

	//
	return CaseID;
}