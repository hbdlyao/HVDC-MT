#pragma once

#include "CmcDefs.h"

class CmcCase
{

public:
	vector<struct_mcResultData*> pDataVect;

	struct_mcResultData pData;

	string DataName;

	//string CalName;
	//string CaseID;
	//string StationName;

	//double PdPer;

public:
	~ CmcCase();
	virtual void Init();
	virtual void Release();

	virtual bool IsLeaf();

	virtual void Add(string vID, CmcCase* vCase);
	virtual void Remove(CmcCase* vItem);

public:

	int datCount();

public:
	
};
