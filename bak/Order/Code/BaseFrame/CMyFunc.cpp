///////////////////////////////////////////////////////////
//  CMyFunc.cpp
//  Implementation of the Class CMyFunc
//  Created on:      25-3��-2017 14:30:49
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include <time.h>
#include <CString>

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

string CMyFunc::GetString(double vX)
{
	string vStr;

	vStr = to_string(vX);

	return vStr;

}
string CMyFunc::GetString(int vX)
{
	string vStr;

	vStr = to_string(vX);

	return vStr;
}

string CMyFunc::VarToStr(_variant_t & vVar)
{
	string vStr;

	switch (vVar.vt)
	{
	case VT_BSTR://�ַ���
	case VT_LPSTR://�ַ���
	case VT_LPWSTR://�ַ���
		vStr = (_bstr_t)vVar;
		break;
	case VT_I1:
	case VT_UI1:
		vStr = to_string(vVar.bVal);
		break;
	case VT_I2://������
		vStr = to_string(vVar.iVal);
		break;
	case VT_UI2://�޷��Ŷ�����
		vStr = to_string(vVar.uiVal);
		break;
	case VT_INT://����
		vStr = to_string(vVar.intVal);
		break;
	case VT_I4: //����
		vStr = to_string(vVar.lVal);
		break;
	case VT_I8: //������
		vStr = to_string(vVar.lVal);
		break;
	case VT_UINT://�޷�������
		vStr = to_string(vVar.uintVal);
		break;
	case VT_UI4: //�޷�������
		vStr = to_string(vVar.ulVal);
		break;
	case VT_UI8: //�޷��ų�����
		vStr = to_string(vVar.ulVal);
		break;
	case VT_VOID:
		//vStr = to_string(vVar.byref);

		break;
	case VT_R4://������
			   //vStr.Format(_T("%.4f"), vVar.fltVal);
		vStr = to_string(vVar.fltVal);
		break;
	case VT_R8://˫������
			   //vStr.Format(_T("%.8f"), vVar.dblVal);
		vStr = to_string(vVar.dblVal);
		break;
	case VT_DECIMAL: //С��
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

	case VT_BOOL://������
		vStr = vVar.boolVal ? "TRUE" : "FALSE";
		break;
	case VT_DATE: //������
				  /*
				  {
				  DATE dt = vVar.date;
				  COleDateTime da = COleDateTime(dt);
				  vStr = da.Format(_T("%Y-%m-%d %H:%M:%S"));
				  }*/

		break;
	case VT_NULL://NULLֵ
		vStr = "";
		break;
	case VT_EMPTY://��
		vStr = "";
		break;
	case VT_UNKNOWN://δ֪����
	default:
		vStr = "UN_KNOW";
		break;
	}
	return vStr;
}

