///////////////////////////////////////////////////////////
//  CmcSolveMvc.cpp
//  Implementation of the Class CmcSolveMvc
//  Created on:      23-4月-2017 16:46:17
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcParams.h"
#include "CHvdcFunc.h"

#include "CmcSolveMvc.h"
#include "CmcSolvesNormal.h"

#include "CmcRwOrderMvc.h"
#include "CmcRwResultMvc.h"

#include <iostream>
#include <iomanip>


CmcSolveMvc::~CmcSolveMvc()
{
	Release();
}

void CmcSolveMvc::Release()
{
	delete pmcSolves;
	pmcSolves = nullptr;

	delete pmcProfile;
	pmcProfile = nullptr;

	delete pmcResult;
	pmcResult = nullptr;
}

void CmcSolveMvc::Clear()
{
	pmcSolves->Clear();

	pmcProfile->Clear();

	pmcResult->Clear();
}


void CmcSolveMvc::Init(CmcHvdcGrid* vGrid)
{
	pmcHvdc = vGrid;
	//
	pmcProfile = new CmcProfile();
	pmcProfile->Init();

	//
	pmcResult = new CmcResult();
	pmcResult->Init();

	//
	pmcSolves = new CmcSolves();
	pmcSolves->Init(pmcProfile, pmcHvdc);

}

void CmcSolveMvc::InitOrder(CmcOrder* vOrder)
{
	CalName = vOrder->CalName;

	pmcOrder = vOrder;

	pmcProfile->InitOrder(pmcOrder);
	pmcSolves->InitOrder(pmcOrder);

}

void CmcSolveMvc::SaveResults()
{
	CmcRwResultMvc vRwMvc;

	vRwMvc.InitAdo(CmcParams::dbfFile);
	vRwMvc.Init(pmcResult);

	vRwMvc.OnSave(CmcParams::dbfFile);
}


void CmcSolveMvc::Test(int vGNDType)
{
	pmcOrder->GroundType = vGNDType;

	//pmcSolves->Init(pmcProfile, pmcHvdc);
	//
	doNewSolves(vGNDType);

	//节点编号
	doNodeID();

	//换流站排序
	doStationSort();

	//记录各站测量点的节点编号
	//doRecordMeasureNode();

	//给定额定值
	doPrepareNormal();

	//doRun();
}

void CmcSolveMvc::Run()
{
	cout << "Run---mc---" << endl;

	//多工况运行
	doInitRun();

	//
	doRun_Ground(pmcOrder->Flag_Ground);

	//
	cout << endl;
}


int CmcSolveMvc::StaCount()
{
	return CmcParams::mcStationCount;
}

void CmcSolveMvc::doRecordResult()
{
	string vCaseID = pmcOrder->CreateCaseID();
	pmcResult->Record(CalName, vCaseID, pmcProfile->pmcStaData, pmcProfile->pmcStaDataN);

	//测试用
	static int vN = 1;
	cout << "\b\b\b\b\b\b\b\b\b\bb\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	cout << "主回路:";
	cout << vCaseID;
	cout << "%";
	cout.width(3);
	cout << pmcOrder->PdPer;

	cout << "======";
	cout.width(6);
	cout << vN++;

}


void CmcSolveMvc::doNodeID()
{
	pmcSolves->NodeID();
}


void CmcSolveMvc::doStationSort()
{
	pmcSolves->StationSort();
}


void CmcSolveMvc::doNewSolves(int vGNDType)
{
	pmcSolves->Clear();
	pmcSolves->NewSolves(vGNDType);
}


void CmcSolveMvc::doInitRun()
{
	//pmcSolves->Init(pmcProfile, pmcHvdc);
	//
	int vStaCount = StaCount();
	int vCaseCount = pmcOrder->CaseCount();

	pmcResult->Clear();
	pmcResult->Init(vStaCount, vCaseCount, pmcOrder->PdSize);
}


void CmcSolveMvc::doPrepareNormal()
{
	//pmcProfile->ResetData();

	pmcSolves->PrepareNormal();
}

void CmcSolveMvc::doRun()
{
	pmcProfile->ResetData();
	//
	pmcSolves->Run();
	//记录结果
	doRecordResult();

}


void CmcSolveMvc::doRun_Ground(string vFlag)
{
	int vN = static_cast<int> (vFlag.size());

	//单极大地/金属回线/双极/双极并联
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //"1111"
		{
			pmcOrder->GroundType = GndTypeArr[i];

			//根据接地类型生成 mcCalculate,与设备一一对应
			doNewSolves(GndTypeArr[i]);

			//节点编号
			doNodeID();

			//换流站排序
			doStationSort();

			//给定额定值
			doPrepareNormal();

			//
			doRun_Rd(pmcOrder->Flag_Rd);

		}//if

	}//for
}


