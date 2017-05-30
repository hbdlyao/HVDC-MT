#pragma once

#include "C3pDefs.h"

class C3pCase
{

public:
	struct_U3pStaData pStaData;

	string DataName;
	string StationName;

public:
	~ C3pCase();
	virtual void Init();
	virtual void Clear();
	virtual void Release();
	virtual void ClearData();
	virtual void InitData();
	virtual bool IsLeaf();
	virtual void Add(C3pCase* vItem);
	virtual void Remove(C3pCase* vItem);

public:
	string Get_hCalName();
	void Set_hCalName(string vName);
	string Get_hCaseID();
	void Set_hCaseID(string vCaseID);
	string Get_hStationName();
	void Set_hStationName(string vCaseID);
	double Get_hPdPer();
	void Set_hPdPer(double vX);

	void Set_hUac(double vX);

	double Get_hUac();

	void Set_hUv(double vX);

	double Get_hUv();

	void Set_hUvN(double vX);

	double Get_hUvN();

	void Set_hId(double vX);

	double Get_hId();

	void Set_hTC(int vX);

	int Get_hTC();

	void Set_halphaOrgamma(double vX);

	double Get_halphaOrgamma();

	void Set_hmiu(double vX);

	double Get_hmiu();

	void Set_hNnom(double vX);

	double Get_hNnom();

	//¡ı≥©£¨get set pData
};


typedef vector<C3pCase*> p3pCaseVect;

typedef map<string, C3pCase *> p3pCaseMap;