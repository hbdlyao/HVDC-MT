
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

void C3pSolveMvc::Run(CmcResult * vResult)
{
	pmcCase = vResult;

	//
	doInitRun();
	//
	doRunCal(pmcCase->pCasePack);

}

void C3pSolveMvc::doInitRun()
{
	cout << " NewCaseU3p------" << endl;

	pmcCase->NewCaseU3p();

	//
	p3pResult->Clear();

}


void C3pSolveMvc::doRunCal(CmcCasePack & vRoot)
{
	cout << " doRunCal------" << endl;

	for each (pair<string, CmcCase *> vPair in vRoot.Children())
	{
		CmcCasePack * vCalPack = dynamic_cast<CmcCasePack *>(vPair.second);

		//p3pOrder->CalName = vCalPack->DataName;

		for each (pair<string, CmcCase *> vPair in vCalPack->Children())
		{
			CmcCasePack * vCasePack = dynamic_cast<CmcCasePack *>(vPair.second);

			doRunCase(vCasePack);

		}
	}


	cout << endl;

}


void C3pSolveMvc::doRunCase(CmcCasePack * vCasePack)
{
	p3pOrder->CaseID = vCasePack->DataName;

	
	int vGndType = p3pOrder->GroundType;
	p3pOrder->ParserOrder(vCasePack->DataName);
	if (vGndType != p3pOrder->GroundType)
	{
		cout << endl;


		vGndType = p3pOrder->GroundType;

		doNewSolves(vGndType);

		doStationSort();

	}
	
	//doPrepare3pData(int vDType, int vLoopTimes);

	//
	for each (pair<string, CmcCase *> vPair in vCasePack->Children())
	{
		CmcCase * vPdCase = vPair.second;

		doRunPd(vPdCase);

	}

}


void C3pSolveMvc::doRunPd(CmcCase * vPdCase)
{
	p3pOrder->PdPercent = vPdCase->DataName;

	for each (struct_mcResultData * vStaData in vPdCase->pDataVect)
	{		
		doSetStationData(vStaData);
	}

	doRun();

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
	static int vN = 0;

	cout << "\b\b\b\b\b\b\b\b\b\bb\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	cout << "   U3p:";
	cout << p3pOrder->CaseID;	
	cout << "%";
	cout << p3pOrder->PdPercent;

	cout << "======";
	cout.width(6);
	cout << vN++;

}


void C3pSolveMvc::doSetStationData(struct_mcResultData * vData)
{
	CDevTBL *  vTBL = p3pHvdc->DeviceTBL(C3pDefs::StaData);

	for each (C3pDevStaData *  vDev in  vTBL->Children())
	{
		vDev->SetStationData(vData);
	}
}