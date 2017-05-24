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

void CmcRwOrderMvc::doLoad()
{
	string vSQL, vStr;
	_variant_t vValue;
	bool vOk;
	
	//
	vSQL = "select * from mcOrder_yao ";
	vOk = RwAdo->OpenSQL(vSQL);
	
	if (vOk)
		while (!RwAdo->IsEOF())
		{
			cout << "Load---mcOrder_yao---" << endl;
	
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
	
			RwAdo->GetFieldValue("PdPercent", vValue);
			if (vValue.vt != VT_NULL)
			{
				pOrder->PdPer = vValue.dblVal;
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


void CmcRwOrderMvc::doSave()
{

}