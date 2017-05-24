///////////////////////////////////////////////////////////
//  CPowerSolves.cpp
//  Implementation of the Class CPowerSolves
//  Created on:      09-4��-2017 21:38:12
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CPowerSolves.h"

CPowerSolves::~CPowerSolves()
{
	Release();
}

void CPowerSolves::Release()
{
	for each (CPowerCalculate * vCal in pChildren)
	{
		delete vCal;
		vCal = nullptr;
	}

	pChildren.clear();
}

void CPowerSolves::Clear() 
{

	for each (CPowerCalculate * vCal in pChildren)
	{
		delete vCal;
		vCal = nullptr;
	}

	pChildren.clear();
}

void CPowerSolves::Init(CPowerProfile * vProfile, CPowerGrid * vGrid)
{
	pProfile = vProfile;
	pGrid = vGrid;
}


void CPowerSolves::Add(CPowerCalculate* vItem)
{

	pChildren.push_back(vItem);
}


void CPowerSolves::Remove(CPowerCalculate* vItem)
{

	//children.removeElement( component );
}


int CPowerSolves::ChildCount()
{

	return static_cast<int >(pChildren.size());
}


CPowerCalculate * CPowerSolves::Child(int vIndex)
{

	return dynamic_cast<CPowerCalculate * >(pChildren[vIndex]);
}


pPowerCalVector CPowerSolves::Children()
{

	return pChildren;
}



void CPowerSolves::NewSolves()
{
	//
	for each (CDevTBL * vTBL in  pGrid->Children())
	{
		doNewItem(vTBL);
	}
}

void CPowerSolves::doNewItem(int vtblType)
{
	CDevTBL * vTBL;

	vTBL = pGrid->DeviceTBL(vtblType);

	doNewItem(vTBL);
}


void CPowerSolves::doNewItem(CDevTBL * vTBL)
{

	for each (CDevBase * vDev in  vTBL->Children())
	{
		NewCal_Tree(vDev);
	}

}

/**
 * Cal��Devһ�£�Ҳ�γ�Tree
 */
void CPowerSolves::NewCal_Tree(CDevBase* vDev)
{
	//Cal��Devһ�£�Ҳ�γ�Tree
	CPowerCalculate * vCal;

	vCal = doNewCal(vDev);

	//
	if (!vDev->IsLeaf())
	{
		//vNode = dynamic_cast<CDevTree *>(vDev);
		//for each (CDevBase* vDev in vNode->Children())
		for each (CDevBase* vChild in vDev->Children())
		{
			vCal->NewCal_Tree(vChild);
		}//for 
	}
}


/**
 * ��Device�ֽ����豸��cal���γ�tree
 */
void CPowerSolves::NewCal_Tree_1(CDevBase* vDev) 
{
	//��Device�ֽ����豸��cal���γ�tree
	CPowerCalculate * vCal;

	if (vDev->IsLeaf())
	{
		vCal = doNewCal(vDev);
	}
	else
	{
		for each (CDevBase* vChild in vDev->Children())
		{
			NewCal_Tree_1(vChild);
		}//for
	}//else
}

CPowerCalculate* CPowerSolves::doNewCal(CDevBase * vDev)
{

	int vType;
	string vName;
	CPowerCalculate * vCal = nullptr;

	vType = vDev->GetDeviceType();

	switch (vType)
	{
	case 0:
		break;

	default:
		vCal = new  CPowerCalculate();

		break;

	}//switch
	
	//
	Add(vCal);

	//
	return vCal;

}



void CPowerSolves::Run()
{

}


void CPowerSolves::StationSort()
{
	StationMap vStaMap;

	doStationSort(vStaMap);

	//pmcProfile->StaCount = static_cast<int>(vStaMap.size());
	
}


void CPowerSolves::NodeID()
{
	int vK = 0;
	
	NodeMap vNodeID, vNodeMap;
	
	//
	pGrid->ClearNodeID();
	
	//
	doNodeSort(vNodeMap);
	//
	doNodeGround(vNodeMap);

	//
	vK = 0;
	for each (pair<string, int> vPair in vNodeMap)
	{
		//��ȥ�ӵؽڵ�
		if (vPair.second != -1)
		{
			vNodeID[vPair.first] = vK;
	
			vK = vK + 1;
		}
		else
			vNodeID[vPair.first] = -1;
	
	}// for each
	
	 //
	pProfile->SetYdim(vK);

	//
	doNodeID(vNodeID);
	//

	//
	pProfile->pNodeMap = vNodeMap;
	pProfile->pNodeID = vNodeID;

}


void CPowerSolves::doNodeSort(NodeMap& vNodeMap)
{
	for each (CPowerCalculate * vCal in pChildren)
	{
		//�����нڵ��ţ������ӵصĽڵ�
		vCal->NodeSort(vNodeMap);
	}//

}


void CPowerSolves::doNodeGround(NodeMap& vNodeMap)
{

	//Children
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->NodeGround(vNodeMap);
	}
}


void CPowerSolves::doNodeID(NodeMap& vNodeID)
{

	//��ÿһ��CPowerCalculate
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->NodeID(vNodeID);
	}
}


void CPowerSolves::doStationSort(StationMap& vStaMap)
{

	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->StationSort(vStaMap);
	}//
}


void CPowerSolves::doPrepare()
{

	//��ÿһ��CxbCalculate
	for each (CPowerCalculate * vCal in pChildren)
	{
		vCal->Prepare();
	}
}

