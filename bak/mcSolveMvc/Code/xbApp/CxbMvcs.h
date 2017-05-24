#pragma once

#include "CxbRwMvc.h"

class CxbMvcs
{
public:

	static CxbRwMvc *  pxbRwMvc;
		
	static void Init();
	static void Clear();
	static void Release();

	static void OnLoad(string vdbf);
	static void OnSave(string vdbf);
	
protected:
	CxbMvcs(const CxbMvcs & theCmcMvcs) {};

	CxbMvcs() {};

	virtual ~CxbMvcs() {};


};

