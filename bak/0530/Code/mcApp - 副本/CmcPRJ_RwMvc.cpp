///////////////////////////////////////////////////////////
//  CProjectRwMDB.cpp
//  Implementation of the Class CHvdcPRJ_RwMvc
//  Created on:      18-4ÔÂ-2017 22:23:47
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcPRJ_RwMvc.h"
#include "CmcParams.h"

#include <iostream>


void CmcPRJ_RwMvc::InitAdo(string vDbf)
{
	dbfName = vDbf;

	//RwAdo = new CMyRwAdo_MDB();

	RwAdo = new CMyRwAdo_Access();
	RwAdo->InitDbf(dbfName, "", "", "false");
}

void CmcPRJ_RwMvc::doLoad()
{

	string vSQL, vStr;
	_variant_t vValue;
	bool vOk;

	//
	vSQL = "select * from mc_Project";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
		while (!RwAdo->IsEOF())
		{
			cout << "Load---mc_Project---" << endl;

			RwAdo->GetFieldValue("ProjectName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (_bstr_t)vValue; //×Ö·ûÐÍ
				CmcParams::ProjectName = vStr;
			};

			RwAdo->GetFieldValue("mcStationCount", vValue);
			if (vValue.vt != VT_NULL)
			{
				CmcParams::mcStationCount = vValue.iVal;
			};

			cout << "   Finished " << endl;

			RwAdo->Record_MoveNext();

		}//while

	RwAdo->CloseTBL();
}


void CmcPRJ_RwMvc::doSave()
{

	string vSQL;

	tblName = "mc_Project";
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
	
	SqlStr = SqlStr + "ProjectName, ";
	SqlParam = SqlParam + GetString(CmcParams::ProjectName) + ",";

	SqlStr = SqlStr + "mcStationCount ";
	SqlParam = SqlParam + GetString(CmcParams::mcStationCount) + "";

	//
	SqlStr = SqlStr + " ) ";
	SqlParam = SqlParam + " ) ";
	//
	SqlStr = SqlStr + SqlParam;

	//
	RwAdo->ExecSQL(SqlStr);

	RwAdo->CloseTBL();

	//
	cout << " Finished mc_Project " << endl;

}
