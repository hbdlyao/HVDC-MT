#pragma once

#include "CxbDefs.h"
#include <vector>
#include <map>

using namespace std;

class CxbU3pData
{
protected:
	int FreqDim;

	struct_xbU3PData pU3pData;

public:
	~ CxbU3pData();

	virtual void Init();

	virtual void Clear();
	virtual void Release();

	virtual void ClearData();

public:
	virtual void InitData();

	virtual bool IsLeaf();
	virtual void Add(CxbU3pData* vItem);
	virtual void Remove(CxbU3pData* vItem);

protected:
	int hMax();

	void doInitData(int vDim);

};

typedef vector<CxbU3pData*> pU3pDataList;