///////////////////////////////////////////////////////////
//  C3pDevXf2.cpp
//  Implementation of the Class C3pDevXf2
//  Created on:      19-5月-2017 10:28:19
//  Original author: open2
///////////////////////////////////////////////////////////

#include "C3pDevXf2.h"

#include "C3pDefs.h"

#include <random>

#include <time.h>


double C3pDevXf2::GetdTkN(){

	return dTkN;
}


void C3pDevXf2::SetdTkN(double newVal){

	dTkN = newVal;
}


double C3pDevXf2::GetStd_Lt(){

	return Std_Lt;
}


void C3pDevXf2::SetStd_Lt(double newVal){

	Std_Lt = newVal;
}


double C3pDevXf2::GetdLtA(){

	return dLtA;
}


void C3pDevXf2::SetdLtA(double newVal){

	dLtA = newVal;
}


double C3pDevXf2::GetdLtB(){

	return dLtB;
}


void C3pDevXf2::SetdLtB(double newVal){

	dLtB = newVal;
}


double C3pDevXf2::GetdLtC(){

	return dLtC;
}


void C3pDevXf2::SetdLtC(double newVal){

	dLtC = newVal;
}


double C3pDevXf2::GetTkN(){

	return TkN;
}


void C3pDevXf2::SetTkN(double newVal){

	TkN = newVal;
}


double C3pDevXf2::GetUacN(){

	return UacN;
}


void C3pDevXf2::SetUacN(double newVal){

	UacN = newVal;
}


double C3pDevXf2::GetUkp(){

	return Ukp;
}


void C3pDevXf2::SetUkp(double newVal){

	Ukp = newVal;
}


double C3pDevXf2::GetUrp(){

	return Urp;
}


void C3pDevXf2::SetUrp(double newVal){

	Urp = newVal;
}


double C3pDevXf2::GetUvN(){

	return UvN;
}


void C3pDevXf2::SetUvN(double newVal){

	UvN = newVal;
}


double C3pDevXf2::GetSN(){

	return SN;
}


void C3pDevXf2::SetSN(double newVal){

	SN = newVal;
}


double C3pDevXf2::GetPhaseShift(){

	return PhaseShift;
}


void C3pDevXf2::SetPhaseShift(double newVal){

	PhaseShift = newVal;
}


double C3pDevXf2::GetDis_dLt(){

	return Dis_dLt;
}


void C3pDevXf2::SetDis_dLt(double newVal){

	Dis_dLt = newVal;
}


void C3pDevXf2::Prepare3pData(int vDType, int vLoopTimes)
{
	//计算电感
	

	//计算偏差
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

void C3pDevXf2::doDFixed()
{
	dLtAVec = new double[1];
	dLtBVec = new double[1];
	dLtCVec = new double[1];

	dLtAVec[0] = dLtA;
	dLtBVec[0] = dLtB;
	dLtCVec[0] = dLtC;
}

void C3pDevXf2::doDAutoDis()
{
	dLtAVec = new double[1];
	dLtBVec = new double[1];
	dLtCVec = new double[1];


}

void C3pDevXf2::doDRandom(int vLoopTimes)
{
	std::default_random_engine vseed(time(NULL));

	std::normal_distribution<double> valpha(0, Std_Lt);

	dLtAVec = new double[vLoopTimes];
	dLtBVec = new double[vLoopTimes];
	dLtCVec = new double[vLoopTimes];


}
