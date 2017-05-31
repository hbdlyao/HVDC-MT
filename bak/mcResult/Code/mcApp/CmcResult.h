#pragma once

#include "CmcDefs.h"
#include "CmcCasePack.h"
#include "gbHead_Mytype.h"

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

	CmcCasePack pPack;

	vector<struct_mcResultData*> pDataVect;

public:
	~CmcResult();

	void Init();
	void Init(int vStaDim, int vCaseDim, int vPdPreDim);
	void Clear();
	void Release();

public:
	int DataDim();
	int PdSize();
	int StaCount();

	void Record(string vCalName,string vCaseId, struct_mcStationData* vStaData, struct_mcStationData* vStaDataN);

	string GetResultName();

public:
	long PackedLeng();
	int RecordByte();	
	void Serialize(Byte * vPacket);
	void UnSerialize(Byte * vPacket);

	CmcCase * NewCase(struct_mcResultData * vData);	

	void NewData(int vDim);
	void NewData1(int vDim);
};
