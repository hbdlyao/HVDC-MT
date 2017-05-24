///////////////////////////////////////////////////////////
//  CxbRwShunt.cpp
//  Implementation of the Class CxbRwShunt
//  Created on:      18-4月-2017 17:11:19
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwShunt.h"
#include "CxbDevShunt.h"

void CxbRwShunt::doLoad(CDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevShunt * vDev;

	vDev = dynamic_cast<CxbDevShunt *>(vDevice);

	CxbRwOne::doLoad(vDev);


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


void CxbRwShunt::doSave(CDevBase * vDevice)
{
	CxbDevShunt * vDev;

	vDev = dynamic_cast<CxbDevShunt *>(vDevice);

	CxbRwOne::doSave(vDev);

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
