///////////////////////////////////////////////////////////
//  CProjectRwMDB.cpp
//  Implementation of the Class CHvdcPRJ_RwMvc
//  Created on:      18-4ÔÂ-2017 22:23:47
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CHvdcPRJ_RwMvc.h"
#include "CmcParams.h"
#include "CxbParams.h"

#include "CHvdcParams.h"

#include <iostream>


void CHvdcPRJ_RwMvc::InitAdo(string vDbf)
{
	dbfName = vDbf;

	//RwAdo = new CRwAdo_MDB();

	RwAdo = new CRwAdo_Access();
	RwAdo->InitDbf(dbfName, "", "", "false");
}

void CHvdcPRJ_RwMvc::doLoad()
{

	string vSQL, vStr;
	_variant_t vValue;
	bool vOk;
	
	//
	vSQL = "select * from Hvdc_Project";
	vOk = RwAdo->OpenSQL(vSQL);
	
	if (vOk)
		while (!RwAdo->IsEOF())
		{
			cout << "Load---Hvdc_Project---" << endl;

			RwAdo->GetFieldValue("ProjectName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (_bstr_t)vValue; //×Ö·ûÐÍ
				CHvdcParams::ProjectName = vStr;
			};

			RwAdo->GetFieldValue("ID", vValue);
			if (vValue.vt != VT_NULL)
			{
				CHvdcParams::ProjectID = vValue.iVal;
			};

			RwAdo->GetFieldValue("mcStationCount", vValue);
			if (vValue.vt != VT_NULL)
			{
				CmcParams::mcStationCount = vValue.iVal;
			};

			RwAdo->GetFieldValue("xbStationCount", vValue);
			if (vValue.vt != VT_NULL)
			{
				CxbParams::xbStationCount = vValue.iVal;
			};
			cout << "   Finished " << endl;

			RwAdo->Record_MoveNext();

		}//while
		
	RwAdo->CloseTBL();
}


void CHvdcPRJ_RwMvc::doSave()
{
	
	string vSQL;

	tblName = "Hvdc_Project";
	//
	vSQL = "delete * from  " + tblName;
	RwAdo->ExecSQL(vSQL);

	//
	cout << "Save---" << tblName << "---" << endl;

	//
	SqlStr = "Insert into " + tblName;
	SqlParam = "Values ";
	//
	SqlStr = SqlStr		+ " ( ";
	SqlParam = SqlParam + " ( ";

	//
	SqlStr = SqlStr + "ID, ";
	SqlParam = SqlParam + GetString(CHvdcParams::ProjectID) + ",";

	SqlStr = SqlStr + "ProjectName, ";
	SqlParam = SqlParam + GetString(CHvdcParams::ProjectName) + ",";

	SqlStr = SqlStr + "mcStationCount, ";
	SqlParam = SqlParam + GetString(CmcParams::mcStationCount) + ",";

	SqlStr = SqlStr + "xbStationCount ";
	SqlParam = SqlParam + GetString(CxbParams::xbStationCount);

	//
	SqlStr = SqlStr		+ " ) ";
	SqlParam = SqlParam + " ) ";
	//
	SqlStr = SqlStr + SqlParam;

	//
	RwAdo->ExecSQL(SqlStr);

	RwAdo->CloseTBL();

	//
	cout << " Finished Hvdc_Project " << endl;
	
}
