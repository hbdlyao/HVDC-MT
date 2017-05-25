///////////////////////////////////////////////////////////
//  CHvdcOrder.cpp
//  Implementation of the Class CHvdcOrder
//  Created on:      03-4��-2017 18:55:02
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

	Flag_Ground = "1111";  //�������/��������/˫��/˫������
	Flag_Ud = "111";  //ȫѹ/80%/70%
	Flag_Rd = "110";    //����/����/�
	Flag_Uac = "1111";  //���/�/��С/��С

	IsUdCustom = false;//ֱ����ѹԤ���������Ԥ����ʹ��UdCustom��Ϊ��ѹָ�����ʹ��UdLevel
	IsUacSwap = true;// �Ƿ�����ѹ����
	IsUdToGround = false;//ֱ����ѹ�Եػ��������
						 //string Flag_IsPdSingle = "0";//�Ƿ񵥹���ˮƽ���ó�Ա���Բ�Ҫ������ԱBdSizeȡֵΪ1ʱ��Ϊ������ˮƽ
	PdStartPer = 10;//��ʼ����ˮƽ
	PdIncrePer = 5;//����ˮƽ����
	PdSize = 29;//����ˮƽ��

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

	Flag_Ground = "0010";  //�������/��������/˫��/˫������
	Flag_Ud = "100";  //ȫѹ/80%/70%
	Flag_Rd = "001";    //����/���裨���
	Flag_Uac = "0100";  //���/�/��С/��С

	IsUdCustom = false;//ֱ����ѹԤ���������Ԥ����ʹ��UdCustom��Ϊ��ѹָ�����ʹ��UdLevel
	IsUacSwap = false;// �Ƿ�����ѹ����
	IsUdToGround = false;//ֱ����ѹ�Եػ��������
						 //string Flag_IsPdSingle = "0";//�Ƿ񵥹���ˮƽ���ó�Ա���Բ�Ҫ������ԱBdSizeȡֵΪ1ʱ��Ϊ������ˮƽ
	PdStartPer = 100;//��ʼ����ˮƽ
	PdIncrePer = 0;//����ˮƽ����
	PdSize = 1;//����ˮƽ��

}


void CHvdcOrder::UpdatePdPercent(int & vPdSize)
{
	PdPer = PdStartPer + PdIncrePer*vPdSize;

}


void CHvdcOrder::AddCase(string vID)
{
	CaseList.push_back(vID);
}



