///////////////////////////////////////////////////////////
//  CHvdcApp.cpp
//  Implementation of the Class CHvdcApp
//  Created on:      24-3月-2017 20:41:13
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcApp.h"

#include "CHvdcParams.h"
#include "CHvdcMvcs.h"
#include "CHvdcVars.h"

int CHvdcApp::appState	    = app_Start;
int CHvdcApp::State_Prev	= app_Start;
int CHvdcApp::State_Next	= app_Start;


void CHvdcApp::Init()
{
	CHvdcParams::Init();
		
	CHvdcVars::Init();
	
	CHvdcMvcs::Init();

}

void CHvdcApp::Clear()
{
	//清空数据(子对象)
	CHvdcParams::Clear();
	CHvdcVars::Clear();
	CHvdcMvcs::Clear();

}

void CHvdcApp::Release()
{
	//清空数据表
	CHvdcVars::Release();	
	CHvdcMvcs::Release();
}

void CHvdcApp::StateMachine()
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

bool CHvdcApp::Close()
{
	bool vOk = true;
	//
	Save();
	
	//
	Clear();

	return vOk;

}

bool CHvdcApp::Closing()
{
	bool vOk = true;
	//
	Save();

	//
	Clear();

	return vOk;

}

bool CHvdcApp::Exit()
{
	bool vOk = true;

	Save();

	//
	Release();

	return vOk;

}


bool CHvdcApp::Start()
{
	return true;
}

bool CHvdcApp::Logon()
{
	return true;
}

bool CHvdcApp::Waiting()
{
	return true;
}



bool CHvdcApp::New()
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


bool CHvdcApp::Open(){

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

bool CHvdcApp::Edit()
{
	return true;
}


bool CHvdcApp::Save(){

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


bool CHvdcApp::SaveAs(){

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


bool CHvdcApp::IsSave(){

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


void CHvdcApp::Help(int vID){

	//vStr=gbcfg.helpPath+'Hvdc.hlp';
	//WinHelp(Application.MainForm.Handle,PChar(vStr),HELP_CONTEXT,vID);
}