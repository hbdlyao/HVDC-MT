///////////////////////////////////////////////////////////
//  CMyRwAdo.cpp
//  Implementation of the Class CMyRwAdo
//  Created on:      31-3月-2017 11:02:24
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CMyRwAdo.h"
#include "CMyFunc.h"

#include <iostream>


CMyRwAdo::~CMyRwAdo()
{
	CloseDBF();
}


/**
 * StrTable dbfTable;
 */
void CMyRwAdo::InitDbf(string vDbf, string vUserID, string vPassword, string vSecurity)
{

}

bool CMyRwAdo::IsEOF()
{
	return static_cast<bool>(pRecordset->adoEOF);

}

bool CMyRwAdo::IsOpen()
{
	bool vOk;

	vOk = (pConnection != nullptr);
	//
	if (vOk)
		vOk=vOk && (pConnection->State & adStateOpen);

	//
	return vOk;

}


bool CMyRwAdo::OpenDBF()
{
	_bstr_t vStrConnect;
	_bstr_t vUserID;
	_bstr_t vPassword;

	HRESULT vhr=S_FALSE;

	//
	::CoInitialize(NULL);
	
	try
	{
		//vhr = pConnection.CreateInstance(__uuidof(Connection));
		vhr = pConnection.CreateInstance("ADODB.Connection");
		
		//连接数据库  
		vStrConnect = _bstr_t(strConnect.c_str());
		vUserID		= _bstr_t(UserID.c_str());
		vPassword	= _bstr_t(Password.c_str());

		//
		if (vhr ==S_OK)
			vhr=pConnection->Open(vStrConnect, vUserID, vPassword, adModeUnknown);
				
	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}

	//
	return (vhr==S_OK);
}


bool CMyRwAdo::CloseDBF()
{
	HRESULT vhr = S_FALSE;

	try
	{
		if (pRecordset != nullptr)
			if (pRecordset->State != adStateClosed)
				pRecordset->Close();

		if (pCommand != nullptr)
			if (pCommand->State != adStateClosed)
				pCommand->Release();
	
		if (pConnection != nullptr)
			if (pConnection->State != adStateClosed)
				pConnection->Close();


		//
		pConnection = nullptr;
		pRecordset = nullptr;
		pCommand = nullptr;

	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}

	
	//
	::CoUninitialize();

	//
	return (vhr == S_OK);

}

bool CMyRwAdo::ExecStoreProcess(string vSQL)
{
	
	HRESULT vhr = S_FALSE;

	try
	{
		if (IsOpen())
		{
			//BeginTrans();

			pCommand.CreateInstance(__uuidof(Command));
			pCommand->ActiveConnection = pConnection;
			pCommand->CommandType = adCmdStoredProc;
			pCommand->CommandText = _bstr_t(vSQL.c_str());

			//设置PLSQLRSet属性(如果存储过程输出参数不是记录集，忽略此步骤)
			//pCommand->Properties->GetItem("PLSQLRSet")->Value = true;

			vhr = pCommand->Execute(NULL, NULL, adCmdStoredProc | adExecuteNoRecords);

			//CommitTrans();

		}//if
	}//try
	catch (_com_error & vErr)
	{
		//RollbackTrans();

		cout << vErr.Description() << endl;

	}


	return (vhr == S_OK);

}

bool CMyRwAdo::ExecSQL(string vSQL)
{
	HRESULT vhr = S_FALSE;

	try
	{
		if (IsOpen())
		{
			//BeginTrans();

			pCommand.CreateInstance(__uuidof(Command));
			pCommand->ActiveConnection = pConnection;
			pCommand->CommandText = _bstr_t(vSQL.c_str());
			
			vhr= pCommand->Execute(NULL, NULL, adCmdText | adExecuteNoRecords);

			//CommitTrans();

		}//if
	}//try
	catch (_com_error & vErr)
	{
		//RollbackTrans();

		cout << vErr.Description() << endl;

	}


	return (vhr == S_OK);

}


