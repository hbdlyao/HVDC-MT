#pragma once

#include "C3pDefs.h"
#include "C3pCase.h"
#include "gbHead_myType.h"

class C3pCaseList : public C3pCase
{

public:
	~C3pCaseList();
	void Clear() override;
	void Release() override;
	bool IsLeaf() override;
	void Add(C3pCase* vItem) override;
	void Remove(C3pCase* vItem) override;
	virtual int ChildCount();

public:
	C3pCase* NewStaData(int vIndex, StrVector vNames);
	C3pCase* DataSelected(int vIndex, StrVector vNames);

protected:
	p3pCaseMap pDataList;

};

