#include "gbHead_App.h"

#include "time.h"


void zkTest(int vGnd)
{
	CxbMvcs::zkOnLoadOrder(CxbParams::dbfFile);

	CzkSolveMvc * vMvc;

	vMvc = new CzkSolveMvc();
	vMvc->Init(CxbVars::pxbHvdcGrid);
	vMvc->InitOrder(CxbVars::pzkOrder);

	vMvc->Test(vGnd);

	delete vMvc;

}

void lmTest()
{
	ClmSolveMvc * vMvc;

	vMvc = new ClmSolveMvc();
	vMvc->Init(CxbVars::pxbHvdcGrid);
	vMvc->InitOrder(CxbVars::plmOrder);

	vMvc->Run();

	delete vMvc;

}

void U3pTest(int vGnd)
{
	//C3pMvcs::OnLoadOrder(C3pParams::dbfFile);

	C3pSolveMvc * vMvc;

	vMvc = new C3pSolveMvc();
	vMvc->Init(C3pVars::pGrid);
	vMvc->InitOrder(C3pVars::p3pOrder);

	vMvc->Test(vGnd);

	delete vMvc;

}


void xbTest(int vGnd)
{
	CxbSolveMvc * vMvc;

	vMvc = new CxbSolveMvc();
	vMvc->Init(CxbVars::pxbHvdcGrid);
	vMvc->InitOrder(CxbVars::pxbOrder);

	vMvc->Test(vGnd);

	delete vMvc;

}


void xbCalculate()
{
	CxbMvcs::xbOnLoadOrder(CxbParams::dbfFile);
	
	CxbSolveMvc * vMvc;
	
	vMvc= new CxbSolveMvc();
	vMvc->Init(CxbVars::pxbHvdcGrid);
	vMvc->InitOrder(CxbVars::pxbOrder);

	vMvc->Run();

	//
	delete vMvc;

}


void mcTest(int vGnd)
{
	CmcSolveMvc * vMvc;

	vMvc = new CmcSolveMvc();
	vMvc->Init(CmcVars::pmcHvdcGrid);
	vMvc->InitOrder(CmcVars::pmcOrder);

	vMvc->Test(vGnd);

	delete vMvc;

}

//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  mcCreateGrid
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.����ʱ���¼
// �Ķ�ʱ��:  2017/05/23
//************************************
void mcCalculate(string vCalName)
{	
	CmcMvcs::OnLoadOrder(CmcParams::dbfFile);
	CmcVars::pmcOrder->CalName = vCalName;

	///////////////////////////////////////////
	SYSTEMTIME sys_time1;
	GetLocalTime(&sys_time1);
	cout <<"Time---"<< sys_time1.wYear << "��" << sys_time1.wMonth << "��" << sys_time1.wDay << "��" << sys_time1.wHour << "ʱ" << sys_time1.wMinute << "��" << sys_time1.wSecond << "." << sys_time1.wMilliseconds << "��" << "    ����" << sys_time1.wDayOfWeek << endl;
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

void mcCalculateNormal()
{
	CmcSolveMvc * vMvc;
	
	vMvc= new CmcSolveMvcNormal();
	vMvc->Init(CmcVars::pmcHvdcGrid);
	vMvc->InitOrder(CmcVars::pmcOrder);
	vMvc->Run();

	//vMvc->SaveResults();

	delete vMvc;

}


//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  mcCreateGrid
// �Ķ���:    �޿���
// �Ķ�����:  ����
// �Ķ�����:  1.����Grid����
// �Ķ�ʱ��:  2017/05/23
//************************************
void mcCreateGrid()
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

void OnLoad()
{
	CmcMvcs::OnLoad(CmcParams::dbfFile);

	CxbMvcs::OnLoad(CxbParams::dbfFile);

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

	//mcCalculateNormal();
	
	//mcCalculate("����" + std::to_string((unsigned int)time(0)));
	
	///////////////////////////////////////////
	
	//xbTest(Ground10);

	//xbCalculate();
	
	///////////////////////////////////////////

	//U3pTest(Ground10);

	/////////////////////////
	zkTest(Ground10);
	/////////////////////////
	OnSave();

	CHvdcInitApp::Exit();

	//
	cout << "End" << endl;

	system("pause"); 	
	
	/////////////////////////

}