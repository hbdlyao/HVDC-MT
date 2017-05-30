///////////////////////////////////////////////////////////
//  CmcParams.cpp
//  Implementation of the Class CmcParams
//  Created on:      24-3ÔÂ-2017 20:55:58
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcParams.h"

string CmcParams::dbfFile = "mcDBF";

int CmcParams::mcStationCount=2;


void CmcParams::Init()
{
	//CMyParams::Init();

	//AccessMDB
	//dbfFile = PRJFilePath + "mcDBF.accdb";

	dbfFile = "../../dbf/mcDBF.accdb";

}
