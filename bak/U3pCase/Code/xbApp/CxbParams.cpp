///////////////////////////////////////////////////////////
//  CxbParams.cpp
//  Implementation of the Class CxbParams
//  Created on:      24-3ÔÂ-2017 20:55:58
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbParams.h"

string CxbParams::dbfFile = "mcDBF";
int CxbParams::xbStationCount=2;
int CxbParams::hMax = 60;
double CxbParams::Frequence = 50;

void CxbParams::Init()
{
	//AccessMDB
	//dbfFile = PRJFilePath + "xbDBF.accdb";
	dbfFile = "../../dbf/xbDBF.accdb";
}
