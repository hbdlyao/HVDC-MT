///////////////////////////////////////////////////////////
//  CMyObjTBL.cpp
//  Implementation of the Class CMyObjTBL
//  Created on:      20-5ÔÂ-2017 22:35:51
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CMyObjTBL.h"

/**
 * CMyObjTBL(CMyObjTBL & vTBL);
 */
CMyObjTBL::~CMyObjTBL()
{
	Release();
}


void CMyObjTBL::Release() 
{
	for each (CMyObjBase * vObj in pChildren)
	{
		delete vObj;
		vObj = nullptr;
	}

	pChildren.clear();
}

void CMyObjTBL::Clear()
{
	for each (CMyObjBase * vObj in pChildren)
	{
		delete vObj;
		vObj = nullptr;
	}

	pChildren.clear();
}

string CMyObjTBL::TypeToName(int vType)
{

	return "CMyObjTBL::TypeToName";
}


void CMyObjTBL::Init()
{

	tblName = "CMyObjTBL.tblname";
	tblType = -1;
}

void CMyObjTBL::Add(CMyObjBase* vItem)
{

	pChildren.push_back(vItem);
}


void CMyObjTBL::Remove(CMyObjBase* vItem)
{

	//children.removeElement( component );
}


int CMyObjTBL::ChildCount(){

	return static_cast<int >(pChildren.size());
}


CMyObjBase * CMyObjTBL::Child(int vIndex){

	if (vIndex < ChildCount())
		return pChildren[vIndex];
	else
		return nullptr;
}


pObjVector CMyObjTBL::Children(){

	return pChildren;
}


string CMyObjTBL::GetTblName(){

	return tblName;
}


void CMyObjTBL::SetTblName(string newVal){

	tblName = newVal;
}


int CMyObjTBL::GetTblType(){

	return tblType;
}


void CMyObjTBL::SetTblType(int newVal){

	tblType = newVal;
}