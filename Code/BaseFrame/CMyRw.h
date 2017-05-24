#pragma once


#include "CMyRwAdo.h"

#include <string>

using namespace std;

class CRwDbf
{
public:
	virtual void OnLoad();
	virtual void OnSave();

	virtual void InitAdo(CRwAdo * vAdo);

	virtual void InitTable(string vtblName);
	virtual void InitType(int vtblType, int vDevType);

protected:
	
	string dbfName;
	CRwAdo* RwAdo;
	string tblName;
	int tblType;
	int devType;

	string SqlStr = "";
	string SqlParam = "";

public:
	static string GetString(string vX);
	static string GetString(int vX);
	static string GetString(double vX);

};
