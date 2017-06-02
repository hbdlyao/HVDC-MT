///////////////////////////////////////////////////////////
//  CMyFunc.cpp
//  Implementation of the Class CMyFunc
//  Created on:      25-3月-2017 14:30:49
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include <time.h>
#include <CString>

#include <stdio.h>

#include "CMyFunc.h"


CMyFunc::CMyFunc() {

}



CMyFunc::~CMyFunc() {

}



CMyFunc::CMyFunc(const CMyFunc& theCMyFunc)
{

}


string CMyFunc::CreateObjID()
{

	unsigned x;
	unsigned vSeed;
	//return 0;

	vSeed = (unsigned)time(NULL);
	srand(vSeed); //srand(3)
	x = rand();

	//x = x / RAND_MAX;

	return to_string(x);

}

string CMyFunc::GetString(string vStr)
{
	vStr = "'" + vStr + "'";

	return vStr;

}



string CMyFunc::GetString(double vX, const char * vfmt )
{
	char vChar[15];
	sprintf_s(vChar, 15, vfmt, vX);

	return vChar;

}

string CMyFunc::GetString(int vX, const char * vfmt )
{
	char vChar[15];
	sprintf_s(vChar, 15, vfmt, vX);

	return vChar;

}

string CMyFunc::VarToStr(_variant_t & vVar)
{
	string vStr;

	switch (vVar.vt)
	{
	case VT_BSTR://字符串
	case VT_LPSTR://字符串
	case VT_LPWSTR://字符串
		vStr = (_bstr_t)vVar;
		break;
	case VT_I1:
	case VT_UI1:
		vStr = to_string(vVar.bVal);
		break;
	case VT_I2://短整型
		vStr = to_string(vVar.iVal);
		break;
	case VT_UI2://无符号短整型
		vStr = to_string(vVar.uiVal);
		break;
	case VT_INT://整型
		vStr = to_string(vVar.intVal);
		break;
	case VT_I4: //整型
		vStr = to_string(vVar.lVal);
		break;
	case VT_I8: //长整型
		vStr = to_string(vVar.lVal);
		break;
	case VT_UINT://无符号整型
		vStr = to_string(vVar.uintVal);
		break;
	case VT_UI4: //无符号整型
		vStr = to_string(vVar.ulVal);
		break;
	case VT_UI8: //无符号长整型
		vStr = to_string(vVar.ulVal);
		break;
	case VT_VOID:
		//vStr = to_string(vVar.byref);

		break;
	case VT_R4://浮点型
			   //vStr.Format(_T("%.4f"), vVar.fltVal);
		vStr = to_string(vVar.fltVal);
		break;
	case VT_R8://双精度型
			   //vStr.Format(_T("%.8f"), vVar.dblVal);
		vStr = to_string(vVar.dblVal);
		break;
	case VT_DECIMAL: //小数
					 //vStr.Format(_T("%.8f"), (double)vVar);
		vStr = to_string((double)vVar);
		break;
	case VT_CY:
		/*
		{
		COleCurrency cy = vVar.cyVal;
		vStr = cy.Format();
		}
		*/
		break;
	case VT_BLOB:
	case VT_BLOB_OBJECT:
	case 0x2011:
		vStr = "[BLOB]";
		break;

	case VT_BOOL://布尔型
		vStr = vVar.boolVal ? "TRUE" : "FALSE";
		break;
	case VT_DATE: //日期型
				  /*
				  {
				  DATE dt = vVar.date;
				  COleDateTime da = COleDateTime(dt);
				  vStr = da.Format(_T("%Y-%m-%d %H:%M:%S"));
				  }*/

		break;
	case VT_NULL://NULL值
		vStr = "";
		break;
	case VT_EMPTY://空
		vStr = "";
		break;
	case VT_UNKNOWN://未知类型
	default:
		vStr = "UN_KNOW";
		break;
	}
	return vStr;
}

