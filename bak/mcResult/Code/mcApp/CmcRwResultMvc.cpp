///////////////////////////////////////////////////////////
//  CmcRwResultMvc.cpp
//  Implementation of the Class CmcRwResultMvc
//  Created on:      18-4ÔÂ-2017 22:36:28
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwResultMvc.h"
#include <iostream>
#include "comutil.h"
#include <direct.h>


void CmcRwResultMvc::Init(CmcResult * vRes)
{
	pResult = vRes;
}

void CmcRwResultMvc::doLoad()
{
	string  vSQL;
	_variant_t vValue;

	tblName = "mcResult";

	cout << "Load---" + tblName + "---" << endl;

	vSQL = "select *  from " + tblName;
	vSQL = vSQL + " where CalName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + pResult->GetResultName();
	vSQL = vSQL + "' ";
	vSQL = vSQL + " order by CalName ";

	RwAdo->OpenSQL(vSQL);
	//
	if (!RwAdo->IsEOF())
	{
		try
		{
			RwAdo->GetFieldValue("Data", vValue);
			if (vValue.vt != VT_NULL)
			{
				Byte *vDataPacket;
				long vPacketOffset = 0;

				SafeArrayAccessData(vValue.parray, (void **)&vDataPacket);

				pResult->Clear();
				pResult->UnSerialize(vDataPacket);

				SafeArrayUnaccessData(vValue.parray);
			}
		}
		catch (const std::exception&)
		{
			cout << "Err:";
		}

	}//while

	 //
	RwAdo->CloseTBL();

	//
	cout << "Finished" << endl;
}


void CmcRwResultMvc::doSave()
{

	Byte * vDataPacket;
	long vHead, vPacketLeng;

	vHead = sizeof(long);
	vPacketLeng = 2 * vHead + pResult->PackedLeng();

	vDataPacket = new Byte[vPacketLeng];
	pResult->Serialize(vDataPacket);

	//

	string vSQL;
	bool vOk;

	vSQL = "delete * from mcResult ";
	vSQL = vSQL + " where CalName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + pResult->GetResultName();
	vSQL = vSQL + "' ";
	RwAdo->ExecSQL(vSQL);

	cout << "Save---" << tblName << "---" << endl;

	vSQL = "select * from mcResult ";
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		RwAdo->Record_AddNew();

		_variant_t vValue;

		vValue = _variant_t(pResult->GetResultName().c_str()); //
		RwAdo->SetFieldValue("CalName", vValue); //

		////////////////////////////////////////////
		SAFEARRAY   *psa;
		SAFEARRAYBOUND rgsabound[1];

		rgsabound[0].lLbound = 0;
		rgsabound[0].cElements = vPacketLeng;
		psa = SafeArrayCreate(VT_UI1, 1, rgsabound);

		for (long i = 0; i < vPacketLeng; i++)
			SafeArrayPutElement(psa, &i, &vDataPacket[i]);

		vValue.vt = VT_ARRAY | VT_UI1;
		vValue.parray = psa;
		///////////////////////////////////////////////

		RwAdo->SetFieldValue("Data", vValue); //

		RwAdo->Record_Update();
	}

	RwAdo->CloseTBL();

	cout << "Finished" << endl;

	delete[] vDataPacket;
}
