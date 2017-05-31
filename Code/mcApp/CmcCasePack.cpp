///////////////////////////////////////////////////////////
//  C3pCaseList.cpp
//  Implementation of the Class C3pCaseList
//  Created on:      26-5ÔÂ-2017 17:18:14
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcCasePack.h"


CmcCasePack::~CmcCasePack()
{
	Release();
}


void CmcCasePack::Clear()
{
	for each (pair<string, CmcCase *> vPair in pCaseMap)
	{
		delete vPair.second;
		vPair.second = nullptr;
	}
	
	pCaseMap.clear();

}


void CmcCasePack::Release(){

	for each (pair<string, CmcCase *> vPair in pCaseMap)
	{
		delete vPair.second;
		vPair.second = nullptr;
	}
	
	pCaseMap.clear();
}


bool CmcCasePack::IsLeaf(){

	return false;
}


void CmcCasePack::Add(CmcCase* vItem){

	//pChildren.push_back(vItem);
}


void CmcCasePack::Remove(CmcCase* vItem){

	//
}


int CmcCasePack::ChildCount()
{
	return static_cast<int >(pCaseMap.size());
}


CmcCase* CmcCasePack::NewCase(int vIndex, StrVector vNames){

	CmcCase * vData;
	
	int vDeep = static_cast<int> (vNames.size()) - 1;
	string vID = vNames[vIndex];
	
	int vN = static_cast<int> (pCaseMap.count(vID));
	
	if (vN == 0)
	{//²»´æÔÚ vName	
	
		if (vIndex == vDeep)
			vData = new CmcCase();
		else
			vData = new CmcCasePack();
			//
		
		vData->Init();
		vData->DataName = vID;
	
		//
		pCaseMap[vID] = vData;
		Add(vData);
	
	}//if vN
	
	vData = pCaseMap[vID];
	
	if (vData->IsLeaf())
		return vData;
	else
	{
		CmcCasePack * vList;
		vList = dynamic_cast<CmcCasePack * >(vData);
	
		return vList->NewCase(vIndex + 1, vNames);
	}
}


CmcCase* CmcCasePack::DataSelected(int vIndex, StrVector vNames){

	CmcCase * vData;
	
	int vDeep =static_cast<int> (vNames.size()) - 1;
	string vID = vNames[vIndex];
	
	vData = pCaseMap[vID];
	
	if (vData->IsLeaf())
		return vData;
	else
	{
		CmcCasePack * vList;
		vList = dynamic_cast<CmcCasePack * >(vData);
	
		return vList->DataSelected(vIndex + 1, vNames);
	}
}