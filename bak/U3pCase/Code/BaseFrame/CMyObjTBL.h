#pragma once

#include "CMyObjBase.h"

#include <string>
using namespace std;

/**
* ∂‘œÛ±Ì
*/
class CMyObjTBL
{
protected:
	pObjVector pChildren;

public:
	virtual ~CMyObjTBL();

	virtual string TypeToName(int vType);

	virtual void Init();
	virtual void Clear();
	virtual void Release();

protected:
	void Add(CMyObjBase* vItem);
	void Remove(CMyObjBase* vItem);

public:
	int ChildCount();
	CMyObjBase * Child(int vIndex);
	pObjVector Children();

protected:
	string tblName;
	int tblType;

public:
	string GetTblName();
	void SetTblName(string newVal);
	int GetTblType();
	void SetTblType(int newVal);

};

typedef vector<CMyObjTBL*> pTBLVector;
