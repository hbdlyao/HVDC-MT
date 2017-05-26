///////////////////////////////////////////////////////////
//  C3pRwStaData.cpp
//  Implementation of the Class C3pRwStaData
//  Created on:      26-5��-2017 18:28:34
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pRwStaData.h"

#include <iostream>

string C3pRwStaData::GetSQL_Load()
{
	string vSQL;
	
	//
	vSQL = "select StationName  from mcResult";
	//vSQL = vSQL + " where StationName = ";
	//vSQL = vSQL + " '";
	//vSQL = vSQL + vDev->GetStationName();
	//vSQL = vSQL + "' ";
	vSQL = vSQL + " group by StationName ";

	return vSQL;

}

void C3pRwStaData::OnLoad()
{
	C3pRw::OnLoad();
	
	doLoad_hCase();
	doLoad_hData();
}


void C3pRwStaData::OnSave()
{
}


void C3pRwStaData::doLoad(CDevBase* vDevice)
{

	string vStr;
	_variant_t vValue;
	C3pDevStaData * vDev;
	
	vDev = dynamic_cast<C3pDevStaData *>(vDevice);
	
	//
	RwAdo->GetFieldValue("StationName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue; //�ַ���			
		
		vDev->SetStationName(0,vStr);

		vDev->SetDeviceName(vStr);
		vDev->SetDeviceID(vStr);
		vDev->SetDeviceType(C3pDefs::StaData);

	};

}


void C3pRwStaData::doLoad_hCase()
{
	///////////////////////////////////////////
	CDevTBL * vTBL;
	
	vTBL = pGrid->DeviceTBL(tblType);
	for each (C3pDevStaData * vDev in  vTBL->Children())
	{
		doLoad_hCase(vDev);
	
	}//for each
}


void C3pRwStaData::doLoad_hCase(C3pDevStaData* vDev)
{
	string  vSQL;
	string  vStr;
	_variant_t vValue;
	
	//
	vSQL = "select CalName,CaseID,PdPercent  from mcResult" ;
	vSQL = vSQL + " where StationName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vDev->GetStationName();
	vSQL = vSQL + "' ";
	vSQL = vSQL + " group by CalName,CaseID,PdPercent ";
	
	RwAdo->OpenSQL(vSQL);
	
	int vN = RwAdo->Record_RowCount();
	
	while (!RwAdo->IsEOF())
	{
		string vCalName, vCaseID;
		double vPdPer;
	
		RwAdo->GetFieldValue("CalName", vValue);
		if (vValue.vt != VT_NULL)
		{
			vCalName = (_bstr_t)vValue; //�ַ���			
		};
	
		RwAdo->GetFieldValue("CaseID", vValue);
		if (vValue.vt != VT_NULL)
		{
			vCaseID = (_bstr_t)vValue; //�ַ���			
		};
	
		RwAdo->GetFieldValue("PdPercent", vValue);
		if (vValue.vt != VT_NULL)
		{
			vPdPer = vValue.dblVal; //�ַ���			
		};
	
		//
		vDev->NewStaData(vCalName, vCaseID, vPdPer);
	
		//
		RwAdo->Record_MoveNext();
	
			
	}//while
	
	cout << "  ---StaData-" + vDev->GetDeviceName() << endl;

	RwAdo->CloseTBL();
}


void C3pRwStaData::doLoad_hData()
{

	///////////////////////////////////////////
	CDevTBL * vTBL;

	vTBL = pGrid->DeviceTBL(tblType);
	for each (C3pDevStaData * vDev in  vTBL->Children())
	{
		for each(C3pCase* vData in vDev->DataVect)
			doLoad_hData(vData);

	}//for each
}


void C3pRwStaData::doLoad_hData(C3pCase* vData)
{

	string  vSQL, vStr;
	_variant_t vValue;
	
	//
	vSQL = "select * from mcResult ";
	vSQL = vSQL + " Where ";
	vSQL = vSQL + " StationName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vData->StationName;
	vSQL = vSQL + "' ";

	vSQL = vSQL + " and ";
	vSQL = vSQL + " CalName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vData->Get_hCalName();
	vSQL = vSQL + "' ";
	
	vSQL = vSQL + " and ";
	vSQL = vSQL + " CaseID = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vData->Get_hCaseID();
	vSQL = vSQL + "' ";
	
	vSQL = vSQL + " and ";
	vSQL = vSQL + " PdPercent = ";
	vSQL = vSQL + to_string(vData->Get_hPdPer());
	
	
	RwAdo->OpenSQL(vSQL);
	
	int vN = RwAdo->Record_RowCount();

	while (!RwAdo->IsEOF())
	{
		RwAdo->GetFieldValue("CalName", vValue);
		if (vValue.vt != VT_NULL)
		{
			vStr = (_bstr_t)vValue; //�ַ���
			vData->Set_hCalName(vStr);
		};
	
		RwAdo->GetFieldValue("CaseID", vValue);
		if (vValue.vt != VT_NULL)
		{
			vStr = (_bstr_t)vValue; //�ַ���
			vData->Set_hCaseID(vStr);
		};
	
		RwAdo->GetFieldValue("PdPercent", vValue);
		if (vValue.vt != VT_NULL)
		{
			vData->Set_hPdPer(vValue.dblVal);
		};
			
		//����

		//
		RwAdo->Record_MoveNext();
	
	
	}//while
	
	cout << "  ---StaData-" << vData->StationName;
	cout << "---" << vData->Get_hCalName();
	cout << "---" << vData->Get_hCaseID();
	cout << "---" << vData->Get_hPdPer();
	cout << endl;
	
	RwAdo->CloseTBL();
	
	//
}

