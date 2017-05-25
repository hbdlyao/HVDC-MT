///////////////////////////////////////////////////////////
//  C3pDevConvertor.cpp
//  Implementation of the Class C3pDevConvertor
//  Created on:      19-5ÔÂ-2017 10:17:29
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pDevConvertor.h"


double C3pDevConvertor::GetdAngle(int i)
{
	return dAngle[i];
}


void C3pDevConvertor::SetdAngle(int i, double newVal)
{
	dAngle[i] = newVal;
}


double C3pDevConvertor::GetStd_Angle()
{
	return Std_Angle;
}


void C3pDevConvertor::SetStd_Angle(double newVal)
{
	Dis_dAngle = newVal;
}


double C3pDevConvertor::GetDis_dAngle()
{
	return Dis_dAngle;
}


void C3pDevConvertor::SetDis_dAngle(double newVal)
{
	Dis_dAngle = newVal;
}


int C3pDevConvertor::GetStationType()
{
	return StationType;
}


void C3pDevConvertor::SetStationType(int newVal)
{
	StationType = newVal;
}