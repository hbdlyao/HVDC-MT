///////////////////////////////////////////////////////////
//  CPowerCal_Tree.cpp
//  Implementation of the Class CPowerCal_Tree
//  Created on:      21-4��-2017 18:10:14
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CPowerCal_Tree.h"
#include "CDevTree.h"


void CPowerCal_Tree::Init(CPowerProfile* vProfile)
{
	pProfile = vProfile;

	//��ÿһ��CPowerCalculate
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->Init(vProfile);
	}
}


void CPowerCal_Tree::Init(CDevBase* vDev)
{
	pDevice = vDev;
}


void CPowerCal_Tree::Add(CPowerCalculate * vItem)
{
	pChildren.push_back(vItem);
}


bool CPowerCal_Tree::IsLeaf()
{
	return false;
}


void CPowerCal_Tree::NodeID(NodeMap& vNodeID)
{

	//��ÿһ��CPowerCalculate
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->NodeID(vNodeID);
	}
}



void CPowerCal_Tree::NodeSort(NodeMap& vNodeMap)
{

	//Children
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->NodeSort(vNodeMap);
	}
}


void CPowerCal_Tree::NodeGround(NodeMap& vNodeMap)
{

	//Children
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->NodeGround(vNodeMap);
	}
}


void CPowerCal_Tree::StationSort(StationMap& vStaMap)
{

	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->StationSort(vStaMap);
	}//
}


/**
 * Cal��Devһ�£�Ҳ�γ�Tree
 */
void CPowerCal_Tree::NewCal_Tree(CDevBase* vDev)
{
	//Cal��Devһ�£�Ҳ�γ�Tree
	
	CPowerCalculate * vCal;
	CDevTree * vNode;

	vCal = doNewCal(vDev);

	//
	if (!vDev->IsLeaf())
	{
		vNode = dynamic_cast<CDevTree *>(vDev);
		for each (CDevBase* vDev in vNode->Children())
		{
			vCal->NewCal_Tree(vDev);
		}//for 
	}
}


/**
 * ��Device�ֽ����豸��cal���γ�tree
 */
void CPowerCal_Tree::NewCal_Tree_1(CDevBase* vDev)
{//��Device�ֽ����豸��cal���γ�tree

	int i, vN;

	CDevBase * vChild;
	CDevTree * vNode;
	CPowerCalculate * vCal;

	if (vDev->IsLeaf())
	{
		vCal=doNewCal(vDev);

		//vName = vDev->GetDeviceName();
		//vCal->SelfID = vName;
		//vCal->SelfType = vType;

		//
		vCal->Init(vDev);
		vCal->Init(pProfile);
	}
	else
	{
		vNode = dynamic_cast<CDevTree *> (vDev);
		vN = vNode->ChildCount();
		for (i = 0; i<vN; i++)
		{
			vChild = vNode->Child(i);
			NewCal_Tree(vChild);
		}//for
	}//else
}

CPowerCalculate * CPowerCal_Tree::doNewCal(CDevBase* vDev)
{
	int vType;
	string vName;
	CPowerCalculate * vCal = nullptr;

	vType = vDev->GetDeviceType();
	switch (vType)
	{
	case 1:
		break;

	default:
		vCal = new CPowerCalculate();
		break;


	}//switch

	//
	Add(vCal);

	//
	//cout << "doNewCal---" << xbTypeToName(vType) << "----" << vName;
	//cout << "  ChildCount  " << ChildCount() << endl;

	//
	return vCal;

}


void CPowerCal_Tree::Prepare()
{

	//��ÿһ��CxbCalculate
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->Prepare();
	}
}


