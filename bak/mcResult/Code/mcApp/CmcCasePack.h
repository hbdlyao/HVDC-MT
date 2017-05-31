#pragma once

#include "CmcDefs.h"
#include "CmcCase.h"
#include "gbHead_myType.h"

class CmcCasePack : public CmcCase
{
public:

public:
	~CmcCasePack();
	void Clear() override;
	void Release() override;
	bool IsLeaf() override;
	void Add(CmcCase* vItem) override;
	void Remove(CmcCase* vItem) override;
	virtual int ChildCount();

public:
	CmcCase* NewCase(int vIndex, StrVector vNames);

	CmcCase* DataSelected(int vIndex, StrVector vNames);

protected:
	//p3pCaseMap pDataList;

	map<string,CmcCase *> pCaseMap;

};

