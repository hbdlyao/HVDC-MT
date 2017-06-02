///////////////////////////////////////////////////////////
//  C3pMain.cpp
//  Implementation of the Class C3pMain
//  Created on:      25-5��-2017 7:03:35
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pMain.h"
#include "gbHead_3pApp.h"

#include "CmcMvcs.h"

void C3pMain::U3pMain()
{
	CmcResult * vResult=new CmcResult();

	vResult->CalName = "�������mc����";

	CmcMvcs::OnLoadResult(C3pParams::dbfFile, vResult);

	/////
	
	U3pCalculate("U3pTest",vResult);

	//U3pTest("����" + std::to_string((unsigned int)time(0)));

	delete vResult;

}

void C3pMain::U3pCalculate(string vCalName, CmcResult * vResult)
{
	SYSTEMTIME sys_time1;
	GetLocalTime(&sys_time1);
	cout << "��ʼU3p����---";
	cout << sys_time1.wHour << "ʱ";
	cout << sys_time1.wMinute << "��";
	cout << sys_time1.wSecond << "��";
	cout << endl;

	//////
	C3pMvcs::OnLoadOrder(C3pParams::dbfFile);
	C3pVars::p3pOrder->CalName = vCalName;


	C3pSolveMvc * vMvc;

	vMvc = new C3pSolveMvc();
	vMvc->Init(C3pVars::pGrid);
	vMvc->InitOrder(C3pVars::p3pOrder);

	vMvc->Run(vResult);

	delete vMvc;


	SYSTEMTIME sys_time2;
	GetLocalTime(&sys_time2);
	cout << "�������---";
	cout << sys_time2.wHour << "ʱ";
	cout << sys_time2.wMinute << "��";
	cout << sys_time2.wSecond << "��";
	//cout << sys_time2.wMilliseconds << "��";
	cout << endl;

}

