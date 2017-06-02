///////////////////////////////////////////////////////////
//  C3pMain.cpp
//  Implementation of the Class C3pMain
//  Created on:      25-5月-2017 7:03:35
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pMain.h"
#include "gbHead_3pApp.h"

#include "CmcMvcs.h"

void C3pMain::U3pMain()
{
	CmcResult * vResult=new CmcResult();

	vResult->CalName = "南网多端mc计算";

	CmcMvcs::OnLoadResult(C3pParams::dbfFile, vResult);

	/////
	
	U3pCalculate("U3pTest",vResult);

	//U3pTest("测试" + std::to_string((unsigned int)time(0)));

	delete vResult;

}

void C3pMain::U3pCalculate(string vCalName, CmcResult * vResult)
{
	SYSTEMTIME sys_time1;
	GetLocalTime(&sys_time1);
	cout << "开始U3p计算---";
	cout << sys_time1.wHour << "时";
	cout << sys_time1.wMinute << "分";
	cout << sys_time1.wSecond << "秒";
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
	cout << "计算结束---";
	cout << sys_time2.wHour << "时";
	cout << sys_time2.wMinute << "分";
	cout << sys_time2.wSecond << "秒";
	//cout << sys_time2.wMilliseconds << "秒";
	cout << endl;

}

