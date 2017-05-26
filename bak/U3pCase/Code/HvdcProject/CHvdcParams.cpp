///////////////////////////////////////////////////////////
//  CHvdcParams.cpp
//  Implementation of the Class CHvdcParams
//  Created on:      24-3ÔÂ-2017 20:55:58
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcParams.h"

void CHvdcParams::Init()
{
	CMyParams::Init();

	CmcParams::Init();
	CxbParams::Init();
	C3pParams::Init();

	//
	//PRJFile = PRJFilePath + "mcDBF.accdb";

	PRJFile = "../../dbf/mcDBF.accdb";
}

