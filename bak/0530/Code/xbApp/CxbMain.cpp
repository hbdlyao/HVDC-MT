///////////////////////////////////////////////////////////
//  CxbMain.cpp
//  Implementation of the Class CxbMain
//  Created on:      25-5ÔÂ-2017 7:03:11
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbMain.h"
#include "gbHead_xbApp.h"

#include "time.h"

#include <iostream>


void CxbMain::xbMain()
{
	//xbCreateGrid();

	xbTest(Ground10);
	//xbCalculate("²âÊÔ");

	//zkTest(Ground10);
	//zkCalculate("²âÊÔ");

	//lmTest();
	
}

void CxbMain::xbCreateGrid()
{
	StrVector vStaNames =
	{
		"SÕ¾",
		"KÕ¾",
		"PÕ¾",
	};

	CxbHvdcGrid *vHvdc = CxbVars::pxbHvdcGrid;

	vHvdc->Clear();
	
	//vHvdc->NewGrid(vStaNames);

	//delete vHvdc;

}


void CxbMain::xbTest(int vGnd)
{
	CxbMvcs::xbOnLoadOrder(CxbParams::dbfFile);

	CxbSolveMvc * vMvc;
		
	vMvc = new CxbSolveMvc();
	vMvc->Init(CxbVars::pxbHvdcGrid);
	vMvc->InitOrder(CxbVars::pxbOrder);
	
	vMvc->Test(vGnd);
	
	delete vMvc;
}


void CxbMain::xbCalculate(string vCalName)
{
	CxbMvcs::xbOnLoadOrder(CxbParams::dbfFile);

	CxbVars::pxbOrder->CalName = vCalName;
	
	CxbSolveMvc * vMvc;

	vMvc = new CxbSolveMvc();
	
	vMvc->Init(CxbVars::pxbHvdcGrid);
	vMvc->InitOrder(CxbVars::pxbOrder);
	
	vMvc->Run();
	
	//vMvc->SaveResults();
	

	delete vMvc;
}


void CxbMain::zkCalculate(string vCalName)
{
	CxbMvcs::zkOnLoadOrder(CxbParams::dbfFile);

	CxbVars::pzkOrder->CalName = vCalName;

	CzkSolveMvc * vMvc;

	vMvc = new CzkSolveMvc();
	vMvc->Init(CxbVars::pxbHvdcGrid);
	vMvc->InitOrder(CxbVars::pzkOrder);

	vMvc->Run();

	delete vMvc;

}


void CxbMain::zkTest(int vGnd)
{
	CxbMvcs::zkOnLoadOrder(CxbParams::dbfFile);

	CzkSolveMvc * vMvc;

	vMvc = new CzkSolveMvc();
	vMvc->Init(CxbVars::pxbHvdcGrid);
	vMvc->InitOrder(CxbVars::pzkOrder);

	vMvc->Test(vGnd);

	delete vMvc;

}

void CxbMain::lmTest()
{
	ClmSolveMvc * vMvc;

	vMvc = new ClmSolveMvc();
	vMvc->Init(CxbVars::pxbHvdcGrid);
	vMvc->InitOrder(CxbVars::plmOrder);

	vMvc->Run();

	delete vMvc;

}
