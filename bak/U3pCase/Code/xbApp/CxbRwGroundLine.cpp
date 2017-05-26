///////////////////////////////////////////////////////////
//  CxbRwGroundLine.cpp
//  Implementation of the Class CxbRwGroundLine
//  Created on:      26-4ÔÂ-2017 23:54:28
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwGroundLine.h"


void CxbRwGroundLine::doLoad_Leaf_Data(CxbDevBase* vLeaf)
{
	string vStr;
	_variant_t vValue;
	CxbDevGroundLine_Seg * vDev;


	vDev = dynamic_cast<CxbDevGroundLine_Seg *>(vLeaf);

	CxbRw_Tree::doLoad_Leaf_Data(vDev);


	RwAdo->GetFieldValue("Leng", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_Long(vValue.dblVal);
	};

	RwAdo->GetFieldValue("WireCount", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_WireCount(vValue.intVal);
	};

	RwAdo->GetFieldValue("Hspace0", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_Hspace(0, vValue.dblVal);
	};

	RwAdo->GetFieldValue("Hspace1", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_Hspace(1, vValue.dblVal);
	};

	RwAdo->GetFieldValue("Hspace2", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_Hspace(2, vValue.dblVal);
	};

	RwAdo->GetFieldValue("Height0", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_Height(0, vValue.dblVal);
	};

	RwAdo->GetFieldValue("Height1", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_Height(1, vValue.dblVal);
	};

	RwAdo->GetFieldValue("Height2", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_Height(2, vValue.dblVal);
	};

	RwAdo->GetFieldValue("Sag0", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_Sag(0, vValue.dblVal);
	};

	RwAdo->GetFieldValue("Sag1", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_Sag(1, vValue.dblVal);
	};

	RwAdo->GetFieldValue("Sag2", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_Sag(2, vValue.dblVal);
	};

	RwAdo->GetFieldValue("L_CondRadius", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_L_CondRadius(vValue.dblVal);
	};

	RwAdo->GetFieldValue("G_CondRadius", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_G_CondRadius(vValue.dblVal);
	};

	RwAdo->GetFieldValue("L_CondType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_L_CondType(vValue.intVal);
	};

	RwAdo->GetFieldValue("L_CondValue", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_L_CondValue(vValue.dblVal);
	};

	RwAdo->GetFieldValue("G_CondType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_G_CondType(vValue.intVal);
	};

	RwAdo->GetFieldValue("G_CondValue", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_G_CondValue(vValue.dblVal);
	};

	RwAdo->GetFieldValue("L_SplitAmount", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_L_SplitAmount(vValue.intVal);
	};

	RwAdo->GetFieldValue("G_SplitAmount", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_G_SplitAmount(vValue.intVal);
	};

	RwAdo->GetFieldValue("L_BundleSpace", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_L_BundleSpace(vValue.dblVal);
	};

	RwAdo->GetFieldValue("G_BundleSpace", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_G_BundleSpace(vValue.dblVal);
	};

	RwAdo->GetFieldValue("SoilRe", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->pLineParam.WireParam.set_SoilRe(vValue.dblVal);
	};

}

void CxbRwGroundLine::doSave_Leaf_Data(CxbDevBase* vLeaf)
{
	CxbDevGroundLine_Seg * vDev;

	vDev = (CxbDevGroundLine_Seg *)(vLeaf);

	CxbRw_Tree::doSave_Leaf_Data(vDev);


	SqlStr = SqlStr + ", ";
	SqlParam = SqlParam + " , ";

	SqlStr = SqlStr + "WireCount, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.WireCount) + " , ";

	SqlStr = SqlStr + "Leng, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.Long) + " , ";

	SqlStr = SqlStr + "Hspace0, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.Hspace[0]) + " , ";

	SqlStr = SqlStr + "Hspace1, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.Hspace[1]) + " , ";

	SqlStr = SqlStr + "Hspace2, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.Hspace[2]) + " , ";

	SqlStr = SqlStr + "Height0, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.Height[0]) + " , ";

	SqlStr = SqlStr + "Height1, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.Height[1]) + " , ";

	SqlStr = SqlStr + "Height2, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.Height[2]) + " , ";

	SqlStr = SqlStr + "Sag0, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.Sag[0]) + " , ";

	SqlStr = SqlStr + "Sag1, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.Sag[1]) + " , ";

	SqlStr = SqlStr + "Sag2, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.Sag[2]) + " , ";

	SqlStr = SqlStr + "L_CondRadius, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.L_CondRadius) + " , ";

	SqlStr = SqlStr + "L_CondType, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.L_CondType) + " , ";

	SqlStr = SqlStr + "L_CondValue, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.L_CondValue) + " , ";

	SqlStr = SqlStr + "G_CondRadius, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.G_CondRadius) + " , ";

	SqlStr = SqlStr + "G_CondType, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.G_CondType) + " , ";

	SqlStr = SqlStr + "G_CondValue, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.G_CondValue) + " , ";

	SqlStr = SqlStr + "L_SplitAmount, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.L_SplitAmount) + " , ";

	SqlStr = SqlStr + "G_SplitAmount, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.G_SplitAmount) + " , ";

	SqlStr = SqlStr + "L_BundleSpace, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.L_BundleSpace) + " , ";

	SqlStr = SqlStr + "G_BundleSpace, ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.G_BundleSpace) + " , ";

	SqlStr = SqlStr + "SoilRe ";
	SqlParam = SqlParam + GetString(vDev->pLineParam.WireParam.SoilRe);

}
