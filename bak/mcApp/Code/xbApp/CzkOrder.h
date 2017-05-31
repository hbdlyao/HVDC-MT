#pragma once

#include "CxbOrder.h"
#include "CxbDefs.h"

class CzkOrder :public CxbOrder
{
public:
	void Init();

	string CreateCaseID() override;
	
	//ɨ��˿�
	string GetPortName(int i);

	string ScanPortStation = "Station1";

	int ScanPortPole = xb_Pos;

	int ScanPort = 0;
	//��ʼƵ��
	double FreStart = 10;
	//Ƶ�����Ӳ���
	double FreStep = 10;
	//Ƶ������
	int FreDim = 300;
};

