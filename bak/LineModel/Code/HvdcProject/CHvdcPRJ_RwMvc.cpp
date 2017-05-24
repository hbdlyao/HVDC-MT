///////////////////////////////////////////////////////////
//  CProjectRwMDB.cpp
//  Implementation of the Class CHvdcPRJ_RwMvc
//  Created on:      18-4月-2017 22:23:47
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
				vStr = (_bstr_t)vValue; //字符型
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


void CHvdcPRJ_RwMvc::doSave(){

	string vSQL, vStr;
	_variant_t vValue;
	
	bool vOk = S_FALSE;
	
	vSQL = "delete * from Hvdc_Project";
	vOk = RwAdo->ExecSQL(vSQL);
	
	
	vSQL = "select * from Hvdc_Project";
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));
	
	if (vOk)
	{
		cout << "Save---Hvdc_Project---" << endl;
	
			RwAdo->Record_AddNew();
		
			vValue = _variant_t(CHvdcParams::ProjectID); //整型
			RwAdo->SetFieldValue("ID", vValue);
	
			vValue = _variant_t(CHvdcParams::ProjectName.c_str());//文本型
			RwAdo->SetFieldValue("ProjectName", vValue);
	
			vValue = _variant_t(CmcParams::mcStationCount);
			RwAdo->SetFieldValue("mcStationCount", vValue);

			vValue = _variant_t(CxbParams::xbStationCount);
			RwAdo->SetFieldValue("xbStationCount", vValue);


	
			RwAdo->Record_Update();
	
			cout << " Finished Hvdc_Project " << endl;
	
	
	}//if
	
	RwAdo->CloseTBL();
}

