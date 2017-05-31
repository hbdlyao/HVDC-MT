#pragma once

#include "CMyRwMvc.h"

class CMyMvcs
{
protected:
	CMyMvcs(const CMyMvcs& theInstance) {};

	CMyMvcs() {};	
    ~CMyMvcs() {};
	
public:

	static void Release();
	static void Clear();
	static void Init();

public:

	static void OnLoad(string vdbf);
	static void OnSave(string vdbf);

};


