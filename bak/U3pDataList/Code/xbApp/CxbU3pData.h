#pragma once

#include "CxbDefs.h"
#include "gbHead_Mytype.h"

#include <vector>
#include <map>

using namespace std;

class CxbU3pData
{
protected:
	int FreqDim;

public:
	struct_xbU3PData * pData;

	string DeviceName;
	string CalName;
	string CaseID;
	double PdPercent;

public:
	~ CxbU3pData();

	virtual void Init();

	virtual void Clear();
	virtual void Release();

	virtual void ClearData();

public:
	string DataName;
	virtual void InitData();

	virtual bool IsLeaf();
	virtual void Add(CxbU3pData* vItem);
	virtual void Remove(CxbU3pData* vItem);

public:
	double hUre(int vhOrder);
	double hUim(int vhOrder);
	double hIre(int vhOrder);
	double hIim(int vhOrder);
	double hYg(int vhOrder);
	double hYb(int vhOrder);

	double Get_hUrms(int vhOrder);
	void Set_hUrms(int vhOrder, double vX);
	double Get_hAngle(int vhOrder);
	void Set_hAngle(int vhOrder, double vX);
	double Get_hYb(int vhOrder);
	void Set_hYb(int vhOrder, double vX);
	void Set_hCalName(string vName);
	void Set_hCaseID(string vCaseID);
	void Set_hPdPer(double vX);

protected:
	int hMax();

	void doInitData(int vDim);

};

typedef vector<CxbU3pData*> pU3pDataVect;