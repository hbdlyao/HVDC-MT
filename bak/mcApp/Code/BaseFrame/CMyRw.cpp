///////////////////////////////////////////////////////////
//  CMyRw.cpp
//  Implementation of the Class CRwDbf
//  Created on:      02-4ÔÂ-2017 15:37:52
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CMyRw.h"
#include "CMyFunc.h"


#include <iostream>

void CRwDbf::InitAdo(CRwAdo * vAdo)
{
	RwAdo = vAdo;
}

void CRwDbf::InitTable(string vtblName)
{
	tblName = vtblName;
}

void CRwDbf::InitType(int vtblType, int vDevType)
{
	tblType = vtblType;
	devType = vDevType;
}

string CRwDbf::GetString(string vStr)
{
	return CMyFunc::GetString(vStr);
}

string CRwDbf::GetString(double vX)
{
	return CMyFunc::GetString(vX);
}


string CRwDbf::GetString(int vX)
{
	return CMyFunc::GetString(vX);
}


void CRwDbf::OnLoad() 
{

}


void CRwDbf::OnSave()
{

}

