///////////////////////////////////////////////////////////
//  CxbDev_Tree.cpp
//  Implementation of the Class CxbDev_Tree
//  Created on:      17-4ÔÂ-2017 17:24:53
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDev_Tree.h"

void CxbDev_Tree::Init()
{
	SetStaCount(1);
	SetDotCount(0);

	InitData();
}

void CxbDev_Tree::Add(CDevBase * vItem)
{
	pChildren.push_back(vItem);
}

bool CxbDev_Tree::IsLeaf()
{
	return false;
}

void CxbDev_Tree::ClearNodeID()
{
	for each (CDevBase * vDev in  pChildren)
	{
		vDev->ClearNodeID();
	}
}


void CxbDev_Tree::NodeSort(NodeMap& vNodeMap)
{
	for each (CDevBase * vDev in  pChildren)
	{
		vDev->NodeSort(vNodeMap);
	}

}

void CxbDev_Tree::NodeGround(NodeMap & vNodeMap)
{
	for each (CDevBase * vDev in  pChildren)
	{
		vDev->NodeGround(vNodeMap);
	}

}


void CxbDev_Tree::NodeID(NodeMap& vNodeID)
{

	for each (CDevBase * vDev in  pChildren)
	{
		vDev->NodeID(vNodeID);
	}

}

void CxbDev_Tree::Prepare_hRLC()
{
	for each (CxbDevBase * vDev in  pChildren)
	{
		vDev->Prepare_hRLC();
	}

}


void CxbDev_Tree::Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim)
{
	for each (CxbDevBase * vDev in  pChildren)
	{
		vDev->Prepare_hRLC(vFreStart, vFreStep, vFreDim);
	}

}
