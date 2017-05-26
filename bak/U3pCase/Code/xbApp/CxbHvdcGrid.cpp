///////////////////////////////////////////////////////////
//  CxbHvdcGrid.cpp
//  Implementation of the Class CxbHvdcGrid
//  Created on:      22-5月-2017 14:08:32
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbHvdcGrid.h"

#include "CxbDevTBL.h"
#include "CxbDefs.h"
#include "CxbFunc.h"
#include "gbHead_xbDevice.h"

void CxbHvdcGrid::Init(){

	for (int i = CxbDefs::Usrc3p; i <= CxbDefs::GroundLine; i++)
		NewDevTBL(i);
}


string CxbHvdcGrid::TypeToName(int vType){

	string vName;
	vName = CxbFunc::xbTypeToName(vType);
	
	return vName;
}


CDevTBL * CxbHvdcGrid::doNewDevTBL(int vType){

	CDevTBL * vTBL = new CxbDevTBL();
	
	return vTBL;
}


void CxbHvdcGrid::Prepare_hRLC(){

	for each (CxbDevTBL * vTBL in  pChildren)
	{
		vTBL->Prepare_hRLC();
	}
}


void CxbHvdcGrid::Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim){

	for each (CxbDevTBL * vTBL in  pChildren)
	{
		vTBL->Prepare_hRLC(vFreStart, vFreStep, vFreDim);
	}
}


void CxbHvdcGrid::NewGrid(StrVector vStaNames, int vValvePole)
{

	for each(string vStaName in vStaNames)
	{
		NewVSrc3pTBL(vStaName, vValvePole);
	
		NewXfCTBL(vStaName, vValvePole);
	
		NewPbDKQTBL(vStaName);
	
		NewDCFTBL(vStaName);
	
		NewGroundTBL(vStaName);
	
		NewCoupleCTBL(vStaName);
	
		NewPulseCTBL(vStaName);
	
		NewTrapTBL(vStaName);
	
		NewMonitorTBL(vStaName);
	
		NewGroundLineTBL(vStaName);
	
	
		//vType = CxbDefs::GroundLine_Seg;
		//NewDevTBL(vType);
	
		//vType = CxbDefs::GroundLine;
		//NewDevTBL(vType);
	}
}


void CxbHvdcGrid::NewVSrc3pTBL(string vStaName, int vValvePole)
{

	CDevBase * vDev;
	
	CDevTBL * vTBL;
	
	string vDevName;
	
	string vNodeName1, vNodeName2;
	
	int vType = CxbDefs::Usrc3p;
	
	vTBL = DeviceTBL(vType);
	//正极
	for (int i = 0; i < 4 * vValvePole; i++)
	{
		vDev = vTBL->NewDevice(vType);
	
		vDevName = vStaName + "---PosVSrc3p" + to_string(i);
		vNodeName1 = vStaName + "---Pos3p" + to_string(i);
		if (i == 0)
			vNodeName2 = vStaName + "---PosValveGnd";
		else
			vNodeName2 = vStaName + "---Pos3p" + to_string(i - 1);
	
		vDev->Init();
		vDev->SetStaCount(1);
		vDev->SetDotCount(2);
		vDev->SetStationName(0, vStaName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);
		vDev->SetNodeID(0, -2);
		vDev->SetNodeID(1, -2);
		vDev->SetNodeName(0, vNodeName1);
		vDev->SetNodeName(1, vNodeName2);
		//vDev->SetParentDeviceName("");
	}
	//负极
	for (int i = 0; i < 4 * vValvePole; i++)
	{
	
		vDev = vTBL->NewDevice(vType);
	
		vDevName = vStaName + "---NegVSrc3p" + to_string(i);
		vNodeName1 = vStaName + "---Neg3p" + to_string(i);
		if (i == 0)
			vNodeName2 = vStaName + "---NegValveGnd";
		else
			vNodeName2 = vStaName + "---Neg3p" + to_string(i - 1);
	
		vDev->Init();
		vDev->SetStaCount(1);
		vDev->SetDotCount(2);
		vDev->SetStationName(0, vStaName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);
		vDev->SetNodeID(0, -2);
		vDev->SetNodeID(1, -2);
		vDev->SetNodeName(0, vNodeName1);
		vDev->SetNodeName(1, vNodeName2);
		//vDev->SetParentDeviceName("");
	}
}


