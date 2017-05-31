#pragma once

/**
* ≥Ã–Ú≥ı ºªØ
*/
class CmcInitApp
{
protected:
	static void Clear();
	static void Release();

public:
	static bool IsEditing;

	static int appState;
	static int State_Prev;
	static int State_Next;

	static void StateMachine();
	static void Init();

	static bool Start();
	static bool Logon();

	static bool Waiting();

	static bool New();
	static bool Open();
	static bool Edit();


	static bool  Closing();
	static bool  Close();
	static bool  Exit();

	static bool Save();
	static bool SaveAs();

	static bool IsSave();
	static void Help(int vID);

protected:
	CmcInitApp(const CmcInitApp& vInstance){

	}

	CmcInitApp(){

	}

	~CmcInitApp(){

	}

};

