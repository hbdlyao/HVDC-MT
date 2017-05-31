///////////////////////////////////////////////////////////
//  C3pDevConvertor.cpp
//  Implementation of the Class C3pDevConvertor
//  Created on:      19-5ÔÂ-2017 10:17:29
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pDevConvertor.h"
#include "C3pDefs.h"
#include <random>
#include <time.h>
void C3pDevConvertor::Prepare3pData(int vDType, int vLoopTimes)
{
	DType = vDType;
	switch (vDType)
	{
	case C3pDefs::DFixed:
		doDFixed();
	case C3pDefs::DAutoDis:
		doDAutoDis();
	case C3pDefs::DRandom:
		doDRandom(vLoopTimes);

	}
}
void C3pDevConvertor::doDFixed()
{
	for (int i = 0;i < 6; i++)
		dAngleVec[i] = new double[1];

	for (int i = 0;i < 6; i++)
		dAngleVec[i][0] = dAngle[i];
		
}

void C3pDevConvertor::doDAutoDis()
{
	for (int i = 0;i < 6; i++)
		dAngleVec[i] = new double[1];


}

void C3pDevConvertor::doDRandom(int vLoopTimes)
{
	std::default_random_engine vseed(time(NULL));

	std::normal_distribution<double> valpha(0 , Std_Angle);

	for (int i = 0;i < 6; i++)
	{
		dAngleVec[i] = new double[vLoopTimes];
		for (int j = 0;j < vLoopTimes; j++)
			dAngleVec[i][j] = valpha(vseed);
	}	

}

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