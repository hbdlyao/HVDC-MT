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

	//¡ı≥©£¨get set pData

};
