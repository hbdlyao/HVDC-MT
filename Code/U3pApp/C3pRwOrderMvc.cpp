///////////////////////////////////////////////////////////
//  C3pRwOrderMvc.cpp
//  Implementation of the Class C3pRwOrderMvc
//  Created on:      18-5ÔÂ-2017 12:55:59
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CHvdcDefs.h"
#include "C3pRwOrderMvc.h"

#include <iostream>


void C3pRwOrderMvc::Init(C3pOrder * vOrder)
{
	pOrder = vOrder;
}


void C3pRwOrderMvc::OnLoad(string vdbf)
{
	InitAdo(vdbf);

	OnLoad();
}

void C3pRwOrderMvc::OnLoad()
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

void C3pRwOrderMvc::doLoad()
{
	string vSQL, vStr;
	_variant_t vValue;
	bool vOk;


	//
	vSQL = "select * from U3pOrder ";
	vOk = RwAdo->OpenSQL(vSQL);

	cout << "Load---U3pOrder---" << endl;

	if (vOk)
		while (!RwAdo->IsEOF())
		{

			RwAdo->GetFieldValue("Flag_Ground", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (_bstr_t)vValue; //×Ö·ûÐÍ
				pOrder->Flag_Ground = vStr;
			};

			RwAdo->GetFieldValue("Flag_Ud", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (_bstr_t)vValue; //×Ö·ûÐÍ
				pOrder->Flag_Ud = vStr;
			};

			RwAdo->GetFieldValue("Flag_Rd", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (_bstr_t)vValue; //×Ö·ûÐÍ
				pOrder->Flag_Rd = vStr;
			};

			RwAdo->GetFieldValue("Flag_Uac", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (_bstr_t)vValue; //×Ö·ûÐÍ
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

void C3pRwOrderMvc::doSave()
{

}

