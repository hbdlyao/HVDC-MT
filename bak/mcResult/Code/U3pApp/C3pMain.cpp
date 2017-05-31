///////////////////////////////////////////////////////////
//  C3pMain.cpp
//  Implementation of the Class C3pMain
//  Created on:      25-5ÔÂ-2017 7:03:35
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pMain.h"
#include "gbHead_3pApp.h"

void C3pMain::U3pMain()
{
	//xbCreateGrid();

	U3pTest(Ground10);

	//U3pTest("²âÊÔ" + std::to_string((unsigned int)time(0)));

}

void C3pMain::U3pTest(int vGnd)
{
	C3pMvcs::OnLoadOrder(C3pParams::dbfFile);

	C3pSolveMvc * vMvc;

	vMvc = new C3pSolveMvc();
	vMvc->Init(C3pVars::pGrid);
	vMvc->InitOrder(C3pVars::p3pOrder);

	vMvc->Test(vGnd);

	delete vMvc;

}

void C3pMain::U3pCalculate(string vCalName)
{
	C3pMvcs::OnLoadOrder(C3pParams::dbfFile);
	C3pVars::p3pOrder->CalName = vCalName;


	C3pSolveMvc * vMvc;

	vMvc = new C3pSolveMvc();
	vMvc->Init(C3pVars::pGrid);
	vMvc->InitOrder(C3pVars::p3pOrder);

	vMvc->Run();

	delete vMvc;

}

