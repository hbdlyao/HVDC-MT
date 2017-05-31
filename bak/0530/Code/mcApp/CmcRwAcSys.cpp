///////////////////////////////////////////////////////////
//  CmcRwAcSys.cpp
//  Implementation of the Class CmcRwAcSys
//  Created on:      18-4月-2017 20:38:07
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwAcSys.h"

void CmcRwAcSys::doLoad(CDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(vDevice);

	CmcRwOne::doLoad(vDevice);


	RwAdo->GetFieldValue("QfMinN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQfMinN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("QfMaxN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQfMaxN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("QinMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQinMax(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("QoutMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQoutMax(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UacExMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacExMin(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UacMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacMax(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UacMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacMin(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UacN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacN(vValue.dblVal); //双精度
	};

}

void CmcRwAcSys::doSave(CDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(vDevice);

	CmcRwOne::doSave(vDevice);

	SqlStr = SqlStr + ",";
	SqlParam = SqlParam + ",";

	SqlStr = SqlStr + "QfMinN, ";
	SqlParam = SqlParam + GetString(vDev->GetQfMinN()) + " , ";

	SqlStr = SqlStr + "QfMaxN, ";
	SqlParam = SqlParam + GetString(vDev->GetQfMaxN()) + " , ";

	SqlStr = SqlStr + "QinMax, ";
	SqlParam = SqlParam + GetString(vDev->GetQinMax()) + " , ";

	SqlStr = SqlStr + "QoutMax, ";
	SqlParam = SqlParam + GetString(vDev->GetQoutMax()) + " , ";

	SqlStr = SqlStr + "UacExMin, ";
	SqlParam = SqlParam + GetString(vDev->GetUacExMin()) + " , ";

	SqlStr = SqlStr + "UacMax, ";
	SqlParam = SqlParam + GetString(vDev->GetUacMax()) + " , ";

	SqlStr = SqlStr + "UacMin, ";
	SqlParam = SqlParam + GetString(vDev->GetUacMin()) + " , ";

	SqlStr = SqlStr + "UacN ";
	SqlParam = SqlParam + GetString(vDev->GetUacN());
}