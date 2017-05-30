///////////////////////////////////////////////////////////
//  CmcRwConvertor.cpp
//  Implementation of the Class CmcRwConvertor
//  Created on:      22-4月-2017 14:52:12
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwConvertor.h"


void CmcRwConvertor::doLoad(CDevBase* vDevice){

	string vStr;
	_variant_t vValue;
	CmcDevConvertor * vDev;
	
	vDev = dynamic_cast<CmcDevConvertor *>(vDevice);
	
	CmcRwTwo::doLoad(vDevice);

	RwAdo->GetFieldValue("PconvN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetPconvN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("QconvN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQconvN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("miuN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetmiuN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Alpha_gamaN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetAlpha_gamaN(vValue.dblVal); //双精度
	};

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

	RwAdo->GetFieldValue("PdN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetPdN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UdN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUdN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("UT", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUT(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Valvor12Count", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetValvor12Count(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("UdioN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUdioN(vValue.dblVal);//双精度
	};

	RwAdo->GetFieldValue("UvN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUvN(vValue.dblVal);//双精度
	};

	RwAdo->GetFieldValue("IdN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetIdN(vValue.dblVal);//双精度
	};

	RwAdo->GetFieldValue("StationType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetStationType(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("StationCtrlType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetStationCtrlType(vValue.iVal);//整型
	};
	RwAdo->GetFieldValue("StationCtrlTypeN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetStationCtrlTypeN(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("IsGround", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetIsGround(vValue.iVal);//整型
	};

	RwAdo->GetFieldValue("AngleRef", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetAngleRef(vValue.dblVal); //双精度
	};
	
	RwAdo->GetFieldValue("MeasureStation", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue; //字符型
		vDev->SetMeasureStation(vStr);
	};

}

void CmcRwConvertor::doSave(CDevBase* vDevice){

	string vStr;
	_variant_t vValue;
	CmcDevConvertor * vDev;
	
	vDev = dynamic_cast<CmcDevConvertor *>(vDevice);
	
	CmcRwTwo::doSave(vDevice);
	
	SqlStr = SqlStr + ",";
	SqlParam = SqlParam + ",";

	SqlStr = SqlStr + "Valvor12Count,";
	SqlParam = SqlParam +GetString(vDev->GetValvor12Count()) + ",";

	SqlStr = SqlStr + "PconvN, ";
	SqlParam = SqlParam +GetString(vDev->GetPconvN()) + ",";

	SqlStr = SqlStr + "QconvN, ";
	SqlParam = SqlParam +GetString(vDev->GetQconvN()) + ",";

	SqlStr = SqlStr + "miuN, ";
	SqlParam = SqlParam +GetString(vDev->GetmiuN()) + ",";

	SqlStr = SqlStr + "Alpha_gamaN, ";
	SqlParam = SqlParam +GetString(vDev->GetAlpha_gamaN()) + ",";

	SqlStr = SqlStr + "AngleMax, ";
	SqlParam = SqlParam +GetString(vDev->GetAngleMax()) + ",";

	SqlStr = SqlStr + "AngleMin, ";
	SqlParam = SqlParam +GetString(vDev->GetAngleMin()) + ",";

	SqlStr = SqlStr + "PdN, ";
	SqlParam = SqlParam +GetString(vDev->GetPdN()) + ",";

	SqlStr = SqlStr + "UdN, ";
	SqlParam = SqlParam +GetString(vDev->GetUdN()) + ",";

	SqlStr = SqlStr + "IdN, ";
	SqlParam = SqlParam +GetString(vDev->GetIdN()) + ",";

	SqlStr = SqlStr + "UT, ";
	SqlParam = SqlParam +GetString(vDev->GetUT()) + ",";

	SqlStr = SqlStr + "UdioN, ";
	SqlParam = SqlParam +GetString(vDev->GetUdioN()) + ",";

	SqlStr = SqlStr + "UvN, ";
	SqlParam = SqlParam +GetString(vDev->GetUvN()) + ",";

	SqlStr = SqlStr + "StationType, ";
	SqlParam = SqlParam +GetString(vDev->GetStationType()) + ",";

	SqlStr = SqlStr + "StationCtrlType, ";
	SqlParam = SqlParam +GetString(vDev->GetStationCtrlType()) + ",";

	SqlStr = SqlStr + "StationCtrlTypeN, ";
	SqlParam = SqlParam +GetString(vDev->GetStationCtrlTypeN()) + ",";

	SqlStr = SqlStr + "IsGround, ";
	SqlParam = SqlParam +GetString(vDev->GetIsGround()) + ",";

	SqlStr = SqlStr + "AngleRef, ";
	SqlParam = SqlParam +GetString(vDev->GetAngleRef()) + ",";

	SqlStr = SqlStr + "MeasureStation ";
	SqlParam = SqlParam +GetString(vDev->GetMeasureStation());
}