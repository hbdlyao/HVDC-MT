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

	while (!RwAdo->IsEOF())
	{
		try
		{
			RwAdo->GetFieldValue("Data", vValue);
			if (vValue.vt != VT_NULL)
			{
				Byte *vDataPacket;				

				SafeArrayAccessData(vValue.parray, (void **)&vDataPacket);

				pResult->Clear();
				pResult->UnSerialize(vDataPacket);
				pResult->NewCase();

				SafeArrayUnaccessData(vValue.parray);

				/*
				test

				Byte * vPack;
				vPack = pResult->Serialize();
				
				*/

				RwAdo->Record_MoveNext();

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
	long vPacketBytes;
	vPacketBytes = pResult->PacketBytes();

	Byte * vDataPacket; 
	vDataPacket = new Byte[vPacketBytes];


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
		SAFEARRAY   * psa;
		SAFEARRAYBOUND rgsabound[1];

		rgsabound[0].lLbound = 0;
		rgsabound[0].cElements = vPacketBytes;
		psa = SafeArrayCreate(VT_UI1, 1, rgsabound);

		for (long i = 0; i < vPacketBytes; i++)
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
