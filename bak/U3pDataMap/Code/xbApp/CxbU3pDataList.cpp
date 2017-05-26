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


void CxbU3pDataList::Release()
{
	for each (pair<string, CxbU3pData *> vPair in pDataList)
	{
		delete vPair.second;
		vPair.second = nullptr;
	}

	pDataList.clear();
}


void CxbU3pDataList::Clear()
{
	for each (pair<string, CxbU3pData *> vPair in pDataList)
	{
		delete vPair.second;
		vPair.second = nullptr;
	}

	pDataList.clear();

}

bool CxbU3pDataList::IsLeaf()
{
	return false;
}


void CxbU3pDataList::Add(CxbU3pData* vItem)
{

	//pChildren.push_back(vItem);
}


void CxbU3pDataList::Remove(CxbU3pData* vItem)
{

	//
}


int CxbU3pDataList::ChildCount()
{
	//return static_cast<int >(pChildren.size());

	return static_cast<int >(pDataList.size());
}


CxbU3pData * CxbU3pDataList::NewU3pData(int vIndex, StrVector vNames)
{
	CxbU3pData * vData;

	int vDeep = static_cast<int> (vNames.size()) - 1;
	string vID = vNames[vIndex];

	int vN = static_cast<int> (pDataList.count(vID));

	if (vN == 0)
	{//²»´æÔÚ vName	

		if (vIndex == vDeep)
			vData = new CxbU3pData();
		else
			vData = new CxbU3pDataList();
			//
		
		vData->Init();
		vData->DataName = vID;

		//
		pDataList[vID] = vData;
		Add(vData);

	}//if vN

	vData = pDataList[vID];

	if (vData->IsLeaf())
		return vData;
	else
	{
		CxbU3pDataList * vList;
		vList = dynamic_cast<CxbU3pDataList * >(vData);

		return vList->NewU3pData(vIndex + 1, vNames);
	}

}



CxbU3pData * CxbU3pDataList::DataSelected(int vIndex, StrVector vNames)
{
	CxbU3pData * vData;

	int vDeep =static_cast<int> (vNames.size()) - 1;
	string vID = vNames[vIndex];

	vData = pDataList[vID];

	if (vData->IsLeaf())
		return vData;
	else
	{
		CxbU3pDataList * vList;
		vList = dynamic_cast<CxbU3pDataList * >(vData);

		return vList->DataSelected(vIndex + 1, vNames);
	}	

}
