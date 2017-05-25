///////////////////////////////////////////////////////////
//  CxbSolveMvc.cpp
//  Implementation of the Class CxbSolveMvc
//  Created on:      05-4��-2017 18:22:37
//  Original author: Administrator
///////////////////////////////////////////////////////////


#include "CHvdcDefs.h"

#include "CxbSolveMvc.h"
#include "CxbDevDCF.h"
#include "CMyParams.h"
#include "CxbParams.h"
#include "CxbDev3pVSrc.h"

#include "CxbRwOrderMvc.h"


CxbSolveMvc::~CxbSolveMvc()
{
	pxbSolves->Clear();
	delete pxbSolves;
	pxbSolves = nullptr;

	//
	pxbProfile->Clear();
	delete pxbProfile;
	pxbProfile = nullptr;


	pxbResult->Clear();
	delete pxbResult;
	pxbResult = nullptr;

}

void CxbSolveMvc::Clear()
{
	pxbSolves->Clear();

	pxbProfile->Clear();

	pxbResult->Clear();

}

void CxbSolveMvc::Init(CxbHvdcGrid* vGrid)
{
	pxbHvdc = vGrid;
	//
	pxbProfile = new CxbProfile();
	pxbProfile->Init();

	//
	pxbResult = new CxbResult();
	pxbResult->Init();

	//
	pxbSolves = new CxbSolves();
	pxbSolves->Init(pxbProfile, pxbHvdc);

}

void CxbSolveMvc::InitOrder(CxbOrder * vOrder)
{
	//CalName = vOrder->CalName;

	pxbOrder = vOrder;

	pxbProfile->InitOrder(pxbOrder);

	pxbSolves->InitOrder(pxbOrder);

}

void CxbSolveMvc::doNodeID()
{
	pxbSolves->NodeID();
}


void CxbSolveMvc::doStationSort()
{
	pxbSolves->StationSort();
}


void CxbSolveMvc::doNewSolves(int vGNDType)
{
	//
	pxbSolves->Clear();
	//
	pxbSolves->NewSolves(vGNDType);
	//
}


int CxbSolveMvc::StaCount()
{
	//�ӹ��������ж�ȡ
	return CxbParams::xbStationCount;

}


void CxbSolveMvc::Test(int vGNDType)
{
	doPrepare_hRLC();

	doInitRun();
	//
	pxbOrder->GroundType = vGNDType;
	//
	//pxbSolves->Init(pxbProfile, pxbHvdc);

	//
	doNewSolves(vGNDType);

	//�ڵ���
	doNodeID();

	doStationSort();

	//��ʼ�������þ���
	doInitMatrix();

	doRun();

}

void CxbSolveMvc::Run()
{
	//
	doPrepare_hRLC();


	doInitRun();

	//�๤������
	doRun_Ground(pxbOrder->Flag_Ground);
}


void CxbSolveMvc::doPrepare_hRLC()
{
	//���������豸�ĸ���г���迹��
	pxbHvdc->Prepare_hRLC();

}


double CxbSolveMvc::Frequence()
{
	return CxbParams::Frequence;
}

double CxbSolveMvc::hMax()
{
	return CxbParams::hMax;
}

void CxbSolveMvc::doRun()
{
	//����

	//���ǹ���(����ˮƽ)��DCFƫ�����͡�г������
	//doPrepare_U3p(pxbOrder->CreateCaseID());
	
	//г������1-hMax()
	for (int i = 1; i <= hMax(); i++)
	//int i = 1;
	{
		cout << "----г������:  " << i <<"-----" << endl;

		pxbProfile->hOrder = i;		
		pxbProfile->ReSetData();

		pxbSolves->Run();

	}

	//
	doSolveIeq();

	//��¼���
	doRecordResult();

}

void CxbSolveMvc::doSolveIeq()
{
	pxbSolves->SolveIeq();
}


void CxbSolveMvc::doRecordResult()
{
	//������
	static int vN = 1;
	string vCaseID = pxbOrder->CreateCaseID();

	//pxbResult->mcResultMap[vCaseID]=

	cout << "г��:";
	cout << vCaseID;
	cout << "%";
	cout << pxbOrder->PdPer;

	cout << "======" << vN++;

	cout << endl;
}


void CxbSolveMvc::doInitRun()
{
	//pxbSolves->Init(pxbProfile, pxbHvdc);
	//
	int vStaCount = StaCount();

	//
	int vCaseCount = pxbOrder->CaseCount();
	pxbResult->Clear();
	//pxbResult->Init(vStaCount, vCaseCount, pxbOrder->PdSize);
}


void CxbSolveMvc::doInitMatrix() 
{
	//
	pxbProfile->InitMatrix();
}