void CxbHvdcGrid::NewXfCTBL(string vStaName, int vValvePole)
{

	CDevBase * vDev;
	
	CDevTBL * vTBL;
	
	string vDevName;
	
	string vNodeName;
	
	int vType = CxbDefs::XfC;
	
	vTBL = DeviceTBL(vType);
	//正极
	for (int i = 0; i < 2 * vValvePole; i++)
	{
	
		vDev = vTBL->NewDevice(vType);
	
		vDevName = vStaName + "---PosXfC" + to_string(i);
		vNodeName = vStaName + "---Pos3p" + to_string(i * 2 + 1);
	
		vDev->Init();
		vDev->SetStaCount(1);
		vDev->SetDotCount(1);
		vDev->SetStationName(0, vStaName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);
		vDev->SetNodeID(0, -2);
		vDev->SetNodeID(1, -2);
		vDev->SetNodeName(0, vNodeName);
		//vDev->SetParentDeviceName("");
	}
	//负极
	for (int i = 0; i < 4 * vValvePole; i++)
	{
	
		vDev = vTBL->NewDevice(vType);
	
		vDevName = vStaName + "---NegXfC3p" + to_string(i);
		vNodeName = vStaName + "---Neg3p" + to_string(i * 2 + 1);
	
		vDev->Init();
		vDev->SetStaCount(1);
		vDev->SetDotCount(1);
		vDev->SetStationName(0, vStaName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);
		vDev->SetNodeID(0, -2);
		vDev->SetNodeID(1, -2);
		vDev->SetNodeName(0, vNodeName);
		//vDev->SetParentDeviceName("");
	}
}


void CxbHvdcGrid::NewPbDKQTBL(string vStaName)
{

	CDevBase * vDev;
	
	CxbDevBase * vxbDev;
	
	CDevTBL * vTBL;
	
	string vDevName;
	
	string vNodeName1, vNodeName2;
	
	int vType = CxbDefs::PbDKQ;
	
	vTBL = DeviceTBL(vType);
	
	for (int i = 0; i < 8; i++)
	{
		vDev = vTBL->NewDevice(vType);
	
		vDevName = vStaName + "---PbDKQ" + to_string(i);
		vNodeName1 = vStaName + "---" + xbNodeNamePbDKQ[i * 2];
		vNodeName2 = vStaName + "---" + xbNodeNamePbDKQ[i * 2 + 1];
	
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
		vxbDev = dynamic_cast<CxbDevBase *>(vDev);
		if (i<4)
			vxbDev->SetPosOrNeg(xb_Pos);
		else
			vxbDev->SetPosOrNeg(xb_Neg);
	}
}


void CxbHvdcGrid::NewDCFTBL(string vStaName)
{

	CDevBase * vDev;
	
	CxbDevBase * vxbDev;
	
	CDevTBL * vTBL;
	
	string vDevName;
	
	string vNodeName1, vNodeName2;
	
	int vType = CxbDefs::DCF;
	
	vTBL = DeviceTBL(vType);
	
	for (int i = 0; i < 4; i++)
	{
		vDev = vTBL->NewDevice(vType);
	
		vDevName = vStaName + "---DCF" + to_string(i);
		vNodeName1 = vStaName + "---" + xbNodeNameDCF[i * 2];
		vNodeName2 = vStaName + "---" + xbNodeNameDCF[i * 2 + 1];
	
		vDev->Init();
		vDev->SetStaCount(1);
		vDev->SetDotCount(2);
		vDev->SetStationName(0, vStaName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);
		vDev->SetNodeID(0, -2);
		vDev->SetNodeID(1, -2);
		vDev->SetNodeName(0, vNodeName1);
		vDev->SetNodeName(1, vNodeName2);
		//vDev->SetParentDeviceName("直流滤波器");
		vxbDev = dynamic_cast<CxbDevBase *>(vDev);
		if (i<2)
			vxbDev->SetPosOrNeg(xb_Pos);
		else
			vxbDev->SetPosOrNeg(xb_Neg);
	}
}


