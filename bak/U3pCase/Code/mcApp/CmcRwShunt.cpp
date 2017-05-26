///////////////////////////////////////////////////////////
//  CmcRwShunt.cpp
//  Implementation of the Class CmcRwShunt
//  Created on:      18-4月-2017 20:25:00
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwShunt.h"

void CmcRwShunt::doLoad(CDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevShunt * vDev;
	
	vDev = dynamic_cast<CmcDevShunt *>(vDevice);
	
	CmcRwOne::doLoad(vDevice);
	
	RwAdo->GetFieldValue("ZrN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZrN(vValue.dblVal); //双精度
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


void CmcRwShunt::doSave(CDevBase* vDevice)
{

	CmcDevShunt * vDev;
	
	vDev = dynamic_cast<CmcDevShunt *>(vDevice);
	
	CmcRwOne::doSave(vDevice);	

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
	SqlParam = SqlParam + GetString(vDev->GetZx_C()) ;

}