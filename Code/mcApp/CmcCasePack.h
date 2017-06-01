#pragma once

#include "CmcDefs.h"
#include "CmcCase.h"
#include "gbHead_myType.h"

class CmcCasePack : public CmcCase
{
protected:
	map<string, CmcCase *> pChildren;

public:
	~CmcCasePack();
	void Release() override;

	bool IsLeaf() override;
	void Add(string vID, CmcCase* vCase) override;
	void Remove(CmcCase* vItem) override;

	int ChildCount();
	map<string, CmcCase *> Children();

public:
	CmcCase* NewCase(int vIndex, StrVector vNames, struct_mcResultData * vData);
	CmcCase* FindCase(int vIndex, StrVector vNames);

};

