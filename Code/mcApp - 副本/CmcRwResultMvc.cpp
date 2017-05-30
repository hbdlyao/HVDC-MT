///////////////////////////////////////////////////////////
//  CmcRwResultMvc.cpp
//  Implementation of the Class CmcRwResultMvc
//  Created on:      18-4月-2017 22:36:28
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwResultMvc.h"
#include <iostream>
#include "comutil.h"


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


	cout << "Load---" + tblName + "---" << endl;

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
			doLoad(pResult->pmcResultData+vh);
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
	cout << endl;
}

void CmcRwResultMvc::doLoad(struct_mcResultData *vResult)
{
	string  vStr;
	_variant_t vValue;

	RwAdo->GetFieldValue("ResultName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue; //字符型
		vResult->CalName = vStr;
	};

	RwAdo->GetFieldValue("CaseID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue; //字符型
		vResult->CaseID = vStr;
	};

	RwAdo->GetFieldValue("StationName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue; //字符型
		vResult->StationName = vStr;
	};

	RwAdo->GetFieldValue("PdPer", vValue);
	if (vValue.vt != VT_NULL)
	{
		vResult->PdPer = vValue.dblVal;  //双精度
	};

	RwAdo->GetFieldValue("Data", vValue);
	if (vValue.vt != VT_NULL)
	{
		int vDoubleLen = sizeof(double);
		int vIntLen = sizeof(int);
		BYTE* pData;
		SafeArrayAccessData(vValue.parray, (void **)&pData);

		int i = 0;
		memcpy(&vResult->Uac, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Uv, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Udio, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Ud, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->UdL, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Id, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Pd, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Pconv, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Qconv, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->alphaOrgamma, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->miu, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Qf_max, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Qf_min, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Udio_N, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Uv_N, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Tk_N, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Tk, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Ud6Valve, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Pd6Valve, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Pac6Valve, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->Qac6Valve, pData + vDoubleLen*i++, vDoubleLen);
		memcpy(&vResult->TC, pData + vDoubleLen*i++, vIntLen);

		SafeArrayUnaccessData(vValue.parray);
	};
}



void CmcRwResultMvc::doSave1()
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

	}//for

	cout << endl;

	RwAdo->CloseTBL();

}

void CmcRwResultMvc::doSave1(struct_mcResultData vResult)
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
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	cout << "主回路:";
	cout << vResult.CaseID;
	cout << "%";
	cout.width(3);
	cout << vResult.PdPer;

	cout << "======";
	cout.width(6);
	cout << vN++;
}


//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doSave
// 改动者:    崔康生[第二波]
// 改动类型:  重写两个函数
// 改动内容:  1.原有的两个doSave暂时更名为doSave1，新的doSave采用二进制Blob形式存储
// 改动时间:  2017/05/27
//************************************
void CmcRwResultMvc::doSave()
{
	int vN;
	string vSQL;
	bool vOk;

	vSQL = "delete * from mcResult ";
	vSQL = vSQL + " where ResultName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + pResult->GetResultName();
	vSQL = vSQL + "' ";
	RwAdo->ExecSQL(vSQL);

	cout << "Save---" << tblName << "---" << endl;
	vN = pResult->DataDim();

	vSQL = "select * from mcResult ";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
		for (int i = 0; i < vN; i++)
		{
			RwAdo->Record_AddNew();
			doSave(pResult->pmcResultData[i]);
			RwAdo->Record_Update();
		}

	RwAdo->CloseTBL();

	cout << endl;
}

void CmcRwResultMvc::doSave(struct_mcResultData vResult)
{
	_variant_t vValue;

	vValue = _variant_t(vResult.CalName.c_str()); //
	RwAdo->SetFieldValue("ResultName", vValue); //

	vValue = _variant_t(vResult.CaseID.c_str()); //
	RwAdo->SetFieldValue("CaseID", vValue); //

	vValue = _variant_t(vResult.StationName.c_str()); //
	RwAdo->SetFieldValue("StationName", vValue); //

	vValue = _variant_t(vResult.PdPer); //
	RwAdo->SetFieldValue("PdPer", vValue); //

	//Data
	int vLen = sizeof(double) * 21 + sizeof(int);
	int vDoubleLen = sizeof(double);
	int vIntLen = sizeof(int);
	BYTE* pData = new BYTE[vLen];

	int i = 0;
	memcpy(pData + vDoubleLen*i++, &vResult.Uac, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Uv, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Udio, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Ud, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.UdL, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Id, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Pd, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Pconv, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Qconv, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.alphaOrgamma, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.miu, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Qf_max, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Qf_min, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Udio_N, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Uv_N, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Tk_N, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Tk, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Ud6Valve, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Pd6Valve, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Pac6Valve, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.Qac6Valve, vDoubleLen);
	memcpy(pData + vDoubleLen*i++, &vResult.TC, vIntLen);

	SAFEARRAY   *psa;
	SAFEARRAYBOUND rgsabound[1];
	rgsabound[0].lLbound = 0;
	rgsabound[0].cElements = vLen;
	psa = SafeArrayCreate(VT_UI1, 1, rgsabound);
	for (long i = 0; i < (long)vLen; i++)
		SafeArrayPutElement(psa, &i, &pData[i]);
	vValue.vt = VT_ARRAY | VT_UI1;
	vValue.parray = psa;

	RwAdo->SetFieldValue("Data", vValue); //

	delete[] pData;
	//测试用
	static int vN = 1;
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	cout << "主回路:";
	cout << vResult.CaseID;
	cout << "%";
	cout.width(3);
	cout << vResult.PdPer;

	cout << "======";
	cout.width(6);
	cout << vN++;
}