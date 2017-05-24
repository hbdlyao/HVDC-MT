#pragma once

#include "CHvdcPRJ_RwMvc.h"

#include "CMyMvcs.h"
#include "CmcMvcs.h"
#include "CxbMvcs.h"
#include "C3pMvcs.h"

class CHvdcMvcs
{
public:
	static CHvdcPRJ_RwMvc *  PRJ_RwMvc;

	static void Init();
	static void Clear();
	static void Release();

	static void OnLoad();
	static void OnSave();

	
protected:
	CHvdcMvcs(const CHvdcMvcs& theCmcMvcs) {};

	CHvdcMvcs() {};

	virtual ~CHvdcMvcs() {};
};

