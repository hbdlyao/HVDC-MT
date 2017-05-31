///////////////////////////////////////////////////////////
//  CmcRwGroundLine.cpp
//  Implementation of the Class CmcRwGroundLine
//  Created on:      18-4月-2017 22:02:19
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwGroundLine.h"


void CmcRwGroundLine::doLoad(CDevBase* vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevGroundLine * vDev;

	vDev = dynamic_cast<CmcDevGroundLine *>(vDevice);

	CmcRwTwo::doLoad(vDevice);


	RwAdo->GetFieldValue("ZrN", vValue);

	if (vValue.vt != VT_NULL)
	{
		vDev->SetZrN(vValue.dblVal); //双精度
	};

	//
	RwAdo->GetFieldValue("ZrMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZrMax(vValue.dblVal); //双精度
	};


	//
	RwAdo->GetFieldValue("ZrMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetZrMin(vValue.dblVal); //双精度
	};

}


void CmcRwGroundLine::doSave(CDevBase* vDevice)
{
	CmcDevGroundLine * vDev;

	vDev = dynamic_cast<CmcDevGroundLine *>(vDevice);

	CmcRwTwo::doSave(vDevice);

	SqlStr = SqlStr + ",";
	SqlParam = SqlParam + ",";

	SqlStr = SqlStr + "ZrN, ";
	SqlParam = SqlParam + GetString(vDev->GetZrN()) + ",";

	SqlStr = SqlStr + "ZrMax, ";
	SqlParam = SqlParam + GetString(vDev->GetZrMax()) + ",";

	SqlStr = SqlStr + "ZrMin ";
	SqlParam = SqlParam + GetString(vDev->GetZrMin());
}