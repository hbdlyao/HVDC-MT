///////////////////////////////////////////////////////////
//  C3pDevGrid.cpp
//  Implementation of the Class C3pDevGrid
//  Created on:      18-5月-2017 7:12:42
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pDefs.h"

#include "C3pFunc.h"

#include "C3pDevGrid.h"

#include "C3pDevTBL.h"

#include "C3pFunc.h"

#include "gbHead_3pDevice.h"


string C3pDevGrid::TypeToName(int vType)
{

	return C3pFunc::TypeToName(vType);
}


void C3pDevGrid::Init()
{

	int i;
	CDevTBL * vTBL;
	
	for (i = C3pDefs::AcSys; i <= C3pDefs::Convertor; i++)
	{
		vTBL = NewDevTBL(i);
	}
}


CDevTBL * C3pDevGrid::doNewDevTBL(int vType)
{
	C3pDevTBL * vTBL;

	vTBL = new C3pDevTBL();

	return vTBL;
}

void C3pDevGrid::Prepare3pData(int vDType, int vLoopTimes)
{
	for each (C3pDevTBL * vTBL in  pChildren)
	{
		vTBL->Prepare3pData(vDType, vLoopTimes);
	}
}

void C3pDevGrid::NewGrid(StrVector vStaNames, int vValvePole)
{
	int vValveNum = vValvePole * 2;
	for each(string vStaName in vStaNames)
	{
		NewConvetor(vStaName, vValveNum);

		NewXf2(vStaName, vValveNum);

		NewAcSys(vStaName, vValveNum);

		NewSModeData(vStaName, vValveNum);
	}
}

