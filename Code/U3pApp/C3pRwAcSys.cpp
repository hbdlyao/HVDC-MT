///////////////////////////////////////////////////////////
//  C3pRwAcSys.cpp
//  Implementation of the Class C3pRwAcSys
//  Created on:      18-5月-2017 8:07:25
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pRwAcSys.h"
#include "C3pDevAcSys.h"

#include <iostream>

void C3pRwAcSys::OnLoad()
{
	C3pRwOne::OnLoad();

	doLoad_hData();
}


void C3pRwAcSys::OnSave()
{
	C3pRwOne::OnSave();

	doSave_hData();
}


void C3pRwAcSys::doLoad(CDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	C3pDevAcSys * vDev;

	vDev = dynamic_cast<C3pDevAcSys *>(vDevice);

	C3pRwOne::doLoad(vDevice);


	RwAdo->GetFieldValue("Rs", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetRs(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Ls", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetLs(vValue.dblVal); //双精度
	};
}

void C3pRwAcSys::doLoad_hData()
{
	///////////////////////////////////////////
	CDevTBL * vTBL;

	vTBL = pGrid->DeviceTBL(tblType);
	for each (C3pDevAcSys * vDev in  vTBL->Children())
	{
		//
		doLoad_hData(vDev);


	}//for each
}


void C3pRwAcSys::doLoad_hData(C3pDevAcSys* vDev)
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

		vDev->SethCount(RwAdo->Record_RowCount());

		vh = 0;
		while (!RwAdo->IsEOF())
		{
			RwAdo->GetFieldValue("hOrder", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->Set_hIndex(vh, vValue.iVal);
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

			vh = vh + 1;

			//
			RwAdo->Record_MoveNext();


		}//while

		cout << "   --" << vDev->GetDeviceName() << endl;

	}//if

	RwAdo->CloseTBL();


}


void C3pRwAcSys::doSave(CDevBase* vDevice)
{

	string vStr;
	_variant_t vValue;
	C3pDevAcSys * vDev;

	vDev = dynamic_cast<C3pDevAcSys *>(vDevice);

	C3pRwOne::doSave(vDevice);

	SqlStr = SqlStr + ",";
	SqlParam = SqlParam + ",";

	SqlStr = SqlStr + "Ls, ";
	SqlParam = SqlParam + GetString(vDev->GetLs()) + " , ";

	SqlStr = SqlStr + "Rs ";
	SqlParam = SqlParam + GetString(vDev->GetRs());

}


void C3pRwAcSys::doSave_hData()
{
	///////////////////////////////////////////
	CDevTBL * vTBL;

	vTBL = pGrid->DeviceTBL(tblType);
	for each (C3pDevAcSys * vDev in  vTBL->Children())
	{
		doSave_hData(vDev);
	}
}


void C3pRwAcSys::doSave_hData(C3pDevAcSys* vDev)
{
	string vSQL, vStr;
	_variant_t vValue;
	int i;

	vSQL = "delete * from " + tblName + "_hData ";
	vSQL = vSQL + " where DeviceName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vDev->GetDeviceName();
	vSQL = vSQL + "' ";

	RwAdo->ExecSQL(vSQL);

	//
	cout << "Save --- " + tblName + "_hData " << endl;

	for (i = 0; i < vDev->GethCount(); i++)
	{
		//
		SqlStr = "Insert into " + tblName + "_hData ";
		SqlParam = "";
		//
		SqlStr = SqlStr + " (";
		SqlParam = SqlParam + " Values ( ";

		SqlStr = SqlStr + "DeviceName, ";
		SqlParam = SqlParam + GetString(vDev->GetDeviceName()) + " , ";

		SqlStr = SqlStr + "hOrder, ";
		SqlParam = SqlParam + GetString(vDev->Get_hIndex(i)) + " , ";

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

		//
		cout << "  ---" << vDev->ShowName() << endl;

	}//for

	RwAdo->CloseTBL();

}
