///////////////////////////////////////////////////////////
//  CObjTBL.cpp
//  Implementation of the Class CObjTBL
//  Created on:      20-5ÔÂ-2017 22:35:51
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CObjTBL.h"

/**
 * CObjTBL(CObjTBL & vTBL);
 */
CObjTBL::~CObjTBL()
{
	Release();
}


void CObjTBL::Release() 
{
	for each (CObjBase * vObj in pChildren)
	{
		delete vObj;
		vObj = nullptr;
	}

	pChildren.clear();
}

void CObjTBL::Clear()
{
	for each (CObjBase * vObj in pChildren)
	{
		delete vObj;
		vObj = nullptr;
	}

	pChildren.clear();
}

string CObjTBL::TypeToName(int vType)
{

	return "CObjTBL::TypeToName";
}


void CObjTBL::Init()
{

	tblName = "CObjTBL.tblname";
	tblType = -1;
}

void CObjTBL::Add(CObjBase* vItem)
{

	pChildren.push_back(vItem);
}


void CObjTBL::Remove(CObjBase* vItem)
{

	//children.removeElement( component );
}


int CObjTBL::ChildCount(){

	return static_cast<int >(pChildren.size());
}


CObjBase * CObjTBL::Child(int vIndex){

	if (vIndex < ChildCount())
		return pChildren[vIndex];
	else
		return nullptr;
}


pObjVector CObjTBL::Children(){

	return pChildren;
}


string CObjTBL::GetTblName(){

	return tblName;
}


void CObjTBL::SetTblName(string newVal){

	tblName = newVal;
}


int CObjTBL::GetTblType(){

	return tblType;
}


void CObjTBL::SetTblType(int newVal){

	tblType = newVal;
}