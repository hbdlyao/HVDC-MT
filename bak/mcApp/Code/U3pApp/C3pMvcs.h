#pragma once

#include "C3pRw.h"
#include "C3pRwMvc.h"

class C3pMvcs
{

public:
	static C3pRwMvc* pRwMvc;

	static void Init();
	static void Clear();
	static void Release();

public:
	static void OnLoad(string vdbf);
	static void OnSave(string vdbf);

	static void OnLoadOrder(string vdbf);

protected:
	C3pMvcs(const C3pMvcs& theC3pMvcs){}
	C3pMvcs(){}
	virtual ~C3pMvcs(){}

};
