#pragma once

#include "CxbOrder.h"
#include "CxbDefs.h"

class CzkOrder :public CxbOrder
{
public:
	void Init();
	
	//ɨ��˿�
	string GetPortName(int i);
	string ScanPortStation = "Station1";
	int ScanPortPole = xb_Pos;
	int ScanPort = 0;

	//��ʼƵ��
	double FreStart;
	//Ƶ�����Ӳ���
	double FreStep;
	//Ƶ������
	int FreDim ;
};

