#pragma once

#include "CHvdcOrder.h"

#include <string>

using namespace std;

class C3pOrder : public CHvdcOrder
{
public:
	//Âí¿¥Åô
	//ÂË²¨Æ÷Æ«²îÀàĞÍ
	int DType;

	int RandTimes;

	void Init();

	string CreateCaseID() override;

	int CaseCount() override;

	int LoopTimes();
};