///////////////////////////////////////////////////////////
//  C3pDevAcSys.cpp
//  Implementation of the Class C3pDevAcSys
//  Created on:      18-5��-2017 7:45:37
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pDevAcSys.h"

C3pDevAcSys::~C3pDevAcSys()
{
	delete pXb;
	pXb = nullptr;
}

int C3pDevAcSys::GethCount()
{
	return hCount;
}


void C3pDevAcSys::SethCount(int newVal)
{
	hCount = newVal;

	pXb = new struct_AcSysXb[hCount];

}


/**
 * ����ϵͳ����
 */
double C3pDevAcSys::GetRs(){

	return Rs;
}


/**
 * ����ϵͳ����
 */
void C3pDevAcSys::SetRs(double newVal){

	Rs = newVal;
}


/**
 * ����ϵͳ���
 */
double C3pDevAcSys::GetLs(){

	return Ls;
}


/**
 * ����ϵͳ���
 */
void C3pDevAcSys::SetLs(double newVal)
{

	Ls = newVal;
}

 double C3pDevAcSys::GetLeq()
 {
	 return Leq;
 }

void C3pDevAcSys::Prepare3pData(int vDType, int vLoopTimes)
{
}

int C3pDevAcSys::Get_hIndex(int vIndex)
{
	return pXb[vIndex].hIndex;
}

void C3pDevAcSys::Set_hIndex(int vIndex,int vValue)
{
	pXb[vIndex].hIndex = vValue;
}

double C3pDevAcSys::Get_hUrms(int vIndex)
{
	return pXb[vIndex].hUrms;
}

void C3pDevAcSys::Set_hUrms(int vIndex, double vValue)
{
	pXb[vIndex].hUrms = vValue;
}

double C3pDevAcSys::Get_hAngle(int vIndex)
{
	return pXb[vIndex].hAngle;
}

void C3pDevAcSys::Set_hAngle(int vIndex, double vValue)
{
	pXb[vIndex].hAngle = vValue;
}
