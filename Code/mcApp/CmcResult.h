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

	string CalName;

	CmcCasePack pCasePack;

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
	void NewCase();

protected:
	CmcCase * doNewCase(struct_mcResultData * vData);
	CmcCase * doNewCase(StrVector vNames, struct_mcResultData * vData);
	
	CmcCase * doFindCase(StrVector vNames);

public:
	int RecordByte();
	long PacketBytes();

	Byte * Serialize();

	void Serialize(Byte * vPacket);
	void UnSerialize(Byte * vPacket);

	void Serialize(StrVector vNames, Byte * vPacket);
	void UnSerialize(StrVector vNames, Byte * vPacket);

protected:
	void doSerialize(vector<struct_mcResultData*>  vDataVect, Byte * vPacket);
	void doUnSerialize(Byte * vPacket, vector<struct_mcResultData*> & vDataVect);

};
