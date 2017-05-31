#pragma once

#include "CHvdcPRJ_RwMvc.h"

#include "CMyMvcs.h"
#include "CmcMvcs.h"
#include "CxbMvcs.h"
#include "C3pMvcs.h"

class CHvdcMvcs
{
public:
	static void Init();
	static void Clear();
	static void Release();

	static void OnLoad();
	static void OnSave();

	static void OnLoad_PRJ(string vdbf);
	static void OnSave_PRJ(string vdbf);

	
protected:
	CHvdcMvcs(const CHvdcMvcs& theCmcMvcs) {};

	CHvdcMvcs() {};

	virtual ~CHvdcMvcs() {};
};

