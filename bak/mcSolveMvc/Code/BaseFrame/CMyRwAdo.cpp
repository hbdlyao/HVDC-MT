///////////////////////////////////////////////////////////
//  CMyRwAdo.cpp
//  Implementation of the Class CRwAdo
//  Created on:      31-3月-2017 11:02:24
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CMyRwAdo.h"
#include "CMyFunc.h"

#include <iostream>


CRwAdo::~CRwAdo()
{
	CloseDBF();
}


/**
 * StrTable dbfTable;
 */
void CRwAdo::InitDbf(string vDbf, string vUserID, string vPassword, string vSecurity)
{

}

bool CRwAdo::IsEOF()
{
	return static_cast<bool>(pRecordset->adoEOF);

}

bool CRwAdo::IsOpen()
{
	bool vOk;

	vOk = (pConnection != nullptr);
	//
	if (vOk)
		vOk=vOk && (pConnection->State & adStateOpen);

	//
	return vOk;

}


bool CRwAdo::OpenDBF()
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


bool CRwAdo::CloseDBF()
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


bool CRwAdo::ExecSQL(string vSQL)
{
	HRESULT vhr = S_FALSE;


	try
	{
		if (IsOpen())
		{
			//BeginTrans();

			//vSQL = "select * from MCCAcSystem";

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


bool CRwAdo::OpenSQL(string vSQL)
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



bool CRwAdo::CloseTBL()
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

void CRwAdo::GetFieldValue(string vName, _variant_t & vValue)
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

void CRwAdo::SetFieldValue(string vName, _variant_t vValue)
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

int CRwAdo::Record_RowCount()
{
	return pRecordset->GetRecordCount();
}

void CRwAdo::Record_MoveNext()
{
	pRecordset->MoveNext();
}

void CRwAdo::Record_Update()
{
	pRecordset->Update();
}

void CRwAdo::Record_AddNew()
{
	pRecordset->AddNew();
}

void CRwAdo::BeginTrans()
{
	pConnection->BeginTrans();
}

void CRwAdo::CommitTrans()
{
	pConnection->CommitTrans();
}

void CRwAdo::RollbackTrans()
{
	pConnection->RollbackTrans();
}

////////////////////////////////
void CRwAdo_MDB::InitDbf(string vDbf, string vUserID, string vPassword, string vSecurity)
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
void CRwAdo_Access::InitDbf(string vDbf, string vUserID, string vPassword, string vSecurity)
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

