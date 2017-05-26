#pragma once

#include "CHvdcOrder.h"

#include <string>

using namespace std;

class C3pOrder : public CHvdcOrder
{
public:
	int DType;

	int RandTimes;

	void Init() override;
	int StaCount() override;

	int LoopTimes();

};