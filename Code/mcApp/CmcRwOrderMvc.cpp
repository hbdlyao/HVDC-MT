///////////////////////////////////////////////////////////
//  CmcRwOrderMvc.cpp
//  Implementation of the Class CmcRwOrderMvc
//  Created on:      18-4月-2017 22:36:22
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwOrderMvc.h"
#include "CmcDefs.h"

#include <iostream>


void CmcRwOrderMvc::Init(CmcOrder * vOrder)
{
	pOrder = vOrder;
}


void CmcRwOrderMvc::OnLoad(string vdbf)
{
	InitAdo(vdbf);

	OnLoad();
}

void CmcRwOrderMvc::OnLoad()
{
	try
	{
		if (doOpenDBF())
		{
			doLoad();
			doLoad_UdCustom();

			//
			doCloseDBF();

		}//if 
	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}
}

void CmcRwOrderMvc::OnSave()
{
	try
	{
		if (doOpenDBF())
		{
			doSave();
			doSave_UdCustom();

			//
			doCloseDBF();

		}//if 
	}
	catch (_com_error & vErr)
	{
		cout << vErr.Description() << endl;
	}
}

void CmcRwOrderMvc::doLoad()
{
	string vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	//
	vSQL = "select * from mcOrder ";
	vSQL = vSQL + " where CalName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + pOrder->CalName;
	vSQL = vSQL + "' ";
	vOk = RwAdo->OpenSQL(vSQL);

	cout << "Load---mcOrder_yao---" << endl;

	if (vOk)
		while (!RwAdo->IsEOF())
		{

			RwAdo->GetFieldValue("Flag_Ground", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (_bstr_t)vValue; //字符型
				pOrder->Flag_Ground = vStr;
			};

			RwAdo->GetFieldValue("Flag_Ud", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (_bstr_t)vValue; //字符型
				pOrder->Flag_Ud = vStr;
			};

			RwAdo->GetFieldValue("Flag_Rd", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (_bstr_t)vValue; //字符型
				pOrder->Flag_Rd = vStr;
			};

			RwAdo->GetFieldValue("Flag_Uac", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (_bstr_t)vValue; //字符型
				pOrder->Flag_Uac = vStr;
			};

			RwAdo->GetFieldValue("IsUdCustom", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->IsUdCustom = (vValue.iVal == 1);
			};

			RwAdo->GetFieldValue("IsUacSwap", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->IsUacSwap = (vValue.iVal == 1);
			};

			RwAdo->GetFieldValue("IsUdToGround", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->IsUdToGround = (vValue.iVal == 1);
			};

			RwAdo->GetFieldValue("nValvor", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->nValNum = vValue.iVal;
			};

			RwAdo->GetFieldValue("PdStartPercent", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->PdStartPer = vValue.dblVal;
			};

			RwAdo->GetFieldValue("PdIncrePer", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->PdIncrePer = vValue.dblVal;
			};

			RwAdo->GetFieldValue("PdSize", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->PdSize = vValue.iVal;
			};

			RwAdo->GetFieldValue("Is6Pulse", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->Is6Pulse = (vValue.iVal == 1);
			};

			//崔康生20170828-单功率水平
			RwAdo->GetFieldValue("IsLoadSingle", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->IsLoadSingle = (vValue.iVal == 1);
			};
			RwAdo->GetFieldValue("UdSingle", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->UdSingle = vValue.dblVal;
			};
			RwAdo->GetFieldValue("PdSingle", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->PdSingle = vValue.dblVal;
			};

			RwAdo->Record_MoveNext();

			cout << "   Finished mc_Order  " << endl;

		}//while

	RwAdo->CloseTBL();
}
void CmcRwOrderMvc::doLoad_UdCustom()
{
	string vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	//
	vSQL = "select * from mcOrder_UdData ";
	vSQL = vSQL + " where CalName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + pOrder->CalName;
	vSQL = vSQL + "' ";
	vOk = RwAdo->OpenSQL(vSQL);

	cout << "Load---mcOrder_UdData---" << endl;

	if (vOk)
		while (!RwAdo->IsEOF())
		{
			RecUdCustom vUdCustom = RecUdCustom();

			RwAdo->GetFieldValue("PdIndex", vValue);
			if (vValue.vt != VT_NULL)
			{
				vUdCustom.PdIndex = vValue.iVal;
			};

			RwAdo->GetFieldValue("Ud_Ground11", vValue);
			if (vValue.vt != VT_NULL)
			{
				vUdCustom.Ud11 = vValue.dblVal;
			};

			RwAdo->GetFieldValue("Ud_Ground12", vValue);
			if (vValue.vt != VT_NULL)
			{
				vUdCustom.Ud12 = vValue.dblVal;
			};

			RwAdo->GetFieldValue("Ud_Ground21", vValue);
			if (vValue.vt != VT_NULL)
			{
				vUdCustom.Ud21 = vValue.dblVal;
			};

			RwAdo->GetFieldValue("Ud_Ground22", vValue);
			if (vValue.vt != VT_NULL)
			{
				vUdCustom.Ud22 = vValue.dblVal;
			};

			pOrder->UdData.push_back(vUdCustom);


			RwAdo->Record_MoveNext();


		}//while

	cout << "   Finished mcOrder_UdData  " << endl;
	RwAdo->CloseTBL();
}