void CxbHvdcGrid::NewGroundTBL(string vStaName)
{

	CDevBase * vDev;
	
	CDevTBL * vTBL;
	
	string vDevName;
	
	string vNodeName;
	
	int vType = CxbDefs::Ground;
	
	vTBL = DeviceTBL(vType);
	
	vDev = vTBL->NewDevice(vType);
	
	vDevName = vStaName + "---Ground" + to_string(0);
	vNodeName = vStaName + "---" + xbNodeNameGround[0];
	
	vDev->Init();
	vDev->SetStaCount(1);
	vDev->SetDotCount(1);
	vDev->SetStationName(0, vStaName);
	vDev->SetDeviceName(vDevName);
	vDev->SetDeviceType(vType);
	vDev->SetNodeID(0, -2);
	vDev->SetNodeID(1, -2);
	vDev->SetNodeName(0, vNodeName);
	//vDev->SetParentDeviceName("接地电阻");
	
	//vxbDev->SetPosOrNeg(2);
}


void CxbHvdcGrid::NewCoupleCTBL(string vStaName){

	CDevBase * vDev;
	
	CxbDevBase * vxbDev;
	
	CDevTBL * vTBL;
	
	string vDevName;
	
	string vNodeName;
	
	int vType = CxbDefs::CoupleC;
	
	vTBL = DeviceTBL(vType);
	
	for (int i = 0; i < 2; i++)
	{
		vDev = vTBL->NewDevice(vType);
	
		vDevName = vStaName + "---CoupleC" + to_string(i);
		vNodeName = vStaName + "---" + xbNodeNameCoupleC[i];
	
		vDev->Init();
		vDev->SetStaCount(1);
		vDev->SetDotCount(1);
		vDev->SetStationName(0, vStaName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);
		vDev->SetNodeID(0, -2);
		vDev->SetNodeID(1, -2);
		vDev->SetNodeName(0, vNodeName);
		//vDev->SetParentDeviceName("耦合电容器");
		vxbDev = dynamic_cast<CxbDevBase *>(vDev);
		if (i<1)
			vxbDev->SetPosOrNeg(xb_Pos);
		else
			vxbDev->SetPosOrNeg(xb_Neg);
	}
}


void CxbHvdcGrid::NewPulseCTBL(string vStaName){

	CDevBase * vDev;
	
	CxbDevBase * vxbDev;
	
	CDevTBL * vTBL;
	
	string vDevName;
	
	string vNodeName;
	
	int vType = CxbDefs::PulseC;
	
	vTBL = DeviceTBL(vType);
	
	for (int i = 0; i < 2; i++)
	{
		vDev = vTBL->NewDevice(vType);
	
		vDevName = vStaName + "---PulseC" + to_string(i);
		vNodeName = vStaName + "---" + xbNodeNamePulseC[i];
	
		vDev->Init();
		vDev->SetStaCount(1);
		vDev->SetDotCount(1);
		vDev->SetStationName(0, vStaName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);
		vDev->SetNodeID(0, -2);
		vDev->SetNodeID(1, -2);
		vDev->SetNodeName(0, vNodeName);
		//vDev->SetParentDeviceName("冲激电容器");
		vxbDev = dynamic_cast<CxbDevBase *>(vDev);
		if (i<1)
			vxbDev->SetPosOrNeg(xb_Pos);
		else
			vxbDev->SetPosOrNeg(xb_Neg);
	}
}


