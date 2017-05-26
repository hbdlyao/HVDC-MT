
#include "gbHead_App.h"

#include "gbHead_Main.h"


void OnLoad()
{
	//CmcMvcs::OnLoadResult(CmcParams::dbfFile);

	CmcMvcs::OnLoad(CmcParams::dbfFile);

	CxbMvcs::OnLoad(CxbParams::dbfFile);

	C3pMvcs::OnLoad(C3pParams::dbfFile);

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

	//////////////����·//////////
	//CmcMain::mcMain();

	//////////ֱ��г��////////////
	//CxbMain::xbMain();
	
	//////////�迹ɨ��///////////////
	//CxbMain::zkTest(Ground10);

	//////////��·ģ��///////////////
	//CxbMain::lmTest();

	////////////////��������ѹԴ/////
	C3pMain::U3pMain();

	/////////////////////////

	OnSave();


	/////////////////////////

	CHvdcInitApp::Exit();

	//
	cout << "End" << endl;

	system("pause"); 	
	
	/////////////////////////

}