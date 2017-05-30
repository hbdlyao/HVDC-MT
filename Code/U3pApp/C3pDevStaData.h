#pragma once

#include "C3pDevBase.h"

#include "C3pDefs.h"

#include "C3pCaseList.h"

class C3pDevStaData : public C3pDevBase
{
protected:
	struct_U3pStaData * pStaData;

public:	
	p3pCaseVect DataVect;

	C3pCaseList DataList;

public:
	~C3pDevStaData();

	void Init() override;

	void DataSelected(string vCalName, string vCaseID, double vPdPersent) override;

	void NewStaData(string vCalName, string vCaseID, double vPdPercent);

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

	//¡ı≥©£¨get set pData

};
