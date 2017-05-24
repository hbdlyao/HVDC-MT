///////////////////////////////////////////////////////////
//  CxbRwBranch.cpp
//  Implementation of the Class CxbRwBranch
//  Created on:      18-4月-2017 17:11:24
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwBranch.h"
#include "CxbDevBranch.h"

void CxbRwBranch::doLoad(CDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevBranch * vDev;

	vDev = dynamic_cast<CxbDevBranch *>(vDevice);

	CxbRwTwo::doLoad(vDev);

	RwAdo->GetFieldValue("Zr", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZr(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Z_L", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZ_L(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Z_C", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZ_C(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Zx_L", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZx_L(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Zx_C", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZx_C(vValue.dblVal); //双精度
	};
}


void CxbRwBranch::doSave(CDevBase * vDevice)
{
	CxbDevBranch * vDev;

	vDev = dynamic_cast<CxbDevBranch *>(vDevice);

	CxbRwTwo::doSave(vDev);

	SqlStr = SqlStr + ",";
	SqlParam = SqlParam + ",";

	SqlStr = SqlStr + "Zr, ";
	SqlParam = SqlParam + GetString(vDev->GetZr()) + " , ";

	SqlStr = SqlStr + "Z_L, ";
	SqlParam = SqlParam + GetString(vDev->GetZ_L()) + " , ";

	SqlStr = SqlStr + "Z_C, ";
	SqlParam = SqlParam + GetString(vDev->GetZ_C()) + " , ";

	SqlStr = SqlStr + "Zx_L, ";
	SqlParam = SqlParam + GetString(vDev->GetZx_L()) + " , ";

	SqlStr = SqlStr + "Zx_C ";
	SqlParam = SqlParam + GetString(vDev->GetZx_C());

}
