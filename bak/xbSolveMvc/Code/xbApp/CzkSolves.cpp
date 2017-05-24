
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

void CzkSolves::NodeID()
{
	//Yao ?
	int vK = 0;
	NodeMap vNodeID, vNodeMap;

	//
	pzkHvdc->ClearNodeID();

	for each (CxbCalculate * vCal in pChildren)
	{
		//给所有节点编号，包括接地的节点
		vCal->NodeSort(vNodeMap);
	}//

	 //
	for each (CxbCalculate * vCal in pChildren)
	{
		//将接地的节点的编号置为-1，表示接地
		vCal->NodeGround(vNodeMap);
	}//

	vK = 0;
	for each (pair<string, int> vPair in vNodeMap)
	{
		//划去接地节点
		if (vPair.second != -1)
		{
			vNodeID[vPair.first] = vK;

			vK = vK + 1;
		}
		else
			vNodeID[vPair.first] = -1;

	}// for each


	pzkProfile->SetYdim(vK);

	for each (CxbCalculate * vCal in pChildren)
	{
		//给定节点编号
		vCal->NodeID(vNodeID);
	}//

	//
	pzkProfile->NodeID = vNodeID;

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
