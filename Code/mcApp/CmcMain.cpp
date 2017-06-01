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

	//mcClose();

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
	CmcVars::pmcOrder->Init();
	CmcMvcs::OnLoadOrder(CmcParams::dbfFile);	
	

	///////////////////////////////////////////
	SYSTEMTIME sys_time1;
	GetLocalTime(&sys_time1);
	cout << "---开始mc计算---";
	cout << sys_time1.wHour << "时";
	cout << sys_time1.wMinute << "分";
	cout << sys_time1.wSecond << "秒";
	cout << endl;


	CmcSolveMvc * vMvc;
	vMvc = new CmcSolveMvc();

	vMvc->Init(CmcVars::pmcHvdcGrid);
	vMvc->InitOrder(CmcVars::pmcOrder);

	vMvc->Run();


	SYSTEMTIME sys_time2;
	GetLocalTime(&sys_time2);
	cout << "---计算结束---";
	cout << sys_time2.wHour << "时";
	cout << sys_time2.wMinute << "分";
	cout << sys_time2.wSecond << "秒";
	//cout << sys_time2.wMilliseconds << "秒";
	cout << endl;
	///////////////////////////////////////////

	system("pause");

	CmcMvcs::OnSaveResult(CmcParams::dbfFile,vMvc->pmcResult);

	//
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