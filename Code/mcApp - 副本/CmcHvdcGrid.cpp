///////////////////////////////////////////////////////////
//  CmcHvdcGrid.cpp
//  Implementation of the Class CmcHvdcGrid
//  Created on:      21-5月-2017 0:51:09
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


//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  NewGrid
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.实现NewGrid方法功能
// 改动时间:  2017/05/23
//************************************
void CmcHvdcGrid::NewGrid(StrVector vStaNames)
{
	for each (string vStaName in vStaNames)
	{
		NewAcFilterTBL(vStaName);

		NewAcSysTBL(vStaName);

		NewXf2TBL(vStaName);

		NewConvertorTBL(vStaName);
	}
}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  NewAcFilterTBL至NewXf2TBL
// 改动者:    崔康生
// 改动类型:  新增
// 改动内容:  1.创建一个换流站对应设备类型的设备
// 改动时间:  2017/05/23
//************************************
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
	vNodeName1 = vStaName + "---" + xbNodeNameConvertor[0];
	vNodeName2 = vStaName + "---" + xbNodeNameConvertor[1];

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