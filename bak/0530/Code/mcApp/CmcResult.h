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

	void NewData(int vDim);

	void NewData1(int vDim);

	void Release();

	void Clear();
public:
	int DataDim();
	int PdSize();
	int StaCount();
	void Record(string vCalName,string vCaseId, struct_mcStationData* vStaData, struct_mcStationData* vStaDataN);

	string GetResultName();

};
