///////////////////////////////////////////////////////////
//  C3pDevStaData.cpp
//  Implementation of the Class C3pDevStaData
//  Created on:      18-5ÔÂ-2017 11:51:00
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pDevStaData.h"

C3pDevStaData::~C3pDevStaData()
{
}

void C3pDevStaData::Init()
{
	SetStaCount(1);
	SetDotCount(0);

	pStaData = nullptr;

}


void C3pDevStaData::SetStationData(struct_mcResultData * vData)
{
	if (GetStationName()==vData->StationName)
		pStaData = vData;

}


void C3pDevStaData::SetCaseID(string Val)
{
	strcpy_s(pStaData->CaseID, Val.c_str());
}

void C3pDevStaData::SetCalName(string Val)
{
	strcpy_s(pStaData->CalName, Val.c_str());
}


void C3pDevStaData::SetPdPer(double Val)
{
	pStaData->PdPer = Val;
}

void C3pDevStaData::SetUac(double Val)
{
	pStaData->Uac = Val;
}

void C3pDevStaData::SetUv(double Val)
{
	pStaData->Uv = Val;
}

void C3pDevStaData::SetUvN(double Val)
{
	pStaData->Uv_N = Val;
}

void C3pDevStaData::SetId(double Val)
{
	pStaData->Id = Val;
}

void C3pDevStaData::SetTC(int Val)
{
	pStaData->TC = Val;
}

void C3pDevStaData::SetalphaOrgamma(double Val)
{
	pStaData->alphaOrgamma = Val;
}

void C3pDevStaData::Setmiu(double Val)
{
	pStaData->miu = Val;
}

void C3pDevStaData::SetNnom(double Val)
{
	pStaData->Tk_N = Val;
}

string C3pDevStaData::GetCaseID()
{
	return pStaData->CaseID;
}

string C3pDevStaData::GetCalName()
{
	return pStaData->CalName;
}

double C3pDevStaData::GetPdPer()
{
	return pStaData->PdPer;
}

double C3pDevStaData::GetUac()
{
	return pStaData->Uac;
}

double C3pDevStaData::GetUv()
{
	return pStaData->Uv;
}

double C3pDevStaData::GetUvN()
{
	return pStaData->Uv_N;
}

double C3pDevStaData::GetId()
{
	return pStaData->Id;
}

int C3pDevStaData::GetTC()
{
	return pStaData->TC;
}

double C3pDevStaData::GetalphaOrgamma()
{
	return pStaData->alphaOrgamma;
}

double C3pDevStaData::Getmiu()
{
	return pStaData->miu;
}

double C3pDevStaData::GetNnom()
{
	return pStaData->Tk_N;
}

