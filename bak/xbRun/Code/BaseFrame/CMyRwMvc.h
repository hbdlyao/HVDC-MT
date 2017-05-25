///////////////////////////////////////////////////////////
//  CMyRwMvc.h
//  Implementation of the Class CMyRwMvc
//  Created on:      18-4ÔÂ-2017 18:14:29
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_9E4459A1_995B_4bbe_9EA9_BF5BDAFC6E16__INCLUDED_)
#define EA_9E4459A1_995B_4bbe_9EA9_BF5BDAFC6E16__INCLUDED_

#include "CMyRwAdo.h"
#include "CMyRwDev.h"

#include <string>

using namespace std;

class CMyRwMvc
{

protected:
	CMyRwAdo* RwAdo = nullptr;

	string dbfName;
	string tblName;
	int tblType;
	int devType;

public:
	virtual ~CMyRwMvc();

	virtual void InitAdo(string vDbf);

public:
	virtual void OnLoad(string vdbf);
	virtual void OnSave(string vdbf);

	virtual void OnLoad(int vType);
	virtual void OnSave(int vType);

protected:
	virtual void OnLoad();
	virtual void OnSave();

	virtual void doLoad();
	virtual void doSave();

	virtual void doLoad(int vType);
	virtual void doSave(int vType);

protected:
	virtual bool doOpenDBF();
	virtual bool doCloseDBF();

	virtual CMyRwDev * doNewRw(int vtblType);

protected:
	string SqlStr = "";
	string SqlParam = "";

public:
	static string GetString(string vX);
	static string GetString(int vX);
	static string GetString(double vX);
};

class CMyRwMvcAccess : public CMyRwMvc
{

public:
	virtual void InitAdo(string vDbf);

};
#endif // !defined(EA_9E4459A1_995B_4bbe_9EA9_BF5BDAFC6E16__INCLUDED_)
