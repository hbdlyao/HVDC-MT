#pragma once

#include "C3pDevBase.h"

#include "C3pDefs.h"

#include "CmcDefs.h"

class C3pDevStaData : public C3pDevBase
{
protected:
	struct_mcResultData * pStaData;

public:
	~C3pDevStaData();

	void Init() override;
	
	void SetStationData(struct_mcResultData * vData);

	void SetCaseID(string Val);

	void SetCalName(string Val);

	void SetPdPer(double Val);

	void SetUac(double Val);

	void SetUv(double Val);

	void SetUvN(double Val);

	void SetId(double Val);

	void SetTC(int Val);

	void SetalphaOrgamma(double Val);

	void Setmiu(double Val);

	void SetNnom(double Val);

	string GetCaseID();

	string GetCalName();

	double GetPdPer();

	double GetUac();

	double GetUv();

	double GetUvN();

	double GetId();

	int GetTC();

	double GetalphaOrgamma();

	double Getmiu();

	double GetNnom();

};
