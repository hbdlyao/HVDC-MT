///////////////////////////////////////////////////////////
//  CPowerCalculate.cpp
//  Implementation of the Class CPowerCalculate
//  Created on:      22-5ÔÂ-2017 12:38:24
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CPowerCalculate.h"


CPowerCalculate::~CPowerCalculate()
{
	Release();
}


void CPowerCalculate::Release()
{
	for each (CPowerCalculate * vCal in pChildren)
	{
		delete vCal;
		vCal = nullptr;
	}
	
	pChildren.clear();
}

void CPowerCalculate::Clear() 
{

	for each (CPowerCalculate * vCal in pChildren)
	{
		delete vCal;
		vCal = nullptr;
	}

	pChildren.clear();
}


void CPowerCalculate::Init(CDevBase* vDev)
{
	pDevice = vDev;
}


void CPowerCalculate::Init(CPowerProfile* vProfile)
{

	pProfile = vProfile;
}


void CPowerCalculate::Add(CPowerCalculate* vItem){

}


void CPowerCalculate::Remove(CPowerCalculate* vItem){

}


bool CPowerCalculate::IsLeaf(){

	return true;
}


int CPowerCalculate::ChildCount(){

	return static_cast<int >(pChildren.size());
}


CPowerCalculate * CPowerCalculate::Child(int vIndex)
{
	if (vIndex < ChildCount())
		return dynamic_cast<CPowerCalculate *>(pChildren[vIndex]);
	else
		return nullptr;

}

pCalVector CPowerCalculate::Children(){

	return pChildren;
}


void CPowerCalculate::NewCal_Tree(CDevBase* vDev){

}


void CPowerCalculate::Prepare(){

}


void CPowerCalculate::StationSort(StationMap& vStaMap){

	int vN, vID;
	string vName;
	
	vName = pDevice->GetStationName();
	vN = static_cast<int > (vStaMap.count(vName));
	
	if (vN == 0)
	{//²»´æÔÚ vName
		vID = static_cast<int> (vStaMap.size());
		vStaMap[vName] = vID;
	}
	
	StationIndex = vStaMap[vName];
}


void CPowerCalculate::NodeSort(NodeMap& vNodeMap){

	pDevice->NodeSort(vNodeMap);
}


void CPowerCalculate::NodeGround(NodeMap& vNodeMap){

	pDevice->NodeGround(vNodeMap);
}


void CPowerCalculate::NodeID(NodeMap& vNodeID){

	pDevice->NodeID(vNodeID);
}