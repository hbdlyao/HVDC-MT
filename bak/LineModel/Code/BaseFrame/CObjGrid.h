#pragma once

#include "CObjBase.h"
#include "CObjTBL.h"

#include <string>

using namespace std;


/**
 * ∂‘œÛ±Ì
 */
class CObjGrid
{

public:
	virtual ~CObjGrid();
	virtual string TypeToName(int vType);
	virtual void Init();
	virtual void Clear();
	int ChildCount();
	CObjTBL* Child(int vIndex);
	pTBLVector Children();
	void Add(CObjTBL* vItem);
	void Remove(CObjTBL* vItem);

protected:
	pTBLVector pChildren;

};
