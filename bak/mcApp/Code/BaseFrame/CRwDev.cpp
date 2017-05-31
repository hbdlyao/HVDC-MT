///////////////////////////////////////////////////////////
//  CRwDev.cpp
//  Implementation of the Class CRwDev
//  Created on:      15-5月-2017 11:13:44
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CRwDev.h"
#include <iostream>

void CRwDev::InitGrid(CDevGrid * vGrid) 
{
	pGrid = vGrid;
}


string CRwDev::StaField(int vStaCount, int vIndex)
{
	string vStr;
	
	switch (vStaCount)
	{
	    case 1:
	        vStr = "StationName";
	        break;
	
	    default:
	        vStr = "StationName" + to_string(vIndex);
	        break;
	
	}
	
	return vStr;
}


string CRwDev::NodeNameField(int vStaCount, int vIndex)
{

	string vStr;
	
	switch (vStaCount)
	{
	    case 1:
	        vStr = "NodeName";
	        break;
	
	    default:
	        vStr = "NodeName" + to_string(vIndex);
	        break;
	
	}
	
	return vStr;
}


string CRwDev::NodeIDField(int vStaCount, int vIndex)
{

	string vStr;

	switch (vStaCount)
	{
	case 1:
		vStr = "NodeID";
		break;

	default:
		vStr = "NodeID" + to_string(vIndex);
		break;

	}

	return vStr;
}


void CRwDev::OnLoad()
{
	CDevTBL * vTBL;
	CDevBase * vDev;

	string  vSQL, vStr;
	_variant_t vValue;
	bool vOk;

	vSQL = "select * from " + tblName;
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---" << tblName << "---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = pGrid->DeviceTBL(tblType);
			vDev = dynamic_cast<CDevBase *>(vTBL->NewDevice(devType));

			doLoad(vDev);

			vTBL->DeviceAdd(vDev->GetDeviceName(), vDev);

			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->ShowName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();
}


void CRwDev::OnSave()
{
	CDevTBL * vTBL;

	string vSQL, vStr;
	_variant_t vValue;

	vSQL = "delete * from " + tblName;
	RwAdo->ExecSQL(vSQL);


	cout << "Save ---" << tblName << "---" << endl;

	vTBL = pGrid->DeviceTBL(tblType);
	for each(CDevBase * vDev in vTBL->Children())
	{
		//
		SqlStr = "Insert into " + tblName;
		SqlParam = "";
		//
		SqlStr = SqlStr + " (";
		SqlParam = SqlParam + " Values ( ";

		//
		doSave(vDev);

		//
		SqlStr = SqlStr + " ) ";
		SqlParam = SqlParam + " ) ";
		//
		SqlStr = SqlStr + SqlParam;

		//
		RwAdo->ExecSQL(SqlStr);

		//
		//RwAdo->Record_Update();
		//
		cout << "   --" << vDev->ShowName() << endl;

	}//for


	RwAdo->CloseTBL();

}


void CRwDev::doLoad(CDevBase * vDevice)
{
	int i;
	string vFieldName;
	string vStr;
	_variant_t vValue;

	for (i = 1; i <= vDevice->GetStaCount(); i++)
	{
		vFieldName = StaField(vDevice->GetStaCount(), i);

		RwAdo->GetFieldValue(vFieldName, vValue);
		if (vValue.vt != VT_NULL)
		{
			vStr = (_bstr_t)vValue; //字符型
			vDevice->SetStationName(i - 1, vStr);
		};

	}

	for (i = 1; i <= vDevice->GetDotCount(); i++)
	{
		vFieldName = NodeNameField(vDevice->GetDotCount(), i);
		RwAdo->GetFieldValue(vFieldName, vValue);
		if (vValue.vt != VT_NULL)
		{
			vStr = (_bstr_t)vValue; //字符型
			vDevice->SetNodeName(i - 1, vStr);
		};
	}

	//
	RwAdo->GetFieldValue("ID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDevice->SetObjGUID(vValue.iVal);
	};

	RwAdo->GetFieldValue("DeviceID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue; //字符型
		vDevice->SetDeviceID(vStr);
	};

	RwAdo->GetFieldValue("DeviceName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue;
		vDevice->SetDeviceName(vStr);
	};

	RwAdo->GetFieldValue("DeviceType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDevice->SetDeviceType(vValue.iVal);//整型
	};

}


void CRwDev::doSave(CDevBase * vDevice)
{
	int i;
	string vFieldName;

	for (i = 1; i <= vDevice->GetStaCount(); i++)
	{
		vFieldName = StaField(vDevice->GetStaCount(), i);

		SqlStr = SqlStr + vFieldName + ",";
		SqlParam = SqlParam + GetString(vDevice->GetStationName(i - 1)) + ",";
	}

	for (i = 1; i <= vDevice->GetDotCount(); i++)
	{
		vFieldName = NodeNameField(vDevice->GetDotCount(), i);

		SqlStr = SqlStr + vFieldName + ",";
		SqlParam = SqlParam + GetString(vDevice->GetNodeName(i - 1)) + ",";
	}

	for (i = 1; i <= vDevice->GetDotCount(); i++)
	{
		vFieldName = NodeIDField(vDevice->GetDotCount(), i);

		SqlStr = SqlStr + vFieldName + ",";
		SqlParam = SqlParam + GetString(vDevice->GetNodeID(i - 1)) + ",";
	}


	SqlStr = SqlStr + "ID , ";
	SqlParam = SqlParam + GetString(vDevice->GetObjGUID()) + " , ";
	//
	SqlStr = SqlStr + "DeviceID , ";
	SqlParam = SqlParam + GetString(vDevice->GetDeviceID()) + " , ";

	SqlStr = SqlStr + "DeviceName , ";
	SqlParam = SqlParam + GetString(vDevice->GetDeviceName()) + " , ";

	SqlStr = SqlStr + "DeviceType ";
	SqlParam = SqlParam + GetString(vDevice->GetDeviceType());
}