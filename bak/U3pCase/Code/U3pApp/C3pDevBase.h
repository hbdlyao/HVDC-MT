#pragma once

#include "CDevBase.h"
#include "gbHead_3ptype.h"

class C3pDevBase : public CDevBase
{
public:
	void Init() override;
	virtual void InitData();

protected:
	/**
	 * 正极或负极
	 */
	int PosOrNeg;

	string ValveName;
public:

	virtual void Sort3p(ValveMap& vValMap);
	/**
	 * 正极或负极
	 */
	int GetPosOrNeg();
	/**
	 * 正极或负极
	 */
	void SetPosOrNeg(int newVal);

	void SetValveName(string vNewVal);

	string GetValveName();

	int hMax();
	double FreqRef();
	double Omega();

	virtual void Prepare3pData(int vDType, int vLoopTimes);
	virtual void DataSelected(string vCalName, string vCaseID, double vPdPersent);
};
