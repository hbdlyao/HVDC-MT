///////////////////////////////////////////////////////////
//  CmcRwOrderMvc.cpp
//  Implementation of the Class CmcRwOrderMvc
//  Created on:      18-4月-2017 22:36:22
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwOrderMvc.h"

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
	vSQL = "select * from mcOrder_yao ";
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
				pOrder->Is6Pulse = vValue.iVal;
			};

			RwAdo->Record_MoveNext();

			cout << "   Finished mc_Order  " << endl;

		}//while

	RwAdo->CloseTBL();
}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doSave
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.
// 改动时间:  2017/05/26
//************************************
void CmcRwOrderMvc::doSave()
{
	string vSQL;

	tblName = "mcOrder_yao";
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