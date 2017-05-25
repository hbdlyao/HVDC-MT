#pragma once

#include "CmcRwMvc.h"

class CmcMvcs
{
public:	
	static void Init();
	static void Clear();
	static void Release();

	static void OnLoad(string vdbf);
	static void OnSave(string vdbf);

	static void OnLoadOrder(string vdbf);

	static void OnLoadResult(string vdbf);
	
protected:
	CmcMvcs(const CmcMvcs & theCmcMvcs) {};

	CmcMvcs() {};

	virtual ~CmcMvcs() {};


};

