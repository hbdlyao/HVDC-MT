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
	//mcCreateGrid();

	//mcTest(Ground10);

	mcCalculateNormal();

	//mcCalculate("����" + std::to_string((unsigned int)time(0)));

	mcCalculate("����");

}

void CmcMain::mcTest(int vGnd)
{
	CmcSolveMvc * vMvc;

	vMvc = new CmcSolveMvc();
	vMvc->Init(CmcVars::pmcHvdcGrid);
	vMvc->InitOrder(CmcVars::pmcOrder);

	vMvc->Test(vGnd);

	delete vMvc;

}

void CmcMain::mcCalculate(string vCalName)
{
	CmcMvcs::OnLoadOrder(CmcParams::dbfFile);
	CmcVars::pmcOrder->CalName = vCalName;

	///////////////////////////////////////////
	SYSTEMTIME sys_time1;
	GetLocalTime(&sys_time1);
	cout << "Time---" << sys_time1.wYear << "��" << sys_time1.wMonth << "��" << sys_time1.wDay << "��" << sys_time1.wHour << "ʱ" << sys_time1.wMinute << "��" << sys_time1.wSecond << "." << sys_time1.wMilliseconds << "��" << "    ����" << sys_time1.wDayOfWeek << endl;
	///////////////////////////////////////////

	CmcSolveMvc * vMvc;
	vMvc = new CmcSolveMvc();

	vMvc->Init(CmcVars::pmcHvdcGrid);
	vMvc->InitOrder(CmcVars::pmcOrder);

	vMvc->Run();

	///////////////////////////////////////////
	SYSTEMTIME sys_time2;
	GetLocalTime(&sys_time2);
	cout << "Time---" << "������ʱ" << sys_time2.wHour - sys_time1.wHour << "ʱ" << sys_time2.wMinute - sys_time1.wMinute << "��" << sys_time2.wSecond - sys_time1.wSecond << "." << sys_time2.wMilliseconds - sys_time1.wMilliseconds << "��" << endl;
	///////////////////////////////////////////

	vMvc->SaveResults();

	///////////////////////////////////////////
	SYSTEMTIME sys_time3;
	GetLocalTime(&sys_time3);
	cout << "Time---" << "����ʱ" << sys_time3.wHour - sys_time1.wHour << "ʱ" << sys_time3.wMinute - sys_time1.wMinute << "��" << sys_time3.wSecond - sys_time1.wSecond << "." << sys_time3.wMilliseconds - sys_time1.wMilliseconds << "��" << endl;
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


void CmcMain::mcCreateGrid()
{
	StrVector vStaNames =
	{
		"Sվ",
		"Kվ",
		"Pվ",
	};

	CmcHvdcGrid *vHvdc = CmcVars::pmcHvdcGrid;

	vHvdc->Clear();
	vHvdc->NewGrid(vStaNames);

	//delete vHvdc;

}


