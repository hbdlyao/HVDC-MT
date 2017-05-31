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

string C3pCase::Get_hStationName()
{

	return pStaData.StationName;
}

void C3pCase::Set_hStationName(string vCaseID)
{

	pStaData.StationName = vCaseID;
}

double C3pCase::Get_hPdPer()
{

	return pStaData.PdPer;
}


void C3pCase::Set_hPdPer(double vX)
{

	pStaData.PdPer = vX;
}

void C3pCase::Set_hUac(double vX)
{

	pStaData.Uac = vX;
}

double C3pCase::Get_hUac()
{

	return pStaData.Uac;
}

void C3pCase::Set_hUv(double vX)
{

	pStaData.Uv = vX;
}

double C3pCase::Get_hUv()
{

	return pStaData.Uv;
}

void C3pCase::Set_hUvN(double vX)
{

	pStaData.UvN = vX;
}

double C3pCase::Get_hUvN()
{

	return pStaData.UvN;
}

void C3pCase::Set_hId(double vX)
{

	pStaData.Id = vX;
}

double C3pCase::Get_hId()
{

	return pStaData.Id;
}

void C3pCase::Set_hTC(int vX)
{

	pStaData.TC = vX;
}

int C3pCase::Get_hTC()
{

	return pStaData.TC;
}

void C3pCase::Set_halphaOrgamma(double vX)
{

	pStaData.alphaOrgamma = vX;
}

double C3pCase::Get_halphaOrgamma()
{

	return pStaData.alphaOrgamma;
}

void C3pCase::Set_hmiu(double vX)
{

	pStaData.miu = vX;
}

double C3pCase::Get_hmiu()
{

	return pStaData.miu;
}

void C3pCase::Set_hNnom(double vX)
{

	pStaData.Nnom = vX;
}

double C3pCase::Get_hNnom()
{

	return pStaData.Nnom;
}