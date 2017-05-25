///////////////////////////////////////////////////////////
//  CmcRwResultMvc.cpp
//  Implementation of the Class CmcRwResultMvc
//  Created on:      18-4月-2017 22:36:28
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwResultMvc.h"
#include <iostream>

void CmcRwResultMvc::Init(CmcResult * vRes)
{
	pResult = vRes;
}

void CmcRwResultMvc::doLoad()
{
	string  vSQL;

	tblName = "mcResult";
	//
	vSQL = "select CaseID  from " + tblName;
	vSQL = vSQL + " where ResultName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + pResult->GetResultName();
	vSQL = vSQL + "' ";
	vSQL = vSQL + " group by CaseID ";

	RwAdo->OpenSQL(vSQL);

	int vN = RwAdo->Record_RowCount();
	pResult->NewData1(vN);

	
	cout << "Load---" + tblName +"---" << endl;

	vSQL = "select *  from " + tblName;
	vSQL = vSQL + " where ResultName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + pResult->GetResultName();
	vSQL = vSQL + "' ";
	vSQL = vSQL + " order by ResultName,CaseID,StationName,PdPer ";

	RwAdo->OpenSQL(vSQL);
	//
	int vh = 0;
	while (!RwAdo->IsEOF())
	{
		try
		{
			doLoad(pResult->pmcResultData[vh]);
		}
		catch (const std::exception&)
		{
			cout << "Err:" + vh;
		}

		vh = vh + 1;
		//
		RwAdo->Record_MoveNext();

		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		cout << pResult->GetResultName();
		cout << "  ---";
		cout << "%";
		cout.width(3);
		cout << vh;

	}//while

	//
	RwAdo->CloseTBL();

	//
	cout <<  endl;
}

void CmcRwResultMvc::doLoad(struct_mcResultData vResult)
{
	string  vStr;
	_variant_t vValue;

	RwAdo->GetFieldValue("ResultName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue; //字符型
		vResult.CalName = vStr;
	};

	RwAdo->GetFieldValue("CaseID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue; //字符型
		vResult.CaseID = vStr;
	};

	RwAdo->GetFieldValue("StationName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue; //字符型
		vResult.StationName = vStr;
	};

	RwAdo->GetFieldValue("PdPer", vValue);
	if (vValue.vt != VT_NULL)
	{
		vResult.PdPer = vValue.dblVal;  //双精度
	};


	/*
	RwAdo->GetFieldValue("PdPer", vValue);
	if (vValue.vt != VT_NULL)
	{
		vResult.PdPer = vValue.iVal;  //整型
	};
	*/

}



void CmcRwResultMvc::doSave()
{
	int vN;

	string vSQL, vStr;
	_variant_t vValue;

	vSQL = "delete * from mcResult ";
	vSQL = vSQL + " where ResultName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + pResult->GetResultName();
	vSQL = vSQL + "' ";

	RwAdo->ExecSQL(vSQL);


	tblName = "mcResult";

	cout << "Save---" << tblName << "---" << endl;

	vN = pResult->DataDim();

	for (int i = 0; i < vN; i++)
	{
		//
		SqlStr = "Insert into " + tblName;
		SqlParam = "";
		//
		SqlStr = SqlStr + " (";
		SqlParam = SqlParam + " Values ( ";

		//
		doSave(pResult->pmcResultData[i]);

		//
		SqlStr = SqlStr + " ) ";
		SqlParam = SqlParam + " ) ";
		//
		SqlStr = SqlStr + SqlParam;

		//
		RwAdo->ExecSQL(SqlStr);

		//cout << "   --" << vDev->ShowName() << endl;
		cout << endl;

	}//for


	RwAdo->CloseTBL();

}

void CmcRwResultMvc::doSave(struct_mcResultData vResult)
{
	SqlStr = SqlStr + "ResultName, ";
	SqlParam = SqlParam + GetString(vResult.CalName) + ",";

	SqlStr = SqlStr + "CaseID, ";
	SqlParam = SqlParam + GetString(vResult.CaseID) + ",";

	SqlStr = SqlStr + "StationName, ";
	SqlParam = SqlParam + GetString(vResult.StationName) + ",";

	SqlStr = SqlStr + "PdPer, ";
	SqlParam = SqlParam + GetString(vResult.PdPer) + ",";

	SqlStr = SqlStr + "Uac, ";
	SqlParam = SqlParam + GetString(vResult.Uac) + ",";
	SqlStr = SqlStr + "Uv, ";
	SqlParam = SqlParam + GetString(vResult.Uv) + ",";
	SqlStr = SqlStr + "Udio, ";
	SqlParam = SqlParam + GetString(vResult.Udio) + ",";
	SqlStr = SqlStr + "Ud, ";
	SqlParam = SqlParam + GetString(vResult.Ud) + ",";
	SqlStr = SqlStr + "UdL, ";
	SqlParam = SqlParam + GetString(vResult.UdL) + ",";
	SqlStr = SqlStr + "DcId, ";
	SqlParam = SqlParam + GetString(vResult.Id) + ",";
	SqlStr = SqlStr + "Pd, ";
	SqlParam = SqlParam + GetString(vResult.Pd) + ",";
	SqlStr = SqlStr + "Pconv, ";
	SqlParam = SqlParam + GetString(vResult.Pconv) + ",";
	SqlStr = SqlStr + "Qconv, ";
	SqlParam = SqlParam + GetString(vResult.Qconv) + ",";

	SqlStr = SqlStr + "TC, ";
	SqlParam = SqlParam + GetString(vResult.TC) + ",";
	SqlStr = SqlStr + "alphaOrgamma, ";
	SqlParam = SqlParam + GetString(vResult.alphaOrgamma) + ",";
	SqlStr = SqlStr + "miu, ";
	SqlParam = SqlParam + GetString(vResult.miu) + ",";
	SqlStr = SqlStr + "Qf_max, ";
	SqlParam = SqlParam + GetString(vResult.Qf_max) + ",";
	SqlStr = SqlStr + "Qf_min, ";
	SqlParam = SqlParam + GetString(vResult.Qf_min) + ",";

	SqlStr = SqlStr + "Udio_N, ";
	SqlParam = SqlParam + GetString(vResult.Udio_N) + ",";
	SqlStr = SqlStr + "Uv_N, ";
	SqlParam = SqlParam + GetString(vResult.Uv_N) + ",";

	SqlStr = SqlStr + "Tk_N, ";
	SqlParam = SqlParam + GetString(vResult.Tk_N) + ",";

	SqlStr = SqlStr + "Tk, ";
	SqlParam = SqlParam + GetString(vResult.Tk) + ",";

	SqlStr = SqlStr + "Ud6Valve, ";
	SqlParam = SqlParam + GetString(vResult.Ud6Valve) + ",";
	SqlStr = SqlStr + "Pd6Valve, ";
	SqlParam = SqlParam + GetString(vResult.Pd6Valve) + ",";
	SqlStr = SqlStr + "Pac6Valve, ";
	SqlParam = SqlParam + GetString(vResult.Pac6Valve) + ",";
	SqlStr = SqlStr + "Qac6Valve";
	SqlParam = SqlParam + GetString(vResult.Qac6Valve);

	//测试用
	static int vN = 1;
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	cout << "主回路:";
	cout << vResult.CaseID;
	cout << "%";
	cout.width(3);
	cout << vResult.PdPer;

	cout << "======";
	cout.width(6);
	cout << vN++;
}