void C3pDevGrid::NewConvetor(string vStaName, int vValveNum)
{
	CDevBase * vDev;

	C3pDevBase * v3pDev;

	CDevTBL * vTBL;

	string vDevName, vValveName;

	string vNodeName1, vNodeName2;

	int vType = C3pDefs::Convertor;

	vTBL = DeviceTBL(vType);
	//正极
	for (int i = 0; i <vValveNum; i++)
	{
		vDev = vTBL->NewDevice(vType);
	
		vDevName = vStaName + "---PosConvertor" + to_string(i);
		vNodeName1 = vStaName + "---Pos3p" + to_string(i);
		if (i == 0)
			vNodeName2 = vStaName + "---PosValveGnd";
		else
			vNodeName2 = vStaName + "---Pos3p" + to_string(i - 1);
	
		vDev->Init();
		//vDev->SetStaCount(1);
		//vDev->SetDotCount(2);
		vDev->SetStationName(0, vStaName);

		vDev->SetDeviceID(vDevName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);

		//vDev->SetNodeID(0, -2);
		//vDev->SetNodeID(1, -2);

		vDev->SetNodeName(0, vNodeName1);
		vDev->SetNodeName(1, vNodeName2);
		//vDev->SetParentDeviceName("平波电抗器");

		v3pDev = dynamic_cast<C3pDevBase *>(vDev);
		
		vValveName = vStaName + "Pos" + C3pFunc::ValveName(i);

		v3pDev->SetValveName(vValveName);
		v3pDev->SetPosOrNeg(Position_Pos0 + i);
	}
	//负极
	for (int i = 0; i < vValveNum; i++)
	{
		vDev = vTBL->NewDevice(vType);

		vDevName = vStaName + "---NegConvetor" + to_string(i);
		vNodeName2 = vStaName + "---Neg3p" + to_string(i);
		if (i == 0)
			vNodeName1 = vStaName + "---NegValveGnd";
		else
			vNodeName1 = vStaName + "---Neg3p" + to_string(i - 1);

		vDev->Init();
		//vDev->SetStaCount(1);
		//vDev->SetDotCount(2);
		vDev->SetStationName(0, vStaName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);
		//vDev->SetNodeID(0, -2);
		//vDev->SetNodeID(1, -2);
		vDev->SetNodeName(0, vNodeName1);
		vDev->SetNodeName(1, vNodeName2);
		//vDev->SetParentDeviceName("");

		v3pDev = dynamic_cast<C3pDevBase *>(vDev);

		vValveName = vStaName + "Neg" + C3pFunc::ValveName(i);

		v3pDev->SetValveName(vValveName);
		v3pDev->SetPosOrNeg(Position_Neg0 + i);
	}
}
void C3pDevGrid::NewXf2(string vStaName, int vValveNum)
{
	CDevBase * vDev;

	C3pDevBase * v3pDev;

	CDevTBL * vTBL;

	string vDevName, vValveName;

	string vNodeName1, vNodeName2;

	int vType = C3pDefs::Xf2;

	vTBL = DeviceTBL(vType);
	//正极
	for (int i = 0; i <vValveNum; i++)
	{
		vDev = vTBL->NewDevice(vType);

		vDevName = vStaName + "---PosXf2" + to_string(i);
		vNodeName1 = vStaName + "---Pos3p" + to_string(i);
		if (i == 0)
			vNodeName2 = vStaName + "---PosValveGnd";
		else
			vNodeName2 = vStaName + "---Pos3p" + to_string(i - 1);

		vDev->Init();
		//vDev->SetStaCount(1);
		//vDev->SetDotCount(2);
		vDev->SetStationName(0, vStaName);

		vDev->SetDeviceID(vDevName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);

		//vDev->SetNodeID(0, -2);
		//vDev->SetNodeID(1, -2);

		vDev->SetNodeName(0, vNodeName1);
		vDev->SetNodeName(1, vNodeName2);
		//vDev->SetParentDeviceName("平波电抗器");

		v3pDev = dynamic_cast<C3pDevBase *>(vDev);

		vValveName = vStaName + "Pos" + C3pFunc::ValveName(i);

		v3pDev->SetValveName(vValveName);
		v3pDev->SetPosOrNeg(Position_Pos0 + i);
	}
	//负极
	for (int i = 0; i < vValveNum; i++)
	{
		vDev = vTBL->NewDevice(vType);

		vDevName = vStaName + "---NegXf2" + to_string(i);
		vNodeName2 = vStaName + "---Neg3p" + to_string(i);
		if (i == 0)
			vNodeName1 = vStaName + "---NegValveGnd";
		else
			vNodeName1 = vStaName + "---Neg3p" + to_string(i - 1);

		vDev->Init();
		//vDev->SetStaCount(1);
		//vDev->SetDotCount(2);
		vDev->SetStationName(0, vStaName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);
		//vDev->SetNodeID(0, -2);
		//vDev->SetNodeID(1, -2);
		vDev->SetNodeName(0, vNodeName1);
		vDev->SetNodeName(1, vNodeName2);
		//vDev->SetParentDeviceName("");

		v3pDev = dynamic_cast<C3pDevBase *>(vDev);

		vValveName = vStaName + "Neg" + C3pFunc::ValveName(i);

		v3pDev->SetValveName(vValveName);
		v3pDev->SetPosOrNeg(Position_Neg0 + i);
	}
}

