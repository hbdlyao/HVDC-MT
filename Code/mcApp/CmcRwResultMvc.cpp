///////////////////////////////////////////////////////////
//  CmcRwResultMvc.cpp
//  Implementation of the Class CmcRwResultMvc
//  Created on:      18-4月-2017 22:36:28
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
	string  vSQL, vStr;
	_variant_t vValue;

	tblName = "mcResult";

	cout << "Load---" + tblName + "---" << endl;

	vSQL = "select *  from " + tblName;
	vSQL = vSQL + " where CalName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + pResult->GetResultName();
	vSQL = vSQL + "' ";
	vSQL = vSQL + " order by CalName,CaseID ,StationName ";

	RwAdo->OpenSQL(vSQL);
	//
	pResult->Clear();
	while (!RwAdo->IsEOF())
	{
		RwAdo->GetFieldValue("CalName", vValue);
		if (vValue.vt != VT_NULL)
		{
			vStr = (_bstr_t)vValue; //字符型
			//pOrder->Flag_Ground = vStr;
		};

		RwAdo->GetFieldValue("CaseID", vValue);
		if (vValue.vt != VT_NULL)
		{
			vStr = (_bstr_t)vValue; //字符型
									//pOrder->Flag_Ground = vStr;
		};

		RwAdo->GetFieldValue("StationName", vValue);
		if (vValue.vt != VT_NULL)
		{
			vStr = (_bstr_t)vValue; //字符型
									//pOrder->Flag_Ground = vStr;
		};


		RwAdo->GetFieldValue("Data", vValue);
		if (vValue.vt != VT_NULL)
		{
			Byte *vDataPacket;

			SafeArrayAccessData(vValue.parray, (void **)&vDataPacket);

			pResult->UnSerialize(vDataPacket);

			SafeArrayUnaccessData(vValue.parray);

			RwAdo->Record_MoveNext();

		}
	}//while

	 //pResult->NewCase();

	//
	RwAdo->CloseTBL();

	//
	cout << "Finished" << endl;

}


void CmcRwResultMvc::doSave()
{
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


	for each (pair<string,CmcCase *> vPair in pResult->pCasePack.Children())
	{
		CmcCasePack * vCalPack = dynamic_cast<CmcCasePack *>(vPair.second);

		for each (pair<string, CmcCase *> vPair in vCalPack->Children())
		{
			CmcCasePack * vCasePack = dynamic_cast<CmcCasePack *>(vPair.second);

			for each (pair<string, CmcCase *> vPair in vCasePack->Children())
			{
				RwAdo->Record_AddNew();

				doSave(vPair.second->pDataVect);

				RwAdo->Record_Update();
			}
		}
	}

	RwAdo->CloseTBL();

	cout << "Finished" << endl;


}

void CmcRwResultMvc::doSave(vector<struct_mcResultData*> & vDataVect)
{
	if (vDataVect.size() <= 0)
		return;

	//
	_variant_t vValue;

	vValue = _variant_t(vDataVect[0]->CalName);
	RwAdo->SetFieldValue("CalName", vValue); //

	vValue = _variant_t(vDataVect[0]->CaseID);
	RwAdo->SetFieldValue("CaseID", vValue); //

	vValue = _variant_t(vDataVect[0]->StationName);
	RwAdo->SetFieldValue("StationName", vValue); //


	////////////////////////////////////////////
	SAFEARRAY   * psa;
	SAFEARRAYBOUND rgsabound[1];

	long vBytes = pResult->PacketBytes(vDataVect);
	Byte * vPacket = pResult->Serialize(vDataVect);

	rgsabound[0].lLbound = 0;
	rgsabound[0].cElements = vBytes;
	psa = SafeArrayCreate(VT_UI1, 1, rgsabound);

	for (long i = 0; i < vBytes; i++)
		SafeArrayPutElement(psa, &i, &vPacket[i]);

	vValue.vt = VT_ARRAY | VT_UI1;
	vValue.parray = psa;
	///////////////////////////////////////////////

	RwAdo->SetFieldValue("Data", vValue); //

	//
	delete[] vPacket;

}
