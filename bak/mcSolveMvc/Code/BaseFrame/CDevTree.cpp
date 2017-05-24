///////////////////////////////////////////////////////////
//  CDevTree.cpp
//  Implementation of the Class CDevTree
//  Created on:      21-4ÔÂ-2017 19:40:47
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CDevTree.h"


CDevTree::CDevTree()
{
	SetStaCount(1);
	SetDotCount(0);
}

void CDevTree::Add(CDevBase* vItem)
{
	pChildren.push_back(vItem);
}

void CDevTree::ClearNodeID()
{
	for each (CDevBase * vDev in pChildren)
	{
		vDev->ClearNodeID();	
	}
}


void CDevTree::NodeSort(NodeMap& vNodeMap)
{
	for each (CDevBase * vDev in pChildren)
	{
		vDev->NodeSort(vNodeMap);	
	}
}


void CDevTree::NodeGround(NodeMap& vNodeMap)
{

	for each (CDevBase * vDev in pChildren)
	{
		vDev->NodeGround(vNodeMap);	
	}
}

void CDevTree::NodeID(NodeMap& vNodeID)
{
	for each (CDevBase * vDev in pChildren)
	{
		vDev->NodeID(vNodeID);	
	}
}