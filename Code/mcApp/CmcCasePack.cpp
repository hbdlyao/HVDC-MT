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


void CmcCasePack::Release() 
{
	for each (pair<string, CmcCase *> vPair in pChildren)
	{
		delete vPair.second;
		vPair.second = nullptr;
	}

	pChildren.clear();

	//
	pDataVect.clear();

}

bool CmcCasePack::IsLeaf()
{

	return false;
}


void CmcCasePack::Add(string vID,CmcCase* vCase)
{
	pChildren[vID] = vCase;
}


void CmcCasePack::Remove(CmcCase* vItem)
{
	//pChildren.erase();
}


int CmcCasePack::ChildCount()
{
	return static_cast<int >(pChildren.size());
}

map<string, CmcCase*> CmcCasePack::Children()
{
	return pChildren;
}

CmcCase* CmcCasePack::NewCase(int vIndex, StrVector vNames, struct_mcResultData * vData)
{
	CmcCase * vCase;
	
	int vDeep = static_cast<int> (vNames.size()) - 1;
	string vID = vNames[vIndex];
	
	int vN = static_cast<int> (pChildren.count(vID));
	
	if (vN == 0)
	{//²»´æÔÚ vName	
	
		if (vIndex == vDeep)
			vCase = new CmcCase();
		else
			vCase = new CmcCasePack();
			//
		
		vCase->Init();
		vCase->DataName = vID;
	
		//
		Add(vID,vCase);
	
	}//if vN
	
	vCase = pChildren[vID];
	vCase->pDataVect.push_back(vData);
	

	if (vCase->IsLeaf())
		return vCase;
	else
	{
		CmcCasePack * vPack;
		vPack = dynamic_cast<CmcCasePack * >(vCase);
	
		return vPack->NewCase(vIndex + 1, vNames,vData);
	}
}



CmcCase* CmcCasePack::FindCase(int vIndex, StrVector vNames)
{

	CmcCase * vCase;
	
	int vDeep =static_cast<int> (vNames.size()) - 1;
	string vID = vNames[vIndex];
	
	vCase = pChildren[vID];
	
	if (vCase == nullptr)
		return nullptr;

	if (vCase->IsLeaf())
		return vCase;
	else
	{
		CmcCasePack * vPack;
		vPack = dynamic_cast<CmcCasePack * >(vCase);
	
		return vPack->FindCase(vIndex + 1, vNames);
	}

}