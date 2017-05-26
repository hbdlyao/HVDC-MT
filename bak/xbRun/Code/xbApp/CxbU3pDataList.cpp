///////////////////////////////////////////////////////////
//  CxbU3pDataList.cpp
//  Implementation of the Class CxbU3pDataList
//  Created on:      25-5ÔÂ-2017 15:03:42
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbU3pDataList.h"




CxbU3pDataList::~CxbU3pDataList()
{
	Release();
}

void CxbU3pDataList::Clear()
{	
	for each (CxbU3pData * vData in pChildren)
	{
		vData->Clear();
	}
	
	//pChildren.clear();
}


void CxbU3pDataList::Release()
{
	//
	for each (CxbU3pData * vData in pChildren)
	{
		delete vData;
		vData = nullptr;
	}
	
	pChildren.clear();
}


bool CxbU3pDataList::IsLeaf()
{
	return false;
}


void CxbU3pDataList::Add(CxbU3pData* vItem)
{

	pChildren.push_back(vItem);
}


void CxbU3pDataList::Remove(CxbU3pData* vItem)
{

	//
}


int CxbU3pDataList::ChildCount()
{
	return static_cast<int >(pChildren.size());
}


CxbU3pData* CxbU3pDataList::Child(int vIndex)
{

	if (vIndex < ChildCount())
		return dynamic_cast<CxbU3pData *>(pChildren[vIndex]);
	else
		return nullptr;
}

pU3pDataList CxbU3pDataList::Children()
{
	return pChildren;
}
