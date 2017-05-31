#pragma once


#include <string>

#include "CMyDefs.h"

#pragma comment(lib,"ws2_32.lib")
#import "c:\program files\common files\system\ado\msado15.dll" no_namespace rename("EOF","adoEOF"), rename("BOF","adoBOF")

using namespace std;

/**
 * Ado数据库
 */
class CMyRwAdo
{

protected:
	//数据库指针
	_ConnectionPtr pConnection = nullptr;

	//记录指针
	_RecordsetPtr pRecordset = nullptr;

	//命令指针
	_CommandPtr pCommand = nullptr;

	//存储过程中的参数
	_ParameterPtr pParams = nullptr;

	//StrTable dbfTable;

	string strConnect = "strConnect";

	string UserID = "";
	string Password = "";


public:
	~CMyRwAdo();


	/**
	 * StrTable dbfTable;
	 */
	virtual void InitDbf(string vDbf, string vUserID, string vPassword, string vSecurity);

	virtual bool IsEOF();
	//
	virtual bool IsOpen();
	//
	virtual bool OpenDBF();
	virtual bool CloseDBF();

	virtual bool ExecStoreProcess(string vSQL);

	//
	virtual bool OpenSQL(string vSQL);
	virtual bool ExecSQL(string vSQL);

	virtual bool CloseTBL();

	//
	virtual void GetFieldValue(string vFieldName, _variant_t & vValue);
	virtual void SetFieldValue(string vFieldName, _variant_t vValue);

	virtual int Record_RowCount();

	//
	virtual void Record_MoveNext();
	virtual void Record_Update();
	virtual void Record_AddNew();

	//
	virtual void BeginTrans();
	virtual void CommitTrans();
	virtual void RollbackTrans();
};


/**
 * Ado_MDB数据库
 */
class CMyRwAdo_MDB : public CMyRwAdo
{
public:
	virtual void InitDbf(string vDbf, string vUserID, string vPassword, string vSecurity);

};

class CMyRwAdo_Access : public CMyRwAdo
{
public:
	virtual void InitDbf(string vDbf, string vUserID, string vPassword, string vSecurity);

};
