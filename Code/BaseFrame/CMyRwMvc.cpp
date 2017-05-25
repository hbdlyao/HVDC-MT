///////////////////////////////////////////////////////////
//  CMyRwMvc.cpp
//  Implementation of the Class CMyRwMvc
//  Created on:      18-4ÔÂ-2017 18:14:29
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CMyRwMvc.h"
#include "CMyFunc.h"

#include <iostream>

CMyRwMvc::~CMyRwMvc()
{
	//
	delete RwAdo;
	RwAdo = nullptr;
}


void CMyRwMvc::InitAdo(string vDbf)
{
	dbfName = vDbf;

	if (RwAdo==nullptr)
		RwAdo = new CMyRwAdo();

	RwAdo->InitDbf(dbfName, "", "", "false");

}

CMyRwDev * CMyRwMvc::doNewRw(int vtblType)
{
	return nullptr;
}

void CMyRwMvc::OnLoad(string vdbf)
{
	InitAdo(vdbf);

	OnLoad();
}

void CMyRwMvc::OnSave(string vdbf)
{
	InitAdo(vdbf);

	OnSave();
}



void CMyRwMvc::OnLoad()
{

	try
	{
		if (doOpenDBF())
		{
			doLoad();
	
			//
			doCloseDBF();
	
		}//if 
	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}
}

void CMyRwMvc::OnSave()
{

	try
	{
		if (doOpenDBF())
		{
			
			doSave();
	
			//
			doCloseDBF();
	
		}//if 
	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}
}

void CMyRwMvc::doLoad()
{

}


void CMyRwMvc::doSave()
{

}


void CMyRwMvc::OnLoad(int vtblType)
{
	try
	{
		if (doOpenDBF())
		{
			doLoad(vtblType);

			//
			doCloseDBF();

		}//if 
	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}
}


void CMyRwMvc::OnSave(int vtblType)
{
	try
	{
		if (doOpenDBF())
		{

			doSave(vtblType);

			//
			doCloseDBF();

		}//if 
	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}
}

void CMyRwMvc::doLoad(int vtblType)
{
	CMyRwDev * vRw;

	vRw = doNewRw(vtblType);

	vRw->OnLoad();

	delete vRw;

}


void CMyRwMvc::doSave(int vtblType)
{

}


bool CMyRwMvc::doOpenDBF()
{
	bool vOk;
	
	vOk=RwAdo->OpenDBF();
	
	return vOk;
}


bool CMyRwMvc::doCloseDBF()
{
	bool vOk;
	
	vOk=RwAdo->CloseDBF();
	
	return vOk;
}



string CMyRwMvc::GetString(string vStr)
{
	return CMyFunc::GetString(vStr);
}

string CMyRwMvc::GetString(double vX)
{
	return CMyFunc::GetString(vX);
}


string CMyRwMvc::GetString(int vX)
{
	return CMyFunc::GetString(vX);
}



void CMyRwMvcAccess::InitAdo(string vDbf)
{
	dbfName = vDbf;
	
	if (RwAdo == nullptr)
		RwAdo = new CMyRwAdo_Access();

	RwAdo->InitDbf(dbfName, "", "", "false");
}

