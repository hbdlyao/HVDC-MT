///////////////////////////////////////////////////////////
//  CMyRw.cpp
//  Implementation of the Class CMyRwDbf
//  Created on:      02-4ÔÂ-2017 15:37:52
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CMyRw.h"
#include "CMyFunc.h"


#include <iostream>

void CMyRwDbf::InitAdo(CMyRwAdo * vAdo)
{
	RwAdo = vAdo;
}

void CMyRwDbf::InitTable(string vtblName)
{
	tblName = vtblName;
}

void CMyRwDbf::InitType(int vtblType, int vDevType)
{
	tblType = vtblType;
	devType = vDevType;
}

string CMyRwDbf::GetString(string vStr)
{
	return CMyFunc::GetString(vStr);
}

string CMyRwDbf::GetString(double vX, char* vfmt)
{
	return CMyFunc::GetString(vX, vfmt);
}


string CMyRwDbf::GetString(int vX, char* vfmt)
{
	return CMyFunc::GetString(vX, vfmt);
}


void CMyRwDbf::OnLoad() 
{

}


void CMyRwDbf::OnSave()
{

}

