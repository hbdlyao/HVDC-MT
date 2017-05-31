///////////////////////////////////////////////////////////
//  C3pRwConvertor.cpp
//  Implementation of the Class C3pRwConvertor
//  Created on:      18-5ÔÂ-2017 8:07:32
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pRwConvertor.h"


void C3pRwConvertor::doLoad(CDevBase* vDevice)
{

	string vStr;
	_variant_t vValue;
	C3pDevConvertor * vDev;
	
	vDev = dynamic_cast<C3pDevConvertor *>(vDevice);
	
	C3pRwTwo::doLoad(vDevice);


	RwAdo->GetFieldValue("DeviceType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDevice->SetDeviceType(vValue.iVal);//ÕûÐÍ
	};
	
}


void C3pRwConvertor::doSave(CDevBase* vDevice)
{

	string vStr;
	_variant_t vValue;
	C3pDevConvertor * vDev;
	
	vDev = dynamic_cast<C3pDevConvertor *>(vDevice);
	
	C3pRwTwo::doSave(vDevice);
	
	//SqlStr = SqlStr + ",";
	//SqlParam = SqlParam + ",";
		
	//SqlStr = SqlStr + "Valvor12Count,";
	//SqlParam = SqlParam +GetString(vDev->GetValvor12Count()) + ",";
	
	
}