#pragma once

#include "CHvdcOrder.h"

#include <string>

using namespace std;

class C3pOrder : public CHvdcOrder
{
public:
	//����
	//�˲���ƫ������
	int DType;

	int RandTimes;

	void Init();

	string CreateCaseID() override;

	int CaseCount() override;

	int LoopTimes();
};