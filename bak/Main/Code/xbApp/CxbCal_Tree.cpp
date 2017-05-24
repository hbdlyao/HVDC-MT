///////////////////////////////////////////////////////////
//  CxbCal_Tree.cpp
//  Implementation of the Class CxbCal_Tree
//  Created on:      21-4��-2017 20:03:35
///////////////////////////////////////////////////////////

#include "CxbCal_Tree.h"
#include "CxbFunc.h"
#include "CxbDevBase.h"
#include "CxbDev_Tree.h"

#include "gbHead_xbCal.h"

void CxbCal_Tree::Init(CPowerProfile* vProfile)
{
	pProfile = vProfile;
	pxbProfile = dynamic_cast<CxbProfile *> (pProfile);

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Init(vProfile);
	}
}


void CxbCal_Tree::Init(CDevBase* vDev)
{
	pDevice = vDev;
}


void CxbCal_Tree::Add(CxbCalculate * vItem)
{
	pChildren.push_back(vItem);
}


bool CxbCal_Tree::IsLeaf()
{
	return false;
}

void CxbCal_Tree::Prepare()
{

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Prepare();
	}
}


void CxbCal_Tree::NodeID(NodeMap& vNodeID)
{

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->NodeID(vNodeID);
	}
}



void CxbCal_Tree::NodeSort(NodeMap& vNodeMap)
{

	//Children
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->NodeSort(vNodeMap);
	}
}


void CxbCal_Tree::NodeGround(NodeMap& vNodeMap)
{

	//Children
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->NodeGround(vNodeMap);
	}
}


void CxbCal_Tree::StationSort(StationMap& vStaMap)
{

	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->StationSort(vStaMap);
	}//
}


CxbCalculate * CxbCal_Tree::doNewCal(CDevBase* vDev)
{
	int vType;
	CxbCalculate * vCal = nullptr;
	
	vType = vDev->GetDeviceType();
	
	switch (vType)
	{
	case CxbDefs::Usrc3p:
		vCal = new CxbCal3pVSrc();
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
	
	
	//case CxbDefs::MetalLine:
		//vCal = new CxbCalMetalLine();
	//	break;
	
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
	cout << "doNewCal---" << CxbFunc::xbTypeToName(vType) << "----" << vDev->GetDeviceName();
	cout << "  ChildCount  " << ChildCount() << endl;

	//
	return vCal;

}

void CxbCal_Tree::NewCal_Tree(CDevBase* vDev)
{
	CPowerCalculate * vCal;
	CxbDev_Tree * vNode;

	//
	vCal = doNewCal(vDev);

	//
	if (!vDev->IsLeaf())
	{
		vNode = dynamic_cast<CxbDev_Tree * >(vDev);
		for each (CDevBase* vDev in vNode->Children())
		{
			vCal->NewCal_Tree(vDev);
		}//for 

	}//else
}

void CxbCal_Tree::UpdateY()
{

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateY();
	}
}
void CxbCal_Tree::UpdateI() 
{

	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->UpdateI();
	}
}
void CxbCal_Tree::SolveI()
{
	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->SolveI();
	}
}

void CxbCal_Tree::SolveIeq()
{
	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->SolveIeq();
	}
}


void CxbCal_Tree::Update_zkY()
{
	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Update_zkY();
	}
}

void CxbCal_Tree::Update_zkI()
{
	//��ÿһ��CxbCalculate
	for each (CxbCalculate * vCal in pChildren)
	{
		vCal->Update_zkI();
	}
}
