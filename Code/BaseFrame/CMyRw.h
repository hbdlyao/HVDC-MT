#pragma once


#include "CMyRwAdo.h"

#include <string>

using namespace std;

class CMyRwDbf
{
public:
	virtual void OnLoad();
	virtual void OnSave();

	virtual void InitAdo(CMyRwAdo * vAdo);

	virtual void InitTable(string vtblName);
	virtual void InitType(int vtblType, int vDevType);

protected:
	
	string dbfName;
	CMyRwAdo* RwAdo;
	string tblName;
	int tblType;
	int devType;

	string SqlStr = "";
	string SqlParam = "";

public:
	static string GetString(string vX);
	static string GetString(int vX, char* vfmt = "%f");
	static string GetString(double vX, char* vfmt = "%f");

};
