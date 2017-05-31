///////////////////////////////////////////////////////////
//  CHvdcMvcs.cpp
//  Implementation of the Class CHvdcMvcs
//  Created on:      24-3月-2017 20:58:52
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
	//CmcVars::pmcOrder->CalName = "测试1495529378";

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
	cout << "---读入mc计算结果---";
	cout << sys_time1.wHour <<	"时";
	cout << sys_time1.wMinute << "分";
	cout << sys_time1.wSecond << "秒";
	cout<< endl;


	//
	CmcRwResultMvc* vRwMvc = new CmcRwResultMvc();

	vRwMvc->InitAdo(vdbf);
	vRwMvc->Init(vResult);
	vRwMvc->OnLoad(vdbf);

	delete vRwMvc;

	SYSTEMTIME sys_time2;
	GetLocalTime(&sys_time2);
	cout << "---读入结束---";
	cout << sys_time2.wHour	<<"时";
	cout << sys_time2.wMinute << "分";
	cout << sys_time2.wSecond << "秒";
	//cout << sys_time2.wMilliseconds << "秒";
	cout << endl;

	/*cout<< sys_time2.wHour - sys_time1.wHour;
	cout << "时" << sys_time2.wMinute - sys_time1.wMinute;
	cout << "分" << sys_time2.wSecond - sys_time1.wSecond << ".";
	cout << sys_time2.wMilliseconds - sys_time1.wMilliseconds << "秒";
	cout<< endl*/;

}

void CmcMvcs::OnSaveResult(string vdbf, CmcResult* vResult)
{
	SYSTEMTIME sys_time1;
	GetLocalTime(&sys_time1);
	cout << "---存储mc计算结果---";
	cout << sys_time1.wHour << "时";
	cout << sys_time1.wMinute << "分";
	cout << sys_time1.wSecond << "秒";
	cout << endl;


	//
	CmcRwResultMvc* vRwMvc = new CmcRwResultMvc();

	vRwMvc->InitAdo(vdbf);
	vRwMvc->Init(vResult);
	vRwMvc->OnSave(vdbf);

	delete vRwMvc;

	SYSTEMTIME sys_time2;
	GetLocalTime(&sys_time2);
	cout << "---存储结束---";
	cout << sys_time2.wHour << "时";
	cout << sys_time2.wMinute << "分";
	cout << sys_time2.wSecond << "秒";
	//cout << sys_time2.wMilliseconds << "秒";
	cout << endl;
}
