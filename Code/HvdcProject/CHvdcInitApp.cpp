///////////////////////////////////////////////////////////
//  CHvdcInitApp.cpp
//  Implementation of the Class CHvdcInitApp
//  Created on:      24-3月-2017 20:41:13
//  Original author: Administrator
///////////////////////////////////////////////////////////


#include "CHvdcInitApp.h"

#include "gbHead_App.h"


int CHvdcInitApp::appState	    = app_Start;
int CHvdcInitApp::State_Prev	= app_Start;
int CHvdcInitApp::State_Next	= app_Start;


void CHvdcInitApp::Init()
{
	CHvdcParams::Init();	
	
	CHvdcVars::Init();

	//
	CHvdcMvcs::Init();

}

void CHvdcInitApp::Clear(){
	//清空数据(子对象)

	CHvdcVars::Clear();
	CHvdcMvcs::Clear();

}

void CHvdcInitApp::Release()
{
	//清空数据表

	CHvdcVars::Release();
	
	CHvdcMvcs::Release();


}

void CHvdcInitApp::StateMachine()
{
	bool vOk;

	switch (appState)
	{
	case app_Start:
		vOk=Start();
		if (vOk)
		{
			State_Prev = app_Start;
			appState = app_Logon;
		}
		break;

	case app_Logon:
		vOk = Logon();
		if (vOk)
		{
			State_Prev = app_Logon;
			appState = app_Waiting;
		}
		else
			appState = State_Prev;

		break;

	case app_Waiting:
		State_Prev = app_Waiting;
		Waiting();
		break;

	case app_New:
		vOk = New();

		if (vOk)
		{
			State_Prev = app_New;
			appState = app_Edit;
		}
		else
			appState = State_Prev;

		break;

	case app_Open:
		vOk = Open();

		if (vOk)
		{
			State_Prev = app_Open;
			appState = app_Edit;
		}
		else
			appState = State_Prev;

		break;

	
	case app_Edit:
		State_Prev = app_Edit;
		Edit();
		
		break;

	case app_Close:
		vOk = Close();

		if (vOk)
			appState = app_Waiting;
		else
			appState = State_Prev;

		break;

	case app_Exit:		
		vOk = Close();

		if (!vOk)
			appState = State_Prev;

		break;

	case app_Closing:
		vOk=Save();

		if (vOk) appState = State_Next;
		else appState = State_Prev;

		break;

	}//switch
}

bool CHvdcInitApp::Close()
{
	bool vOk = true;
	//
	Save();
	
	//
	Clear();

	return vOk;

}

bool CHvdcInitApp::Closing()
{
	bool vOk = true;
	//
	Save();

	//
	Clear();

	return vOk;

}

bool CHvdcInitApp::Exit()
{
	bool vOk = true;

	Save();

	//
	Release();

	return vOk;

}


bool CHvdcInitApp::Start()
{
	return true;
}

bool CHvdcInitApp::Logon()
{
	return true;
}

bool CHvdcInitApp::Waiting()
{
	return true;
}



bool CHvdcInitApp::New()
{

	bool vOk=true;
	return vOk;
	/*
		vOk=gbShowMvc.ShowNew();
		if vOk then
		  begin
		    gbcfg.IsEditing=true;
		  end;
		
		Result=vOk;
	*/
}


bool CHvdcInitApp::Open(){

	bool vOk = true;

	//
	CHvdcMvcs::OnLoad();

	//
	return vOk;
	/*
		vOk=gbShowMvc.ShowOpen();//svag
		
		if vOk then
		  begin
		    vFile=gbCfg.PRJFile;
		    //
		    gbPRJMVC.OnLoad();
		    //
		    gbRw.OnLoad();
		
		    gbCfg.IsExist=true;
		    gbcfg.IsEditing=true;
		
		  end;
		
		Result=vOk;
	*/
}

bool CHvdcInitApp::Edit()
{
	return true;
}


bool CHvdcInitApp::Save(){

	bool vOk = true;

	CHvdcMvcs::OnSave();

	return vOk;
	/*
	
		if gbCfg.IsExist then
		  vOk=gbShowMvc.ShowSave()
		else
		  vOk=gbShowMvc.ShowSaveAs();
		
		/////////////////////
		if vOk then
		 begin
		   vFile=gbCfg.PRJFile;
		   if not FileExists(vFile) then
		     NewPRJFile(vFile);
		
		   //
		   gbPrjMvc.OnSave();
		   //
		   //gbRw.OnSave();    //2013-4-3 by yao
		
		   //
		   gbCfg.IsExist=true;
		
		 end;
		
		result=vOk;
	*/
}


bool CHvdcInitApp::SaveAs(){

	bool vOk = true;

	//
	CHvdcMvcs::OnSave();


	return vOk;
	/*
		vOk=gbShowMvc.ShowSaveAs();
		if vOk then
		 begin
		   vFile=gbCfg.PRJFile;
		   if not FileExists(vFile) then
		     NewPRJFile(vFile);
		   //
		   gbPrjMvc.OnSave(vFile);
		   //
		   gbRw.OnSave();
		
		 end;
		
		result=vOk;
	*/
}


bool CHvdcInitApp::IsSave(){

	bool vOk = true;
	return vOk;
	/*
		if gbPrjMvc.IsEditing then
		  begin
		    vRes=msg_Question('将要退出程序，是否保存数据？');//,'提示',MB_DEFBUTTON1);
		
		    case vRes of
		      mrYes   :   gbCFG.IsContinue=true;
		      mrNo     :  gbCFG.IsContinue=true;
		      mrCancel :  gbCFG.IsContinue=false;
		    end;
		
		  end;//if
		
		//
		result=(vRes=mrYes);
	*/
}


void CHvdcInitApp::Help(int vID){

	//vStr=gbcfg.helpPath+'Hvdc.hlp';
	//WinHelp(Application.MainForm.Handle,PChar(vStr),HELP_CONTEXT,vID);
}