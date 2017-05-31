#pragma once

#include "CmcDefs.h"

class CmcCase
{

public:
	struct_mcResultData pData;
	vector<struct_mcResultData*> pDataVect;

	string DataName;

	string CalName;
	string CaseID;
	string StationName;

	double PdPer;

public:
	~ CmcCase();
	virtual void Init();
	virtual void Clear();
	virtual void Release();

	virtual void ClearData();
	virtual void InitData();
	virtual bool IsLeaf();

	virtual void Add(CmcCase* vItem);
	virtual void Remove(CmcCase* vItem);

public:
	
};
