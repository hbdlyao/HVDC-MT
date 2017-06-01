///////////////////////////////////////////////////////////
//  CmcMain.cpp
//  Implementation of the Class CmcMain
//  Created on:      25-5��-2017 6:55:56
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcMain.h"

#include "gbHead_mcApp.h"

#include "time.h"

#include <iostream>

void CmcMain::mcMain()
{
	//StrVector vStaNames = { "Sվ", "Kվ", "Pվ", };
	//mcCreateGrid(vStaNames);

	mcCalculateNormal();

	mcCalculate("�������mc����");

	//mcClose();

}

void CmcMain::DLLMain(string vDbfFile)
{
	mcInit(vDbfFile);

	mcLoad();

	mcCalculateNormal();

	mcCalculate("�������mc����");

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
	cout << "---��ʼmc����---";
	cout << sys_time1.wHour << "ʱ";
	cout << sys_time1.wMinute << "��";
	cout << sys_time1.wSecond << "��";
	cout << endl;


	CmcSolveMvc * vMvc;
	vMvc = new CmcSolveMvc();

	vMvc->Init(CmcVars::pmcHvdcGrid);
	vMvc->InitOrder(CmcVars::pmcOrder);

	vMvc->Run();


	SYSTEMTIME sys_time2;
	GetLocalTime(&sys_time2);
	cout << "---�������---";
	cout << sys_time2.wHour << "ʱ";
	cout << sys_time2.wMinute << "��";
	cout << sys_time2.wSecond << "��";
	//cout << sys_time2.wMilliseconds << "��";
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