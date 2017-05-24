///////////////////////////////////////////////////////////
//  CPowerSolveMvc.cpp
//  Implementation of the Class CPowerSolveMvc
//  Created on:      09-4月-2017 21:45:59
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CPowerSolveMvc.h"

CPowerSolveMvc::~CPowerSolveMvc()
{
	Release();
}

void CPowerSolveMvc::Release()
{
	pSolves->Clear();
	pProfile->Clear();

	delete pSolves;
	pSolves = nullptr;

	//
	delete pProfile;
	pProfile = nullptr;
}

void CPowerSolveMvc::Clear()
{
	pSolves->Clear();

	pProfile->Clear();
}

void CPowerSolveMvc::Init(CPowerGrid * vGrid)
{
	pGrid = vGrid;

	pProfile = new CPowerProfile();
	pProfile->Init();

	pSolves = new CPowerSolves();
	pSolves->Init(pProfile, pGrid);

}


void CPowerSolveMvc::NodeID()
{
	//
	pSolves->Init(pProfile, pGrid);
	//
	doNewSolves();
	
	//节点编号
	doNodeID();
}


void CPowerSolveMvc::Run()
{
	//
	pSolves->Init(pProfile, pGrid);
	//
	doNewSolves();

	//节点编号
	doNodeID();

	//
	doStationSort();

	//
	doRun();
}


void CPowerSolveMvc::doRun()
{
	//
	pProfile->Clear();
	//
	pSolves->Run();
}


void CPowerSolveMvc::doNewSolves()
{
	pSolves->Clear();
	pSolves->NewSolves();
}


void CPowerSolveMvc::doNodeID()
{
	pSolves->NodeID();
}


void CPowerSolveMvc::doStationSort()
{
	pSolves->StationSort();
}

