///////////////////////////////////////////////////////////
//  CxbSolves.cpp
//  Implementation of the Class CxbSolves
//  Created on:      21-4��-2017 20:29:55
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CHvdcDefs.h"

#include "CxbFunc.h"

#include "CxbSolves.h"
#include "CxbDevBase.h"
#include "CxbDev_Tree.h"


#include "gbHead_xbCal.h"

#include <iostream>

int CxbSolves::GroundType()
{
	return pxbOrder->GroundType;
}

void CxbSolves::Init(CxbProfile* vProfile, CxbHvdcGrid * vGrid)
{
	CPowerSolves::Init(vProfile, vGrid);

	pxbHvdc = vGrid;
	pxbProfile = vProfile;

}


void CxbSolves::InitOrder(CxbOrder * vOrder)
{
	pxbOrder = vOrder;
}

void CxbSolves::NewSolves(int vGndType)
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


void CxbSolves::doNewXbSolvers10()
{

	cout << "doNewCal---�������---" << endl;

	//�������	
	doNewItem(CxbDefs::Usrc3p);
	
	doNewItem(CxbDefs::PbDKQ);
	
	doNewItem(CxbDefs::DCF);
	
	doNewItem(CxbDefs::DCLine);

	doNewItem(CxbDefs::GroundLine);


	doNewItem(CxbDefs::Ground);
	
	doNewItem(CxbDefs::XfC);
	doNewItem(CxbDefs::CoupleC);
	doNewItem(CxbDefs::PulseC);
	
	
	doNewItem(CxbDefs::Shunt);
	doNewItem(CxbDefs::Branch);
	
	doNewItem(CxbDefs::Trap);
	doNewItem(CxbDefs::Monitor);
}


void CxbSolves::doNewXbSolvers11()
{
	cout << "doNewCal---������������---" << endl;

	//������������	
	doNewItem(CxbDefs::Usrc3p);
	
	doNewItem(CxbDefs::PbDKQ);
	
	doNewItem(CxbDefs::DCF);
	
	doNewItem(CxbDefs::DCLine);

	//doNewItem(CxbDefs::GroundLine);
	//doNewItem(CxbDefs::Ground);
	
	doNewItem(CxbDefs::XfC);
	doNewItem(CxbDefs::CoupleC);
	doNewItem(CxbDefs::PulseC);
	
	doNewItem(CxbDefs::Shunt);
	doNewItem(CxbDefs::Branch);
	
	doNewItem(CxbDefs::Trap);
	
	//doNewItem(CxbDefs::Monitor);
}


void CxbSolves::doNewXbSolvers20()
{
	cout << "doNewCal---˫��---" << endl;

	doNewItem(CxbDefs::Usrc3p);
	
	doNewItem(CxbDefs::PbDKQ);
	
	doNewItem(CxbDefs::DCF);
	
	doNewItem(CxbDefs::DCLine);

	doNewItem(CxbDefs::GroundLine);
	doNewItem(CxbDefs::Ground);
	
	doNewItem(CxbDefs::XfC);
	doNewItem(CxbDefs::CoupleC);
	doNewItem(CxbDefs::PulseC);
		
	doNewItem(CxbDefs::Shunt);
	doNewItem(CxbDefs::Branch);
		
	doNewItem(CxbDefs::Trap);
	doNewItem(CxbDefs::Monitor);
}


void CxbSolves::doNewItem(int vtblType)
{
	CDevTBL * vTBL;
	
	vTBL = pxbHvdc->DeviceTBL(vtblType);
	
	doNewItem( vTBL);
}


void CxbSolves::doNewItem(CDevTBL * vTBL)
{
	for each (CxbDevBase *  vDev in  vTBL->Children())
	{
		if ((vDev->GetPosOrNeg()) == xb_Pos) //�����豸
			NewCal_Tree(vDev);


		if ((vDev->GetPosOrNeg()) == xb_Neg) //�����豸
			switch (GroundType())
			{
			case Ground20: //˫�����Ե�
			case Ground21: //˫������
				NewCal_Tree(vDev);

				break;

			default:
				break;
			}
	}
}


CPowerCalculate * CxbSolves::doNewCal(CDevBase* vDev)
{
	int vType;
	CxbCalculate * vCal = nullptr;

	vType = vDev->GetDeviceType();

	switch (vType)
	{
	case CxbDefs::Usrc3p:
		vCal = new CxbCalU3p();
		break;

	case CxbDefs::PbDKQ:
		vCal = new CxbCalPbDkq();
		break;

	case CxbDefs::DCF:
		vCal = new CxbCalDCF();
		break;

	case CxbDefs::DCF_RLC:
		vCal = new CxbCalDCF_RLC();
		break;

	case CxbDefs::DCLine:
		vCal = new CxbCalDcLine();
		break;

	case CxbDefs::GroundLine:
		vCal = new CxbCalGroundLine();
		break;

	case CxbDefs::DcLine_Seg:
		vCal = new CxbCalDcLine_Seg();
		break;

	case CxbDefs::GroundLine_Seg:
		vCal = new CxbCalGroundLine_Seg();
		break;

	case CxbDefs::Ground:
		vCal = new CxbCalGround();
		break;


	case CxbDefs::MetalLine:
		//vCal = new CxbCalMetalLine();
		break;

	case CxbDefs::XfC:
		vCal = new CxbCalXf_C();
		break;

	case CxbDefs::CoupleC:
		vCal = new CxbCalCouple_C();
		break;

	case CxbDefs::PulseC:
		vCal = new CxbCalCouple_C();
		break;

	case CxbDefs::Shunt:
		vCal = new CxbCalShunt();
		break;

	case CxbDefs::Branch:
		vCal = new CxbCalBranch();
		break;

	case CxbDefs::Monitor:
		vCal = new CxbCal_Tree();
		break;

	case CxbDefs::Trap:
		vCal = new CxbCal_Tree();
		break;

	default:
		break;

	}//switch

	 //
	vCal->Init(vDev);
	vCal->Init(pxbProfile);
	vCal->InitOrder(pxbOrder);

	//
	Add(vCal);

	//
	cout << "doNewCal---" << CxbFunc::xbTypeToName(vType) << "----" << vDev->ShowName();
	cout << "  ChildCount  " << ChildCount() << endl;

	//
	return vCal;
}

void CxbSolves::Run()
{
	//
	doPrepare();
	
	//
	doSolve();

}


void CxbSolves::doSolve()
{
	//cout << "----UpdateY---" << endl;

	//�γ�Y
	doUpdateY();

	//cout << "----UpdateI---" << endl;
	//
	doUpdateI();

	//cout << "----SolveU---" << endl;
	//
	doSolveU();

	//cout << "----SolveI---" << endl;
	//
	doSolveI();

}

void CxbSolves::doUpdateY() 
{

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateY();
	}
}


void CxbSolves::doUpdateI()
{

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateI();
	}
}


void CxbSolves::doSolveU()
{
	pxbProfile->Solve();
}

void CxbSolves::doSolveI()
{
	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->SolveI();
	}
}

void CxbSolves::SolveIeq()
{
	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->SolveIeq();
	}
}
