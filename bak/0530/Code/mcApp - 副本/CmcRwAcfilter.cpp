///////////////////////////////////////////////////////////
//  CmcRwAcfilter.cpp
//  Implementation of the Class CmcRwAcfilter
//  Created on:      18-4��-2017 20:38:13
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwAcfilter.h"


void CmcRwAcfilter::doLoad(CDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevAcFilter * vDev;

	vDev = dynamic_cast<CmcDevAcFilter *>(vDevice);

	CmcRwOne::doLoad(vDevice);


	RwAdo->GetFieldValue("UacN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUacN(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("QacN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQacN(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("QacfN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQacfN(vValue.dblVal); //˫����
	};

}


void CmcRwAcfilter::doSave(CDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CmcDevAcFilter * vDev;

	vDev = dynamic_cast<CmcDevAcFilter *>(vDevice);

	CmcRwOne::doSave(vDevice);


	SqlStr = SqlStr + ",";
	SqlParam = SqlParam + ",";

	SqlStr = SqlStr + "UacN, ";
	SqlParam = SqlParam + GetString(vDev->GetUacN()) + " , ";

	SqlStr = SqlStr + "QacN, ";
	SqlParam = SqlParam + GetString(vDev->GetQacN()) + " , ";

	SqlStr = SqlStr + "QacfN ";
	SqlParam = SqlParam + GetString(vDev->GetQacfN());

	//
}