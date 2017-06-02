
#include "gbHead_App.h"

#include "gbHead_Main.h"


void OnLoad()
{
	//CmcMvcs::OnLoadResult(CmcParams::dbfFile,CmcVars::pmcResult);
	//CmcVars::pmcResult->NewCase();
	//system("pause");		
	//CmcMvcs::OnSaveResult(CmcParams::dbfFile, CmcVars::pmcResult);
	//system("pause");
	
	//CmcMvcs::OnLoad(CmcParams::dbfFile);

	//CxbMvcs::OnLoad(CxbParams::dbfFile);

	C3pMvcs::OnLoad(C3pParams::dbfFile);

	//system("pause");

};

void OnSave()
{
	//CmcMvcs::OnSave(CmcParams::dbfFile);

	//CxbMvcs::OnSave(CxbParams::dbfFile);

	//C3pMvcs::OnSave(C3pParams::dbfFile);
}

void mcDLL()
{
	/*
	HINSTANCE hInst = LoadLibraryA("../Dll/mcApp.dll");
	typedef void(*pFun)();
	pFun mcMain = (pFun)GetProcAddress(hInst, "mcMain");

	mcMain();

	FreeLibrary(hInst);
	*/
}

int main()
{
	CHvdcApp::Init();	
	CHvdcApp::Open();

	//
	OnLoad();

	//////////////主回路//////////
	//CmcMain::mcMain();

	//////////直流谐波////////////
	//CxbMain::xbMain();
	
	//////////阻抗扫描///////////////
	//CxbMain::zkTest(Ground10);

	//////////线路模型///////////////
	//CxbMain::lmTest();

	////////////////三脉动电压源/////
	C3pMain::U3pMain();

	/////////////////////////

	OnSave();


	/////////////////////////

	CHvdcApp::Exit();

	//
	cout << "End" << endl;

	system("pause"); 	
	
	/////////////////////////

}