void C3pDevGrid::NewAcSys(string vStaName, int vValveNum)
{
	CDevBase * vDev;

	C3pDevBase * v3pDev;

	CDevTBL * vTBL;

	string vDevName, vValveName;

	string vNodeName1, vNodeName2;

	int vType = C3pDefs::Convertor;

	vTBL = DeviceTBL(vType);
	//正极
	for (int i = 0; i <vValveNum; i++)
	{
		vDev = vTBL->NewDevice(vType);

		vDevName = vStaName + "---PosAcSys" + to_string(i);
		vNodeName1 = vStaName + "---Pos3p" + to_string(i);
		if (i == 0)
			vNodeName2 = vStaName + "---PosValveGnd";
		else
			vNodeName2 = vStaName + "---Pos3p" + to_string(i - 1);

		vDev->Init();
		//vDev->SetStaCount(1);
		//vDev->SetDotCount(2);
		vDev->SetStationName(0, vStaName);

		vDev->SetDeviceID(vDevName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);

		//vDev->SetNodeID(0, -2);
		//vDev->SetNodeID(1, -2);

		vDev->SetNodeName(0, vNodeName1);
		vDev->SetNodeName(1, vNodeName2);
		//vDev->SetParentDeviceName("平波电抗器");

		v3pDev = dynamic_cast<C3pDevBase *>(vDev);

		vValveName = vStaName + "Pos" + C3pFunc::ValveName(i);

		v3pDev->SetValveName(vValveName);
		v3pDev->SetPosOrNeg(Position_Pos0 + i);
	}
	//负极
	for (int i = 0; i < vValveNum; i++)
	{
		vDev = vTBL->NewDevice(vType);

		vDevName = vStaName + "---NegAcSys" + to_string(i);
		vNodeName2 = vStaName + "---Neg3p" + to_string(i);
		if (i == 0)
			vNodeName1 = vStaName + "---NegValveGnd";
		else
			vNodeName1 = vStaName + "---Neg3p" + to_string(i - 1);

		vDev->Init();
		//vDev->SetStaCount(1);
		//vDev->SetDotCount(2);
		vDev->SetStationName(0, vStaName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);
		//vDev->SetNodeID(0, -2);
		//vDev->SetNodeID(1, -2);
		vDev->SetNodeName(0, vNodeName1);
		vDev->SetNodeName(1, vNodeName2);
		//vDev->SetParentDeviceName("");

		v3pDev = dynamic_cast<C3pDevBase *>(vDev);

		vValveName = vStaName + "Neg" + C3pFunc::ValveName(i);

		v3pDev->SetValveName(vValveName);
		v3pDev->SetPosOrNeg(Position_Neg0 + i);
	}
}

void C3pDevGrid::NewSModeData(string vStaName, int vValveNum)
{
	CDevBase * vDev;

	C3pDevBase * v3pDev;

	CDevTBL * vTBL;

	string vDevName, vValveName;

	string vNodeName1, vNodeName2;

	int vType = C3pDefs::Convertor;

	vTBL = DeviceTBL(vType);
	//正极
	for (int i = 0; i <vValveNum; i++)
	{
		vDev = vTBL->NewDevice(vType);

		vDevName = vStaName + "---PosSModeData" + to_string(i);
		vNodeName1 = vStaName + "---Pos3p" + to_string(i);
		if (i == 0)
			vNodeName2 = vStaName + "---PosValveGnd";
		else
			vNodeName2 = vStaName + "---Pos3p" + to_string(i - 1);

		vDev->Init();
		//vDev->SetStaCount(1);
		//vDev->SetDotCount(2);
		vDev->SetStationName(0, vStaName);

		vDev->SetDeviceID(vDevName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);

		//vDev->SetNodeID(0, -2);
		//vDev->SetNodeID(1, -2);

		vDev->SetNodeName(0, vNodeName1);
		vDev->SetNodeName(1, vNodeName2);
		//vDev->SetParentDeviceName("平波电抗器");

		v3pDev = dynamic_cast<C3pDevBase *>(vDev);

		vValveName = vStaName + "Pos" + C3pFunc::ValveName(i);

		v3pDev->SetValveName(vValveName);
		v3pDev->SetPosOrNeg(Position_Pos0 + i);
	}
	//负极
	for (int i = 0; i < vValveNum; i++)
	{
		vDev = vTBL->NewDevice(vType);

		vDevName = vStaName + "---NegSModeData" + to_string(i);
		vNodeName2 = vStaName + "---Neg3p" + to_string(i);
		if (i == 0)
			vNodeName1 = vStaName + "---NegValveGnd";
		else
			vNodeName1 = vStaName + "---Neg3p" + to_string(i - 1);

		vDev->Init();
		//vDev->SetStaCount(1);
		//vDev->SetDotCount(2);
		vDev->SetStationName(0, vStaName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);
		//vDev->SetNodeID(0, -2);
		//vDev->SetNodeID(1, -2);
		vDev->SetNodeName(0, vNodeName1);
		vDev->SetNodeName(1, vNodeName2);
		//vDev->SetParentDeviceName("");

		v3pDev = dynamic_cast<C3pDevBase *>(vDev);

		vValveName = vStaName + "Neg" + C3pFunc::ValveName(i);

		v3pDev->SetValveName(vValveName);
		v3pDev->SetPosOrNeg(Position_Neg0 + i);
	}
}

