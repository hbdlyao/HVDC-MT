#pragma once
#include "CxbU3pData.h"

class CxbU3pDataList : public CxbU3pData
{
protected:
	pU3pDataList pChildren;

	map<string, CxbU3pData *> pDataList_Case;

public:
	~CxbU3pDataList();

	void Clear() override;
	void Release()override;

public:
	bool IsLeaf()  override;

	void Add(CxbU3pData* vItem)  override;
	void Remove(CxbU3pData* vItem)  override;


	virtual int ChildCount();
	virtual CxbU3pData* Child(int vIndex);

	virtual pU3pDataList Children();


};
