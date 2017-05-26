#pragma once

#include <vector>
#include <map>

using namespace std;

/**
 * 对象基类
 */
class CMyObjBase
{

public:
	CMyObjBase();
	virtual ~CMyObjBase();

	virtual void Clear();
	virtual void Release();

	int GetObjGUID();
	void SetObjGUID(int newVal);

protected:
	int objGUID;
	
	virtual void Init();

};

typedef vector<CMyObjBase*> pObjVector;
typedef map<string, CMyObjBase*> pObjMap;

//typedef pair<string, CMyObjBase*> pObj_Pair;

