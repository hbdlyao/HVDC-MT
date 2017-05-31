#pragma once

#include "CHvdcOrder.h"

#include <string>

using namespace std;

class C3pOrder : public CHvdcOrder
{
private:
	//»»Á÷Æ÷µçÁ÷Æ«²î
	double ValveKId;
	//»»Á÷Æ÷µçÑ¹Æ«²î
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