
#include "CzkSolveMvc.h"

#include "CHvdcDefs.h"
#include "CxbDefs.h"
#include "CxbDev3pVSrc.h"

#include "CxbRwOrderMvc.h"
#include "CxbParams.h"


void CzkSolveMvc::Init(CxbHvdcGrid* vGrid)
{
	pzkHvdc = vGrid;
	//
	pzkProfile = new CzkProfile();
	pzkProfile->Init();

	//
	pzkResult = new CzkResult();
	pzkResult->Init();

	//
	pzkSolves = new CzkSolves();
	pzkSolves->Init(pzkProfile, pzkHvdc);

/////////////////////////////////////////////
	pxbHvdc = pzkHvdc;
	pxbProfile = pzkProfile;
	pxbResult  = pzkResult;
	pxbSolves = pzkSolves;
}


void CzkSolveMvc::Test(int vGNDType)
{
	doPrepare_hRLC();

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


void CzkSolveMvc::doPrepare_hRLC()
{
	double vFreStart = pzkProfile->pzkOrder->FreStart;

	double vFreStep = pzkProfile->pzkOrder->FreStep;

	int vFreDim = pzkProfile->pzkOrder->FreDim;

	//计算出相关设备的各次谐波阻抗；
	pzkHvdc->Prepare_hRLC(vFreStart, vFreStep, vFreDim);

}

void CzkSolveMvc::doRun()
{
	//马俊鹏

	//考虑工况(功率水平)、DCF偏差类型、谐波次数
	//doPrepare_U3p(pzkProfile->pzkOrder->CreateCaseID());

	int vDim = pzkProfile->pzkOrder->FreDim;

	double vFreStart = pzkProfile->pzkOrder->FreStart;

	double vFreStep = pzkProfile->pzkOrder->FreStep;

	//谐波次数1-hMax()
	for (int i = 1; i <= vDim; i++)
		//int i = 1;
	{
		cout << "----频率:  " << vFreStart + vFreStep * i << "-----" << endl;

		pzkProfile->hOrder = i;
		pzkProfile->ReSetData();

		pzkSolves->Run();

	}

	//记录结果
	doRecordResult();

}

void CzkSolveMvc::doRecordResult()
{
	//测试用
	static int vN = 1;
	string vCaseID = pzkProfile->pzkOrder->CreateCaseID();

	//pzkResult->mcResultMap[vCaseID]=

	cout << "阻抗扫描:";
	cout << vCaseID;
	cout << "%";
	cout << pzkProfile->pzkOrder->PdPer;

	cout << "======" << vN++;

	cout << endl;

}

