///////////////////////////////////////////////////////////
//  CObjGrid.cpp
//  Implementation of the Class CObjGrid
//  Created on:      20-5ÔÂ-2017 22:36:37
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CObjGrid.h"


CObjGrid::~CObjGrid()
{
	Clear();
}


string CObjGrid::TypeToName(int vType){

	return "CObjTBL::TypeToName";
}


void CObjGrid::Init()
{
}


void CObjGrid::Clear()
{

	for each (CObjTBL * vTBL in pChildren)
	{
		delete vTBL;
		vTBL = nullptr;
	}
	
	pChildren.clear();
}


void CObjGrid::Add(CObjTBL* vItem)
{
	pChildren.push_back(vItem);
}


void CObjGrid::Remove(CObjTBL* vItem)
{
	//children.removeElement( component );
}


int CObjGrid::ChildCount()
{

	return static_cast<int >(pChildren.size());
}


CObjTBL* CObjGrid::Child(int vIndex)
{

	if (vIndex < ChildCount())
		return pChildren[vIndex];
	else
		return nullptr;
}


pTBLVector CObjGrid::Children()
{
	return pChildren;
}
