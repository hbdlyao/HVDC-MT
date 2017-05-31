///////////////////////////////////////////////////////////
//  CmcRwXf2.cpp
//  Implementation of the Class CmcRwXf2
//  Created on:      18-4月-2017 20:38:23
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwXf2.h"


void CmcRwXf2::doLoad(CDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevXf2 * vDev;

	vDev = dynamic_cast<CmcDevXf2 *>(vDevice);

	CmcRwTwo::doLoad(vDevice);


	//
	RwAdo->GetFieldValue("AngleMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetAngleMax(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("AngleMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetAngleMin(vValue.dblVal);//双精度
	};

	RwAdo->GetFieldValue("FixedURef", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetFixedURef(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("TapCtrlType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapCtrlType(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("TapMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapMax(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("TapMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapMin(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("TapN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapN(vValue.iVal);//整型
	};
	
	RwAdo->GetFieldValue("TapSetup", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTapSetup(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("TkN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTkN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UacN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Ukp", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUkp(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Urp", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUrp(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UvMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUvMax(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UvN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUvN(vValue.dblVal); //双精度
	};

}

void CmcRwXf2::doSave(CDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevXf2 * vDev;

	vDev = dynamic_cast<CmcDevXf2 *>(vDevice);

	CmcRwTwo::doSave(vDevice);

	SqlStr = SqlStr + ",";
	SqlParam = SqlParam + ",";

	SqlStr = SqlStr + "FixedURef, ";
	SqlParam = SqlParam +GetString(vDev->GetFixedURef()) + ",";

	SqlStr = SqlStr + "FixedUType, ";
	SqlParam = SqlParam +GetString(vDev->GetFixedUType()) + ",";

	SqlStr = SqlStr + "AngleMax, ";
	SqlParam = SqlParam +GetString(vDev->GetAngleMax()) + ",";

	SqlStr = SqlStr + "AngleMin, ";
	SqlParam = SqlParam +GetString(vDev->GetAngleMin()) + ",";

	SqlStr = SqlStr + "TapCtrlType, ";
	SqlParam = SqlParam +GetString(vDev->GetTapCtrlType()) + ",";

	SqlStr = SqlStr + "TapN, ";
	SqlParam = SqlParam +GetString(vDev->GetTapN()) + ",";

	SqlStr = SqlStr + "TapMax, ";
	SqlParam = SqlParam +GetString(vDev->GetTapMax()) + ",";

	SqlStr = SqlStr + "TapMin, ";
	SqlParam = SqlParam +GetString(vDev->GetTapMin()) + ",";

	SqlStr = SqlStr + "TapSetup, ";
	SqlParam = SqlParam +GetString(vDev->GetTapSetup()) + ",";

	SqlStr = SqlStr + "Ukp, ";
	SqlParam = SqlParam +GetString(vDev->GetUkp()) + ",";

	SqlStr = SqlStr + "Urp, ";
	SqlParam = SqlParam +GetString(vDev->GetUrp()) + ",";

	SqlStr = SqlStr + "TkN, ";
	SqlParam = SqlParam +GetString(vDev->GetTkN()) + ",";

	SqlStr = SqlStr + "UacN, ";
	SqlParam = SqlParam +GetString(vDev->GetUacN()) + ",";

	SqlStr = SqlStr + "UvN, ";
	SqlParam = SqlParam +GetString(vDev->GetUvN()) + ",";

	SqlStr = SqlStr + "UvMax ";
	SqlParam = SqlParam +GetString(vDev->GetUvMax());
}