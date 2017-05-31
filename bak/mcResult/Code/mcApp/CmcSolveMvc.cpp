///////////////////////////////////////////////////////////
//  CmcSolveMvc.cpp
//  Implementation of the Class CmcSolveMvc
//  Created on:      23-4��-2017 16:46:17
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
	//Byte * vData;
	//long vLeng;

	//vLeng = sizeof(long);
	////RecordDim+RecordByte+PackedLeng
	//vLeng = 2*vLeng + pmcResult->PackedLeng();

	//vData = new Byte[vLeng];
	//pmcResult->Serialize(vData);
	//pmcResult->UnSerialize(vData);

	//CmcMvcs::OnSaveResult(CmcParams::dbfFile,pmcResult);

}


void CmcSolveMvc::Test(int vGNDType)
{
	pmcOrder->GroundType = vGNDType;

	//pmcSolves->Init(pmcProfile, pmcHvdc);
	//
	doNewSolves(vGNDType);

	//�ڵ���
	doNodeID();

	//����վ����
	doStationSort();

	//��¼��վ������Ľڵ���
	//doRecordMeasureNode();

	//�����ֵ
	doPrepareNormal();

	//doRun();
}

void CmcSolveMvc::Run()
{
	cout << "Run---mc---" << endl;

	//�๤������
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

	//������
	static int vN = 1;
	cout << "\b\b\b\b\b\b\b\b\b\bb\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	cout << "����·:";
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
	//��¼���
	doRecordResult();

}


void CmcSolveMvc::doRun_Ground(string vFlag)
{
	int vN = static_cast<int> (vFlag.size());

	//�������/��������/˫��/˫������
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //"1111"
		{
			pmcOrder->GroundType = GndTypeArr[i];

			//���ݽӵ��������� mcCalculate,���豸һһ��Ӧ
			doNewSolves(GndTypeArr[i]);

			//�ڵ���
			doNodeID();

			//����վ����
			doStationSort();

			//�����ֵ
			doPrepareNormal();

			//
			doRun_Rd(pmcOrder->Flag_Rd);

		}//if

	}//for
}


void CmcSolveMvc::doRun_Rd(string vFlag)
{
	int vN = static_cast<int> (vFlag.size());

	//���衢����
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

	//�޿���20170828-������ˮƽ
	if (pmcOrder->IsLoadSingle)
		doRun_Uac(pmcOrder->Flag_Uac);
	else
		//ȫѹ/80%/70%
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

	//���/�/��С/��С
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

	//vIndex��0��ʼ,��vIndex==vStaCount,˵�����еĻ���վ��������Uac
	if (vIndex == vStaCount)
		doRun_Pd();
	else
	{//���/�/��С/��С
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

	//�޿���20170828-������ˮƽ
	if (pmcOrder->IsLoadSingle)
		doRun();
	else
		for (int i = 0; i < vPdSize; i++)
		{
			pmcOrder->UpdatePdPercent(i);
			pmcOrder->IsUdCustomPre = false;

			if (pmcOrder->IsUdCustom) //ָ��Ud
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

	//������
	static int vN = 1;
	string vCaseID = pmcOrder->CreateCaseID();

	cout << "����·�:";
	cout << vCaseID;
	cout << "%";
	cout << pmcOrder->PdPer;

	cout << "======" << vN++;
}