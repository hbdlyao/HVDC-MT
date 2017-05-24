#pragma once

#include "CObjBase.h"

#include <string>
using namespace std;

/**
* ∂‘œÛ±Ì
*/
class CObjTBL
{
protected:
	pObjVector pChildren;

public:
	virtual ~CObjTBL();

	virtual string TypeToName(int vType);

	virtual void Init();
	virtual void Clear();
	virtual void Release();

public:
	void Add(CObjBase* vItem);
	void Remove(CObjBase* vItem);

	int ChildCount();
	CObjBase * Child(int vIndex);
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

typedef vector<CObjTBL*> pTBLVector;
