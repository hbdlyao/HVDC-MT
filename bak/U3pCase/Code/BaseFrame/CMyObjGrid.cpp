///////////////////////////////////////////////////////////
//  CMyObjGrid.cpp
//  Implementation of the Class CMyObjGrid
//  Created on:      20-5ÔÂ-2017 22:36:37
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CMyObjGrid.h"


CMyObjGrid::~CMyObjGrid()
{
	Clear();
}


string CMyObjGrid::TypeToName(int vType){

	return "CMyObjTBL::TypeToName";
}


void CMyObjGrid::Init()
{
}


void CMyObjGrid::Clear()
{

	for each (CMyObjTBL * vTBL in pChildren)
	{
		delete vTBL;
		vTBL = nullptr;
	}
	
	pChildren.clear();
}


void CMyObjGrid::Add(CMyObjTBL* vItem)
{
	pChildren.push_back(vItem);
}


void CMyObjGrid::Remove(CMyObjTBL* vItem)
{
	//children.removeElement( component );
}


int CMyObjGrid::ChildCount()
{

	return static_cast<int >(pChildren.size());
}


CMyObjTBL* CMyObjGrid::Child(int vIndex)
{

	if (vIndex < ChildCount())
		return pChildren[vIndex];
	else
		return nullptr;
}


pTBLVector CMyObjGrid::Children()
{
	return pChildren;
}
