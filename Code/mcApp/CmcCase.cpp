///////////////////////////////////////////////////////////
//  C3pCase.cpp
//  Implementation of the Class C3pCase
//  Created on:      26-5ÔÂ-2017 17:18:05
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcCase.h"


CmcCase::~ CmcCase()
{
	Release();
}


void CmcCase::Release()
{
	pDataVect.clear();
}

void CmcCase::Init()
{
}


bool CmcCase::IsLeaf()
{

	return true;
}


void CmcCase::Add(string vID, CmcCase* vCase)
{

}


void CmcCase::Remove(CmcCase* vCase)
{
	//
}


int CmcCase::datCount()
{
	return static_cast<int>(pDataVect.size());

}

