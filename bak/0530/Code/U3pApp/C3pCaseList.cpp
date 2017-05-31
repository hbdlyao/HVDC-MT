///////////////////////////////////////////////////////////
//  C3pCaseList.cpp
//  Implementation of the Class C3pCaseList
//  Created on:      26-5ÔÂ-2017 17:18:14
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pCaseList.h"


C3pCaseList::~C3pCaseList()
{
	Release();
}


void C3pCaseList::Clear()
{
	for each (pair<string, C3pCase *> vPair in pDataList)
	{
		delete vPair.second;
		vPair.second = nullptr;
	}
	
	pDataList.clear();

}


void C3pCaseList::Release(){

	for each (pair<string, C3pCase *> vPair in pDataList)
	{
		delete vPair.second;
		vPair.second = nullptr;
	}
	
	pDataList.clear();
}


bool C3pCaseList::IsLeaf(){

	return false;
}


void C3pCaseList::Add(C3pCase* vItem){

	//pChildren.push_back(vItem);
}


void C3pCaseList::Remove(C3pCase* vItem){

	//
}


int C3pCaseList::ChildCount(){

	//return static_cast<int >(pChildren.size());
	
	return static_cast<int >(pDataList.size());
}


C3pCase* C3pCaseList::NewStaData(int vIndex, StrVector vNames){

	C3pCase * vData;
	
	int vDeep = static_cast<int> (vNames.size()) - 1;
	string vID = vNames[vIndex];
	
	int vN = static_cast<int> (pDataList.count(vID));
	
	if (vN == 0)
	{//²»´æÔÚ vName	
	
		if (vIndex == vDeep)
			vData = new C3pCase();
		else
			vData = new C3pCaseList();
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
		C3pCaseList * vList;
		vList = dynamic_cast<C3pCaseList * >(vData);
	
		return vList->NewStaData(vIndex + 1, vNames);
	}
}


C3pCase* C3pCaseList::DataSelected(int vIndex, StrVector vNames){

	C3pCase * vData;
	
	int vDeep =static_cast<int> (vNames.size()) - 1;
	string vID = vNames[vIndex];
	
	vData = pDataList[vID];
	
	if (vData->IsLeaf())
		return vData;
	else
	{
		C3pCaseList * vList;
		vList = dynamic_cast<C3pCaseList * >(vData);
	
		return vList->DataSelected(vIndex + 1, vNames);
	}
}