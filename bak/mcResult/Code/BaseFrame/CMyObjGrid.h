#pragma once

#include "CMyObjBase.h"
#include "CMyObjTBL.h"

#include <string>

using namespace std;


/**
 * ∂‘œÛ±Ì
 */
class CMyObjGrid
{

public:
	virtual ~CMyObjGrid();
	virtual string TypeToName(int vType);
	virtual void Init();
	virtual void Clear();
	int ChildCount();
	CMyObjTBL* Child(int vIndex);
	pTBLVector Children();
	void Add(CMyObjTBL* vItem);
	void Remove(CMyObjTBL* vItem);

protected:
	pTBLVector pChildren;

};