void CxbSolveMvc::doRun_Ground(string vFlag) {

	int vN = static_cast<int> (vFlag.size());

	//�������/��������/˫��/˫������
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //"1111"
		{
			pxbOrder->GroundType = GndTypeArr[i];

			//���ݽӵ��������� mcCalculate,���豸һһ��Ӧ
			doNewSolves(GndTypeArr[i]);

			//�ڵ���
			doNodeID();

			//����վ����
			doStationSort();

			//��ʼ�������þ���
			doInitMatrix();

			doRun_Rd(pxbOrder->Flag_Rd);

		}//if

	}//for
}


void CxbSolveMvc::doRun_Rd(string vFlag) {

	int vN = static_cast<int> (vFlag.size());

	//���衢����
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //
		{
			pxbOrder->RdLevel = RdLevelArr[i];

			//
			if (pxbOrder->IsUdCustom) //ָ��Ud
				doRun_UdCustom();
			else
				doRun_Ud(pxbOrder->Flag_Ud);

		}//if vFlag

	}//for
}


void CxbSolveMvc::doRun_Ud(string vFlag) {

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();

	//ȫѹ/80%/70%
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1')
		{
			pxbOrder->UdLevel = UdLevelArr[i];

			if (pxbOrder->IsUacSwap)
				doRun_UacSwap(pxbOrder->Flag_Uac, 0, vStaCount);
			else
				doRun_Uac(pxbOrder->Flag_Uac);

		}//if

	}//for
}


void CxbSolveMvc::doRun_UdCustom()
{

	int vStaCount = StaCount();

	pxbOrder->UdLevel = Ud_Custom;

	//Ud����

	//
	if (pxbOrder->IsUacSwap)
		doRun_UacSwap(pxbOrder->Flag_Uac, 0, vStaCount);
	else
		doRun_Uac(pxbOrder->Flag_Uac);
}


void CxbSolveMvc::doRun_Uac(string vFlag) {

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();

	//���/�/��С/��С
	for (int i = 0; i < vN; i++)
		if (vFlag[i] == '1')
		{
			for (int j = 0; j<vStaCount; j++)
				pxbOrder->UacLevel[j] = UacLevelArr[i];
			//
			doRun_Pd();
		}//if
}


void CxbSolveMvc::doRun_UacSwap(string vFlag, int vIndex, int vStaCount) {

	int vN = static_cast<int> (vFlag.size());


	//vIndex��0��ʼ,��vIndex==vStaCount,˵�����еĻ���վ��������Uac
	if (vIndex == vStaCount)
		doRun_Pd();
	else
	{//���/�/��С/��С
		for (int i = 0; i < vN; i++)
			if (vFlag[i] == '1')
			{
				pxbOrder->UacLevel[vIndex] = UacLevelArr[i];

				doRun_UacSwap(vFlag, vIndex + 1, vStaCount);
			}//if

	}//else
}


void CxbSolveMvc::doRun_Pd()
{

	int vPdSize;

	vPdSize = pxbOrder->PdSize;

	for (int i = 0; i<vPdSize; i++)
	{
		pxbOrder->UpdatePdPercent(i);

		//doRun_DCF();

		doRun();

	}//for
}

void CxbSolveMvc::doRun_DCF()
{

/*
//����
	static int vCount = 1;
	int i, vDevN;
	CDevTBL * vTBL;
	CxbDevDCF * vDev;


	vTBL = pGrid->DeviceTBL(CxbDefs::DCF);
	vDevN = vTBL->DeviceCount();
	switch (pxbOrder->DCFDevType)
	{
	case DCF_NoneDev://��ƫ��
		for (i = 0; i < vDevN; i++)
		{
			vDev = dynamic_cast<CxbDevDCF *>(vTBL->Device(i));
			vDev->selectNoneDevY();
		}
		doRun();
		return;

	case DCF_ConsDev://�㶨ƫ��
		for (vCount = 0; vCount < 3; vCount++)
			for (i = 0; i < vDevN; i++)
			{
				vDev = dynamic_cast<CxbDevDCF *>(vTBL->Device(i));
				vDev->selectConsDevY(vCount);
				doRun();
			}
		return;

	case DCF_RandDev: //����ƫ��
		for (vCount = 0; vCount < pxbOrder->DCFRandTimes; vCount++)
			for (i = 0; i < vDevN; i++)
			{
				vDev = dynamic_cast<CxbDevDCF *>(vTBL->Device(i));
				vDev->selectConsDevY(vCount);
				doRun();
			}
		return;
	}
	return;
*/

}


void CxbSolveMvc::doPrepare_U3p(string  vCondition)
{
	CDevTBL *  vTBL = pxbHvdc->DeviceTBL(CxbDefs::Usrc3p);
	for each (CxbDev3pVSrc *  vDev in  vTBL->Children())
	{
		vDev->PrepareData(vCondition);
	}
}


