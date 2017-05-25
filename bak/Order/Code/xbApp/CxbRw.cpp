///////////////////////////////////////////////////////////
//  CxbRw.cpp
//  Implementation of the Class CxbRw
//  Created on:      06-4ÔÂ-2017 17:56:23
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbRw.h"

void CxbRw::doLoad(CDevBase * vDevice)
{
	string vFieldName;
	string vStr;
	_variant_t vValue;

	CxbDevBase * vDev;

	vDev = dynamic_cast<CxbDevBase *>(vDevice);
	
	CRwDev::doLoad(vDev);

	RwAdo->GetFieldValue("PosOrNeg", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetPosOrNeg(vValue.iVal);//ÕûÐÍ
	};

}

void CxbRw::doSave(CDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevBase * vDev;

	vDev = dynamic_cast<CxbDevBase *>(vDevice);

	CRwDev::doSave(vDev);

	SqlStr = SqlStr + ",";
	SqlParam = SqlParam + ",";

	SqlStr = SqlStr + "PosOrNeg ";
	SqlParam = SqlParam + GetString(vDev->GetPosOrNeg());

}