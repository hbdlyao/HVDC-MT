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
#include "CxbDevU3p.h"

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


int CxbSolveMvc::StaCount()
{
	//�ӹ��������ж�ȡ
	return CxbParams::xbStationCount;

}

double CxbSolveMvc::Frequence()
{
	return CxbParams::Frequence;
}

double CxbSolveMvc::hMax()
{
	return CxbParams::hMax;
}


void CxbSolveMvc::Test(int vGNDType)
{
	struct_Case vData = pxbOrder->CaseList[0];

	pxbOrder->ParserOrder(vData.CaseID);

	//
	pxbOrder->GroundType = vGNDType;

	doPrepare_hRLC();

	doInitRun();

	//
	doNewSolves(vGNDType);

	//�ڵ���
	doNodeID();

	doStationSort();

	//��ʼ�������þ���
	doInitMatrix();

	//
	doDataSelected_U3p(vData.CalName, vData.CaseID, vData.PdPercent);

	//doRun_DCF();

	doRun();

}


void CxbSolveMvc::Run()
{
	int vGndType;
	//
	doPrepare_hRLC();

	doInitRun();

	//
	for each (struct_Case vData in pxbOrder->CaseList)
	{
		vGndType = pxbOrder->GroundType;

		pxbOrder->ParserOrder(vData.CaseID);

		//
		if (vGndType != pxbOrder->GroundType)
		{
			vGndType = pxbOrder->GroundType;

			//
			doNewSolves(vGndType);
			//�ڵ���
			doNodeID();
			//
			doStationSort();
			//
			doInitMatrix();

		}
		
		//
		doDataSelected_U3p(vData.CalName,vData.CaseID,vData.PdPercent);
		//
		//doRun_DCF();
		//
		doRun();

	}//for 

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


void CxbSolveMvc::doPrepare_hRLC()
{
	//���������豸�ĸ���г���迹��
	pxbHvdc->Prepare_hRLC();

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


void CxbSolveMvc::doDataSelected_U3p(string  vCalName,string vCaseID,double vPdPersent)
{
	CDevTBL *  vTBL = pxbHvdc->DeviceTBL(CxbDefs::Usrc3p);
	for each (CxbDevU3p *  vDev in  vTBL->Children())
	{
		vDev->DataSelected(vCalName, vCaseID, vPdPersent);
	}
}


