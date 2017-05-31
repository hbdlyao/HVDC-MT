///////////////////////////////////////////////////////////
//  CmcMain.cpp
//  Implementation of the Class CmcMain
//  Created on:      25-5月-2017 6:55:56
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcMain.h"

#include "gbHead_mcApp.h"

#include "time.h"

#include <iostream>

void CmcMain::mcMain()
{
	//StrVector vStaNames = { "S站", "K站", "P站", };
	//mcCreateGrid(vStaNames);

	mcCalculateNormal();

	mcCalculate("南网多端mc计算");

	mcClose();

}

void CmcMain::DLLMain(string vDbfFile)
{
	mcInit(vDbfFile);

	mcLoad();

	mcCalculateNormal();

	mcCalculate("南网多端mc计算");

	mcClose();
}

void CmcMain::mcCalculate(string vCalName)
{
	CmcVars::pmcOrder->CalName = vCalName;
	CmcMvcs::OnLoadOrder(CmcParams::dbfFile);

	///////////////////////////////////////////
	SYSTEMTIME sys_time1;
	GetLocalTime(&sys_time1);
	cout << "Time---" << sys_time1.wYear << "年" << sys_time1.wMonth << "月" << sys_time1.wDay << "日" << sys_time1.wHour << "时" << sys_time1.wMinute << "分" << sys_time1.wSecond << "." << sys_time1.wMilliseconds << "秒" << "    星期" << sys_time1.wDayOfWeek << endl;
	///////////////////////////////////////////

	CmcSolveMvc * vMvc;
	vMvc = new CmcSolveMvc();

	vMvc->Init(CmcVars::pmcHvdcGrid);
	vMvc->InitOrder(CmcVars::pmcOrder);

	vMvc->Run();

	///////////////////////////////////////////
	SYSTEMTIME sys_time2;
	GetLocalTime(&sys_time2);
	cout << "Time---" << "计算用时" << sys_time2.wHour - sys_time1.wHour << "时" << sys_time2.wMinute - sys_time1.wMinute << "分" << sys_time2.wSecond - sys_time1.wSecond << "." << sys_time2.wMilliseconds - sys_time1.wMilliseconds << "秒" << endl;
	///////////////////////////////////////////

	vMvc->SaveResults();

	///////////////////////////////////////////
	SYSTEMTIME sys_time3;
	GetLocalTime(&sys_time3);
	cout << "Time---" << "总用时" << sys_time3.wHour - sys_time1.wHour << "时" << sys_time3.wMinute - sys_time1.wMinute << "分" << sys_time3.wSecond - sys_time1.wSecond << "." << sys_time3.wMilliseconds - sys_time1.wMilliseconds << "秒" << endl;
	///////////////////////////////////////////

	delete vMvc;

}

void CmcMain::mcCalculateNormal()
{
	CmcSolveMvc * vMvc;

	vMvc = new CmcSolveMvcNormal();
	vMvc->Init(CmcVars::pmcHvdcGrid);
	vMvc->InitOrder(CmcVars::pmcOrder);
	vMvc->Run();

	//vMvc->SaveResults();

	delete vMvc;

}

void CmcMain::mcCreateGrid(StrVector vStaNames)
{
	CmcHvdcGrid *vHvdc = CmcVars::pmcHvdcGrid;

	vHvdc->Clear();
	vHvdc->NewGrid(vStaNames);
}



void CmcMain::mcInit(string vDBFFile)
{
	CmcInitApp::Init();

	CmcParams::dbfFile = vDBFFile;
	CmcParams::PRJFile = vDBFFile;

	CmcInitApp::Open();
}
void CmcMain::mcLoad()
{
	CmcMvcs::OnLoad(CmcParams::dbfFile);
}
void CmcMain::mcClose()
{
	CmcMvcs::OnSave(CmcParams::dbfFile);

	CmcInitApp::Exit();
}