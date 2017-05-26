#pragma once

#include "CxbDevTwo.h"
#include "CxbDefs.h"

#include "CxbU3pDataList.h"

/**
* 三脉动电压源
*/
class CxbDev3pVSrc : public CxbDevTwo
{
public:	//
	struct_xbU3PData * pU3pData;
	
	pU3pDataVect DataVect;

	CxbU3pDataList DataList;

	void doInitData(int vDim) override;

	void DataSelected(string vCalName, string vCaseID, double vPdPercent);

public:
	~CxbDev3pVSrc();

	void ClearData() override;

public:
	virtual void Prepare_hRLC();
	virtual void Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim);

	struct_xbU3PData * NewU3pData();
	CxbU3pData * NewU3pData(string vCalName, string vCaseID, double vPdPercent);

	void AddDataToList();

public:
	double hUre(int vhOrder);
	double hUim(int vhOrder);

	double hIre(int vhOrder);
	double hIim(int vhOrder);

	double hYg(int vhOrder);
	double hYb(int vhOrder);

	double Get_hUrms(int vhOrder);
	void   Set_hUrms(int vhOrder,double vX);

	double Get_hAngle(int vhOrder);
	void   Set_hAngle(int vhOrder, double vX);

	double Get_hYb(int vhOrder);
	void   Set_hYb(int vhOrder, double vX);

	void Set_hCalName(string vName);

	void Set_hCaseID(string vCaseID);

	void Set_hPdPer(double vX);

};

