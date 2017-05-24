///////////////////////////////////////////////////////////
//  CObjBase.cpp
//  Implementation of the Class CObjBase
//  Created on:      02-4ÔÂ-2017 15:16:13
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CObjBase.h"

CObjBase::CObjBase()
{
}

CObjBase::~CObjBase()
{
	Release();
}


void CObjBase::Release()
{

}

void CObjBase::Clear()
{

}

void CObjBase::Init()
{
	//objGUID = CMyFunc::CreateObjID();
	//
}




int CObjBase::GetObjGUID(){

	return objGUID;
}


void CObjBase::SetObjGUID(int newVal)
{

	objGUID = newVal;
}