bool CMyRwAdo::OpenSQL(string vSQL)
{
	HRESULT vhr= S_FALSE;


	try
	{
		if (IsOpen())
			vhr = pRecordset.CreateInstance("ADODB.Recordset");

		//if (vhr == S_OK)
		//	pRecordset->CursorLocation = adUseClient;

		if (vhr == S_OK)
			vhr = pRecordset->Open(_variant_t(vSQL.c_str()), _variant_t((IDispatch*)pConnection, true), adOpenStatic, adLockOptimistic, adCmdText);

	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}
	
	//
	return (vhr == S_OK);

}



bool CMyRwAdo::CloseTBL()
{
	HRESULT vhr = S_FALSE;

	try
	{
		if (pRecordset != nullptr)
			if (pRecordset->State != adStateClosed)
				pRecordset->Close();

		//
		pRecordset = nullptr;

	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}

	return (vhr == S_OK);

}

void CMyRwAdo::GetFieldValue(string vName, _variant_t & vValue)
{
	_bstr_t vFieldName;

	try
	{
		vFieldName = _bstr_t(vName.c_str());

		vValue=pRecordset->Fields->Item[vFieldName]->Value;	
		
	}
	catch (_com_error & vErr)
	{
		cout << "   " + vFieldName + "---" + vErr.Description() << endl;
	}

	//


}

void CMyRwAdo::SetFieldValue(string vName, _variant_t vValue)
{
	//RwAdo->pRecordset->PutCollect(_variant_t("DevicID"), vValue);


	_bstr_t vFieldName;

	try
	{		
		vFieldName = _bstr_t(vName.c_str());

		pRecordset->Fields->Item[vFieldName]->Value = vValue;

	}
	catch (_com_error & vErr)
	{
		cout << "   "+vFieldName+"---"+vErr.Description() << endl;
	}
	
	//
}

int CMyRwAdo::Record_RowCount()
{
	return pRecordset->GetRecordCount();
}

void CMyRwAdo::Record_MoveNext()
{
	pRecordset->MoveNext();
}

void CMyRwAdo::Record_Update()
{
	pRecordset->Update();
}

void CMyRwAdo::Record_AddNew()
{
	pRecordset->AddNew();
}

void CMyRwAdo::BeginTrans()
{
	pConnection->BeginTrans();
}

void CMyRwAdo::CommitTrans()
{
	pConnection->CommitTrans();
}

void CMyRwAdo::RollbackTrans()
{
	pConnection->RollbackTrans();
}

////////////////////////////////
void CMyRwAdo_MDB::InitDbf(string vDbf, string vUserID, string vPassword, string vSecurity)
{
	
	UserID = vUserID;
	Password = vPassword;
	
	strConnect = "Provider=Microsoft.Jet.OLEDB.4.0 ; Persist Security Info= ";

	//strConnect = "Provider = Microsoft.ACE.OLEDB.12.0; Persist Security Info= ";
	strConnect = strConnect + vSecurity;
	strConnect = strConnect + "; Data Source= ";
	strConnect = strConnect + vDbf;
	
	
	/*
	strConnect = "Provider = Microsoft.ACE.OLEDB.12.0; Persist Security Info= ";
	strConnect = strConnect + vSecurity;
	strConnect = strConnect + "; Driver = { Microsoft Access Driver(*.mdb, *.accdb) } " ;
	strConnect = strConnect + "; DBQ = " ;
	strConnect = strConnect + vDbf ;
	*/

}

////////////////////////////////
void CMyRwAdo_Access::InitDbf(string vDbf, string vUserID, string vPassword, string vSecurity)
{

	UserID = vUserID;
	Password = vPassword;

	//strConnect = "Provider=Microsoft.Jet.OLEDB.4.0 ; Persist Security Info= ";

	strConnect = "Provider = Microsoft.ACE.OLEDB.12.0; Persist Security Info= ";
	strConnect = strConnect + vSecurity;
	strConnect = strConnect + "; Data Source= ";
	strConnect = strConnect + vDbf;

	/*
	strConnect = "Provider = Microsoft.ACE.OLEDB.12.0; Persist Security Info= ";
	strConnect = strConnect + vSecurity;
	strConnect = strConnect + "; Driver = { Microsoft Access Driver(*.mdb, *.accdb) } " ;
	strConnect = strConnect + "; DBQ = " ;
	strConnect = strConnect + vDbf ;
	*/

}

