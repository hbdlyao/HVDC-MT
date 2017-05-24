
#include "C3pSolves.h"

#include "CHvdcDefs.h"
#include "C3pDefs.h"

#include "C3pDevBase.h"
#include "C3pFunc.h"
#include "gbHead_3pCal.h"

#include <iostream>


void C3pSolves::Init(C3pProfile * vProfile, C3pDevGrid * vGrid)
{
	CPowerSolves::Init(vProfile,vGrid);

	p3pProfile = vProfile;
	p3pHvdc = vGrid;
}


void C3pSolves::NewSolves(int vGndType)
{
	//
	switch (vGndType)
	{
	case Ground10:
		doNewXbSolvers10(); //单极大地
		break;

	case Ground11:
		doNewXbSolvers11();//单极金属回线
		break;

	case Ground20:
		doNewXbSolvers20();//双极
		break;

	default:
		break;
	}//switch
}


void C3pSolves::doNewXbSolvers10()
{
	cout << "doNewCal---单极大地---" << endl;

	doNewItem(C3pDefs::ACF);

	doNewItem(C3pDefs::AcSys);

	doNewItem(C3pDefs::Convertor);

	doNewItem(C3pDefs::Xf2);
}


void C3pSolves::doNewXbSolvers11()
{
	cout << "doNewCal---单极金属回线---" << endl;

	doNewItem(C3pDefs::ACF);

	doNewItem(C3pDefs::AcSys);

	doNewItem(C3pDefs::Convertor);

	doNewItem(C3pDefs::Xf2);
}


void C3pSolves::doNewXbSolvers20()
{
	cout << "doNewCal---双极---" << endl;
	//
	doNewItem(C3pDefs::ACF);

	doNewItem(C3pDefs::AcSys);

	doNewItem(C3pDefs::Convertor);

	doNewItem(C3pDefs::Xf2);
}



int C3pSolves::GroundType()
{
	return p3pProfile->pOrder->GroundType;
}

void C3pSolves::doNewItem(int vtblType)
{
	CDevTBL * vTBL;

	vTBL = pGrid->DeviceTBL(vtblType);

	doNewItem(vTBL);
}

void C3pSolves::doNewItem(CDevTBL * vTBL)
{
	for each (C3pDevBase *  vDev in  vTBL->Children())
	{
		if ((vDev->GetPosOrNeg()) == C3pDefs::Pos) //正极设备
			doNewCal(vDev);

		if ((vDev->GetPosOrNeg()) == C3pDefs::Neg) //负极设备
			switch (GroundType())
			{
			case Ground20: //双极中性点
			case Ground21: //双极并联
				doNewCal(vDev);

				break;

			default:
				break;
			}

	}//pObj_Pair


}

CPowerCalculate * C3pSolves::doNewCal(CDevBase * vDev)
{
	int vType;
	string vName;
	CPowerCalculate * vCal = nullptr;

	vType = vDev->GetDeviceType();
	switch (vType)
	{
	case C3pDefs::AcSys:
		//交流系统  
		vCal = new  C3pCalAcSys();
		break;

	case C3pDefs::Xf2:
		//双绕组变压器  
		vCal = new  C3pCalXf2();
		break;

	case C3pDefs::Convertor:
		//换流器  
		vCal = new  C3pCalConvertor();
		break;

	default:
		vCal = new  C3pCalculate();
		break;

	}//switch


	 //
	//vName = vDev->GetDeviceName();
	//vCal->SelfID = vName;
	//vCal->SelfType = vType;

	vCal->Init(vDev);
	vCal->Init(p3pProfile);

	Add(vCal);

	return vCal;

}


void C3pSolves::doSolveMiu()
{
	p3pProfile->SolveMiu();
}

void C3pSolves::doSolveU3p()
{
	p3pProfile->SolveU3p();
}

void C3pSolves::doSolveL()
{
	p3pProfile->SolveL();
}

void C3pSolves::Run()
{
	doPrepare();
	
	for (int i = 0;i <p3pProfile->pOrder->LoopTimes();i++)
	{
		doSolveMiu();

		doSolveU3p();
	}
	
	doSolveL();
}

void C3pSolves::Sort3p()
{
	ValveMap vValMap;

	for each (C3pCalculate * vCal in pChildren)
	{
		//三脉动编号
		vCal->Sort3p(vValMap);
	}//

	int vK = vValMap.size();

	p3pProfile->CellDim = vK;

}

