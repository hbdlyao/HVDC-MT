#pragma once

#include "CxbU3pData.h"
#include "gbHead_MyType.h"


class CxbU3pDataList : public CxbU3pData
{
protected:
	pU3pDataVect pChildren;

	map<string, CxbU3pData *> pDataList;

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

	virtual pU3pDataVect Children();

	CxbU3pData * NewU3pData(int vIndex, StrVector vNames) ;

	CxbU3pData * DataSelected(int vIndex, StrVector vNames);


};
