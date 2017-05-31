
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
		//�����нڵ��ţ������ӵصĽڵ�
		vCal->NodeSort(vNodeMap);
	}//

	 //
	for each (CxbCalculate * vCal in pChildren)
	{
		//���ӵصĽڵ�ı����Ϊ-1����ʾ�ӵ�
		vCal->NodeGround(vNodeMap);
	}//

	vK = 0;
	for each (pair<string, int> vPair in vNodeMap)
	{
		//��ȥ�ӵؽڵ�
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
		//�����ڵ���
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
	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Prepare_zk();
	}
}

void CzkSolves::doSolve()
{
	//cout << "----UpdateY---" << endl;

	//�γ�Y
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