void CxbHvdcGrid::NewTrapTBL(string vStaName){

	CDevBase * vDev;
	
	CxbDevBase * vxbDev;
	
	CDevTBL * vTBL;
	
	string vDevName;
	
	string vNodeName1, vNodeName2;
	
	int vType = CxbDefs::Trap;
	
	vTBL = DeviceTBL(vType);
	
	for (int i = 0; i < 4; i++)
	{
		vDev = vTBL->NewDevice(vType);
	
		vDevName = vStaName + "---Trap" + to_string(i);
		vNodeName1 = vStaName + "---" + xbNodeNameTrap[i * 2];
		vNodeName2 = vStaName + "---" + xbNodeNameTrap[i * 2 + 1];
	
		vDev->Init();
		vDev->SetStaCount(1);
		vDev->SetDotCount(2);
		vDev->SetStationName(0, vStaName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);
		vDev->SetNodeID(0, -2);
		vDev->SetNodeID(1, -2);
		vDev->SetNodeName(0, vNodeName1);
		vDev->SetNodeName(1, vNodeName2);
		//vDev->SetParentDeviceName("阻波器");
		vxbDev = dynamic_cast<CxbDevBase *>(vDev);
		if (i<2)
			vxbDev->SetPosOrNeg(xb_Pos);
		else
			vxbDev->SetPosOrNeg(xb_Neg);
	
	}
}


void CxbHvdcGrid::NewMonitorTBL(string vStaName)
{

	CDevBase * vDev;
	
	CDevTBL * vTBL;
	
	string vDevName;
	
	string vNodeName1, vNodeName2;
	
	int vType = CxbDefs::Monitor;
	
	vTBL = DeviceTBL(vType);
	
	for (int i = 0; i < 2; i++)
	{
		vDev = vTBL->NewDevice(vType);
	
		vDevName = vStaName + "---Monitor" + to_string(i);
		vNodeName1 = vStaName + "---" + xbNodeNameMonitor[i * 2];
		vNodeName2 = vStaName + "---" + xbNodeNameMonitor[i * 2 + 1];
	
		vDev->Init();
		vDev->SetStaCount(1);
		vDev->SetDotCount(2);
		vDev->SetStationName(0, vStaName);
		vDev->SetDeviceName(vDevName);
		vDev->SetDeviceType(vType);
		vDev->SetNodeID(0, -2);
		vDev->SetNodeID(1, -2);
		vDev->SetNodeName(0, vNodeName1);
		vDev->SetNodeName(1, vNodeName2);
		//vDev->SetParentDeviceName("监控装置");
	
		//vxbDev->SetPosOrNeg(2);
	}
}


void CxbHvdcGrid::NewGroundLineTBL(string vStaName)
{

	CDevBase * vDev;
	
	CDevTBL * vTBL;
	
	string vDevName;
	
	string vNodeName[4];
	
	int vType = CxbDefs::GroundLine;
	
	vTBL = DeviceTBL(vType);
	
	vDev = vTBL->NewDevice(vType);
	
	vDevName = vStaName + "---GLine" + to_string(0);
	for (int i = 0; i < 4; i++)
		vNodeName[i] = vStaName + "---" + xbNodeNameGroundLine[i];
	
	
	vDev->Init();
	vDev->SetStaCount(1);
	vDev->SetDotCount(4);
	vDev->SetStationName(0, vStaName);
	vDev->SetDeviceName(vDevName);
	vDev->SetDeviceType(vType);
	vDev->SetNodeID(0, -2);
	vDev->SetNodeID(1, -2);
	for (int i = 0; i < 4; i++)
		vDev->SetNodeName(i, vNodeName[i]);
	//vDev->SetParentDeviceName("接地极线");
	
	
	////Seg
	//vType = CxbDefs::GroundLine_Seg;
	
	//vTBL = DeviceTBL(vType);
	
	//vDev = vTBL->NewDevice(vType);
	
	//vDevName = vStaName + "---GLine" + to_string(0) + "_Seg" + to_string(0);
	//for (int i = 0;i < 4;i++)
	//	vNodeName[i] = vStaName + "---" + xbNodeNameGroundLine[i];
	
	
	//vDev->Init();
	//vDev->SetStaCount(1);
	//vDev->SetDotCount(4);
	//vDev->SetStationName(0, vStaName);
	//vDev->SetDeviceName(vDevName);
	//vDev->SetDeviceType(vType);
	//vDev->SetNodeID(0, -2);
	//vDev->SetNodeID(1, -2);
	//for (int i = 0;i < 4;i++)
	//	vDev->SetNodeName(i, vNodeName[i]);
	////vDev->SetParentDeviceName("接地极线");
}