void CmcSolveMvc::doRun_Rd(string vFlag)
{
	int vN = static_cast<int> (vFlag.size());

	//高阻、低阻
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //
		{
			pmcOrder->RdLevel = RdLevelArr[i];

			doRun_Ud(pmcOrder->Flag_Ud);

		}//if vFlag

	}//for
}


void CmcSolveMvc::doRun_Ud(string vFlag)
{

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();

	//崔康生20170828-单功率水平
	if (pmcOrder->IsLoadSingle)
		doRun_Uac(pmcOrder->Flag_Uac);
	else
		//全压/80%/70%
		for (int i = 0; i < vN; i++)
		{
			if (vFlag[i] == '1')
			{
				pmcOrder->UdLevel = UdLevelArr[i];

				if (pmcOrder->IsUacSwap)
					doRun_UacSwap(pmcOrder->Flag_Uac, 0, vStaCount);
				else
					doRun_Uac(pmcOrder->Flag_Uac);

			}//if

		}//for
}

void CmcSolveMvc::doRun_Uac(string vFlag) {

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();

	//最大/额定/最小/极小
	for (int i = 0; i < vN; i++)
		if (vFlag[i] == '1')
		{
			for (int j = 0; j < vStaCount; j++)
				pmcOrder->UacLevel[j] = UacLevelArr[i];
			//
			doRun_Pd();
		}//if
}


void CmcSolveMvc::doRun_UacSwap(string vFlag, int vIndex, int vStaCount)
{
	int vN = static_cast<int> (vFlag.size());

	//vIndex从0开始,当vIndex==vStaCount,说明所有的换流站都已设置Uac
	if (vIndex == vStaCount)
		doRun_Pd();
	else
	{//最大/额定/最小/极小
		for (int i = 0; i < vN; i++)
			if (vFlag[i] == '1')
			{
				pmcOrder->UacLevel[vIndex] = UacLevelArr[i];

				doRun_UacSwap(vFlag, vIndex + 1, vStaCount);
			}//if

	}//else
}

void CmcSolveMvc::doRun_Pd()
{

	int vPdSize;

	vPdSize = pmcOrder->PdSize;

	//崔康生20170828-单功率水平
	if (pmcOrder->IsLoadSingle)
		doRun();
	else
		for (int i = 0; i < vPdSize; i++)
		{
			pmcOrder->UpdatePdPercent(i);
			pmcOrder->IsUdCustomPre = false;

			if (pmcOrder->IsUdCustom) //指定Ud
				doRun_UdCustom(i);
			else
				doRun();

		}//for
}

void CmcSolveMvc::doRun_UdCustom(int vPdIndex)
{
	for each (RecUdCustom vUdCustom in pmcOrder->UdData)
		if (vUdCustom.PdIndex == vPdIndex)
		{
			pmcOrder->IsUdCustomPre = true;

			bool vOk;

			vOk = pmcOrder->GroundType == GndTypeArr[0] || pmcOrder->GroundType == GndTypeArr[1];
			vOk = vOk&&pmcOrder->nValNum == 1;
			if (vOk)
				pmcOrder->UdCustom = vUdCustom.Ud11;

			vOk = pmcOrder->GroundType == GndTypeArr[0] || pmcOrder->GroundType == GndTypeArr[1];
			vOk = vOk&&pmcOrder->nValNum != 1;
			if (vOk)
				pmcOrder->UdCustom = vUdCustom.Ud12;

			vOk = pmcOrder->GroundType == GndTypeArr[2] || pmcOrder->GroundType == GndTypeArr[3];
			vOk = vOk&&pmcOrder->nValNum == 1;
			if (vOk)
				pmcOrder->UdCustom = vUdCustom.Ud21;

			vOk = pmcOrder->GroundType == GndTypeArr[2] || pmcOrder->GroundType == GndTypeArr[3];
			vOk = vOk&&pmcOrder->nValNum != 1;
			if (vOk)
				pmcOrder->UdCustom = vUdCustom.Ud22;
		}
	doRun();
}

void CmcSolveMvcNormal::Init(CmcHvdcGrid * vGrid)
{
	pmcHvdc = vGrid;
	//
	pmcProfile = new CmcProfile();
	pmcProfile->Init();

	//
	pmcResult = new CmcResult();
	pmcResult->Init();

	//
	pmcSolves = new CmcSolvesNormal();
	pmcSolves->Init(pmcProfile, pmcHvdc);

}

void CmcSolveMvcNormal::Run()
{
	//pmcSolves->Init(pmcProfile, pmcHvdc);

	pmcOrder->InitNormal();

	//
	CmcSolveMvc::Run();
}

void CmcSolveMvcNormal::doRecordResult() {

	dynamic_cast<CmcSolvesNormal*>(pmcSolves)->SaveNorml();

	//测试用
	static int vN = 1;
	string vCaseID = pmcOrder->CreateCaseID();

	cout << "主回路额定:";
	cout << vCaseID;
	cout << "%";
	cout << pmcOrder->PdPer;

	cout << "======" << vN++;
}