///////////////////////////////////////////////////////////
//  CHvdcMvcs.cpp
//  Implementation of the Class CHvdcMvcs
//  Created on:      24-3��-2017 20:58:52
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcMvcs.h"
#include "CmcParams.h"
#include "CmcVars.h"

#include "CmcRwOrderMvc.h"
#include "CmcRwResultMvc.h"

#include <iostream>

void CmcMvcs::Init()
{			
}


void CmcMvcs::Clear()
{
}

void CmcMvcs::Release()
{		
}

void CmcMvcs::OnLoad(string vdbf)
{
	CmcRwMvc* vRwMvc;

	vRwMvc = new CmcRwMvc();
	vRwMvc->InitAdo(vdbf);
	vRwMvc->InitGrid(CmcVars::pmcHvdcGrid);

	vRwMvc->OnLoad(vdbf);

	delete vRwMvc;
}

void CmcMvcs::OnSave(string vdbf)
{
	CmcRwMvc* vRwMvc;

	vRwMvc = new CmcRwMvc();
	vRwMvc->InitAdo(vdbf);
	vRwMvc->InitGrid(CmcVars::pmcHvdcGrid);

	vRwMvc->OnSave(vdbf);

	delete vRwMvc;
}

void CmcMvcs::OnLoadOrder(string vdbf)
{
	//CmcVars::pmcOrder->CalName = "����1495529378";

	CmcRwOrderMvc* vRwMvc = new CmcRwOrderMvc();

	vRwMvc->InitAdo(vdbf);
	vRwMvc->Init(CmcVars::pmcOrder);
	vRwMvc->OnLoad(vdbf);

	delete vRwMvc;
}


void CmcMvcs::OnLoad_PRJ(string vdbf)
{
	CmcPRJ_RwMvc * vRwMvc;

	vRwMvc = new CmcPRJ_RwMvc();
	vRwMvc->InitAdo(CmcParams::PRJFile);

	vRwMvc->OnLoad(CmcParams::PRJFile);

	delete vRwMvc;
}

void CmcMvcs::OnSave_PRJ(string vdbf)
{
	CmcPRJ_RwMvc * vRwMvc;

	vRwMvc = new CmcPRJ_RwMvc();
	vRwMvc->InitAdo(CmcParams::PRJFile);

	vRwMvc->OnSave(CmcParams::PRJFile);

	delete vRwMvc;
}

void CmcMvcs::OnLoadResult(string vdbf, CmcResult* vResult)
{
	SYSTEMTIME sys_time1;
	GetLocalTime(&sys_time1);
	cout << "---����mc������---";
	cout << sys_time1.wHour <<	"ʱ";
	cout << sys_time1.wMinute << "��";
	cout << sys_time1.wSecond << "��";
	cout<< endl;


	//
	CmcRwResultMvc* vRwMvc = new CmcRwResultMvc();

	vRwMvc->InitAdo(vdbf);
	vRwMvc->Init(vResult);
	vRwMvc->OnLoad(vdbf);

	delete vRwMvc;

	SYSTEMTIME sys_time2;
	GetLocalTime(&sys_time2);
	cout << "---�������---";
	cout << sys_time2.wHour	<<"ʱ";
	cout << sys_time2.wMinute << "��";
	cout << sys_time2.wSecond << "��";
	//cout << sys_time2.wMilliseconds << "��";
	cout << endl;

	/*cout<< sys_time2.wHour - sys_time1.wHour;
	cout << "ʱ" << sys_time2.wMinute - sys_time1.wMinute;
	cout << "��" << sys_time2.wSecond - sys_time1.wSecond << ".";
	cout << sys_time2.wMilliseconds - sys_time1.wMilliseconds << "��";
	cout<< endl*/;

}

void CmcMvcs::OnSaveResult(string vdbf, CmcResult* vResult)
{
	SYSTEMTIME sys_time1;
	GetLocalTime(&sys_time1);
	cout << "---�洢mc������---";
	cout << sys_time1.wHour << "ʱ";
	cout << sys_time1.wMinute << "��";
	cout << sys_time1.wSecond << "��";
	cout << endl;


	//
	CmcRwResultMvc* vRwMvc = new CmcRwResultMvc();

	vRwMvc->InitAdo(vdbf);
	vRwMvc->Init(vResult);
	vRwMvc->OnSave(vdbf);

	delete vRwMvc;

	SYSTEMTIME sys_time2;
	GetLocalTime(&sys_time2);
	cout << "---�洢����---";
	cout << sys_time2.wHour << "ʱ";
	cout << sys_time2.wMinute << "��";
	cout << sys_time2.wSecond << "��";
	//cout << sys_time2.wMilliseconds << "��";
	cout << endl;
}
