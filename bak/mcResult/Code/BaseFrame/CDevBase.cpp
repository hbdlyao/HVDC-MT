///////////////////////////////////////////////////////////
//  CDevBase.cpp
//  Implementation of the Class CDevBase
//  Created on:      22-5月-2017 11:04:47
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CDevBase.h"

CDevBase::~CDevBase()
{
	Release();
}

void CDevBase::Release()
{
	delete[] NodeIDs;
	delete[] NodeNames;
	delete[] StaNames;

	//
	for each (CDevBase * vDev in pChildren)
	{
		delete vDev;
		vDev = nullptr;
	}

	pChildren.clear();
}


void CDevBase::Clear()
{
	//delete[] NodeIDs;
	//delete[] NodeNames;
	//delete[] StaNames;

	for each (CDevBase * vDev in pChildren)
	{
		vDev->Clear();
	}

	//pChildren.clear();

}

void CDevBase::Init()
{
}

bool CDevBase::IsLeaf()
{
	//bool vOk;
	//vOk = (ChildCount() == 0);

	return true;
}


void CDevBase::Add(CDevBase* vItem)
{

}


void CDevBase::Remove(CDevBase* vItem)
{
	//
}

int CDevBase::ChildCount()
{
	return static_cast<int >(pChildren.size());
}


CDevBase * CDevBase::Child(int vIndex)
{
	if (vIndex < ChildCount())
		return dynamic_cast<CDevBase *>(pChildren[vIndex]);
	else
		return nullptr;

}


pObjVector CDevBase::Children()
{
	return pChildren;
}


string CDevBase::GetDeviceID()
{
	return DeviceID;
}




void CDevBase::SetDeviceID(string newVal){

	DeviceID = newVal;
	//objGUID = newVal; ?
}


string CDevBase::GetDeviceName(){

	return DeviceName;
}


void CDevBase::SetDeviceName(string newVal){

	DeviceName = newVal;
	//objName = newVal;
}


string CDevBase::GetParentDeviceName(){

	return ParentDeviceName;
}


void CDevBase::SetParentDeviceName(string newVal){

	ParentDeviceName = newVal;
	//objName = newVal;
}


int CDevBase::GetDeviceType(){

	return DeviceType;
}


void CDevBase::SetDeviceType(int newVal){

	DeviceType = newVal;
	//objType = newVal;
}


string CDevBase::GetStationName(){

	return StaNames[0];
}


string CDevBase::ShowName(){

	string vStr = StaNames[0] + "--" + DeviceName;
	return vStr;
}


int CDevBase::GetDotCount(){

	return dotCount;
}


void CDevBase::SetDotCount(int newVal){

	dotCount = newVal;
	
	NodeIDs = new int[newVal];
	NodeNames = new string[newVal];
	
	for (int i = 0; i < dotCount; i++)
	{
		NodeIDs[i] = -2;
		NodeNames[i] = GetDeviceName() + "--NodeNames-2";
	
	}
}


int CDevBase::GetStaCount()
{
	return staCount;
}


void CDevBase::SetStaCount(int newVal){

	staCount = newVal;
	
	StaNames = new string[newVal];
	
	for (int i = 0; i < staCount; i++)
	{
		StaNames[i] = "StationName" + to_string(i + 1);
	}
}


string CDevBase::GetStationName(int vIndex){

	return StaNames[vIndex];
}


void CDevBase::SetStationName(int vIndex, string newVal){

	StaNames[vIndex] = newVal;
}


string CDevBase::GetNodeName(int vIndex){

	return  NodeNames[vIndex];
}


void CDevBase::SetNodeName(int vIndex, string vName){

	NodeNames[vIndex] = vName;
}


int CDevBase::GetNodeID(int vIndex){

	return  NodeIDs[vIndex];
}


void CDevBase::SetNodeID(int vIndex, int vID){

	NodeIDs[vIndex] = vID;
}


string CDevBase::BusName(int vIndex){

	string vBus;
	
	//vBus = DeviceName + "--" + GetNodeName(vIndex);
	
	vBus = GetNodeName(vIndex);
	
	return vBus;
}


void CDevBase::ClearNodeID(){

	int vN = GetDotCount();
	for (int i = 0; i < vN; i++)
	{
		SetNodeID(i, -2);
	}//for i
}


void CDevBase::NodeSort(NodeMap& vNodeMap){

	int vN, vID;
	string vBus;
	
	int vK = GetDotCount();
	for (int i = 0; i < vK; i++)
	{
		vBus = BusName(i);
		vN = static_cast<int > (vNodeMap.count(vBus));
	
		if (vN == 0)
		{//不存在 vName
			vID = static_cast<int> (vNodeMap.size());
			vNodeMap[vBus] = vID;
		}
	
		if (vBus == "-1")//-1表示接地
			vNodeMap[vBus] = -1;
	
	}//for i
}


void CDevBase::NodeGround(NodeMap& vNodeMap){

}


void CDevBase::NodeID(NodeMap& vNodeID){

	int vID;
	string vBus;
	
	int vN = GetDotCount();
	for (int i = 0; i < vN; i++)
	{
		vBus = BusName(i);
		vID = vNodeID[vBus];
	
		SetNodeID(i, vID);
	
	}//for i
}