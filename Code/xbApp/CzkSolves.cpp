
#include "CHvdcDefs.h"

#include "CzkSolves.h"
#include "CxbDevBase.h"
#include "CxbCalculate.h"

void CzkSolves::Init(CzkProfile* vProfile, CxbHvdcGrid * vGrid)
{
	CxbSolves::Init(vProfile, vGrid);

	pzkHvdc = vGrid;
	pzkProfile = vProfile;

}


void CzkSolves::InitOrder(CzkOrder * vOrder)
{
	//CalName = vOrder->CalName;

	pzkOrder = vOrder;

	pxbOrder = pzkOrder;

}


CPowerCalculate * CzkSolves::doNewCal(CDevBase* vDev)
{
	int vType;
	CxbCalculate * vCal = nullptr;

	vCal = dynamic_cast<CxbCalculate * >( CxbSolves::doNewCal(vDev));

	vCal->InitOrder(pzkOrder);
	//
	return vCal;
}

void CzkSolves::Run()
{
	//
	doPrepare();

	//
	doSolve();

}


void CzkSolves::doPrepare()
{
	//对每一个CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Prepare_zk();
	}
}

void CzkSolves::doSolve()
{
	//cout << "----UpdateY---" << endl;

	//形成Y
	Update_zkY();

	//cout << "----UpdateI---" << endl;
	//
	Update_zkI();

	//cout << "----SolveU---" << endl;
	//
	Solve_zkU();


	Solve_zkReq();
}

void CzkSolves::Update_zkY()
{
	//int vScanPort = pzkProfile->pzkOrder->ScanPort;

	for each (CxbCalculate * vCal in pChildren)
	{
		//if(vCal->StationIndex == vScanPort)
		//	continue;
		vCal->Update_zkY();
	}
}

void CzkSolves::Update_zkI()
{
	int vScanPort = pzkProfile->pzkOrder->ScanPort;

	for each (CxbCalculate * vCal in pChildren)
	{
		//if (vCal->StationIndex != vScanPort)
		//	continue;
		vCal->Update_zkI();
	}
}

void CzkSolves::Solve_zkU()
{
	pzkProfile->Solve();
}

void CzkSolves::Solve_zkReq()
{
	pzkProfile->Solve_zkReq();
}
