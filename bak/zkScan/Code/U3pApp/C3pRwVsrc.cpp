///////////////////////////////////////////////////////////
//  C3pRwVsrc.cpp
//  Implementation of the Class C3pRwVsrc
//  Created on:      18-5月-2017 8:16:42
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pRwVsrc.h"
#include "C3pDevVSrc.h"

#include <iostream>


void C3pRwVsrc::OnLoad()
{
	C3pRwTwo::OnLoad();
	
	doLoad_hData();
}


void C3pRwVsrc::OnSave()
{
	C3pRwTwo::OnSave();
	
	doSave_hData();
}


void C3pRwVsrc::doLoad(CDevBase* vDevice){

	string vStr;
	_variant_t vValue;
	C3pDevVSrc * vDev;
	
	vDev = dynamic_cast<C3pDevVSrc *>(vDevice);
	
	C3pRwTwo::doLoad(vDev);
	//
}


void C3pRwVsrc::doLoad_hData()
{

	///////////////////////////////////////////
	CDevTBL * vTBL;
	
	vTBL = pGrid->DeviceTBL(tblType);
	for each (C3pDevVSrc * vDev in  vTBL->Children())
	{
		//
		doLoad_hData(vDev);
	
	
	}//for each
}


void C3pRwVsrc::doLoad_hData(C3pDevVSrc* vDev)
{
/*
	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;
	int vh;
	
	//
	vSQL = "select * from " + tblName + "_hData ";
	vSQL = vSQL + " where DeviceName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vDev->GetDeviceName();
	vSQL = vSQL + "' ";
	vSQL = vSQL + " order by DeviceName ,hOrder ";
	
	vOk = RwAdo->OpenSQL(vSQL);
	
	if (vOk)
	{
		cout << "Load---" + tblName + "_hData " << endl;
	
		while (!RwAdo->IsEOF())
		{
			RwAdo->GetFieldValue("hOrder", vValue);
			if (vValue.vt != VT_NULL)
			{
				vh = vValue.iVal;
			};
	
			RwAdo->GetFieldValue("hUrms", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->Set_hUrms(vh, vValue.dblVal);
			};
	
			RwAdo->GetFieldValue("hAngle", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->Set_hAngle(vh, vValue.dblVal);
			};
			RwAdo->GetFieldValue("hYb", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->Set_hYb(vh, vValue.dblVal);
			};
	
			//
			RwAdo->Record_MoveNext();
	
	
		}//while
	
		cout << "   --" << vDev->GetDeviceName() << endl;
	
	}//if
	
	RwAdo->CloseTBL();
	*/

}


void C3pRwVsrc::doSave(CDevBase* vDevice){

	string vStr;
	_variant_t vValue;
	C3pDevVSrc * vDev;
	
	vDev = dynamic_cast<C3pDevVSrc *>(vDevice);
	
	C3pRwTwo::doSave(vDev);
}


void C3pRwVsrc::doSave_hData()
{
/*
	///////////////////////////////////////////
	CDevTBL * vTBL;
	
	vTBL = pGrid->DeviceTBL(tblType);
	for each (C3pDevVSrc * vDev in  vTBL->Children())
	{
		//
		//doSave_hData(vDev);
	
	}//for each
}


void C3pRwVsrc::doSave_hData(C3pDevVSrc* vDev){

	string vSQL, vStr;
	_variant_t vValue;
	
	bool vOk = S_FALSE;
	int i;
	
	vSQL = "delete * from " + tblName + "_hData ";
	vSQL = vSQL + " where DeviceName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vDev->GetDeviceName();
	vSQL = vSQL + "' ";
	
	vOk = RwAdo->ExecSQL(vSQL);
	
	vSQL = "select * from " + tblName + "_hData ";
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));
	
	//
	if (vOk)
	{
		cout << "save---" + tblName + "_hData " << endl;
	
		for (i = 1; i<=vDev->hMax(); i++)
		{
			RwAdo->Record_AddNew();
			//
			vValue = _variant_t(i);//整型
			RwAdo->SetFieldValue("hOrder", vValue);
	
			vValue = _variant_t(vDev->Get_hUrms(i));//双精度
			RwAdo->SetFieldValue("hUrms", vValue);
	
			vValue = _variant_t(vDev->Get_hAngle(i));//双精度
			RwAdo->SetFieldValue("hAngle", vValue);
			
			vValue = _variant_t(vDev->Get_hYb(i));//双精度
			RwAdo->SetFieldValue("hYb", vValue);
			
			//
			RwAdo->Record_Update();
	
		}//
	
		cout << "   --" << vDev->GetDeviceName() << endl;
	
	}//if
	
	RwAdo->CloseTBL();
	
	*/
}

void C3pRwVsrc::doSave_hData(C3pDevVSrc * vDev)
{
}
