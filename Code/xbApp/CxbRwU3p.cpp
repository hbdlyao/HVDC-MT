///////////////////////////////////////////////////////////
//  CxbRwU3p.cpp
//  Implementation of the Class CxbRwU3p
//  Created on:      18-4ÔÂ-2017 17:17:11
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwU3p.h"
#include "CxbParams.h"

#include <iostream>
//

void CxbRwU3p::OnLoad()
{
	CxbRwTwo::OnLoad();

	doLoad_hCase();
	doLoad_hData();
}

void CxbRwU3p::OnSave()
{
	CxbRwTwo::OnSave();

	doSave_hData();
}

void CxbRwU3p::doLoad(CDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevU3p * vDev;

	vDev = dynamic_cast<CxbDevU3p *>(vDevice);

	CxbRwTwo::doLoad(vDev);
	//

}


void CxbRwU3p::doLoad_hCase()
{
	///////////////////////////////////////////
	CDevTBL * vTBL;

	vTBL = pGrid->DeviceTBL(tblType);
	for each (CxbDevU3p * vDev in  vTBL->Children())
	{
		doLoad_hCase(vDev);

	}//for each

}

void CxbRwU3p::doLoad_hCase(CxbDevU3p * vDev)
{
	string  vSQL;
	string  vStr;
	_variant_t vValue;

	//
	vSQL = "select CalName,CaseID,PdPercent  from " + tblName+"_hData" ;
	vSQL = vSQL + " where DeviceName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vDev->GetDeviceName();
	vSQL = vSQL + "' ";
	vSQL = vSQL + " group by CalName,CaseID,PdPercent ";

	RwAdo->OpenSQL(vSQL);

	//int vN = RwAdo->Record_RowCount();

	while (!RwAdo->IsEOF())
	{
		string vCalName, vCaseID;
		double vPdPer;

		RwAdo->GetFieldValue("CalName", vValue);
		if (vValue.vt != VT_NULL)
		{
			vCalName = (_bstr_t)vValue; //×Ö·ûÐÍ			
		};

		RwAdo->GetFieldValue("CaseID", vValue);
		if (vValue.vt != VT_NULL)
		{
			vCaseID = (_bstr_t)vValue; //×Ö·ûÐÍ			
		};

		RwAdo->GetFieldValue("PdPercent", vValue);
		if (vValue.vt != VT_NULL)
		{
			vPdPer = vValue.dblVal; //×Ö·ûÐÍ			
		};

		//
		vDev->NewU3pData(vCalName, vCaseID, vPdPer);

		//
		RwAdo->Record_MoveNext();

		cout << "  ---U3pCase-" + vDev->GetDeviceName() << endl;

	}//while

	 //
	RwAdo->CloseTBL();

}


void CxbRwU3p::doLoad_hData()
{
	///////////////////////////////////////////
	CDevTBL * vTBL;

	vTBL = pGrid->DeviceTBL(tblType);
	for each (CxbDevU3p * vDev in  vTBL->Children())
	{
		for each(CxbU3pData* vData in vDev->DataVect)
			doLoad_hData(vData);

	}//for each

}

void CxbRwU3p::doLoad_hData(CxbU3pData* vData)
{
	string  vSQL, vStr;
	_variant_t vValue;

	//
	vSQL = "select * from " + tblName + "_hData ";
	vSQL = vSQL + " Where ";
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

	vSQL = vSQL + " order by hOrder ";

	RwAdo->OpenSQL(vSQL);
	
	//
	int vh;
	while (!RwAdo->IsEOF())
	{
		RwAdo->GetFieldValue("CalName", vValue);
		if (vValue.vt != VT_NULL)
		{
			vStr = (_bstr_t)vValue; //×Ö·ûÐÍ
			vData->Set_hCalName(vStr);
		};

		RwAdo->GetFieldValue("CaseID", vValue);
		if (vValue.vt != VT_NULL)
		{
			vStr = (_bstr_t)vValue; //×Ö·ûÐÍ
			vData->Set_hCaseID(vStr);
		};

		RwAdo->GetFieldValue("PdPercent", vValue);
		if (vValue.vt != VT_NULL)
		{
			vData->Set_hPdPer(vValue.dblVal);
		};

		//
		RwAdo->GetFieldValue("hOrder", vValue);
		if (vValue.vt != VT_NULL)
		{
			vh = vValue.iVal;
		};

		RwAdo->GetFieldValue("hUrms", vValue);
		if (vValue.vt != VT_NULL)
		{
			vData->Set_hUrms(vh, vValue.dblVal);
		};

		RwAdo->GetFieldValue("hAngle", vValue);
		if (vValue.vt != VT_NULL)
		{
			vData->Set_hAngle(vh, vValue.dblVal);
		};
		RwAdo->GetFieldValue("hYb", vValue);
		if (vValue.vt != VT_NULL)
		{
			vData->Set_hYb(vh, vValue.dblVal);
		};

		//
		RwAdo->Record_MoveNext();


	}//while

	cout << "  ---U3pData-" << vData->DeviceName << endl;

	RwAdo->CloseTBL();

	//
}


void CxbRwU3p::doSave(CDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevU3p * vDev;

	vDev = dynamic_cast<CxbDevU3p *>(vDevice);

	CxbRwTwo::doSave(vDev);


}

void CxbRwU3p::doSave_hData()
{
	///////////////////////////////////////////
	CDevTBL * vTBL;

	vTBL = pGrid->DeviceTBL(tblType);
	for each (CxbDevU3p * vDev in  vTBL->Children())
	{
		//
		//doSave_hData(vDev);

	}//for each

}


void CxbRwU3p::doSave_hData(CxbDevU3p * vDev)
{
	string vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;

	vSQL = "delete * from " + tblName + "_hData ";
	vSQL = vSQL + " where DeviceName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vDev->GetDeviceName();
	vSQL = vSQL + "' ";

	RwAdo->ExecSQL(vSQL);

	//
	cout << "save---" + tblName + "_hData " << endl;

	for (int i = 1; i <= vDev->hMax(); i++)
	{
		//
		SqlStr = "Insert into " + tblName + "_hData ";
		SqlParam = "";
		//
		SqlStr = SqlStr + " (";
		SqlParam = SqlParam + " Values ( ";

		SqlStr = SqlStr + "hOrder, ";
		SqlParam = SqlParam + GetString(i) + " , ";

		SqlStr = SqlStr + "hUrms, ";
		SqlParam = SqlParam + GetString(vDev->Get_hUrms(i)) + " , ";

		SqlStr = SqlStr + "hAngle ";
		SqlParam = SqlParam + GetString(vDev->Get_hAngle(i));

		//
		SqlStr = SqlStr + " ) ";
		SqlParam = SqlParam + " ) ";
		//
		SqlStr = SqlStr + SqlParam;

		//
		RwAdo->ExecSQL(SqlStr);

		cout << "   --" << vDev->ShowName() << endl;

	}//if

	RwAdo->CloseTBL();

	//
}