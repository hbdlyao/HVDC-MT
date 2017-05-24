#pragma once

#include <string>
#include <vector>

using namespace std;

class CCalculateBase
{
public:
	virtual ~CCalculateBase();
	virtual void Clear();
	virtual void Release();

};

typedef vector<CCalculateBase*> pCalVector;

