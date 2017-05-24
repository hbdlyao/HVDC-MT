///////////////////////////////////////////////////////////
//  CDevGrid.cpp
//  Implementation of the Class CDevGrid
//  Created on:      20-5ÔÂ-2017 23:05:43
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CDevGrid.h"


CDevGrid::~CDevGrid()
{
	Release();
}

void CDevGrid::Release() 
{
	for each (CDevTBL * vTBL in pChildren)
	{
		delete vTBL;
		vTBL = nullptr;
	}

	pChildren.clear();

	pTables.clear();
}

void CDevGrid::Clear() 
{
	for each (CDevTBL * vTBL in pChildren)
	{
		vTBL->Clear();
	}

	//pChildren.clear();
	//pTables.clear();
}

string CDevGrid::TypeToName(int vType)
{

	string vName="CDevGrid";
	//vName = CMyFunc::TypeToName(vType);	
	return vName;
}


void CDevGrid::Init(){

	/*
	int i;
	pDevTBL * vTBL;
	
	
	for (i = xb_3pVSrc; i <= xb_GroundLine; i++)
	{
		vTBL = NewDevTBL(i);
		vTBL->SetTblType(i);	
	}
	*/
}

void CDevGrid::Add(CDevTBL* vItem)
{
	pChildren.push_back(vItem);

	//
	int vType = vItem->GetTblType();
	pTables[vType] = vItem;

}


void CDevGrid::Remove(CDevTBL* vItem){

	//children.removeElement( component );
}


CObjTBL* CDevGrid::Child(int vIndex){

	if (vIndex < ChildCount())
		return pChildren[vIndex];
	else
		return nullptr;
}


int CDevGrid::ChildCount(){

	return static_cast<int >(pChildren.size());
}


pTBLVector CDevGrid::Children(){

	return pChildren;
}


CDevTBL * CDevGrid::NewDevTBL(int vType)
{
	CDevTBL * vTBL;
	string vName;
	vName = TypeToName(vType);

	vTBL = doNewDevTBL(vType);

	vTBL->Init();
	vTBL->SetTblType(vType);
	vTBL->SetTblName(vName);

	//
	Add(vTBL);
	//	
	return vTBL;
}

CDevTBL * CDevGrid::doNewDevTBL(int vType)
{
	CDevTBL * vTBL = new CDevTBL();

	return vTBL;

}

CDevTBL * CDevGrid::DeviceTBL(int vType)
{
	return pTables[vType];
}


CDevBase * CDevGrid::Device(int vType, int vIndex){

	return DeviceTBL(vType)->Device(vIndex);
}


CDevBase * CDevGrid::Device(int vType, string vDeviceName){

	return DeviceTBL(vType)->Device(vDeviceName);
}


void CDevGrid::DeviceAdd(int vType, CDevBase* vItem)
{
	DeviceTBL(vType)->DeviceAdd(vItem->GetDeviceName(),vItem);
}


void CDevGrid::DeviceRemove(int vType, CDevBase* vItem)
{
	DeviceTBL(vType)->DeviceRemove(vType,vItem);
}


void CDevGrid::ClearNodeID()
{

	for each (CDevTBL * vTBL in pChildren)
	{
		vTBL->ClearNodeID();
	}
}


void CDevGrid::NodeSort(NodeMap& vNodeMap){

	for each (CDevTBL * vTBL in pChildren)
	{
		vTBL->NodeSort(vNodeMap);
	}
}


void CDevGrid::NodeGround(NodeMap& vNodeMap){

	for each (CDevTBL * vTBL in pChildren)
	{
		vTBL->NodeGround(vNodeMap);
	}
}


void CDevGrid::NodeID(NodeMap& vNodeID){

	for each (CDevTBL * vTBL in pChildren)
	{
		vTBL->NodeID(vNodeID);
	}
}


void CDevGrid::NewGrid(StrVector vStaNames)
{

}