///////////////////////////////////////////////////////////
//  CxbRwDCF.cpp
//  Implementation of the Class CxbRwDCF
//  Created on:      18-4月-2017 23:40:50
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwDCF.h"
#include "CxbDevDCF.h"
#include "CxbDevDCF_RLC.h"


void CxbRwDCF::doLoad(CDevBase * vDevice)
{
	string vStr;
	_variant_t vValue;
	CxbDevDCF * vDev;
	
	vDev = dynamic_cast<CxbDevDCF *>(vDevice);
	
	CxbRw::doLoad(vDev);
	
	RwAdo->GetFieldValue("DcfType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetDCFType(vValue.iVal); //整型
	};

	RwAdo->GetFieldValue("MaxFreqDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMaxFreqDelta(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("MinFreqDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMinFreqDelta(vValue.dblVal); //双精度
	};
	
}

void CxbRwDCF::doLoad_Leaf_Data(CxbDevBase * vLeaf)
{
	string vStr;
	_variant_t vValue;
	CxbDevDCF_RLC * vDev;

	vDev = dynamic_cast<CxbDevDCF_RLC *>(vLeaf);

	CxbRwRLCs::doLoad_Leaf_Data(vDev);

	//
	RwAdo->GetFieldValue("MaxRDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMaxRDelta(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("MinRDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMinRDelta(vValue.dblVal); //双精度
	};

	//
	RwAdo->GetFieldValue("MaxLDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMaxLDelta(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("MinLDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMinLDelta(vValue.dblVal); //双精度
	};

	//
	RwAdo->GetFieldValue("MaxCDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMaxCDelta(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("MinCDelta", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetMinCDelta(vValue.dblVal); //双精度
	};

}

void CxbRwDCF::doSave(CDevBase * vLeaf)
{
	CxbDevDCF * vDev;

	vDev = dynamic_cast<CxbDevDCF *>(vLeaf);

	CxbRw::doSave(vLeaf);

	SqlStr = SqlStr + ", ";
	SqlParam = SqlParam + " , ";

	SqlStr = SqlStr + "DcfType, ";
	SqlParam = SqlParam + GetString(vDev->GetDCFType()) + " , ";

	SqlStr = SqlStr + "MaxFreqDelta, ";
	SqlParam = SqlParam + GetString(vDev->GetMaxFreqDelta()) + " , ";

	SqlStr = SqlStr + "MinFreqDelta ";
	SqlParam = SqlParam + GetString(vDev->GetMinFreqDelta());

}

void CxbRwDCF::doSave_Leaf_Data(CxbDevBase * vLeaf)
{
	CxbDevDCF_RLC * vDev;

	vDev = dynamic_cast<CxbDevDCF_RLC *>(vLeaf);

	CxbRwRLCs::doSave_Leaf_Data(vLeaf);

	SqlStr = SqlStr + ", ";
	SqlParam = SqlParam + " , ";

	SqlStr = SqlStr + "MaxRDelta, ";
	SqlParam = SqlParam + GetString(vDev->GetMaxRDelta()) + " , ";

	SqlStr = SqlStr + "MinRDelta, ";
	SqlParam = SqlParam + GetString(vDev->GetMinRDelta()) + " , ";

	SqlStr = SqlStr + "MaxLDelta, ";
	SqlParam = SqlParam + GetString(vDev->GetMaxLDelta()) + " , ";

	SqlStr = SqlStr + "MinLDelta, ";
	SqlParam = SqlParam + GetString(vDev->GetMinLDelta()) + " , ";

	SqlStr = SqlStr + "MaxCDelta, ";
	SqlParam = SqlParam + GetString(vDev->GetMaxCDelta()) + " , ";

	SqlStr = SqlStr + "MinCDelta ";
	SqlParam = SqlParam + GetString(vDev->GetMinCDelta());
}
