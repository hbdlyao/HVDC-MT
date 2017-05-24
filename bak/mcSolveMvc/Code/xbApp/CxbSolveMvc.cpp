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

void CxbSolveMvc::InitOrder()
{
	CxbRwOrderMvc  vRwMvc;

	vRwMvc.InitAdo(CxbParams::dbfFile);
	vRwMvc.Init(pxbProfile->pxbOrder);

	vRwMvc.OnLoad(CxbParams::dbfFile);
	
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
	//从工程属性中读取
	return CxbParams::xbStationCount;

}


void CxbSolveMvc::Test(int vGNDType)
{
	doPrepare_hRLC();

	doInitRun();
	//
	pxbProfile->pxbOrder->GroundType = vGNDType;
	//
	//pxbSolves->Init(pxbProfile, pxbHvdc);

	//
	doNewSolves(vGNDType);

	//节点编号
	doNodeID();

	doStationSort();

	//初始化计算用矩阵
	doInitMatrix();

	doRun();

}

void CxbSolveMvc::Run()
{
	//
	doPrepare_hRLC();


	doInitRun();

	//多工况运行
	doRun_Ground(pxbProfile->pxbOrder->Flag_Ground);
}


void CxbSolveMvc::doPrepare_hRLC()
{
	//计算出相关设备的各次谐波阻抗；
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
	//马俊鹏

	//考虑工况(功率水平)、DCF偏差类型、谐波次数
	//doPrepare_U3p(pxbProfile->pxbOrder->CreateCaseID());
	
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
	string vCaseID = pxbProfile->pxbOrder->CreateCaseID();

	//pxbResult->mcResultMap[vCaseID]=

	cout << "谐波:";
	cout << vCaseID;
	cout << "%";
	cout << pxbProfile->pxbOrder->PdPer;

	cout << "======" << vN++;

	cout << endl;
}


void CxbSolveMvc::doInitRun()
{
	//pxbSolves->Init(pxbProfile, pxbHvdc);
	//
	int vStaCount = StaCount();

	//
	int vCaseCount = pxbProfile->pxbOrder->CaseCount();
	pxbResult->Clear();
	//pxbResult->Init(vStaCount, vCaseCount, pxbProfile->pxbOrder->PdSize);
}


void CxbSolveMvc::doInitMatrix() 
{
	//
	pxbProfile->InitMatrix();
}


void CxbSolveMvc::doRun_Ground(string vFlag) {

	int vN = static_cast<int> (vFlag.size());

	//单极大地/金属回线/双极/双极并联
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //"1111"
		{
			pxbProfile->pxbOrder->GroundType = GndTypeArr[i];

			//根据接地类型生成 mcCalculate,与设备一一对应
			doNewSolves(GndTypeArr[i]);

			//节点编号
			doNodeID();

			//换流站排序
			doStationSort();

			//初始化计算用矩阵
			doInitMatrix();

			doRun_Rd(pxbProfile->pxbOrder->Flag_Rd);

		}//if

	}//for
}


void CxbSolveMvc::doRun_Rd(string vFlag) {

	int vN = static_cast<int> (vFlag.size());

	//高阻、低阻
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //
		{
			pxbProfile->pxbOrder->RdLevel = RdLevelArr[i];

			//
			if (pxbProfile->pxbOrder->IsUdCustom) //指定Ud
				doRun_UdCustom();
			else
				doRun_Ud(pxbProfile->pxbOrder->Flag_Ud);

		}//if vFlag

	}//for
}


void CxbSolveMvc::doRun_Ud(string vFlag) {

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();

	//全压/80%/70%
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1')
		{
			pxbProfile->pxbOrder->UdLevel = UdLevelArr[i];

			if (pxbProfile->pxbOrder->IsUacSwap)
				doRun_UacSwap(pxbProfile->pxbOrder->Flag_Uac, 0, vStaCount);
			else
				doRun_Uac(pxbProfile->pxbOrder->Flag_Uac);

		}//if

	}//for
}


void CxbSolveMvc::doRun_UdCustom()
{

	int vStaCount = StaCount();

	pxbProfile->pxbOrder->UdLevel = Ud_Custom;

	//Ud处理

	//
	if (pxbProfile->pxbOrder->IsUacSwap)
		doRun_UacSwap(pxbProfile->pxbOrder->Flag_Uac, 0, vStaCount);
	else
		doRun_Uac(pxbProfile->pxbOrder->Flag_Uac);
}


void CxbSolveMvc::doRun_Uac(string vFlag) {

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();

	//最大/额定/最小/极小
	for (int i = 0; i < vN; i++)
		if (vFlag[i] == '1')
		{
			for (int j = 0; j<vStaCount; j++)
				pxbProfile->pxbOrder->UacLevel[j] = UacLevelArr[i];
			//
			doRun_Pd();
		}//if
}


void CxbSolveMvc::doRun_UacSwap(string vFlag, int vIndex, int vStaCount) {

	int vN = static_cast<int> (vFlag.size());


	//vIndex从0开始,当vIndex==vStaCount,说明所有的换流站都已设置Uac
	if (vIndex == vStaCount)
		doRun_Pd();
	else
	{//最大/额定/最小/极小
		for (int i = 0; i < vN; i++)
			if (vFlag[i] == '1')
			{
				pxbProfile->pxbOrder->UacLevel[vIndex] = UacLevelArr[i];

				doRun_UacSwap(vFlag, vIndex + 1, vStaCount);
			}//if

	}//else
}


void CxbSolveMvc::doRun_Pd()
{

	int vPdSize;

	vPdSize = pxbProfile->pxbOrder->PdSize;

	for (int i = 0; i<vPdSize; i++)
	{
		pxbProfile->pxbOrder->UpdatePdPercent(i);

		//doRun_DCF();

		doRun();

	}//for
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
	switch (pxbProfile->pxbOrder->DCFDevType)
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
		for (vCount = 0; vCount < pxbProfile->pxbOrder->DCFRandTimes; vCount++)
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


