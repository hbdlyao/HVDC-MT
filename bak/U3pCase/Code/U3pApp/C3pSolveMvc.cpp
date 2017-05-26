
#include "C3pSolveMvc.h"

#include "C3pParams.h"
#include "C3pRwOrderMvc.h"


#include "C3pDevStaData.h"

#include <iostream>

C3pSolveMvc::~C3pSolveMvc()
{
	p3pSolves->Clear();
	delete p3pSolves;
	p3pSolves = nullptr;

	//
	p3pProfile->Clear();
	delete p3pProfile;
	p3pProfile = nullptr;


	p3pResult->Clear();
	delete p3pResult;
	p3pResult = nullptr;

}

void C3pSolveMvc::Clear()
{
	p3pSolves->Clear();

	p3pProfile->Clear();

	p3pResult->Clear();

}

void C3pSolveMvc::Init(C3pDevGrid* vGrid)
{
	p3pHvdc = vGrid;

	//
	p3pProfile = new C3pProfile();
	p3pProfile->Init();

	//
	p3pResult = new C3pResult();
	p3pResult->Init();

	p3pSolves = new C3pSolves();
	p3pSolves->Init(p3pProfile, p3pHvdc);

}

void C3pSolveMvc::InitOrder(C3pOrder * vOrder)
{
	//CalName = vOrder->CalName;

	p3pOrder = vOrder;

	p3pProfile->InitOrder(p3pOrder);
	p3pSolves->InitOrder(p3pOrder);
}



int C3pSolveMvc::StaCount()
{
	//从工程属性中读取
	return C3pParams::StationCount;

}


double C3pSolveMvc::Frequence()
{
	return C3pParams::Frequence;
}

double C3pSolveMvc::hMax()
{
	return C3pParams::hMax;
}


void C3pSolveMvc::Test(int vGNDType)
{
	struct_Case vData = p3pOrder->CaseList[0];

	p3pOrder->ParserOrder(vData.CaseID);

	//
	p3pOrder->GroundType = vGNDType;

	doPrepare3pData(p3pOrder->DType, p3pOrder->LoopTimes());
	//
	doInitRun();
	//
	doNewSolves(vGNDType);
	//
	doStationSort();

	//初始化计算用矩阵
	//doInitMatrix();

	//
	doDataSelected(vData.CalName, vData.CaseID, vData.PdPercent);

	//doRun_DCF();

	//doRun();

}

void C3pSolveMvc::Run()
{

}

void C3pSolveMvc::doInitRun()
{
	//
	int vStaCount = StaCount();

	//
	int vCaseCount = p3pOrder->CaseCount();
	p3pResult->Clear();
	//p3pResult->Init(vStaCount, vCaseCount, p3pOrder->PdSize);

}

void C3pSolveMvc::doPrepare3pData(int vDType, int vLoopTimes)
{
	//计算偏差？
	p3pHvdc->Prepare3pData(vDType, vLoopTimes);

}

void C3pSolveMvc::doNewSolves(int vGNDType)
{
	//
	p3pSolves->Clear();
	//
	p3pSolves->NewSolves(vGNDType);
	//

	p3pProfile->ClearData();	
	p3pProfile->NewU3pData(vGNDType);

}

void C3pSolveMvc::doStationSort()
{
	p3pSolves->StationSort();
}

void C3pSolveMvc::doRun()
{
	p3pProfile->ReSetData();

	p3pSolves->Run();

	//记录结果
	doRecordResult();
}


void C3pSolveMvc::doRecordResult()
{
//
}


void C3pSolveMvc::doDataSelected(string  vCalName, string vCaseID, double vPdPersent)
{
	CDevTBL *  vTBL = p3pHvdc->DeviceTBL(C3pDefs::StaData);

	for each (C3pDevStaData *  vDev in  vTBL->Children())
	{
		vDev->DataSelected(vCalName, vCaseID, vPdPersent);
	}
}