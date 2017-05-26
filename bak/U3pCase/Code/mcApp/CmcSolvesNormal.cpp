///////////////////////////////////////////////////////////
//  CmcSolvesNormal.cpp
//  Implementation of the Class CmcSolvesNormal
//  Created on:      21-5ÔÂ-2017 0:48:10
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcSolvesNormal.h"


/**
 * CmcSolvesNormal
 */
void CmcSolvesNormal::Run(){

	doPrepare();
	
	doSovleDcNet();
	
	doCalStation();
}


void CmcSolvesNormal::SaveNorml(){

	for each (CmcCalculate * vCal in pChildren)
	{
		vCal->SaveNormal();
	}
}


void CmcSolvesNormal::doCalStation(){

	pmcProfile->CalStation_N();
	
	pmcProfile->CalACSide();
}