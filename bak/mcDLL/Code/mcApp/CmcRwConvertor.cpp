///////////////////////////////////////////////////////////
//  CmcRwConvertor.cpp
//  Implementation of the Class CmcRwConvertor
//  Created on:      22-4��-2017 14:52:12
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
		vDev->SetPconvN(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("QconvN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetQconvN(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("miuN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetmiuN(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("Alpha_gamaN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetAlpha_gamaN(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("AngleMax", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetAngleMax(vValue.dblVal); //˫����
	};
	
	
	RwAdo->GetFieldValue("AngleMin", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetAngleMin(vValue.dblVal);//˫����
	};

	RwAdo->GetFieldValue("PdN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetPdN(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("UdN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUdN(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("UT", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUT(vValue.dblVal); //˫����
	};

	RwAdo->GetFieldValue("Valvor12Count", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetValvor12Count(vValue.iVal);//����
	};

	RwAdo->GetFieldValue("UdioN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUdioN(vValue.dblVal);//˫����
	};

	RwAdo->GetFieldValue("UvN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUvN(vValue.dblVal);//˫����
	};

	RwAdo->GetFieldValue("IdN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetIdN(vValue.dblVal);//˫����
	};

	RwAdo->GetFieldValue("StationType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetStationType(vValue.iVal);//����
	};

	RwAdo->GetFieldValue("StationCtrlType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetStationCtrlType(vValue.iVal);//����
	};
	RwAdo->GetFieldValue("StationCtrlTypeN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetStationCtrlTypeN(vValue.iVal);//����
	};

	RwAdo->GetFieldValue("IsGround", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetIsGround(vValue.iVal);//����
	};

	RwAdo->GetFieldValue("AngleRef", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetAngleRef(vValue.dblVal); //˫����
	};
	
	RwAdo->GetFieldValue("MeasureStation", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue; //�ַ���
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