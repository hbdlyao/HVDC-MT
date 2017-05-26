///////////////////////////////////////////////////////////
//  C3pCase.cpp
//  Implementation of the Class C3pCase
//  Created on:      26-5ÔÂ-2017 17:18:05
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pCase.h"


C3pCase::~ C3pCase()
{
	Release();
}


void C3pCase::Release()
{

}

void C3pCase::Clear() 
{
	//ClearData();
}

void C3pCase::ClearData()
{

}

void C3pCase::Init()
{
	InitData();
}

void C3pCase::InitData()
{
}


bool C3pCase::IsLeaf()
{

	return true;
}


void C3pCase::Add(C3pCase* vItem)
{

}


void C3pCase::Remove(C3pCase* vItem)
{
	//
}


string C3pCase::Get_hCalName()
{

	return pStaData.CalName;
}


void C3pCase::Set_hCalName(string vName)
{

	pStaData.CalName = vName;
}


string C3pCase::Get_hCaseID()
{

	return pStaData.CaseID;
}


void C3pCase::Set_hCaseID(string vCaseID)
{

	pStaData.CaseID = vCaseID;
}


double C3pCase::Get_hPdPer()
{

	return pStaData.PdPer;
}


void C3pCase::Set_hPdPer(double vX)
{

	pStaData.PdPer = vX;
}
