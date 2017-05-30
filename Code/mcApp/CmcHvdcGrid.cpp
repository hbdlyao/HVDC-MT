///////////////////////////////////////////////////////////
//  CmcHvdcGrid.cpp
//  Implementation of the Class CmcHvdcGrid
//  Created on:      21-5ÔÂ-2017 0:51:09
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcHvdcGrid.h"

#include "CmcDevTBL.h"

#include "CmcFunc.h"
#include "CmcDefs.h"
#include "gbHead_mcDevice.h"


void CmcHvdcGrid::Init(){

	int i;
	CDevTBL * vTBL;
	
	for (i = CmcDefs::AcSys; i <= CmcDefs::Ground; i++)
	{
		vTBL = NewDevTBL(i);
		vTBL->SetTblType(i);
	}
}


string CmcHvdcGrid::TypeToName(int vType){

	return CmcFunc::mcTypeToName(vType);
}

CDevTBL * CmcHvdcGrid::doNewDevTBL(int vType)
{
	CDevTBL * vTBL = new CmcDevTBL();

	return vTBL;

}


void CmcHvdcGrid::NewGrid(StrVector vStaNames)
{
	for each (string vStaName in vStaNames)
	{
		NewAcFilterTBL(vStaName);

		NewAcSysTBL(vStaName);

		NewXf2TBL(vStaName);

		NewConvertorTBL(vStaName);

		//´Þ¿µÉú20170528-NewGrid
		NewGroundLineTBL(vStaName);

		//´Þ¿µÉú20170528-NewGrid
		NewGroundTBL(vStaName);
	}
}

void CmcHvdcGrid::NewAcFilterTBL(string vStaName)
{
	CDevTBL * vTBL;
	CDevBase * vDev;
	int vType;
	string vDevName;
	//string vNodeName;

	vType = CmcDefs::ACF;
	vDevName = vStaName + "---ACF";
	//vNodeName = vStaName + "---" + mcNodeNameACF[0];

	vTBL = DeviceTBL(vType);
	vDev = vTBL->NewDevice(vType);
	vDev->Init();

	vDev->SetStationName(0, vStaName);

	vDev->SetDeviceID(vDevName);
	vDev->SetDeviceName(vDevName);
	vDev->SetDeviceType(vType);

	//vDev->SetNodeName(0,vNodeName);

	vTBL->DeviceAdd(vDevName, vDev);
}

void CmcHvdcGrid::NewAcSysTBL(string vStaName)
{
	CDevTBL * vTBL;
	CDevBase * vDev;
	int vType;
	string vDevName;
	//string vNodeName;

	vType = CmcDefs::AcSys;
	vDevName = vStaName + "---AcSys";
	//vNodeName = vStaName + "---" + mcNodeNameACSys[0];

	vTBL = DeviceTBL(vType);
	vDev = vTBL->NewDevice(vType);
	vDev->Init();

	vDev->SetStationName(0, vStaName);

	vDev->SetDeviceID(vDevName);
	vDev->SetDeviceName(vDevName);
	vDev->SetDeviceType(vType);

	//vDev->SetNodeName(0,vNodeName);

	vTBL->DeviceAdd(vDevName, vDev);
}

void CmcHvdcGrid::NewConvertorTBL(string vStaName)
{
	CDevTBL * vTBL;
	CDevBase * vDev;
	int vType;
	string vDevName;
	string vNodeName1;
	string vNodeName2;

	vType = CmcDefs::Convertor;
	vDevName = vStaName + "---Convertor";
	vNodeName1 = vStaName + "---" + mcNodeNameConvertor[0];
	vNodeName2 = vStaName + "---" + mcNodeNameConvertor[1];

	vTBL = DeviceTBL(vType);
	vDev = vTBL->NewDevice(vType);
	vDev->Init();

	vDev->SetStationName(0, vStaName);

	vDev->SetDeviceID(vDevName);
	vDev->SetDeviceName(vDevName);
	vDev->SetDeviceType(vType);

	vDev->SetNodeName(0, vNodeName1);
	vDev->SetNodeName(1, vNodeName2);

	vTBL->DeviceAdd(vDevName, vDev);
}

void CmcHvdcGrid::NewXf2TBL(string vStaName)
{
	CDevTBL * vTBL;
	CDevBase * vDev;
	int vType;
	string vDevName;
	//string vNodeName;

	vType = CmcDefs::Xf2;
	vDevName = vStaName + "---Xf2";
	//vNodeName = vStaName + "---" + mcNodeNameACF[0];

	vTBL = DeviceTBL(vType);
	vDev = vTBL->NewDevice(vType);
	vDev->Init();

	vDev->SetStationName(0, vStaName);

	vDev->SetDeviceID(vDevName);
	vDev->SetDeviceName(vDevName);
	vDev->SetDeviceType(vType);

	//vDev->SetNodeName(0,vNodeName);

	vTBL->DeviceAdd(vDevName, vDev);
}

//´Þ¿µÉú20170528-NewGrid
void CmcHvdcGrid::NewGroundLineTBL(string vStaName)
{
	CDevTBL * vTBL;
	CDevBase * vDev;
	int vType;
	string vDevName;
	string vNodeName;

	vType = CmcDefs::GroundLine;
	vDevName = vStaName + "---GroundLine";
	vNodeName = vStaName + "---" + mcNodeNameGroundLine[0];

	vTBL = DeviceTBL(vType);
	vDev = vTBL->NewDevice(vType);
	vDev->Init();

	vDev->SetStationName(0, vStaName);

	vDev->SetDeviceID(vDevName);
	vDev->SetDeviceName(vDevName);
	vDev->SetDeviceType(vType);

	vDev->SetNodeName(0,vNodeName);

	vTBL->DeviceAdd(vDevName, vDev);
}

//´Þ¿µÉú20170528-NewGrid
void CmcHvdcGrid::NewGroundTBL(string vStaName)
{
	CDevTBL * vTBL;
	CDevBase * vDev;
	int vType;
	string vDevName;
	string vNodeName;

	vType = CmcDefs::Ground;
	vDevName = vStaName + "---Ground";
	vNodeName = vStaName + "---" + mcNodeNameGround[0];

	vTBL = DeviceTBL(vType);
	vDev = vTBL->NewDevice(vType);
	vDev->Init();

	vDev->SetStationName(0, vStaName);

	vDev->SetDeviceID(vDevName);
	vDev->SetDeviceName(vDevName);
	vDev->SetDeviceType(vType);

	vDev->SetNodeName(0, vNodeName);

	vTBL->DeviceAdd(vDevName, vDev);
}