#include "gbHead_App.h"

#include "CmcRwOrderMvc.h"

#include "time.h"


void mcTest(int vGnd)
{ 
	CmcSolveMvc * vMvc;

	vMvc = new CmcSolveMvc();
	vMvc->Init(CmcVars::pmcHvdcGrid);
	//vMvc->InitOrder();

	vMvc->Test(vGnd);

	delete vMvc;

}


void xbTest(int vGnd)
{
	CxbSolveMvc * vMvc;

	vMvc = new CxbSolveMvc();
	vMvc->Init(CxbVars::pxbHvdcGrid);
	//vMvc->InitOrder();

	vMvc->Test(vGnd);

	delete vMvc;

}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  mcCreateGrid
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.增加时间记录
// 改动时间:  2017/05/23
//************************************
void mcCalculate(string vCalName)
{	
	CmcOrder * vOrder;
	
	vOrder = new CmcOrder();
	vOrder->CalName = vCalName;
	vOrder->Init();

	CmcRwOrderMvc* vRwMvc=new CmcRwOrderMvc();

	vRwMvc->InitAdo(CmcParams::dbfFile);
	vRwMvc->Init(vOrder);
	vRwMvc->OnLoad(CmcParams::dbfFile);


	///////////////////////////////////////////
	SYSTEMTIME sys_time1;
	GetLocalTime(&sys_time1);
	cout <<"Time---"<< sys_time1.wYear << "年" << sys_time1.wMonth << "月" << sys_time1.wDay << "日" << sys_time1.wHour << "时" << sys_time1.wMinute << "分" << sys_time1.wSecond << "." << sys_time1.wMilliseconds << "秒" << "    星期" << sys_time1.wDayOfWeek << endl;
	///////////////////////////////////////////

	CmcSolveMvc * vSolveMvc;
	vSolveMvc = new CmcSolveMvc();

	vSolveMvc->Init(CmcVars::pmcHvdcGrid);
	vSolveMvc->InitOrder(vOrder);

	vSolveMvc->Run();

	///////////////////////////////////////////
	SYSTEMTIME sys_time2;
	GetLocalTime(&sys_time2);
	cout << "Time---" << "计算用时" << sys_time2.wHour - sys_time1.wHour << "时" << sys_time2.wMinute - sys_time1.wMinute << "分" << sys_time2.wSecond - sys_time1.wSecond << "." << sys_time2.wMilliseconds - sys_time1.wMilliseconds << "秒" << endl;
	///////////////////////////////////////////
	
	vSolveMvc->SaveResults();

	///////////////////////////////////////////
	SYSTEMTIME sys_time3;
	GetLocalTime(&sys_time3);
	cout << "Time---" << "总用时" << sys_time3.wHour - sys_time1.wHour << "时" << sys_time3.wMinute - sys_time1.wMinute << "分" << sys_time3.wSecond - sys_time1.wSecond << "." << sys_time3.wMilliseconds - sys_time1.wMilliseconds << "秒" << endl;
	///////////////////////////////////////////

	delete vRwMvc;
	delete vOrder;
	delete vSolveMvc;


}

void mcCalculateNormal()
{

	CmcOrder * vOrder = new CmcOrder();
	CmcSolveMvc * vMvc = new CmcSolveMvcNormal();

	vMvc->Init(CmcVars::pmcHvdcGrid);
	vMvc->InitOrder(vOrder);
	vMvc->Run();

	//vMvc->SaveResults();

	delete vMvc;

}

void xbCalculate()
{	
	//
	CxbSolveMvc * vMvc;

	//
	vMvc = new CxbSolveMvc();
	vMvc->Init(CxbVars::pxbHvdcGrid);
	vMvc->InitOrder();

	vMvc->Run();

	//
	delete vMvc;

}


//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  mcCreateGrid
// 改动者:    崔康生
// 改动类型:  新增
// 改动内容:  1.测试Grid创建
// 改动时间:  2017/05/23
//************************************
void mcCreateGrid()
{
	StrVector vStaNames = {
		"S站",
		"K站",
		"P站",
	};

	CmcHvdcGrid *vHvdc = CmcVars::pmcHvdcGrid;
	vHvdc->NewGrid(vStaNames);
}

void OnLoad()
{
	CmcMvcs::OnLoad(CmcParams::dbfFile);

	//CxbMvcs::OnLoad(CxbParams::dbfFile);

	//C3pMvcs::OnLoad(C3pParams::dbfFile);

};

void OnSave()
{
	//CmcMvcs::OnSave(CmcParams::dbfFile);

	//CxbMvcs::OnSave(CxbParams::dbfFile);

	//C3pMvcs::OnSave(C3pParams::dbfFile);
}

int main()
{
	CHvdcInitApp::Init();	
	CHvdcInitApp::Open();

	//
	OnLoad();
	///////////////////////////////////////////	

	//mcCreateGrid();

	//mcTest(Ground10);

	mcCalculateNormal();
	
	mcCalculate("测试" + std::to_string((unsigned int)time(0)));

	
	///////////////////////////////////////////
	
	//xbTest(Ground10);

	//xbCalculate();
	

	/////////////////////////
	OnSave();

	CHvdcInitApp::Exit();

	//
	cout << "End" << endl;

	system("pause"); 	
	
	/////////////////////////

}