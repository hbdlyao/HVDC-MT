#pragma once

#include "CHvdcOrder.h"
#include <vector>
#include <string>

using namespace std;

class C3pOrder : public CHvdcOrder
{
private:
	//����������ƫ��
	double ValveKId;
	//��������ѹƫ��
	double ValveKUv;
public:
	double GetValveKId();
	double GetValveKUv();

	void SetValveKId(double vVal);
	void SetValveKUv(double vVal);

public:
	string mcName;

	int DType;

	int RandTimes;

	void Init() override;
	int StaCount() override;

	int LoopTimes();

};