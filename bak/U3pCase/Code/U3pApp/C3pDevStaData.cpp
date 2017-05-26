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


void C3pDevStaData::DataSelected(string  vCalName, string vCaseID, double vPdPercent)
{
	char vChar[6];
	sprintf_s(vChar, 6, "%-3.0f", vPdPercent);

	StrVector vNames;

	vNames.push_back(vCalName);
	vNames.push_back(vCaseID);
	vNames.push_back(vChar);

	//
	C3pCase * vData;

	vData = DataList.DataSelected(0, vNames);
	pStaData = &(vData->pStaData);

}

void C3pDevStaData::NewStaData(string vCalName, string vCaseID, double vPdPercent)
{
	char vChar[6];
	sprintf_s(vChar, 6, "%-3.0f", vPdPercent);

	StrVector vNames;

	vNames.push_back(vCalName);
	vNames.push_back(vCaseID);
	vNames.push_back(vChar);

	//
	C3pCase * vData;

	vData = DataList.NewStaData(0, vNames);

	vData->StationName = GetStationName();

	vData->Set_hCalName(vCalName);
	vData->Set_hCaseID(vCaseID);
	vData->Set_hPdPer(vPdPercent);

	//
	DataVect.push_back(vData);

}
