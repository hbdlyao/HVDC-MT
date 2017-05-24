#pragma once

#include "CmcDefs.h"

class CmcResult
{
public:
	int nStaDim;
	int nCaseDim;
	int nPdPreDim;
	
	int datDim;

	int CurrentOffset;

	string ResultName;
	struct_mcResultData * pmcResultData;

public:
	~CmcResult();

	void Init();
	void Init(int vStaDim, int vCaseDim, int vPdPreDim);

	void Release();

	void Clear();
public:
	int DataDim();
	void Record(string vCalName,string vCaseId, struct_mcStationData* vStaData, struct_mcStationData* vStaDataN);

	string GetResultName();

};
