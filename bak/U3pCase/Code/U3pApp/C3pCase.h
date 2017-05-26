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
	double Get_hPdPer();
	void Set_hPdPer(double vX);

};


typedef vector<C3pCase*> p3pCaseVect;

typedef map<string, C3pCase *> p3pCaseMap;