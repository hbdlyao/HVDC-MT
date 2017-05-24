#pragma once

#include <vector>
#include <map>

using namespace std;

/**
 * 对象基类
 */
class CObjBase
{

public:
	CObjBase();
	virtual ~CObjBase();

	virtual void Clear();
	virtual void Release();

	int GetObjGUID();
	void SetObjGUID(int newVal);

protected:
	int objGUID;
	
	virtual void Init();

};

typedef vector<CObjBase*> pObjVector;
typedef map<string, CObjBase*> pObjMap;

//typedef pair<string, CObjBase*> pObj_Pair;

