///////////////////////////////////////////////////////////
//  CDevTBL.cpp
//  Implementation of the Class CDevTBL
//  Created on:      26-4ÔÂ-2017 19:38:20
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CDevTBL.h"
#include "CMyFunc.h"

CDevTBL::~CDevTBL()
{
	Release();
}

void CDevTBL::Release()
{
	for each (CObjBase * vObj in pChildren)
	{
		delete vObj;
		vObj = nullptr;
	}

	pChildren.clear();
}

void CDevTBL::Clear()
{
	for each (CObjBase * vObj in pChildren)
	{
		//vObj->Clear();

		delete vObj;
		vObj = nullptr;
	}

	pChildren.clear();
}

CDevBase * CDevTBL::NewDevice(int vDevType)
{

	string vID,vName;
	CDevBase * vDev;
	
	vID = CMyFunc::CreateObjID();
	vName = TypeToName(vDevType) + to_string(ChildCount()) + "_" + vID;
	
	vDev = NewDevice(vDevType, vID, vName);
	
	return  vDev;
}


CDevBase * CDevTBL::NewDevice(int vDevType, string vID)
{

	CDevBase * vDev;
	
	vDev = NewDevice(vDevType, vID, vID);
	
	return  vDev;
}


CDevBase * CDevTBL::NewDevice(int vDevType, string vID, string vName)
{
	CDevBase * vDev;
	
	vDev = doNewDevice(vDevType);

	vDev->Init();
	vDev->SetDeviceID(vID);
	vDev->SetDeviceName(vName);
	vDev->SetDeviceType(vDevType);
	
	
	return vDev;
}


void CDevTBL::DeviceAdd(string vID, CDevBase* vItem)
{
	Add(vItem);
}


void CDevTBL::DeviceRemove(int vType, CDevBase* vItem)
{
	Remove(vItem);
}



CDevBase * CDevTBL::doNewDevice(int vDevType)
{
	return nullptr;
}

CDevBase* CDevTBL::Device(string vDevName)
{
	CDevBase* vDevice = nullptr;

	for each(CDevBase* vDev in pChildren)
	{
		string vName = vDev->GetDeviceName();
		if (vName ==(vDevName))
		{
			vDevice = vDev;

			break;
		}
	}

	return vDevice;

}

CDevBase* CDevTBL::Device(int vIndex)
{
	return dynamic_cast<CDevBase*> (Child(vIndex));
}


void CDevTBL::ClearNodeID()
{

	for each (CDevBase * vDev in pChildren)
	{
		vDev->ClearNodeID();	
	}
}


string CDevTBL::TypeToName(int vDevType)
{

	string vName = "CDevTBL";
	
	//vName = CMyFunc::TypeToName(vType);
	
	return vName;
}


void CDevTBL::NodeSort(NodeMap& vNodeMap)
{

	for each (CDevBase * vDev in pChildren)
	{
		vDev->NodeSort(vNodeMap);	
	}
}


void CDevTBL::NodeGround(NodeMap& vNodeMap)
{

	for each (CDevBase * vDev in pChildren)
	{
		vDev->NodeGround(vNodeMap);	
	}
}


void CDevTBL::NodeID(NodeMap& vNodeID)
{

	for each (CDevBase * vDev in pChildren)
	{
		vDev->NodeID(vNodeID);	
	}
}