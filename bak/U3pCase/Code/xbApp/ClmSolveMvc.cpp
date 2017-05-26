///////////////////////////////////////////////////////////
//  ClmSolveMvc.cpp
//  Implementation of the Class ClmSolveMvc
//  Created on:      24-5ÔÂ-2017 13:27:46
//  Original author: open2
///////////////////////////////////////////////////////////

#include "ClmSolveMvc.h"

ClmSolveMvc::~ClmSolveMvc()
{
	delete plmSolves;
	plmSolves = nullptr;

	delete plmProfile;
	plmProfile = nullptr;
	

	delete plmResult;
	plmResult = nullptr;
}


void ClmSolveMvc::Clear()
{
	plmSolves->Clear();
	
	plmProfile->Clear();
	
	plmResult->Clear();
}


void ClmSolveMvc::Init(CxbHvdcGrid* vGrid)
{
	plmHvdc = vGrid;
	//
	plmProfile = new ClmProfile();
	plmProfile->Init();
	
	//
	plmResult = new ClmResult();
	plmResult->Init();
	
	//
	plmSolves = new ClmSolves();
	plmSolves->Init(plmProfile, plmHvdc);
}


void ClmSolveMvc::InitOrder(ClmOrder* vOrder)
{

	//CalName = vOrder->CalName;
	
	plmOrder = vOrder;
	
	plmProfile->InitOrder(plmOrder);
	
	plmSolves->InitOrder(plmOrder);
}


double ClmSolveMvc::hMax()
{
	return CxbParams::hMax;
}


double ClmSolveMvc::Frequence() 
{
	return CxbParams::Frequence;
}


void ClmSolveMvc::Run()
{
	doNewSolves();

	doRun();
}

void ClmSolveMvc::doNewSolves()
{
	plmSolves->Clear();
	plmSolves->NewSolves();
}

void ClmSolveMvc::doRun()
{
	plmSolves->Run();
}