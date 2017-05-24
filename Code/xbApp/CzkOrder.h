#pragma once

#include "CxbOrder.h"
#include "CxbDefs.h"

class CzkOrder :public CxbOrder
{
public:
	void Init();
	
	//扫描端口
	string GetPortName(int i);

	string ScanPortStation = "Station1";

	int ScanPortPole = xb_Pos;

	int ScanPort = 0;
	//起始频率
	double FreStart = 10;
	//频率增加步长
	double FreStep = 10;
	//频率总数
	int FreDim = 300;
};

