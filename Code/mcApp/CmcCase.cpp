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

}

void CmcCase::Clear() 
{
	//ClearData();
}

void CmcCase::ClearData()
{
	for each (struct_mcResultData * vCase in pDataVect)
	{
		delete vCase;
		vCase = nullptr;
	}

	pDataVect.clear();

}

void CmcCase::Init()
{
	InitData();
}

void CmcCase::InitData()
{
}


bool CmcCase::IsLeaf()
{

	return true;
}


void CmcCase::Add(CmcCase* vItem)
{

}


void CmcCase::Remove(CmcCase* vItem)
{
	//
}