void CmcRwOrderMvc::doSave()
{
	string vSQL;

	tblName = "mcOrder";
	//
	vSQL = "delete * from  " + tblName;
	RwAdo->ExecSQL(vSQL);

	//
	cout << "Save---" << tblName << "---" << endl;

	//
	SqlStr = "Insert into " + tblName;
	SqlParam = "Values ";
	//
	SqlStr = SqlStr + " ( ";
	SqlParam = SqlParam + " ( ";

	SqlStr = SqlStr + "CalName, ";
	SqlParam = SqlParam + GetString(pOrder->CalName) + ",";

	SqlStr = SqlStr + "Flag_Ground, ";
	SqlParam = SqlParam + GetString(pOrder->Flag_Ground) + ",";

	SqlStr = SqlStr + "Flag_Ud, ";
	SqlParam = SqlParam + GetString(pOrder->Flag_Ud) + ",";

	SqlStr = SqlStr + "Flag_Rd, ";
	SqlParam = SqlParam + GetString(pOrder->Flag_Rd) + ",";

	SqlStr = SqlStr + "Flag_Uac, ";
	SqlParam = SqlParam + GetString(pOrder->Flag_Uac) + ",";

	SqlStr = SqlStr + "IsUdCustom, ";
	SqlParam = SqlParam + GetString(pOrder->IsUdCustom) + ",";

	SqlStr = SqlStr + "IsUacSwap, ";
	SqlParam = SqlParam + GetString(pOrder->IsUacSwap) + ",";

	SqlStr = SqlStr + "IsUdToGround, ";
	SqlParam = SqlParam + GetString(pOrder->IsUdToGround) + ",";

	SqlStr = SqlStr + "nValvor, ";
	SqlParam = SqlParam + GetString(pOrder->nValNum) + ",";

	SqlStr = SqlStr + "PdStartPercent, ";
	SqlParam = SqlParam + GetString(pOrder->PdStartPer) + ",";

	SqlStr = SqlStr + "PdIncrePer, ";
	SqlParam = SqlParam + GetString(pOrder->PdIncrePer) + ",";

	SqlStr = SqlStr + "PdSize, ";
	SqlParam = SqlParam + GetString(pOrder->PdSize) + ",";

	//崔康生20170828-单功率水平
	SqlStr = SqlStr + "IsLoadSingle, ";
	SqlParam = SqlParam + GetString(pOrder->IsLoadSingle) + ",";
	SqlStr = SqlStr + "UdSingle, ";
	SqlParam = SqlParam + GetString(pOrder->UdSingle) + ",";
	SqlStr = SqlStr + "PdSingle, ";
	SqlParam = SqlParam + GetString(pOrder->PdSingle) + ",";

	SqlStr = SqlStr + "Is6Pulse ";
	SqlParam = SqlParam + GetString(pOrder->Is6Pulse) + "";

	//
	SqlStr = SqlStr + " ) ";
	SqlParam = SqlParam + " ) ";
	//
	SqlStr = SqlStr + SqlParam;

	//
	RwAdo->ExecSQL(SqlStr);

	RwAdo->CloseTBL();

	//
	cout << " Finished mc_Order " << endl;
}
void CmcRwOrderMvc::doSave_UdCustom()
{
	string vSQL;

	tblName = "mcOrder_UdData";
	//
	vSQL = "delete * from  " + tblName;
	RwAdo->ExecSQL(vSQL);

	//
	cout << "Save---" << tblName << "---" << endl;

	for each(RecUdCustom vUdCustom in pOrder->UdData)
	{
		//
		SqlStr = "Insert into " + tblName;
		SqlParam = "Values ";
		//
		SqlStr = SqlStr + " ( ";
		SqlParam = SqlParam + " ( ";

		SqlStr = SqlStr + "CalName, ";
		SqlParam = SqlParam + GetString(pOrder->CalName) + ",";

		SqlStr = SqlStr + "PdIndex, ";
		SqlParam = SqlParam + GetString(vUdCustom.PdIndex) + ",";

		SqlStr = SqlStr + "Ud_Ground11, ";
		SqlParam = SqlParam + GetString(vUdCustom.Ud11) + ",";

		SqlStr = SqlStr + "Ud_Ground12, ";
		SqlParam = SqlParam + GetString(vUdCustom.Ud12) + ",";

		SqlStr = SqlStr + "Ud_Ground21, ";
		SqlParam = SqlParam + GetString(vUdCustom.Ud21) + ",";

		SqlStr = SqlStr + "Ud_Ground22 ";
		SqlParam = SqlParam + GetString(vUdCustom.Ud22) + "";

		//
		SqlStr = SqlStr + " ) ";
		SqlParam = SqlParam + " ) ";
		//
		SqlStr = SqlStr + SqlParam;

		//
		RwAdo->ExecSQL(SqlStr);
	}

	RwAdo->CloseTBL();

	//
	cout << " Finished mcOrder_UdData " << endl;
}