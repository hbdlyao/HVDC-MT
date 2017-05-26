///////////////////////////////////////////////////////////
//  CMyObjBase.cpp
//  Implementation of the Class CMyObjBase
//  Created on:      02-4ÔÂ-2017 15:16:13
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CMyObjBase.h"

CMyObjBase::CMyObjBase()
{
}

CMyObjBase::~CMyObjBase()
{
	Release();
}


void CMyObjBase::Release()
{

}

void CMyObjBase::Clear()
{

}

void CMyObjBase::Init()
{
	//objGUID = CMyFunc::CreateObjID();
	//
}


int CMyObjBase::GetObjGUID()
{

	return objGUID;
}


void CMyObjBase::SetObjGUID(int newVal)
{

	objGUID = newVal;
}