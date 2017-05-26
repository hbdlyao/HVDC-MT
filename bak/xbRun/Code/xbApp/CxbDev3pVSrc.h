#pragma once

#include "CxbDevTwo.h"
#include "CxbDefs.h"

#include "CxbU3pDataList.h"

/**
* 三脉动电压源
*/
class CxbDev3pVSrc : public CxbDevTwo
{

protected:	//
	struct_xbU3PData  pU3pData;
	map<string, CxbU3pDataList *> pDataList_PdPer;

	void doInitData(int vDim) override;

public:
	~CxbDev3pVSrc();

	void ClearData() override;

public:
	virtual void Prepare_hRLC();
	virtual void Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim);

public:

	//马骏鹏
	//virtual void PrepareData(string vCondition, string vPowPre);
	virtual void PrepareData(string vCondition);

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

