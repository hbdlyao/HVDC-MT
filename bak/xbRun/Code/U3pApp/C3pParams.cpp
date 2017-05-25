///////////////////////////////////////////////////////////
//  C3pParams.cpp
//  Implementation of the Class C3pParams
//  Created on:      18-5ÔÂ-2017 8:36:07
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pParams.h"

string C3pParams::dbfFile;
int C3pParams::StationCount;
int C3pParams::hMax = 60;
double C3pParams::Frequence = 50;


void C3pParams::Init()
{
	//AccessMDB
	//dbfFile = PRJFilePath + "U3pDBF.accdb";
	dbfFile = "../../dbf/U3pDBF.accdb";
}