///////////////////////////////////////////////////////////
//  CRwMvc.cpp
//  Implementation of the Class CRwMvc
//  Created on:      18-4ÔÂ-2017 18:14:29
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CMyRwMvc.h"
#include "CMyFunc.h"

#include <iostream>

CRwMvc::~CRwMvc()
{
	//
	delete RwAdo;
	RwAdo = nullptr;
}


void CRwMvc::InitAdo(string vDbf)
{
	dbfName = vDbf;

	if (RwAdo==nullptr)
		RwAdo = new CRwAdo();

	RwAdo->InitDbf(dbfName, "", "", "false");

}

CRwDev * CRwMvc::doNewRw(int vtblType)
{
	return nullptr;
}

void CRwMvc::OnLoad(string vdbf)
{
	InitAdo(vdbf);

	OnLoad();
}

void CRwMvc::OnSave(string vdbf)
{
	InitAdo(vdbf);

	OnSave();
}



void CRwMvc::OnLoad()
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

void CRwMvc::OnSave()
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

void CRwMvc::doLoad()
{

}


void CRwMvc::doSave()
{

}


void CRwMvc::OnLoad(int vtblType)
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


void CRwMvc::OnSave(int vtblType)
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

void CRwMvc::doLoad(int vtblType)
{
	CRwDev * vRw;

	vRw = doNewRw(vtblType);

	vRw->OnLoad();

	delete vRw;

}


void CRwMvc::doSave(int vtblType)
{

}


bool CRwMvc::doOpenDBF()
{
	bool vOk;
	
	vOk=RwAdo->OpenDBF();
	
	return vOk;
}


bool CRwMvc::doCloseDBF()
{
	bool vOk;
	
	vOk=RwAdo->CloseDBF();
	
	return vOk;
}



string CRwMvc::GetString(string vStr)
{
	return CMyFunc::GetString(vStr);
}

string CRwMvc::GetString(double vX)
{
	return CMyFunc::GetString(vX);
}


string CRwMvc::GetString(int vX)
{
	return CMyFunc::GetString(vX);
}



void CRwMvcAccess::InitAdo(string vDbf)
{
	dbfName = vDbf;
	
	if (RwAdo == nullptr)
		RwAdo = new CRwAdo_Access();

	RwAdo->InitDbf(dbfName, "", "", "false");
}

