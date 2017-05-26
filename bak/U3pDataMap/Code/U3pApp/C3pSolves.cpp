
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

	p3pHvdc = vGrid;
	p3pProfile = vProfile;

}


void C3pSolves::InitOrder(C3pOrder * vOrder)
{
	p3pOrder = vOrder;
}

void C3pSolves::NewSolves(int vGndType)
{
	//
	switch (vGndType)
	{
	case Ground10:
		doNewXbSolvers10(); //�������
		break;

	case Ground11:
		doNewXbSolvers11();//������������
		break;

	case Ground20:
		doNewXbSolvers20();//˫��
		break;

	default:
		break;
	}//switch
}


void C3pSolves::doNewXbSolvers10()
{
	cout << "doNewCal---�������---" << endl;

	doNewItem(C3pDefs::ACF);

	doNewItem(C3pDefs::AcSys);

	doNewItem(C3pDefs::Convertor);

	doNewItem(C3pDefs::Xf2);
}


void C3pSolves::doNewXbSolvers11()
{
	cout << "doNewCal---������������---" << endl;

	doNewItem(C3pDefs::ACF);

	doNewItem(C3pDefs::AcSys);

	doNewItem(C3pDefs::Convertor);

	doNewItem(C3pDefs::Xf2);
}


void C3pSolves::doNewXbSolvers20()
{
	cout << "doNewCal---˫��---" << endl;
	//
	doNewItem(C3pDefs::ACF);

	doNewItem(C3pDefs::AcSys);

	doNewItem(C3pDefs::Convertor);

	doNewItem(C3pDefs::Xf2);
}



int C3pSolves::GroundType()
{
	return p3pOrder->GroundType;
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
		if ((vDev->GetPosOrNeg()) == C3pDefs::Pos) //�����豸
			doNewCal(vDev);

		if ((vDev->GetPosOrNeg()) == C3pDefs::Neg) //�����豸
			switch (GroundType())
			{
			case Ground20: //˫�����Ե�
			case Ground21: //˫������
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
	C3pCalculate * vCal = nullptr;

	vType = vDev->GetDeviceType();
	switch (vType)
	{
	case C3pDefs::AcSys:
		//����ϵͳ  
		vCal = new  C3pCalAcSys();
		break;

	case C3pDefs::Xf2:
		//˫�����ѹ��  
		vCal = new  C3pCalXf2();
		break;

	case C3pDefs::Convertor:
		//������  
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
	vCal->InitOrder(p3pOrder);

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
	
	for (int i = 0;i <p3pOrder->LoopTimes();i++)
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
		//���������
		vCal->Sort3p(vValMap);
	}//

	int vK = vValMap.size();

	p3pProfile->CellDim = vK;

}
