///////////////////////////////////////////////////////////
//  C3pRwStaData.cpp
//  Implementation of the Class C3pRwStaData
//  Created on:      26-5ÔÂ-2017 18:28:34
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pRwStaData.h"

#include <iostream>


void C3pRwStaData::doLoad(CDevBase* vDevice)
{
/*
	string vStr;
	_variant_t vValue;
	C3pDevStaData * vDev;
	
	vDev = dynamic_cast<C3pDevStaData *>(vDevice);*/
	

	C3pRw::doLoad(vDevice);


}

void C3pRwStaData::doSave(CDevBase* vDevice)
{
	C3pRw::doSave(vDevice);
}
