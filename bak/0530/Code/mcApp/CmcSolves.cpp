///////////////////////////////////////////////////////////
//  CmcSolves.cpp
//  Implementation of the Class CmcSolves
//  Created on:      21-5月-2017 0:25:45
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcSolves.h"
#include "CmcFunc.h"
#include "gbHead_mcCal.h"

string CmcSolves::TypeToName(int vType)
{
	string vName;
	vName = CmcFunc::mcTypeToName(vType);
	
	return vName;
}


void CmcSolves::Init(CmcProfile* vProfile, CmcHvdcGrid* vGrid)
{
	CPowerSolves::Init(vProfile,vGrid);

	pmcHvdc = vGrid;
	pmcProfile = vProfile;

}


void CmcSolves::InitOrder(CmcOrder * vOrder)
{
	pmcOrder = vOrder;
}

void CmcSolves::NewSolves(int vGndType)
{
	//
	switch (vGndType)
	{
	case Ground10:
		doNewSolvers10(); //单极大地
		break;
	
	case Ground11:
		doNewSolvers11();//单极金属回线
		break;
	
	case Ground20:
		doNewSolvers20();//双极中性点
		break;
	
	case Ground21:
		doNewSolvers21();//双极并联大地
		break;
	
	default:
		break;
	}//switch
}


CPowerCalculate * CmcSolves::doNewCal(CDevBase* vDev)
{
	int vType;
	string vName;
	CmcCalculate * vCal;
	
	vType = vDev->GetDeviceType();
	switch (vType)
	{
	case CmcDefs::AcSys:
		//交流系统  
		vCal = new  CmcCalAcSys();
		break;
	
	case CmcDefs::ACF:
		//交流滤波器
		vCal = new  CmcCalAcFilter();
		break;
	
	case CmcDefs::Xf2:
		//双绕组变压器  
		vCal = new  CmcCalXf2();
		break;
	
	case CmcDefs::Convertor:
		//换流器  
		vCal = new  CmcCalConvertor();
		break;
	
	case CmcDefs::DcLine:
		//直流极线  
		vCal = new  CmcCalDcLine();
		break;
	
	case CmcDefs::GroundLine:
		//接地极线  
		vCal = new  CmcCalGroundLine();
		break;
	
	case CmcDefs::MetalLine:
		//金属回线  
		vCal = new  CmcCalMetalLine();
		break;
	
	case CmcDefs::Ground:
		//接地极  
		vCal = new  CmcCalGround();
		break;
	
	default:
		vCal = nullptr;
		break;
	
	}//switch
	
	//
	vCal->Init(vDev);
	vCal->Init(pmcProfile);
	vCal->InitOrder(pmcOrder);
	
	//
	Add(vCal);
	
	//
	//cout << "doNewCal---" << CmcFunc::mcTypeToName(vType) << "  " << vName << endl;

	return vCal;
}


void CmcSolves::doNewSolvers10()
{

	//单极大地
	
	doNewItem(CmcDefs::AcSys);
	
	doNewItem(CmcDefs::ACF);
	
	doNewItem(CmcDefs::Xf2);
	
	doNewItem(CmcDefs::Convertor);
	
	doNewItem(CmcDefs::DcLine);
	
	doNewItem(CmcDefs::GroundLine);
	
	//doNewItem(Ground);
	
	//doNewItem(CmcDefs::MetalLine);
}


void CmcSolves::doNewSolvers11(){

	//单极金属回线
	
	doNewItem(CmcDefs::AcSys);
	
	doNewItem(CmcDefs::ACF);
	
	doNewItem(CmcDefs::Xf2);
	
	doNewItem(CmcDefs::Convertor);
	
	doNewItem(CmcDefs::DcLine);
	
	//doNewItem(CmcDefs::GroundLine);
	
	//doNewItem(Ground);
	
	doNewItem(CmcDefs::MetalLine);
}


void CmcSolves::doNewSolvers20(){

	//双极中性点
	
	doNewItem(CmcDefs::AcSys);
	
	doNewItem(CmcDefs::ACF);
	
	doNewItem(CmcDefs::Xf2);
	
	doNewItem(CmcDefs::Convertor);
	
	doNewItem(CmcDefs::DcLine);
	
	
	//doNewItem(CmcDefs::GroundLine);
	
	//doNewItem(Ground);
	
	//doNewItem(CmcDefs::MetalLine);
}


void CmcSolves::doNewSolvers21(){

	//双极并联
	
	doNewItem(CmcDefs::AcSys);
	
	doNewItem(CmcDefs::ACF);
	
	doNewItem(CmcDefs::Xf2);
	
	doNewItem(CmcDefs::Convertor);
	
	doNewItem(CmcDefs::DcLine);
	
	doNewItem(CmcDefs::GroundLine);
	
	//doNewItem(Ground);
	
	//doNewItem(CmcDefs::MetalLine);
}


void CmcSolves::Run()
{
	doPrepare();

	doUpdateUdio();

	while (true)
	{
		pmcProfile->LimitOK = true;

		doSovleDcNet();

		doLimitUd();

		if (pmcProfile->LimitOK)
			doCalStation();

		if (pmcProfile->LimitOK)
			break;
	}
}


void CmcSolves::PrepareNormal() 
{
	//
	for each (CmcCalculate * vCal in pChildren)
	{
		vCal->PrepareNormal();
	}
}



double CmcSolves::doGetMaxdX()
{

	return pmcProfile->GetMaxdX();
}


void CmcSolves::doOffsetSort()
{

	pmcProfile->OffSet();
	pmcProfile->ResetMatrix();
}


void CmcSolves::doSaveX()
{

	pmcProfile->SaveX();
}

void CmcSolves::doPrepare()
{
	pmcProfile->IsUrefToGround = pmcOrder->IsUdToGround;
	for each (CmcCalculate * vCal in pChildren)
	{
		vCal->Prepare();
	}
	
	//
	pmcProfile->UpdateBalanceStation();
}


void CmcSolves::doInit_XVect()
{

	pmcProfile->InitX();
}


void CmcSolves::doSovleDcNet()
{

	doOffsetSort();
	
	//初始化,X0
	doInit_XVect();
	
	//形成Y
	doUpdateY();
	
	//用NL法求解直流网络
	while (true)
	{
		doUpdateJ();//和换流器对应的部分
		//
		doUpdateF();
		//
		doSolve_dX();
		//
		doUpdateX();
	
		if (doGetMaxdX() < Epsilon)
			break;
	}//while
	
	doSaveX();
}


void CmcSolves::doSolve_dX()
{

	pmcProfile->Solve_dX();
}


void CmcSolves::doUpdateF()
{

	pmcProfile->UpdateF_Y();//和节点导纳对应的部分
	
	pmcProfile->UpdateF_J();//和换流器对应的部分
}


void CmcSolves::doUpdateJ()
{

	pmcProfile->UpdateJ();
}


void CmcSolves::doUpdateY(){

	//对每一个CmcCalculate
	for each (CmcCalculate * vCal in pChildren)
	{
		vCal->UpdateY();
	}
}


void CmcSolves::doUpdateX()
{
	pmcProfile->UpdateX();
}


void CmcSolves::doCalStation()
{

	pmcProfile->CalStation();
}


void CmcSolves::doUpdateUdio(){

	pmcProfile->UpdateUdio();
}


void CmcSolves::doLimitUd()
{

	pmcProfile->LimitUd();
}

