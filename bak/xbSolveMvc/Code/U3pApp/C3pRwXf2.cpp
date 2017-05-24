///////////////////////////////////////////////////////////
//  C3pRwXf2.cpp
//  Implementation of the Class C3pRwXf2
//  Created on:      18-5月-2017 8:07:40
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pRwXf2.h"


void C3pRwXf2::doLoad(CDevBase* vDevice)
{

	string vStr;
	_variant_t vValue;
	C3pDevXf2 * vDev;
	
	vDev = dynamic_cast<C3pDevXf2 *>(vDevice);
	
	C3pRwTwo::doLoad(vDevice);
	
		
	RwAdo->GetFieldValue("SN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTkN(vValue.dblVal); //双精度
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
				
	RwAdo->GetFieldValue("UvN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetUvN(vValue.dblVal); //双精度
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


	RwAdo->GetFieldValue("dTkN", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetdTkN(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("PhaseShift", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetTkN(vValue.dblVal); //双精度
	};

	/*
	RwAdo->GetFieldValue("Std_Lt", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetStd_Lt(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("Dis_dLt", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetDis_dLt(vValue.dblVal); //双精度
	};
	*/

	RwAdo->GetFieldValue("deltaLtA", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetdLtA(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("deltaLtB", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetdLtB(vValue.dblVal); //双精度
	};

	RwAdo->GetFieldValue("deltaLtC", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetdLtC(vValue.dblVal); //双精度
	};


}


void C3pRwXf2::doSave(CDevBase* vDevice)
	{

	string vStr;
	_variant_t vValue;
	C3pDevXf2 * vDev;
	
	vDev = dynamic_cast<C3pDevXf2 *>(vDevice);
	
	C3pRwTwo::doSave(vDevice);
	
	SqlStr = SqlStr + ",";
	SqlParam = SqlParam + ",";
	
	SqlStr = SqlStr + "Ukp, ";
	SqlParam = SqlParam +GetString(vDev->GetUkp()) + ",";
	
	SqlStr = SqlStr + "Urp, ";
	SqlParam = SqlParam +GetString(vDev->GetUrp()) + ",";

		
	SqlStr = SqlStr + "SN, ";
	SqlParam = SqlParam +GetString(vDev->GetSN()) + ",";
	
	SqlStr = SqlStr + "TkN, ";
	SqlParam = SqlParam +GetString(vDev->GetTkN()) + ",";
	
	SqlStr = SqlStr + "UacN, ";
	SqlParam = SqlParam +GetString(vDev->GetUacN()) + ",";
	
	SqlStr = SqlStr + "UvN, ";
	SqlParam = SqlParam +GetString(vDev->GetUvN()) + ",";

	SqlStr = SqlStr + "PhaseShift, ";
	SqlParam = SqlParam +GetString(vDev->GetPhaseShift()) + ",";
	
	SqlStr = SqlStr + "dTkN, ";
	SqlParam = SqlParam +GetString(vDev->GetdTkN()) + ",";
	
	//SqlStr = SqlStr + "Std_Lt, ";
	//SqlParam = SqlParam +GetString(vDev->GetStd_Lt()) + ",";

	//SqlStr = SqlStr + "Dis_dLt, ";
	//SqlParam = SqlParam +GetString(vDev->GetDis_dLt()) + ",";
	
	SqlStr = SqlStr + "deltaLtA, ";
	SqlParam = SqlParam +GetString(vDev->GetdLtA()) + ",";
	
	SqlStr = SqlStr + "deltaLtB, ";
	SqlParam = SqlParam +GetString(vDev->GetdLtB()) + ",";

	SqlStr = SqlStr + "deltaLtC ";
	SqlParam = SqlParam +GetString(vDev->GetdLtC());



}