///////////////////////////////////////////////////////////
//  CxbSolveMvc.cpp
//  Implementation of the Class CxbSolveMvc
//  Created on:      05-4月-2017 18:22:37
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
	//从工程属性中读取
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

	//节点编号
	doNodeID();

	doStationSort();

	//初始化计算用矩阵
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
			//节点编号
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
	//计算出相关设备的各次谐波阻抗；
	pxbHvdc->Prepare_hRLC();

}


void CxbSolveMvc::doRun()
{
	//马俊鹏

	//考虑工况(功率水平)、DCF偏差类型、谐波次数
	//doPrepare_U3p(pxbOrder->CreateCaseID());
	
	//谐波次数1-hMax()
	for (int i = 1; i <= hMax(); i++)
	//int i = 1;
	{
		cout << "----谐波次数:  " << i <<"-----" << endl;

		pxbProfile->hOrder = i;		
		pxbProfile->ReSetData();

		pxbSolves->Run();

	}

	//
	doSolveIeq();

	//记录结果
	doRecordResult();

}

void CxbSolveMvc::doSolveIeq()
{
	pxbSolves->SolveIeq();
}


void CxbSolveMvc::doRecordResult()
{
	//测试用
	static int vN = 1;
	string vCaseID = pxbOrder->CreateCaseID();

	//pxbResult->mcResultMap[vCaseID]=

	cout << "谐波:";
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
//马俊鹏
	static int vCount = 1;
	int i, vDevN;
	CDevTBL * vTBL;
	CxbDevDCF * vDev;


	vTBL = pGrid->DeviceTBL(CxbDefs::DCF);
	vDevN = vTBL->DeviceCount();
	switch (pxbOrder->DCFDevType)
	{
	case DCF_NoneDev://无偏差
		for (i = 0; i < vDevN; i++)
		{
			vDev = dynamic_cast<CxbDevDCF *>(vTBL->Device(i));
			vDev->selectNoneDevY();
		}
		doRun();
		return;

	case DCF_ConsDev://恒定偏差
		for (vCount = 0; vCount < 3; vCount++)
			for (i = 0; i < vDevN; i++)
			{
				vDev = dynamic_cast<CxbDevDCF *>(vTBL->Device(i));
				vDev->selectConsDevY(vCount);
				doRun();
			}
		return;

	case DCF_RandDev: //概率偏差
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


