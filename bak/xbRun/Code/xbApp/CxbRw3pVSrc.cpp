///////////////////////////////////////////////////////////
//  CxbRw3pVSrc.cpp
//  Implementation of the Class CxbRw3pVSrc
//  Created on:      18-4ÔÂ-2017 17:17:11
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRw3pVSrc.h"

#include <iostream>
//

void CxbRw3pVSrc::OnLoad()
{
	CxbRwTwo::OnLoad();

	doLoad_hData();
}

void CxbRw3pVSrc::OnSave()
{
	CxbRwTwo::OnSave();

	doSave_hData();
}

void CxbRw3pVSrc::doLoad(CDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDev3pVSrc * vDev;

	vDev = dynamic_cast<CxbDev3pVSrc *>(vDevice);

	CxbRwTwo::doLoad(vDev);
	//

}


void CxbRw3pVSrc::doLoad_hData()
{
	///////////////////////////////////////////
	CDevTBL * vTBL;

	vTBL = pGrid->DeviceTBL(tblType);
	for each (CxbDev3pVSrc * vDev in  vTBL->Children())
	{
		//
		doLoad_hData(vDev);


	}//for each

}


void CxbRw3pVSrc::doLoad_hData(CxbDev3pVSrc * vDev)
{
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

		cout << "   --" << vDev->ShowName() << endl;

	}//if

	RwAdo->CloseTBL();

	//
}


void CxbRw3pVSrc::doSave(CDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDev3pVSrc * vDev;

	vDev = dynamic_cast<CxbDev3pVSrc *>(vDevice);

	CxbRwTwo::doSave(vDev);


}

void CxbRw3pVSrc::doSave_hData()
{
	///////////////////////////////////////////
	CDevTBL * vTBL;

	vTBL = pGrid->DeviceTBL(tblType);
	for each (CxbDev3pVSrc * vDev in  vTBL->Children())
	{
		//
		//doSave_hData(vDev);

	}//for each

}


void CxbRw3pVSrc::doSave_hData(CxbDev3pVSrc * vDev)
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