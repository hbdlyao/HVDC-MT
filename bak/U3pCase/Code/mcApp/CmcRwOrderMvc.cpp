///////////////////////////////////////////////////////////
//  CmcRwOrderMvc.cpp
//  Implementation of the Class CmcRwOrderMvc
//  Created on:      18-4��-2017 22:36:22
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

			//doLoad_CaseID();

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
				vStr = (_bstr_t)vValue; //�ַ���
				pOrder->Flag_Ground = vStr;
			};
	
			RwAdo->GetFieldValue("Flag_Ud", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (_bstr_t)vValue; //�ַ���
				pOrder->Flag_Ud = vStr;
			};
	
			RwAdo->GetFieldValue("Flag_Rd", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (_bstr_t)vValue; //�ַ���
				pOrder->Flag_Rd = vStr;
			};
	
			RwAdo->GetFieldValue("Flag_Uac", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (_bstr_t)vValue; //�ַ���
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
	
			/*
			RwAdo->GetFieldValue("Is6p", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->Is6p = (vValue.iVal == 1);
			};
	
			RwAdo->GetFieldValue("Is12pDouble", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->Is12pDouble = (vValue.iVal == 1);
			};
			*/
	
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
	
			RwAdo->Record_MoveNext();
	
			cout << "   Finished " << endl;
	
		}//while
	
	RwAdo->CloseTBL();
}


void CmcRwOrderMvc::doLoad_CaseID()
{
	string  vSQL;
	string  vStr;
	_variant_t vValue;

	tblName = "mcResult";
	//
	vSQL = "select CalName,CaseID,PdPercent from " + tblName;
	vSQL = vSQL + " where ResultName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + pOrder->CalName;
	vSQL = vSQL + "' ";
	vSQL = vSQL + " group by CalName,CaseID,PdPercent ";

	RwAdo->OpenSQL(vSQL);

	//int vN = RwAdo->Record_RowCount();

	int vh = 0;
	while (!RwAdo->IsEOF())
	{
		struct_Case vCase;

		RwAdo->GetFieldValue("CalName", vValue);
		if (vValue.vt != VT_NULL)
		{
			vCase.CalName = (_bstr_t)vValue; //�ַ���
		};

		RwAdo->GetFieldValue("CaseID", vValue);
		if (vValue.vt != VT_NULL)
		{
			vCase.CaseID = (_bstr_t)vValue; //�ַ���
		};

		RwAdo->GetFieldValue("PdPercent", vValue);
		if (vValue.vt != VT_NULL)
		{
			vCase.PdPercent = vValue.dblVal; //�ַ���
		};

		pOrder->AddCase(vCase);

		vh = vh + 1;
		RwAdo->Record_MoveNext();

		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		cout << pOrder->CalName;
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


void CmcRwOrderMvc::doSave()
{

}